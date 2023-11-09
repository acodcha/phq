// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SOUND_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SOUND_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalarQuantity.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsentropicBulkModulus.hpp"
#include "MassDensity.hpp"
#include "SpecificGasConstant.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"
#include "Temperature.hpp"

namespace PhQ {

// Forward declarations for class SoundSpeed.
class MachNumber;
class Speed;

// Speed of sound. Applies to any deformable medium, including fluids and elastic solids.
class SoundSpeed : public DimensionalScalarQuantity<Unit::Speed> {
public:
  // Default constructor. Constructs a sound speed with an uninitialized value.
  SoundSpeed() = default;

  // Constructs a sound speed from a given value and speed unit.
  SoundSpeed(const double value, const Unit::Speed unit)
    : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  // Constructs a sound speed from an isentropic bulk modulus and a mass density. This is the
  // definition of the sound speed; this relation always holds true.
  SoundSpeed(const IsentropicBulkModulus& isentropic_bulk_modulus, const MassDensity& mass_density)
    : SoundSpeed(std::sqrt(isentropic_bulk_modulus.Value() / mass_density.Value())) {}

  // Constructs a sound speed from a heat capacity ratio, a static pressure, and a mass density.
  // This relation applies only to an ideal gas.
  SoundSpeed(const HeatCapacityRatio& heat_capacity_ratio, const StaticPressure& static_pressure,
             const MassDensity& mass_density)
    : SoundSpeed(
        std::sqrt(heat_capacity_ratio.Value() * static_pressure.Value() / mass_density.Value())) {}

  // Constructs a sound speed from a heat capacity ratio, a specific gas constant, and a
  // temperature. This relation applies only to an ideal gas.
  SoundSpeed(const HeatCapacityRatio& heat_capacity_ratio,
             const SpecificGasConstant& specific_gas_constant, const Temperature& temperature)
    : SoundSpeed(std::sqrt(
        heat_capacity_ratio.Value() * specific_gas_constant.Value() * temperature.Value())) {}

  // Constructs a sound speed from a speed and a Mach number. This uses the definition of the Mach
  // number; this relation always holds true.
  constexpr SoundSpeed(const Speed& speed, const MachNumber& mach_number);

  static constexpr SoundSpeed Zero() {
    return SoundSpeed{0.0};
  }

  // Creates a sound speed from a given value and speed unit.
  template <Unit::Speed Unit>
  static constexpr SoundSpeed Create(const double value) {
    return SoundSpeed{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  constexpr SoundSpeed operator+(const SoundSpeed& speed) const {
    return SoundSpeed{value_ + speed.value_};
  }

  constexpr Speed operator+(const Speed& speed) const {
    return Speed{value_ + speed.value_};
  }

  constexpr SoundSpeed operator-(const SoundSpeed& speed) const {
    return SoundSpeed{value_ - speed.value_};
  }

  constexpr Speed operator-(const Speed& speed) const {
    return Speed{value_ - speed.value_};
  }

  constexpr SoundSpeed operator*(const double number) const {
    return SoundSpeed{value_ * number};
  }

  constexpr Speed operator*(const MachNumber& mach_number) const;

  constexpr SoundSpeed operator/(const double number) const {
    return SoundSpeed{value_ / number};
  }

  constexpr double operator/(const SoundSpeed& sound_speed) const noexcept {
    return value_ / sound_speed.value_;
  }

  constexpr void operator+=(const SoundSpeed& sound_speed) noexcept {
    value_ += sound_speed.value_;
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  constexpr void operator-=(const SoundSpeed& sound_speed) noexcept {
    value_ -= sound_speed.value_;
  }

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a sound speed with a given value expressed in the standard speed unit.
  explicit constexpr SoundSpeed(const double value)
    : DimensionalScalarQuantity<Unit::Speed>(value) {}
};

inline constexpr bool operator==(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const SoundSpeed& left, const SoundSpeed& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const SoundSpeed& sound_speed) {
  stream << sound_speed.Print();
  return stream;
}

inline constexpr SoundSpeed operator*(const double number, const SoundSpeed& sound_speed) {
  return sound_speed * number;
}

inline constexpr Speed Speed::operator+(const SoundSpeed& sound_speed) const {
  return Speed{value_ + sound_speed.Value()};
}

inline constexpr Speed Speed::operator-(const SoundSpeed& sound_speed) const {
  return Speed{value_ - sound_speed.Value()};
}

inline constexpr void Speed::operator+=(const SoundSpeed& speed) noexcept {
  value_ += speed.Value();
}

inline constexpr void Speed::operator-=(const SoundSpeed& speed) noexcept {
  value_ -= speed.Value();
}

constexpr MassDensity::MassDensity(
    const IsentropicBulkModulus& isentropic_bulk_modulus, const SoundSpeed& sound_speed)
  : MassDensity(isentropic_bulk_modulus.Value() / std::pow(sound_speed.Value(), 2)) {}

constexpr IsentropicBulkModulus::IsentropicBulkModulus(
    const MassDensity& mass_density, const SoundSpeed& sound_speed)
  : IsentropicBulkModulus(mass_density.Value() * std::pow(sound_speed.Value(), 2)) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SoundSpeed> {
  inline size_t operator()(const PhQ::SoundSpeed& sound_speed) const {
    return hash<double>()(sound_speed.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SOUND_SPEED_HPP
