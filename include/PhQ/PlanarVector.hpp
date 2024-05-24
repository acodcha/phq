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
template <typename Number>
class Angle;

// Forward declaration for class PhQ::PlanarVector.
template <typename>
class Dyad;

// Forward declaration for class PhQ::PlanarVector.
template <typename Number>
class PlanarDirection;

// Forward declaration for class PhQ::PlanarVector.
template <typename Number>
class Vector;

/// \brief Two-dimensional planar vector in the XY plane in Cartesian coordinates. Contains two
/// components: x and y.
template <typename Number = double>
class PlanarVector {
  static_assert(std::is_floating_point<Number>::value,
                "The Number template parameter of PhQ::PlanarVector<Number> must be a "
                "floating-point number type.");

public:
  /// \brief Default constructor. Constructs a two-dimensional planar vector with uninitialized x
  /// and y Cartesian components.
  PlanarVector() = default;

  /// \brief Constructor. Constructs a two-dimensional planar vector from the given x and y
  /// Cartesian components.
  constexpr PlanarVector(const Number x, const Number y) : x_y_({x, y}) {}

  /// \brief Constructor. Constructs a two-dimensional planar vector from a given array representing
  /// its x and y Cartesian components.
  explicit constexpr PlanarVector(const std::array<Number, 2>& x_y) : x_y_(x_y) {}

  /// \brief Constructor. Constructs a two-dimensional planar vector from a given three-dimensional
  /// vector. Projects the three-dimensional vector onto the XY plane.
  explicit constexpr PlanarVector(const Vector<Number>& vector);

  /// \brief Constructor. Constructs a two-dimensional planar vector given a magnitude and a planar
  /// direction.
  constexpr PlanarVector(Number magnitude, const PlanarDirection<Number>& direction);

  /// \brief Destructor. Destroys this two-dimensional planar vector.
  ~PlanarVector() noexcept = default;

  /// \brief Copy constructor. Constructs a two-dimensional planar vector by copying another one.
  constexpr PlanarVector(const PlanarVector<Number>& other) = default;

  /// \brief Copy constructor. Constructs a two-dimensional planar vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarVector(const PlanarVector<OtherNumber>& other)
    : x_y_({static_cast<Number>(other.x()), static_cast<Number>(other.y())}) {}

  /// \brief Move constructor. Constructs a two-dimensional planar vector by moving another one.
  constexpr PlanarVector(PlanarVector<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this two-dimensional planar vector by copying another
  /// one.
  constexpr PlanarVector<Number>& operator=(const PlanarVector<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this two-dimensional planar vector by copying another
  /// one.
  template <typename OtherNumber>
  constexpr PlanarVector<Number>& operator=(const PlanarVector<OtherNumber>& other) {
    x_y_[0] = static_cast<Number>(other.x());
    x_y_[1] = static_cast<Number>(other.y());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this two-dimensional planar vector by moving another
  /// one.
  constexpr PlanarVector<Number>& operator=(PlanarVector<Number>&& other) noexcept = default;

  /// \brief Assignment operator. Assigns this two-dimensional planar vector by copying a given
  /// array representing its x and y Cartesian components.
  constexpr PlanarVector<Number>& operator=(const std::array<Number, 2>& x_y) {
    x_y_ = x_y;
    return *this;
  }

  /// \brief Statically creates a two-dimensional planar vector with its x and y Cartesian
  /// components initialized to zero.
  static constexpr PlanarVector<Number> Zero() {
    return PlanarVector<Number>{
        std::array<Number, 2>{static_cast<Number>(0), static_cast<Number>(0)}
    };
  }

  /// \brief Returns this two-dimensional planar vector's x and y Cartesian components as an array.
  [[nodiscard]] constexpr const std::array<Number, 2>& x_y() const noexcept {
    return x_y_;
  }

  /// \brief Returns this two-dimensional planar vector's x Cartesian component.
  [[nodiscard]] constexpr Number x() const noexcept {
    return x_y_[0];
  }

  /// \brief Returns this two-dimensional planar vector's y Cartesian component.
  [[nodiscard]] constexpr Number y() const noexcept {
    return x_y_[1];
  }

  /// \brief Returns this two-dimensional planar vector's x and y Cartesian components as a mutable
  /// array.
  constexpr std::array<Number, 2>& Mutable_x_y() noexcept {
    return x_y_;
  }

  /// \brief Returns this two-dimensional planar vector's x Cartesian component as a mutable value.
  constexpr Number& Mutable_x() noexcept {
    return x_y_[0];
  }

  /// \brief Returns this two-dimensional planar vector's y Cartesian component as a mutable value.
  constexpr Number& Mutable_y() noexcept {
    return x_y_[1];
  }

  /// \brief Sets this two-dimensional planar vector's x and y Cartesian components to the given
  /// values.
  constexpr void Set_x_y(const std::array<Number, 2>& x_y) noexcept {
    x_y_ = x_y;
  }

  /// \brief Sets this two-dimensional planar vector's x and y Cartesian components to the given
  /// values.
  constexpr void Set_x_y(const Number x, const Number y) noexcept {
    x_y_[0] = x;
    x_y_[1] = y;
  }

  /// \brief Sets this two-dimensional planar vector's x Cartesian component to a given value.
  constexpr void Set_x(const Number x) noexcept {
    x_y_[0] = x;
  }

  /// \brief Sets this two-dimensional planar vector's y Cartesian component to a given value.
  constexpr void Set_y(const Number y) noexcept {
    x_y_[1] = y;
  }

  /// \brief Returns the square of the magnitude of this two-dimensional planar vector.
  [[nodiscard]] constexpr Number MagnitudeSquared() const noexcept {
    return x_y_[0] * x_y_[0] + x_y_[1] * x_y_[1];
  }

  /// \brief Returns the magnitude (also known as the L2 norm) of this two-dimensional planar
  /// vector.
  [[nodiscard]] Number Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  /// \brief Returns the planar direction of this two-dimensional planar vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const;

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// two-dimensional planar vector and another one.
  [[nodiscard]] constexpr Number Dot(const PlanarVector<Number>& planar_vector) const noexcept {
    return x_y_[0] * planar_vector.x_y_[0] + x_y_[1] * planar_vector.x_y_[1];
  }

  /// \brief Returns the dot product (also known as the inner product or scalar product) of this
  /// two-dimensional planar vector and a given planar direction.
  [[nodiscard]] constexpr Number Dot(
      const PhQ::PlanarDirection<Number>& planar_direction) const noexcept;  // TODO.

  /// \brief Returns the cross product (also known as the vector product) of this two-dimensional
  /// planar vector and another one.
  [[nodiscard]] constexpr Vector<Number> Cross(const PlanarVector<Number>& planar_vector) const;

  /// \brief Returns the cross product (also known as the vector product) of this two-dimensional
  /// planar vector and a given planar direction.
  [[nodiscard]] constexpr Vector<Number> Cross(
      const PhQ::PlanarDirection<Number>& planar_direction) const;  // TODO.

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// two-dimensional planar vector and another one.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(
      const PlanarVector<Number>& planar_vector) const;  // TODO.

  /// \brief Returns the dyadic tensor product (also known as the outer product) of this
  /// two-dimensional planar vector and a given planar direction.
  [[nodiscard]] constexpr Dyad<Number> Dyadic(
      const PhQ::PlanarDirection<Number>& planar_direction) const;  // TODO.

  /// \brief Returns the angle between this two-dimensional planar vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarVector<Number>& planar_vector) const;  // TODO.

  /// \brief Returns the angle between this two-dimensional planar vector and a given planar
  /// direction.
  [[nodiscard]] PhQ::Angle<Number> Angle(
      const PhQ::PlanarDirection<Number>& planar_direction) const;  // TODO.

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

  constexpr void operator+=(const PlanarVector<Number>& planar_vector) noexcept {
    x_y_[0] += planar_vector.x_y_[0];
    x_y_[1] += planar_vector.x_y_[1];
  }

  constexpr void operator-=(const PlanarVector<Number>& planar_vector) noexcept {
    x_y_[0] -= planar_vector.x_y_[0];
    x_y_[1] -= planar_vector.x_y_[1];
  }

  template <typename OtherNumber>
  constexpr void operator*=(const OtherNumber number) noexcept {
    x_y_[0] *= static_cast<Number>(number);
    x_y_[1] *= static_cast<Number>(number);
  }

  template <typename OtherNumber>
  constexpr void operator/=(const OtherNumber number) noexcept {
    x_y_[0] /= static_cast<Number>(number);
    x_y_[1] /= static_cast<Number>(number);
  }

private:
  /// \brief Cartesian components of this two-dimensional planar vector.
  std::array<Number, 2> x_y_;
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  return left.x() == right.x() && left.y() == right.y();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  return left.x() != right.x() || left.y() != right.y();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() < right.x();
  }
  return left.y() < right.y();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() > right.x();
  }
  return left.y() > right.y();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline constexpr PlanarVector<Number> operator+(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) {
  return PlanarVector<Number>{left.x() + right.x(), left.y() + right.y()};
}

template <typename Number>
inline constexpr PlanarVector<Number> operator-(
    const PlanarVector<Number>& left, const PlanarVector<Number>& right) {
  return PlanarVector<Number>{left.x() - right.x(), left.y() - right.y()};
}

template <typename Number, typename OtherNumber>
inline constexpr PlanarVector<Number> operator*(
    const PlanarVector<Number>& planar_vector, const OtherNumber number) {
  return PlanarVector<Number>{planar_vector.x() * static_cast<Number>(number),
                              planar_vector.y() * static_cast<Number>(number)};
}

template <typename Number, typename OtherNumber>
inline constexpr PlanarVector<Number> operator*(
    const OtherNumber number, const PlanarVector<Number>& planar_vector) {
  return PlanarVector<Number>{planar_vector * number};
}

template <typename Number, typename OtherNumber>
inline constexpr PlanarVector<Number> operator/(
    const PlanarVector<Number>& planar_vector, const OtherNumber number) {
  return PlanarVector<Number>{planar_vector.x() / static_cast<Number>(number),
                              planar_vector.y() / static_cast<Number>(number)};
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PlanarVector<Number>& planar_vector) {
  stream << planar_vector.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarVector<Number>> {
  inline size_t operator()(const PhQ::PlanarVector<Number>& planar_vector) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result + hash<Number>()(planar_vector.x());
    result = static_cast<size_t>(31) * result + hash<Number>()(planar_vector.y());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_VECTOR_HPP
