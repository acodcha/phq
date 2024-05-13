// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_AREA_VECTOR_HPP
#define PHQ_AREA_VECTOR_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "Area.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Unit/Area.hpp"
#include "Vector.hpp"

namespace PhQ {

// Vector area. The vector analog to a scalar area. See also PhQ::Area.
template <typename Number = double>
class VectorArea : public DimensionalVector<Unit::Area, Number> {
public:
  // Default constructor. Constructs a vector area with an uninitialized value.
  VectorArea() = default;

  // Constructor. Constructs a vector area with a given value expressedin a given area unit.
  VectorArea(const Vector<Number>& value, const Unit::Area unit)
    : DimensionalVector<Unit::Area, Number>(value, unit) {}

  // Constructor. Constructs a vector area from a given area and direction.
  constexpr VectorArea(const Area<Number>& area, const Direction<Number>& direction)
    : VectorArea<Number>(area.Value() * direction.Value()) {}

  // Destructor. Destroys this vector area.
  ~VectorArea() noexcept = default;

  // Copy constructor. Constructs a vector area by copying another one.
  constexpr VectorArea(const VectorArea<Number>& other) = default;

  // Copy constructor. Constructs a vector area by copying another one.
  template <typename OtherNumber>
  explicit constexpr VectorArea(const VectorArea<OtherNumber>& other)
    : VectorArea(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a vector area by moving another one.
  constexpr VectorArea(VectorArea<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this vector area by copying another one.
  constexpr VectorArea<Number>& operator=(const VectorArea<Number>& other) = default;

  // Copy assignment operator. Assigns this vector area by copying another one.
  template <typename OtherNumber>
  constexpr VectorArea<Number>& operator=(const VectorArea<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this vector area by moving another one.
  constexpr VectorArea<Number>& operator=(VectorArea<Number>&& other) noexcept = default;

  // Statically creates a vector area of zero.
  static constexpr VectorArea<Number> Zero() {
    return VectorArea<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const Number x, const Number y, const Number z) {
    return VectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<Number>{x, y, z})};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const std::array<Number, 3>& x_y_z) {
    return VectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<Number>{x_y_z})};
  }

  // Statically creates a vector area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const Vector<Number>& value) {
    return VectorArea<Number>{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  // Returns the x Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> x() const noexcept {
    return Area<Number>{this->value.x()};
  }

  // Returns the y Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> y() const noexcept {
    return Area<Number>{this->value.y()};
  }

  // Returns the z Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> z() const noexcept {
    return Area<Number>{this->value.z()};
  }

  // Returns the magnitude of this vector area.
  [[nodiscard]] Area<Number> Magnitude() const {
    return Area<Number>{this->value.Magnitude()};
  }

  // Returns the direction of this vector area.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  // Returns the angle between this vector area and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const VectorArea<Number>& vector_area) const {
    return PhQ::Angle<Number>{*this, vector_area};
  }

  constexpr VectorArea<Number> operator+(const VectorArea<Number>& vector_area) const {
    return VectorArea<Number>{this->value + vector_area.value};
  }

  constexpr VectorArea<Number> operator-(const VectorArea<Number>& vector_area) const {
    return VectorArea<Number>{this->value - vector_area.value};
  }

  constexpr VectorArea<Number> operator*(const Number number) const {
    return VectorArea<Number>{this->value * number};
  }

  constexpr VectorArea<Number> operator/(const Number number) const {
    return VectorArea<Number>{this->value / number};
  }

  constexpr void operator+=(const VectorArea<Number>& vector_area) noexcept {
    this->value += vector_area.value;
  }

  constexpr void operator-=(const VectorArea<Number>& vector_area) noexcept {
    this->value -= vector_area.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a vector area with a given value expressed in the standard area unit.
  explicit constexpr VectorArea(const Vector<Number>& value)
    : DimensionalVector<Unit::Area, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const VectorArea<Number>& vector_area) {
  stream << vector_area.Print();
  return stream;
}

template <typename Number>
inline constexpr VectorArea<Number> operator*(
    const Number number, const VectorArea<Number>& vector_area) {
  return vector_area * number;
}

template <typename Number>
inline Direction<Number>::Direction(const VectorArea<Number>& vector_area)
  : Direction<Number>(vector_area.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const VectorArea<Number>& vector_area_1, const VectorArea<Number>& vector_area_2)
  : Angle<Number>(vector_area_1.Value(), vector_area_2.Value()) {}

template <typename Number>
inline constexpr VectorArea<Number> Direction<Number>::operator*(const Area<Number>& area) const {
  return VectorArea<Number>{area, *this};
}

template <typename Number>
inline constexpr VectorArea<Number> Area<Number>::operator*(
    const Direction<Number>& direction) const {
  return VectorArea<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::VectorArea<Number>> {
  inline size_t operator()(const PhQ::VectorArea<Number>& vector_area) const {
    return hash<PhQ::Vector<Number>>()(vector_area.Value());
  }
};

}  // namespace std

#endif  // PHQ_AREA_VECTOR_HPP
