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

#ifndef PHQ_SOUND_SPEED_HPP
#define PHQ_SOUND_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsentropicBulkModulus.hpp"
#include "MassDensity.hpp"
#include "SpecificGasConstant.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"
#include "Temperature.hpp"

namespace PhQ {

// Forward declaration for class PhQ::SoundSpeed.
template <typename NumericType>
class MachNumber;

// Forward declaration for class PhQ::SoundSpeed.
template <typename NumericType>
class Speed;

/// \brief Speed of sound. Applies to any deformable material, including fluids and deformable
/// solids. Defined as the ratio of a material's isentropic bulk modulus to its mass density; see
/// PhQ::IsentropicBulkModulus and PhQ::MassDensity. The speed of sound also appears in the
/// definition of the Mach number; see PhQ::MachNumber and PhQ::Speed.
template <typename NumericType = double>
class SoundSpeed : public DimensionalScalar<Unit::Speed, NumericType> {
public:
  /// \brief Default constructor. Constructs a sound speed with an uninitialized value.
  SoundSpeed() = default;

  /// \brief Constructs a sound speed from a given value and speed unit.
  SoundSpeed(const NumericType value, const Unit::Speed unit)
    : DimensionalScalar<Unit::Speed, NumericType>(value, unit) {}

  /// \brief Constructs a sound speed from an isentropic bulk modulus and a mass density. This is
  /// the definition of the sound speed; this relation always holds true.
  SoundSpeed(const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
             const MassDensity<NumericType>& mass_density)
    : SoundSpeed<NumericType>(std::sqrt(isentropic_bulk_modulus.Value() / mass_density.Value())) {}

  /// \brief Constructs a sound speed from a heat capacity ratio, a static pressure, and a mass
  /// density. This relation applies only to an ideal gas.
  SoundSpeed(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
             const StaticPressure<NumericType>& static_pressure,
             const MassDensity<NumericType>& mass_density)
    : SoundSpeed<NumericType>(
        std::sqrt(heat_capacity_ratio.Value() * static_pressure.Value() / mass_density.Value())) {}

  /// \brief Constructs a sound speed from a heat capacity ratio, a specific gas constant, and a
  /// temperature. This relation applies only to an ideal gas.
  SoundSpeed(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
             const SpecificGasConstant<NumericType>& specific_gas_constant,
             const Temperature<NumericType>& temperature)
    : SoundSpeed<NumericType>(std::sqrt(
        heat_capacity_ratio.Value() * specific_gas_constant.Value() * temperature.Value())) {}

  /// \brief Constructs a sound speed from a speed and a Mach number. This uses the definition of
  /// the Mach number; this relation always holds true.
  constexpr SoundSpeed(const Speed<NumericType>& speed, const MachNumber<NumericType>& mach_number);

  /// \brief Destructor. Destroys this sound speed.
  ~SoundSpeed() noexcept = default;

  /// \brief Copy constructor. Constructs a sound speed by copying another one.
  constexpr SoundSpeed(const SoundSpeed<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a sound speed by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SoundSpeed(const SoundSpeed<OtherNumericType>& other)
    : SoundSpeed(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a sound speed by moving another one.
  constexpr SoundSpeed(SoundSpeed<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this sound speed by copying another one.
  constexpr SoundSpeed<NumericType>& operator=(const SoundSpeed<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this sound speed by copying another one.
  template <typename OtherNumericType>
  constexpr SoundSpeed<NumericType>& operator=(const SoundSpeed<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this sound speed by moving another one.
  constexpr SoundSpeed<NumericType>& operator=(SoundSpeed<NumericType>&& other) noexcept = default;

  [[nodiscard]] static constexpr SoundSpeed<NumericType> Zero() {
    return SoundSpeed<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Creates a sound speed from a given value and speed unit.
  template <Unit::Speed Unit>
  [[nodiscard]] static constexpr SoundSpeed<NumericType> Create(const NumericType value) {
    return SoundSpeed<NumericType>{
        ConvertStatically<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  constexpr SoundSpeed<NumericType> operator+(const SoundSpeed<NumericType>& speed) const {
    return SoundSpeed<NumericType>{this->value + speed.value};
  }

  constexpr Speed<NumericType> operator+(const Speed<NumericType>& speed) const {
    return Speed<NumericType>{this->value + speed.value};
  }

  constexpr SoundSpeed<NumericType> operator-(const SoundSpeed<NumericType>& speed) const {
    return SoundSpeed<NumericType>{this->value - speed.value};
  }

  constexpr Speed<NumericType> operator-(const Speed<NumericType>& speed) const {
    return Speed<NumericType>{this->value - speed.value};
  }

  constexpr SoundSpeed<NumericType> operator*(const NumericType number) const {
    return SoundSpeed<NumericType>{this->value * number};
  }

  constexpr Speed<NumericType> operator*(const MachNumber<NumericType>& mach_number) const;

  constexpr SoundSpeed<NumericType> operator/(const NumericType number) const {
    return SoundSpeed<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const SoundSpeed<NumericType>& sound_speed) const noexcept {
    return this->value / sound_speed.value;
  }

  constexpr void operator+=(const SoundSpeed<NumericType>& sound_speed) noexcept {
    this->value += sound_speed.value;
  }

  constexpr void operator+=(const Speed<NumericType>& speed) noexcept {
    this->value += speed.value;
  }

  constexpr void operator-=(const SoundSpeed<NumericType>& sound_speed) noexcept {
    this->value -= sound_speed.value;
  }

  constexpr void operator-=(const Speed<NumericType>& speed) noexcept {
    this->value -= speed.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a sound speed with a given value expressed in the standard
  /// speed unit.
  explicit constexpr SoundSpeed(const NumericType value)
    : DimensionalScalar<Unit::Speed, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SoundSpeed<NumericType>& left, const SoundSpeed<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const SoundSpeed<NumericType>& sound_speed) {
  stream << sound_speed.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SoundSpeed<NumericType> operator*(
    const NumericType number, const SoundSpeed<NumericType>& sound_speed) {
  return sound_speed * number;
}

template <typename NumericType>
inline constexpr Speed<NumericType> Speed<NumericType>::operator+(
    const SoundSpeed<NumericType>& sound_speed) const {
  return Speed<NumericType>{this->value + sound_speed.Value()};
}

template <typename NumericType>
inline constexpr Speed<NumericType> Speed<NumericType>::operator-(
    const SoundSpeed<NumericType>& sound_speed) const {
  return Speed<NumericType>{this->value - sound_speed.Value()};
}

template <typename NumericType>
inline constexpr void Speed<NumericType>::operator+=(
    const SoundSpeed<NumericType>& speed) noexcept {
  this->value += speed.Value();
}

template <typename NumericType>
inline constexpr void Speed<NumericType>::operator-=(
    const SoundSpeed<NumericType>& speed) noexcept {
  this->value -= speed.Value();
}

template <typename NumericType>
constexpr MassDensity<NumericType>::MassDensity(
    const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
    const SoundSpeed<NumericType>& sound_speed)
  : MassDensity<NumericType>(isentropic_bulk_modulus.Value() / std::pow(sound_speed.Value(), 2)) {}

template <typename NumericType>
constexpr IsentropicBulkModulus<NumericType>::IsentropicBulkModulus(
    const MassDensity<NumericType>& mass_density, const SoundSpeed<NumericType>& sound_speed)
  : IsentropicBulkModulus<NumericType>(mass_density.Value() * std::pow(sound_speed.Value(), 2)) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SoundSpeed<NumericType>> {
  inline size_t operator()(const PhQ::SoundSpeed<NumericType>& sound_speed) const {
    return hash<NumericType>()(sound_speed.Value());
  }
};

}  // namespace std

#endif  // PHQ_SOUND_SPEED_HPP
