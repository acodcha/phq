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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP

#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations for class StrainScalar.
class LinearThermalExpansionCoefficient;
class TemperatureDifference;

class StrainScalar : public DimensionlessScalarQuantity {
public:
  constexpr StrainScalar() noexcept : DimensionlessScalarQuantity() {}

  explicit constexpr StrainScalar(const double value) noexcept
      : DimensionlessScalarQuantity(value) {}

  constexpr StrainScalar(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient,
      const TemperatureDifference& temperature_difference) noexcept;

  inline StrainScalar operator+(
      const StrainScalar& strain_scalar) const noexcept {
    return StrainScalar{value_ + strain_scalar.value_};
  }

  inline StrainScalar operator-(
      const StrainScalar& strain_scalar) const noexcept {
    return StrainScalar{value_ - strain_scalar.value_};
  }

  inline StrainScalar operator*(const double number) const noexcept {
    return StrainScalar{value_ * number};
  }

  inline StrainScalar operator/(const double number) const noexcept {
    return StrainScalar{value_ / number};
  }

  inline constexpr void operator+=(const StrainScalar& strain_scalar) noexcept {
    value_ += strain_scalar.value_;
  }

  inline constexpr void operator-=(const StrainScalar& strain_scalar) noexcept {
    value_ -= strain_scalar.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(const StrainScalar& left,
                                 const StrainScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const StrainScalar& left,
                                 const StrainScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StrainScalar& left,
                                const StrainScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StrainScalar& left,
                                const StrainScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const StrainScalar& left,
                                 const StrainScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const StrainScalar& left,
                                 const StrainScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const StrainScalar& strain_scalar) noexcept {
  stream << strain_scalar.Print();
  return stream;
}

inline StrainScalar operator+(const double number,
                              const StrainScalar& strain_scalar) noexcept {
  return StrainScalar{number + strain_scalar.Value()};
}

inline StrainScalar operator-(const double number,
                              const StrainScalar& strain_scalar) noexcept {
  return StrainScalar{number - strain_scalar.Value()};
}

inline StrainScalar operator*(const double number,
                              const StrainScalar& strain_scalar) noexcept {
  return StrainScalar{number * strain_scalar.Value()};
}

inline constexpr double operator/(const double number,
                                  const StrainScalar& strain_scalar) noexcept {
  return number / strain_scalar.Value();
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StrainScalar> {
  size_t operator()(const PhQ::StrainScalar& strain_scalar) const {
    return hash<double>()(strain_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STRAIN_SCALAR_HPP
