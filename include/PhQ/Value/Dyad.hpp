// Copyright 2020 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP

#include "SymmetricDyad.hpp"

namespace PhQ {

namespace Value {

class Dyad {
public:
  constexpr Dyad() noexcept
      : xx_(), xy_(), xz_(), yx_(), yy_(), yz_(), zx_(), zy_(), zz_() {}

  constexpr Dyad(const double xx, const double xy, const double xz,
                 const double yx, const double yy, const double yz,
                 const double zx, const double zy, const double zz) noexcept
      : xx_(xx),
        xy_(xy),
        xz_(xz),
        yx_(yx),
        yy_(yy),
        yz_(yz),
        zx_(zx),
        zy_(zy),
        zz_(zz) {}

  constexpr Dyad(
      const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept
      : xx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[0]),
        xy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[1]),
        xz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[2]),
        yx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[3]),
        yy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[4]),
        yz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[5]),
        zx_(xx_xy_xz_yx_yy_yz_zx_zy_zz[6]),
        zy_(xx_xy_xz_yx_yy_yz_zx_zy_zz[7]),
        zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz[8]) {}

  constexpr Dyad(const SymmetricDyad& symdyad) noexcept
      : xx_(symdyad.xx()),
        xy_(symdyad.xy()),
        xz_(symdyad.xz()),
        yx_(symdyad.yx()),
        yy_(symdyad.yy()),
        yz_(symdyad.yz()),
        zx_(symdyad.zx()),
        zy_(symdyad.zy()),
        zz_(symdyad.zz()) {}

  static constexpr Dyad Zero() noexcept {
    return {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  }

  inline constexpr double xx() const noexcept { return xx_; }

  inline constexpr double xy() const noexcept { return xy_; }

  inline constexpr double xz() const noexcept { return xz_; }

  inline constexpr double yx() const noexcept { return yx_; }

  inline constexpr double yy() const noexcept { return yy_; }

  inline constexpr double yz() const noexcept { return yz_; }

  inline constexpr double zx() const noexcept { return zx_; }

  inline constexpr double zy() const noexcept { return zy_; }

  inline constexpr double zz() const noexcept { return zz_; }

  inline constexpr bool IsSymmetric() const noexcept {
    return xy_ == yx_ && xz_ == zx_ && yz_ == zy_;
  }

  inline constexpr double Trace() const noexcept { return xx_ + yy_ + zz_; }

  inline constexpr double Determinant() const noexcept {
    return (xx_ * (yy_ * zz_ - yz_ * zy_) + xy_ * (yz_ * zx_ - yx_ * zz_) +
            xz_ * (yx_ * zy_ - yy_ * zx_));
  }

  inline constexpr Dyad Transpose() const noexcept {
    return {xx_, yx_, zx_, xy_, yy_, zy_, xz_, yz_, zz_};
  }

  constexpr Dyad Cofactors() const noexcept {
    const double cofactor_xx{yy_ * zz_ - yz_ * zy_};
    const double cofactor_xy{yz_ * zx_ - yx_ * zz_};
    const double cofactor_xz{yx_ * zy_ - yy_ * zx_};
    const double cofactor_yx{xz_ * zy_ - xy_ * zz_};
    const double cofactor_yy{xx_ * zz_ - xz_ * zx_};
    const double cofactor_yz{xy_ * zx_ - xx_ * zy_};
    const double cofactor_zx{xy_ * yz_ - xz_ * yy_};
    const double cofactor_zy{xz_ * yx_ - xx_ * yz_};
    const double cofactor_zz{xx_ * yy_ - xy_ * yx_};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy,
            cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  constexpr Dyad Adjugate() const noexcept { return Cofactors().Transpose(); }

  Dyad Inverse() const;

  std::string Print() const noexcept {
    return "(" + PhQ::Print(xx_) + ", " + PhQ::Print(xy_) + ", " +
           PhQ::Print(xz_) + "; " + PhQ::Print(yx_) + ", " + PhQ::Print(yy_) +
           ", " + PhQ::Print(yz_) + "; " + PhQ::Print(zx_) + ", " +
           PhQ::Print(zy_) + ", " + PhQ::Print(zz_) + ")";
  }

  std::string Json() const noexcept {
    return "{\"xx\":" + PhQ::Print(xx_) + ",\"xy\":" + PhQ::Print(xy_) +
           ",\"xz\":" + PhQ::Print(xz_) + ",\"yx\":" + PhQ::Print(yx_) +
           ",\"yy\":" + PhQ::Print(yy_) + ",\"yz\":" + PhQ::Print(yz_) +
           ",\"zx\":" + PhQ::Print(zx_) + ",\"zy\":" + PhQ::Print(zy_) +
           ",\"zz\":" + PhQ::Print(zz_) + "}";
  }

  std::string Xml() const noexcept {
    return "<xx>" + PhQ::Print(xx_) + "</xx><xy>" + PhQ::Print(xy_) +
           "</xy><xz>" + PhQ::Print(xz_) + "</xz><yx>" + PhQ::Print(yx_) +
           "</yx><yy>" + PhQ::Print(yy_) + "</yy><yz>" + PhQ::Print(yz_) +
           "</yz><zx>" + PhQ::Print(zx_) + "</zx><zy>" + PhQ::Print(zy_) +
           "</zy><zz>" + PhQ::Print(zz_) + "</zz>";
  }

  std::string Yaml() const noexcept {
    return "{xx:" + PhQ::Print(xx_) + ",xy:" + PhQ::Print(xy_) +
           ",xz:" + PhQ::Print(xz_) + ",yx:" + PhQ::Print(yx_) +
           ",yy:" + PhQ::Print(yy_) + ",yz:" + PhQ::Print(yz_) +
           ",zx:" + PhQ::Print(zx_) + ",zy:" + PhQ::Print(zy_) +
           ",zz:" + PhQ::Print(zz_) + "}";
  }

  constexpr void operator+=(const Dyad& dyad) noexcept {
    xx_ += dyad.xx_;
    xy_ += dyad.xy_;
    xz_ += dyad.xz_;
    yx_ += dyad.yx_;
    yy_ += dyad.yy_;
    yz_ += dyad.yz_;
    zx_ += dyad.zx_;
    zy_ += dyad.zy_;
    zz_ += dyad.zz_;
  }

  constexpr void operator-=(const Dyad& dyad) noexcept {
    xx_ -= dyad.xx_;
    xy_ -= dyad.xy_;
    xz_ -= dyad.xz_;
    yx_ -= dyad.yx_;
    yy_ -= dyad.yy_;
    yz_ -= dyad.yz_;
    zx_ -= dyad.zx_;
    zy_ -= dyad.zy_;
    zz_ -= dyad.zz_;
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

private:
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

constexpr bool operator==(const Dyad& left, const Dyad& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() &&
          left.xz() == right.xz() && left.yx() == right.yx() &&
          left.yy() == right.yy() && left.yz() == right.yz() &&
          left.zx() == right.zx() && left.zy() == right.zy() &&
          left.zz() == right.zz());
}

constexpr bool operator!=(const Dyad& left, const Dyad& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() ||
          left.xz() != right.xz() || left.yx() != right.yx() ||
          left.yy() != right.yy() || left.yz() != right.yz() ||
          left.zx() != right.zx() || left.zy() != right.zy() ||
          left.zz() != right.zz());
}

constexpr Dyad operator+(const Dyad& left, const Dyad& right) noexcept {
  return {
      left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
      left.yx() + right.yx(), left.yy() + right.yy(), left.yz() + right.yz(),
      left.zx() + right.zx(), left.zy() + right.zy(), left.zz() + right.zz()};
}

constexpr Dyad operator-(const Dyad& left, const Dyad& right) noexcept {
  return {
      left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
      left.yx() - right.yx(), left.yy() - right.yy(), left.yz() - right.yz(),
      left.zx() - right.zx(), left.zy() - right.zy(), left.zz() - right.zz()};
}

constexpr Dyad operator*(const Dyad& dyad, const double real) noexcept {
  return {dyad.xx() * real, dyad.xy() * real, dyad.xz() * real,
          dyad.yx() * real, dyad.yy() * real, dyad.yz() * real,
          dyad.zx() * real, dyad.zy() * real, dyad.zz() * real};
}

constexpr Dyad operator*(const double real, const Dyad& dyad) noexcept {
  return {dyad * real};
}

constexpr Vector operator*(const Dyad& dyad, const Vector& vector) noexcept {
  return {
      dyad.xx() * vector.x() + dyad.xy() * vector.y() + dyad.xz() * vector.z(),
      dyad.yx() * vector.x() + dyad.yy() * vector.y() + dyad.yz() * vector.z(),
      dyad.zx() * vector.x() + dyad.zy() * vector.y() + dyad.zz() * vector.z()};
}

inline constexpr Dyad operator*(const SymmetricDyad& left,
                                const SymmetricDyad& right) noexcept {
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

inline constexpr Dyad operator*(const SymmetricDyad& symdyad,
                                const Dyad& dyad) noexcept {
  return {symdyad.xx() * dyad.xx() + symdyad.xy() * dyad.yx() +
              symdyad.xz() * dyad.zx(),
          symdyad.xx() * dyad.xy() + symdyad.xy() * dyad.yy() +
              symdyad.xz() * dyad.zy(),
          symdyad.xx() * dyad.xz() + symdyad.xy() * dyad.yz() +
              symdyad.xz() * dyad.zz(),
          symdyad.xy() * dyad.xx() + symdyad.yy() * dyad.yx() +
              symdyad.yz() * dyad.zx(),
          symdyad.xy() * dyad.xy() + symdyad.yy() * dyad.yy() +
              symdyad.yz() * dyad.zy(),
          symdyad.xy() * dyad.xz() + symdyad.yy() * dyad.yz() +
              symdyad.yz() * dyad.zz(),
          symdyad.xz() * dyad.xx() + symdyad.yz() * dyad.yx() +
              symdyad.zz() * dyad.zx(),
          symdyad.xz() * dyad.xy() + symdyad.yz() * dyad.yy() +
              symdyad.zz() * dyad.zy(),
          symdyad.xz() * dyad.xz() + symdyad.yz() * dyad.yz() +
              symdyad.zz() * dyad.zz()};
}

inline constexpr Dyad operator*(const Dyad& dyad,
                                const SymmetricDyad& symdyad) noexcept {
  return {dyad.xx() * symdyad.xx() + dyad.xy() * symdyad.yx() +
              dyad.xz() * symdyad.zx(),
          dyad.xx() * symdyad.xy() + dyad.xy() * symdyad.yy() +
              dyad.xz() * symdyad.zy(),
          dyad.xx() * symdyad.xz() + dyad.xy() * symdyad.yz() +
              dyad.xz() * symdyad.zz(),
          dyad.yx() * symdyad.xx() + dyad.yy() * symdyad.yx() +
              dyad.yz() * symdyad.zx(),
          dyad.yx() * symdyad.xy() + dyad.yy() * symdyad.yy() +
              dyad.yz() * symdyad.zy(),
          dyad.yx() * symdyad.xz() + dyad.yy() * symdyad.yz() +
              dyad.yz() * symdyad.zz(),
          dyad.zx() * symdyad.xx() + dyad.zy() * symdyad.yx() +
              dyad.zz() * symdyad.zx(),
          dyad.zx() * symdyad.xy() + dyad.zy() * symdyad.yy() +
              dyad.zz() * symdyad.zy(),
          dyad.zx() * symdyad.xz() + dyad.zy() * symdyad.yz() +
              dyad.zz() * symdyad.zz()};
}

constexpr Dyad operator*(const Dyad& left, const Dyad& right) noexcept {
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

constexpr Dyad operator/(const Dyad& dyad, const double real) noexcept {
  return {dyad.xx() / real, dyad.xy() / real, dyad.xz() / real,
          dyad.yx() / real, dyad.yy() / real, dyad.yz() / real,
          dyad.zx() / real, dyad.zy() / real, dyad.zz() / real};
}

Dyad Dyad::Inverse() const {
  const double determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return Adjugate() / determinant_;
  } else {
    throw std::runtime_error{"Cannot compute the inverse of " + Print() +
                             " because its determinant is 0."};
  }
}

std::ostream& operator<<(std::ostream& stream, const Dyad& dyad) noexcept {
  stream << dyad.Print();
  return stream;
}

inline constexpr Dyad Vector::Dyadic(const Vector& vector) const noexcept {
  return {x_y_z_[0] * vector.x_y_z_[0], x_y_z_[0] * vector.x_y_z_[1],
          x_y_z_[0] * vector.x_y_z_[2], x_y_z_[1] * vector.x_y_z_[0],
          x_y_z_[1] * vector.x_y_z_[1], x_y_z_[1] * vector.x_y_z_[2],
          x_y_z_[2] * vector.x_y_z_[0], x_y_z_[2] * vector.x_y_z_[1],
          x_y_z_[2] * vector.x_y_z_[2]};
}

}  // namespace Value

inline constexpr Value::Dyad Direction::Dyadic(
    const PhQ::Direction& direction) const noexcept {
  return {x_y_z_[0] * direction.x_y_z_[0], x_y_z_[0] * direction.x_y_z_[1],
          x_y_z_[0] * direction.x_y_z_[2], x_y_z_[1] * direction.x_y_z_[0],
          x_y_z_[1] * direction.x_y_z_[1], x_y_z_[1] * direction.x_y_z_[2],
          x_y_z_[2] * direction.x_y_z_[0], x_y_z_[2] * direction.x_y_z_[1],
          x_y_z_[2] * direction.x_y_z_[2]};
}

inline constexpr Value::Dyad Direction::Dyadic(
    const Value::Vector& vector) const noexcept {
  return {
      x_y_z_[0] * vector.x(), x_y_z_[0] * vector.y(), x_y_z_[0] * vector.z(),
      x_y_z_[1] * vector.x(), x_y_z_[1] * vector.y(), x_y_z_[1] * vector.z(),
      x_y_z_[2] * vector.x(), x_y_z_[2] * vector.y(), x_y_z_[2] * vector.z()};
}

inline constexpr Value::Dyad Value::Vector::Dyadic(
    const PhQ::Direction& direction) const noexcept {
  return {x_y_z_[0] * direction.x(), x_y_z_[0] * direction.y(),
          x_y_z_[0] * direction.z(), x_y_z_[1] * direction.x(),
          x_y_z_[1] * direction.y(), x_y_z_[1] * direction.z(),
          x_y_z_[2] * direction.x(), x_y_z_[2] * direction.y(),
          x_y_z_[2] * direction.z()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Value::Dyad> {
  size_t operator()(const PhQ::Value::Dyad& dyad) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(dyad.xx());
    result = 31 * result + hash<double>()(dyad.xy());
    result = 31 * result + hash<double>()(dyad.xz());
    result = 31 * result + hash<double>()(dyad.yx());
    result = 31 * result + hash<double>()(dyad.yy());
    result = 31 * result + hash<double>()(dyad.yz());
    result = 31 * result + hash<double>()(dyad.zx());
    result = 31 * result + hash<double>()(dyad.zy());
    result = 31 * result + hash<double>()(dyad.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP
