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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYADIC_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYADIC_HPP

#include "Vector.hpp"

namespace PhQ::Value {

class SymmetricDyadic {
public:
  constexpr SymmetricDyadic() noexcept
      : xx_(), xy_(), xz_(), yy_(), yz_(), zz_() {}

  constexpr SymmetricDyadic(const double xx, const double xy, const double xz,
                            const double yy, const double yz,
                            const double zz) noexcept
      : xx_(xx), xy_(xy), xz_(xz), yy_(yy), yz_(yz), zz_(zz) {}

  constexpr SymmetricDyadic(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept
      : xx_(xx_xy_xz_yy_yz_zz[0]),
        xy_(xx_xy_xz_yy_yz_zz[1]),
        xz_(xx_xy_xz_yy_yz_zz[2]),
        yy_(xx_xy_xz_yy_yz_zz[3]),
        yz_(xx_xy_xz_yy_yz_zz[4]),
        zz_(xx_xy_xz_yy_yz_zz[5]) {}

  static constexpr SymmetricDyadic Zero() noexcept {
    return {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  }

  inline constexpr double xx() const noexcept { return xx_; }

  inline constexpr double xy() const noexcept { return xy_; }

  inline constexpr double xz() const noexcept { return xz_; }

  inline constexpr double yx() const noexcept { return xy_; }

  inline constexpr double yy() const noexcept { return yy_; }

  inline constexpr double yz() const noexcept { return yz_; }

  inline constexpr double zx() const noexcept { return xz_; }

  inline constexpr double zy() const noexcept { return yz_; }

  inline constexpr double zz() const noexcept { return zz_; }

  static bool is_symmetric() noexcept { return true; }

  inline constexpr double trace() const noexcept { return xx_ + yy_ + zz_; }

  inline constexpr double determinant() const noexcept {
    return (xx_ * (yy_ * zz_ - yz_ * yz_) + xy_ * (xz_ * yz_ - xy_ * zz_) +
            xz_ * (xy_ * yz_ - xz_ * yy_));
  }

  inline constexpr SymmetricDyadic transpose() const noexcept { return *this; }

  constexpr SymmetricDyadic cofactors() const noexcept {
    const double cofactor_xx{yy_ * zz_ - yz_ * yz_};
    const double cofactor_xy{xz_ * yz_ - xy_ * zz_};
    const double cofactor_xz{xy_ * yz_ - xz_ * yy_};
    const double cofactor_yy{xx_ * zz_ - xz_ * xz_};
    const double cofactor_yz{xy_ * xz_ - xx_ * yz_};
    const double cofactor_zz{xx_ * yy_ - xy_ * xy_};
    return {cofactor_xx, cofactor_xy, cofactor_xz,
            cofactor_yy, cofactor_yz, cofactor_zz};
  }

  constexpr SymmetricDyadic adjugate() const noexcept {
    // Normally, this would be cofactors().transpose(), but since this is a
    // symmetric dyadic, the transpose is not needed.
    return cofactors();
  }

  constexpr SymmetricDyadic inverse() const;

  std::string print() const noexcept {
    return "(" + PhQ::print(xx_) + ", " + PhQ::print(xy_) + ", " +
           PhQ::print(xz_) + "; " + PhQ::print(yy_) + ", " + PhQ::print(yz_) +
           "; " + PhQ::print(zz_) + ")";
  }

  std::string json() const noexcept {
    return "{\"xx\":" + PhQ::print(xx_) + ",\"xy\":" + PhQ::print(xy_) +
           ",\"xz\":" + PhQ::print(xz_) + ",\"yy\":" + PhQ::print(yy_) +
           ",\"yz\":" + PhQ::print(yz_) + ",\"zz\":" + PhQ::print(zz_) + "}";
  }

  std::string xml() const noexcept {
    return "<xx>" + PhQ::print(xx_) + "</xx><xy>" + PhQ::print(xy_) +
           "</xy><xz>" + PhQ::print(xz_) + "</xz><yy>" + PhQ::print(yy_) +
           "</yy><yz>" + PhQ::print(yz_) + "</yz><zz>" + PhQ::print(zz_) +
           "</zz>";
  }

  std::string yaml() const noexcept {
    return "{xx:" + PhQ::print(xx_) + ",xy:" + PhQ::print(xy_) +
           ",xz:" + PhQ::print(xz_) + ",yy:" + PhQ::print(yy_) +
           ",yz:" + PhQ::print(yz_) + ",zz:" + PhQ::print(zz_) + "}";
  }

  constexpr void operator+=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_ += symmetric_dyadic.xx_;
    xy_ += symmetric_dyadic.xy_;
    xz_ += symmetric_dyadic.xz_;
    yy_ += symmetric_dyadic.yy_;
    yz_ += symmetric_dyadic.yz_;
    zz_ += symmetric_dyadic.zz_;
  }

  constexpr void operator-=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_ -= symmetric_dyadic.xx_;
    xy_ -= symmetric_dyadic.xy_;
    xz_ -= symmetric_dyadic.xz_;
    yy_ -= symmetric_dyadic.yy_;
    yz_ -= symmetric_dyadic.yz_;
    zz_ -= symmetric_dyadic.zz_;
  }

  constexpr void operator*=(const double real) noexcept {
    xx_ *= real;
    xy_ *= real;
    xz_ *= real;
    yy_ *= real;
    yz_ *= real;
    zz_ *= real;
  }

  constexpr void operator/=(const double real) noexcept {
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

constexpr bool operator==(const SymmetricDyadic& left,
                          const SymmetricDyadic& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() &&
          left.xz() == right.xz() && left.yy() == right.yy() &&
          left.yz() == right.yz() && left.zz() == right.zz());
}

constexpr bool operator!=(const SymmetricDyadic& left,
                          const SymmetricDyadic& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() ||
          left.xz() != right.xz() || left.yy() != right.yy() ||
          left.yz() != right.yz() || left.zz() != right.zz());
}

constexpr SymmetricDyadic operator+(const SymmetricDyadic& left,
                                    const SymmetricDyadic& right) noexcept {
  return {left.xx() + right.xx(), left.xy() + right.xy(),
          left.xz() + right.xz(), left.yy() + right.yy(),
          left.yz() + right.yz(), left.zz() + right.zz()};
}

constexpr SymmetricDyadic operator-(const SymmetricDyadic& left,
                                    const SymmetricDyadic& right) noexcept {
  return {left.xx() - right.xx(), left.xy() - right.xy(),
          left.xz() - right.xz(), left.yy() - right.yy(),
          left.yz() - right.yz(), left.zz() - right.zz()};
}

constexpr SymmetricDyadic operator*(const SymmetricDyadic& symmetric_dyadic,
                                    const double real) noexcept {
  return {symmetric_dyadic.xx() * real, symmetric_dyadic.xy() * real,
          symmetric_dyadic.xz() * real, symmetric_dyadic.yy() * real,
          symmetric_dyadic.yz() * real, symmetric_dyadic.zz() * real};
}

constexpr SymmetricDyadic operator*(
    const double real, const SymmetricDyadic& symmetric_dyadic) noexcept {
  return {symmetric_dyadic * real};
}

constexpr Vector operator*(const SymmetricDyadic& symmetric_dyadic,
                           const Direction& direction) noexcept {
  return {symmetric_dyadic.xx() * direction.x() +
              symmetric_dyadic.xy() * direction.y() +
              symmetric_dyadic.xz() * direction.z(),
          symmetric_dyadic.xy() * direction.x() +
              symmetric_dyadic.yy() * direction.y() +
              symmetric_dyadic.yz() * direction.z(),
          symmetric_dyadic.xz() * direction.x() +
              symmetric_dyadic.yz() * direction.y() +
              symmetric_dyadic.zz() * direction.z()};
}

constexpr Vector operator*(const SymmetricDyadic& symmetric_dyadic,
                           const Vector& vector) noexcept {
  return {
      symmetric_dyadic.xx() * vector.x() + symmetric_dyadic.xy() * vector.y() +
          symmetric_dyadic.xz() * vector.z(),
      symmetric_dyadic.xy() * vector.x() + symmetric_dyadic.yy() * vector.y() +
          symmetric_dyadic.yz() * vector.z(),
      symmetric_dyadic.xz() * vector.x() + symmetric_dyadic.yz() * vector.y() +
          symmetric_dyadic.zz() * vector.z()};
}

constexpr Dyadic operator*(const SymmetricDyadic& left,
                           const SymmetricDyadic& right) noexcept;

constexpr Dyadic operator*(const SymmetricDyadic& symmetric_dyadic,
                           const Dyadic& dyadic) noexcept;

constexpr SymmetricDyadic operator/(const SymmetricDyadic& symmetric_dyadic,
                                    const double real) noexcept {
  return {symmetric_dyadic.xx() / real, symmetric_dyadic.xy() / real,
          symmetric_dyadic.xz() / real, symmetric_dyadic.yy() / real,
          symmetric_dyadic.yz() / real, symmetric_dyadic.zz() / real};
}

constexpr SymmetricDyadic SymmetricDyadic::inverse() const {
  const double determinant_{determinant()};
  if (determinant_ != 0.0) {
    return adjugate() / determinant_;
  } else {
    throw std::runtime_error{"Cannot compute the inverse of " + print() +
                             " because its determinant is 0."};
  }
}

std::ostream& operator<<(std::ostream& stream,
                         const SymmetricDyadic& symmetric) noexcept {
  stream << symmetric.print();
  return stream;
}

}  // namespace PhQ::Value

namespace std {

template <>
struct hash<PhQ::Value::SymmetricDyadic> {
  size_t operator()(const PhQ::Value::SymmetricDyadic& symmetric) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(symmetric.xx());
    result = 31 * result + hash<double>()(symmetric.xy());
    result = 31 * result + hash<double>()(symmetric.xz());
    result = 31 * result + hash<double>()(symmetric.yy());
    result = 31 * result + hash<double>()(symmetric.yz());
    result = 31 * result + hash<double>()(symmetric.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYADIC_HPP
