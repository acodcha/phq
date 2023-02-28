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

// Forward declarations.
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
class AngularSpeed;
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
class Time;
class Volume;
class VolumeRate;

class Duration : public DimensionalScalarQuantity<Unit::Time> {
public:
  constexpr Duration() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  Duration(const double value, const Unit::Time unit) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  constexpr Duration(const PhQ::Frequency& frequency) noexcept;

  constexpr Duration(const AccelerationMagnitude& acceleration_magnitude,
                     const Speed& speed) noexcept;

  constexpr Duration(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const AngularSpeed& angular_speed) noexcept;

  constexpr Duration(const AngularSpeed& angular_speed,
                     const Angle& angle) noexcept;

  constexpr Duration(const MassRate& mass_rate, const Mass& mass) noexcept;

  constexpr Duration(const MemoryRate& memory_rate,
                     const Memory& memory) noexcept;

  constexpr Duration(const Power& power, const Energy& energy) noexcept;

  constexpr Duration(const SpecificPower& specific_power,
                     const SpecificEnergy& specific_energy) noexcept;

  constexpr Duration(const Speed& speed, const Length& length) noexcept;

  constexpr Duration(const VolumeRate& volume_rate,
                     const Volume& volume) noexcept;

  constexpr PhQ::Frequency Frequency() const noexcept;

  inline Time operator+(const Time& time) const noexcept;

  inline Duration operator+(const Duration& duration) const noexcept {
    return Duration{value_ + duration.value_};
  }

  inline Time operator-(const Time& time) const noexcept;

  inline Duration operator-(const Duration& duration) const noexcept {
    return Duration{value_ - duration.value_};
  }

  inline Duration operator*(const double number) const noexcept {
    return Duration{value_ * number};
  }

  inline constexpr double operator*(
      const PhQ::Frequency& frequency) const noexcept;

  inline Mass operator*(const MassRate& mass_rate) const noexcept;

  inline Volume operator*(const VolumeRate& volume_rate) const noexcept;

  inline Energy operator*(const Power& power) const noexcept;

  inline SpecificEnergy operator*(
      const SpecificPower& specific_power) const noexcept;

  inline Strain operator*(const StrainRate& strain_rate) const noexcept;

  inline Duration operator/(const double number) const noexcept {
    return Duration{value_ / number};
  }

  inline constexpr void operator+=(const Duration& duration) noexcept {
    value_ += duration.value_;
  }

  inline constexpr void operator-=(const Duration& duration) noexcept {
    value_ -= duration.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Duration(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Time;
};

inline constexpr bool operator==(const Duration& left,
                                 const Duration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Duration& left,
                                 const Duration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Duration& left,
                                const Duration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Duration& left,
                                const Duration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Duration& left,
                                 const Duration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Duration& left,
                                 const Duration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Duration& duration) noexcept {
  stream << duration.Print();
  return stream;
}

inline Duration operator*(const double number,
                          const Duration& duration) noexcept {
  return duration * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Duration> {
  size_t operator()(const PhQ::Duration& duration) const {
    return hash<double>()(duration.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
