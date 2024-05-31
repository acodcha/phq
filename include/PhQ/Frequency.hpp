// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_FREQUENCY_HPP
#define PHQ_FREQUENCY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

/// \brief Frequency. Inverse of a time duration. See also PhQ::Time.
template <typename NumericType = double>
class Frequency : public DimensionalScalar<Unit::Frequency, NumericType> {
public:
  /// \brief Default constructor. Constructs a frequency with an uninitialized value.
  Frequency() = default;

  /// \brief Constructor. Constructs a frequency with a given value expressed in a given frequency
  /// unit.
  Frequency(const NumericType value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a frequency from a given time period using the definition of
  /// frequency.
  constexpr explicit Frequency(const Time<NumericType>& time)
    : Frequency<NumericType>(1.0 / time.Value()) {}

  /// \brief Constructor. Constructs a frequency from a given scalar acceleration and speed using
  /// the definitions of acceleration and frequency.
  constexpr Frequency(
      const ScalarAcceleration<NumericType>& scalar_acceleration, const Speed<NumericType>& speed);

  /// \brief Constructor. Constructs a frequency from a given scalar angular acceleration and
  /// angular speed using the definitions of angular acceleration and frequency.
  constexpr Frequency(const ScalarAngularAcceleration<NumericType>& scalar_angular_acceleration,
                      const AngularSpeed<NumericType>& angular_speed);

  /// \brief Constructor. Constructs a frequency from a given angular speed and angle using the
  /// definitions of angular speed and frequency.
  constexpr Frequency(
      const AngularSpeed<NumericType>& angular_speed, const Angle<NumericType>& angle);

  /// \brief Constructor. Constructs a frequency from a given electric current and electric charge
  /// using the definitions of electric current and frequency.
  constexpr Frequency(const ElectricCurrent<NumericType>& electric_current,
                      const ElectricCharge<NumericType>& electric_charge);

  /// \brief Constructor. Constructs a frequency from a given mass rate and mass using the
  /// definitions of mass rate and frequency.
  constexpr Frequency(const MassRate<NumericType>& mass_rate, const Mass<NumericType>& mass);

  /// \brief Constructor. Constructs a frequency from a given memory rate and memory using the
  /// definitions of memory rate and frequency.
  constexpr Frequency(
      const MemoryRate<NumericType>& memory_rate, const Memory<NumericType>& memory);

  /// \brief Constructor. Constructs a frequency from a given power and energy using the definitions
  /// of power and frequency.
  constexpr Frequency(const Power<NumericType>& power, const Energy<NumericType>& energy);

  /// \brief Constructor. Constructs a frequency from a given specific power and specific energy
  /// using the definitions of specific power and frequency.
  constexpr Frequency(const SpecificPower<NumericType>& specific_power,
                      const SpecificEnergy<NumericType>& specific_energy);

  /// \brief Constructor. Constructs a frequency from a given speed and length using the definitions
  /// of speed and frequency.
  constexpr Frequency(const Speed<NumericType>& speed, const Length<NumericType>& length);

  /// \brief Constructor. Constructs a frequency from a given volume rate and volume using the
  /// definitions of volume rate and frequency.
  constexpr Frequency(
      const VolumeRate<NumericType>& volume_rate, const Volume<NumericType>& volume);

  /// \brief Destructor. Destroys this frequency.
  ~Frequency() noexcept = default;

  /// \brief Copy constructor. Constructs a frequency by copying another one.
  constexpr Frequency(const Frequency<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a frequency by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Frequency(const Frequency<OtherNumericType>& other)
    : Frequency(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a frequency by moving another one.
  constexpr Frequency(Frequency<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this frequency by copying another one.
  constexpr Frequency<NumericType>& operator=(const Frequency<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this frequency by copying another one.
  template <typename OtherNumericType>
  constexpr Frequency<NumericType>& operator=(const Frequency<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this frequency by moving another one.
  constexpr Frequency<NumericType>& operator=(Frequency<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a frequency of zero.
  static constexpr Frequency<NumericType> Zero() {
    return Frequency<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a frequency with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr Frequency<NumericType> Create(const NumericType value) {
    return Frequency<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Time period that corresponds to this frequency.
  [[nodiscard]] constexpr Time<NumericType> Period() const {
    return Time<NumericType>{*this};
  }

  constexpr Frequency<NumericType> operator+(const Frequency<NumericType>& frequency) const {
    return Frequency<NumericType>{this->value + frequency.value};
  }

  constexpr Frequency<NumericType> operator-(const Frequency<NumericType>& frequency) const {
    return Frequency<NumericType>{this->value - frequency.value};
  }

  constexpr Frequency<NumericType> operator*(const NumericType number) const {
    return Frequency<NumericType>{this->value * number};
  }

  constexpr Frequency<NumericType> operator/(const NumericType number) const {
    return Frequency<NumericType>{this->value / number};
  }

  constexpr NumericType operator*(const Time<NumericType>& time) const noexcept {
    return this->value * time.Value();
  }

  constexpr Speed<NumericType> operator*(const Length<NumericType>& length) const;

  constexpr AngularSpeed<NumericType> operator*(const Angle<NumericType>& angle) const;

  constexpr ElectricCurrent<NumericType> operator*(
      const ElectricCharge<NumericType>& electric_charge) const;

  constexpr PlanarVelocity<NumericType> operator*(
      const PlanarDisplacement<NumericType>& displacement) const;

  constexpr Velocity<NumericType> operator*(const Displacement<NumericType>& displacement) const;

  constexpr PlanarAcceleration<NumericType> operator*(
      const PlanarVelocity<NumericType>& displacement) const;

  constexpr Acceleration<NumericType> operator*(const Velocity<NumericType>& displacement) const;

  constexpr VelocityGradient<NumericType> operator*(
      const DisplacementGradient<NumericType>& displacement_gradient) const;

  constexpr ScalarVelocityGradient<NumericType> operator*(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const;

  constexpr MemoryRate<NumericType> operator*(const Memory<NumericType>& memory) const;

  constexpr ScalarAcceleration<NumericType> operator*(const Speed<NumericType>& speed) const;

  constexpr ScalarAngularAcceleration<NumericType> operator*(
      const AngularSpeed<NumericType>& angular_speed) const;

  constexpr MassRate<NumericType> operator*(const Mass<NumericType>& mass) const;

  constexpr VolumeRate<NumericType> operator*(const Volume<NumericType>& volume) const;

  constexpr Power<NumericType> operator*(const Energy<NumericType>& energy) const;

  constexpr SpecificPower<NumericType> operator*(
      const SpecificEnergy<NumericType>& specific_energy) const;

  constexpr StrainRate<NumericType> operator*(const Strain<NumericType>& strain) const;

  constexpr ScalarStrainRate<NumericType> operator*(
      const ScalarStrain<NumericType>& scalar_strain) const;

  constexpr NumericType operator/(const Frequency<NumericType>& frequency) const noexcept {
    return this->value / frequency.value;
  }

  constexpr void operator+=(const Frequency<NumericType>& frequency) noexcept {
    this->value += frequency.value;
  }

  constexpr void operator-=(const Frequency<NumericType>& frequency) noexcept {
    this->value -= frequency.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a frequency with a given value expressed in the standard
  /// frequency unit.
  explicit constexpr Frequency(const NumericType value)
    : DimensionalScalar<Unit::Frequency, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Frequency<NumericType>& left, const Frequency<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Frequency<NumericType>& frequency) {
  stream << frequency.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Frequency<NumericType> operator*(
    const NumericType number, const Frequency<NumericType>& frequency) {
  return frequency * number;
}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(const PhQ::Frequency<NumericType>& frequency)
  : Time<NumericType>(1.0 / frequency.Value()) {}

template <typename NumericType>
inline constexpr PhQ::Frequency<NumericType> Time<NumericType>::Frequency() const {
  return PhQ::Frequency<NumericType>{*this};
}

template <typename NumericType>
inline constexpr NumericType Time<NumericType>::operator*(
    const PhQ::Frequency<NumericType>& frequency) const noexcept {
  return this->value * frequency.Value();
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Frequency<NumericType>> {
  inline size_t operator()(const PhQ::Frequency<NumericType>& frequency) const {
    return hash<NumericType>()(frequency.Value());
  }
};

}  // namespace std

#endif  // PHQ_FREQUENCY_HPP
