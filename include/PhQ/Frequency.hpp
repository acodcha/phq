// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_FREQUENCY_HPP
#define PHQ_FREQUENCY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Frequency.
class Frequency : public DimensionalScalar<Unit::Frequency> {
public:
  // Default constructor. Constructs a frequency with an uninitialized value.
  Frequency() = default;

  // Constructor. Constructs a frequency with a given value expressed in a given frequency unit.
  Frequency(const double value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a frequency from a given time period using the definition of frequency.
  constexpr explicit Frequency(const Time& time) : Frequency(1.0 / time.Value()) {}

  // Constructor. Constructs a frequency from a given scalar acceleration and speed using the
  // definitions of acceleration and frequency.
  constexpr Frequency(const ScalarAcceleration& scalar_acceleration, const Speed& speed);

  // Constructor. Constructs a frequency from a given scalar angular acceleration and angular speed
  // using the definitions of angular acceleration and frequency.
  constexpr Frequency(const ScalarAngularAcceleration& scalar_angular_acceleration,
                      const AngularSpeed& angular_speed);

  // Constructor. Constructs a frequency from a given angular speed and angle using the definitions
  // of angular speed and frequency.
  constexpr Frequency(const AngularSpeed& angular_speed, const Angle& angle);

  // Constructor. Constructs a frequency from a given mass rate and mass using the definitions of
  // mass rate and frequency.
  constexpr Frequency(const MassRate& mass_rate, const Mass& mass);

  // Constructor. Constructs a frequency from a given memory rate and memory using the definitions
  // of memory rate and frequency.
  constexpr Frequency(const MemoryRate& memory_rate, const Memory& memory);

  // Constructor. Constructs a frequency from a given power and energy using the definitions of
  // power and frequency.
  constexpr Frequency(const Power& power, const Energy& energy);

  // Constructor. Constructs a frequency from a given specific power and specific energy using the
  // definitions of specific power and frequency.
  constexpr Frequency(const SpecificPower& specific_power, const SpecificEnergy& specific_energy);

  // Constructor. Constructs a frequency from a given speed and length using the definitions of
  // speed and frequency.
  constexpr Frequency(const Speed& speed, const Length& length);

  // Constructor. Constructs a frequency from a given volume rate and volume using the definitions
  // of volume rate and frequency.
  constexpr Frequency(const VolumeRate& volume_rate, const Volume& volume);

  // Destructor. Destroys this frequency.
  ~Frequency() noexcept = default;

  // Copy constructor. Constructs a frequency by copying another one.
  constexpr Frequency(const Frequency& other) = default;

  // Move constructor. Constructs a frequency by moving another one.
  constexpr Frequency(Frequency&& other) noexcept = default;

  // Copy assignment operator. Assigns this frequency by copying another one.
  constexpr Frequency& operator=(const Frequency& other) = default;

  // Move assignment operator. Assigns this frequency by moving another one.
  constexpr Frequency& operator=(Frequency&& other) noexcept = default;

  // Statically creates a frequency of zero.
  static constexpr Frequency Zero() {
    return Frequency{0.0};
  }

  // Statically creates a frequency with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr Frequency Create(const double value) {
    return Frequency{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  // Time period that corresponds to this frequency.
  [[nodiscard]] constexpr Time Period() const {
    return Time{*this};
  }

  constexpr Frequency operator+(const Frequency& frequency) const {
    return Frequency{value + frequency.value};
  }

  constexpr Frequency operator-(const Frequency& frequency) const {
    return Frequency{value - frequency.value};
  }

  constexpr Frequency operator*(const double number) const {
    return Frequency{value * number};
  }

  constexpr Frequency operator/(const double number) const {
    return Frequency{value / number};
  }

  constexpr double operator*(const Time& time) const noexcept {
    return value * time.Value();
  }

  constexpr Speed operator*(const Length& length) const;

  constexpr AngularSpeed operator*(const Angle& angle) const;

  constexpr Velocity operator*(const Displacement& displacement) const;

  constexpr VelocityGradient operator*(const DisplacementGradient& displacement_gradient) const;

  constexpr ScalarVelocityGradient operator*(
      const ScalarDisplacementGradient& scalar_displacement_gradient) const;

  constexpr MemoryRate operator*(const Memory& memory) const;

  constexpr ScalarAcceleration operator*(const Speed& speed) const;

  constexpr ScalarAngularAcceleration operator*(const AngularSpeed& angular_speed) const;

  constexpr MassRate operator*(const Mass& mass) const;

  constexpr VolumeRate operator*(const Volume& volume) const;

  constexpr Power operator*(const Energy& energy) const;

  constexpr SpecificPower operator*(const SpecificEnergy& specific_energy) const;

  constexpr StrainRate operator*(const Strain& strain) const;

  constexpr ScalarStrainRate operator*(const ScalarStrain& scalar_strain) const;

  constexpr double operator/(const Frequency& frequency) const noexcept {
    return value / frequency.value;
  }

  constexpr void operator+=(const Frequency& frequency) noexcept {
    value += frequency.value;
  }

  constexpr void operator-=(const Frequency& frequency) noexcept {
    value -= frequency.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a frequency with a given value expressed in the standard frequency
  // unit.
  explicit constexpr Frequency(const double value) : DimensionalScalar<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Frequency& left, const Frequency& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Frequency& frequency) {
  stream << frequency.Print();
  return stream;
}

inline constexpr Frequency operator*(const double number, const Frequency& frequency) {
  return frequency * number;
}

inline constexpr Time::Time(const PhQ::Frequency& frequency) : Time(1.0 / frequency.Value()) {}

inline constexpr PhQ::Frequency Time::Frequency() const {
  return PhQ::Frequency{*this};
}

inline constexpr double Time::operator*(const PhQ::Frequency& frequency) const noexcept {
  return value * frequency.Value();
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Frequency> {
  inline size_t operator()(const PhQ::Frequency& frequency) const {
    return hash<double>()(frequency.Value());
  }
};

}  // namespace std

#endif  // PHQ_FREQUENCY_HPP
