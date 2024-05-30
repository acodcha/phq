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
#include "MassRate.hpp"
#include "Unit/MassDensity.hpp"
#include "Volume.hpp"
#include "VolumeRate.hpp"

namespace PhQ {

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class DynamicPressure;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class IsentropicBulkModulus;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class KinematicViscosity;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class ReynoldsNumber;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class SoundSpeed;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::MassDensity.
template <typename NumericType>
class ThermalDiffusivity;

/// \brief Mass density. Mass per unit volume; see PhQ::Mass and PhQ::Volume.
template <typename NumericType = double>
class MassDensity : public DimensionalScalar<Unit::MassDensity, NumericType> {
public:
  /// \brief Default constructor. Constructs a mass density with an uninitialized value.
  MassDensity() = default;

  /// \brief Constructor. Constructs a mass density with a given value expressed in a given mass
  /// density unit.
  MassDensity(const NumericType value, const Unit::MassDensity unit)
    : DimensionalScalar<Unit::MassDensity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a mass density from a given mass and volume using the
  /// definition of mass density.
  constexpr MassDensity(const Mass<NumericType>& mass, const Volume<NumericType>& volume)
    : MassDensity<NumericType>(mass.Value() / volume.Value()) {}

  /// \brief Constructor. Constructs a mass density from a given mass rate and volume rate using the
  /// definition of mass density.
  constexpr MassDensity(
      const MassRate<NumericType>& mass_rate, const VolumeRate<NumericType>& volume_rate)
    : MassDensity<NumericType>(mass_rate.Value() / volume_rate.Value()) {}

  /// \brief Constructor. Constructs a mass density from a given dynamic viscosity and kinematic
  /// viscosity using the definition of kinematic viscosity.
  constexpr MassDensity(const DynamicViscosity<NumericType>& dynamic_viscosity,
                        const KinematicViscosity<NumericType>& kinematic_viscosity);

  /// \brief Constructor. Constructs a mass density from a given scalar thermal conductivity,
  /// thermal diffusivity, and specific isobaric heat capacity using the definition of thermal
  /// diffusivity.
  constexpr MassDensity(
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const ThermalDiffusivity<NumericType>& thermal_diffusivity,
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity);

  /// \brief Constructor. Constructs a mass density from a given dynamic pressure and speed using
  /// the definition of dynamic pressure.
  constexpr MassDensity(
      const DynamicPressure<NumericType>& dynamic_pressure, const Speed<NumericType>& speed);

  /// \brief Constructor. Constructs a mass density from a given Reynolds number, dynamic viscosity,
  /// speed, and length using the definition of the Reynolds number.
  constexpr MassDensity(const ReynoldsNumber<NumericType>& reynolds_number,
                        const DynamicViscosity<NumericType>& dynamic_viscosity,
                        const Speed<NumericType>& speed, const Length<NumericType>& length);

  /// \brief Constructor. Constructs a mass density from a given isentropic bulk modulus and sound
  /// speed using the definition of the isentropic bulk modulus.
  constexpr MassDensity(const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
                        const SoundSpeed<NumericType>& sound_speed);

  /// \brief Destructor. Destroys this mass density.
  ~MassDensity() noexcept = default;

  /// \brief Copy constructor. Constructs a mass density by copying another one.
  constexpr MassDensity(const MassDensity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a mass density by copying another one.
  template <typename OtherNumericType>
  explicit constexpr MassDensity(const MassDensity<OtherNumericType>& other)
    : MassDensity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a mass density by moving another one.
  constexpr MassDensity(MassDensity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this mass density by copying another one.
  constexpr MassDensity<NumericType>& operator=(const MassDensity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this mass density by copying another one.
  template <typename OtherNumericType>
  constexpr MassDensity<NumericType>& operator=(const MassDensity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this mass density by moving another one.
  constexpr MassDensity<NumericType>& operator=(
      MassDensity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a mass density of zero.
  static constexpr MassDensity<NumericType> Zero() {
    return MassDensity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a mass density with a given value expressed in a given mass density
  /// unit.
  template <Unit::MassDensity Unit>
  static constexpr MassDensity<NumericType> Create(const NumericType value) {
    return MassDensity<NumericType>{
        StaticConvertCopy<Unit::MassDensity, Unit, Standard<Unit::MassDensity>>(value)};
  }

  constexpr MassDensity<NumericType> operator+(const MassDensity<NumericType>& mass_density) const {
    return MassDensity<NumericType>{this->value + mass_density.value};
  }

  constexpr MassDensity<NumericType> operator-(const MassDensity<NumericType>& mass_density) const {
    return MassDensity<NumericType>{this->value - mass_density.value};
  }

  constexpr MassDensity<NumericType> operator*(const NumericType number) const {
    return MassDensity<NumericType>{this->value * number};
  }

  constexpr Mass<NumericType> operator*(const Volume<NumericType>& volume) const {
    return Mass<NumericType>{*this, volume};
  }

  constexpr MassRate<NumericType> operator*(const VolumeRate<NumericType>& volume_rate) const {
    return MassRate<NumericType>{*this, volume_rate};
  }

  constexpr DynamicViscosity<NumericType> operator*(
      const KinematicViscosity<NumericType>& kinematic_viscosity) const;

  constexpr MassDensity<NumericType> operator/(const NumericType number) const {
    return MassDensity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const MassDensity<NumericType>& mass_density) const noexcept {
    return this->value / mass_density.value;
  }

  constexpr void operator+=(const MassDensity<NumericType>& mass_density) noexcept {
    this->value += mass_density.value;
  }

  constexpr void operator-=(const MassDensity<NumericType>& mass_density) noexcept {
    this->value -= mass_density.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a mass density with a given value expressed in the standard
  /// mass density unit.
  explicit constexpr MassDensity(const NumericType value)
    : DimensionalScalar<Unit::MassDensity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const MassDensity<NumericType>& left, const MassDensity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const MassDensity<NumericType>& mass_density) {
  stream << mass_density.Print();
  return stream;
}

template <typename NumericType>
inline constexpr MassDensity<NumericType> operator*(
    const NumericType number, const MassDensity<NumericType>& mass_density) {
  return mass_density * number;
}

template <typename NumericType>
inline constexpr Volume<NumericType>::Volume(
    const Mass<NumericType>& mass, const MassDensity<NumericType>& mass_density)
  : Volume<NumericType>(mass.Value() / mass_density.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const MassDensity<NumericType>& mass_density, const Volume<NumericType>& volume)
  : Mass<NumericType>(mass_density.Value() * volume.Value()) {}

template <typename NumericType>
inline constexpr MassRate<NumericType>::MassRate(
    const MassDensity<NumericType>& mass_density, const VolumeRate<NumericType>& volume_rate)
  : MassRate<NumericType>(mass_density.Value() * volume_rate.Value()) {}

template <typename NumericType>
inline constexpr VolumeRate<NumericType>::VolumeRate(
    const MassRate<NumericType>& mass_rate, const MassDensity<NumericType>& mass_density)
  : VolumeRate<NumericType>(mass_rate.Value() / mass_density.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType> Volume<NumericType>::operator*(
    const MassDensity<NumericType>& mass_density) const {
  return Mass<NumericType>{mass_density, *this};
}

template <typename NumericType>
inline constexpr MassRate<NumericType> VolumeRate<NumericType>::operator*(
    const MassDensity<NumericType>& mass_density) const {
  return MassRate<NumericType>{mass_density, *this};
}

template <typename NumericType>
inline constexpr MassDensity<NumericType> Mass<NumericType>::operator/(
    const Volume<NumericType>& volume) const {
  return MassDensity<NumericType>{*this, volume};
}

template <typename NumericType>
inline constexpr Volume<NumericType> Mass<NumericType>::operator/(
    const MassDensity<NumericType>& mass_density) const {
  return Volume<NumericType>{*this, mass_density};
}

template <typename NumericType>
inline constexpr MassDensity<NumericType> MassRate<NumericType>::operator/(
    const VolumeRate<NumericType>& volume_rate) const {
  return MassDensity<NumericType>{*this, volume_rate};
}

template <typename NumericType>
inline constexpr VolumeRate<NumericType> MassRate<NumericType>::operator/(
    const MassDensity<NumericType>& mass_density) const {
  return VolumeRate<NumericType>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::MassDensity<NumericType>> {
  inline size_t operator()(const PhQ::MassDensity<NumericType>& mass_density) const {
    return hash<NumericType>()(mass_density.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_DENSITY_HPP
