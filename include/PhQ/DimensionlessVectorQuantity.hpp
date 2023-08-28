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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_VECTOR_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_VECTOR_QUANTITY_HPP

#include "Dimensions.hpp"
#include "Value/Vector.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless vector physical
// quantity. Such a physical quantity is composed only of a value where the
// value is a vector of dimension three. Such a physical quantity has no unit of
// measure and no dimension set.
class DimensionlessVectorQuantity {
public:
  static constexpr const PhQ::Dimensions Dimensions() noexcept { return {}; }

  constexpr const Value::Vector& Value() const noexcept { return value_; }

  constexpr Value::Vector& MutableValue() noexcept { return value_; }

  constexpr void SetValue(const Value::Vector& value) noexcept {
    value_ = value;
  }

  std::string Print() const noexcept { return value_.Print(); }

  std::string Print(const Precision precision) const noexcept {
    return value_.Print(precision);
  }

  std::string JSON() const noexcept { return value_.JSON(); }

  std::string XML() const noexcept { return value_.XML(); }

  std::string YAML() const noexcept { return value_.YAML(); }

protected:
  constexpr DimensionlessVectorQuantity() noexcept : value_() {}

  constexpr DimensionlessVectorQuantity(const Value::Vector& value) noexcept
    : value_(value) {}

  constexpr DimensionlessVectorQuantity(Value::Vector&& value) noexcept
    : value_(std::move(value)) {}

  ~DimensionlessVectorQuantity() noexcept = default;

  void operator=(const Value::Vector& value) noexcept { value_ = value; }

  void operator=(Value::Vector&& value) noexcept { value_ = std::move(value); }

  Value::Vector value_;
};

inline std::ostream& operator<<(
    std::ostream& stream,
    const DimensionlessVectorQuantity& quantity) noexcept {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::DimensionlessVectorQuantity> {
  inline size_t operator()(
      const PhQ::DimensionlessVectorQuantity& quantity) const {
    return hash<PhQ::Value::Vector>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_VECTOR_QUANTITY_HPP
