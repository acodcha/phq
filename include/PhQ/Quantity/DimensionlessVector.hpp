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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_VECTOR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_VECTOR_HPP

#include <utility>

#include "../Value/Vector.hpp"
#include "Dimensionless.hpp"

namespace PhQ {

class DimensionlessVectorQuantity : public DimensionlessQuantity {
public:
  constexpr const Value::Vector& Value() const noexcept { return value_; }

  std::string Print() const noexcept override { return value_.Print(); }

  std::string Json() const noexcept override { return value_.Json(); }

  std::string Xml() const noexcept override { return value_.Xml(); }

  std::string Yaml() const noexcept override { return value_.Yaml(); }

protected:
  constexpr DimensionlessVectorQuantity() noexcept
      : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessVectorQuantity(const Value::Vector& value) noexcept
      : DimensionlessQuantity(), value_(value) {}

  constexpr DimensionlessVectorQuantity(Value::Vector&& value) noexcept
      : DimensionlessQuantity(), value_(std::move(value)) {}

  ~DimensionlessVectorQuantity() noexcept = default;

  void operator=(const Value::Vector& value) noexcept { value_ = value; }

  void operator=(Value::Vector&& value) noexcept { value_ = std::move(value); }

  Value::Vector value_;
};

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DimensionlessVectorQuantity> {
  size_t operator()(const PhQ::DimensionlessVectorQuantity& quantity) const {
    return hash<PhQ::Value::Vector>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONLESS_VECTOR_HPP
