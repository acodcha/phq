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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_HPP

#include "Quantity/DimensionlessSymmetricDyad.hpp"
#include "StrainScalar.hpp"

namespace PhQ {

// Forward declarations for class Strain.
class DisplacementGradient;
class Time;
class Frequency;
class StrainRate;

class Strain : public DimensionlessSymmetricDyadQuantity {
public:
  constexpr Strain() noexcept : DimensionlessSymmetricDyadQuantity() {}

  explicit constexpr Strain(const Value::SymmetricDyad& value) noexcept
      : DimensionlessSymmetricDyadQuantity(value) {}

  constexpr Strain(const StrainRate& strain_rate, const Time& time) noexcept;

  constexpr Strain(const StrainRate& strain_rate,
                   const Frequency& frequency) noexcept;

  explicit constexpr Strain(
      const DisplacementGradient& displacement_gradient) noexcept;

  inline Strain operator+(const Strain& strain) const noexcept {
    return Strain{value_ + strain.value_};
  }

  inline Strain operator-(const Strain& strain) const noexcept {
    return Strain{value_ - strain.value_};
  }

  inline Strain operator*(const double number) const noexcept {
    return Strain{value_ * number};
  }

  inline StrainRate operator*(const Frequency& frequency) const noexcept;

  inline Strain operator/(const double number) const noexcept {
    return Strain{value_ / number};
  }

  inline StrainRate operator/(const Time& time) const noexcept;

  inline constexpr void operator+=(const Strain& strain) noexcept {
    value_ += strain.value_;
  }

  inline constexpr void operator-=(const Strain& strain) noexcept {
    value_ -= strain.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(const Strain& left,
                                 const Strain& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Strain& left,
                                 const Strain& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Strain& left,
                                const Strain& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Strain& left,
                                const Strain& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Strain& left,
                                 const Strain& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Strain& left,
                                 const Strain& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Strain& strain) noexcept {
  stream << strain.Print();
  return stream;
}

inline Strain operator*(const double number, const Strain& strain) noexcept {
  return strain * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Strain> {
  size_t operator()(const PhQ::Strain& strain) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_HPP
