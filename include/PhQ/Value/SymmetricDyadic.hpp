// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Vector.hpp"

namespace PhQ {

namespace Value {

class SymmetricDyadic {

public:

  constexpr SymmetricDyadic() noexcept : xx_(), xy_(), xz_(), yy_(), yz_(), zz_() {}

  constexpr SymmetricDyadic(double xx, double xy, double xz, double yy, double yz, double zz) noexcept : xx_(xx), xy_(xy), xz_(xz), yy_(yy), yz_(yz), zz_(zz) {}

  constexpr SymmetricDyadic(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept : xx_(xx_xy_xz_yy_yz_zz[0]), xy_(xx_xy_xz_yy_yz_zz[1]), xz_(xx_xy_xz_yy_yz_zz[2]), yy_(xx_xy_xz_yy_yz_zz[3]), yz_(xx_xy_xz_yy_yz_zz[4]), zz_(xx_xy_xz_yy_yz_zz[5]) {}

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
    return xy_;
  }

  constexpr double yy() const noexcept {
    return yy_;
  }

  constexpr double yz() const noexcept {
    return yz_;
  }

  constexpr double zx() const noexcept {
    return xz_;
  }

  constexpr double zy() const noexcept {
    return yz_;
  }

  constexpr double zz() const noexcept {
    return zz_;
  }

  constexpr bool is_symmetric() const noexcept {
    return true;
  }

  constexpr double trace() const noexcept {
    return xx_ + yy_ + zz_;
  }

  constexpr double determinant() const noexcept {
    return
      xx_ * (yy_ * zz_ - yz_ * yz_) +
      xy_ * (xz_ * yz_ - xy_ * zz_) +
      xz_ * (xy_ * yz_ - xz_ * yy_);
  }

  constexpr SymmetricDyadic transpose() const noexcept {
    return *this;
  }

  constexpr SymmetricDyadic cofactors() const noexcept {
    const double cofactor_xx{yy_ * zz_ - yz_ * yz_};
    const double cofactor_xy{xz_ * yz_ - xy_ * zz_};
    const double cofactor_xz{xy_ * yz_ - xz_ * yy_};
    const double cofactor_yy{xx_ * zz_ - xz_ * xz_};
    const double cofactor_yz{xy_ * xz_ - xx_ * yz_};
    const double cofactor_zz{xx_ * yy_ - xy_ * xy_};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yy, cofactor_yz, cofactor_zz};
  }

  constexpr SymmetricDyadic adjugate() const noexcept {
    return cofactors().transpose();
  }

  constexpr SymmetricDyadic inverse() const {
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
      PhQ::number_to_string(yy_) + ", " +
      PhQ::number_to_string(yz_) + "; " +
      PhQ::number_to_string(zz_) + ")";
  }

  std::string yaml() const noexcept {
    return
      "{xx: " + PhQ::number_to_string(xx_) +
      " , xy: " + PhQ::number_to_string(xy_) +
      " , xz: " + PhQ::number_to_string(xz_) +
      " , yy: " + PhQ::number_to_string(yy_) +
      " , yz: " + PhQ::number_to_string(yz_) +
      " , zz: " + PhQ::number_to_string(zz_) + "}";
  }

  std::string json() const noexcept {
    return
      "{\"xx\": " + PhQ::number_to_string(xx_) +
      " , \"xy\": " + PhQ::number_to_string(xy_) +
      " , \"xz\": " + PhQ::number_to_string(xz_) +
      " , \"yy\": " + PhQ::number_to_string(yy_) +
      " , \"yz\": " + PhQ::number_to_string(yz_) +
      " , \"zz\": " + PhQ::number_to_string(zz_) + "}";
  }

  std::string xml() const noexcept {
    return
      "<xx>" + PhQ::number_to_string(xx_) +
      "</xx><xy>" + PhQ::number_to_string(xy_) +
      "</xy><xz>" + PhQ::number_to_string(xz_) +
      "</xz><yy>" + PhQ::number_to_string(yy_) +
      "</yy><yz>" + PhQ::number_to_string(yz_) +
      "</yz><zz>" + PhQ::number_to_string(zz_) + "</zz>";
  }

  constexpr bool operator==(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return
      xx_ == symmetric_dyadic.xx_ &&
      xy_ == symmetric_dyadic.xy_ &&
      xz_ == symmetric_dyadic.xz_ &&
      yy_ == symmetric_dyadic.yy_ &&
      yz_ == symmetric_dyadic.yz_ &&
      zz_ == symmetric_dyadic.zz_;
  }

  constexpr bool operator!=(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return
      xx_ != symmetric_dyadic.xx_ ||
      xy_ != symmetric_dyadic.xy_ ||
      xz_ != symmetric_dyadic.xz_ ||
      yy_ != symmetric_dyadic.yy_ ||
      yz_ != symmetric_dyadic.yz_ ||
      zz_ != symmetric_dyadic.zz_;
  }

  constexpr SymmetricDyadic operator+(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return {
      xx_ + symmetric_dyadic.xx_,
      xy_ + symmetric_dyadic.xy_,
      xz_ + symmetric_dyadic.xz_,
      yy_ + symmetric_dyadic.yy_,
      yz_ + symmetric_dyadic.yz_,
      zz_ + symmetric_dyadic.zz_
    };
  }

  constexpr void operator+=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_ += symmetric_dyadic.xx_;
    xy_ += symmetric_dyadic.xy_;
    xz_ += symmetric_dyadic.xz_;
    yy_ += symmetric_dyadic.yy_;
    yz_ += symmetric_dyadic.yz_;
    zz_ += symmetric_dyadic.zz_;
  }

  constexpr SymmetricDyadic operator-(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return {
      xx_ - symmetric_dyadic.xx_,
      xy_ - symmetric_dyadic.xy_,
      xz_ - symmetric_dyadic.xz_,
      yy_ - symmetric_dyadic.yy_,
      yz_ - symmetric_dyadic.yz_,
      zz_ - symmetric_dyadic.zz_
    };
  }

  constexpr void operator-=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_ -= symmetric_dyadic.xx_;
    xy_ -= symmetric_dyadic.xy_;
    xz_ -= symmetric_dyadic.xz_;
    yy_ -= symmetric_dyadic.yy_;
    yz_ -= symmetric_dyadic.yz_;
    zz_ -= symmetric_dyadic.zz_;
  }

  constexpr SymmetricDyadic operator*(double real) const noexcept {
    return {xx_ * real, xy_ * real, xz_ * real, yy_ * real, yz_ * real, zz_ * real};
  }

  constexpr Vector operator*(const Vector& vector) const noexcept {
    return {
      xx_ * vector.x() + xy_ * vector.y() + xz_ * vector.z(),
      xy_ * vector.x() + yy_ * vector.y() + yz_ * vector.z(),
      xz_ * vector.x() + yz_ * vector.y() + zz_ * vector.z()
    };
  }

  constexpr Vector operator*(const Direction& direction) const noexcept {
    return {
      xx_ * direction.x() + xy_ * direction.y() + xz_ * direction.z(),
      xy_ * direction.x() + yy_ * direction.y() + yz_ * direction.z(),
      xz_ * direction.x() + yz_ * direction.y() + zz_ * direction.z()
    };
  }

  constexpr Dyadic operator*(const SymmetricDyadic& symmetric_dyadic) const noexcept;

  constexpr Dyadic operator*(const Dyadic& dyadic) const noexcept;

  constexpr void operator*=(double real) noexcept {
    xx_ *= real;
    xy_ *= real;
    xz_ *= real;
    yy_ *= real;
    yz_ *= real;
    zz_ *= real;
  }

  constexpr SymmetricDyadic operator/(double real) const noexcept {
    return {xx_ / real, xy_ / real, xz_ / real, yy_ / real, yz_ / real, zz_ / real};
  }

  constexpr void operator/=(double real) noexcept {
    xx_ /= real;
    xy_ /= real;
    xz_ /= real;
    yy_ /= real;
    yz_ /= real;
    zz_ /= real;
  }

protected:

  double xx_;

  double xy_;

  double xz_;

  double yy_;

  double yz_;

  double zz_;

};

} // namespace Value

template <> constexpr bool sort(const Value::SymmetricDyadic& symmetric_dyadic_1, const Value::SymmetricDyadic& symmetric_dyadic_2) noexcept {
  if (symmetric_dyadic_1.xx() == symmetric_dyadic_2.xx()) {
    if (symmetric_dyadic_1.xy() == symmetric_dyadic_2.xy()) {
      if (symmetric_dyadic_1.xz() == symmetric_dyadic_2.xz()) {
        if (symmetric_dyadic_1.yy() == symmetric_dyadic_2.yy()) {
          if (symmetric_dyadic_1.yz() == symmetric_dyadic_2.yz()) {
            return symmetric_dyadic_1.zz() < symmetric_dyadic_2.zz();
          } else {
            return symmetric_dyadic_1.yz() < symmetric_dyadic_2.yz();
          }
        } else {
          return symmetric_dyadic_1.yy() < symmetric_dyadic_2.yy();
        }
      } else {
        return symmetric_dyadic_1.xz() < symmetric_dyadic_2.xz();
      }
    } else {
      return symmetric_dyadic_1.xy() < symmetric_dyadic_2.xy();
    }
  } else {
    return symmetric_dyadic_1.xx() < symmetric_dyadic_2.xx();
  }
}

} // namespace PhQ

constexpr PhQ::Value::SymmetricDyadic operator*(double real, const PhQ::Value::SymmetricDyadic& symmetric_dyadic) noexcept {
  return {symmetric_dyadic * real};
}

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::SymmetricDyadic& symmetric_dyadic) noexcept {
  output_stream << symmetric_dyadic.print();
  return output_stream;
}

namespace std {

template <> struct hash<PhQ::Value::SymmetricDyadic> {
  size_t operator()(const PhQ::Value::SymmetricDyadic& symmetric_dyadic) const {
    return
      hash<double>()(symmetric_dyadic.xx())
      ^ hash<double>()(symmetric_dyadic.xy())
      ^ hash<double>()(symmetric_dyadic.xz())
      ^ hash<double>()(symmetric_dyadic.yy())
      ^ hash<double>()(symmetric_dyadic.yz())
      ^ hash<double>()(symmetric_dyadic.zz());
  }
};

} // namespace std
