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

namespace PhQ {

namespace Value {

// Forward declaration for PhQ::Convert functions.
class SymmetricDyad;

}  // namespace Value

// Forward declaration for PhQ::Value::SymmetricDyad class.
template <typename Unit>
void Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
             const Unit new_unit) noexcept;

// Forward declaration for PhQ::Value::SymmetricDyad class.
template <typename Unit>
void Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept;

namespace Value {

class SymmetricDyad {
public:
  constexpr SymmetricDyad() noexcept : xx_xy_xz_yy_yz_zz_() {}

  constexpr SymmetricDyad(const double xx, const double xy, const double xz,
                          const double yy, const double yz,
                          const double zz) noexcept
      : xx_xy_xz_yy_yz_zz_({xx, xy, xz, yy, yz, zz}) {}

  constexpr SymmetricDyad(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept
      : xx_xy_xz_yy_yz_zz_(xx_xy_xz_yy_yz_zz) {}

  static constexpr SymmetricDyad Zero() noexcept {
    return std::array<double, 6>{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  }

  inline constexpr const std::array<double, 6>& xx_xy_xz_yy_yz_zz()
      const noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  inline constexpr double xx() const noexcept { return xx_xy_xz_yy_yz_zz_[0]; }

  inline constexpr double xy() const noexcept { return xx_xy_xz_yy_yz_zz_[1]; }

  inline constexpr double xz() const noexcept { return xx_xy_xz_yy_yz_zz_[2]; }

  inline constexpr double yx() const noexcept { return xx_xy_xz_yy_yz_zz_[1]; }

  inline constexpr double yy() const noexcept { return xx_xy_xz_yy_yz_zz_[3]; }

  inline constexpr double yz() const noexcept { return xx_xy_xz_yy_yz_zz_[4]; }

  inline constexpr double zx() const noexcept { return xx_xy_xz_yy_yz_zz_[2]; }

  inline constexpr double zy() const noexcept { return xx_xy_xz_yy_yz_zz_[4]; }

  inline constexpr double zz() const noexcept { return xx_xy_xz_yy_yz_zz_[5]; }

  inline constexpr double Trace() const noexcept { return xx() + yy() + zz(); }

  inline constexpr double Determinant() const noexcept {
    return (xx() * (yy() * zz() - yz() * zy()) +
            xy() * (yz() * zx() - yx() * zz()) +
            xz() * (yx() * zy() - yy() * zx()));
  }

  inline constexpr SymmetricDyad Transpose() const noexcept { return *this; }

  inline constexpr SymmetricDyad Cofactors() const noexcept {
    const double cofactor_xx{yy() * zz() - yz() * yz()};
    const double cofactor_xy{xz() * yz() - xy() * zz()};
    const double cofactor_xz{xy() * yz() - xz() * yy()};
    const double cofactor_yy{xx() * zz() - xz() * xz()};
    const double cofactor_yz{xy() * xz() - xx() * yz()};
    const double cofactor_zz{xx() * yy() - xy() * xy()};
    return {cofactor_xx, cofactor_xy, cofactor_xz,
            cofactor_yy, cofactor_yz, cofactor_zz};
  }

  inline constexpr SymmetricDyad Adjugate() const noexcept {
    // Normally, this would be cofactors().transpose(), but since this is a
    // symmetric dyad, the transpose is not needed.
    return Cofactors();
  }

  inline SymmetricDyad Inverse() const;

  inline std::string Print() const noexcept {
    return "(" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ", " +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ", " +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "; " +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + ", " +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "; " +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  inline std::string Json() const noexcept {
    return "{\"xx\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) +
           ",\"xy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) +
           ",\"xz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) +
           ",\"yy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) +
           ",\"yz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) +
           ",\"zz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  inline std::string Xml() const noexcept {
    return "<xx>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + "</xx><xy>" +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + "</xy><xz>" +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "</xz><yy>" +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + "</yy><yz>" +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "</yz><zz>" +
           PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "</zz>";
  }

  inline std::string Yaml() const noexcept {
    return "{xx:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) +
           ",xy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) +
           ",xz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) +
           ",yy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) +
           ",yz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) +
           ",zz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  inline constexpr void operator+=(const SymmetricDyad& symdyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += symdyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += symdyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += symdyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += symdyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += symdyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += symdyad.xx_xy_xz_yy_yz_zz_[5];
  }

  inline constexpr void operator-=(const SymmetricDyad& symdyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= symdyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= symdyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= symdyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= symdyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= symdyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= symdyad.xx_xy_xz_yy_yz_zz_[5];
  }

  inline constexpr void operator*=(const double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= real;
    xx_xy_xz_yy_yz_zz_[1] *= real;
    xx_xy_xz_yy_yz_zz_[2] *= real;
    xx_xy_xz_yy_yz_zz_[3] *= real;
    xx_xy_xz_yy_yz_zz_[4] *= real;
    xx_xy_xz_yy_yz_zz_[5] *= real;
  }

  inline constexpr void operator/=(const double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] /= real;
    xx_xy_xz_yy_yz_zz_[1] /= real;
    xx_xy_xz_yy_yz_zz_[2] /= real;
    xx_xy_xz_yy_yz_zz_[3] /= real;
    xx_xy_xz_yy_yz_zz_[4] /= real;
    xx_xy_xz_yy_yz_zz_[5] /= real;
  }

private:
  std::array<double, 6> xx_xy_xz_yy_yz_zz_;

  template <typename Unit>
  friend void PhQ::Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
                           const Unit new_unit) noexcept;

  template <typename Unit>
  friend void PhQ::Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
                           const UnitSystem new_unit_system) noexcept;
};

inline constexpr bool operator==(const SymmetricDyad& left,
                                 const SymmetricDyad& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() &&
          left.xz() == right.xz() && left.yy() == right.yy() &&
          left.yz() == right.yz() && left.zz() == right.zz());
}

inline constexpr bool operator!=(const SymmetricDyad& left,
                                 const SymmetricDyad& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() ||
          left.xz() != right.xz() || left.yy() != right.yy() ||
          left.yz() != right.yz() || left.zz() != right.zz());
}

inline constexpr SymmetricDyad operator+(const SymmetricDyad& left,
                                         const SymmetricDyad& right) noexcept {
  return {left.xx() + right.xx(), left.xy() + right.xy(),
          left.xz() + right.xz(), left.yy() + right.yy(),
          left.yz() + right.yz(), left.zz() + right.zz()};
}

inline constexpr SymmetricDyad operator-(const SymmetricDyad& left,
                                         const SymmetricDyad& right) noexcept {
  return {left.xx() - right.xx(), left.xy() - right.xy(),
          left.xz() - right.xz(), left.yy() - right.yy(),
          left.yz() - right.yz(), left.zz() - right.zz()};
}

inline constexpr SymmetricDyad operator*(const SymmetricDyad& symdyad,
                                         const double real) noexcept {
  return {symdyad.xx() * real, symdyad.xy() * real, symdyad.xz() * real,
          symdyad.yy() * real, symdyad.yz() * real, symdyad.zz() * real};
}

inline constexpr SymmetricDyad operator*(
    const double real, const SymmetricDyad& symdyad) noexcept {
  return {symdyad * real};
}

inline constexpr Vector operator*(const SymmetricDyad& symdyad,
                                  const Direction& direction) noexcept {
  return {symdyad.xx() * direction.x() + symdyad.xy() * direction.y() +
              symdyad.xz() * direction.z(),
          symdyad.xy() * direction.x() + symdyad.yy() * direction.y() +
              symdyad.yz() * direction.z(),
          symdyad.xz() * direction.x() + symdyad.yz() * direction.y() +
              symdyad.zz() * direction.z()};
}

inline constexpr Vector operator*(const SymmetricDyad& symdyad,
                                  const Vector& vector) noexcept {
  return {symdyad.xx() * vector.x() + symdyad.xy() * vector.y() +
              symdyad.xz() * vector.z(),
          symdyad.xy() * vector.x() + symdyad.yy() * vector.y() +
              symdyad.yz() * vector.z(),
          symdyad.xz() * vector.x() + symdyad.yz() * vector.y() +
              symdyad.zz() * vector.z()};
}

inline constexpr Dyad operator*(const SymmetricDyad& left,
                                const SymmetricDyad& right) noexcept;

inline constexpr Dyad operator*(const SymmetricDyad& symdyad,
                                const Dyad& dyad) noexcept;

inline constexpr SymmetricDyad operator/(const SymmetricDyad& symdyad,
                                         const double real) noexcept {
  return {symdyad.xx() / real, symdyad.xy() / real, symdyad.xz() / real,
          symdyad.yy() / real, symdyad.yz() / real, symdyad.zz() / real};
}

inline SymmetricDyad SymmetricDyad::Inverse() const {
  const double determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return Adjugate() / determinant_;
  } else {
    throw std::runtime_error{"Cannot compute the inverse of " + Print() +
                             " because its determinant is 0."};
  }
}

inline std::ostream& operator<<(std::ostream& stream,
                                const SymmetricDyad& symmetric) noexcept {
  stream << symmetric.Print();
  return stream;
}

}  // namespace Value

}  // namespace PhQ

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
