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

#ifndef PHQ_MASS_DENSITY_HPP
#define PHQ_MASS_DENSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Mass.hpp"
#include "Unit/MassDensity.hpp"
#include "Volume.hpp"

namespace PhQ {

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class DynamicPressure;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class IsentropicBulkModulus;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class KinematicViscosity;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class ReynoldsNumber;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class SoundSpeed;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::MassDensity.
template <typename Number>
class ThermalDiffusivity;

/// \brief Mass density. Mass per unit volume; see PhQ::Mass and PhQ::Volume.
template <typename Number = double>
class MassDensity : public DimensionalScalar<Unit::MassDensity, Number> {
public:
  /// \brief Default constructor. Constructs a mass density with an uninitialized value.
  MassDensity() = default;

  /// \brief Constructor. Constructs a mass density with a given value expressed in a given mass
  /// density unit.
  MassDensity(const Number value, const Unit::MassDensity unit)
    : DimensionalScalar<Unit::MassDensity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a mass density from a given mass and volume using the
  /// definition of mass density.
  constexpr MassDensity(const Mass<Number>& mass, const Volume<Number>& volume)
    : MassDensity<Number>(mass.Value() / volume.Value()) {}

  /// \brief Constructor. Constructs a mass density from a given dynamic viscosity and kinematic
  /// viscosity using the definition of kinematic viscosity.
  constexpr MassDensity(const DynamicViscosity<Number>& dynamic_viscosity,
                        const KinematicViscosity<Number>& kinematic_viscosity);

  /// \brief Constructor. Constructs a mass density from a given scalar thermal conductivity,
  /// thermal diffusivity, and specific isobaric heat capacity using the definition of thermal
  /// diffusivity.
  constexpr MassDensity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const ThermalDiffusivity<Number>& thermal_diffusivity,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity);

  /// \brief Constructor. Constructs a mass density from a given dynamic pressure and speed using
  /// the definition of dynamic pressure.
  constexpr MassDensity(
      const DynamicPressure<Number>& dynamic_pressure, const Speed<Number>& speed);

  /// \brief Constructor. Constructs a mass density from a given Reynolds number, dynamic viscosity,
  /// speed, and length using the definition of the Reynolds number.
  constexpr MassDensity(const ReynoldsNumber<Number>& reynolds_number,
                        const DynamicViscosity<Number>& dynamic_viscosity,
                        const Speed<Number>& speed, const Length<Number>& length);

  /// \brief Constructor. Constructs a mass density from a given isentropic bulk modulus and sound
  /// speed using the definition of the isentropic bulk modulus.
  constexpr MassDensity(const IsentropicBulkModulus<Number>& isentropic_bulk_modulus,
                        const SoundSpeed<Number>& sound_speed);

  /// \brief Destructor. Destroys this mass density.
  ~MassDensity() noexcept = default;

  /// \brief Copy constructor. Constructs a mass density by copying another one.
  constexpr MassDensity(const MassDensity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a mass density by copying another one.
  template <typename OtherNumber>
  explicit constexpr MassDensity(const MassDensity<OtherNumber>& other)
    : MassDensity(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a mass density by moving another one.
  constexpr MassDensity(MassDensity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this mass density by copying another one.
  constexpr MassDensity<Number>& operator=(const MassDensity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this mass density by copying another one.
  template <typename OtherNumber>
  constexpr MassDensity<Number>& operator=(const MassDensity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this mass density by moving another one.
  constexpr MassDensity<Number>& operator=(MassDensity<Number>&& other) noexcept = default;

  /// \brief Statically creates a mass density of zero.
  static constexpr MassDensity<Number> Zero() {
    return MassDensity<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a mass density with a given value expressed in a given mass density
  /// unit.
  template <Unit::MassDensity Unit>
  static constexpr MassDensity<Number> Create(const Number value) {
    return MassDensity<Number>{
        StaticConvertCopy<Unit::MassDensity, Unit, Standard<Unit::MassDensity>>(value)};
  }

  constexpr MassDensity<Number> operator+(const MassDensity<Number>& mass_density) const {
    return MassDensity<Number>{this->value + mass_density.value};
  }

  constexpr MassDensity<Number> operator-(const MassDensity<Number>& mass_density) const {
    return MassDensity<Number>{this->value - mass_density.value};
  }

  constexpr MassDensity<Number> operator*(const Number number) const {
    return MassDensity<Number>{this->value * number};
  }

  constexpr Mass<Number> operator*(const Volume<Number>& volume) const {
    return Mass<Number>{*this, volume};
  }

  constexpr DynamicViscosity<Number> operator*(
      const KinematicViscosity<Number>& kinematic_viscosity) const;

  constexpr MassDensity<Number> operator/(const Number number) const {
    return MassDensity<Number>{this->value / number};
  }

  constexpr Number operator/(const MassDensity<Number>& mass_density) const noexcept {
    return this->value / mass_density.value;
  }

  constexpr void operator+=(const MassDensity<Number>& mass_density) noexcept {
    this->value += mass_density.value;
  }

  constexpr void operator-=(const MassDensity<Number>& mass_density) noexcept {
    this->value -= mass_density.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a mass density with a given value expressed in the standard
  /// mass density unit.
  explicit constexpr MassDensity(const Number value)
    : DimensionalScalar<Unit::MassDensity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const MassDensity<Number>& left, const MassDensity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const MassDensity<Number>& mass_density) {
  stream << mass_density.Print();
  return stream;
}

template <typename Number>
inline constexpr MassDensity<Number> operator*(
    const Number number, const MassDensity<Number>& mass_density) {
  return mass_density * number;
}

template <typename Number>
inline constexpr Volume<Number>::Volume(
    const Mass<Number>& mass, const MassDensity<Number>& mass_density)
  : Volume<Number>(mass.Value() / mass_density.Value()) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const MassDensity<Number>& mass_density, const Volume<Number>& volume)
  : Mass<Number>(mass_density.Value() * volume.Value()) {}

template <typename Number>
inline constexpr MassDensity<Number> Mass<Number>::operator/(const Volume<Number>& volume) const {
  return MassDensity<Number>{*this, volume};
}

template <typename Number>
inline constexpr Volume<Number> Mass<Number>::operator/(
    const MassDensity<Number>& mass_density) const {
  return Volume<Number>{*this, mass_density};
}

template <typename Number>
inline constexpr Mass<Number> Volume<Number>::operator*(
    const MassDensity<Number>& mass_density) const {
  return Mass<Number>{mass_density, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::MassDensity<Number>> {
  inline size_t operator()(const PhQ::MassDensity<Number>& mass_density) const {
    return hash<Number>()(mass_density.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_DENSITY_HPP
