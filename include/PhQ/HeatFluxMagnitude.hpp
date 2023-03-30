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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP

#include "TemperatureGradientMagnitude.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration for class HeatFluxMagnitude.
class HeatFlux;

class HeatFluxMagnitude : public DimensionalScalarQuantity<Unit::EnergyFlux> {
public:
  constexpr HeatFluxMagnitude() noexcept
      : DimensionalScalarQuantity<Unit::EnergyFlux>() {}

  HeatFluxMagnitude(const double value, const Unit::EnergyFlux unit) noexcept
      : DimensionalScalarQuantity<Unit::EnergyFlux>(value, unit) {}

  constexpr HeatFluxMagnitude(
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const TemperatureGradientMagnitude&
          temperature_gradient_magnitude) noexcept
      : HeatFluxMagnitude(-thermal_conductivity_scalar.Value() *
                          temperature_gradient_magnitude.Value()) {}

  constexpr HeatFluxMagnitude(const HeatFlux& heat_flux) noexcept;

  template <Unit::EnergyFlux Unit>
  static constexpr HeatFluxMagnitude Create(const double value) noexcept {
    return HeatFluxMagnitude{
        StaticConvertCopy<Unit::EnergyFlux, Unit,
                          StandardUnit<Unit::EnergyFlux>>(value)};
  }

  inline constexpr HeatFluxMagnitude operator+(
      const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return HeatFluxMagnitude{value_ + heat_flux_magnitude.value_};
  }

  inline constexpr HeatFluxMagnitude operator-(
      const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return HeatFluxMagnitude{value_ - heat_flux_magnitude.value_};
  }

  inline constexpr HeatFluxMagnitude operator*(
      const double number) const noexcept {
    return HeatFluxMagnitude{value_ * number};
  }

  inline constexpr HeatFlux operator*(
      const Direction& direction) const noexcept;

  inline constexpr HeatFluxMagnitude operator/(
      const double number) const noexcept {
    return HeatFluxMagnitude{value_ / number};
  }

  inline constexpr void operator+=(
      const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ += heat_flux_magnitude.value_;
  }

  inline constexpr void operator-=(
      const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ -= heat_flux_magnitude.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr HeatFluxMagnitude(const double value) noexcept
      : DimensionalScalarQuantity<Unit::EnergyFlux>(value) {}
};

inline constexpr bool operator==(const HeatFluxMagnitude& left,
                                 const HeatFluxMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const HeatFluxMagnitude& left,
                                 const HeatFluxMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const HeatFluxMagnitude& left,
                                const HeatFluxMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const HeatFluxMagnitude& left,
                                const HeatFluxMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const HeatFluxMagnitude& left,
                                 const HeatFluxMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const HeatFluxMagnitude& left,
                                 const HeatFluxMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
  stream << heat_flux_magnitude.Print();
  return stream;
}

inline constexpr HeatFluxMagnitude operator*(
    const double number,
    const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
  return heat_flux_magnitude * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::HeatFluxMagnitude> {
  size_t operator()(const PhQ::HeatFluxMagnitude& heat_flux_magnitude) const {
    return hash<double>()(heat_flux_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_HEAT_FLUX_MAGNITUDE_HPP
