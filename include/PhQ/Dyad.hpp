// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_DYAD_HPP
#define PHQ_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <optional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "PlanarVector.hpp"
#include "SymmetricDyad.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean dyadic tensor. Contains nine components in Cartesian
/// coordinates: xx, xy, xz, yx, yy, yz, zx, zy, and zz. May be symmetric or asymmetric. For a
/// symmetric three-dimensional Euclidean dyadic tensor, see PhQ::SymmetricDyad. For a
/// three-dimensional Euclidean vector, see PhQ::Vector. For a two-dimensional Euclidean vector in
/// the XY plane, see PhQ::PlanarVector.
/// \tparam NumericType Floating-point numeric type: float, double, or long double. Defaults to
/// double if unspecified.
template <typename NumericType = double>
class Dyad {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::Dyad<NumericType> must be a numeric "
                "floating-point type: float, double, or long double.");

public:
  /// \brief Default constructor. Constructs a three-dimensional dyadic tensor with uninitialized
  /// xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  Dyad() = default;

  /// \brief Constructor. Constructs a three-dimensional dyadic tensor from the given xx, xy, xz,
  /// yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr Dyad(const NumericType xx, const NumericType xy, const NumericType xz,
                 const NumericType yx, const NumericType yy, const NumericType yz,
                 const NumericType zx, const NumericType zy, const NumericType zz)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_({xx, xy, xz, yx, yy, yz, zx, zy, zz}) {}

  /// \brief Constructor. Constructs a three-dimensional dyadic tensor from a given array
  /// representing its xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr Dyad(const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  /// \brief Constructor. Constructs a three-dimensional dyadic tensor from a given
  /// three-dimensional symmetric dyadic tensor.
  explicit constexpr Dyad(const SymmetricDyad<NumericType>& symmetric_dyad)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_({symmetric_dyad.xx(), symmetric_dyad.xy(), symmetric_dyad.xz(),
                                   symmetric_dyad.yx(), symmetric_dyad.yy(), symmetric_dyad.yz(),
                                   symmetric_dyad.zx(), symmetric_dyad.zy(), symmetric_dyad.zz()}) {
  }

  /// \brief Destructor. Destroys this three-dimensional dyadic tensor.
  ~Dyad() noexcept = default;

  /// \brief Copy constructor. Constructs a three-dimensional dyadic tensor by copying another one.
  constexpr Dyad(const Dyad<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a three-dimensional dyadic tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Dyad(const Dyad<OtherNumericType>& other)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_(
          {static_cast<NumericType>(other.xx()), static_cast<NumericType>(other.xy()),
           static_cast<NumericType>(other.xz()), static_cast<NumericType>(other.yx()),
           static_cast<NumericType>(other.yy()), static_cast<NumericType>(other.yz()),
           static_cast<NumericType>(other.zx()), static_cast<NumericType>(other.zy()),
           static_cast<NumericType>(other.zz())}) {}

  /// \brief Move constructor. Constructs a three-dimensional dyadic tensor by moving another one.
  constexpr Dyad(Dyad<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional dyadic tensor by copying
  /// another one.
  constexpr Dyad<NumericType>& operator=(const Dyad<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional dyadic tensor by copying
  /// another one.
  template <typename OtherNumericType>
  constexpr Dyad<NumericType>& operator=(const Dyad<OtherNumericType>& other) {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = static_cast<NumericType>(other.xx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = static_cast<NumericType>(other.xy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = static_cast<NumericType>(other.xz());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = static_cast<NumericType>(other.yx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = static_cast<NumericType>(other.yy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = static_cast<NumericType>(other.yz());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = static_cast<NumericType>(other.zx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = static_cast<NumericType>(other.zy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = static_cast<NumericType>(other.zz());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this three-dimensional dyadic tensor by moving
  /// another one.
  constexpr Dyad<NumericType>& operator=(Dyad<NumericType>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this three-dimensional dyadic tensor by copying a
  /// three-dimensional symmetric dyadic tensor.
  constexpr Dyad<NumericType>& operator=(const SymmetricDyad<NumericType>& other) {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = other.xx();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = other.xy();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = other.xz();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = other.yx();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = other.yy();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = other.yz();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = other.zx();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = other.zy();
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = other.zz();
    return *this;
  }

  /// \brief Assignment operator. Assigns this three-dimensional dyadic tensor by copying a given
  /// array representing its xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr Dyad<NumericType>& operator=(
      const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_ = xx_xy_xz_yx_yy_yz_zx_zy_zz;
    return *this;
  }

  /// \brief Statically creates a three-dimensional dyadic tensor with its xx, xy, xz, yx, yy, yz,
  /// zx, zy, and zz Cartesian components initialized to zero.
  [[nodiscard]] static constexpr Dyad<NumericType> Zero() {
    return Dyad<NumericType>{
      std::array<NumericType, 9>{
                                 static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0),
                                 static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0),
                                 static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0)}
    };
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yx, yy, yz, zx,
  /// zy, and zz Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<NumericType, 9>&
  xx_xy_xz_yx_yy_yz_zx_zy_zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  /// \brief Returns this three-dimensional dyadic tensor's xx Cartesian component.
  [[nodiscard]] constexpr NumericType xx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  /// \brief Returns this three-dimensional dyadic tensor's xy Cartesian component.
  [[nodiscard]] constexpr NumericType xy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  /// \brief Returns this three-dimensional dyadic tensor's xz Cartesian component.
  [[nodiscard]] constexpr NumericType xz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yx Cartesian component.
  [[nodiscard]] constexpr NumericType yx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yy Cartesian component.
  [[nodiscard]] constexpr NumericType yy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yz Cartesian component.
  [[nodiscard]] constexpr NumericType yz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zx Cartesian component.
  [[nodiscard]] constexpr NumericType zx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zy Cartesian component.
  [[nodiscard]] constexpr NumericType zy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zz Cartesian component.
  [[nodiscard]] constexpr NumericType zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  /// \brief Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yx, yy, yz, zx,
  /// zy, and zz Cartesian components as a mutable array.
  [[nodiscard]] constexpr std::array<NumericType, 9>&
  Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  /// \brief Returns this three-dimensional dyadic tensor's xx Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_xx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  /// \brief Returns this three-dimensional dyadic tensor's xy Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_xy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  /// \brief Returns this three-dimensional dyadic tensor's xz Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_xz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yx Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_yx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yy Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_yy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  /// \brief Returns this three-dimensional dyadic tensor's yz Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_yz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zx Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_zx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zy Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_zy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  /// \brief Returns this three-dimensional dyadic tensor's zz Cartesian component as a mutable
  /// value.
  [[nodiscard]] constexpr NumericType& Mutable_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  /// \brief Sets this three-dimensional dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz
  /// Cartesian components to the given values.
  constexpr void Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      const std::array<NumericType, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_ = xx_xy_xz_yx_yy_yz_zx_zy_zz;
  }

  /// \brief Sets this three-dimensional dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz
  /// Cartesian components to the given values.
  constexpr void Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yx,
      const NumericType yy, const NumericType yz, const NumericType zx, const NumericType zy,
      const NumericType zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = xx;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = xy;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = xz;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = yx;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = yy;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = yz;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = zx;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = zy;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = zz;
  }

  /// \brief Sets this three-dimensional dyadic tensor's xx Cartesian component to a given value.
  constexpr void Set_xx(const NumericType xx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = xx;
  }

  /// \brief Sets this three-dimensional dyadic tensor's xy Cartesian component to a given value.
  constexpr void Set_xy(const NumericType xy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = xy;
  }

  /// \brief Sets this three-dimensional dyadic tensor's xz Cartesian component to a given value.
  constexpr void Set_xz(const NumericType xz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = xz;
  }

  /// \brief Sets this three-dimensional dyadic tensor's yx Cartesian component to a given value.
  constexpr void Set_yx(const NumericType yx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = yx;
  }

  /// \brief Sets this three-dimensional dyadic tensor's yy Cartesian component to a given value.
  constexpr void Set_yy(const NumericType yy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = yy;
  }

  /// \brief Sets this three-dimensional dyadic tensor's yz Cartesian component to a given value.
  constexpr void Set_yz(const NumericType yz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = yz;
  }

  /// \brief Sets this three-dimensional dyadic tensor's zx Cartesian component to a given value.
  constexpr void Set_zx(const NumericType zx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = zx;
  }

  /// \brief Sets this three-dimensional dyadic tensor's zy Cartesian component to a given value.
  constexpr void Set_zy(const NumericType zy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = zy;
  }

  /// \brief Sets this three-dimensional dyadic tensor's zz Cartesian component to a given value.
  constexpr void Set_zz(const NumericType zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = zz;
  }

  /// \brief Returns whether this three-dimensional dyadic tensor is symmetric.
  [[nodiscard]] constexpr bool IsSymmetric() const noexcept {
    return xy() == yx() && xz() == zx() && yz() == zy();
  }

  /// \brief Returns the trace of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr NumericType Trace() const noexcept {
    return xx() + yy() + zz();
  }

  /// \brief Returns the determinant of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr NumericType Determinant() const noexcept {
    return (xx() * (yy() * zz() - yz() * zy()) + xy() * (yz() * zx() - yx() * zz())
            + xz() * (yx() * zy() - yy() * zx()));
  }

  /// \brief Returns the transpose of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<NumericType> Transpose() const {
    return Dyad<NumericType>{xx(), yx(), zx(), xy(), yy(), zy(), xz(), yz(), zz()};
  }

  /// \brief Returns the cofactors of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<NumericType> Cofactors() const {
    const NumericType cofactor_xx{yy() * zz() - yz() * zy()};
    const NumericType cofactor_xy{yz() * zx() - yx() * zz()};
    const NumericType cofactor_xz{yx() * zy() - yy() * zx()};
    const NumericType cofactor_yx{xz() * zy() - xy() * zz()};
    const NumericType cofactor_yy{xx() * zz() - xz() * zx()};
    const NumericType cofactor_yz{xy() * zx() - xx() * zy()};
    const NumericType cofactor_zx{xy() * yz() - xz() * yy()};
    const NumericType cofactor_zy{xz() * yx() - xx() * yz()};
    const NumericType cofactor_zz{xx() * yy() - xy() * yx()};
    return Dyad<NumericType>{cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy,
                             cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  /// \brief Returns the adjugate of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<NumericType> Adjugate() const {
    return Cofactors().Transpose();
  }

  /// \brief Returns the inverse of this three-dimensional dyadic tensor if it exists, or
  /// std::nullopt otherwise.
  [[nodiscard]] constexpr std::optional<Dyad<NumericType>> Inverse() const;

  /// \brief Prints this three-dimensional dyadic tensor as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(xx()) + ", " + PhQ::Print(xy()) + ", " + PhQ::Print(xz()) + "; "
           + PhQ::Print(yx()) + ", " + PhQ::Print(yy()) + ", " + PhQ::Print(yz()) + "; "
           + PhQ::Print(zx()) + ", " + PhQ::Print(zy()) + ", " + PhQ::Print(zz()) + ")";
  }

  /// \brief Serializes this three-dimensional dyadic tensor as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"xx\":" + PhQ::Print(xx()) + ",\"xy\":" + PhQ::Print(xy()) + ",\"xz\":"
           + PhQ::Print(xz()) + ",\"yx\":" + PhQ::Print(yx()) + ",\"yy\":" + PhQ::Print(yy())
           + ",\"yz\":" + PhQ::Print(yz()) + ",\"zx\":" + PhQ::Print(zx())
           + ",\"zy\":" + PhQ::Print(zy()) + ",\"zz\":" + PhQ::Print(zz()) + "}";
  }

  /// \brief Serializes this three-dimensional dyadic tensor as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<xx>" + PhQ::Print(xx()) + "</xx><xy>" + PhQ::Print(xy()) + "</xy><xz>"
           + PhQ::Print(xz()) + "</xz><yx>" + PhQ::Print(yx()) + "</yx><yy>" + PhQ::Print(yy())
           + "</yy><yz>" + PhQ::Print(yz()) + "</yz><zx>" + PhQ::Print(zx()) + "</zx><zy>"
           + PhQ::Print(zy()) + "</zy><zz>" + PhQ::Print(zz()) + "</zz>";
  }

  /// \brief Serializes this three-dimensional dyadic tensor as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{xx:" + PhQ::Print(xx()) + ",xy:" + PhQ::Print(xy()) + ",xz:" + PhQ::Print(xz())
           + ",yx:" + PhQ::Print(yx()) + ",yy:" + PhQ::Print(yy()) + ",yz:" + PhQ::Print(yz())
           + ",zx:" + PhQ::Print(zx()) + ",zy:" + PhQ::Print(zy()) + ",zz:" + PhQ::Print(zz())
           + "}";
  }

  /// \brief Adds another three-dimensional dyadic tensor to this one.
  constexpr void operator+=(const Dyad<NumericType>& other) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] += other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  /// \brief Subtracts another three-dimensional dyadic tensor from this one.
  constexpr void operator-=(const Dyad<NumericType>& other) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] -= other.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  /// \brief Multiplies this three-dimensional dyadic tensor by the given number.
  /// \tparam OtherNumericType Floating-point numeric type of the given number. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr void operator*=(const OtherNumericType number) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] *= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] *= static_cast<NumericType>(number);
  }

  /// \brief Divides this three-dimensional dyadic tensor by the given number.
  /// \tparam OtherNumericType Floating-point numeric type of the given number. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr void operator/=(const OtherNumericType number) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] /= static_cast<NumericType>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] /= static_cast<NumericType>(number);
  }

private:
  /// \brief Cartesian components of this three-dimensional dyadic tensor.
  std::array<NumericType, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz_;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() && left.xz() == right.xz()
          && left.yx() == right.yx() && left.yy() == right.yy() && left.yz() == right.yz()
          && left.zx() == right.zx() && left.zy() == right.zy() && left.zz() == right.zz());
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() || left.xz() != right.xz()
          || left.yx() != right.yx() || left.yy() != right.yy() || left.yz() != right.yz()
          || left.zx() != right.zx() || left.zy() != right.zy() || left.zz() != right.zz());
}

template <typename NumericType>
inline constexpr bool operator<(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  if (left.xx() != right.xx()) {
    return left.xx() < right.xx();
  }
  if (left.xy() != right.xy()) {
    return left.xy() < right.xy();
  }
  if (left.xz() != right.xz()) {
    return left.xz() < right.xz();
  }
  if (left.yx() != right.yx()) {
    return left.yx() < right.yx();
  }
  if (left.yy() != right.yy()) {
    return left.yy() < right.yy();
  }
  if (left.yz() != right.yz()) {
    return left.yz() < right.yz();
  }
  if (left.zx() != right.zx()) {
    return left.zx() < right.zx();
  }
  if (left.zy() != right.zy()) {
    return left.zy() < right.zy();
  }
  return left.zz() < right.zz();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  if (left.xx() != right.xx()) {
    return left.xx() > right.xx();
  }
  if (left.xy() != right.xy()) {
    return left.xy() > right.xy();
  }
  if (left.xz() != right.xz()) {
    return left.xz() > right.xz();
  }
  if (left.yx() != right.yx()) {
    return left.yx() > right.yx();
  }
  if (left.yy() != right.yy()) {
    return left.yy() > right.yy();
  }
  if (left.yz() != right.yz()) {
    return left.yz() > right.yz();
  }
  if (left.zx() != right.zx()) {
    return left.zx() > right.zx();
  }
  if (left.zy() != right.zy()) {
    return left.zy() > right.zy();
  }
  return left.zz() > right.zz();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator+(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) {
  return Dyad<NumericType>{left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
                           left.yx() + right.yx(), left.yy() + right.yy(), left.yz() + right.yz(),
                           left.zx() + right.zx(), left.zy() + right.zy(), left.zz() + right.zz()};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator-(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) {
  return Dyad<NumericType>{left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
                           left.yx() - right.yx(), left.yy() - right.yy(), left.yz() - right.yz(),
                           left.zx() - right.zx(), left.zy() - right.zy(), left.zz() - right.zz()};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr Dyad<NumericType> operator*(
    const Dyad<NumericType>& dyad, const OtherNumericType number) {
  return Dyad<NumericType>{
    dyad.xx() * static_cast<NumericType>(number), dyad.xy() * static_cast<NumericType>(number),
    dyad.xz() * static_cast<NumericType>(number), dyad.yx() * static_cast<NumericType>(number),
    dyad.yy() * static_cast<NumericType>(number), dyad.yz() * static_cast<NumericType>(number),
    dyad.zx() * static_cast<NumericType>(number), dyad.zy() * static_cast<NumericType>(number),
    dyad.zz() * static_cast<NumericType>(number)};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr Dyad<NumericType> operator*(
    const OtherNumericType number, const Dyad<NumericType>& dyad) {
  return Dyad<NumericType>{dyad * number};
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const Dyad<NumericType>& dyad, const PlanarVector<NumericType>& planar_vector) {
  return Vector<NumericType>{dyad.xx() * planar_vector.x() + dyad.xy() * planar_vector.y(),
                             dyad.yx() * planar_vector.x() + dyad.yy() * planar_vector.y(),
                             dyad.zx() * planar_vector.x() + dyad.zy() * planar_vector.y()};
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator*(
    const Dyad<NumericType>& dyad, const Vector<NumericType>& vector) {
  return Vector<NumericType>{
    dyad.xx() * vector.x() + dyad.xy() * vector.y() + dyad.xz() * vector.z(),
    dyad.yx() * vector.x() + dyad.yy() * vector.y() + dyad.yz() * vector.z(),
    dyad.zx() * vector.x() + dyad.zy() * vector.y() + dyad.zz() * vector.z()};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const SymmetricDyad<NumericType>& left, const SymmetricDyad<NumericType>& right) {
  return Dyad<NumericType>{
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

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const SymmetricDyad<NumericType>& symmetric_dyad, const Dyad<NumericType>& dyad) {
  return Dyad<NumericType>{
    symmetric_dyad.xx() * dyad.xx() + symmetric_dyad.xy() * dyad.yx()
        + symmetric_dyad.xz() * dyad.zx(),
    symmetric_dyad.xx() * dyad.xy() + symmetric_dyad.xy() * dyad.yy()
        + symmetric_dyad.xz() * dyad.zy(),
    symmetric_dyad.xx() * dyad.xz() + symmetric_dyad.xy() * dyad.yz()
        + symmetric_dyad.xz() * dyad.zz(),
    symmetric_dyad.xy() * dyad.xx() + symmetric_dyad.yy() * dyad.yx()
        + symmetric_dyad.yz() * dyad.zx(),
    symmetric_dyad.xy() * dyad.xy() + symmetric_dyad.yy() * dyad.yy()
        + symmetric_dyad.yz() * dyad.zy(),
    symmetric_dyad.xy() * dyad.xz() + symmetric_dyad.yy() * dyad.yz()
        + symmetric_dyad.yz() * dyad.zz(),
    symmetric_dyad.xz() * dyad.xx() + symmetric_dyad.yz() * dyad.yx()
        + symmetric_dyad.zz() * dyad.zx(),
    symmetric_dyad.xz() * dyad.xy() + symmetric_dyad.yz() * dyad.yy()
        + symmetric_dyad.zz() * dyad.zy(),
    symmetric_dyad.xz() * dyad.xz() + symmetric_dyad.yz() * dyad.yz()
        + symmetric_dyad.zz() * dyad.zz()};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const Dyad<NumericType>& dyad, const SymmetricDyad<NumericType>& symmetric_dyad) {
  return Dyad<NumericType>{
    dyad.xx() * symmetric_dyad.xx() + dyad.xy() * symmetric_dyad.yx()
        + dyad.xz() * symmetric_dyad.zx(),
    dyad.xx() * symmetric_dyad.xy() + dyad.xy() * symmetric_dyad.yy()
        + dyad.xz() * symmetric_dyad.zy(),
    dyad.xx() * symmetric_dyad.xz() + dyad.xy() * symmetric_dyad.yz()
        + dyad.xz() * symmetric_dyad.zz(),
    dyad.yx() * symmetric_dyad.xx() + dyad.yy() * symmetric_dyad.yx()
        + dyad.yz() * symmetric_dyad.zx(),
    dyad.yx() * symmetric_dyad.xy() + dyad.yy() * symmetric_dyad.yy()
        + dyad.yz() * symmetric_dyad.zy(),
    dyad.yx() * symmetric_dyad.xz() + dyad.yy() * symmetric_dyad.yz()
        + dyad.yz() * symmetric_dyad.zz(),
    dyad.zx() * symmetric_dyad.xx() + dyad.zy() * symmetric_dyad.yx()
        + dyad.zz() * symmetric_dyad.zx(),
    dyad.zx() * symmetric_dyad.xy() + dyad.zy() * symmetric_dyad.yy()
        + dyad.zz() * symmetric_dyad.zy(),
    dyad.zx() * symmetric_dyad.xz() + dyad.zy() * symmetric_dyad.yz()
        + dyad.zz() * symmetric_dyad.zz()};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> operator*(
    const Dyad<NumericType>& left, const Dyad<NumericType>& right) {
  return Dyad<NumericType>{
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

template <typename NumericType, typename OtherNumericType>
inline constexpr Dyad<NumericType> operator/(
    const Dyad<NumericType>& dyad, const OtherNumericType number) {
  return Dyad<NumericType>{
    dyad.xx() / static_cast<NumericType>(number), dyad.xy() / static_cast<NumericType>(number),
    dyad.xz() / static_cast<NumericType>(number), dyad.yx() / static_cast<NumericType>(number),
    dyad.yy() / static_cast<NumericType>(number), dyad.yz() / static_cast<NumericType>(number),
    dyad.zx() / static_cast<NumericType>(number), dyad.zy() / static_cast<NumericType>(number),
    dyad.zz() / static_cast<NumericType>(number)};
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Dyad<NumericType>& dyad) {
  stream << dyad.Print();
  return stream;
}

template <typename NumericType>
inline constexpr std::optional<Dyad<NumericType>> Dyad<NumericType>::Inverse() const {
  const NumericType determinant_{Determinant()};
  if (determinant_ != static_cast<NumericType>(0)) {
    return std::optional<Dyad<NumericType>>{Adjugate() / determinant_};
  }
  return std::nullopt;
}

template <typename NumericType>
constexpr Dyad<NumericType> PlanarVector<NumericType>::Dyadic(
    const PlanarVector<NumericType>& planar_vector) const {
  return Dyad<NumericType>{
    x_y_[0] * planar_vector.x_y_[0], x_y_[0] * planar_vector.x_y_[1], static_cast<NumericType>(0),
    x_y_[1] * planar_vector.x_y_[0], x_y_[1] * planar_vector.x_y_[1], static_cast<NumericType>(0),
    static_cast<NumericType>(0),     static_cast<NumericType>(0),     static_cast<NumericType>(0)};
}

template <typename NumericType>
inline constexpr Dyad<NumericType> Vector<NumericType>::Dyadic(
    const Vector<NumericType>& other) const {
  return Dyad<NumericType>{
    x_y_z_[0] * other.x_y_z_[0], x_y_z_[0] * other.x_y_z_[1], x_y_z_[0] * other.x_y_z_[2],
    x_y_z_[1] * other.x_y_z_[0], x_y_z_[1] * other.x_y_z_[1], x_y_z_[1] * other.x_y_z_[2],
    x_y_z_[2] * other.x_y_z_[0], x_y_z_[2] * other.x_y_z_[1], x_y_z_[2] * other.x_y_z_[2]};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Dyad<NumericType>> {
  inline size_t operator()(const PhQ::Dyad<NumericType>& dyad) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.xx());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.xy());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.xz());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.yx());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.yy());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.yz());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.zx());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.zy());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(dyad.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_DYAD_HPP
