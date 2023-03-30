// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_VISCOSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_VISCOSITY_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declarations for class KinematicViscosity.
class DynamicViscosity;
class Length;
class MassDensity;
class PrandtlNumber;
class ReynoldsNumber;
class Speed;
class ThermalDiffusivity;

class KinematicViscosity : public DimensionalScalarQuantity<Unit::Diffusivity> {
public:
  constexpr KinematicViscosity() noexcept
      : DimensionalScalarQuantity<Unit::Diffusivity>() {}

  KinematicViscosity(const double value, const Unit::Diffusivity unit) noexcept
      : DimensionalScalarQuantity<Unit::Diffusivity>(value, unit) {}

  constexpr KinematicViscosity(const DynamicViscosity& dynamic_viscosity,
                               const MassDensity& mass_density) noexcept;

  constexpr KinematicViscosity(const ReynoldsNumber& reynolds_number,
                               const Speed& speed,
                               const Length& length) noexcept;

  constexpr KinematicViscosity(
      const PrandtlNumber& prandtl_number,
      const ThermalDiffusivity& thermal_diffusivity) noexcept;

  template <Unit::Diffusivity Unit>
  static constexpr KinematicViscosity Create(const double value) noexcept {
    return KinematicViscosity{
        StaticConvertCopy<Unit::Diffusivity, Unit,
                          StandardUnit<Unit::Diffusivity>>(value)};
  }

  inline constexpr KinematicViscosity operator+(
      const KinematicViscosity& kinematic_viscosity) const noexcept {
    return KinematicViscosity{value_ + kinematic_viscosity.value_};
  }

  inline constexpr KinematicViscosity operator-(
      const KinematicViscosity& kinematic_viscosity) const noexcept {
    return KinematicViscosity{value_ - kinematic_viscosity.value_};
  }

  inline constexpr KinematicViscosity operator*(
      const double number) const noexcept {
    return KinematicViscosity{value_ * number};
  }

  inline constexpr DynamicViscosity operator*(
      const MassDensity& mass_density) const noexcept;

  inline constexpr KinematicViscosity operator/(
      const double number) const noexcept {
    return KinematicViscosity{value_ / number};
  }

  inline constexpr void operator+=(
      const KinematicViscosity& kinematic_viscosity) noexcept {
    value_ += kinematic_viscosity.value_;
  }

  inline constexpr void operator-=(
      const KinematicViscosity& kinematic_viscosity) noexcept {
    value_ -= kinematic_viscosity.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr KinematicViscosity(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Diffusivity>(value) {}
};

inline constexpr bool operator==(const KinematicViscosity& left,
                                 const KinematicViscosity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const KinematicViscosity& left,
                                 const KinematicViscosity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const KinematicViscosity& left,
                                const KinematicViscosity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const KinematicViscosity& left,
                                const KinematicViscosity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const KinematicViscosity& left,
                                 const KinematicViscosity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const KinematicViscosity& left,
                                 const KinematicViscosity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const KinematicViscosity& kinematic_viscosity) noexcept {
  stream << kinematic_viscosity.Print();
  return stream;
}

inline constexpr KinematicViscosity operator*(
    const double number,
    const KinematicViscosity& kinematic_viscosity) noexcept {
  return kinematic_viscosity * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::KinematicViscosity> {
  size_t operator()(const PhQ::KinematicViscosity& kinematic_viscosity) const {
    return hash<double>()(kinematic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_VISCOSITY_HPP
