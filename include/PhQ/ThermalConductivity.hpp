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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP

#include "Quantity/DimensionalSymmetricDyad.hpp"
#include "ThermalConductivityScalar.hpp"

namespace PhQ {

class ThermalConductivity
  : public DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity> {
public:
  constexpr ThermalConductivity() noexcept
    : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>() {}

  ThermalConductivity(const Value::SymmetricDyad& value,
                      const Unit::ThermalConductivity unit) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>(value, unit) {
  }

  constexpr ThermalConductivity(
      const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept
    : ThermalConductivity({thermal_conductivity_scalar.Value(), 0.0, 0.0,
                           thermal_conductivity_scalar.Value(), 0.0,
                           thermal_conductivity_scalar.Value()}) {}

  template<Unit::ThermalConductivity Unit> static constexpr ThermalConductivity
  Create(const Value::SymmetricDyad& value) noexcept {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit,
                          StandardUnit<Unit::ThermalConductivity>>(value)};
  }

  inline constexpr ThermalConductivity operator+(
      const ThermalConductivity& thermal_conductivity) const noexcept {
    return ThermalConductivity{value_ + thermal_conductivity.value_};
  }

  inline constexpr ThermalConductivity operator-(
      const ThermalConductivity& thermal_conductivity) const noexcept {
    return ThermalConductivity{value_ - thermal_conductivity.value_};
  }

  inline constexpr ThermalConductivity operator*(
      const double number) const noexcept {
    return ThermalConductivity{value_ * number};
  }

  inline constexpr ThermalConductivity operator/(
      const double number) const noexcept {
    return ThermalConductivity{value_ / number};
  }

  inline constexpr void operator+=(
      const ThermalConductivity& thermal_conductivity) noexcept {
    value_ += thermal_conductivity.value_;
  }

  inline constexpr void operator-=(
      const ThermalConductivity& thermal_conductivity) noexcept {
    value_ -= thermal_conductivity.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr ThermalConductivity(
      const Value::SymmetricDyad& value) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>(value) {}
};

inline constexpr bool operator==(const ThermalConductivity& left,
                                 const ThermalConductivity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ThermalConductivity& left,
                                 const ThermalConductivity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ThermalConductivity& left,
                                const ThermalConductivity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ThermalConductivity& left,
                                const ThermalConductivity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ThermalConductivity& left,
                                 const ThermalConductivity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ThermalConductivity& left,
                                 const ThermalConductivity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const ThermalConductivity& thermal_conductivity) noexcept {
  stream << thermal_conductivity.Print();
  return stream;
}

inline constexpr ThermalConductivity operator*(
    const double number,
    const ThermalConductivity& thermal_conductivity) noexcept {
  return thermal_conductivity * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::ThermalConductivity> {
  size_t operator()(
      const PhQ::ThermalConductivity& thermal_conductivity) const {
    return hash<PhQ::Value::SymmetricDyad>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP
