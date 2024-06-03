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

#ifndef PHQ_DURATION_HPP
#define PHQ_DURATION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Acceleration;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Angle;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class AngularSpeed;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Displacement;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class DisplacementGradient;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ElectricCharge;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ElectricCurrent;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Energy;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Mass;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class MassRate;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Memory;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class MemoryRate;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class PlanarAcceleration;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class PlanarDisplacement;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class PlanarVelocity;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Power;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarAcceleration;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarAngularAcceleration;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarDisplacementGradient;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarStrain;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarStrainRate;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class ScalarVelocityGradient;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class SpecificEnergy;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class SpecificPower;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Strain;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class StrainRate;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Velocity;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class VelocityGradient;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class Volume;

// Forward declaration for class PhQ::Time.
template <typename NumericType>
class VolumeRate;

/// \brief Time. Can represent either a point in time, a time duration, or a period. For the inverse
/// of time, see PhQ::Frequency.
template <typename NumericType = double>
class Time : public DimensionalScalar<Unit::Time, NumericType> {
public:
  /// \brief Default constructor. Constructs a time quantity with an uninitialized value.
  Time() = default;

  /// \brief Constructor. Constructs a time quantity with a given value expressed in a given time
  /// unit.
  Time(const NumericType value, const Unit::Time unit)
    : DimensionalScalar<Unit::Time, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a time quantity from a given frequency using the definition of
  /// frequency.
  explicit constexpr Time(const PhQ::Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a time quantity from a given speed and scalar acceleration
  /// using the definition of acceleration.
  constexpr Time(
      const Speed<NumericType>& speed, const ScalarAcceleration<NumericType>& scalar_acceleration);

  /// \brief Constructor. Constructs a time quantity from a given angular speed and scalar angular
  /// acceleration using the definition of angular acceleration.
  constexpr Time(const AngularSpeed<NumericType>& angular_speed,
                 const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration);

  /// \brief Constructor. Constructs a time quantity from a given angle and angular speed using the
  /// definition of angular speed.
  constexpr Time(const Angle<NumericType>& angle, const AngularSpeed<NumericType>& angular_speed);

  /// \brief Constructor. Constructs a time quantity from a given electric charge and electric
  /// current using the definition of electric current.
  constexpr Time(const ElectricCharge<NumericType>& electric_charge,
                 const ElectricCurrent<NumericType>& electric_current);

  /// \brief Constructor. Constructs a time quantity from a given mass and mass rate using the
  /// definition of mass rate.
  constexpr Time(const Mass<NumericType>& mass, const MassRate<NumericType>& mass_rate);

  /// \brief Constructor. Constructs a time quantity from a given memory and memory rate using the
  /// definition of memory rate.
  constexpr Time(const Memory<NumericType>& memory, const MemoryRate<NumericType>& memory_rate);

  /// \brief Constructor. Constructs a time quantity from a given energy and power using the
  /// definition of power.
  constexpr Time(const Energy<NumericType>& energy, const Power<NumericType>& power);

  /// \brief Constructor. Constructs a time quantity from a given specific energy and specific power
  /// using the definition of specific power.
  constexpr Time(const SpecificEnergy<NumericType>& specific_energy,
                 const SpecificPower<NumericType>& specific_power);

  /// \brief Constructor. Constructs a time quantity from a given length and speed using the
  /// definition of speed.
  constexpr Time(const Length<NumericType>& length, const Speed<NumericType>& speed);

  /// \brief Constructor. Constructs a time quantity from a given volume and volume rate using the
  /// definition of volume rate.
  constexpr Time(const Volume<NumericType>& volume, const VolumeRate<NumericType>& volume_rate);

  /// \brief Destructor. Destroys this time quantity.
  ~Time() noexcept = default;

  /// \brief Copy constructor. Constructs a time quantity by copying another one.
  constexpr Time(const Time<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a time quantity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Time(const Time<OtherNumericType>& other)
    : Time(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a time quantity by moving another one.
  constexpr Time(Time<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this time quantity by copying another one.
  constexpr Time<NumericType>& operator=(const Time<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this time quantity by copying another one.
  template <typename OtherNumericType>
  constexpr Time<NumericType>& operator=(const Time<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this time quantity by moving another one.
  constexpr Time<NumericType>& operator=(Time<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a time quantity of zero.
  [[nodiscard]] static constexpr Time<NumericType> Zero() {
    return Time<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a time quantity with a given value expressed in a given time unit.
  template <Unit::Time Unit>
  [[nodiscard]] static constexpr Time<NumericType> Create(const NumericType value) {
    return Time<NumericType>{ConvertStatically<Unit::Time, Unit, Standard<Unit::Time>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Frequency<NumericType> Frequency() const;

  constexpr Time<NumericType> operator+(const Time<NumericType>& time) const {
    return Time<NumericType>{this->value + time.value};
  }

  constexpr Time<NumericType> operator-(const Time<NumericType>& time) const {
    return Time<NumericType>{this->value - time.value};
  }

  constexpr Time<NumericType> operator*(const NumericType number) const {
    return Time<NumericType>{this->value * number};
  }

  constexpr NumericType operator*(const PhQ::Frequency<NumericType>& frequency) const noexcept;

  constexpr PlanarVelocity<NumericType> operator*(
      const PlanarAcceleration<NumericType>& planar_acceleration) const;

  constexpr Angle<NumericType> operator*(const AngularSpeed<NumericType>& angular_speed) const;

  constexpr AngularSpeed<NumericType> operator*(
      const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration) const;

  constexpr ElectricCharge<NumericType> operator*(
      const ElectricCurrent<NumericType>& electric_current) const;

  constexpr Velocity<NumericType> operator*(const Acceleration<NumericType>& acceleration) const;

  constexpr Speed<NumericType> operator*(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const;

  constexpr Mass<NumericType> operator*(const MassRate<NumericType>& mass_rate) const;

  constexpr Energy<NumericType> operator*(const Power<NumericType>& power) const;

  constexpr SpecificEnergy<NumericType> operator*(
      const SpecificPower<NumericType>& specific_power) const;

  constexpr Strain<NumericType> operator*(const StrainRate<NumericType>& strain_rate) const;

  constexpr ScalarStrain<NumericType> operator*(
      const ScalarStrainRate<NumericType>& scalar_strain_rate) const;

  constexpr PlanarDisplacement<NumericType> operator*(
      const PlanarVelocity<NumericType>& planar_velocity) const;

  constexpr Displacement<NumericType> operator*(const Velocity<NumericType>& velocity) const;

  constexpr DisplacementGradient<NumericType> operator*(
      const VelocityGradient<NumericType>& velocity_gradient) const;

  constexpr ScalarDisplacementGradient<NumericType> operator*(
      const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient) const;

  constexpr Volume<NumericType> operator*(const VolumeRate<NumericType>& volume_rate) const;

  constexpr Time<NumericType> operator/(const NumericType number) const {
    return Time<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const Time<NumericType>& time) const noexcept {
    return this->value / time.value;
  }

  constexpr void operator+=(const Time<NumericType>& time) noexcept {
    this->value += time.value;
  }

  constexpr void operator-=(const Time<NumericType>& time) noexcept {
    this->value -= time.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a time quantity with a given value expressed in the standard
  /// time unit.
  explicit constexpr Time(const NumericType value) : DimensionalScalar<Unit::Time>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Time<NumericType>& left, const Time<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Time<NumericType>& time) {
  stream << time.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Time<NumericType> operator*(
    const NumericType number, const Time<NumericType>& time) {
  return time * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Time<NumericType>> {
  inline size_t operator()(const PhQ::Time<NumericType>& time) const {
    return hash<NumericType>()(time.Value());
  }
};

}  // namespace std

#endif  // PHQ_DURATION_HPP
