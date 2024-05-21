// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
template <typename Number>
class Angle;

// Forward declaration for class PhQ::Vector.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::Vector.
template <typename>
class Dyad;

/// \brief Three-dimensional vector in Cartesian coordinates. Contains three components: x, y, and
/// z.
template <typename Number = double>
class Vector {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Vector<Number> must be a floating-point number type.");

public:
  /// \brief Default constructor. Constructs a three-dimensional vector with uninitialized x, y, and
  /// z Cartesian components.
  Vector() = default;

  /// \brief Constructor. Constructs a three-dimensional vector from the given x, y, and z Cartesian
  /// components.
  constexpr Vector(const Number x, const Number y, const Number z) : x_y_z_({x, y, z}) {}

  /// \brief Constructor. Constructs a three-dimensional vector from a given array representing its
  /// x, y, and z Cartesian components.
  explicit constexpr Vector(const std::array<Number, 3>& x_y_z) : x_y_z_(x_y_z) {}

  /// \brief Constructor. Constructs a three-dimensional vector given a magnitude and a direction.
  constexpr Vector(Number magnitude, const Direction<Number>& direction);

  /// \brief Destructor. Destroys this three-dimensional vector.
  ~Vector() noexcept = default;

  /// \brief Copy constructor. Constructs a three-dimensional vector by copying another one.
  constexpr Vector(const Vector<Number>& other) = default;

  /// \brief Copy constructor. Constructs a three-dimensional vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr Vector(const Vector<OtherNumber>& other)
    : x_y_z_({static_cast<Number>(other.x()), static_cast<Number>(other.y()),
              static_cast<Number>(other.z())}) {}

  /// \brief Move constructor. Constructs a three-dimensional vector by moving another one.
  constexpr Vector(Vector<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  constexpr Vector<Number>& operator=(const Vector<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  template <typename OtherNumber>
  constexpr Vector<Number>& operator=(const Vector<OtherNumber>& other) {
    x_y_z_[0] = static_cast<Number>(other.x());
    x_y_z_[1] = static_cast<Number>(other.y());
    x_y_z_[2] = static_cast<Number>(other.z());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this three-dimensional vector by moving another one.
  constexpr Vector<Number>& operator=(Vector<Number>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this three-dimensional vector by copying a given array
  /// representing its x, y, and z Cartesian components.
  constexpr Vector<Number>& operator=(const std::array<Number, 3>& x_y_z) {
    x_y_z_ = x_y_z;
    return *this;
  }

  /// \brief Statically creates a three-dimensional vector with its x, y, and z Cartesian components
  /// initialized to zero.
  static constexpr Vector<Number> Zero() {
    return Vector<Number>{
        std::array<Number, 3>{
                              static_cast<Number>(0), static_cast<Number>(0), static_cast<Number>(0)}
    };
  }

  /// \brief Returns this three-dimensional vector's x, y, and z Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<Number, 3>& x_y_z() const noexcept {
    return x_y_z_;
  }

  /// \brief Returns this three-dimensional vector's x Cartesian component.
  [[nodiscard]] constexpr Number x() const noexcept {
    return x_y_z_[0];
  }

  /// \brief Returns this three-dimensional vector's y Cartesian component.
  [[nodiscard]] constexpr Number y() const noexcept {
    return x_y_z_[1];
  }

  /// \brief Returns this three-dimensional vector's z Cartesian component.
  [[nodiscard]] constexpr Number z() const noexcept {
    return x_y_z_[2];
  }

  /// \brief Returns this three-dimensional vector's x, y, and z Cartesian components as a mutable
  /// array.
  constexpr std::array<Number, 3>& Mutable_x_y_z() noexcept {
    return x_y_z_;
  }

  /// \brief Returns this three-dimensional vector's x Cartesian component as a mutable value.
  constexpr Number& Mutable_x() noexcept {
    return x_y_z_[0];
  }

  /// \brief Returns this three-dimensional vector's y Cartesian component as a mutable value.
  constexpr Number& Mutable_y() noexcept {
    return x_y_z_[1];
  }

  /// \brief Returns this three-dimensional vector's z Cartesian component as a mutable value.
  constexpr Number& Mutable_z() noexcept {
    return x_y_z_[2];
  }

  /// \brief Sets this three-dimensional vector's x, y, and z Cartesian components to the given
  /// values.
  constexpr void Set_x_y_z(const std::array<Number, 3>& x_y_z) noexcept {
    x_y_z_ = x_y_z;
  }

  /// \brief Sets this three-dimensional vector's x, y, and z Cartesian components to the given
  /// values.
  constexpr void Set_x_y_z(const Number x, const Number y, const Number z) noexcept {
    x_y_z_[0] = x;
    x_y_z_[1] = y;
    x_y_z_[2] = z;
  }

  /// \brief Sets this three-dimensional vector's x Cartesian component to a given value.
  constexpr void Set_x(const Number x) noexcept {
    x_y_z_[0] = x;
  }

  /// \brief Sets this three-dimensional vector's y Cartesian component to a given value.
  constexpr void Set_y(const Number y) noexcept {
    x_y_z_[1] = y;
  }

  /// \brief Sets this three-dimensional vector's z Cartesian component to a given value.
  constexpr void Set_z(const Number z) noexcept {
    x_y_z_[2] = z;
  }

  /// \brief Returns the square of the magnitude of this three-dimensional vector.
  [[nodiscard]] constexpr Number MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1] + x_y_z_[2] * x_y_z_[2];
  }

  /// \brief Returns the magnitude (also known as the L2 norm) of this three-dimensional vector.
  [[nodiscard]] Number Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  /// \brief Returns the direction of this three-dimensional vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const;

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// three-dimensional vector and another one.
  [[nodiscard]] constexpr Number Dot(const Vector<Number>& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1]
           + x_y_z_[2] * vector.x_y_z_[2];
  }

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// three-dimensional vector and a given direction.
  [[nodiscard]] constexpr Number Dot(const PhQ::Direction<Number>& direction) const noexcept;

  /// \brief Returns the cross product (also known as the vector product) of this three-dimensional
  /// vector and another one.
  [[nodiscard]] constexpr Vector<Number> Cross(const Vector<Number>& vector) const {
    return Vector<Number>{x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
                          x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
                          x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  /// \brief Returns the cross product (also known as the vector product) of this three-dimensional
  /// vector and a given direction.
  [[nodiscard]] constexpr Vector<Number> Cross(const PhQ::Direction<Number>& direction) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// three-dimensional vector and another one.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const Vector<Number>& vector) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// three-dimensional vector and a given direction.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(const PhQ::Direction<Number>& direction) const;

  /// \brief Returns the angle between this three-dimensional vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Vector<Number>& vector) const;

  /// \brief Returns the angle between this three-dimensional vector and a given direction.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PhQ::Direction<Number>& direction) const;

  /// \brief Prints this three-dimensional vector as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", " + PhQ::Print(x_y_z_[2])
           + ")";
  }

  /// \brief Serializes this three-dimensional vector as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) + ",\"y\":" + PhQ::Print(x_y_z_[1])
           + ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  /// \brief Serializes this three-dimensional vector as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1]) + "</y><z>"
           + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  /// \brief Serializes this three-dimensional vector as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{x:" + PhQ::Print(x_y_z_[0]) + ",y:" + PhQ::Print(x_y_z_[1])
           + ",z:" + PhQ::Print(x_y_z_[2]) + "}";
  }

  constexpr void operator+=(const Vector<Number>& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr void operator-=(const Vector<Number>& vector) noexcept {
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
  /// \brief Cartesian components of this three-dimensional vector.
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
  return Vector<Number>{left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

template <typename Number>
inline constexpr Vector<Number> operator-(const Vector<Number>& left, const Vector<Number>& right) {
  return Vector<Number>{left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator*(const Vector<Number>& vector, const OtherNumber number) {
  return Vector<Number>{
      vector.x() * static_cast<Number>(number), vector.y() * static_cast<Number>(number),
      vector.z() * static_cast<Number>(number)};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator*(const OtherNumber number, const Vector<Number>& vector) {
  return Vector<Number>{vector * number};
}

template <typename Number, typename OtherNumber>
inline constexpr Vector<Number> operator/(const Vector<Number>& vector, const OtherNumber number) {
  return Vector<Number>{
      vector.x() / static_cast<Number>(number), vector.y() / static_cast<Number>(number),
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
    result = static_cast<size_t>(31) * result + hash<Number>()(vector.x());
    result = static_cast<size_t>(31) * result + hash<Number>()(vector.y());
    result = static_cast<size_t>(31) * result + hash<Number>()(vector.z());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_VECTOR_HPP
