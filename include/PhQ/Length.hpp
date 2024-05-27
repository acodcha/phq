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

#ifndef PHQ_LENGTH_HPP
#define PHQ_LENGTH_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Length.
template <typename Number>
class Area;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Displacement;

// Forward declaration for class PhQ::Length.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Energy;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Length.
template <typename Number>
class KinematicViscosity;

// Forward declaration for class PhQ::Length.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::Length.
template <typename Number>
class PlanarDirection;

// Forward declaration for class PhQ::Length.
template <typename Number>
class PlanarDisplacement;

// Forward declaration for class PhQ::Length.
template <typename Number>
class PlanarPosition;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Position;

// Forward declaration for class PhQ::Length.
template <typename Number>
class ReynoldsNumber;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Length.
template <typename Number>
class TransportEnergyConsumption;

// Forward declaration for class PhQ::Length.
template <typename Number>
class Volume;

/// \brief Length, distance, or physical size. Can also represent a scalar component or magnitude of
/// a position or displacement vector. For a three-dimensional Euclidean position vector, see
/// PhQ::Position. For a three-dimensional Euclidean displacement vector, see PhQ::Displacement. For
/// a two-dimensional Euclidean position vector in the XY plane, see PhQ::PlanarPosition. For a
/// two-dimensional Euclidean displacement vector in the XY plane, see PhQ::PlanarDisplacement.
template <typename Number = double>
class Length : public DimensionalScalar<Unit::Length, Number> {
public:
  /// \brief Default constructor. Constructs a length with an uninitialized value.
  Length() = default;

  /// \brief Constructor. Constructs a length with a given value expressed in a given length unit.
  Length(const Number value, const Unit::Length unit)
    : DimensionalScalar<Unit::Length, Number>(value, unit) {}

  /// \brief Constructor. Constructs a length from a given area and length.
  constexpr Length(const Area<Number>& area, const Length<Number>& length);

  /// \brief Constructor. Constructs a length from a given volume and area.
  constexpr Length(const Volume<Number>& volume, const Area<Number>& area);

  /// \brief Constructor. Constructs a length from a given speed and time using the definition of
  /// speed.
  constexpr Length(const Speed<Number>& speed, const Time<Number>& time);

  /// \brief Constructor. Constructs a length from a given speed and frequency using the definition
  /// of speed.
  constexpr Length(const Speed<Number>& speed, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs a length from a given Reynolds number, dynamic viscosity, mass
  /// density, and speed using the definition of the Reynolds number.
  constexpr Length(const ReynoldsNumber<Number>& reynolds_number,
                   const DynamicViscosity<Number>& dynamic_viscosity,
                   const MassDensity<Number>& mass_density, const Speed<Number>& speed);

  /// \brief Constructor. Constructs a length from a given Reynolds number, kinematic viscosity, and
  /// speed using the definition of the Reynolds number.
  constexpr Length(
      const ReynoldsNumber<Number>& reynolds_number,
      const KinematicViscosity<Number>& kinematic_viscosity, const Speed<Number>& speed);

  /// \brief Constructor. Constructs a length from a given energy and transport energy consumption
  /// using the definition of transport energy consumption.
  constexpr Length(const Energy<Number>& energy,
                   const TransportEnergyConsumption<Number>& transport_energy_consumption);

  /// \brief Destructor. Destroys this length.
  ~Length() noexcept = default;

  /// \brief Copy constructor. Constructs a length by copying another one.
  constexpr Length(const Length<Number>& other) = default;

  /// \brief Copy constructor. Constructs a length by copying another one.
  template <typename OtherNumber>
  explicit constexpr Length(const Length<OtherNumber>& other)
    : Length(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a length by moving another one.
  constexpr Length(Length<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this length by copying another one.
  constexpr Length<Number>& operator=(const Length<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this length by copying another one.
  template <typename OtherNumber>
  constexpr Length<Number>& operator=(const Length<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this length by moving another one.
  constexpr Length<Number>& operator=(Length<Number>&& other) noexcept = default;

  /// \brief Statically creates a length of zero.
  static constexpr Length<Number> Zero() {
    return Length<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a length with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Length<Number> Create(const Number value) {
    return Length<Number>{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  constexpr Length<Number> operator+(const Length<Number>& length) const {
    return Length<Number>{this->value + length.value};
  }

  constexpr Length<Number> operator-(const Length<Number>& length) const {
    return Length<Number>{this->value - length.value};
  }

  constexpr Length<Number> operator*(const Number number) const {
    return Length<Number>{this->value * number};
  }

  constexpr Area<Number> operator*(const Length<Number>& length) const;

  constexpr Volume<Number> operator*(const Area<Number>& area) const;

  constexpr Speed<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Position<Number> operator*(const Direction<Number>& direction) const;

  constexpr PlanarPosition<Number> operator*(const PlanarDirection<Number>& planar_direction) const;

  constexpr Energy<Number> operator*(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const;

  constexpr Length<Number> operator/(const Number number) const {
    return Length<Number>{this->value / number};
  }

  constexpr Speed<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const Speed<Number>& speed) const;

  constexpr Number operator/(const Length<Number>& length) const noexcept {
    return this->value / length.value;
  }

  constexpr void operator+=(const Length<Number>& length) noexcept {
    this->value += length.value;
  }

  constexpr void operator-=(const Length<Number>& length) noexcept {
    this->value -= length.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a length with a given value expressed in the standard length
  /// unit.
  explicit constexpr Length(const Number value) : DimensionalScalar<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class Displacement;

  template <typename OtherNumber>
  friend class PlanarDisplacement;

  template <typename OtherNumber>
  friend class PlanarPosition;

  template <typename OtherNumber>
  friend class Position;
};

template <typename Number>
inline constexpr bool operator==(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Length<Number>& left, const Length<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Length<Number>& length) {
  stream << length.Print();
  return stream;
}

template <typename Number>
inline constexpr Length<Number> operator*(const Number number, const Length<Number>& length) {
  return length * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Length<Number>> {
  inline size_t operator()(const PhQ::Length<Number>& length) const {
    return hash<Number>()(length.Value());
  }
};

}  // namespace std

#endif  // PHQ_LENGTH_HPP
