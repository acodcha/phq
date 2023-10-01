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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_DIFFERENCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_DIFFERENCE_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/TemperatureDifference.hpp"

namespace PhQ {

// Forward declarations for class TemperatureDifference.
class Length;
class LinearThermalExpansionCoefficient;
class StrainScalar;
class Temperature;
class TemperatureGradientMagnitude;
class VolumetricThermalExpansionCoefficient;

// Temperature difference. Not to be confused with temperature. For example, a
// temperature difference of 20 kelvin is very different from a temperature of
// 20 kelvin.
class TemperatureDifference
  : public DimensionalScalarQuantity<Unit::TemperatureDifference> {
public:
  // Default constructor. Constructs a temperature difference with an
  // uninitialized value.
  TemperatureDifference() = default;

  // Constructor. Constructs a temperature difference with a given value
  // expressed in a given temperature unit.
  TemperatureDifference(
      const double value, const Unit::TemperatureDifference unit)
    : DimensionalScalarQuantity<Unit::TemperatureDifference>(value, unit) {}

  // Constructor. Constructs a temperature difference from a given temperature
  // gradient magnitude and length using the definition of temperature gradient.
  constexpr TemperatureDifference(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude,
      const Length& length);

  // Destructor. Destroys this temperature difference.
  ~TemperatureDifference() noexcept = default;

  // Copy constructor. Constructs a temperature difference by copying another
  // one.
  constexpr TemperatureDifference(const TemperatureDifference& other) = default;

  // Move constructor. Constructs a temperature difference by moving another
  // one.
  constexpr TemperatureDifference(
      TemperatureDifference&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature difference by copying
  // another one.
  constexpr TemperatureDifference& operator=(
      const TemperatureDifference& other) = default;

  // Move assignment operator. Assigns this temperature difference by moving
  // another one.
  constexpr TemperatureDifference& operator=(
      TemperatureDifference&& other) noexcept = default;

  // Statically creates a temperature difference of absolute zero.
  static constexpr TemperatureDifference Zero() {
    return TemperatureDifference{0.0};
  }

  // Statically creates a temperature difference with a given value expressed in
  // a given temperature unit.
  template <Unit::TemperatureDifference Unit>
  static constexpr TemperatureDifference Create(const double value) {
    return TemperatureDifference{
        StaticConvertCopy<Unit::TemperatureDifference, Unit,
                          Standard<Unit::TemperatureDifference>>(value)};
  }

  constexpr Temperature operator+(const Temperature& temperature) const;

  constexpr TemperatureDifference operator+(
      const TemperatureDifference& temperature_difference) const {
    return TemperatureDifference{value_ + temperature_difference.value_};
  }

  constexpr Temperature operator-(const Temperature& temperature) const;

  constexpr TemperatureDifference operator-(
      const TemperatureDifference& temperature_difference) const {
    return TemperatureDifference{value_ - temperature_difference.value_};
  }

  constexpr TemperatureDifference operator*(const double number) const {
    return TemperatureDifference{value_ * number};
  }

  constexpr StrainScalar operator*(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) const;

  constexpr double operator*(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) const;

  constexpr TemperatureDifference operator/(const double number) const {
    return TemperatureDifference{value_ / number};
  }

  constexpr TemperatureGradientMagnitude operator/(const Length& length) const;

  constexpr double operator/(
      const TemperatureDifference& temperature_difference) const noexcept {
    return value_ / temperature_difference.value_;
  }

  constexpr void operator+=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value_;
  }

  constexpr void operator-=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a temperature difference with a given value
  // expressed in the standard temperature difference unit.
  explicit constexpr TemperatureDifference(const double value)
    : DimensionalScalarQuantity<Unit::TemperatureDifference>(value) {}

  friend class Temperature;
};

inline constexpr bool operator==(const TemperatureDifference& left,
                                 const TemperatureDifference& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const TemperatureDifference& left,
                                 const TemperatureDifference& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const TemperatureDifference& left,
                                const TemperatureDifference& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const TemperatureDifference& left,
                                const TemperatureDifference& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const TemperatureDifference& left,
                                 const TemperatureDifference& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const TemperatureDifference& left,
                                 const TemperatureDifference& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureDifference& temperature_difference) {
  stream << temperature_difference.Print();
  return stream;
}

inline constexpr TemperatureDifference operator*(
    const double number, const TemperatureDifference& temperature_difference) {
  return temperature_difference * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureDifference> {
  inline size_t operator()(
      const PhQ::TemperatureDifference& temperature_difference) const {
    return hash<double>()(temperature_difference.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_DIFFERENCE_HPP
