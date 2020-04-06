// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Dimensionless.hpp"

namespace PhQ {

class DimensionlessScalarQuantity : public DimensionlessQuantity {

public:

  DimensionlessScalarQuantity() noexcept : DimensionlessQuantity() {}

  constexpr DimensionlessScalarQuantity(double value) noexcept : DimensionlessQuantity(), value_(value) {}

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

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  DimensionlessScalarQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr double operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value_ != 0.0) {
      return value_ / scalar.value_;
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  constexpr void operator/=(double real) {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

protected:

  double value_;

};

template <> constexpr bool sort(const DimensionlessScalarQuantity& scalar1, const DimensionlessScalarQuantity& scalar2) noexcept {
  return scalar1.value() < scalar2.value();
}

} // namespace PhQ

constexpr PhQ::DimensionlessScalarQuantity operator*(double real, const PhQ::DimensionlessScalarQuantity& scalar) noexcept {
  return {scalar * real};
}

constexpr double operator/(double real, const PhQ::DimensionlessScalarQuantity& scalar) {
  if (scalar.value() != 0.0) {
    return real / scalar.value();
  } else {
    throw std::runtime_error{"Division of " + PhQ::number_to_string(real) + " by " + scalar.print() + "."};
  }
}

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
