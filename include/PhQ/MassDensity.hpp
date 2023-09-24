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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_DENSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_DENSITY_HPP

#include "Mass.hpp"
#include "Unit/MassDensity.hpp"
#include "Volume.hpp"

namespace PhQ {

// Forward declarations for class MassDensity.
class DynamicPressure;
class DynamicViscosity;
class IsentropicBulkModulus;
class KinematicViscosity;
class ReynoldsNumber;
class SoundSpeed;
class SpecificIsobaricHeatCapacity;
class Speed;
class ThermalConductivityScalar;
class ThermalDiffusivity;

// Mass density.
class MassDensity : public DimensionalScalarQuantity<Unit::MassDensity> {
public:
  // Default constructor. Constructs a mass density with an uninitialized value.
  MassDensity() = default;

  // Constructor. Constructs a mass density with a given value expressed in a
  // given mass density unit.
  MassDensity(const double value, const Unit::MassDensity unit)
    : DimensionalScalarQuantity<Unit::MassDensity>(value, unit) {}

  // Constructor. Constructs a mass density from a given mass and volume using
  // the definition of mass density.
  constexpr MassDensity(const Mass& mass, const Volume& volume)
    : MassDensity(mass.Value() / volume.Value()) {}

  // Constructor. Constructs a mass density from a given dynamic viscosity and
  // kinematic viscosity using the definition of kinematic viscosity.
  constexpr MassDensity(const DynamicViscosity& dynamic_viscosity,
                        const KinematicViscosity& kinematic_viscosity);

  // Constructor. Constructs a mass density from a given thermal diffusivity,
  // thermal conductivity, and specific isobaric heat capacity using the
  // definition of thermal diffusivity.
  constexpr MassDensity(
      const ThermalDiffusivity& thermal_diffusivity,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity);

  // Constructor. Constructs a mass density from a given dynamic pressure and
  // speed using the definition of dynamic pressure.
  constexpr MassDensity(
      const DynamicPressure& dynamic_pressure, const Speed& speed);

  // Constructor. Constructs a mass density from a given Reynolds number,
  // dynamic viscosity, speed, and length using the definition of the Reynolds
  // number.
  constexpr MassDensity(const ReynoldsNumber& reynolds_number,
                        const DynamicViscosity& dynamic_viscosity,
                        const Speed& speed, const Length& length);

  // Constructor. Constructs a mass density from a given isentropic bulk modulus
  // and sound speed using the definition of the isentropic bulk modulus.
  constexpr MassDensity(const IsentropicBulkModulus& isentropic_bulk_modulus,
                        const SoundSpeed& sound_speed);

  // Destructor. Destroys this mass density.
  ~MassDensity() noexcept = default;

  // Copy constructor. Constructs a mass density by copying another one.
  constexpr MassDensity(const MassDensity& other) = default;

  // Move constructor. Constructs a mass density by moving another one.
  constexpr MassDensity(MassDensity&& other) noexcept = default;

  // Copy assignment operator. Assigns this mass density by copying another one.
  constexpr MassDensity& operator=(const MassDensity& other) = default;

  // Move assignment operator. Assigns this mass density by moving another one.
  constexpr MassDensity& operator=(MassDensity&& other) noexcept = default;

  // Statically creates a mass density of zero.
  static constexpr MassDensity Zero() {
    return MassDensity{0.0};
  }

  // Statically creates a mass density with a given value expressed in a given
  // mass density unit.
  template <Unit::MassDensity Unit>
  static constexpr MassDensity Create(const double value) {
    return MassDensity{
        StaticConvertCopy<Unit::MassDensity, Unit, Standard<Unit::MassDensity>>(
            value)};
  }

  constexpr MassDensity operator+(const MassDensity& mass_density) const {
    return MassDensity{value_ + mass_density.value_};
  }

  constexpr MassDensity operator-(const MassDensity& mass_density) const {
    return MassDensity{value_ - mass_density.value_};
  }

  constexpr MassDensity operator*(const double number) const {
    return MassDensity{value_ * number};
  }

  constexpr Mass operator*(const Volume& volume) const {
    return Mass{*this, volume};
  }

  constexpr DynamicViscosity operator*(
      const KinematicViscosity& kinematic_viscosity) const;

  constexpr MassDensity operator/(const double number) const {
    return MassDensity{value_ / number};
  }

  constexpr double operator/(const MassDensity& mass_density) const noexcept {
    return value_ / mass_density.value_;
  }

  constexpr void operator+=(const MassDensity& mass_density) noexcept {
    value_ += mass_density.value_;
  }

  constexpr void operator-=(const MassDensity& mass_density) noexcept {
    value_ -= mass_density.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a mass density with a given value expressed in the
  // standard mass density unit.
  explicit constexpr MassDensity(const double value)
    : DimensionalScalarQuantity<Unit::MassDensity>(value) {}
};

inline constexpr bool operator==(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const MassDensity& left, const MassDensity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const MassDensity& mass_density) {
  stream << mass_density.Print();
  return stream;
}

inline constexpr MassDensity operator*(
    const double number, const MassDensity& mass_density) {
  return mass_density * number;
}

inline constexpr Volume::Volume(
    const MassDensity& mass_density, const Mass& mass)
  : Volume(mass.Value() / mass_density.Value()) {}

inline constexpr Mass::Mass(
    const MassDensity& mass_density, const Volume& volume)
  : Mass(mass_density.Value() * volume.Value()) {}

inline constexpr MassDensity Mass::operator/(const Volume& volume) const {
  return MassDensity{*this, volume};
}

inline constexpr Mass Volume::operator*(const MassDensity& mass_density) const {
  return Mass{mass_density, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::MassDensity> {
  inline size_t operator()(const PhQ::MassDensity& mass_density) const {
    return hash<double>()(mass_density.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_DENSITY_HPP
