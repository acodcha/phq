// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_YOUNG_MODULUS_HPP
#define PHQ_YOUNG_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Young's modulus of elasticity of a deformable solid material. A measure of a deformable solid
// material's elastic modulus.
class YoungModulus : public DimensionalScalar<Unit::Pressure> {
public:
  // Default constructor. Constructs a Young's modulus with an uninitialized value.
  YoungModulus() = default;

  // Constructor. Constructs a Young's modulus with a given value expressed in a given pressure
  // unit.
  YoungModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this Young's modulus.
  ~YoungModulus() noexcept = default;

  // Copy constructor. Constructs a Young's modulus by copying another one.
  constexpr YoungModulus(const YoungModulus& other) = default;

  // Move constructor. Constructs a Young's modulus by moving another one.
  constexpr YoungModulus(YoungModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this Young's modulus by copying another one.
  constexpr YoungModulus& operator=(const YoungModulus& other) = default;

  // Move assignment operator. Assigns this Young's modulus by moving another one.
  constexpr YoungModulus& operator=(YoungModulus&& other) noexcept = default;

  // Statically creates a Young's modulus of zero.
  static constexpr YoungModulus Zero() {
    return YoungModulus{0.0};
  }

  // Statically creates a Young's modulus with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr YoungModulus Create(const double value) {
    return YoungModulus{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr YoungModulus operator+(const YoungModulus& young_modulus) const {
    return YoungModulus{value_ + young_modulus.value_};
  }

  constexpr YoungModulus operator-(const YoungModulus& young_modulus) const {
    return YoungModulus{value_ - young_modulus.value_};
  }

  constexpr YoungModulus operator*(const double number) const {
    return YoungModulus{value_ * number};
  }

  constexpr YoungModulus operator/(const double number) const {
    return YoungModulus{value_ / number};
  }

  constexpr double operator/(const YoungModulus& young_modulus) const noexcept {
    return value_ / young_modulus.value_;
  }

  constexpr void operator+=(const YoungModulus& young_modulus) noexcept {
    value_ += young_modulus.value_;
  }

  constexpr void operator-=(const YoungModulus& young_modulus) noexcept {
    value_ -= young_modulus.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a Young's modulus with a given value expressed in the standard pressure
  // unit.
  explicit constexpr YoungModulus(const double value) : DimensionalScalar<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const YoungModulus& left, const YoungModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const YoungModulus& young_modulus) {
  stream << young_modulus.Print();
  return stream;
}

inline constexpr YoungModulus operator*(const double number, const YoungModulus& young_modulus) {
  return young_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::YoungModulus> {
  inline size_t operator()(const PhQ::YoungModulus& young_modulus) const {
    return hash<double>()(young_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_YOUNG_MODULUS_HPP
