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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP

#include "DimensionlessQuantity.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless scalar physical
// quantity. Such a physical quantity is composed only of a value where the
// value is a scalar number. Such a physical quantity has no unit of measure and
// no dimension set.
class DimensionlessScalarQuantity : public DimensionlessQuantity {
public:
  inline constexpr double Value() const noexcept { return value_; }

  inline constexpr double& MutableValue() noexcept { return value_; }

  inline constexpr void SetValue(const double value) noexcept {
    value_ = value;
  }

  std::string Print() const noexcept override { return PhQ::Print(value_); }

  std::string Print(const Precision precision) const noexcept override {
    return PhQ::Print(value_, precision);
  }

  std::string JSON() const noexcept override { return PhQ::Print(value_); }

  std::string XML() const noexcept override { return PhQ::Print(value_); }

  std::string YAML() const noexcept override { return PhQ::Print(value_); }

protected:
  constexpr DimensionlessScalarQuantity() noexcept
    : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessScalarQuantity(const double value) noexcept
    : DimensionlessQuantity(), value_(value) {}

  ~DimensionlessScalarQuantity() noexcept = default;

  void operator=(const double value) noexcept { value_ = value; }

  double value_;
};

}  // namespace PhQ

namespace std {

constexpr double abs(const PhQ::DimensionlessScalarQuantity& quantity) {
  return abs(quantity.Value());
}

double cbrt(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return cbrt(quantity.Value());
};

double exp(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return exp(quantity.Value());
};

double log(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log(quantity.Value());
};

double log2(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log2(quantity.Value());
};

double log10(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return log10(quantity.Value());
};

constexpr double pow(const PhQ::DimensionlessScalarQuantity& quantity,
                     const int_least64_t exponent) {
  return pow(quantity.Value(), exponent);
};

double pow(const PhQ::DimensionlessScalarQuantity& quantity,
           const double exponent) noexcept {
  return pow(quantity.Value(), exponent);
};

double sqrt(const PhQ::DimensionlessScalarQuantity& quantity) noexcept {
  return sqrt(quantity.Value());
};

template<> struct hash<PhQ::DimensionlessScalarQuantity> {
  inline size_t operator()(
      const PhQ::DimensionlessScalarQuantity& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONLESS_SCALAR_QUANTITY_HPP
