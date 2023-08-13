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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_DYAD_HPP

#include <utility>

#include "../Value/Dyad.hpp"
#include "Dimensionless.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless dyadic tensor physical
// quantity. Such a physical quantity is composed only of a value where the
// value is a tensor of rank two and dimension three. The tensor may be
// non-symmetric. Such a physical quantity has no unit of measure and no
// dimension set.
class DimensionlessDyadQuantity : public DimensionlessQuantity {
public:
  inline constexpr const Value::Dyad& Value() const noexcept { return value_; }

  inline constexpr Value::Dyad& MutableValue() noexcept { return value_; }

  inline constexpr void SetValue(const Value::Dyad& value) noexcept {
    value_ = value;
  }

  std::string Print() const noexcept override { return value_.Print(); }

  std::string JSON() const noexcept override { return value_.JSON(); }

  std::string XML() const noexcept override { return value_.XML(); }

  std::string YAML() const noexcept override { return value_.YAML(); }

protected:
  constexpr DimensionlessDyadQuantity() noexcept
    : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessDyadQuantity(const Value::Dyad& value) noexcept
    : DimensionlessQuantity(), value_(value) {}

  constexpr DimensionlessDyadQuantity(Value::Dyad&& value) noexcept
    : DimensionlessQuantity(), value_(std::move(value)) {}

  ~DimensionlessDyadQuantity() noexcept = default;

  void operator=(const Value::Dyad& value) noexcept { value_ = value; }

  void operator=(Value::Dyad&& value) noexcept { value_ = std::move(value); }

  Value::Dyad value_;
};

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::DimensionlessDyadQuantity> {
  size_t operator()(const PhQ::DimensionlessDyadQuantity& quantity) const {
    return hash<PhQ::Value::Dyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_DYAD_HPP
