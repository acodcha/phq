// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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
#include "SymmetricDyad.hpp"
#include "Vector.hpp"

namespace PhQ {

// Three-dimensional dyadic tensor in Cartesian coordinates. May be non-symmetric. Contains nine
// components: xx, xy, xz, yx, yy, yz, zx, zy, and zz.
template <typename Number = double>
class Dyad {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Dyad<Number> must be a floating-point number type.");

public:
  // Default constructor. Constructs a three-dimensional dyadic tensor with uninitialized xx, xy,
  // xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  Dyad() = default;

  // Constructor. Constructs a three-dimensional dyadic tensor from the given xx, xy, xz, yx, yy,
  // yz, zx, zy, and zz Cartesian components.
  constexpr Dyad(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_({xx, xy, xz, yx, yy, yz, zx, zy, zz}) {}

  // Constructor. Constructs a three-dimensional dyadic tensor from a given array representing its
  // xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr Dyad(const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  // Constructor. Constructs a three-dimensional dyadic tensor from a given three-dimensional
  // symmetric dyadic tensor.
  explicit constexpr Dyad(const SymmetricDyad<Number>& symmetric_dyad)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_(
        {symmetric_dyad.xx(), symmetric_dyad.xy(), symmetric_dyad.xz(), symmetric_dyad.yx(),
         symmetric_dyad.yy(), symmetric_dyad.yz(), symmetric_dyad.zx(), symmetric_dyad.zy(),
         symmetric_dyad.zz()}) {}

  // Destructor. Destroys this three-dimensional dyadic tensor.
  ~Dyad() noexcept = default;

  // Copy constructor. Constructs a three-dimensional dyadic tensor by copying another one.
  constexpr Dyad(const Dyad<Number>& other) = default;

  // Copy constructor. Constructs a three-dimensional dyadic tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr Dyad(const Dyad<OtherNumber>& other)
    : xx_xy_xz_yx_yy_yz_zx_zy_zz_(
        {static_cast<Number>(other.xx()), static_cast<Number>(other.xy()),
         static_cast<Number>(other.xz()), static_cast<Number>(other.yx()),
         static_cast<Number>(other.yy()), static_cast<Number>(other.yz()),
         static_cast<Number>(other.zx()), static_cast<Number>(other.zy()),
         static_cast<Number>(other.zz())}) {}

  // Move constructor. Constructs a three-dimensional dyadic tensor by moving another one.
  constexpr Dyad(Dyad<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this three-dimensional dyadic tensor by copying another
  // one.
  constexpr Dyad<Number>& operator=(const Dyad<Number>& other) = default;

  // Copy assignment operator. Assigns this three-dimensional dyadic tensor by copying another
  // one.
  template <typename OtherNumber>
  constexpr Dyad<Number>& operator=(const Dyad<OtherNumber>& other) {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = static_cast<Number>(other.xx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = static_cast<Number>(other.xy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = static_cast<Number>(other.xz());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = static_cast<Number>(other.yx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = static_cast<Number>(other.yy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = static_cast<Number>(other.yz());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = static_cast<Number>(other.zx());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = static_cast<Number>(other.zy());
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = static_cast<Number>(other.zz());
    return *this;
  }

  // Move assignment operator. Assigns this three-dimensional dyadic tensor by moving another
  // one.
  constexpr Dyad<Number>& operator=(Dyad<Number>&& other) noexcept = default;

  // Assignment operator. Assigns this three-dimensional dyadic tensor by copying a
  // three-dimensional symmetric dyadic tensor.
  constexpr Dyad<Number>& operator=(const SymmetricDyad<Number>& other) {
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

  // Assignment operator. Assigns this three-dimensional dyadic tensor by copying a given array
  // representing its xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr Dyad<Number>& operator=(const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_ = xx_xy_xz_yx_yy_yz_zx_zy_zz;
    return *this;
  }

  // Statically creates a three-dimensional dyadic tensor with its xx, xy, xz, yx, yy, yz, zx, zy,
  // and zz Cartesian components initialized to zero.
  static constexpr Dyad<Number> Zero() {
    return Dyad<Number>{
        std::array<Number, 9>{
                              static_cast<Number>(0), static_cast<Number>(0), static_cast<Number>(0),
                              static_cast<Number>(0), static_cast<Number>(0), static_cast<Number>(0),
                              static_cast<Number>(0), static_cast<Number>(0), static_cast<Number>(0)}
    };
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz
  // Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  // Returns this three-dimensional dyadic tensor's xx Cartesian component.
  [[nodiscard]] constexpr Number xx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  // Returns this three-dimensional dyadic tensor's xy Cartesian component.
  [[nodiscard]] constexpr Number xy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  // Returns this three-dimensional dyadic tensor's xz Cartesian component.
  [[nodiscard]] constexpr Number xz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  // Returns this three-dimensional dyadic tensor's yx Cartesian component.
  [[nodiscard]] constexpr Number yx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  // Returns this three-dimensional dyadic tensor's yy Cartesian component.
  [[nodiscard]] constexpr Number yy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  // Returns this three-dimensional dyadic tensor's yz Cartesian component.
  [[nodiscard]] constexpr Number yz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  // Returns this three-dimensional dyadic tensor's zx Cartesian component.
  [[nodiscard]] constexpr Number zx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  // Returns this three-dimensional dyadic tensor's zy Cartesian component.
  [[nodiscard]] constexpr Number zy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  // Returns this three-dimensional dyadic tensor's zz Cartesian component.
  [[nodiscard]] constexpr Number zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  // Returns this three-dimensional symmetric dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz
  // Cartesian components as a mutable array.
  constexpr std::array<Number, 9>& Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  // Returns this three-dimensional dyadic tensor's xx Cartesian component as a mutable value.
  constexpr Number& Mutable_xx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  // Returns this three-dimensional dyadic tensor's xy Cartesian component as a mutable value.
  constexpr Number& Mutable_xy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  // Returns this three-dimensional dyadic tensor's xz Cartesian component as a mutable value.
  constexpr Number& Mutable_xz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  // Returns this three-dimensional dyadic tensor's yx Cartesian component as a mutable value.
  constexpr Number& Mutable_yx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  // Returns this three-dimensional dyadic tensor's yy Cartesian component as a mutable value.
  constexpr Number& Mutable_yy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  // Returns this three-dimensional dyadic tensor's yz Cartesian component as a mutable value.
  constexpr Number& Mutable_yz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  // Returns this three-dimensional dyadic tensor's zx Cartesian component as a mutable value.
  constexpr Number& Mutable_zx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  // Returns this three-dimensional dyadic tensor's zy Cartesian component as a mutable value.
  constexpr Number& Mutable_zy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  // Returns this three-dimensional dyadic tensor's zz Cartesian component as a mutable value.
  constexpr Number& Mutable_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  // Sets this three-dimensional dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian
  // components to the given values.
  constexpr void Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_ = xx_xy_xz_yx_yy_yz_zx_zy_zz;
  }

  // Sets this three-dimensional dyadic tensor's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian
  // components to the given values.
  constexpr void Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz) noexcept {
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

  // Sets this three-dimensional dyadic tensor's xx Cartesian component to a given value.
  constexpr void Set_xx(const Number xx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = xx;
  }

  // Sets this three-dimensional dyadic tensor's xy Cartesian component to a given value.
  constexpr void Set_xy(const Number xy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = xy;
  }

  // Sets this three-dimensional dyadic tensor's xz Cartesian component to a given value.
  constexpr void Set_xz(const Number xz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = xz;
  }

  // Sets this three-dimensional dyadic tensor's yx Cartesian component to a given value.
  constexpr void Set_yx(const Number yx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = yx;
  }

  // Sets this three-dimensional dyadic tensor's yy Cartesian component to a given value.
  constexpr void Set_yy(const Number yy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = yy;
  }

  // Sets this three-dimensional dyadic tensor's yz Cartesian component to a given value.
  constexpr void Set_yz(const Number yz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = yz;
  }

  // Sets this three-dimensional dyadic tensor's zx Cartesian component to a given value.
  constexpr void Set_zx(const Number zx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = zx;
  }

  // Sets this three-dimensional dyadic tensor's zy Cartesian component to a given value.
  constexpr void Set_zy(const Number zy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = zy;
  }

  // Sets this three-dimensional dyadic tensor's zz Cartesian component to a given value.
  constexpr void Set_zz(const Number zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = zz;
  }

  // Returns whether this three-dimensional dyadic tensor is symmetric.
  [[nodiscard]] constexpr bool IsSymmetric() const noexcept {
    return xy() == yx() && xz() == zx() && yz() == zy();
  }

  // Returns the trace of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Number Trace() const noexcept {
    return xx() + yy() + zz();
  }

  // Returns the determinant of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Number Determinant() const noexcept {
    return (xx() * (yy() * zz() - yz() * zy()) + xy() * (yz() * zx() - yx() * zz())
            + xz() * (yx() * zy() - yy() * zx()));
  }

  // Returns the transpose of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<Number> Transpose() const {
    return Dyad<Number>{xx(), yx(), zx(), xy(), yy(), zy(), xz(), yz(), zz()};
  }

  // Returns the cofactors of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<Number> Cofactors() const {
    const Number cofactor_xx{yy() * zz() - yz() * zy()};
    const Number cofactor_xy{yz() * zx() - yx() * zz()};
    const Number cofactor_xz{yx() * zy() - yy() * zx()};
    const Number cofactor_yx{xz() * zy() - xy() * zz()};
    const Number cofactor_yy{xx() * zz() - xz() * zx()};
    const Number cofactor_yz{xy() * zx() - xx() * zy()};
    const Number cofactor_zx{xy() * yz() - xz() * yy()};
    const Number cofactor_zy{xz() * yx() - xx() * yz()};
    const Number cofactor_zz{xx() * yy() - xy() * yx()};
    return Dyad<Number>{cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy,
                        cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  // Returns the adjugate of this three-dimensional dyadic tensor.
  [[nodiscard]] constexpr Dyad<Number> Adjugate() const {
    return Cofactors().Transpose();
  }

  // Returns the inverse of this three-dimensional dyadic tensor if it exists, or std::nullopt
  // otherwise.
  [[nodiscard]] constexpr std::optional<Dyad<Number>> Inverse() const;

  // Prints this three-dimensional dyadic tensor as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(xx()) + ", " + PhQ::Print(xy()) + ", " + PhQ::Print(xz()) + "; "
           + PhQ::Print(yx()) + ", " + PhQ::Print(yy()) + ", " + PhQ::Print(yz()) + "; "
           + PhQ::Print(zx()) + ", " + PhQ::Print(zy()) + ", " + PhQ::Print(zz()) + ")";
  }

  // Serializes this three-dimensional dyadic tensor as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"xx\":" + PhQ::Print(xx()) + ",\"xy\":" + PhQ::Print(xy()) + ",\"xz\":"
           + PhQ::Print(xz()) + ",\"yx\":" + PhQ::Print(yx()) + ",\"yy\":" + PhQ::Print(yy())
           + ",\"yz\":" + PhQ::Print(yz()) + ",\"zx\":" + PhQ::Print(zx())
           + ",\"zy\":" + PhQ::Print(zy()) + ",\"zz\":" + PhQ::Print(zz()) + "}";
  }

  // Serializes this three-dimensional dyadic tensor as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<xx>" + PhQ::Print(xx()) + "</xx><xy>" + PhQ::Print(xy()) + "</xy><xz>"
           + PhQ::Print(xz()) + "</xz><yx>" + PhQ::Print(yx()) + "</yx><yy>" + PhQ::Print(yy())
           + "</yy><yz>" + PhQ::Print(yz()) + "</yz><zx>" + PhQ::Print(zx()) + "</zx><zy>"
           + PhQ::Print(zy()) + "</zy><zz>" + PhQ::Print(zz()) + "</zz>";
  }

  // Serializes this three-dimensional dyadic tensor as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{xx:" + PhQ::Print(xx()) + ",xy:" + PhQ::Print(xy()) + ",xz:" + PhQ::Print(xz())
           + ",yx:" + PhQ::Print(yx()) + ",yy:" + PhQ::Print(yy()) + ",yz:" + PhQ::Print(yz())
           + ",zx:" + PhQ::Print(zx()) + ",zy:" + PhQ::Print(zy()) + ",zz:" + PhQ::Print(zz())
           + "}";
  }

  constexpr void operator+=(const Dyad<Number>& dyad) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr void operator-=(const Dyad<Number>& dyad) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  template <typename OtherNumber>
  constexpr void operator*=(const OtherNumber number) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] *= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] *= static_cast<Number>(number);
  }

  template <typename OtherNumber>
  constexpr void operator/=(const OtherNumber number) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] /= static_cast<Number>(number);
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] /= static_cast<Number>(number);
  }

private:
  // Cartesian components of this three-dimensional dyadic tensor.
  std::array<Number, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz_;
};

template <typename Number>
inline constexpr bool operator==(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() && left.xz() == right.xz()
          && left.yx() == right.yx() && left.yy() == right.yy() && left.yz() == right.yz()
          && left.zx() == right.zx() && left.zy() == right.zy() && left.zz() == right.zz());
}

template <typename Number>
inline constexpr bool operator!=(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() || left.xz() != right.xz()
          || left.yx() != right.yx() || left.yy() != right.yy() || left.yz() != right.yz()
          || left.zx() != right.zx() || left.zy() != right.zy() || left.zz() != right.zz());
}

template <typename Number>
inline constexpr bool operator<(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
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

template <typename Number>
inline constexpr bool operator>(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
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

template <typename Number>
inline constexpr bool operator<=(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(const Dyad<Number>& left, const Dyad<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline constexpr Dyad<Number> operator+(const Dyad<Number>& left, const Dyad<Number>& right) {
  return Dyad<Number>{left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
                      left.yx() + right.yx(), left.yy() + right.yy(), left.yz() + right.yz(),
                      left.zx() + right.zx(), left.zy() + right.zy(), left.zz() + right.zz()};
}

template <typename Number>
inline constexpr Dyad<Number> operator-(const Dyad<Number>& left, const Dyad<Number>& right) {
  return Dyad<Number>{left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
                      left.yx() - right.yx(), left.yy() - right.yy(), left.yz() - right.yz(),
                      left.zx() - right.zx(), left.zy() - right.zy(), left.zz() - right.zz()};
}

template <typename Number, typename OtherNumber>
inline constexpr Dyad<Number> operator*(const Dyad<Number>& dyad, const OtherNumber number) {
  return Dyad<Number>{
      dyad.xx() * static_cast<Number>(number), dyad.xy() * static_cast<Number>(number),
      dyad.xz() * static_cast<Number>(number), dyad.yx() * static_cast<Number>(number),
      dyad.yy() * static_cast<Number>(number), dyad.yz() * static_cast<Number>(number),
      dyad.zx() * static_cast<Number>(number), dyad.zy() * static_cast<Number>(number),
      dyad.zz() * static_cast<Number>(number)};
}

template <typename Number, typename OtherNumber>
inline constexpr Dyad<Number> operator*(const OtherNumber number, const Dyad<Number>& dyad) {
  return Dyad<Number>{dyad * number};
}

template <typename Number>
inline constexpr Vector<Number> operator*(const Dyad<Number>& dyad, const Vector<Number>& vector) {
  return Vector<Number>{dyad.xx() * vector.x() + dyad.xy() * vector.y() + dyad.xz() * vector.z(),
                        dyad.yx() * vector.x() + dyad.yy() * vector.y() + dyad.yz() * vector.z(),
                        dyad.zx() * vector.x() + dyad.zy() * vector.y() + dyad.zz() * vector.z()};
}

template <typename Number>
inline constexpr Dyad<Number> operator*(
    const SymmetricDyad<Number>& left, const SymmetricDyad<Number>& right) {
  return Dyad<Number>{
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

template <typename Number>
inline constexpr Dyad<Number> operator*(
    const SymmetricDyad<Number>& symmetric_dyad, const Dyad<Number>& dyad) {
  return Dyad<Number>{
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

template <typename Number>
inline constexpr Dyad<Number> operator*(
    const Dyad<Number>& dyad, const SymmetricDyad<Number>& symmetric_dyad) {
  return Dyad<Number>{
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

template <typename Number>
inline constexpr Dyad<Number> operator*(const Dyad<Number>& left, const Dyad<Number>& right) {
  return Dyad<Number>{
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

template <typename Number, typename OtherNumber>
inline constexpr Dyad<Number> operator/(const Dyad<Number>& dyad, const OtherNumber number) {
  return Dyad<Number>{
      dyad.xx() / static_cast<Number>(number), dyad.xy() / static_cast<Number>(number),
      dyad.xz() / static_cast<Number>(number), dyad.yx() / static_cast<Number>(number),
      dyad.yy() / static_cast<Number>(number), dyad.yz() / static_cast<Number>(number),
      dyad.zx() / static_cast<Number>(number), dyad.zy() / static_cast<Number>(number),
      dyad.zz() / static_cast<Number>(number)};
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Dyad<Number>& dyad) {
  stream << dyad.Print();
  return stream;
}

template <typename Number>
inline constexpr std::optional<Dyad<Number>> Dyad<Number>::Inverse() const {
  const Number determinant_{Determinant()};
  if (determinant_ != static_cast<Number>(0)) {
    return std::optional<Dyad<Number>>{Adjugate() / determinant_};
  }
  return std::nullopt;
}

template <typename Number>
inline constexpr Dyad<Number> Vector<Number>::Dyadic(const Vector<Number>& vector) const {
  return Dyad<Number>{
      x_y_z_[0] * vector.x_y_z_[0], x_y_z_[0] * vector.x_y_z_[1], x_y_z_[0] * vector.x_y_z_[2],
      x_y_z_[1] * vector.x_y_z_[0], x_y_z_[1] * vector.x_y_z_[1], x_y_z_[1] * vector.x_y_z_[2],
      x_y_z_[2] * vector.x_y_z_[0], x_y_z_[2] * vector.x_y_z_[1], x_y_z_[2] * vector.x_y_z_[2]};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Dyad<Number>> {
  inline size_t operator()(const PhQ::Dyad<Number>& dyad) const {
    size_t result{17};
    result = 31 * result + hash<Number>()(dyad.xx());
    result = 31 * result + hash<Number>()(dyad.xy());
    result = 31 * result + hash<Number>()(dyad.xz());
    result = 31 * result + hash<Number>()(dyad.yx());
    result = 31 * result + hash<Number>()(dyad.yy());
    result = 31 * result + hash<Number>()(dyad.yz());
    result = 31 * result + hash<Number>()(dyad.zx());
    result = 31 * result + hash<Number>()(dyad.zy());
    result = 31 * result + hash<Number>()(dyad.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_DYAD_HPP
