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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_VECTOR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_VECTOR_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "Area.hpp"
#include "DimensionalVectorQuantity.hpp"
#include "Direction.hpp"
#include "Unit/Area.hpp"
#include "Value/Vector.hpp"

namespace PhQ {

// Vector area. The vector analog to a scalar area.
class AreaVector : public DimensionalVectorQuantity<Unit::Area> {
public:
  // Default constructor. Constructs a vector area with an uninitialized value.
  AreaVector() = default;

  // Constructor. Constructs a vector area with a given value expressedin a given area unit.
  AreaVector(const Value::Vector& value, const Unit::Area unit)
    : DimensionalVectorQuantity<Unit::Area>(value, unit) {}

  // Constructor. Constructs a vector area from a given area and direction.
  constexpr AreaVector(const Area& area, const Direction& direction)
    : AreaVector(area.Value() * direction.Value()) {}

  // Destructor. Destroys this vector area.
  ~AreaVector() noexcept = default;

  // Copy constructor. Constructs a vector area by copying another one.
  constexpr AreaVector(const AreaVector& other) = default;

  // Move constructor. Constructs a vector area by moving another one.
  constexpr AreaVector(AreaVector&& other) noexcept = default;

  // Copy assignment operator. Assigns this vector area by copying another one.
  constexpr AreaVector& operator=(const AreaVector& other) = default;

  // Move assignment operator. Assigns this vector area by moving another one.
  constexpr AreaVector& operator=(AreaVector&& other) noexcept = default;

  // Statically creates a vector area of zero.
  static constexpr AreaVector Zero() {
    return AreaVector{Value::Vector::Zero()};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr AreaVector Create(const double x, const double y, const double z) {
    return AreaVector{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Value::Vector{x, y, z})};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr AreaVector Create(const std::array<double, 3>& x_y_z) {
    return AreaVector{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Value::Vector{x_y_z})};
  }

  // Statically creates a vector area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr AreaVector Create(const Value::Vector& value) {
    return AreaVector{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  // Returns the magnitude of this vector area.
  [[nodiscard]] Area Magnitude() const {
    return Area{*this};
  }

  // Returns the angle between this vector area and another one.
  [[nodiscard]] PhQ::Angle Angle(const AreaVector& area_vector) const {
    return {*this, area_vector};
  }

  constexpr AreaVector operator+(const AreaVector& area_vector) const {
    return AreaVector{value_ + area_vector.value_};
  }

  constexpr AreaVector operator-(const AreaVector& area_vector) const {
    return AreaVector{value_ - area_vector.value_};
  }

  constexpr AreaVector operator*(const double number) const {
    return AreaVector{value_ * number};
  }

  constexpr AreaVector operator/(const double number) const {
    return AreaVector{value_ / number};
  }

  constexpr void operator+=(const AreaVector& area_vector) noexcept {
    value_ += area_vector.value_;
  }

  constexpr void operator-=(const AreaVector& area_vector) noexcept {
    value_ -= area_vector.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a vector area with a given value expressed in the standard area unit.
  explicit constexpr AreaVector(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::Area>(value) {}
};

inline constexpr bool operator==(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const AreaVector& left, const AreaVector& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const AreaVector& area_vector) {
  stream << area_vector.Print();
  return stream;
}

inline constexpr AreaVector operator*(const double number, const AreaVector& area_vector) {
  return area_vector * number;
}

inline Direction::Direction(const AreaVector& area_vector) : Direction(area_vector.Value()) {}

inline Angle::Angle(const AreaVector& area_vector_1, const AreaVector& area_vector_2)
  : Angle(area_vector_1.Value(), area_vector_2.Value()) {}

inline Area::Area(const AreaVector& area_vector) : Area(area_vector.Value().Magnitude()) {}

inline constexpr AreaVector Direction::operator*(const Area& area) const {
  return {area, *this};
}

inline constexpr AreaVector Area::operator*(const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AreaVector> {
  inline size_t operator()(const PhQ::AreaVector& area_vector) const {
    return hash<PhQ::Value::Vector>()(area_vector.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_VECTOR_HPP
