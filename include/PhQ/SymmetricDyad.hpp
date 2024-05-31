// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "PlanarVector.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Symmetric three-dimensional Euclidean dyadic tensor. Contains six components in Cartesian
/// coordinates: xx, xy = yx, xz = zx, yy, yz = zy, and zz. For the general case of a
/// three-dimensional Euclidean dyadic tensor which may be symmetric or asymmetric, see PhQ::Dyad.
/// For a three-dimensional Euclidean vector, see PhQ::Vector. For a two-dimensional Euclidean
/// vector in the XY plane, see PhQ::PlanarVector.
template <typename NumericType = double>
class SymmetricDyad {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::SymmetricDyad<NumericType> must be a "
                "numeric floating-point type: float, double, or long double.");

public:
  /// \brief Default constructor. Constructs a three-dimensional symmetric dyadic tensor with
  /// uninitialized xx, xy, xz, yy, yz, and zz Cartesian components.
  SymmetricDyad() = default;

  /// \brief Constructor. Constructs a three-dimensional symmetric dyadic tensor from the given xx,
  /// xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad(const NumericType xx, const NumericType xy, const NumericType xz,
                          const NumericType yy, const NumericType yz, const NumericType zz)
    : xx_xy_xz_yy_yz_zz_({xx, xy, xz, yy, yz, zz}) {}

  /// \brief Constructor. Constructs a three-dimensional symmetric dyadic tensor from a given array
  /// representing its xx, xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr SymmetricDyad(const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz)
    : xx_xy_xz_yy_yz_zz_(xx_xy_xz_yy_yz_zz) {}

  /// \brief Destructor. Destroys this three-dimensional symmetric dyadic tensor.
  ~SymmetricDyad() noexcept = default;

  /// \brief Copy constructor. Constructs a three-dimensional symmetric dyadic tensor by copying
  /// another one.
  constexpr SymmetricDyad(const SymmetricDyad<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a three-dimensional symmetric dyadic tensor by copying
  /// another one.
  template <typename OtherNumericType>
  explicit constexpr SymmetricDyad<NumericType>(const SymmetricDyad<OtherNumericType>& other)
    : xx_xy_xz_yy_yz_zz_(
        {static_cast<NumericType>(other.xx()), static_cast<NumericType>(other.xy()),
         static_cast<NumericType>(other.xz()), static_cast<NumericType>(other.yy()),
         static_cast<NumericType>(other.yz()), static_cast<NumericType>(other.zz())}) {}

  /// \brief Move constructor. Constructs a three-dimensional symmetric dyadic tensor by moving
  /// another one.
  constexpr SymmetricDyad<NumericType>(SymmetricDyad<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional symmetric dyadic tensor by
  /// copying another one.
  constexpr SymmetricDyad<NumericType>& operator=(
      const SymmetricDyad<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional symmetric dyadic tensor by
  /// copying another one.
  template <typename OtherNumericType>
  constexpr SymmetricDyad<NumericType>& operator=(const SymmetricDyad<OtherNumericType>& other) {
    xx_xy_xz_yy_yz_zz_[0] = static_cast<NumericType>(other.xx());
    xx_xy_xz_yy_yz_zz_[1] = static_cast<NumericType>(other.xy());
    xx_xy_xz_yy_yz_zz_[2] = static_cast<NumericType>(other.xz());
    xx_xy_xz_yy_yz_zz_[3] = static_cast<NumericType>(other.yy());
    xx_xy_xz_yy_yz_zz_[4] = static_cast<NumericType>(other.yz());
    xx_xy_xz_yy_yz_zz_[5] = static_cast<NumericType>(other.zz());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this three-dimensional symmetric dyadic tensor by
  /// moving another one.
  constexpr SymmetricDyad<NumericType>& operator=(
      SymmetricDyad<NumericType>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this three-dimensional symmetric dyadic tensor by copying
  /// a given array representing its xx, xy, xz, yy, yz, and zz Cartesian components.
  constexpr SymmetricDyad<NumericType>& operator=(
      const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz) {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
    return *this;
  }

  /// \brief Statically creates a three-dimensional symmetric dyadic tensor with its xx, xy, xz, yy,
  /// yz, and zz Cartesian components initialized to zero.
  static constexpr SymmetricDyad<NumericType> Zero() {
    return SymmetricDyad<NumericType>{
        std::array<NumericType, 6>{
                                   static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0),
                                   static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0)}
    };
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz
  /// Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx Cartesian component.
  [[nodiscard]] constexpr NumericType xx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component.
  [[nodiscard]] constexpr NumericType xy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component.
  [[nodiscard]] constexpr NumericType xz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component.
  [[nodiscard]] constexpr NumericType yx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yy Cartesian component.
  [[nodiscard]] constexpr NumericType yy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component.
  [[nodiscard]] constexpr NumericType yz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component.
  [[nodiscard]] constexpr NumericType zx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component.
  [[nodiscard]] constexpr NumericType zy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zz Cartesian component.
  [[nodiscard]] constexpr NumericType zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz
  /// Cartesian components as a mutable array.
  constexpr std::array<NumericType, 6>& Mutable_xx_xy_xz_yy_yz_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx Cartesian component as a
  /// mutable value.
  constexpr NumericType& Mutable_xx() noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_xy() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_xz() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_yx() noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yy Cartesian component as a
  /// mutable value.
  constexpr NumericType& Mutable_yy() noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_yz() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_zx() noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component as
  /// a mutable value.
  constexpr NumericType& Mutable_zy() noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's zz Cartesian component as a
  /// mutable value.
  constexpr NumericType& Mutable_zz() noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz
  /// Cartesian components to the given values.
  constexpr void Set_xx_xy_xz_yy_yz_zz(
      const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz) noexcept {
    xx_xy_xz_yy_yz_zz_ = xx_xy_xz_yy_yz_zz;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's xx, xy, xz, yy, yz, and zz
  /// Cartesian components to the given values.
  constexpr void Set_xx_xy_xz_yy_yz_zz(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yy,
      const NumericType yz, const NumericType zz) noexcept {
    xx_xy_xz_yy_yz_zz_[0] = xx;
    xx_xy_xz_yy_yz_zz_[1] = xy;
    xx_xy_xz_yy_yz_zz_[2] = xz;
    xx_xy_xz_yy_yz_zz_[3] = yy;
    xx_xy_xz_yy_yz_zz_[4] = yz;
    xx_xy_xz_yy_yz_zz_[5] = zz;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's xx Cartesian component to a given
  /// value.
  constexpr void Set_xx(const NumericType xx) noexcept {
    xx_xy_xz_yy_yz_zz_[0] = xx;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's xy = yx Cartesian component to a
  /// given value.
  constexpr void Set_xy(const NumericType xy) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = xy;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's xz = zx Cartesian component to a
  /// given value.
  constexpr void Set_xz(const NumericType xz) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = xz;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's yx = xy Cartesian component to a
  /// given value.
  constexpr void Set_yx(const NumericType yx) noexcept {
    xx_xy_xz_yy_yz_zz_[1] = yx;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's yy Cartesian component to a given
  /// value.
  constexpr void Set_yy(const NumericType yy) noexcept {
    xx_xy_xz_yy_yz_zz_[3] = yy;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's yz = zy Cartesian component to a
  /// given value.
  constexpr void Set_yz(const NumericType yz) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = yz;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's zx = xz Cartesian component to a
  /// given value.
  constexpr void Set_zx(const NumericType zx) noexcept {
    xx_xy_xz_yy_yz_zz_[2] = zx;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's zy = yz Cartesian component to a
  /// given value.
  constexpr void Set_zy(const NumericType zy) noexcept {
    xx_xy_xz_yy_yz_zz_[4] = zy;
  }

  /// \brief Sets this three-dimensional symmetric dyadic tensor's zz Cartesian component to a given
  /// value.
  constexpr void Set_zz(const NumericType zz) noexcept {
    xx_xy_xz_yy_yz_zz_[5] = zz;
  }

  /// \brief Returns the trace of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr NumericType Trace() const noexcept {
    return xx() + yy() + zz();
  }

  /// \brief Returns the determinant of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr NumericType Determinant() const noexcept {
    return xx() * (yy() * zz() - yz() * zy()) + xy() * (yz() * zx() - yx() * zz())
           + xz() * (yx() * zy() - yy() * zx());
  }

  /// \brief Returns the transpose of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr const SymmetricDyad<NumericType>& Transpose() const noexcept {
    return *this;
  }

  /// \brief Returns the cofactors of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr SymmetricDyad<NumericType> Cofactors() const {
    const NumericType cofactor_xx{yy() * zz() - yz() * yz()};
    const NumericType cofactor_xy{xz() * yz() - xy() * zz()};
    const NumericType cofactor_xz{xy() * yz() - xz() * yy()};
    const NumericType cofactor_yy{xx() * zz() - xz() * xz()};
    const NumericType cofactor_yz{xy() * xz() - xx() * yz()};
    const NumericType cofactor_zz{xx() * yy() - xy() * xy()};
    return SymmetricDyad<NumericType>{
        cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yy, cofactor_yz, cofactor_zz};
  }

  /// \brief Returns the adjugate of this three-dimensional symmetric dyadic tensor.
  [[nodiscard]] constexpr SymmetricDyad<NumericType> Adjugate() const {
    // In general, for a dyadic tensor, this is cofactors().transpose(), but since this is a
    // symmetric dyadic tensor, the transpose is redundant.
    return Cofactors();
  }

  /// \brief Returns the inverse of this three-dimensional symmetric dyadic tensor if it exists, or
  /// std::nullopt otherwise.
  [[nodiscard]] std::optional<SymmetricDyad<NumericType>> Inverse() const;

  /// \brief Prints this three-dimensional symmetric dyadic tensor as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ", " + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + "; " + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + ", "
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "; " + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  /// \brief Serializes this three-dimensional symmetric dyadic tensor as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"xx\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ",\"xy\":"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + ",\"xz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + ",\"yy\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",\"yz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4])
           + ",\"zz\":" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  /// \brief Serializes this three-dimensional symmetric dyadic tensor as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<xx>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + "</xx><xy>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[1]) + "</xy><xz>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2])
           + "</xz><yy>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3]) + "</yy><yz>"
           + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + "</yz><zz>" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5])
           + "</zz>";
  }

  /// \brief Serializes this three-dimensional symmetric dyadic tensor as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{xx:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[0]) + ",xy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[1])
           + ",xz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[2]) + ",yy:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[3])
           + ",yz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[4]) + ",zz:" + PhQ::Print(xx_xy_xz_yy_yz_zz_[5])
           + "}";
  }

  constexpr void operator+=(const SymmetricDyad<NumericType>& symmetric_dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += symmetric_dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr void operator-=(const SymmetricDyad<NumericType>& symmetric_dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= symmetric_dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  template <typename OtherNumericType>
  constexpr void operator*=(const OtherNumericType number) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[1] *= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[2] *= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[3] *= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[4] *= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[5] *= static_cast<NumericType>(number);
  }

  template <typename OtherNumericType>
  constexpr void operator/=(const OtherNumericType number) noexcept {
    xx_xy_xz_yy_yz_zz_[0] /= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[1] /= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[2] /= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[3] /= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[4] /= static_cast<NumericType>(number);
    xx_xy_xz_yy_yz_zz_[5] /= static_cast<NumericType>(number);
  }

private:
  /// \brief Cartesian components of this three-dimensional symmetric dyadic tensor.
  std::array<NumericType, 6> xx_xy_xz_yy_yz_zz_;
};

template <typename NumericType>
inline constexpr bool operator==(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() && left.xz() == right.xz()
          && left.yy() == right.yy() && left.yz() == right.yz() && left.zz() == right.zz());
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() || left.xz() != right.xz()
          || left.yy() != right.yy() || left.yz() != right.yz() || left.zz() != right.zz());
}

template <typename NumericType>
inline constexpr bool operator<(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
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

template <typename NumericType>
inline constexpr bool operator>(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
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

template <typename NumericType>
inline constexpr bool operator<=(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline constexpr SymmetricDyad<NumericType> operator+(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) {
  return SymmetricDyad<NumericType>{
      left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
      left.yy() + right.yy(), left.yz() + right.yz(), left.zz() + right.zz()};
}

template <typename NumericType>
inline constexpr SymmetricDyad<NumericType> operator-(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) {
  return SymmetricDyad<NumericType>{
      left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
      left.yy() - right.yy(), left.yz() - right.yz(), left.zz() - right.zz()};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr SymmetricDyad<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad, const OtherNumericType number) {
  return SymmetricDyad<NumericType>{
      symmetric_dyad.xx() * static_cast<NumericType>(number),
      symmetric_dyad.xy() * static_cast<NumericType>(number),
      symmetric_dyad.xz() * static_cast<NumericType>(number),
      symmetric_dyad.yy() * static_cast<NumericType>(number),
      symmetric_dyad.yz() * static_cast<NumericType>(number),
      symmetric_dyad.zz() * static_cast<NumericType>(number)};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr SymmetricDyad<NumericType> operator*(
    const OtherNumericType number, const SymmetricDyad<NumericType>& symmetric_dyad) {
  return SymmetricDyad<NumericType>{symmetric_dyad * number};
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(const SymmetricDyad<NumericType>& symmetric_dyad,
                                               const PlanarVector<NumericType>& planar_vector) {
  return Vector<NumericType>{
      symmetric_dyad.xx() * planar_vector.x() + symmetric_dyad.xy() * planar_vector.y(),
      symmetric_dyad.xy() * planar_vector.x() + symmetric_dyad.yy() * planar_vector.y(),
      symmetric_dyad.xz() * planar_vector.x() + symmetric_dyad.yz() * planar_vector.y()};
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad, const Vector<NumericType>& vector) {
  return Vector<NumericType>{
      symmetric_dyad.xx() * vector.x() + symmetric_dyad.xy() * vector.y()
          + symmetric_dyad.xz() * vector.z(),
      symmetric_dyad.xy() * vector.x() + symmetric_dyad.yy() * vector.y()
          + symmetric_dyad.yz() * vector.z(),
      symmetric_dyad.xz() * vector.x() + symmetric_dyad.yz() * vector.y()
          + symmetric_dyad.zz() * vector.z()};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right);

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad, const Dyad<NumericType>& dyad);

template <typename NumericType, typename OtherNumericType>
inline constexpr SymmetricDyad<NumericType> operator/(
    const SymmetricDyad<NumericType>& symmetric_dyad, const OtherNumericType number) {
  return SymmetricDyad<NumericType>{
      symmetric_dyad.xx() / static_cast<NumericType>(number),
      symmetric_dyad.xy() / static_cast<NumericType>(number),
      symmetric_dyad.xz() / static_cast<NumericType>(number),
      symmetric_dyad.yy() / static_cast<NumericType>(number),
      symmetric_dyad.yz() / static_cast<NumericType>(number),
      symmetric_dyad.zz() / static_cast<NumericType>(number)};
}

template <typename NumericType>
inline std::optional<SymmetricDyad<NumericType>> SymmetricDyad<NumericType>::Inverse() const {
  const NumericType determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return std::optional<SymmetricDyad>{Adjugate() / determinant_};
  }
  return std::nullopt;
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const SymmetricDyad<NumericType>& symmetric) {
  stream << symmetric.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SymmetricDyad<NumericType>> {
  inline size_t operator()(const PhQ::SymmetricDyad<NumericType>& symmetric) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.xx());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.xy());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.xz());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.yy());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.yz());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(symmetric.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_SYMMETRIC_DYAD_HPP
