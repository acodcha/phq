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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declarations for class Time.
class Acceleration;
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
class AngularSpeed;
class Displacement;
class Energy;
class Frequency;
class Length;
class Mass;
class MassRate;
class Memory;
class MemoryRate;
class Power;
class SpecificEnergy;
class SpecificPower;
class Speed;
class Strain;
class StrainRate;
class Velocity;
class Volume;
class VolumeRate;

class Time : public DimensionalScalarQuantity<Unit::Time> {
public:
  constexpr Time() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  Time(const double value, const Unit::Time unit) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  constexpr Time(const PhQ::Frequency& frequency) noexcept;

  constexpr Time(const AccelerationMagnitude& acceleration_magnitude,
                 const Speed& speed) noexcept;

  constexpr Time(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const AngularSpeed& angular_speed) noexcept;

  constexpr Time(const AngularSpeed& angular_speed,
                 const Angle& angle) noexcept;

  constexpr Time(const MassRate& mass_rate, const Mass& mass) noexcept;

  constexpr Time(const MemoryRate& memory_rate, const Memory& memory) noexcept;

  constexpr Time(const Power& power, const Energy& energy) noexcept;

  constexpr Time(const SpecificPower& specific_power,
                 const SpecificEnergy& specific_energy) noexcept;

  constexpr Time(const Speed& speed, const Length& length) noexcept;

  constexpr Time(const VolumeRate& volume_rate, const Volume& volume) noexcept;

  inline PhQ::Frequency Frequency() const noexcept;

  inline Time operator+(const Time& time) const noexcept {
    return Time{value_ + time.value_};
  }

  inline Time operator-(const Time& time) const noexcept {
    return Time{value_ - time.value_};
  }

  inline Time operator*(const double number) const noexcept {
    return Time{value_ * number};
  }

  inline constexpr double operator*(
      const PhQ::Frequency& frequency) const noexcept;

  inline Mass operator*(const MassRate& mass_rate) const noexcept;

  inline Volume operator*(const VolumeRate& volume_rate) const noexcept;

  inline Energy operator*(const Power& power) const noexcept;

  inline SpecificEnergy operator*(
      const SpecificPower& specific_power) const noexcept;

  inline Strain operator*(const StrainRate& strain_rate) const noexcept;

  inline Displacement operator*(const Velocity& velocity) const noexcept;

  inline Velocity operator*(const Acceleration& acceleration) const noexcept;

  inline Time operator/(const double number) const noexcept {
    return Time{value_ / number};
  }

  inline constexpr void operator+=(const Time& time) noexcept {
    value_ += time.value_;
  }

  inline constexpr void operator-=(const Time& time) noexcept {
    value_ -= time.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Time(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value) {}
};

inline constexpr bool operator==(const Time& left, const Time& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Time& left, const Time& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Time& left, const Time& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Time& left, const Time& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Time& left, const Time& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Time& left, const Time& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Time& time) noexcept {
  stream << time.Print();
  return stream;
}

inline Time operator*(const double number, const Time& time) noexcept {
  return time * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Time> {
  size_t operator()(const PhQ::Time& time) const {
    return hash<double>()(time.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
