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

class DimensionlessDyadQuantity : public DimensionlessQuantity {
public:
  constexpr const Value::Dyad& Value() const noexcept { return value_; }

  std::string Print() const noexcept override { return value_.Print(); }

  std::string Json() const noexcept override { return value_.Json(); }

  std::string Xml() const noexcept override { return value_.Xml(); }

  std::string Yaml() const noexcept override { return value_.Yaml(); }

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

template <>
struct hash<PhQ::DimensionlessDyadQuantity> {
  size_t operator()(const PhQ::DimensionlessDyadQuantity& quantity) const {
    return hash<PhQ::Value::Dyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_DYAD_HPP
