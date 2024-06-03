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

#ifndef PHQ_STATIC_KINEMATIC_PRESSURE_HPP
#define PHQ_STATIC_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename NumericType>
class DynamicKinematicPressure;

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename NumericType>
class TotalKinematicPressure;

/// \brief Static kinematic pressure, which is static pressure divided by mass density; see
/// PhQ::StaticPressure and PhQ::MassDensity.
template <typename NumericType = double>
class StaticKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, NumericType> {
public:
  /// \brief Default constructor. Constructs a static kinematic pressure with an uninitialized
  /// value.
  StaticKinematicPressure() = default;

  /// \brief Constructor. Constructs a static kinematic pressure with a given value expressed in a
  /// given specific energy unit.
  StaticKinematicPressure(const NumericType value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a static kinematic pressure from a given total kinematic
  /// pressure and dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr StaticKinematicPressure(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure,
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure);

  /// \brief Constructor. Constructs a static kinematic pressure from a given static pressure and
  /// mass density using the definition of static kinematic pressure.
  constexpr StaticKinematicPressure(const StaticPressure<NumericType>& static_pressure,
                                    const MassDensity<NumericType>& mass_density)
    : StaticKinematicPressure<NumericType>(static_pressure.Value() / mass_density.Value()) {}

  /// \brief Destructor. Destroys this static kinematic pressure.
  ~StaticKinematicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure(const StaticKinematicPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a static kinematic pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr StaticKinematicPressure(const StaticKinematicPressure<OtherNumericType>& other)
    : StaticKinematicPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure(
      StaticKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this static kinematic pressure by copying another
  /// one.
  constexpr StaticKinematicPressure<NumericType>& operator=(
      const StaticKinematicPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this static kinematic pressure by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr StaticKinematicPressure<NumericType>& operator=(
      const StaticKinematicPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure<NumericType>& operator=(
      StaticKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a static kinematic pressure of zero.
  [[nodiscard]] static constexpr StaticKinematicPressure<NumericType> Zero() {
    return StaticKinematicPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a static kinematic pressure with a given value expressed in a given
  /// specific energy unit.
  template <Unit::SpecificEnergy Unit>
  [[nodiscard]] static constexpr StaticKinematicPressure<NumericType> Create(
      const NumericType value) {
    return StaticKinematicPressure<NumericType>{
        ConvertStatically<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure<NumericType> operator+(
      const StaticKinematicPressure<NumericType>& other) const {
    return StaticKinematicPressure<NumericType>{this->value + other.value};
  }

  constexpr TotalKinematicPressure<NumericType> operator+(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const;

  constexpr StaticKinematicPressure<NumericType> operator-(
      const StaticKinematicPressure<NumericType>& other) const {
    return StaticKinematicPressure<NumericType>{this->value - other.value};
  }

  constexpr StaticKinematicPressure<NumericType> operator*(const NumericType number) const {
    return StaticKinematicPressure<NumericType>{this->value * number};
  }

  constexpr StaticPressure<NumericType> operator*(
      const MassDensity<NumericType>& mass_density) const {
    return StaticPressure<NumericType>{mass_density, *this};
  }

  constexpr StaticKinematicPressure<NumericType> operator/(const NumericType number) const {
    return StaticKinematicPressure<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const StaticKinematicPressure<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const StaticKinematicPressure<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const StaticKinematicPressure<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a static kinematic pressure with a given value expressed in the
  /// standard specific energy unit.
  explicit constexpr StaticKinematicPressure(const NumericType value)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const StaticKinematicPressure<NumericType>& left,
                                 const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const StaticKinematicPressure<NumericType>& left,
                                 const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const StaticKinematicPressure<NumericType>& left,
                                const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const StaticKinematicPressure<NumericType>& left,
                                const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const StaticKinematicPressure<NumericType>& left,
                                 const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const StaticKinematicPressure<NumericType>& left,
                                 const StaticKinematicPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const StaticKinematicPressure<NumericType>& static_kinematic_pressure) {
  stream << static_kinematic_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr StaticKinematicPressure<NumericType> operator*(
    const NumericType number,
    const StaticKinematicPressure<NumericType>& static_kinematic_pressure) {
  return static_kinematic_pressure * number;
}

template <typename NumericType>
inline constexpr StaticPressure<NumericType>::StaticPressure(
    const MassDensity<NumericType>& mass_density,
    const StaticKinematicPressure<NumericType>& static_kinematic_pressure)
  : StaticPressure<NumericType>(mass_density.Value() * static_kinematic_pressure.Value()) {}

template <typename NumericType>
inline constexpr StaticKinematicPressure<NumericType> StaticPressure<NumericType>::operator/(
    const MassDensity<NumericType>& mass_density) const {
  return StaticKinematicPressure<NumericType>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::StaticKinematicPressure<NumericType>> {
  inline size_t operator()(
      const PhQ::StaticKinematicPressure<NumericType>& static_kinematic_pressure) const {
    return hash<NumericType>()(static_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_KINEMATIC_PRESSURE_HPP
