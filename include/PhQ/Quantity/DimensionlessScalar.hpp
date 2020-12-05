// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Dimensionless.hpp"

namespace PhQ {

// Forward declarations.
class DimensionlessDyadicQuantity;
class DimensionlessSymmetricDyadicQuantity;
template <typename Unit> class DimensionalDyadicQuantity;
template <typename Unit> class DimensionalScalarQuantity;
template <typename Unit> class DimensionalSymmetricDyadicQuantity;
template <typename Unit> class DimensionalVectorQuantity;

class DimensionlessScalarQuantity : public DimensionlessQuantity {

public:

  constexpr double value() const noexcept {
    return value_;
  }

  std::string print() const noexcept {
    return number_to_string(value_);
  }

  std::string json() const noexcept {
    return number_to_string(value_);
  }

  std::string xml() const noexcept {
    return number_to_string(value_);
  }

  constexpr bool operator==(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ == scalar.value_;
  }

  constexpr bool operator!=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ != scalar.value_;
  }

  constexpr bool operator<(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ < scalar.value_;
  }

  constexpr bool operator<=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ <= scalar.value_;
  }

  constexpr bool operator>(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ > scalar.value_;
  }

  constexpr bool operator>=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ >= scalar.value_;
  }

  constexpr DimensionlessScalarQuantity operator+(double real) const noexcept {
    return {value_ + real};
  }

  constexpr DimensionlessScalarQuantity operator+(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ + scalar.value_};
  }

  constexpr void operator+=(double real) noexcept {
    value_ += real;
  }

  constexpr void operator+=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ += scalar.value_;
  }

  constexpr DimensionlessScalarQuantity operator-(double real) const noexcept {
    return {value_ - real};
  }

  constexpr DimensionlessScalarQuantity operator-(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ - scalar.value_};
  }

  constexpr void operator-=(double real) noexcept {
    value_ -= real;
  }

  constexpr void operator-=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ -= scalar.value_;
  }

  constexpr DimensionlessScalarQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr double operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ * scalar.value_;
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator*(const DimensionlessSymmetricDyadicQuantity& symmetric_dyadic) const noexcept;

  constexpr DimensionlessDyadicQuantity operator*(const DimensionlessDyadicQuantity& dyadic) const noexcept;

  template <typename Unit> constexpr DimensionalScalarQuantity<Unit> operator*(const DimensionalScalarQuantity<Unit>& dimensional_scalar) noexcept;

  template <typename Unit> constexpr DimensionalVectorQuantity<Unit> operator*(const DimensionalVectorQuantity<Unit>& dimensional_vector) noexcept;

  template <typename Unit> constexpr DimensionalSymmetricDyadicQuantity<Unit> operator*(const DimensionalSymmetricDyadicQuantity<Unit>& dimensional_symmetric_dyadic) noexcept;

  template <typename Unit> constexpr DimensionalDyadicQuantity<Unit> operator*(const DimensionalDyadicQuantity<Unit>& dimensional_dyadic) noexcept;

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value_;
  }

  constexpr DimensionlessScalarQuantity operator/(double real) const noexcept {
    return {value_ / real};
  }

  constexpr double operator/(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ / scalar.value_;
  }

  constexpr void operator/=(double real) noexcept {
    value_ /= real;
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ /= scalar.value_;
  }

protected:

  constexpr DimensionlessScalarQuantity() noexcept : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessScalarQuantity(double value) noexcept : DimensionlessQuantity(), value_(value) {}

  double value_;

};

template <> constexpr bool sort(const DimensionlessScalarQuantity& scalar_1, const DimensionlessScalarQuantity& scalar_2) noexcept {
  return scalar_1.value() < scalar_2.value();
}

} // namespace PhQ

namespace std {

double cbrt(const PhQ::DimensionlessScalarQuantity& scalar) {
  return cbrt(scalar.value());
};

double exp(const PhQ::DimensionlessScalarQuantity& scalar) {
  return exp(scalar.value());
};

double log(const PhQ::DimensionlessScalarQuantity& scalar) {
  return log(scalar.value());
};

double log10(const PhQ::DimensionlessScalarQuantity& scalar) {
  return log10(scalar.value());
};

double pow(const PhQ::DimensionlessScalarQuantity& scalar, int_least64_t exponent) {
  return pow(scalar.value(), exponent);
};

double pow(const PhQ::DimensionlessScalarQuantity& scalar, double exponent) {
  return pow(scalar.value(), exponent);
};

double sqrt(const PhQ::DimensionlessScalarQuantity& scalar) {
  return sqrt(scalar.value());
};

} // namespace std

namespace std {

template <> struct hash<PhQ::DimensionlessScalarQuantity> {
  size_t operator()(const PhQ::DimensionlessScalarQuantity& quantity) const {
    return hash<double>()(quantity.value());
  }
};

} // namespace std
