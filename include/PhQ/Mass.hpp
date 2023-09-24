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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

// Forward declarations for class Mass.
class Time;
class Energy;
class Frequency;
class GasConstant;
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class MassDensity;
class MassRate;
class Power;
class SpecificEnergy;
class SpecificGasConstant;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;
class SpecificPower;
class Volume;

// Mass.
class Mass : public DimensionalScalarQuantity<Unit::Mass> {
public:
  // Default constructor. Constructs a mass with an uninitialized value.
  Mass() = default;

  // Constructor. Constructs a mass with a given value expressed in a given mass
  // unit.
  Mass(const double value, const Unit::Mass unit)
    : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

  // Constructor. Constructs a mass from a given mass density and volume using
  // the definition of mass density.
  constexpr Mass(const MassDensity& mass_density, const Volume& volume);

  // Constructor. Constructs a mass from a given mass rate and time using the
  // definition of mass rate.
  constexpr Mass(const MassRate& mass_rate, const Time& time);

  // Constructor. Constructs a mass from a given mass rate and frequency using
  // the definition of mass rate.
  constexpr Mass(const MassRate& mass_rate, const Frequency& frequency);

  // Constructor. Constructs a mass from a given specific energy and energy
  // using the definition of specific energy.
  constexpr Mass(const SpecificEnergy& specific_energy, const Energy& energy);

  // Constructor. Constructs a mass from a given specific power and power using
  // the definition of specific power.
  constexpr Mass(const SpecificPower& specific_power, const Power& power);

  // Constructor. Constructs a mass from a given specific gas constant and gas
  // constant using the definition of the specific gas constant.
  constexpr Mass(const SpecificGasConstant& specific_gas_constant,
                 const GasConstant& gas_constant);

  // Constructor. Constructs a mass from a given specific isobaric heat capacity
  // and isobaric heat capacity using the definition of the specific isobaric
  // heat capacity.
  constexpr Mass(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const IsobaricHeatCapacity& isobaric_heat_capacity);

  // Constructor. Constructs a mass from a given specific isochoric heat
  // capacity and isochoric heat capacity using the definition of the specific
  // isochoric heat capacity.
  constexpr Mass(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const IsochoricHeatCapacity& isochoric_heat_capacity);

  // Destructor. Destroys this mass.
  ~Mass() noexcept = default;

  // Copy constructor. Constructs a mass by copying another one.
  constexpr Mass(const Mass& other) = default;

  // Move constructor. Constructs a mass by moving another one.
  constexpr Mass(Mass&& other) noexcept = default;

  // Copy assignment operator. Assigns this mass by copying another one.
  constexpr Mass& operator=(const Mass& other) = default;

  // Move assignment operator. Assigns this mass by moving another one.
  constexpr Mass& operator=(Mass&& other) noexcept = default;

  // Statically creates a mass of zero.
  static constexpr Mass Zero() {
    return Mass{0.0};
  }

  // Statically creates a mass with a given value expressed in a given mass
  // unit.
  template <Unit::Mass Unit>
  static constexpr Mass Create(const double value) {
    return Mass{
        StaticConvertCopy<Unit::Mass, Unit, Standard<Unit::Mass>>(value)};
  }

  constexpr Mass operator+(const Mass& mass) const {
    return Mass{value_ + mass.value_};
  }

  constexpr Mass operator-(const Mass& mass) const {
    return Mass{value_ - mass.value_};
  }

  constexpr Mass operator*(const double number) const {
    return Mass{value_ * number};
  }

  constexpr MassRate operator*(const Frequency& frequency) const;

  constexpr Energy operator*(const SpecificEnergy& specific_energy) const;

  constexpr Power operator*(const SpecificPower& specific_power) const;

  constexpr IsobaricHeatCapacity
  operator*(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const;

  constexpr IsochoricHeatCapacity operator*(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const;

  constexpr GasConstant operator*(
      const SpecificGasConstant& specific_gas_constant) const;

  constexpr Mass operator/(const double number) const {
    return Mass{value_ / number};
  }

  constexpr MassDensity operator/(const Volume& volume) const;

  constexpr MassRate operator/(const Time& time) const;

  constexpr Time operator/(const MassRate& mass_rate) const;

  constexpr double operator/(const Mass& mass) const noexcept {
    return value_ / mass.value_;
  }

  constexpr void operator+=(const Mass& mass) noexcept {
    value_ += mass.value_;
  }

  constexpr void operator-=(const Mass& mass) noexcept {
    value_ -= mass.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a mass with a given value expressed in the standard
  // mass unit.
  explicit constexpr Mass(const double value)
    : DimensionalScalarQuantity<Unit::Mass>(value) {}
};

inline constexpr bool operator==(const Mass& left, const Mass& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Mass& left, const Mass& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Mass& left, const Mass& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Mass& left, const Mass& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Mass& left, const Mass& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Mass& left, const Mass& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Mass& mass) {
  stream << mass.Print();
  return stream;
}

inline constexpr Mass operator*(const double number, const Mass& mass) {
  return mass * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Mass> {
  inline size_t operator()(const PhQ::Mass& mass) const {
    return hash<double>()(mass.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_HPP
