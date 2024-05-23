// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

#ifndef PHQ_HEAT_FLUX_SCALAR_HPP
#define PHQ_HEAT_FLUX_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "ScalarThermalConductivity.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarHeatFlux.
template <typename Number>
class HeatFlux;

/// \brief Scalar heat flux component or magnitude of a heat flux vector. See also PhQ::HeatFlux.
template <typename Number = double>
class ScalarHeatFlux : public DimensionalScalar<Unit::EnergyFlux, Number> {
public:
  /// \brief Default constructor. Constructs a scalar heat flux with an uninitialized value.
  ScalarHeatFlux() = default;

  /// \brief Constructor. Constructs a scalar heat flux with a given value expressed in a given
  /// energy flux unit.
  ScalarHeatFlux(const Number value, const Unit::EnergyFlux unit)
    : DimensionalScalar<Unit::EnergyFlux, Number>(value, unit) {}

  /// \brief Constructor. Constructs a scalar heat flux from a given scalar thermal conductivity and
  /// scalar temperature gradient using Fourier's law of heat conduction. Since heat flows opposite
  /// the temperature gradient, the resulting scalar heat flux is negative.
  constexpr ScalarHeatFlux(const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
                           const ScalarTemperatureGradient<Number>& scalar_temperature_gradient)
    : ScalarHeatFlux<Number>(
        -scalar_thermal_conductivity.Value() * scalar_temperature_gradient.Value()) {}

  /// \brief Destructor. Destroys this scalar heat flux.
  ~ScalarHeatFlux() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar heat flux by copying another one.
  constexpr ScalarHeatFlux(const ScalarHeatFlux<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar heat flux by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarHeatFlux(const ScalarHeatFlux<OtherNumber>& other)
    : ScalarHeatFlux(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar heat flux by moving another one.
  constexpr ScalarHeatFlux(ScalarHeatFlux<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar heat flux by copying another one.
  constexpr ScalarHeatFlux<Number>& operator=(const ScalarHeatFlux<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar heat flux by copying another one.
  template <typename OtherNumber>
  constexpr ScalarHeatFlux<Number>& operator=(const ScalarHeatFlux<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar heat flux by moving another one.
  constexpr ScalarHeatFlux<Number>& operator=(ScalarHeatFlux<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar heat flux of zero.
  static constexpr ScalarHeatFlux<Number> Zero() {
    return ScalarHeatFlux<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar heat flux with a given value expressed in a given energy
  /// flux unit.
  template <Unit::EnergyFlux Unit>
  static constexpr ScalarHeatFlux<Number> Create(const Number value) {
    return ScalarHeatFlux<Number>{
        StaticConvertCopy<Unit::EnergyFlux, Unit, Standard<Unit::EnergyFlux>>(value)};
  }

  constexpr ScalarHeatFlux<Number> operator+(const ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return ScalarHeatFlux<Number>{this->value + scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux<Number> operator-(const ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return ScalarHeatFlux<Number>{this->value - scalar_heat_flux.value};
  }

  constexpr ScalarHeatFlux<Number> operator*(const Number number) const {
    return ScalarHeatFlux<Number>{this->value * number};
  }

  constexpr HeatFlux<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarHeatFlux<Number> operator/(const Number number) const {
    return ScalarHeatFlux<Number>{this->value / number};
  }

  constexpr Number operator/(const ScalarHeatFlux<Number>& scalar_heat_flux) const noexcept {
    return this->value / scalar_heat_flux.value;
  }

  constexpr void operator+=(const ScalarHeatFlux<Number>& scalar_heat_flux) noexcept {
    this->value += scalar_heat_flux.value;
  }

  constexpr void operator-=(const ScalarHeatFlux<Number>& scalar_heat_flux) noexcept {
    this->value -= scalar_heat_flux.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar heat flux with a given value expressed in the standard
  /// energy flux unit.
  explicit constexpr ScalarHeatFlux(const Number value)
    : DimensionalScalar<Unit::EnergyFlux, Number>(value) {}

  template <typename OtherNumber>
  friend class HeatFlux;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarHeatFlux<Number>& left, const ScalarHeatFlux<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarHeatFlux<Number>& scalar_heat_flux) {
  stream << scalar_heat_flux.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarHeatFlux<Number> operator*(
    const Number number, const ScalarHeatFlux<Number>& scalar_heat_flux) {
  return scalar_heat_flux * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarHeatFlux<Number>> {
  inline size_t operator()(const PhQ::ScalarHeatFlux<Number>& scalar_heat_flux) const {
    return hash<Number>()(scalar_heat_flux.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_FLUX_SCALAR_HPP
