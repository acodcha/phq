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
class VectorArea : public DimensionalVector<Unit::Area> {
public:
  // Default constructor. Constructs a vector area with an uninitialized value.
  VectorArea() = default;

  // Constructor. Constructs a vector area with a given value expressedin a given area unit.
  VectorArea(const Vector<double>& value, const Unit::Area unit)
    : DimensionalVector<Unit::Area>(value, unit) {}

  // Constructor. Constructs a vector area from a given area and direction.
  constexpr VectorArea(const Area& area, const Direction& direction)
    : VectorArea(area.Value() * direction.Value()) {}

  // Destructor. Destroys this vector area.
  ~VectorArea() noexcept = default;

  // Copy constructor. Constructs a vector area by copying another one.
  constexpr VectorArea(const VectorArea& other) = default;

  // Move constructor. Constructs a vector area by moving another one.
  constexpr VectorArea(VectorArea&& other) noexcept = default;

  // Copy assignment operator. Assigns this vector area by copying another one.
  constexpr VectorArea& operator=(const VectorArea& other) = default;

  // Move assignment operator. Assigns this vector area by moving another one.
  constexpr VectorArea& operator=(VectorArea&& other) noexcept = default;

  // Statically creates a vector area of zero.
  static constexpr VectorArea Zero() {
    return VectorArea{Vector<double>::Zero()};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea Create(const double x, const double y, const double z) {
    return VectorArea{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<double>{x, y, z})};
  }

  // Statically creates a vector area from the given x, y, and z Cartesian components expressed in a
  // given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea Create(const std::array<double, 3>& x_y_z) {
    return VectorArea{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<double>{x_y_z})};
  }

  // Statically creates a vector area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea Create(const Vector<double>& value) {
    return VectorArea{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  // Returns the x Cartesian component of this vector area.
  [[nodiscard]] constexpr Area x() const noexcept {
    return Area{value.x()};
  }

  // Returns the y Cartesian component of this vector area.
  [[nodiscard]] constexpr Area y() const noexcept {
    return Area{value.y()};
  }

  // Returns the z Cartesian component of this vector area.
  [[nodiscard]] constexpr Area z() const noexcept {
    return Area{value.z()};
  }

  // Returns the magnitude of this vector area.
  [[nodiscard]] Area Magnitude() const {
    return Area{value.Magnitude()};
  }

  // Returns the direction of this vector area.
  [[nodiscard]] PhQ::Direction Direction() const {
    return value.Direction();
  }

  // Returns the angle between this vector area and another one.
  [[nodiscard]] PhQ::Angle Angle(const VectorArea& vector_area) const {
    return {*this, vector_area};
  }

  constexpr VectorArea operator+(const VectorArea& vector_area) const {
    return VectorArea{value + vector_area.value};
  }

  constexpr VectorArea operator-(const VectorArea& vector_area) const {
    return VectorArea{value - vector_area.value};
  }

  constexpr VectorArea operator*(const double number) const {
    return VectorArea{value * number};
  }

  constexpr VectorArea operator/(const double number) const {
    return VectorArea{value / number};
  }

  constexpr void operator+=(const VectorArea& vector_area) noexcept {
    value += vector_area.value;
  }

  constexpr void operator-=(const VectorArea& vector_area) noexcept {
    value -= vector_area.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a vector area with a given value expressed in the standard area unit.
  explicit constexpr VectorArea(const Vector<double>& value)
    : DimensionalVector<Unit::Area>(value) {}
};

inline constexpr bool operator==(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const VectorArea& left, const VectorArea& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const VectorArea& vector_area) {
  stream << vector_area.Print();
  return stream;
}

inline constexpr VectorArea operator*(const double number, const VectorArea& vector_area) {
  return vector_area * number;
}

inline Direction::Direction(const VectorArea& vector_area) : Direction(vector_area.Value()) {}

inline Angle::Angle(const VectorArea& vector_area_1, const VectorArea& vector_area_2)
  : Angle(vector_area_1.Value(), vector_area_2.Value()) {}

inline constexpr VectorArea Direction::operator*(const Area& area) const {
  return {area, *this};
}

inline constexpr VectorArea Area::operator*(const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::VectorArea> {
  inline size_t operator()(const PhQ::VectorArea& vector_area) const {
    return hash<PhQ::Vector<double>>()(vector_area.Value());
  }
};

}  // namespace std

#endif  // PHQ_AREA_VECTOR_HPP
