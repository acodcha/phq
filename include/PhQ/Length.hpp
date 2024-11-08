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

#ifndef PHQ_LENGTH_HPP
#define PHQ_LENGTH_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Area;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Displacement;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Energy;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class KinematicViscosity;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class PlanarDisplacement;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class PlanarPosition;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Position;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class ReynoldsNumber;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class TransportEnergyConsumption;

// Forward declaration for class PhQ::Length.
template <typename NumericType>
class Volume;

/// \brief Length, distance, or physical size. Can also represent a scalar component or magnitude of
/// a position or displacement vector. For a three-dimensional Euclidean position vector, see
/// PhQ::Position. For a three-dimensional Euclidean displacement vector, see PhQ::Displacement. For
/// a two-dimensional Euclidean position vector in the XY plane, see PhQ::PlanarPosition. For a
/// two-dimensional Euclidean displacement vector in the XY plane, see PhQ::PlanarDisplacement.
template <typename NumericType = double>
class Length : public DimensionalScalar<Unit::Length, NumericType> {
public:
  /// \brief Default constructor. Constructs a length with an uninitialized value.
  Length() = default;

  /// \brief Constructor. Constructs a length with a given value expressed in a given length unit.
  Length(const NumericType value, const Unit::Length unit)
    : DimensionalScalar<Unit::Length, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a length from a given area and length.
  constexpr Length(const Area<NumericType>& area, const Length<NumericType>& length);

  /// \brief Constructor. Constructs a length from a given volume and area.
  constexpr Length(const Volume<NumericType>& volume, const Area<NumericType>& area);

  /// \brief Constructor. Constructs a length from a given speed and time using the definition of
  /// speed.
  constexpr Length(const Speed<NumericType>& speed, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a length from a given speed and frequency using the definition
  /// of speed.
  constexpr Length(const Speed<NumericType>& speed, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a length from a given Reynolds number, dynamic viscosity, mass
  /// density, and speed using the definition of the Reynolds number.
  constexpr Length(const ReynoldsNumber<NumericType>& reynolds_number,
                   const DynamicViscosity<NumericType>& dynamic_viscosity,
                   const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed);

  /// \brief Constructor. Constructs a length from a given Reynolds number, kinematic viscosity, and
  /// speed using the definition of the Reynolds number.
  constexpr Length(
      const ReynoldsNumber<NumericType>& reynolds_number,
      const KinematicViscosity<NumericType>& kinematic_viscosity, const Speed<NumericType>& speed);

  /// \brief Constructor. Constructs a length from a given energy and transport energy consumption
  /// using the definition of transport energy consumption.
  constexpr Length(const Energy<NumericType>& energy,
                   const TransportEnergyConsumption<NumericType>& transport_energy_consumption);

  /// \brief Destructor. Destroys this length.
  ~Length() noexcept = default;

  /// \brief Copy constructor. Constructs a length by copying another one.
  constexpr Length(const Length<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a length by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Length(const Length<OtherNumericType>& other)
    : Length(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a length by moving another one.
  constexpr Length(Length<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this length by copying another one.
  constexpr Length<NumericType>& operator=(const Length<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this length by copying another one.
  template <typename OtherNumericType>
  constexpr Length<NumericType>& operator=(const Length<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this length by moving another one.
  constexpr Length<NumericType>& operator=(Length<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a length of zero.
  [[nodiscard]] static constexpr Length<NumericType> Zero() {
    return Length<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a length with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  [[nodiscard]] static constexpr Length<NumericType> Create(const NumericType value) {
    return Length<NumericType>{
      ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  constexpr Length<NumericType> operator+(const Length<NumericType>& length) const {
    return Length<NumericType>{this->value + length.value};
  }

  constexpr Length<NumericType> operator-(const Length<NumericType>& length) const {
    return Length<NumericType>{this->value - length.value};
  }

  constexpr Length<NumericType> operator*(const NumericType number) const {
    return Length<NumericType>{this->value * number};
  }

  constexpr Area<NumericType> operator*(const Length<NumericType>& length) const;

  constexpr Volume<NumericType> operator*(const Area<NumericType>& area) const;

  constexpr Speed<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Position<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr PlanarPosition<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr Energy<NumericType> operator*(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const;

  constexpr Length<NumericType> operator/(const NumericType number) const {
    return Length<NumericType>{this->value / number};
  }

  constexpr Speed<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(const Speed<NumericType>& speed) const;

  constexpr NumericType operator/(const Length<NumericType>& length) const noexcept {
    return this->value / length.value;
  }

  constexpr void operator+=(const Length<NumericType>& length) noexcept {
    this->value += length.value;
  }

  constexpr void operator-=(const Length<NumericType>& length) noexcept {
    this->value -= length.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a length with a given value expressed in the standard length
  /// unit.
  explicit constexpr Length(const NumericType value)
    : DimensionalScalar<Unit::Length, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class Displacement;

  template <typename OtherNumericType>
  friend class PlanarDisplacement;

  template <typename OtherNumericType>
  friend class PlanarPosition;

  template <typename OtherNumericType>
  friend class Position;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Length<NumericType>& left, const Length<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Length<NumericType>& length) {
  stream << length.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Length<NumericType> operator*(
    const NumericType number, const Length<NumericType>& length) {
  return length * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Length<NumericType>> {
  inline size_t operator()(const PhQ::Length<NumericType>& length) const {
    return hash<NumericType>()(length.Value());
  }
};

}  // namespace std

#endif  // PHQ_LENGTH_HPP
