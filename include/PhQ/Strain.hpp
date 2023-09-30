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

#include "DimensionlessSymmetricDyadQuantity.hpp"
#include "StrainScalar.hpp"

namespace PhQ {

// Forward declarations for class Strain.
class DisplacementGradient;
class Time;
class Frequency;
class StrainRate;

// Strain symmetric dyadic tensor.
class Strain : public DimensionlessSymmetricDyadQuantity {
public:
  // Default constructor. Constructs a strain tensor with an uninitialized
  // value.
  Strain() = default;

  // Constructor. Constructs a strain tensor with a given value.
  explicit constexpr Strain(const Value::SymmetricDyad& value)
    : DimensionlessSymmetricDyadQuantity(value) {}

  // Constructor. Constructs a strain tensor from a given strain rate tensor and
  // time using the definition of the strain rate tensor.
  constexpr Strain(const StrainRate& strain_rate, const Time& time);

  // Constructor. Constructs a strain tensor from a given strain rate tensor and
  // frequency using the definition of the strain rate tensor.
  constexpr Strain(const StrainRate& strain_rate, const Frequency& frequency);

  // Constructor. Constructs a strain tensor from a given displacement gradient
  // using the definition of the strain tensor.
  explicit constexpr Strain(const DisplacementGradient& displacement_gradient);

  // Destructor. Destroys this strain tensor.
  ~Strain() noexcept = default;

  // Copy constructor. Constructs a strain tensor by copying another one.
  constexpr Strain(const Strain& other) = default;

  // Move constructor. Constructs a strain tensor by moving another one.
  constexpr Strain(Strain&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain tensor by copying another
  // one.
  constexpr Strain& operator=(const Strain& other) = default;

  // Move assignment operator. Assigns this strain tensor by moving another one.
  constexpr Strain& operator=(Strain&& other) noexcept = default;

  // Statically creates a strain tensor of zero.
  static constexpr Strain Zero() {
    return Strain{Value::SymmetricDyad::Zero()};
  }

  constexpr Strain operator+(const Strain& strain) const {
    return Strain{value_ + strain.value_};
  }

  constexpr Strain operator-(const Strain& strain) const {
    return Strain{value_ - strain.value_};
  }

  constexpr Strain operator*(const double number) const {
    return Strain{value_ * number};
  }

  constexpr StrainRate operator*(const Frequency& frequency) const;

  constexpr Strain operator/(const double number) const {
    return Strain{value_ / number};
  }

  constexpr StrainRate operator/(const Time& time) const;

  constexpr void operator+=(const Strain& strain) noexcept {
    value_ += strain.value_;
  }

  constexpr void operator-=(const Strain& strain) noexcept {
    value_ -= strain.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Strain& left, const Strain& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Strain& strain) {
  stream << strain.Print();
  return stream;
}

inline constexpr Strain operator*(const double number, const Strain& strain) {
  return strain * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Strain> {
  inline size_t operator()(const PhQ::Strain& strain) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_HPP
