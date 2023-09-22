// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRIC_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRIC_DYAD_HPP

#include "Vector.hpp"

namespace PhQ::Value {

// Three-dimensional symmetric dyadic tensor value in Cartesian coordinates.
// Contains six components: xx, xy = yx, xz = zx, yy, yz = zy, and zz.
class SymmetricDyad {
public:
  // Default constructor. Constructs a three-dimensional symmetric dyadic tensor
  // value with uninitialized xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad() : xx_xy_xz_yy_yz_zz_() {}

  // Constructor. Constructs a three-dimensional symmetric dyadic tensor value
  // from the given xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad(const double xx, const double xy, const double xz,
                          const double yy, const double yz, const double zz)
    : xx_xy_xz_yy_yz_zz_({xx, xy, xz, yy, yz, zz}) {}

  // Constructor. Constructs a three-dimensional symmetric dyadic tensor value
  // from a given array representing its xx, xy, xz, yy, yz, and zz Cartesian
  // components.
  explicit constexpr SymmetricDyad(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz)
    : xx_xy_xz_yy_yz_zz_(xx_xy_xz_yy_yz_zz) {}

  // Destructor. Destroys this three-dimensional symmetric dyadic tensor value.
  ~SymmetricDyad() noexcept = default;

  // Copy constructor. Constructs a three-dimensional symmetric dyadic tensor
  // value by copying another one.
  constexpr SymmetricDyad(const SymmetricDyad& other) = default;

  // Copy assignment operator. Assigns the components of this three-dimensional
  // symmetric dyadic tensor value by copying another three-dimensional
  // symmetric dyadic tensor value.
  constexpr SymmetricDyad& operator=(const SymmetricDyad& other) = default;

  // Copy assignment operator. Assigns the components of this three-dimensional
  // symmetric dyadic tensor value by copying a given array representing its xx,
  // xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad& operator=(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz) {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
    return *this;
  }

  // Move constructor. Constructs a three-dimensional symmetric dyadic tensor
  // value by moving another one.
  constexpr SymmetricDyad(SymmetricDyad&& other) noexcept = default;

  // Move constructor. Constructs a three-dimensional symmetric dyadic tensor
  // value by moving a given array representing its xx, xy, xz, yy, yz, and zz
  // Cartesian components.
  constexpr SymmetricDyad(std::array<double, 6>&& xx_xy_xz_yy_yz_zz) noexcept
    : xx_xy_xz_yy_yz_zz_(std::move(xx_xy_xz_yy_yz_zz)) {}

  // Move assignment operator. Assigns the components of this three-dimensional
  // symmetric dyadic tensor value by moving another three-dimensional symmetric
  // dyadic tensor value.
  constexpr SymmetricDyad& operator=(SymmetricDyad&& other) noexcept = default;

  // Move assignment operator. Assigns the components of this three-dimensional
  // symmetric dyadic tensor value by moving a given array representing its xx,
  // xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad& operator=(
      std::array<double, 6>&& xx_xy_xz_yy_yz_zz) noexcept {
    xx_xy_xz_yy_yz_zz_ = std::move(xx_xy_xz_yy_yz_zz);
    return *this;
  }

  // Returns a three-dimensional symmetric dyadic tensor value with its xx, xy,
  // xz, yy, yz, and zz Cartesian components initialized to zero.
  static constexpr SymmetricDyad Zero() {
    return SymmetricDyad{
        std::array<double, 6>{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xx, xy, xz,
  // yy, yz, and zz Cartesian components as an array.
  constexpr const std::array<double, 6>& xx_xy_xz_yy_yz_zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xx Cartesian
  // component.
  constexpr double xx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xy = yx
  // Cartesian component.
  constexpr double xy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xz = zx
  // Cartesian component.
  constexpr double xz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yx = xy
  // Cartesian component.
  constexpr double yx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yy Cartesian
  // component.
  constexpr double yy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yz = zy
  // Cartesian component.
  constexpr double yz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zx = xz
  // Cartesian component.
  constexpr double zx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zy = yz
  // Cartesian component.
  constexpr double zy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zz Cartesian
  // component.
  constexpr double zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xx, xy, xz,
  // yy, yz, and zz Cartesian components as a mutable array.
  constexpr std::array<double, 6>& Mutable_xx_xy_xz_yy_yz_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xx Cartesian
  // component as a mutable value.
  constexpr double& Mutable_xx() noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xy = yx
  // Cartesian component as a mutable value.
  constexpr double& Mutable_xy() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's xz = zx
  // Cartesian component as a mutable value.
  constexpr double& Mutable_xz() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yx = xy
  // Cartesian component as a mutable value.
  constexpr double& Mutable_yx() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yy Cartesian
  // component as a mutable value.
  constexpr double& Mutable_yy() noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's yz = zy
  // Cartesian component as a mutable value.
  constexpr double& Mutable_yz() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zx = xz
  // Cartesian component as a mutable value.
  constexpr double& Mutable_zx() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zy = yz
  // Cartesian component as a mutable value.
  constexpr double& Mutable_zy() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor value's zz Cartesian
  // component as a mutable value.
  constexpr double& Mutable_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  // Sets this three-dimensional symmetric dyadic tensor value's xx, xy, xz, yy,
  // yz, and zz Cartesian components to the given values.
  constexpr void Set_xx_xy_xz_yy_yz_zz(
      const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's xx Cartesian
  // component to a given value.
  constexpr void Set_xx(const double xx) noexcept {
    xx_xy_xz_yy_yz_zz_[0] = xx;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's xy = yx
  // Cartesian component to a given value.
  constexpr void Set_xy(const double xy) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = xy;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's xz = zx
  // Cartesian component to a given value.
  constexpr void Set_xz(const double xz) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = xz;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's yx = xy
  // Cartesian component to a given value.
  constexpr void Set_yx(const double yx) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = yx;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's yy Cartesian
  // component to a given value.
  constexpr void Set_yy(const double yy) noexcept {
    xx_xy_xz_yy_yz_zz_[3] = yy;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's yz = zy
  // Cartesian component to a given value.
  constexpr void Set_yz(const double yz) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = yz;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's zx = xz
  // Cartesian component to a given value.
  constexpr void Set_zx(const double zx) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = zx;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's zy = yz
  // Cartesian component to a given value.
  constexpr void Set_zy(const double zy) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = zy;
  }

  // Sets this three-dimensional symmetric dyadic tensor value's zz Cartesian
  // component to a given value.
  constexpr void Set_zz(const double zz) noexcept {
    xx_xy_xz_yy_yz_zz_[5] = zz;
  }

  // Returns the trace of this three-dimensional symmetric dyadic tensor value.
  constexpr double Trace() const noexcept {
    return xx() + yy() + zz();
  }

  // Returns the determinant of this three-dimensional symmetric dyadic tensor
  // value.
  constexpr double Determinant() const noexcept {
    return xx() * (yy() * zz() - yz() * zy())
           + xy() * (yz() * zx() - yx() * zz())
           + xz() * (yx() * zy() - yy() * zx());
  }

  // Returns the transpose of this three-dimensional symmetric dyadic tensor
  // value.
  constexpr const SymmetricDyad& Transpose() const noexcept {
    return *this;
  }

  // Returns the cofactors of this three-dimensional symmetric dyadic tensor
  // value.
  constexpr SymmetricDyad Cofactors() const {
    const double cofactor_xx{yy() * zz() - yz() * yz()};
    const double cofactor_xy{xz() * yz() - xy() * zz()};
    const double cofactor_xz{xy() * yz() - xz() * yy()};
    const double cofactor_yy{xx() * zz() - xz() * xz()};
    const double cofactor_yz{xy() * xz() - xx() * yz()};
    const double cofactor_zz{xx() * yy() - xy() * xy()};
    return {cofactor_xx, cofactor_xy, cofactor_xz,
            cofactor_yy, cofactor_yz, cofactor_zz};
  }

  // Returns the adjugate of this three-dimensional symmetric dyadic tensor
  // value.
  constexpr SymmetricDyad Adjugate() const {
    // Normally, this would be cofactors().transpose(), but since this is a
    // symmetric dyad, the transpose is not needed.
    return Cofactors();
  }

  // Returns the inverse of this three-dimensional symmetric dyadic tensor
  // value if it exists, or std::nullopt otherwise.
  std::optional<SymmetricDyad> Inverse() const;

  // Prints this three-dimensional symmetric dyadic tensor value as a string.
  // Components are printed to double floating point precision.
  std::string Print() const {
    return "(" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "; "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "; "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  // Prints this three-dimensional symmetric dyadic tensor value as a string.
  // Components are printed to a given floating point precision.
  std::string Print(const Precision precision) const {
    return "(" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0], precision) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1], precision) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[2], precision) + "; "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[3], precision) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4], precision) + "; "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[5], precision) + ")";
  }

  // Serializes this three-dimensional symmetric dyadic tensor value as a JSON
  // message.
  std::string JSON() const {
    return "{\"xx\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0])
           + ",\"xy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1])
           + ",\"xz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + ",\"yy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",\"yz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4])
           + ",\"zz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  // Serializes this three-dimensional symmetric dyadic tensor value as an XML
  // message.
  std::string XML() const {
    return "<xx>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + "</xx><xy>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + "</xy><xz>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "</xz><yy>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + "</yy><yz>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "</yz><zz>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "</zz>";
  }

  // Serializes this three-dimensional symmetric dyadic tensor value as a YAML
  // message.
  std::string YAML() const {
    return "{xx:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0])
           + ",xy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1])
           + ",xz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + ",yy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",yz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4])
           + ",zz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  constexpr void operator+=(const SymmetricDyad& symdyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += symdyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += symdyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += symdyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += symdyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += symdyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += symdyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr void operator-=(const SymmetricDyad& symdyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= symdyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= symdyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= symdyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= symdyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= symdyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= symdyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr void operator*=(const double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= real;
    xx_xy_xz_yy_yz_zz_[1] *= real;
    xx_xy_xz_yy_yz_zz_[2] *= real;
    xx_xy_xz_yy_yz_zz_[3] *= real;
    xx_xy_xz_yy_yz_zz_[4] *= real;
    xx_xy_xz_yy_yz_zz_[5] *= real;
  }

  constexpr void operator/=(const double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] /= real;
    xx_xy_xz_yy_yz_zz_[1] /= real;
    xx_xy_xz_yy_yz_zz_[2] /= real;
    xx_xy_xz_yy_yz_zz_[3] /= real;
    xx_xy_xz_yy_yz_zz_[4] /= real;
    xx_xy_xz_yy_yz_zz_[5] /= real;
  }

private:
  std::array<double, 6> xx_xy_xz_yy_yz_zz_;

  friend Dyad;
};

inline constexpr bool operator==(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy()
          && left.xz() == right.xz() && left.yy() == right.yy()
          && left.yz() == right.yz() && left.zz() == right.zz());
}

inline constexpr bool operator!=(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy()
          || left.xz() != right.xz() || left.yy() != right.yy()
          || left.yz() != right.yz() || left.zz() != right.zz());
}

inline constexpr bool operator<(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  if (left.xx() != right.xx()) {
    return left.xx() < right.xx();
  }
  if (left.xy() != right.xy()) {
    return left.xy() < right.xy();
  }
  if (left.xz() != right.xz()) {
    return left.xz() < right.xz();
  }
  if (left.yy() != right.yy()) {
    return left.yy() < right.yy();
  }
  if (left.yz() != right.yz()) {
    return left.yz() < right.yz();
  }
  return left.zz() < right.zz();
}

inline constexpr bool operator>(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  if (left.xx() != right.xx()) {
    return left.xx() > right.xx();
  }
  if (left.xy() != right.xy()) {
    return left.xy() > right.xy();
  }
  if (left.xz() != right.xz()) {
    return left.xz() > right.xz();
  }
  if (left.yy() != right.yy()) {
    return left.yy() > right.yy();
  }
  if (left.yz() != right.yz()) {
    return left.yz() > right.yz();
  }
  return left.zz() > right.zz();
}

inline constexpr bool operator<=(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(
    const SymmetricDyad& left, const SymmetricDyad& right) noexcept {
  return !(left < right);
}

inline constexpr SymmetricDyad operator+(
    const SymmetricDyad& left, const SymmetricDyad& right) {
  return {left.xx() + right.xx(), left.xy() + right.xy(),
          left.xz() + right.xz(), left.yy() + right.yy(),
          left.yz() + right.yz(), left.zz() + right.zz()};
}

inline constexpr SymmetricDyad operator-(
    const SymmetricDyad& left, const SymmetricDyad& right) {
  return {left.xx() - right.xx(), left.xy() - right.xy(),
          left.xz() - right.xz(), left.yy() - right.yy(),
          left.yz() - right.yz(), left.zz() - right.zz()};
}

inline constexpr SymmetricDyad operator*(
    const SymmetricDyad& symdyad, const double real) {
  return {symdyad.xx() * real, symdyad.xy() * real, symdyad.xz() * real,
          symdyad.yy() * real, symdyad.yz() * real, symdyad.zz() * real};
}

inline constexpr SymmetricDyad operator*(
    const double real, const SymmetricDyad& symdyad) {
  return {symdyad * real};
}

inline constexpr Vector operator*(
    const SymmetricDyad& symdyad, const Vector& vector) {
  return {symdyad.xx() * vector.x() + symdyad.xy() * vector.y()
              + symdyad.xz() * vector.z(),
          symdyad.xy() * vector.x() + symdyad.yy() * vector.y()
              + symdyad.yz() * vector.z(),
          symdyad.xz() * vector.x() + symdyad.yz() * vector.y()
              + symdyad.zz() * vector.z()};
}

inline constexpr Dyad operator*(
    const SymmetricDyad& left, const SymmetricDyad& right);

inline constexpr Dyad operator*(const SymmetricDyad& symdyad, const Dyad& dyad);

inline constexpr SymmetricDyad operator/(
    const SymmetricDyad& symdyad, const double real) {
  return {symdyad.xx() / real, symdyad.xy() / real, symdyad.xz() / real,
          symdyad.yy() / real, symdyad.yz() / real, symdyad.zz() / real};
}

inline std::optional<SymmetricDyad> SymmetricDyad::Inverse() const {
  const double determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return std::optional<SymmetricDyad>{Adjugate() / determinant_};
  } else {
    return std::nullopt;
  }
}

inline std::ostream& operator<<(
    std::ostream& stream, const SymmetricDyad& symmetric) {
  stream << symmetric.Print();
  return stream;
}

}  // namespace PhQ::Value

namespace std {

template <>
struct hash<PhQ::Value::SymmetricDyad> {
  inline size_t operator()(const PhQ::Value::SymmetricDyad& symmetric) const {
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_SYMMETRIC_DYAD_HPP
