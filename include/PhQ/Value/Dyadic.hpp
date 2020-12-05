// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "SymmetricDyadic.hpp"

namespace PhQ {

namespace Value {

class Dyadic {

public:

  constexpr Dyadic() noexcept : xx_(), xy_(), xz_(), yx_(), yy_(), yz_(), zx_(), zy_(), zz_() {}

  constexpr Dyadic(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz) noexcept : xx_(xx), xy_(xy), xz_(xz), yx_(yx), yy_(yy), yz_(yz), zx_(zx), zy_(zy), zz_(zz) {}

  constexpr Dyadic(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept : xx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[0]), xy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[1]), xz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[2]), yx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[3]), yy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[4]), yz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[5]), zx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[6]), zy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[7]), zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[8]) {}

  constexpr Dyadic(const SymmetricDyadic& symmetric_dyadic) noexcept : xx_(symmetric_dyadic.xx()), xy_(symmetric_dyadic.xy()), xz_(symmetric_dyadic.xz()), yx_(symmetric_dyadic.yx()), yy_(symmetric_dyadic.yy()), yz_(symmetric_dyadic.yz()), zx_(symmetric_dyadic.zx()), zy_(symmetric_dyadic.zy()), zz_(symmetric_dyadic.zz()) {}

  constexpr double xx() const noexcept {
    return xx_;
  }

  constexpr double xy() const noexcept {
    return xy_;
  }

  constexpr double xz() const noexcept {
    return xz_;
  }

  constexpr double yx() const noexcept {
    return yx_;
  }

  constexpr double yy() const noexcept {
    return yy_;
  }

  constexpr double yz() const noexcept {
    return yz_;
  }

  constexpr double zx() const noexcept {
    return zx_;
  }

  constexpr double zy() const noexcept {
    return zy_;
  }

  constexpr double zz() const noexcept {
    return zz_;
  }

  constexpr bool is_symmetric() const noexcept {
    return xy_ == yx_ && xz_ == zx_ && yz_ == zy_;
  }

  constexpr double trace() const noexcept {
    return xx_ + yy_ + zz_;
  }

  constexpr double determinant() const noexcept {
    return
      xx_ * (yy_ * zz_ - yz_ * zy_) +
      xy_ * (yz_ * zx_ - yx_ * zz_) +
      xz_ * (yx_ * zy_ - yy_ * zx_);
  }

  constexpr Dyadic transpose() const noexcept {
    return {xx_, yx_, zx_, xy_, yy_, zy_, xz_, yz_, zz_};
  }

  constexpr Dyadic cofactors() const noexcept {
    const double cofactor_xx{yy_ * zz_ - yz_ * zy_};
    const double cofactor_xy{yz_ * zx_ - yx_ * zz_};
    const double cofactor_xz{yx_ * zy_ - yy_ * zx_};
    const double cofactor_yx{xz_ * zy_ - xy_ * zz_};
    const double cofactor_yy{xx_ * zz_ - xz_ * zx_};
    const double cofactor_yz{xy_ * zx_ - xx_ * zy_};
    const double cofactor_zx{xy_ * yz_ - xz_ * yy_};
    const double cofactor_zy{xz_ * yx_ - xx_ * yz_};
    const double cofactor_zz{xx_ * yy_ - xy_ * yx_};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy, cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  constexpr Dyadic adjugate() const noexcept {
    return cofactors().transpose();
  }

  Dyadic inverse() const {
    const double determinant_{determinant()};
    if (determinant_ != 0.0) {
      return adjugate() / determinant_;
    } else {
      throw std::runtime_error{"Cannot compute the inverse of " + print() + " because its determinant is 0."};
    }
  }

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(xx_) + ", " +
      PhQ::number_to_string(xy_) + ", " +
      PhQ::number_to_string(xz_) + "; " +
      PhQ::number_to_string(yx_) + ", " +
      PhQ::number_to_string(yy_) + ", " +
      PhQ::number_to_string(yz_) + "; " +
      PhQ::number_to_string(zx_) + ", " +
      PhQ::number_to_string(zy_) + ", " +
      PhQ::number_to_string(zz_) + ")";
  }

  std::string yaml() const noexcept {
    return
      "{xx: " + PhQ::number_to_string(xx_) +
      " , xy: " + PhQ::number_to_string(xy_) +
      " , xz: " + PhQ::number_to_string(xz_) +
      " , yx: " + PhQ::number_to_string(yx_) +
      " , yy: " + PhQ::number_to_string(yy_) +
      " , yz: " + PhQ::number_to_string(yz_) +
      " , zx: " + PhQ::number_to_string(zx_) +
      " , zy: " + PhQ::number_to_string(zy_) +
      " , zz: " + PhQ::number_to_string(zz_) + "}";
  }

  std::string json() const noexcept {
    return
      "{\"xx\": " + PhQ::number_to_string(xx_) +
      " , \"xy\": " + PhQ::number_to_string(xy_) +
      " , \"xz\": " + PhQ::number_to_string(xz_) +
      " , \"yx\": " + PhQ::number_to_string(yx_) +
      " , \"yy\": " + PhQ::number_to_string(yy_) +
      " , \"yz\": " + PhQ::number_to_string(yz_) +
      " , \"zx\": " + PhQ::number_to_string(zx_) +
      " , \"zy\": " + PhQ::number_to_string(zy_) +
      " , \"zz\": " + PhQ::number_to_string(zz_) + "}";
  }

  std::string xml() const noexcept {
    return
      "<xx>" + PhQ::number_to_string(xx_) +
      "</xx><xy>" + PhQ::number_to_string(xy_) +
      "</xy><xz>" + PhQ::number_to_string(xz_) +
      "</xz><yx>" + PhQ::number_to_string(yx_) +
      "</yx><yy>" + PhQ::number_to_string(yy_) +
      "</yy><yz>" + PhQ::number_to_string(yz_) +
      "</yz><zx>" + PhQ::number_to_string(zx_) +
      "</zx><zy>" + PhQ::number_to_string(zy_) +
      "</zy><zz>" + PhQ::number_to_string(zz_) + "</zz>";
  }

  constexpr bool operator==(const Dyadic& dyadic) const noexcept {
    return
      xx_ == dyadic.xx_ &&
      xy_ == dyadic.xy_ &&
      xz_ == dyadic.xz_ &&
      yx_ == dyadic.yx_ &&
      yy_ == dyadic.yy_ &&
      yz_ == dyadic.yz_ &&
      zx_ == dyadic.zx_ &&
      zy_ == dyadic.zy_ &&
      zz_ == dyadic.zz_;
  }

  constexpr bool operator!=(const Dyadic& dyadic) const noexcept {
    return
      xx_ != dyadic.xx_ ||
      xy_ != dyadic.xy_ ||
      xz_ != dyadic.xz_ ||
      yx_ != dyadic.yx_ ||
      yy_ != dyadic.yy_ ||
      yz_ != dyadic.yz_ ||
      zx_ != dyadic.zx_ ||
      zy_ != dyadic.zy_ ||
      zz_ != dyadic.zz_;
  }

  constexpr Dyadic operator+(const Dyadic& dyadic) const noexcept {
    return {
      xx_ + dyadic.xx_,
      xy_ + dyadic.xy_,
      xz_ + dyadic.xz_,
      yx_ + dyadic.yx_,
      yy_ + dyadic.yy_,
      yz_ + dyadic.yz_,
      zx_ + dyadic.zx_,
      zy_ + dyadic.zy_,
      zz_ + dyadic.zz_
    };
  }

  constexpr void operator+=(const Dyadic& dyadic) noexcept {
    xx_ += dyadic.xx_;
    xy_ += dyadic.xy_;
    xz_ += dyadic.xz_;
    yx_ += dyadic.yx_;
    yy_ += dyadic.yy_;
    yz_ += dyadic.yz_;
    zx_ += dyadic.zx_;
    zy_ += dyadic.zy_;
    zz_ += dyadic.zz_;
  }

  constexpr Dyadic operator-(const Dyadic& dyadic) const noexcept {
    return {
      xx_ - dyadic.xx_,
      xy_ - dyadic.xy_,
      xz_ - dyadic.xz_,
      yx_ - dyadic.yx_,
      yy_ - dyadic.yy_,
      yz_ - dyadic.yz_,
      zx_ - dyadic.zx_,
      zy_ - dyadic.zy_,
      zz_ - dyadic.zz_
    };
  }

  constexpr void operator-=(const Dyadic& dyadic) noexcept {
    xx_ -= dyadic.xx_;
    xy_ -= dyadic.xy_;
    xz_ -= dyadic.xz_;
    yx_ -= dyadic.yx_;
    yy_ -= dyadic.yy_;
    yz_ -= dyadic.yz_;
    zx_ -= dyadic.zx_;
    zy_ -= dyadic.zy_;
    zz_ -= dyadic.zz_;
  }

  constexpr Dyadic operator*(double real) const noexcept {
    return {xx_ * real, xy_ * real, xz_ * real, yx_ * real, yy_ * real, yz_ * real, zx_ * real, zy_ * real, zz_ * real};
  }

  constexpr Vector operator*(const Vector& vector) const noexcept {
    return {
      xx_ * vector.x() + xy_ * vector.y() + xz_ * vector.z(),
      yx_ * vector.x() + yy_ * vector.y() + yz_ * vector.z(),
      zx_ * vector.x() + zy_ * vector.y() + zz_ * vector.z()
    };
  }

  constexpr Dyadic operator*(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return {
      xx_ * symmetric_dyadic.xx() + xy_ * symmetric_dyadic.yx() + xz_ * symmetric_dyadic.zx(),
      xx_ * symmetric_dyadic.xy() + xy_ * symmetric_dyadic.yy() + xz_ * symmetric_dyadic.zy(),
      xx_ * symmetric_dyadic.xz() + xy_ * symmetric_dyadic.yz() + xz_ * symmetric_dyadic.zz(),
      yx_ * symmetric_dyadic.xx() + yy_ * symmetric_dyadic.yx() + yz_ * symmetric_dyadic.zx(),
      yx_ * symmetric_dyadic.xy() + yy_ * symmetric_dyadic.yy() + yz_ * symmetric_dyadic.zy(),
      yx_ * symmetric_dyadic.xz() + yy_ * symmetric_dyadic.yz() + yz_ * symmetric_dyadic.zz(),
      zx_ * symmetric_dyadic.xx() + zy_ * symmetric_dyadic.yx() + zz_ * symmetric_dyadic.zx(),
      zx_ * symmetric_dyadic.xy() + zy_ * symmetric_dyadic.yy() + zz_ * symmetric_dyadic.zy(),
      zx_ * symmetric_dyadic.xz() + zy_ * symmetric_dyadic.yz() + zz_ * symmetric_dyadic.zz()
    };
  }

  constexpr Dyadic operator*(const Dyadic& dyadic) const noexcept {
    return {
      xx_ * dyadic.xx_ + xy_ * dyadic.yx_ + xz_ * dyadic.zx_,
      xx_ * dyadic.xy_ + xy_ * dyadic.yy_ + xz_ * dyadic.zy_,
      xx_ * dyadic.xz_ + xy_ * dyadic.yz_ + xz_ * dyadic.zz_,
      yx_ * dyadic.xx_ + yy_ * dyadic.yx_ + yz_ * dyadic.zx_,
      yx_ * dyadic.xy_ + yy_ * dyadic.yy_ + yz_ * dyadic.zy_,
      yx_ * dyadic.xz_ + yy_ * dyadic.yz_ + yz_ * dyadic.zz_,
      zx_ * dyadic.xx_ + zy_ * dyadic.yx_ + zz_ * dyadic.zx_,
      zx_ * dyadic.xy_ + zy_ * dyadic.yy_ + zz_ * dyadic.zy_,
      zx_ * dyadic.xz_ + zy_ * dyadic.yz_ + zz_ * dyadic.zz_
    };
  }

  constexpr void operator*=(double real) noexcept {
    xx_ *= real;
    xy_ *= real;
    xz_ *= real;
    yx_ *= real;
    yy_ *= real;
    yz_ *= real;
    zx_ *= real;
    zy_ *= real;
    zz_ *= real;
  }

  constexpr Dyadic operator/(double real) const noexcept {
    return {xx_ / real, xy_ / real, xz_ / real, yx_ / real, yy_ / real, yz_ / real, zx_ / real, zy_ / real, zz_ / real};
  }

  constexpr void operator/=(double real) noexcept {
    xx_ /= real;
    xy_ /= real;
    xz_ /= real;
    yx_ /= real;
    yy_ /= real;
    yz_ /= real;
    zx_ /= real;
    zy_ /= real;
    zz_ /= real;
  }

protected:

  double xx_;

  double xy_;

  double xz_;

  double yx_;

  double yy_;

  double yz_;

  double zx_;

  double zy_;

  double zz_;

};

constexpr Dyadic Vector::dyadic(const Vector& vector) const noexcept {
  return {
    x_ * vector.x_, x_ * vector.y_, x_ * vector.z_,
    y_ * vector.x_, y_ * vector.y_, y_ * vector.z_,
    z_ * vector.x_, z_ * vector.y_, z_ * vector.z_
  };
}

constexpr Dyadic SymmetricDyadic::operator*(const SymmetricDyadic& symmetric_dyadic) const noexcept {
  return {
    xx_ * symmetric_dyadic.xx_ + xy_ * symmetric_dyadic.xy_ + xz_ * symmetric_dyadic.xz_,
    xx_ * symmetric_dyadic.xy_ + xy_ * symmetric_dyadic.yy_ + xz_ * symmetric_dyadic.yz_,
    xx_ * symmetric_dyadic.xz_ + xy_ * symmetric_dyadic.yz_ + xz_ * symmetric_dyadic.zz_,
    xy_ * symmetric_dyadic.xx_ + yy_ * symmetric_dyadic.xy_ + yz_ * symmetric_dyadic.xz_,
    xy_ * symmetric_dyadic.xy_ + yy_ * symmetric_dyadic.yy_ + yz_ * symmetric_dyadic.yz_,
    xy_ * symmetric_dyadic.xz_ + yy_ * symmetric_dyadic.yz_ + yz_ * symmetric_dyadic.zz_,
    xz_ * symmetric_dyadic.xx_ + yz_ * symmetric_dyadic.xy_ + zz_ * symmetric_dyadic.xz_,
    xz_ * symmetric_dyadic.xy_ + yz_ * symmetric_dyadic.yy_ + zz_ * symmetric_dyadic.yz_,
    xz_ * symmetric_dyadic.xz_ + yz_ * symmetric_dyadic.yz_ + zz_ * symmetric_dyadic.zz_
  };
}

constexpr Dyadic SymmetricDyadic::operator*(const Dyadic& dyadic) const noexcept {
  return {
    xx_ * dyadic.xx() + xy_ * dyadic.yx() + xz_ * dyadic.zx(),
    xx_ * dyadic.xy() + xy_ * dyadic.yy() + xz_ * dyadic.zy(),
    xx_ * dyadic.xz() + xy_ * dyadic.yz() + xz_ * dyadic.zz(),
    xy_ * dyadic.xx() + yy_ * dyadic.yx() + yz_ * dyadic.zx(),
    xy_ * dyadic.xy() + yy_ * dyadic.yy() + yz_ * dyadic.zy(),
    xy_ * dyadic.xz() + yy_ * dyadic.yz() + yz_ * dyadic.zz(),
    xz_ * dyadic.xx() + yz_ * dyadic.yx() + zz_ * dyadic.zx(),
    xz_ * dyadic.xy() + yz_ * dyadic.yy() + zz_ * dyadic.zy(),
    xz_ * dyadic.xz() + yz_ * dyadic.yz() + zz_ * dyadic.zz()
  };
}

} // namespace Value

constexpr Value::Dyadic Direction::dyadic(const Direction& direction) const noexcept {
  return {
    x_ * direction.x_, x_ * direction.y_, x_ * direction.z_,
    y_ * direction.x_, y_ * direction.y_, y_ * direction.z_,
    z_ * direction.x_, z_ * direction.y_, z_ * direction.z_
  };
}

constexpr Value::Dyadic Direction::dyadic(const Value::Vector& vector) const noexcept {
  return {
    x_ * vector.x(), x_ * vector.y(), x_ * vector.z(),
    y_ * vector.x(), y_ * vector.y(), y_ * vector.z(),
    z_ * vector.x(), z_ * vector.y(), z_ * vector.z()
  };
}

constexpr Value::Dyadic Value::Vector::dyadic(const Direction& direction) const noexcept {
  return {
    x_ * direction.x(), x_ * direction.y(), x_ * direction.z(),
    y_ * direction.x(), y_ * direction.y(), y_ * direction.z(),
    z_ * direction.x(), z_ * direction.y(), z_ * direction.z()
  };
}

template <> constexpr bool sort(const Value::Dyadic& dyadic_1, const Value::Dyadic& dyadic_2) noexcept {
  if (dyadic_1.xx() == dyadic_2.xx()) {
    if (dyadic_1.xy() == dyadic_2.xy()) {
      if (dyadic_1.xz() == dyadic_2.xz()) {
        if (dyadic_1.yx() == dyadic_2.yx()) {
          if (dyadic_1.yy() == dyadic_2.yy()) {
            if (dyadic_1.yz() == dyadic_2.yz()) {
              if (dyadic_1.zx() == dyadic_2.zx()) {
                if (dyadic_1.zy() == dyadic_2.zy()) {
                  return dyadic_1.zz() < dyadic_2.zz();
                } else {
                  return dyadic_1.zy() < dyadic_2.zy();
                }
              } else {
                return dyadic_1.zx() < dyadic_2.zx();
              }
            } else {
              return dyadic_1.yz() < dyadic_2.yz();
            }
          } else {
            return dyadic_1.yy() < dyadic_2.yy();
          }
        } else {
          return dyadic_1.yx() < dyadic_2.yx();
        }
      } else {
        return dyadic_1.xz() < dyadic_2.xz();
      }
    } else {
      return dyadic_1.xy() < dyadic_2.xy();
    }
  } else {
    return dyadic_1.xx() < dyadic_2.xx();
  }
}

} // namespace PhQ

constexpr PhQ::Value::Dyadic operator*(double real, const PhQ::Value::Dyadic& dyadic) noexcept {
  return {dyadic * real};
}

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::Dyadic& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}

namespace std {

template <> struct hash<PhQ::Value::Dyadic> {
  size_t operator()(const PhQ::Value::Dyadic& dyadic) const {
    return
      hash<double>()(dyadic.xx())
      ^ hash<double>()(dyadic.xy())
      ^ hash<double>()(dyadic.xz())
      ^ hash<double>()(dyadic.yx())
      ^ hash<double>()(dyadic.yy())
      ^ hash<double>()(dyadic.yz())
      ^ hash<double>()(dyadic.zx())
      ^ hash<double>()(dyadic.zy())
      ^ hash<double>()(dyadic.zz());
  }
};

} // namespace std
