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

#ifndef PHQ_VECTOR_HPP
#define PHQ_VECTOR_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"

namespace PhQ {

// Forward declarations for class PhQ::Vector.
class Angle;
class Direction;

// Forward declaration for class PhQ::Vector.
template <typename>
class Dyad;

// Three-dimensional vector in Cartesian coordinates. Contains three components: x, y, and z.
template <typename Number = double>
class Vector {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Vector<Number> must be a floating-point number type.");

public:
  // Default constructor. Constructs a three-dimensional vector with uninitialized x, y, and z
  // Cartesian components.
  Vector() = default;

  // Constructor. Constructs a three-dimensional vector from the given x, y, and z Cartesian
  // components.
  constexpr Vector(const Number x, const Number y, const Number z) : x_y_z_({x, y, z}) {}

  // Constructor. Constructs a three-dimensional vector from a given array representing its x, y,
  // and z Cartesian components.
  explicit constexpr Vector(const std::array<Number, 3>& x_y_z) : x_y_z_(x_y_z) {}

  // Constructor. Constructs a three-dimensional vector given a magnitude and a direction.
  constexpr Vector(Number magnitude, const Direction& direction);

  // Destructor. Destroys this three-dimensional vector.
  ~Vector() noexcept = default;

  // Copy constructor. Constructs a three-dimensional vector by copying another one.
  constexpr Vector(const Vector& other) = default;

  // Copy constructor. Constructs a three-dimensional vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr Vector(const Vector<OtherNumber>& other)
    : x_y_z_({static_cast<Number>(other.x()), static_cast<Number>(other.y()),
              static_cast<Number>(other.z())}) {}

  // Move constructor. Constructs a three-dimensional vector by moving another one.
  constexpr Vector(Vector&& other) noexcept = default;

  // Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  constexpr Vector& operator=(const Vector& other) = default;

  // Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  template <typename OtherNumber>
  constexpr Vector& operator=(const Vector<OtherNumber>& other) {
    x_y_z_[0] = static_cast<Number>(other.x());
    x_y_z_[1] = static_cast<Number>(other.y());
    x_y_z_[2] = static_cast<Number>(other.z());
    return *this;
  }

  // Move assignment operator. Assigns this three-dimensional vector by moving another one.
  constexpr Vector& operator=(Vector&& other) noexcept = default;

  // Assignment operator. Assigns this three-dimensional vector by copying a given array
  // representing its x, y, and z Cartesian components.
  constexpr Vector& operator=(const std::array<Number, 3>& x_y_z) {
    x_y_z_ = x_y_z;
    return *this;
  }

  // Statically creates a three-dimensional vector with its x, y, and z Cartesian components
  // initialized to zero.
  static constexpr Vector Zero() {
    return Vector{
        std::array<Number, 3>{0.0, 0.0, 0.0}
    };
  }

  // Returns this three-dimensional vector's x, y, and z Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<Number, 3>& x_y_z() const noexcept {
    return x_y_z_;
  }

  // Returns this three-dimensional vector's x Cartesian component.
  [[nodiscard]] constexpr Number x() const noexcept {
    return x_y_z_[0];
  }

  // Returns this three-dimensional vector's y Cartesian component.
  [[nodiscard]] constexpr Number y() const noexcept {
    return x_y_z_[1];
  }

  // Returns this three-dimensional vector's z Cartesian component.
  [[nodiscard]] constexpr Number z() const noexcept {
    return x_y_z_[2];
  }

  // Returns this three-dimensional vector's x, y, and z Cartesian components as a mutable array.
  constexpr std::array<Number, 3>& Mutable_x_y_z() noexcept {
    return x_y_z_;
  }

  // Returns this three-dimensional vector's x Cartesian component as a mutable value.
  constexpr Number& Mutable_x() noexcept {
    return x_y_z_[0];
  }

  // Returns this three-dimensional vector's y Cartesian component as a mutable value.
  constexpr Number& Mutable_y() noexcept {
    return x_y_z_[1];
  }

  // Returns this three-dimensional vector's z Cartesian component as a mutable value.
  constexpr Number& Mutable_z() noexcept {
    return x_y_z_[2];
  }

  // Sets this three-dimensional vector's x, y, and z Cartesian components to the given values.
  constexpr void Set_x_y_z(const std::array<Number, 3>& x_y_z) noexcept {
    x_y_z_ = x_y_z;
  }

  // Sets this three-dimensional vector's x, y, and z Cartesian components to the given values.
  constexpr void Set_x_y_z(const Number x, const Number y, const Number z) noexcept {
    x_y_z_[0] = x;
    x_y_z_[1] = y;
    x_y_z_[2] = z;
  }

  // Sets this three-dimensional vector's x Cartesian component to a given value.
  constexpr void Set_x(const Number x) noexcept {
    x_y_z_[0] = x;
  }

  // Sets this three-dimensional vector's y Cartesian component to a given value.
  constexpr void Set_y(const Number y) noexcept {
    x_y_z_[1] = y;
  }

  // Sets this three-dimensional vector's z Cartesian component to a given value.
  constexpr void Set_z(const Number z) noexcept {
    x_y_z_[2] = z;
  }

  // Returns the square of the magnitude of this three-dimensional vector.
  [[nodiscard]] constexpr Number MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1] + x_y_z_[2] * x_y_z_[2];
  }

  // Returns the magnitude (also known as the L2 norm) of this three-dimensional vector.
  [[nodiscard]] Number Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  // Returns the direction of this three-dimensional vector.
  [[nodiscard]] PhQ::Direction Direction() const;

  // Returns the dot product (also known as the inner product or scalar product) of this
  // three-dimensional vector and another one.
  [[nodiscard]] constexpr Number Dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1]
           + x_y_z_[2] * vector.x_y_z_[2];
  }

  // Returns the dot product (also known as the inner product or scalar product) of this
  // three-dimensional vector and a given direction.
  [[nodiscard]] constexpr Number Dot(const PhQ::Direction& direction) const noexcept;

  // Returns the cross product (also known as the vector product) of this three-dimensional vector
  // and another one.
  [[nodiscard]] constexpr Vector Cross(const Vector& vector) const {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
            x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
            x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  // Returns the cross product (also known as the vector product) of this three-dimensional vector
  // and a given direction.
  [[nodiscard]] constexpr Vector Cross(const PhQ::Direction& direction) const;

  // Returns the dyadic tensor product (also known as the outer product) of this three-dimensional
  // vector and another one.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const Vector& vector) const;

  // Returns the dyadic tensor product (also known as the outer product) of this three-dimensional
  // vector and a given direction.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const PhQ::Direction& direction) const;

  // Returns the angle between this three-dimensional vector and another one.
  [[nodiscard]] PhQ::Angle Angle(const Vector& vector) const;

  // Returns the angle between this three-dimensional vector and a given direction.
  [[nodiscard]] PhQ::Angle Angle(const PhQ::Direction& direction) const;

  // Prints this three-dimensional vector as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", " + PhQ::Print(x_y_z_[2])
           + ")";
  }

  // Serializes this three-dimensional vector as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) + ",\"y\":" + PhQ::Print(x_y_z_[1])
           + ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  // Serializes this three-dimensional vector as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1]) + "</y><z>"
           + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  // Serializes this three-dimensional vector as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{x:" + PhQ::Print(x_y_z_[0]) + ",y:" + PhQ::Print(x_y_z_[1])
           + ",z:" + PhQ::Print(x_y_z_[2]) + "}";
  }

  constexpr void operator+=(const Vector& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr void operator-=(const Vector& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  template <typename OtherNumber>
  constexpr void operator*=(const OtherNumber number) noexcept {
    x_y_z_[0] *= static_cast<Number>(number);
    x_y_z_[1] *= static_cast<Number>(number);
    x_y_z_[2] *= static_cast<Number>(number);
  }

  template <typename OtherNumber>
  constexpr void operator/=(const OtherNumber number) noexcept {
    x_y_z_[0] /= static_cast<Number>(number);
    x_y_z_[1] /= static_cast<Number>(number);
    x_y_z_[2] /= static_cast<Number>(number);
  }

private:
  // Cartesian components of this three-dimensional vector.
  std::array<Number, 3> x_y_z_;
};

template <typename Number>
inline constexpr bool operator==(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  return left.x() == right.x() && left.y() == right.y() && left.z() == right.z();
}

template <typename Number>
inline constexpr bool operator!=(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  return left.x() != right.x() || left.y() != right.y() || left.z() != right.z();
}

template <typename Number>
inline constexpr bool operator<(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() < right.x();
  }
  if (left.y() != right.y()) {
    return left.y() < right.y();
  }
  return left.z() < right.z();
}

template <typename Number>
inline constexpr bool operator>(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() > right.x();
  }
  if (left.y() != right.y()) {
    return left.y() > right.y();
  }
  return left.z() > right.z();
}

template <typename Number>
inline constexpr bool operator<=(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(const Vector<Number>& left, const Vector<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline constexpr Vector<Number> operator+(const Vector<Number>& left, const Vector<Number>& right) {
  return {left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

template <typename Number>
inline constexpr Vector<Number> operator-(const Vector<Number>& left, const Vector<Number>& right) {
  return {left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator*(const Vector<Number>& vector, const OtherNumber number) {
  return {vector.x() * static_cast<Number>(number), vector.y() * static_cast<Number>(number),
          vector.z() * static_cast<Number>(number)};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator*(const OtherNumber number, const Vector<Number>& vector) {
  return {vector * number};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator/(const Vector<Number>& vector, const OtherNumber number) {
  return {vector.x() / static_cast<Number>(number), vector.y() / static_cast<Number>(number),
          vector.z() / static_cast<Number>(number)};
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Vector<Number>& vector) {
  stream << vector.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Vector<Number>> {
  inline size_t operator()(const PhQ::Vector<Number>& vector) const {
    size_t result{17};
    result = 31 * result + hash<Number>()(vector.x());
    result = 31 * result + hash<Number>()(vector.y());
    result = 31 * result + hash<Number>()(vector.z());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_VECTOR_HPP
