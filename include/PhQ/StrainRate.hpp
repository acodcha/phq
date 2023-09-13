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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP

#include "DimensionalSymmetricDyadQuantity.hpp"
#include "Frequency.hpp"
#include "Strain.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declaration for class StrainRate.
class VelocityGradient;

// Strain rate dyadic tensor. Time rate of change of the strain dyadic tensor.
class StrainRate : public DimensionalSymmetricDyadQuantity<Unit::Frequency> {
public:
  constexpr StrainRate() noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Frequency>() {}

  StrainRate(const Value::SymmetricDyad& value, Unit::Frequency unit) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value, unit) {}

  constexpr StrainRate(const Strain& strain, const Time& time) noexcept
    : StrainRate(strain.Value() / time.Value()) {}

  constexpr StrainRate(
      const Strain& strain, const Frequency& frequency) noexcept
    : StrainRate(strain.Value() * frequency.Value()) {}

  explicit constexpr StrainRate(
      const VelocityGradient& velocity_gradient) noexcept;

  static constexpr StrainRate Zero() noexcept {
    return StrainRate{Value::SymmetricDyad::Zero()};
  }

  template <Unit::Frequency Unit>
  static constexpr StrainRate
  Create(const Value::SymmetricDyad& value) noexcept {
    return StrainRate{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            value)};
  }

  constexpr StrainRate operator+(const StrainRate& strain_rate) const noexcept {
    return {value_ + strain_rate.value_};
  }

  constexpr StrainRate operator-(const StrainRate& strain_rate) const noexcept {
    return {value_ - strain_rate.value_};
  }

  constexpr StrainRate operator*(const double number) const noexcept {
    return StrainRate{value_ * number};
  }

  constexpr Strain operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  constexpr StrainRate operator/(const double number) const noexcept {
    return StrainRate{value_ / number};
  }

  constexpr Strain operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr void operator+=(const StrainRate& strain_rate) noexcept {
    value_ += strain_rate.value_;
  }

  constexpr void operator-=(const StrainRate& strain_rate) noexcept {
    value_ -= strain_rate.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  constexpr StrainRate(const Value::SymmetricDyad& value) noexcept
    : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value) {}
};

inline constexpr bool operator==(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StrainRate& left, const StrainRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const StrainRate& strain_rate) noexcept {
  stream << strain_rate.Print();
  return stream;
}

inline constexpr StrainRate operator*(
    const double number, const StrainRate& strain_rate) noexcept {
  return strain_rate * number;
}

inline constexpr Strain::Strain(
    const StrainRate& strain_rate, const Time& time) noexcept
  : Strain(strain_rate.Value() * time.Value()) {}

inline constexpr Strain::Strain(
    const StrainRate& strain_rate, const Frequency& frequency) noexcept
  : Strain(strain_rate.Value() / frequency.Value()) {}

inline constexpr StrainRate Strain::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr StrainRate Strain::operator/(const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Strain Time::operator*(
    const StrainRate& strain_rate) const noexcept {
  return {strain_rate, *this};
}

inline constexpr StrainRate Frequency::operator*(
    const Strain& strain) const noexcept {
  return {strain, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StrainRate> {
  inline size_t operator()(const PhQ::StrainRate& strain_rate) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_RATE_HPP
