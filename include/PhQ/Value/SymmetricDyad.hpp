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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYAD_HPP

#include "Vector.hpp"

namespace PhQ::Value {

class SymmetricDyad {
public:
  constexpr SymmetricDyad() noexcept
      : xx_(), xy_(), xz_(), yy_(), yz_(), zz_() {}

  constexpr SymmetricDyad(const double xx, const double xy, const double xz,
                          const double yy, const double yz,
                          const double zz) noexcept
      : xx_(xx), xy_(xy), xz_(xz), yy_(yy), yz_(yz), zz_(zz) {}

  constexpr SymmetricDyad(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept
      : xx_(xx_xy_xz_yy_yz_zz[0]),
        xy_(xx_xy_xz_yy_yz_zz[1]),
        xz_(xx_xy_xz_yy_yz_zz[2]),
        yy_(xx_xy_xz_yy_yz_zz[3]),
        yz_(xx_xy_xz_yy_yz_zz[4]),
        zz_(xx_xy_xz_yy_yz_zz[5]) {}

  static constexpr SymmetricDyad Zero() noexcept {
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

  static bool IsSymmetric() noexcept { return true; }

  inline constexpr double Trace() const noexcept { return xx_ + yy_ + zz_; }

  inline constexpr double Determinant() const noexcept {
    return (xx_ * (yy_ * zz_ - yz_ * yz_) + xy_ * (xz_ * yz_ - xy_ * zz_) +
            xz_ * (xy_ * yz_ - xz_ * yy_));
  }

  inline constexpr SymmetricDyad Transpose() const noexcept { return *this; }

  constexpr SymmetricDyad Cofactors() const noexcept {
    const double cofactor_xx{yy_ * zz_ - yz_ * yz_};
    const double cofactor_xy{xz_ * yz_ - xy_ * zz_};
    const double cofactor_xz{xy_ * yz_ - xz_ * yy_};
    const double cofactor_yy{xx_ * zz_ - xz_ * xz_};
    const double cofactor_yz{xy_ * xz_ - xx_ * yz_};
    const double cofactor_zz{xx_ * yy_ - xy_ * xy_};
    return {cofactor_xx, cofactor_xy, cofactor_xz,
            cofactor_yy, cofactor_yz, cofactor_zz};
  }

  constexpr SymmetricDyad Adjugate() const noexcept {
    // Normally, this would be cofactors().transpose(), but since this is a
    // symmetric dyad, the transpose is not needed.
    return Cofactors();
  }

  constexpr SymmetricDyad Inverse() const;

  std::string Print() const noexcept {
    return "(" + PhQ::Print(xx_) + ", " + PhQ::Print(xy_) + ", " +
           PhQ::Print(xz_) + "; " + PhQ::Print(yy_) + ", " + PhQ::Print(yz_) +
           "; " + PhQ::Print(zz_) + ")";
  }

  std::string Json() const noexcept {
    return "{\"xx\":" + PhQ::Print(xx_) + ",\"xy\":" + PhQ::Print(xy_) +
           ",\"xz\":" + PhQ::Print(xz_) + ",\"yy\":" + PhQ::Print(yy_) +
           ",\"yz\":" + PhQ::Print(yz_) + ",\"zz\":" + PhQ::Print(zz_) + "}";
  }

  std::string Xml() const noexcept {
    return "<xx>" + PhQ::Print(xx_) + "</xx><xy>" + PhQ::Print(xy_) +
           "</xy><xz>" + PhQ::Print(xz_) + "</xz><yy>" + PhQ::Print(yy_) +
           "</yy><yz>" + PhQ::Print(yz_) + "</yz><zz>" + PhQ::Print(zz_) +
           "</zz>";
  }

  std::string Yaml() const noexcept {
    return "{xx:" + PhQ::Print(xx_) + ",xy:" + PhQ::Print(xy_) +
           ",xz:" + PhQ::Print(xz_) + ",yy:" + PhQ::Print(yy_) +
           ",yz:" + PhQ::Print(yz_) + ",zz:" + PhQ::Print(zz_) + "}";
  }

  constexpr void operator+=(const SymmetricDyad& symdyad) noexcept {
    xx_ += symdyad.xx_;
    xy_ += symdyad.xy_;
    xz_ += symdyad.xz_;
    yy_ += symdyad.yy_;
    yz_ += symdyad.yz_;
    zz_ += symdyad.zz_;
  }

  constexpr void operator-=(const SymmetricDyad& symdyad) noexcept {
    xx_ -= symdyad.xx_;
    xy_ -= symdyad.xy_;
    xz_ -= symdyad.xz_;
    yy_ -= symdyad.yy_;
    yz_ -= symdyad.yz_;
    zz_ -= symdyad.zz_;
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

private:
  double xx_;

  double xy_;

  double xz_;

  double yy_;

  double yz_;

  double zz_;
};

constexpr bool operator==(const SymmetricDyad& left,
                          const SymmetricDyad& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() &&
          left.xz() == right.xz() && left.yy() == right.yy() &&
          left.yz() == right.yz() && left.zz() == right.zz());
}

constexpr bool operator!=(const SymmetricDyad& left,
                          const SymmetricDyad& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() ||
          left.xz() != right.xz() || left.yy() != right.yy() ||
          left.yz() != right.yz() || left.zz() != right.zz());
}

constexpr SymmetricDyad operator+(const SymmetricDyad& left,
                                  const SymmetricDyad& right) noexcept {
  return {left.xx() + right.xx(), left.xy() + right.xy(),
          left.xz() + right.xz(), left.yy() + right.yy(),
          left.yz() + right.yz(), left.zz() + right.zz()};
}

constexpr SymmetricDyad operator-(const SymmetricDyad& left,
                                  const SymmetricDyad& right) noexcept {
  return {left.xx() - right.xx(), left.xy() - right.xy(),
          left.xz() - right.xz(), left.yy() - right.yy(),
          left.yz() - right.yz(), left.zz() - right.zz()};
}

constexpr SymmetricDyad operator*(const SymmetricDyad& symdyad,
                                  const double real) noexcept {
  return {symdyad.xx() * real, symdyad.xy() * real, symdyad.xz() * real,
          symdyad.yy() * real, symdyad.yz() * real, symdyad.zz() * real};
}

constexpr SymmetricDyad operator*(const double real,
                                  const SymmetricDyad& symdyad) noexcept {
  return {symdyad * real};
}

constexpr Vector operator*(const SymmetricDyad& symdyad,
                           const Direction& direction) noexcept {
  return {symdyad.xx() * direction.x() + symdyad.xy() * direction.y() +
              symdyad.xz() * direction.z(),
          symdyad.xy() * direction.x() + symdyad.yy() * direction.y() +
              symdyad.yz() * direction.z(),
          symdyad.xz() * direction.x() + symdyad.yz() * direction.y() +
              symdyad.zz() * direction.z()};
}

constexpr Vector operator*(const SymmetricDyad& symdyad,
                           const Vector& vector) noexcept {
  return {symdyad.xx() * vector.x() + symdyad.xy() * vector.y() +
              symdyad.xz() * vector.z(),
          symdyad.xy() * vector.x() + symdyad.yy() * vector.y() +
              symdyad.yz() * vector.z(),
          symdyad.xz() * vector.x() + symdyad.yz() * vector.y() +
              symdyad.zz() * vector.z()};
}

constexpr Dyad operator*(const SymmetricDyad& left,
                         const SymmetricDyad& right) noexcept;

constexpr Dyad operator*(const SymmetricDyad& symdyad,
                         const Dyad& dyad) noexcept;

constexpr SymmetricDyad operator/(const SymmetricDyad& symdyad,
                                  const double real) noexcept {
  return {symdyad.xx() / real, symdyad.xy() / real, symdyad.xz() / real,
          symdyad.yy() / real, symdyad.yz() / real, symdyad.zz() / real};
}

constexpr SymmetricDyad SymmetricDyad::Inverse() const {
  const double determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return Adjugate() / determinant_;
  } else {
    throw std::runtime_error{"Cannot compute the inverse of " + Print() +
                             " because its determinant is 0."};
  }
}

std::ostream& operator<<(std::ostream& stream,
                         const SymmetricDyad& symmetric) noexcept {
  stream << symmetric.Print();
  return stream;
}

}  // namespace PhQ::Value

namespace std {

template <>
struct hash<PhQ::Value::SymmetricDyad> {
  size_t operator()(const PhQ::Value::SymmetricDyad& symmetric) const {
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRICDYAD_HPP
