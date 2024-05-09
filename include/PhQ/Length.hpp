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

// Length, size, or distance. Can also represent the magnitude of a position vector or displacement
// vector.
template <typename Number = double>
class Length : public DimensionalScalar<Unit::Length, Number> {
public:
  // Default constructor. Constructs a length with an uninitialized value.
  Length() = default;

  // Constructor. Constructs a length with a given value expressed in a given length unit.
  Length(const Number value, const Unit::Length unit)
    : DimensionalScalar<Unit::Length, Number>(value, unit) {}

  // Constructor. Constructs a length from a given area and length.
  constexpr Length(const Area<Number>& area, const Length<Number>& length);

  // Constructor. Constructs a length from a given volume and area.
  constexpr Length(const Volume<Number>& volume, const Area<Number>& area);

  // Constructor. Constructs a length from a given speed and time using the definition of speed.
  constexpr Length(const Speed<Number>& speed, const Time<Number>& time);

  // Constructor. Constructs a length from a given speed and frequency using the definition of
  // speed.
  constexpr Length(const Speed<Number>& speed, const Frequency<Number>& frequency);

  // Constructor. Constructs a length from a given Reynolds number, dynamic viscosity, mass density,
  // and speed using the definition of the Reynolds number.
  constexpr Length(const ReynoldsNumber<Number>& reynolds_number,
                   const DynamicViscosity<Number>& dynamic_viscosity,
                   const MassDensity<Number>& mass_density, const Speed<Number>& speed);

  // Constructor. Constructs a length from a given Reynolds number, kinematic viscosity, and speed
  // using the definition of the Reynolds number.
  constexpr Length(
      const ReynoldsNumber<Number>& reynolds_number,
      const KinematicViscosity<Number>& kinematic_viscosity, const Speed<Number>& speed);

  // Constructor. Constructs a length from a given energy and transport energy consumption using the
  // definition of transport energy consumption.
  constexpr Length(const Energy<Number>& energy,
                   const TransportEnergyConsumption<Number>& transport_energy_consumption);

  // Destructor. Destroys this length.
  ~Length() noexcept = default;

  // Copy constructor. Constructs a length by copying another one.
  constexpr Length(const Length<Number>& other) = default;

  // Copy constructor. Constructs a length by copying another one.
  template <typename OtherNumber>
  explicit constexpr Length(const Length<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a length by moving another one.
  constexpr Length(Length<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this length by copying another one.
  constexpr Length<Number>& operator=(const Length<Number>& other) = default;

  // Copy assignment operator. Assigns this length by copying another one.
  template <typename OtherNumber>
  constexpr Length<Number>& operator=(const Length<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this length by moving another one.
  constexpr Length<Number>& operator=(Length<Number>&& other) noexcept = default;

  // Statically creates a length of zero.
  static constexpr Length<Number> Zero() {
    return Length<Number>{static_cast<Number>(0)};
  }

  // Statically creates a length with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Length<Number> Create(const Number value) {
    return Length<Number>{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  constexpr Length<Number> operator+(const Length<Number>& length) const {
    return Length<Number>{value + length.value};
  }

  constexpr Length<Number> operator-(const Length<Number>& length) const {
    return Length<Number>{value - length.value};
  }

  constexpr Length<Number> operator*(const Number number) const {
    return Length<Number>{value * number};
  }

  constexpr Area<Number> operator*(const Length<Number>& length) const;

  constexpr Volume<Number> operator*(const Area<Number>& area) const;

  constexpr Speed<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Position<Number> operator*(const Direction<Number>& direction) const;

  constexpr Energy<Number> operator*(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const;

  constexpr Length<Number> operator/(const Number number) const {
    return Length<Number>{value / number};
  }

  constexpr Speed<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const Speed<Number>& speed) const;

  constexpr Number operator/(const Length<Number>& length) const noexcept {
    return value / length.value;
  }

  constexpr void operator+=(const Length<Number>& length) noexcept {
    value += length.value;
  }

  constexpr void operator-=(const Length<Number>& length) noexcept {
    value -= length.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a length with a given value expressed in the standard length unit.
  explicit constexpr Length(const Number value) : DimensionalScalar<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class Displacement;

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
