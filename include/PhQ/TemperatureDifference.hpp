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

#include "Quantity/DimensionalScalar.hpp"
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
  constexpr TemperatureDifference() noexcept
    : DimensionalScalarQuantity<Unit::TemperatureDifference>() {}

  TemperatureDifference(
      const double value, const Unit::TemperatureDifference unit) noexcept
    : DimensionalScalarQuantity<Unit::TemperatureDifference>(value, unit) {}

  constexpr TemperatureDifference(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude,
      const Length& length) noexcept;

  static constexpr TemperatureDifference Zero() noexcept {
    return TemperatureDifference{0.0};
  }

  template<Unit::TemperatureDifference Unit>
  static constexpr TemperatureDifference Create(const double value) noexcept {
    return TemperatureDifference{
        StaticConvertCopy<Unit::TemperatureDifference, Unit,
                          StandardUnit<Unit::TemperatureDifference>>(value)};
  }

  inline constexpr Temperature operator+(
      const Temperature& temperature) const noexcept;

  inline constexpr TemperatureDifference operator+(
      const TemperatureDifference& temperature_difference) const noexcept {
    return TemperatureDifference{value_ + temperature_difference.value_};
  }

  inline constexpr Temperature operator-(
      const Temperature& temperature) const noexcept;

  inline constexpr TemperatureDifference operator-(
      const TemperatureDifference& temperature_difference) const noexcept {
    return TemperatureDifference{value_ - temperature_difference.value_};
  }

  inline constexpr TemperatureDifference operator*(
      const double number) const noexcept {
    return TemperatureDifference{value_ * number};
  }

  inline constexpr StrainScalar operator*(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) const noexcept;

  inline constexpr double operator*(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) const noexcept;

  inline constexpr TemperatureDifference operator/(
      const double number) const noexcept {
    return TemperatureDifference{value_ / number};
  }

  inline constexpr TemperatureGradientMagnitude operator/(
      const Length& length) const noexcept;

  inline constexpr void operator+=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value_;
  }

  inline constexpr void operator-=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TemperatureDifference(const double value) noexcept
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
    std::ostream& stream,
    const TemperatureDifference& temperature_difference) noexcept {
  stream << temperature_difference.Print();
  return stream;
}

inline constexpr TemperatureDifference operator*(
    const double number,
    const TemperatureDifference& temperature_difference) noexcept {
  return temperature_difference * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::TemperatureDifference> {
  size_t operator()(
      const PhQ::TemperatureDifference& temperature_difference) const {
    return hash<double>()(temperature_difference.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_DIFFERENCE_HPP
