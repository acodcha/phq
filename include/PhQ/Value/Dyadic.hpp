// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYADIC_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYADIC_HPP

#include "SymmetricDyadic.hpp"

namespace PhQ {

namespace Value {

class Dyadic {
public:
  constexpr Dyadic() noexcept : xx_(), xy_(), xz_(), yx_(), yy_(), yz_(), zx_(), zy_(), zz_() {}

  constexpr Dyadic(const double xx, const double xy, const double xz, const double yx, const double yy, const double yz, const double zx, const double zy, const double zz) noexcept : xx_(xx), xy_(xy), xz_(xz), yx_(yx), yy_(yy), yz_(yz), zx_(zx), zy_(zy), zz_(zz) {}

  constexpr Dyadic(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept : xx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[0]), xy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[1]), xz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[2]), yx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[3]), yy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[4]), yz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[5]), zx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[6]), zy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[7]), zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[8]) {}

  constexpr Dyadic(const SymmetricDyadic& symmetric) noexcept : xx_(symmetric.xx()), xy_(symmetric.xy()), xz_(symmetric.xz()), yx_(symmetric.yx()), yy_(symmetric.yy()), yz_(symmetric.yz()), zx_(symmetric.zx()), zy_(symmetric.zy()), zz_(symmetric.zz()) {}

  static constexpr Dyadic Zero() noexcept {
    return {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  }

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
    return (
        xx_ * (yy_ * zz_ - yz_ * zy_) +
        xy_ * (yz_ * zx_ - yx_ * zz_) +
        xz_ * (yx_ * zy_ - yy_ * zx_));
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

  Dyadic inverse() const;

  std::string print() const noexcept {
    return {
        "(" + PhQ::print(xx_) + ", " + PhQ::print(xy_) + ", " + PhQ::print(xz_) + "; " +
        PhQ::print(yx_) + ", " + PhQ::print(yy_) + ", " + PhQ::print(yz_) + "; " +
        PhQ::print(zx_) + ", " + PhQ::print(zy_) + ", " + PhQ::print(zz_) + ")"};
  }

  std::string json() const noexcept {
    return {
        "{\"xx\":" + PhQ::print(xx_) + ",\"xy\":" + PhQ::print(xy_) + ",\"xz\":" + PhQ::print(xz_) +
        ",\"yx\":" + PhQ::print(yx_) + ",\"yy\":" + PhQ::print(yy_) + ",\"yz\":" + PhQ::print(yz_) +
        ",\"zx\":" + PhQ::print(zx_) + ",\"zy\":" + PhQ::print(zy_) + ",\"zz\":" + PhQ::print(zz_) + "}"};
  }

  std::string xml() const noexcept {
    return {
        "<xx>" + PhQ::print(xx_) + "</xx><xy>" + PhQ::print(xy_) + "</xy><xz>" + PhQ::print(xz_) +
        "</xz><yx>" + PhQ::print(yx_) + "</yx><yy>" + PhQ::print(yy_) + "</yy><yz>" + PhQ::print(yz_) +
        "</yz><zx>" + PhQ::print(zx_) + "</zx><zy>" + PhQ::print(zy_) + "</zy><zz>" + PhQ::print(zz_) + "</zz>"};
  }

  std::string yaml() const noexcept {
    return {
        "{xx:" + PhQ::print(xx_) + ",xy:" + PhQ::print(xy_) + ",xz:" + PhQ::print(xz_) +
        ",yx:" + PhQ::print(yx_) + ",yy:" + PhQ::print(yy_) + ",yz:" + PhQ::print(yz_) +
        ",zx:" + PhQ::print(zx_) + ",zy:" + PhQ::print(zy_) + ",zz:" + PhQ::print(zz_) + "}"};
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

  constexpr void operator*=(const double real) noexcept {
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

  constexpr void operator/=(const double real) noexcept {
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
      z_ * vector.x_, z_ * vector.y_, z_ * vector.z_};
}

constexpr bool operator==(const Dyadic& left, const Dyadic& right) noexcept {
  return (
      left.xx() == right.xx() && left.xy() == right.xy() && left.xz() == right.xz() &&
      left.yx() == right.yx() && left.yy() == right.yy() && left.yz() == right.yz() &&
      left.zx() == right.zx() && left.zy() == right.zy() && left.zz() == right.zz());
}

constexpr bool operator!=(const Dyadic& left, const Dyadic& right) noexcept {
  return (
      left.xx() != right.xx() || left.xy() != right.xy() || left.xz() != right.xz() ||
      left.yx() != right.yx() || left.yy() != right.yy() || left.yz() != right.yz() ||
      left.zx() != right.zx() || left.zy() != right.zy() || left.zz() != right.zz());
}

constexpr Dyadic operator+(const Dyadic& left, const Dyadic& right) noexcept {
  return {
      left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
      left.yx() + right.yx(), left.yy() + right.yy(), left.yz() + right.yz(),
      left.zx() + right.zx(), left.zy() + right.zy(), left.zz() + right.zz()};
}

constexpr Dyadic operator-(const Dyadic& left, const Dyadic& right) noexcept {
  return {
      left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
      left.yx() - right.yx(), left.yy() - right.yy(), left.yz() - right.yz(),
      left.zx() - right.zx(), left.zy() - right.zy(), left.zz() - right.zz()};
}

constexpr Dyadic operator*(const Dyadic& dyadic, const double real) noexcept {
  return {
      dyadic.xx() * real, dyadic.xy() * real, dyadic.xz() * real,
      dyadic.yx() * real, dyadic.yy() * real, dyadic.yz() * real,
      dyadic.zx() * real, dyadic.zy() * real, dyadic.zz() * real};
}

constexpr Dyadic operator*(const double real, const Dyadic& dyadic) noexcept {
  return {dyadic * real};
}

constexpr Vector operator*(const Dyadic& dyadic, const Vector& vector) noexcept {
  return {
      dyadic.xx() * vector.x() + dyadic.xy() * vector.y() + dyadic.xz() * vector.z(),
      dyadic.yx() * vector.x() + dyadic.yy() * vector.y() + dyadic.yz() * vector.z(),
      dyadic.zx() * vector.x() + dyadic.zy() * vector.y() + dyadic.zz() * vector.z()};
}

constexpr Dyadic operator*(const SymmetricDyadic& left, const SymmetricDyadic& right) noexcept {
  return {
      left.xx() * right.xx() + left.xy() * right.xy() + left.xz() * right.xz(),
      left.xx() * right.xy() + left.xy() * right.yy() + left.xz() * right.yz(),
      left.xx() * right.xz() + left.xy() * right.yz() + left.xz() * right.zz(),
      left.xy() * right.xx() + left.yy() * right.xy() + left.yz() * right.xz(),
      left.xy() * right.xy() + left.yy() * right.yy() + left.yz() * right.yz(),
      left.xy() * right.xz() + left.yy() * right.yz() + left.yz() * right.zz(),
      left.xz() * right.xx() + left.yz() * right.xy() + left.zz() * right.xz(),
      left.xz() * right.xy() + left.yz() * right.yy() + left.zz() * right.yz(),
      left.xz() * right.xz() + left.yz() * right.yz() + left.zz() * right.zz()};
}

constexpr Dyadic operator*(const SymmetricDyadic& symmetric, const Dyadic& dyadic) noexcept {
  return {
      symmetric.xx() * dyadic.xx() + symmetric.xy() * dyadic.yx() + symmetric.xz() * dyadic.zx(),
      symmetric.xx() * dyadic.xy() + symmetric.xy() * dyadic.yy() + symmetric.xz() * dyadic.zy(),
      symmetric.xx() * dyadic.xz() + symmetric.xy() * dyadic.yz() + symmetric.xz() * dyadic.zz(),
      symmetric.xy() * dyadic.xx() + symmetric.yy() * dyadic.yx() + symmetric.yz() * dyadic.zx(),
      symmetric.xy() * dyadic.xy() + symmetric.yy() * dyadic.yy() + symmetric.yz() * dyadic.zy(),
      symmetric.xy() * dyadic.xz() + symmetric.yy() * dyadic.yz() + symmetric.yz() * dyadic.zz(),
      symmetric.xz() * dyadic.xx() + symmetric.yz() * dyadic.yx() + symmetric.zz() * dyadic.zx(),
      symmetric.xz() * dyadic.xy() + symmetric.yz() * dyadic.yy() + symmetric.zz() * dyadic.zy(),
      symmetric.xz() * dyadic.xz() + symmetric.yz() * dyadic.yz() + symmetric.zz() * dyadic.zz()};
}

constexpr Dyadic operator*(const Dyadic& dyadic, const SymmetricDyadic& symmetric) noexcept {
  return {
      dyadic.xx() * symmetric.xx() + dyadic.xy() * symmetric.yx() + dyadic.xz() * symmetric.zx(),
      dyadic.xx() * symmetric.xy() + dyadic.xy() * symmetric.yy() + dyadic.xz() * symmetric.zy(),
      dyadic.xx() * symmetric.xz() + dyadic.xy() * symmetric.yz() + dyadic.xz() * symmetric.zz(),
      dyadic.yx() * symmetric.xx() + dyadic.yy() * symmetric.yx() + dyadic.yz() * symmetric.zx(),
      dyadic.yx() * symmetric.xy() + dyadic.yy() * symmetric.yy() + dyadic.yz() * symmetric.zy(),
      dyadic.yx() * symmetric.xz() + dyadic.yy() * symmetric.yz() + dyadic.yz() * symmetric.zz(),
      dyadic.zx() * symmetric.xx() + dyadic.zy() * symmetric.yx() + dyadic.zz() * symmetric.zx(),
      dyadic.zx() * symmetric.xy() + dyadic.zy() * symmetric.yy() + dyadic.zz() * symmetric.zy(),
      dyadic.zx() * symmetric.xz() + dyadic.zy() * symmetric.yz() + dyadic.zz() * symmetric.zz()};
}

constexpr Dyadic operator*(const Dyadic& left, const Dyadic& right) noexcept {
  return {
      left.xx() * right.xx() + left.xy() * right.yx() + left.xz() * right.zx(),
      left.xx() * right.xy() + left.xy() * right.yy() + left.xz() * right.zy(),
      left.xx() * right.xz() + left.xy() * right.yz() + left.xz() * right.zz(),
      left.yx() * right.xx() + left.yy() * right.yx() + left.yz() * right.zx(),
      left.yx() * right.xy() + left.yy() * right.yy() + left.yz() * right.zy(),
      left.yx() * right.xz() + left.yy() * right.yz() + left.yz() * right.zz(),
      left.zx() * right.xx() + left.zy() * right.yx() + left.zz() * right.zx(),
      left.zx() * right.xy() + left.zy() * right.yy() + left.zz() * right.zy(),
      left.zx() * right.xz() + left.zy() * right.yz() + left.zz() * right.zz()};
}

constexpr Dyadic operator/(const Dyadic& dyadic, const double real) noexcept {
  return {
      dyadic.xx() / real, dyadic.xy() / real, dyadic.xz() / real,
      dyadic.yx() / real, dyadic.yy() / real, dyadic.yz() / real,
      dyadic.zx() / real, dyadic.zy() / real, dyadic.zz() / real};
}

Dyadic Dyadic::inverse() const {
  const double determinant_{determinant()};
  if (determinant_ != 0.0) {
    return adjugate() / determinant_;
  } else {
    throw std::runtime_error{"Cannot compute the inverse of " + print() + " because its determinant is 0."};
  }
}

std::ostream& operator<<(std::ostream& output_stream, const Dyadic& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}

}  // namespace Value

constexpr Value::Dyadic Direction::dyadic(const Direction& direction) const noexcept {
  return {
      x_ * direction.x_, x_ * direction.y_, x_ * direction.z_,
      y_ * direction.x_, y_ * direction.y_, y_ * direction.z_,
      z_ * direction.x_, z_ * direction.y_, z_ * direction.z_};
}

constexpr Value::Dyadic Direction::dyadic(const Value::Vector& vector) const noexcept {
  return {
      x_ * vector.x(), x_ * vector.y(), x_ * vector.z(),
      y_ * vector.x(), y_ * vector.y(), y_ * vector.z(),
      z_ * vector.x(), z_ * vector.y(), z_ * vector.z()};
}

constexpr Value::Dyadic Value::Vector::dyadic(const Direction& direction) const noexcept {
  return {
      x_ * direction.x(), x_ * direction.y(), x_ * direction.z(),
      y_ * direction.x(), y_ * direction.y(), y_ * direction.z(),
      z_ * direction.x(), z_ * direction.y(), z_ * direction.z()};
}

}  // namespace PhQ

namespace std {

template <> struct hash<PhQ::Value::Dyadic> {
  size_t operator()(const PhQ::Value::Dyadic& dyadic) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(dyadic.xx());
    result = 31 * result + hash<double>()(dyadic.xy());
    result = 31 * result + hash<double>()(dyadic.xz());
    result = 31 * result + hash<double>()(dyadic.yx());
    result = 31 * result + hash<double>()(dyadic.yy());
    result = 31 * result + hash<double>()(dyadic.yz());
    result = 31 * result + hash<double>()(dyadic.zx());
    result = 31 * result + hash<double>()(dyadic.zy());
    result = 31 * result + hash<double>()(dyadic.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYADIC_HPP
