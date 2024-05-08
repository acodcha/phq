// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_SYMMETRIC_DYAD_HPP
#define PHQ_SYMMETRIC_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <optional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Vector.hpp"

namespace PhQ {

// Three-dimensional symmetric dyadic tensor in Cartesian coordinates. Contains six components: xx,
// xy = yx, xz = zx, yy, yz = zy, and zz.
template <typename Number = double>
class SymmetricDyad {
  static_assert(std::is_floating_point<Number>::value,
                "The Number template parameter of PhQ::SymmetricDyad<Number> must be a "
                "floating-point number type.");

public:
  // Default constructor. Constructs a three-dimensional symmetric dyadic tensor with uninitialized
  // xx, xy, xz, yy, yz, and zz Cartesian components.
  SymmetricDyad() = default;

  // Constructor. Constructs a three-dimensional symmetric dyadic tensor from the given xx, xy, xz,
  // yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad(const Number xx, const Number xy, const Number xz, const Number yy,
                          const Number yz, const Number zz)
    : xx_xy_xz_yy_yz_zz_({xx, xy, xz, yy, yz, zz}) {}

  // Constructor. Constructs a three-dimensional symmetric dyadic tensor from a given array
  // representing its xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr SymmetricDyad(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz)
    : xx_xy_xz_yy_yz_zz_(xx_xy_xz_yy_yz_zz) {}

  // Destructor. Destroys this three-dimensional symmetric dyadic tensor.
  ~SymmetricDyad() noexcept = default;

  // Copy constructor. Constructs a three-dimensional symmetric dyadic tensor by copying another
  // one.
  constexpr SymmetricDyad(const SymmetricDyad& other) = default;

  // Copy constructor. Constructs a three-dimensional symmetric dyadic tensor by copying another
  // one.
  template <typename OtherNumber>
  explicit constexpr SymmetricDyad(const SymmetricDyad<OtherNumber>& other)
    : xx_xy_xz_yy_yz_zz_({static_cast<Number>(other.xx()), static_cast<Number>(other.xy()),
                          static_cast<Number>(other.xz()), static_cast<Number>(other.yy()),
                          static_cast<Number>(other.yz()), static_cast<Number>(other.zz())}) {}

  // Move constructor. Constructs a three-dimensional symmetric dyadic tensor by moving another one.
  constexpr SymmetricDyad(SymmetricDyad&& other) noexcept = default;

  // Copy assignment operator. Assigns this three-dimensional symmetric dyadic tensor by copying
  // another one.
  constexpr SymmetricDyad& operator=(const SymmetricDyad& other) = default;

  // Copy assignment operator. Assigns this three-dimensional symmetric dyadic tensor by copying
  // another one.
  template <typename OtherNumber>
  constexpr SymmetricDyad& operator=(const SymmetricDyad<OtherNumber>& other) {
    xx_xy_xz_yy_yz_zz_[0] = static_cast<Number>(other.xx());
    xx_xy_xz_yy_yz_zz_[1] = static_cast<Number>(other.xy());
    xx_xy_xz_yy_yz_zz_[2] = static_cast<Number>(other.xz());
    xx_xy_xz_yy_yz_zz_[3] = static_cast<Number>(other.yy());
    xx_xy_xz_yy_yz_zz_[4] = static_cast<Number>(other.yz());
    xx_xy_xz_yy_yz_zz_[5] = static_cast<Number>(other.zz());
    return *this;
  }

  // Move assignment operator. Assigns this three-dimensional symmetric dyadic tensor by moving
  // another one.
  constexpr SymmetricDyad& operator=(SymmetricDyad&& other) noexcept = default;

  // Assignment operator. Assigns this three-dimensional symmetric dyadic tensor by copying a given
  // array representing its xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad& operator=(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
    return *this;
  }

  // Statically creates a three-dimensional symmetric dyadic tensor with its xx, xy, xz, yy, yz, and
  // zz Cartesian components initialized to zero.
  static constexpr SymmetricDyad Zero() {
    return SymmetricDyad{
        std::array<Number, 6>{0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz Cartesian
  // components as an array.
  [[nodiscard]] constexpr const std::array<Number, 6>& xx_xy_xz_yy_yz_zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx Cartesian component.
  [[nodiscard]] constexpr Number xx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component.
  [[nodiscard]] constexpr Number xy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component.
  [[nodiscard]] constexpr Number xz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component.
  [[nodiscard]] constexpr Number yx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yy Cartesian component.
  [[nodiscard]] constexpr Number yy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component.
  [[nodiscard]] constexpr Number yz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component.
  [[nodiscard]] constexpr Number zx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component.
  [[nodiscard]] constexpr Number zy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zz Cartesian component.
  [[nodiscard]] constexpr Number zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz Cartesian
  // components as a mutable array.
  constexpr std::array<Number, 6>& Mutable_xx_xy_xz_yy_yz_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx Cartesian component as a mutable
  // value.
  constexpr Number& Mutable_xx() noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_xy() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_xz() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_yx() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yy Cartesian component as a mutable
  // value.
  constexpr Number& Mutable_yy() noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  // Returns this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_yz() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_zx() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component as a
  // mutable value.
  constexpr Number& Mutable_zy() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  // Returns this three-dimensional symmetric dyadic tensor's zz Cartesian component as a mutable
  // value.
  constexpr Number& Mutable_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  // Sets this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz Cartesian
  // components to the given values.
  constexpr void Set_xx_xy_xz_yy_yz_zz(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) noexcept {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
  }

  // Sets this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz Cartesian
  // components to the given values.
  constexpr void Set_xx_xy_xz_yy_yz_zz(const Number xx, const Number xy, const Number xz,
                                       const Number yy, const Number yz, const Number zz) noexcept {
    xx_xy_xz_yy_yz_zz_[0] = xx;
    xx_xy_xz_yy_yz_zz_[1] = xy;
    xx_xy_xz_yy_yz_zz_[2] = xz;
    xx_xy_xz_yy_yz_zz_[3] = yy;
    xx_xy_xz_yy_yz_zz_[4] = yz;
    xx_xy_xz_yy_yz_zz_[5] = zz;
  }

  // Sets this three-dimensional symmetric dyadic tensor's xx Cartesian component to a given value.
  constexpr void Set_xx(const Number xx) noexcept {
    xx_xy_xz_yy_yz_zz_[0] = xx;
  }

  // Sets this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component to a given
  // value.
  constexpr void Set_xy(const Number xy) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = xy;
  }

  // Sets this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component to a given
  // value.
  constexpr void Set_xz(const Number xz) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = xz;
  }

  // Sets this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component to a given
  // value.
  constexpr void Set_yx(const Number yx) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = yx;
  }

  // Sets this three-dimensional symmetric dyadic tensor's yy Cartesian component to a given value.
  constexpr void Set_yy(const Number yy) noexcept {
    xx_xy_xz_yy_yz_zz_[3] = yy;
  }

  // Sets this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component to a given
  // value.
  constexpr void Set_yz(const Number yz) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = yz;
  }

  // Sets this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component to a given
  // value.
  constexpr void Set_zx(const Number zx) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = zx;
  }

  // Sets this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component to a given
  // value.
  constexpr void Set_zy(const Number zy) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = zy;
  }

  // Sets this three-dimensional symmetric dyadic tensor's zz Cartesian component to a given value.
  constexpr void Set_zz(const Number zz) noexcept {
    xx_xy_xz_yy_yz_zz_[5] = zz;
  }

  // Returns the trace of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr Number Trace() const noexcept {
    return xx() + yy() + zz();
  }

  // Returns the determinant of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr Number Determinant() const noexcept {
    return xx() * (yy() * zz() - yz() * zy()) + xy() * (yz() * zx() - yx() * zz())
           + xz() * (yx() * zy() - yy() * zx());
  }

  // Returns the transpose of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr const SymmetricDyad& Transpose() const noexcept {
    return *this;
  }

  // Returns the cofactors of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr SymmetricDyad Cofactors() const {
    const Number cofactor_xx{yy() * zz() - yz() * yz()};
    const Number cofactor_xy{xz() * yz() - xy() * zz()};
    const Number cofactor_xz{xy() * yz() - xz() * yy()};
    const Number cofactor_yy{xx() * zz() - xz() * xz()};
    const Number cofactor_yz{xy() * xz() - xx() * yz()};
    const Number cofactor_zz{xx() * yy() - xy() * xy()};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yy, cofactor_yz, cofactor_zz};
  }

  // Returns the adjugate of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr SymmetricDyad Adjugate() const {
    // In general, for a dyadic tensor, this is cofactors().transpose(), but since this is a
    // symmetric dyadic tensor, the transpose is redundant.
    return Cofactors();
  }

  // Returns the inverse of this three-dimensional symmetric dyadic tensor if it exists, or
  // std::nullopt otherwise.
  [[nodiscard]] std::optional<SymmetricDyad> Inverse() const;

  // Prints this three-dimensional symmetric dyadic tensor as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ", " + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "; " + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "; " + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  // Serializes this three-dimensional symmetric dyadic tensor as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"xx\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ",\"xy\":"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ",\"xz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + ",\"yy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",\"yz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4])
           + ",\"zz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  // Serializes this three-dimensional symmetric dyadic tensor as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<xx>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + "</xx><xy>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + "</xy><xz>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + "</xz><yy>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + "</yy><yz>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "</yz><zz>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5])
           + "</zz>";
  }

  // Serializes this three-dimensional symmetric dyadic tensor as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{xx:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ",xy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1])
           + ",xz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + ",yy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",yz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + ",zz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5])
           + "}";
  }

  constexpr void operator+=(const SymmetricDyad& symmetric_dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr void operator-=(const SymmetricDyad& symmetric_dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  template <typename OtherNumber>
  constexpr void operator*=(const OtherNumber number) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[1] *= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[2] *= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[3] *= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[4] *= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[5] *= static_cast<Number>(number);
  }

  template <typename OtherNumber>
  constexpr void operator/=(const OtherNumber number) noexcept {
    xx_xy_xz_yy_yz_zz_[0] /= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[1] /= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[2] /= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[3] /= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[4] /= static_cast<Number>(number);
    xx_xy_xz_yy_yz_zz_[5] /= static_cast<Number>(number);
  }

private:
  // Cartesian components of this three-dimensional symmetric dyadic tensor.
  std::array<Number, 6> xx_xy_xz_yy_yz_zz_;

  friend class Dyad<Number>;
};

template <typename Number>
inline constexpr bool operator==(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() && left.xz() == right.xz()
          && left.yy() == right.yy() && left.yz() == right.yz() && left.zz() == right.zz());
}

template <typename Number>
inline constexpr bool operator!=(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() || left.xz() != right.xz()
          || left.yy() != right.yy() || left.yz() != right.yz() || left.zz() != right.zz());
}

template <typename Number>
inline constexpr bool operator<(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
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

template <typename Number>
inline constexpr bool operator>(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
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

template <typename Number>
inline constexpr bool operator<=(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline constexpr SymmetricDyad<Number> operator+(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) {
  return {left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
          left.yy() + right.yy(), left.yz() + right.yz(), left.zz() + right.zz()};
}

template <typename Number>
inline constexpr SymmetricDyad<Number> operator-(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) {
  return {left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
          left.yy() - right.yy(), left.yz() - right.yz(), left.zz() - right.zz()};
}

template <typename Number, typename OtherNumber>
inline constexpr SymmetricDyad<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const OtherNumber number) {
  return {symmetric_dyad.xx() * static_cast<Number>(number),
          symmetric_dyad.xy() * static_cast<Number>(number),
          symmetric_dyad.xz() * static_cast<Number>(number),
          symmetric_dyad.yy() * static_cast<Number>(number),
          symmetric_dyad.yz() * static_cast<Number>(number),
          symmetric_dyad.zz() * static_cast<Number>(number)};
}

template <typename Number, typename OtherNumber>
inline constexpr SymmetricDyad<Number> operator*(
    const OtherNumber number, const SymmetricDyad<Number>& symmetric_dyad) {
  return {symmetric_dyad * number};
}

template <typename Number>
inline constexpr Vector<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const Vector<Number>& vector) {
  return {symmetric_dyad.xx() * vector.x() + symmetric_dyad.xy() * vector.y()
              + symmetric_dyad.xz() * vector.z(),
          symmetric_dyad.xy() * vector.x() + symmetric_dyad.yy() * vector.y()
              + symmetric_dyad.yz() * vector.z(),
          symmetric_dyad.xz() * vector.x() + symmetric_dyad.yz() * vector.y()
              + symmetric_dyad.zz() * vector.z()};
}

template <typename Number>
inline constexpr Dyad<Number> operator*(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right);

template <typename Number>
inline constexpr Dyad<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const Dyad<Number>& dyad);

template <typename Number, typename OtherNumber>
inline constexpr SymmetricDyad<Number> operator/(
    const SymmetricDyad<Number>& symmetric_dyad, const OtherNumber number) {
  return {symmetric_dyad.xx() / static_cast<Number>(number),
          symmetric_dyad.xy() / static_cast<Number>(number),
          symmetric_dyad.xz() / static_cast<Number>(number),
          symmetric_dyad.yy() / static_cast<Number>(number),
          symmetric_dyad.yz() / static_cast<Number>(number),
          symmetric_dyad.zz() / static_cast<Number>(number)};
}

template <typename Number>
inline std::optional<SymmetricDyad<Number>> SymmetricDyad<Number>::Inverse() const {
  const Number determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return std::optional<SymmetricDyad>{Adjugate() / determinant_};
  }
  return std::nullopt;
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const SymmetricDyad<Number>& symmetric) {
  stream << symmetric.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SymmetricDyad<Number>> {
  inline size_t operator()(const PhQ::SymmetricDyad<Number>& symmetric) const {
    size_t result{17};
    result = 31 * result + hash<Number>()(symmetric.xx());
    result = 31 * result + hash<Number>()(symmetric.xy());
    result = 31 * result + hash<Number>()(symmetric.xz());
    result = 31 * result + hash<Number>()(symmetric.yy());
    result = 31 * result + hash<Number>()(symmetric.yz());
    result = 31 * result + hash<Number>()(symmetric.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_SYMMETRIC_DYAD_HPP
