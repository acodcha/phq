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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_FREQUENCY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_FREQUENCY_HPP

#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declarations for class Frequency.
class Acceleration;
class Displacement;
class Length;
class Velocity;

// Frequency.
class Frequency : public DimensionalScalarQuantity<Unit::Frequency> {
public:
  constexpr Frequency() : DimensionalScalarQuantity<Unit::Frequency>() {}

  Frequency(const double value, const Unit::Frequency unit)
    : DimensionalScalarQuantity<Unit::Frequency>(value, unit) {}

  constexpr Frequency(const Time& time) : Frequency(1.0 / time.Value()) {}

  constexpr Frequency(
      const AccelerationMagnitude& acceleration_magnitude, const Speed& speed);

  constexpr Frequency(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const AngularSpeed& angular_speed);

  constexpr Frequency(const AngularSpeed& angular_speed, const Angle& angle);

  constexpr Frequency(const MassRate& mass_rate, const Mass& mass);

  constexpr Frequency(const MemoryRate& memory_rate, const Memory& memory);

  constexpr Frequency(const Power& power, const Energy& energy);

  constexpr Frequency(const SpecificPower& specific_power,
                      const SpecificEnergy& specific_energy);

  constexpr Frequency(const Speed& speed, const Length& length);

  constexpr Frequency(const VolumeRate& volume_rate, const Volume& volume);

  static constexpr Frequency Zero() {
    return Frequency{0.0};
  }

  template <Unit::Frequency Unit>
  static constexpr Frequency Create(const double value) {
    return Frequency{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            value)};
  }

  constexpr Time Period() const {
    return {*this};
  }

  constexpr Frequency operator+(const Frequency& frequency) const {
    return Frequency{value_ + frequency.value_};
  }

  constexpr Frequency operator-(const Frequency& frequency) const {
    return Frequency{value_ - frequency.value_};
  }

  constexpr Frequency operator*(const double number) const {
    return Frequency{value_ * number};
  }

  constexpr Frequency operator/(const double number) const {
    return Frequency{value_ / number};
  }

  constexpr double operator*(const Time& time) const noexcept {
    return value_ * time.Value();
  }

  constexpr Speed operator*(const Length& length) const;

  constexpr AngularSpeed operator*(const Angle& angle) const;

  constexpr Velocity operator*(const Displacement& displacement) const;

  constexpr MemoryRate operator*(const Memory& memory) const;

  constexpr AccelerationMagnitude operator*(const Speed& speed) const;

  constexpr AngularAccelerationMagnitude operator*(
      const AngularSpeed& angular_speed) const;

  constexpr MassRate operator*(const Mass& mass) const;

  constexpr VolumeRate operator*(const Volume& volume) const;

  constexpr Power operator*(const Energy& energy) const;

  constexpr SpecificPower operator*(
      const SpecificEnergy& specific_energy) const;

  constexpr StrainRate operator*(const Strain& strain) const;

  constexpr double operator/(const Frequency& frequency) const noexcept {
    return value_ / frequency.value_;
  }

  constexpr void operator+=(const Frequency& frequency) noexcept {
    value_ += frequency.value_;
  }

  constexpr void operator-=(const Frequency& frequency) noexcept {
    value_ -= frequency.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Frequency(const double value)
    : DimensionalScalarQuantity<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Frequency& left, const Frequency& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Frequency& frequency) {
  stream << frequency.Print();
  return stream;
}

inline constexpr Frequency operator*(
    const double number, const Frequency& frequency) {
  return frequency * number;
}

inline constexpr Time::Time(const PhQ::Frequency& frequency)
  : Time(1.0 / frequency.Value()) {}

inline constexpr PhQ::Frequency Time::Frequency() const {
  return {*this};
}

inline constexpr double Time::operator*(
    const PhQ::Frequency& frequency) const noexcept {
  return value_ * frequency.Value();
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FREQUENCY_HPP
