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

#include "DimensionalSymmetricDyadQuantity.hpp"
#include "ThermalConductivityScalar.hpp"

namespace PhQ {

// Thermal conductivity symmetric dyadic tensor.
class ThermalConductivity
  : public DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity> {
public:
  // Default constructor. Constructs a thermal conductivity tensor with an
  // uninitialized value.
  ThermalConductivity() = default;

  // Constructor. Constructs a thermal conductivity tensor with a given value
  // expressed in a given thermal conductivity unit.
  ThermalConductivity(
      const Value::SymmetricDyad& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>(value, unit) {
  }

  // Constructor. Constructs a thermal conductivity tensor from a given thermal
  // conductivity scalar.
  constexpr ThermalConductivity(
      const ThermalConductivityScalar& thermal_conductivity_scalar)
    : ThermalConductivity({thermal_conductivity_scalar.Value(), 0.0, 0.0,
                           thermal_conductivity_scalar.Value(), 0.0,
                           thermal_conductivity_scalar.Value()}) {}

  // Destructor. Destroys this thermal conductivity tensor.
  ~ThermalConductivity() noexcept = default;

  // Copy constructor. Constructs a thermal conductivity tensor by copying
  // another one.
  constexpr ThermalConductivity(const ThermalConductivity& other) = default;

  // Move constructor. Constructs a thermal conductivity tensor by moving
  // another one.
  constexpr ThermalConductivity(ThermalConductivity&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal conductivity tensor by
  // copying another one.
  constexpr ThermalConductivity& operator=(
      const ThermalConductivity& other) = default;

  // Move assignment operator. Assigns this thermal conductivity tensor by
  // moving another one.
  constexpr ThermalConductivity& operator=(
      ThermalConductivity&& other) noexcept = default;

  // Statically creates a thermal conductivity tensor of zero.
  static constexpr ThermalConductivity Zero() {
    return ThermalConductivity{Value::SymmetricDyad::Zero()};
  }

  // Statically creates a thermal conductivity tensor with a given value
  // expressed in a given thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity
  Create(const Value::SymmetricDyad& value) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit,
                          Standard<Unit::ThermalConductivity>>(value)};
  }

  constexpr ThermalConductivity operator+(
      const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value_ + thermal_conductivity.value_};
  }

  constexpr ThermalConductivity operator-(
      const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value_ - thermal_conductivity.value_};
  }

  constexpr ThermalConductivity operator*(const double number) const {
    return ThermalConductivity{value_ * number};
  }

  constexpr ThermalConductivity operator/(const double number) const {
    return ThermalConductivity{value_ / number};
  }

  constexpr void operator+=(
      const ThermalConductivity& thermal_conductivity) noexcept {
    value_ += thermal_conductivity.value_;
  }

  constexpr void operator-=(
      const ThermalConductivity& thermal_conductivity) noexcept {
    value_ -= thermal_conductivity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a thermal conductivity tensor with a given value
  // expressed in the standard thermal conductivity unit.
  explicit constexpr ThermalConductivity(const Value::SymmetricDyad& value)
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
    std::ostream& stream, const ThermalConductivity& thermal_conductivity) {
  stream << thermal_conductivity.Print();
  return stream;
}

inline constexpr ThermalConductivity operator*(
    const double number, const ThermalConductivity& thermal_conductivity) {
  return thermal_conductivity * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ThermalConductivity> {
  inline size_t operator()(
      const PhQ::ThermalConductivity& thermal_conductivity) const {
    return hash<PhQ::Value::SymmetricDyad>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP
