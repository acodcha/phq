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

#ifndef PHQ_LENGTH_HPP
#define PHQ_LENGTH_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declarations for class Length.
class Area;
class Direction;
class Displacement;
class DynamicViscosity;
class Energy;
class Frequency;
class KinematicViscosity;
class MassDensity;
class Position;
class ReynoldsNumber;
class Speed;
class Time;
class TransportEnergyConsumption;
class Volume;

// Length, size, or distance. Can also represent the magnitude of a position vector or displacement
// vector.
class Length : public DimensionalScalar<Unit::Length> {
public:
  // Default constructor. Constructs a length with an uninitialized value.
  Length() = default;

  // Constructor. Constructs a length with a given value expressed in a given length unit.
  Length(const double value, const Unit::Length unit)
    : DimensionalScalar<Unit::Length>(value, unit) {}

  // Constructor. Constructs a length from a given area and length.
  constexpr Length(const Area& area, const Length& length);

  // Constructor. Constructs a length from a given volume and area.
  constexpr Length(const Volume& volume, const Area& area);

  // Constructor. Constructs a length from a given speed and time using the definition of speed.
  constexpr Length(const Speed& speed, const Time& time);

  // Constructor. Constructs a length from a given speed and frequency using the definition of
  // speed.
  constexpr Length(const Speed& speed, const Frequency& frequency);

  // Constructor. Constructs a length from a given Reynolds number, dynamic viscosity, mass density,
  // and speed using the definition of the Reynolds number.
  constexpr Length(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity,
                   const MassDensity& mass_density, const Speed& speed);

  // Constructor. Constructs a length from a given Reynolds number, kinematic viscosity, and speed
  // using the definition of the Reynolds number.
  constexpr Length(const ReynoldsNumber& reynolds_number,
                   const KinematicViscosity& kinematic_viscosity, const Speed& speed);

  // Constructor. Constructs a length from a given energy and transport energy consumption using the
  // definition of transport energy consumption.
  constexpr Length(
      const Energy& energy, const TransportEnergyConsumption& transport_energy_consumption);

  // Destructor. Destroys this length.
  ~Length() noexcept = default;

  // Copy constructor. Constructs a length by copying another one.
  constexpr Length(const Length& other) = default;

  // Move constructor. Constructs a length by moving another one.
  constexpr Length(Length&& other) noexcept = default;

  // Copy assignment operator. Assigns this length by copying another one.
  constexpr Length& operator=(const Length& other) = default;

  // Move assignment operator. Assigns this length by moving another one.
  constexpr Length& operator=(Length&& other) noexcept = default;

  // Statically creates a length of zero.
  static constexpr Length Zero() {
    return Length{0.0};
  }

  // Statically creates a length with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Length Create(const double value) {
    return Length{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  constexpr Length operator+(const Length& length) const {
    return Length{value + length.value};
  }

  constexpr Length operator-(const Length& length) const {
    return Length{value - length.value};
  }

  constexpr Length operator*(const double number) const {
    return Length{value * number};
  }

  constexpr Area operator*(const Length& length) const;

  constexpr Volume operator*(const Area& area) const;

  constexpr Speed operator*(const Frequency& frequency) const;

  constexpr Position operator*(const Direction& direction) const;

  constexpr Energy operator*(const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr Length operator/(const double number) const {
    return Length{value / number};
  }

  constexpr Speed operator/(const Time& time) const;

  constexpr Time operator/(const Speed& speed) const;

  constexpr double operator/(const Length& length) const noexcept {
    return value / length.value;
  }

  constexpr void operator+=(const Length& length) noexcept {
    value += length.value;
  }

  constexpr void operator-=(const Length& length) noexcept {
    value -= length.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a length with a given value expressed in the standard length unit.
  explicit constexpr Length(const double value) : DimensionalScalar<Unit::Length>(value) {}

  friend class Displacement;

  friend class Position;
};

inline constexpr bool operator==(const Length& left, const Length& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Length& left, const Length& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Length& left, const Length& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Length& left, const Length& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Length& left, const Length& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Length& left, const Length& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Length& length) {
  stream << length.Print();
  return stream;
}

inline constexpr Length operator*(const double number, const Length& length) {
  return length * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Length> {
  inline size_t operator()(const PhQ::Length& length) const {
    return hash<double>()(length.Value());
  }
};

}  // namespace std

#endif  // PHQ_LENGTH_HPP
