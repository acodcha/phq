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
template <typename Number = double>
class Frequency : public DimensionalScalar<Unit::Frequency, Number> {
public:
  /// \brief Default constructor. Constructs a frequency with an uninitialized value.
  Frequency() = default;

  /// \brief Constructor. Constructs a frequency with a given value expressed in a given frequency
  /// unit.
  Frequency(const Number value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, Number>(value, unit) {}

  /// \brief Constructor. Constructs a frequency from a given time period using the definition of
  /// frequency.
  constexpr explicit Frequency(const Time<Number>& time) : Frequency<Number>(1.0 / time.Value()) {}

  /// \brief Constructor. Constructs a frequency from a given scalar acceleration and speed using
  /// the definitions of acceleration and frequency.
  constexpr Frequency(
      const ScalarAcceleration<Number>& scalar_acceleration, const Speed<Number>& speed);

  /// \brief Constructor. Constructs a frequency from a given scalar angular acceleration and
  /// angular speed using the definitions of angular acceleration and frequency.
  constexpr Frequency(const ScalarAngularAcceleration<Number>& scalar_angular_acceleration,
                      const AngularSpeed<Number>& angular_speed);

  /// \brief Constructor. Constructs a frequency from a given angular speed and angle using the
  /// definitions of angular speed and frequency.
  constexpr Frequency(const AngularSpeed<Number>& angular_speed, const Angle<Number>& angle);

  /// \brief Constructor. Constructs a frequency from a given mass rate and mass using the
  /// definitions of mass rate and frequency.
  constexpr Frequency(const MassRate<Number>& mass_rate, const Mass<Number>& mass);

  /// \brief Constructor. Constructs a frequency from a given memory rate and memory using the
  /// definitions of memory rate and frequency.
  constexpr Frequency(const MemoryRate<Number>& memory_rate, const Memory<Number>& memory);

  /// \brief Constructor. Constructs a frequency from a given power and energy using the definitions
  /// of power and frequency.
  constexpr Frequency(const Power<Number>& power, const Energy<Number>& energy);

  /// \brief Constructor. Constructs a frequency from a given specific power and specific energy
  /// using the definitions of specific power and frequency.
  constexpr Frequency(
      const SpecificPower<Number>& specific_power, const SpecificEnergy<Number>& specific_energy);

  /// \brief Constructor. Constructs a frequency from a given speed and length using the definitions
  /// of speed and frequency.
  constexpr Frequency(const Speed<Number>& speed, const Length<Number>& length);

  /// \brief Constructor. Constructs a frequency from a given volume rate and volume using the
  /// definitions of volume rate and frequency.
  constexpr Frequency(const VolumeRate<Number>& volume_rate, const Volume<Number>& volume);

  /// \brief Destructor. Destroys this frequency.
  ~Frequency() noexcept = default;

  /// \brief Copy constructor. Constructs a frequency by copying another one.
  constexpr Frequency(const Frequency<Number>& other) = default;

  /// \brief Copy constructor. Constructs a frequency by copying another one.
  template <typename OtherNumber>
  explicit constexpr Frequency(const Frequency<OtherNumber>& other)
    : Frequency(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a frequency by moving another one.
  constexpr Frequency(Frequency<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this frequency by copying another one.
  constexpr Frequency<Number>& operator=(const Frequency<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this frequency by copying another one.
  template <typename OtherNumber>
  constexpr Frequency<Number>& operator=(const Frequency<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this frequency by moving another one.
  constexpr Frequency<Number>& operator=(Frequency<Number>&& other) noexcept = default;

  /// \brief Statically creates a frequency of zero.
  static constexpr Frequency<Number> Zero() {
    return Frequency<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a frequency with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr Frequency<Number> Create(const Number value) {
    return Frequency<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Time period that corresponds to this frequency.
  [[nodiscard]] constexpr Time<Number> Period() const {
    return Time<Number>{*this};
  }

  constexpr Frequency<Number> operator+(const Frequency<Number>& frequency) const {
    return Frequency<Number>{this->value + frequency.value};
  }

  constexpr Frequency<Number> operator-(const Frequency<Number>& frequency) const {
    return Frequency<Number>{this->value - frequency.value};
  }

  constexpr Frequency<Number> operator*(const Number number) const {
    return Frequency<Number>{this->value * number};
  }

  constexpr Frequency<Number> operator/(const Number number) const {
    return Frequency<Number>{this->value / number};
  }

  constexpr Number operator*(const Time<Number>& time) const noexcept {
    return this->value * time.Value();
  }

  constexpr Speed<Number> operator*(const Length<Number>& length) const;

  constexpr AngularSpeed<Number> operator*(const Angle<Number>& angle) const;

  constexpr PlanarVelocity<Number> operator*(const PlanarDisplacement<Number>& displacement) const;

  constexpr Velocity<Number> operator*(const Displacement<Number>& displacement) const;

  constexpr PlanarAcceleration<Number> operator*(const PlanarVelocity<Number>& displacement) const;

  constexpr Acceleration<Number> operator*(const Velocity<Number>& displacement) const;

  constexpr VelocityGradient<Number> operator*(
      const DisplacementGradient<Number>& displacement_gradient) const;

  constexpr ScalarVelocityGradient<Number> operator*(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const;

  constexpr MemoryRate<Number> operator*(const Memory<Number>& memory) const;

  constexpr ScalarAcceleration<Number> operator*(const Speed<Number>& speed) const;

  constexpr ScalarAngularAcceleration<Number> operator*(
      const AngularSpeed<Number>& angular_speed) const;

  constexpr MassRate<Number> operator*(const Mass<Number>& mass) const;

  constexpr VolumeRate<Number> operator*(const Volume<Number>& volume) const;

  constexpr Power<Number> operator*(const Energy<Number>& energy) const;

  constexpr SpecificPower<Number> operator*(const SpecificEnergy<Number>& specific_energy) const;

  constexpr StrainRate<Number> operator*(const Strain<Number>& strain) const;

  constexpr ScalarStrainRate<Number> operator*(const ScalarStrain<Number>& scalar_strain) const;

  constexpr Number operator/(const Frequency<Number>& frequency) const noexcept {
    return this->value / frequency.value;
  }

  constexpr void operator+=(const Frequency<Number>& frequency) noexcept {
    this->value += frequency.value;
  }

  constexpr void operator-=(const Frequency<Number>& frequency) noexcept {
    this->value -= frequency.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a frequency with a given value expressed in the standard
  /// frequency unit.
  explicit constexpr Frequency(const Number value)
    : DimensionalScalar<Unit::Frequency, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Frequency<Number>& left, const Frequency<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Frequency<Number>& frequency) {
  stream << frequency.Print();
  return stream;
}

template <typename Number>
inline constexpr Frequency<Number> operator*(
    const Number number, const Frequency<Number>& frequency) {
  return frequency * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(const PhQ::Frequency<Number>& frequency)
  : Time<Number>(1.0 / frequency.Value()) {}

template <typename Number>
inline constexpr PhQ::Frequency<Number> Time<Number>::Frequency() const {
  return PhQ::Frequency<Number>{*this};
}

template <typename Number>
inline constexpr Number Time<Number>::operator*(
    const PhQ::Frequency<Number>& frequency) const noexcept {
  return this->value * frequency.Value();
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Frequency<Number>> {
  inline size_t operator()(const PhQ::Frequency<Number>& frequency) const {
    return hash<Number>()(frequency.Value());
  }
};

}  // namespace std

#endif  // PHQ_FREQUENCY_HPP
