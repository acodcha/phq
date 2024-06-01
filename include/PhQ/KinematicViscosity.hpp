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

#ifndef PHQ_KINEMATIC_VISCOSITY_HPP
#define PHQ_KINEMATIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class PrandtlNumber;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class ReynoldsNumber;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class Speed;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename NumericType>
class ThermalDiffusivity;

/// \brief Kinematic viscosity, also known as molecular kinematic viscosity. Defined as dynamic
/// viscosity divided by mass density; see PhQ::DynamicViscosity and PhQ::MassDensity. Also appears
/// in the definition of the Prandtl number; see PhQ::PrandtlNumber and
/// PhQ::ThermalDiffusivity.
template <typename NumericType = double>
class KinematicViscosity : public DimensionalScalar<Unit::Diffusivity, NumericType> {
public:
  /// \brief Default constructor. Constructs a kinematic viscosity with an uninitialized value.
  KinematicViscosity() = default;

  /// \brief Constructor. Constructs a kinematic viscosity with a given value expressed in a given
  /// diffusivity unit.
  KinematicViscosity(const NumericType value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a kinematic viscosity from a given dynamic viscosity and mass
  /// density using the definition of kinematic viscosity.
  constexpr KinematicViscosity(const DynamicViscosity<NumericType>& dynamic_viscosity,
                               const MassDensity<NumericType>& mass_density);

  /// \brief Constructor. Constructs a kinematic viscosity from a given speed, length, and Reynolds
  /// number using the definition of the Reynolds number.
  constexpr KinematicViscosity(const Speed<NumericType>& speed, const Length<NumericType>& length,
                               const ReynoldsNumber<NumericType>& reynolds_number);

  /// \brief Constructor. Constructs a kinematic viscosity from a given Prandtl number and thermal
  /// diffusivity using the definition of Prandtl number.
  constexpr KinematicViscosity(const PrandtlNumber<NumericType>& prandtl_number,
                               const ThermalDiffusivity<NumericType>& thermal_diffusivity);

  /// \brief Destructor. Destroys this kinematic viscosity.
  ~KinematicViscosity() noexcept = default;

  /// \brief Copy constructor. Constructs a kinematic viscosity by copying another one.
  constexpr KinematicViscosity(const KinematicViscosity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a kinematic viscosity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr KinematicViscosity(const KinematicViscosity<OtherNumericType>& other)
    : KinematicViscosity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a kinematic viscosity by moving another one.
  constexpr KinematicViscosity(KinematicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  constexpr KinematicViscosity<NumericType>& operator=(
      const KinematicViscosity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  template <typename OtherNumericType>
  constexpr KinematicViscosity<NumericType>& operator=(
      const KinematicViscosity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this kinematic viscosity by moving another one.
  constexpr KinematicViscosity<NumericType>& operator=(
      KinematicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a kinematic viscosity of zero.
  static constexpr KinematicViscosity<NumericType> Zero() {
    return KinematicViscosity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a kinematic viscosity with a given value expressed in a given
  /// diffusivity unit.
  template <Unit::Diffusivity Unit>
  static constexpr KinematicViscosity<NumericType> Create(const NumericType value) {
    return KinematicViscosity<NumericType>{
        ConvertStatically<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr KinematicViscosity<NumericType> operator+(
      const KinematicViscosity<NumericType>& kinematic_viscosity) const {
    return KinematicViscosity<NumericType>{this->value + kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<NumericType> operator-(
      const KinematicViscosity<NumericType>& kinematic_viscosity) const {
    return KinematicViscosity<NumericType>{this->value - kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<NumericType> operator*(const NumericType number) const {
    return KinematicViscosity<NumericType>{this->value * number};
  }

  constexpr DynamicViscosity<NumericType> operator*(
      const MassDensity<NumericType>& mass_density) const;

  constexpr KinematicViscosity<NumericType> operator/(const NumericType number) const {
    return KinematicViscosity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const KinematicViscosity<NumericType>& kinematic_viscosity) const noexcept {
    return this->value / kinematic_viscosity.value;
  }

  constexpr void operator+=(const KinematicViscosity<NumericType>& kinematic_viscosity) noexcept {
    this->value += kinematic_viscosity.value;
  }

  constexpr void operator-=(const KinematicViscosity<NumericType>& kinematic_viscosity) noexcept {
    this->value -= kinematic_viscosity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a kinematic viscosity with a given value expressed in the
  /// standard diffusivity unit.
  explicit constexpr KinematicViscosity(const NumericType value)
    : DimensionalScalar<Unit::Diffusivity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const KinematicViscosity<NumericType>& left,
                                 const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const KinematicViscosity<NumericType>& left,
                                 const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const KinematicViscosity<NumericType>& left,
                                const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const KinematicViscosity<NumericType>& left,
                                const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const KinematicViscosity<NumericType>& left,
                                 const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const KinematicViscosity<NumericType>& left,
                                 const KinematicViscosity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const KinematicViscosity<NumericType>& kinematic_viscosity) {
  stream << kinematic_viscosity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr KinematicViscosity<NumericType> operator*(
    const NumericType number, const KinematicViscosity<NumericType>& kinematic_viscosity) {
  return kinematic_viscosity * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::KinematicViscosity<NumericType>> {
  inline size_t operator()(const PhQ::KinematicViscosity<NumericType>& kinematic_viscosity) const {
    return hash<NumericType>()(kinematic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_KINEMATIC_VISCOSITY_HPP
