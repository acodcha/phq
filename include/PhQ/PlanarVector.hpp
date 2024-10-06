// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_PLANAR_VECTOR_HPP
#define PHQ_PLANAR_VECTOR_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"

namespace PhQ {

// Forward declarations for class PhQ::PlanarVector.
template <typename NumericType>
class Angle;

// Forward declaration for class PhQ::PlanarVector.
template <typename>
class Dyad;

// Forward declaration for class PhQ::PlanarVector.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::PlanarVector.
template <typename NumericType>
class Vector;

/// \brief Two-dimensional Euclidean vector in the XY plane. Contains two components in Cartesian
/// coordinates: x and y. For a three-dimensional Euclidean vector, see PhQ::Vector. For a
/// three-dimensional Euclidean dyadic tensor, see PhQ::Dyad. For a three-dimensional symmetric
/// Euclidean dyadic tensor, see PhQ::SymmetricDyad.
/// \tparam NumericType Floating-point numeric type: float, double, or long double. Defaults to
/// double if unspecified.
template <typename NumericType = double>
class PlanarVector {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::PlanarVector<NumericType> must be a "
                "numeric floating-point type: float, double, or long double.");

public:
  /// \brief Default constructor. Constructs a two-dimensional planar vector with uninitialized x
  /// and y Cartesian components.
  PlanarVector() = default;

  /// \brief Constructor. Constructs a two-dimensional planar vector from the given x and y
  /// Cartesian components.
  constexpr PlanarVector(const NumericType x, const NumericType y) : x_y_({x, y}) {}

  /// \brief Constructor. Constructs a two-dimensional planar vector from a given array representing
  /// its x and y Cartesian components.
  explicit constexpr PlanarVector(const std::array<NumericType, 2>& x_y) : x_y_(x_y) {}

  /// \brief Constructor. Constructs a two-dimensional planar vector from a given three-dimensional
  /// vector. Projects the three-dimensional vector onto the XY plane.
  explicit constexpr PlanarVector(const Vector<NumericType>& vector);

  /// \brief Constructor. Constructs a two-dimensional planar vector given a magnitude and a planar
  /// direction.
  constexpr PlanarVector(NumericType magnitude, const PlanarDirection<NumericType>& direction);

  /// \brief Destructor. Destroys this two-dimensional planar vector.
  ~PlanarVector() noexcept = default;

  /// \brief Copy constructor. Constructs a two-dimensional planar vector by copying another one.
  constexpr PlanarVector(const PlanarVector<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a two-dimensional planar vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarVector(const PlanarVector<OtherNumericType>& other)
    : x_y_({static_cast<NumericType>(other.x()), static_cast<NumericType>(other.y())}) {}

  /// \brief Move constructor. Constructs a two-dimensional planar vector by moving another one.
  constexpr PlanarVector(PlanarVector<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this two-dimensional planar vector by copying another
  /// one.
  constexpr PlanarVector<NumericType>& operator=(const PlanarVector<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this two-dimensional planar vector by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr PlanarVector<NumericType>& operator=(const PlanarVector<OtherNumericType>& other) {
    x_y_[0] = static_cast<NumericType>(other.x());
    x_y_[1] = static_cast<NumericType>(other.y());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this two-dimensional planar vector by moving another
  /// one.
  constexpr PlanarVector<NumericType>& operator=(
      PlanarVector<NumericType>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this two-dimensional planar vector by copying a given
  /// array representing its x and y Cartesian components.
  constexpr PlanarVector<NumericType>& operator=(const std::array<NumericType, 2>& x_y) {
    x_y_ = x_y;
    return *this;
  }

  /// \brief Statically creates a two-dimensional planar vector with its x and y Cartesian
  /// components initialized to zero.
  [[nodiscard]] static constexpr PlanarVector<NumericType> Zero() {
    return PlanarVector<NumericType>{
      std::array<NumericType, 2>{static_cast<NumericType>(0), static_cast<NumericType>(0)}
    };
  }

  /// \brief Returns this two-dimensional planar vector's x and y Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<NumericType, 2>& x_y() const noexcept {
    return x_y_;
  }

  /// \brief Returns this two-dimensional planar vector's x Cartesian component.
  [[nodiscard]] constexpr NumericType x() const noexcept {
    return x_y_[0];
  }

  /// \brief Returns this two-dimensional planar vector's y Cartesian component.
  [[nodiscard]] constexpr NumericType y() const noexcept {
    return x_y_[1];
  }

  /// \brief Returns this two-dimensional planar vector's x and y Cartesian components as a mutable
  /// array.
  [[nodiscard]] constexpr std::array<NumericType, 2>& Mutable_x_y() noexcept {
    return x_y_;
  }

  /// \brief Returns this two-dimensional planar vector's x Cartesian component as a mutable value.
  [[nodiscard]] constexpr NumericType& Mutable_x() noexcept {
    return x_y_[0];
  }

  /// \brief Returns this two-dimensional planar vector's y Cartesian component as a mutable value.
  [[nodiscard]] constexpr NumericType& Mutable_y() noexcept {
    return x_y_[1];
  }

  /// \brief Sets this two-dimensional planar vector's x and y Cartesian components to the given
  /// values.
  constexpr void Set_x_y(const std::array<NumericType, 2>& x_y) noexcept {
    x_y_ = x_y;
  }

  /// \brief Sets this two-dimensional planar vector's x and y Cartesian components to the given
  /// values.
  constexpr void Set_x_y(const NumericType x, const NumericType y) noexcept {
    x_y_[0] = x;
    x_y_[1] = y;
  }

  /// \brief Sets this two-dimensional planar vector's x Cartesian component to a given value.
  constexpr void Set_x(const NumericType x) noexcept {
    x_y_[0] = x;
  }

  /// \brief Sets this two-dimensional planar vector's y Cartesian component to a given value.
  constexpr void Set_y(const NumericType y) noexcept {
    x_y_[1] = y;
  }

  /// \brief Returns the square of the magnitude of this two-dimensional planar vector.
  [[nodiscard]] constexpr NumericType MagnitudeSquared() const noexcept {
    return x_y_[0] * x_y_[0] + x_y_[1] * x_y_[1];
  }

  /// \brief Returns the magnitude (also known as the L2 norm) of this two-dimensional planar
  /// vector.
  [[nodiscard]] NumericType Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  /// \brief Returns the planar direction of this two-dimensional planar vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const;

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// two-dimensional planar vector and another one.
  [[nodiscard]] constexpr NumericType Dot(const PlanarVector<NumericType>& other) const noexcept {
    return x_y_[0] * other.x_y_[0] + x_y_[1] * other.x_y_[1];
  }

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// two-dimensional planar vector and a given planar direction.
  [[nodiscard]] constexpr NumericType Dot(
      const PhQ::PlanarDirection<NumericType>& planar_direction) const noexcept;

  /// \brief Returns the cross product (also known as the vector product) of this two-dimensional
  /// planar vector and another one.
  [[nodiscard]] constexpr Vector<NumericType> Cross(const PlanarVector<NumericType>& other) const;

  /// \brief Returns the cross product (also known as the vector product) of this two-dimensional
  /// planar vector and a given planar direction.
  [[nodiscard]] constexpr Vector<NumericType> Cross(
      const PhQ::PlanarDirection<NumericType>& planar_direction) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// two-dimensional planar vector and another one.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(const PlanarVector<NumericType>& other) const;

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// two-dimensional planar vector and a given planar direction.
  [[nodiscard]] constexpr Dyad<NumericType> Dyadic(
      const PhQ::PlanarDirection<NumericType>& planar_direction) const;

  /// \brief Returns the angle between this two-dimensional planar vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const PlanarVector<NumericType>& other) const;

  /// \brief Returns the angle between this two-dimensional planar vector and a given planar
  /// direction.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PhQ::PlanarDirection<NumericType>& planar_direction) const;

  /// \brief Prints this two-dimensional planar vector as a string.
  [[nodiscard]] std::string Print() const {
    return "(" + PhQ::Print(x_y_[0]) + ", " + PhQ::Print(x_y_[1]) + ")";
  }

  /// \brief Serializes this two-dimensional planar vector as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return "{\"x\":" + PhQ::Print(x_y_[0]) + ",\"y\":" + PhQ::Print(x_y_[1]) + "}";
  }

  /// \brief Serializes this two-dimensional planar vector as an XML message.
  [[nodiscard]] std::string XML() const {
    return "<x>" + PhQ::Print(x_y_[0]) + "</x><y>" + PhQ::Print(x_y_[1]) + "</y>";
  }

  /// \brief Serializes this two-dimensional planar vector as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return "{x:" + PhQ::Print(x_y_[0]) + ",y:" + PhQ::Print(x_y_[1]) + "}";
  }

  /// \brief Adds another two-dimensional planar vector to this one.
  constexpr void operator+=(const PlanarVector<NumericType>& other) noexcept {
    x_y_[0] += other.x_y_[0];
    x_y_[1] += other.x_y_[1];
  }

  /// \brief Subtracts another two-dimensional planar vector from this one.
  constexpr void operator-=(const PlanarVector<NumericType>& other) noexcept {
    x_y_[0] -= other.x_y_[0];
    x_y_[1] -= other.x_y_[1];
  }

  /// \brief Multiplies this two-dimensional planar vector by the given number.
  /// \tparam OtherNumericType Floating-point numeric type of the given number. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr void operator*=(const OtherNumericType number) noexcept {
    x_y_[0] *= static_cast<NumericType>(number);
    x_y_[1] *= static_cast<NumericType>(number);
  }

  /// \brief Divides this two-dimensional planar vector by the given number.
  /// \tparam OtherNumericType Floating-point numeric type of the given number. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr void operator/=(const OtherNumericType number) noexcept {
    x_y_[0] /= static_cast<NumericType>(number);
    x_y_[1] /= static_cast<NumericType>(number);
  }

private:
  /// \brief Cartesian components of this two-dimensional planar vector.
  std::array<NumericType, 2> x_y_;
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  return left.x() == right.x() && left.y() == right.y();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  return left.x() != right.x() || left.y() != right.y();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() < right.x();
  }
  return left.y() < right.y();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() > right.x();
  }
  return left.y() > right.y();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline constexpr PlanarVector<NumericType> operator+(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) {
  return PlanarVector<NumericType>{left.x() + right.x(), left.y() + right.y()};
}

template <typename NumericType>
inline constexpr PlanarVector<NumericType> operator-(
    const PlanarVector<NumericType>& left, const PlanarVector<NumericType>& right) {
  return PlanarVector<NumericType>{left.x() - right.x(), left.y() - right.y()};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr PlanarVector<NumericType> operator*(
    const PlanarVector<NumericType>& planar_vector, const OtherNumericType number) {
  return PlanarVector<NumericType>{planar_vector.x() * static_cast<NumericType>(number),
                                   planar_vector.y() * static_cast<NumericType>(number)};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr PlanarVector<NumericType> operator*(
    const OtherNumericType number, const PlanarVector<NumericType>& planar_vector) {
  return PlanarVector<NumericType>{planar_vector * number};
}

template <typename NumericType, typename OtherNumericType>
inline constexpr PlanarVector<NumericType> operator/(
    const PlanarVector<NumericType>& planar_vector, const OtherNumericType number) {
  return PlanarVector<NumericType>{planar_vector.x() / static_cast<NumericType>(number),
                                   planar_vector.y() / static_cast<NumericType>(number)};
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarVector<NumericType>& planar_vector) {
  stream << planar_vector.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarVector<NumericType>> {
  inline size_t operator()(const PhQ::PlanarVector<NumericType>& planar_vector) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result + hash<NumericType>()(planar_vector.x());
    result = static_cast<size_t>(31) * result + hash<NumericType>()(planar_vector.y());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_VECTOR_HPP
