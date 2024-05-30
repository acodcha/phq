// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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
#include "PlanarVector.hpp"

namespace PhQ {

// Forward declarations for class PhQ::Vector.
template <typename NumericType>
class Angle;

// Forward declaration for class PhQ::Vector.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::Vector.
template <typename>
class Dyad;

/// \brief Three-dimensional Euclidean vector. Contains three components in Cartesian coordinates:
/// x, y, and z. For a two-dimensional Euclidean vector in the XY plane, see PhQ::PlanarVector. For
/// a three-dimensional Euclidean dyadic tensor, see PhQ::Dyad. For a three-dimensional symmetric
/// Euclidean dyadic tensor, see PhQ::SymmetricDyad.
template <typename NumericType = double>
class Vector {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::Vector<NumericType> must be a numeric "
                "floating-point type: float, double, or long double.");

public:
  /// \brief Default constructor. Constructs a three-dimensional vector with uninitialized x, y, and
  /// z Cartesian components.
  Vector() = default;

  /// \brief Constructor. Constructs a three-dimensional vector from the given x, y, and z Cartesian
  /// components.
  constexpr Vector(const NumericType x, const NumericType y, const NumericType z)
    : x_y_z_({x, y, z}) {}

  /// \brief Constructor. Constructs a three-dimensional vector from a given array representing its
  /// x, y, and z Cartesian components.
  explicit constexpr Vector(const std::array<NumericType, 3>& x_y_z) : x_y_z_(x_y_z) {}

  /// \brief Constructor. Constructs a three-dimensional vector from a given two-dimensional planar
  /// vector in the XY plane. This vector's z-component is initialized to zero.
  explicit constexpr Vector(const PlanarVector<NumericType>& planar_vector)
    : x_y_z_({planar_vector.x(), planar_vector.y(), static_cast<NumericType>(0)}) {}

  /// \brief Constructor. Constructs a three-dimensional vector given a magnitude and a direction.
  constexpr Vector(NumericType magnitude, const Direction<NumericType>& direction);

  /// \brief Destructor. Destroys this three-dimensional vector.
  ~Vector() noexcept = default;

  /// \brief Copy constructor. Constructs a three-dimensional vector by copying another one.
  constexpr Vector(const Vector<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a three-dimensional vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Vector(const Vector<OtherNumericType>& other)
    : x_y_z_({static_cast<NumericType>(other.x()), static_cast<NumericType>(other.y()),
              static_cast<NumericType>(other.z())}) {}

  /// \brief Move constructor. Constructs a three-dimensional vector by moving another one.
  constexpr Vector(Vector<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  constexpr Vector<NumericType>& operator=(const Vector<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this three-dimensional vector by copying another one.
  template <typename OtherNumericType>
  constexpr Vector<NumericType>& operator=(const Vector<OtherNumericType>& other) {
    x_y_z_[0] = static_cast<NumericType>(other.x());
    x_y_z_[1] = static_cast<NumericType>(other.y());
    x_y_z_[2] = static_cast<NumericType>(other.z());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this three-dimensional vector by moving another one.
  constexpr Vector<NumericType>& operator=(Vector<NumericType>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this three-dimensional vector by copying a given array
  /// representing its x, y, and z Cartesian components.
  constexpr Vector<NumericType>& operator=(const std::array<NumericType, 3>& x_y_z) {
    x_y_z_ = x_y_z;
    return *this;
  }

  /// \brief Statically creates a three-dimensional vector with its x, y, and z Cartesian components
  /// initialized to zero.
  static constexpr Vector<NumericType> Zero() {
    return Vector<NumericType>{
        std::array<NumericType, 3>{
                                   static_cast<NumericType>(0), static_cast<NumericType>(0), static_cast<NumericType>(0)}
    };
  }

  /// \brief Returns this three-dimensional vector's x, y, and z Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<NumericType, 3>& x_y_z() const noexcept {
    return x_y_z_;
  }

  /// \brief Returns this three-dimensional vector's x Cartesian component.
  [[nodiscard]] constexpr NumericType x() const noexcept {
    return x_y_z_[0];
  }

  /// \brief Returns this three-dimensional vector's y Cartesian component.
  [[nodiscard]] constexpr NumericType y() const noexcept {
    return x_y_z_[1];
  }

  /// \brief Returns this three-dimensional vector's z Cartesian component.
  [[nodiscard]] constexpr NumericType z() const noexcept {
    return x_y_z_[2];
  }

  /// \brief Returns this three-dimensional vector's x, y, and z Cartesian components as a mutable
  /// array.
  constexpr std::array<NumericType, 3>& Mutable_x_y_z() noexcept {
    return x_y_z_;
  }

  /// \brief Returns this three-dimensional vector's x Cartesian component as a mutable value.
  constexpr NumericType& Mutable_x() noexcept {
    return x_y_z_[0];
  }

  /// \brief Returns this three-dimensional vector's y Cartesian component as a mutable value.
  constexpr NumericType& Mutable_y() noexcept {
    return x_y_z_[1];
  }

  /// \brief Returns this three-dimensional vector's z Cartesian component as a mutable value.
  constexpr NumericType& Mutable_z() noexcept {
    return x_y_z_[2];
  }

  /// \brief Sets this three-dimensional vector's x, y, and z Cartesian components to the given
  /// values.
  constexpr void Set_x_y_z(const std::array<NumericType, 3>& x_y_z) noexcept {
    x_y_z_ = x_y_z;
  }

  /// \brief Sets this three-dimensional vector's x, y, and z Cartesian components to the given
  /// values.
  constexpr void Set_x_y_z(const NumericType x, const NumericType y, const NumericType z) noexcept {
    x_y_z_[0] = x;
    x_y_z_[1] = y;
    x_y_z_[2] = z;
  }

  /// \brief Sets this three-dimensional vector's x Cartesian component to a given value.
  constexpr void Set_x(const NumericType x) noexcept {
    x_y_z_[0] = x;
  }

  /// \brief Sets this three-dimensional vector's y Cartesian component to a given value.
  constexpr void Set_y(const NumericType y) noexcept {
    x_y_z_[1] = y;
  }

  /// \brief Sets this three-dimensional vector's z Cartesian component to a given value.
  constexpr void Set_z(const NumericType z) noexcept {
    x_y_z_[2] = z;
  }

  /// \brief Returns the square of the magnitude of this three-dimensional vector.
  [[nodiscard]] constexpr NumericType MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1] + x_y_z_[2] * x_y_z_[2];
  }

  /// \brief Returns the magnitude (also known as the L2 norm) of this three-dimensional vector.
  [[nodiscard]] NumericType Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  /// \brief Returns the direction of this three-dimensional vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const;

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// three-dimensional vector and another one.
  [[nodiscard]] constexpr NumericType Dot(const Vector<NumericType>& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1]
           + x_y_z_[2] * vector.x_y_z_[2];
  }

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// three-dimensional vector and a given direction.
  [[nodiscard]] constexpr NumericType Dot(
      const PhQ::Direction<NumericType>& direction) const noexcept;

  /// \brief Returns the cross product (also known as the vector product) of this three-dimensional
  /// vector and another one.
  [[nodiscard]] constexpr Vector<NumericType> Cross(const Vector<NumericType>& vector) const {
    return Vector<NumericType>{x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
                               x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
                               x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  /// \brief Returns the cross product (also known as the vector product) of this three-dimensional
  /// vector and a given direction.
  [[nodiscard]] constexpr Vector<NumericType> Cross(
      const PhQ::Direction<NumericType>& direction) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// three-dimensional vector and another one.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(const Vector<NumericType>& vector) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// three-dimensional vector and a given direction.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(
      const PhQ::Direction<NumericType>& direction) const;

  /// \brief Returns the angle between this three-dimensional vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Vector<NumericType>& vector) const;

  /// \brief Returns the angle between this three-dimensional vector and a given direction.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const PhQ::Direction<NumericType>& direction) const;

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

  constexpr void operator+=(const Vector<NumericType>& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr void operator-=(const Vector<NumericType>& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  template <typename OtherNumericType>
  constexpr void operator*=(const OtherNumericType number) noexcept {
    x_y_z_[0] *= static_cast<NumericType>(number);
    x_y_z_[1] *= static_cast<NumericType>(number);
    x_y_z_[2] *= static_cast<NumericType>(number);
  }

  template <typename OtherNumericType>
  constexpr void operator/=(const OtherNumericType number) noexcept {
    x_y_z_[0] /= static_cast<NumericType>(number);
    x_y_z_[1] /= static_cast<NumericType>(number);
    x_y_z_[2] /= static_cast<NumericType>(number);
  }

private:
  /// \brief Cartesian components of this three-dimensional vector.
  std::array<NumericType, 3> x_y_z_;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  return left.x() == right.x() && left.y() == right.y() && left.z() == right.z();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  return left.x() != right.x() || left.y() != right.y() || left.z() != right.z();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() < right.x();
  }
  if (left.y() != right.y()) {
    return left.y() < right.y();
  }
  return left.z() < right.z();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() > right.x();
  }
  if (left.y() != right.y()) {
    return left.y() > right.y();
  }
  return left.z() > right.z();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Vector<NumericType>& left, const Vector<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator+(
    const Vector<NumericType>& left, const Vector<NumericType>& right) {
  return Vector<NumericType>{left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

template <typename NumericType>
inline constexpr Vector<NumericType> operator-(
    const Vector<NumericType>& left, const Vector<NumericType>& right) {
  return Vector<NumericType>{left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr Vector<NumericType> operator*(
    const Vector<NumericType>& vector, const OtherNumericType number) {
  return Vector<NumericType>{
      vector.x() * static_cast<NumericType>(number), vector.y() * static_cast<NumericType>(number),
      vector.z() * static_cast<NumericType>(number)};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr Vector<NumericType> operator*(
    const OtherNumericType number, const Vector<NumericType>& vector) {
  return Vector<NumericType>{vector * number};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr Vector<NumericType> operator/(
    const Vector<NumericType>& vector, const OtherNumericType number) {
  return Vector<NumericType>{
      vector.x() / static_cast<NumericType>(number), vector.y() / static_cast<NumericType>(number),
      vector.z() / static_cast<NumericType>(number)};
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Vector<NumericType>& vector) {
  stream << vector.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarVector<NumericType>::PlanarVector(const Vector<NumericType>& vector)
  : x_y_({vector.x(), vector.y()}) {}

template <typename NumericType>
[[nodiscard]] constexpr Vector<NumericType> PlanarVector<NumericType>::Cross(
    const PlanarVector<NumericType>& planar_vector) const {
  return Vector<NumericType>{static_cast<NumericType>(0), static_cast<NumericType>(0),
                             x_y_[0] * planar_vector.x_y_[1] - x_y_[1] * planar_vector.x_y_[0]};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Vector<NumericType>> {
  inline size_t operator()(const PhQ::Vector<NumericType>& vector) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result + hash<NumericType>()(vector.x());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(vector.y());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(vector.z());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_VECTOR_HPP
