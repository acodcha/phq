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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP

#include <functional>
#include <vector>

#include "../Base/Enumeration.hpp"
#include "../Dimension/Set.hpp"
#include "../UnitSystem.hpp"
#include "../Value/Dyad.hpp"

namespace PhQ {

template <typename Unit>
inline constexpr Unit StandardUnit;

template <typename Unit>
inline constexpr Dimension::Set Dimensions;

template <typename Unit, Unit NewUnit>
inline constexpr void ConvertValueFromStandard(double& value) noexcept;

template <typename Unit, Unit OldUnit>
inline constexpr void ConvertValueToStandard(double& value) noexcept;

template <typename Unit, Unit NewUnit>
inline constexpr void ConvertValuesFromStandard(
    double* values, const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConvertValueFromStandard<Unit, NewUnit>(*values);
  }
}

template <typename Unit, Unit OldUnit>
inline constexpr void ConvertValuesToStandard(double* values,
                                              const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConvertValueToStandard<Unit, OldUnit>(*values);
  }
}

template <typename Unit>
inline const std::map<
    Unit, std::function<void(double* values, const std::size_t size)>>
    ConversionsFromStandard;

template <typename Unit>
inline const std::map<
    Unit, std::function<void(double* values, const std::size_t size)>>
    ConversionsToStandard;

template <typename Unit>
void Convert(double& value, const Unit old_unit, const Unit new_unit) noexcept {
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&value, 1);
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&value, 1);
  }
}

template <typename Unit, std::size_t Size>
void Convert(std::array<double, Size>& values, const Unit old_unit,
             const Unit new_unit) noexcept {
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&values[0], Size);
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&values[0], Size);
  }
}

template <typename Unit>
void Convert(std::vector<double>& values, const Unit old_unit,
             const Unit new_unit) noexcept {
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&values[0],
                                                       values.size());
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&values[0],
                                                         values.size());
  }
}

template <typename Unit>
void Convert(Value::Vector& value, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 3>(value.Mutable_x_y_z(), old_unit, new_unit);
}

template <typename Unit>
void Convert(Value::SymmetricDyad& value, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 6>(value.Mutable_xx_xy_xz_yy_yz_zz(), old_unit, new_unit);
}

template <typename Unit>
void Convert(Value::Dyad& value, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 9>(value.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), old_unit,
                   new_unit);
}

template <typename Unit>
double ConvertCopy(const double value, const Unit old_unit,
                   const Unit new_unit) noexcept {
  double result{value};
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&result, 1);
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&result, 1);
  }
  return result;
}

template <typename Unit, std::size_t Size>
std::array<double, Size> ConvertCopy(const std::array<double, Size>& values,
                                     const Unit old_unit,
                                     const Unit new_unit) noexcept {
  std::array<double, Size> result{values};
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&result[0], Size);
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&result[0], Size);
  }
  return result;
}

template <typename Unit>
std::vector<double> ConvertCopy(const std::vector<double>& values,
                                const Unit old_unit,
                                const Unit new_unit) noexcept {
  std::vector<double> result{values};
  if (old_unit != StandardUnit<Unit>) {
    ConversionsToStandard<Unit>.find(old_unit)->second(&result[0],
                                                       result.size());
  }
  if (new_unit != StandardUnit<Unit>) {
    ConversionsFromStandard<Unit>.find(new_unit)->second(&result[0],
                                                         result.size());
  }
  return result;
}

template <typename Unit>
Value::Vector ConvertCopy(const Value::Vector& value, const Unit old_unit,
                          const Unit new_unit) noexcept {
  return Value::Vector{ConvertCopy<Unit, 3>(value.x_y_z(), old_unit, new_unit)};
}

template <typename Unit>
Value::SymmetricDyad ConvertCopy(const Value::SymmetricDyad& value,
                                 const Unit old_unit,
                                 const Unit new_unit) noexcept {
  return Value::SymmetricDyad{
      ConvertCopy<Unit, 6>(value.xx_xy_xz_yy_yz_zz(), old_unit, new_unit)};
}

template <typename Unit>
Value::Dyad ConvertCopy(const Value::Dyad& value, const Unit old_unit,
                        const Unit new_unit) noexcept {
  return Value::Dyad{ConvertCopy<Unit, 9>(value.xx_xy_xz_yx_yy_yz_zx_zy_zz(),
                                          old_unit, new_unit)};
}

template <typename Unit, Unit OldUnit, Unit NewUnit>
inline constexpr double StaticConvertCopy(const double value) noexcept {
  double result{value};
  if (OldUnit != StandardUnit<Unit>) {
    ConvertValueToStandard<Unit, OldUnit>(result);
  }
  if (NewUnit != StandardUnit<Unit>) {
    ConvertValueFromStandard<Unit, NewUnit>(result);
  }
  return result;
}

template <typename Unit, Unit OldUnit, Unit NewUnit, std::size_t Size>
inline constexpr std::array<double, Size> StaticConvertCopy(
    const std::array<double, Size>& values) noexcept {
  std::array<double, Size> result{values};
  if (OldUnit != StandardUnit<Unit>) {
    ConvertValuesToStandard<Unit, OldUnit>(&result[0], Size);
  }
  if (NewUnit != StandardUnit<Unit>) {
    ConvertValuesFromStandard<Unit, NewUnit>(&result[0], Size);
  }
  return result;
}

template <typename Unit, Unit OldUnit, Unit NewUnit>
inline constexpr Value::Vector StaticConvertCopy(
    const Value::Vector& value) noexcept {
  return Value::Vector{
      StaticConvertCopy<Unit, OldUnit, NewUnit, 3>(value.x_y_z())};
}

template <typename Unit, Unit OldUnit, Unit NewUnit>
inline constexpr Value::SymmetricDyad StaticConvertCopy(
    const Value::SymmetricDyad& value) noexcept {
  return Value::SymmetricDyad{
      StaticConvertCopy<Unit, OldUnit, NewUnit, 6>(value.xx_xy_xz_yy_yz_zz())};
}

template <typename Unit, Unit OldUnit, Unit NewUnit>
inline constexpr Value::Dyad StaticConvertCopy(
    const Value::Dyad& value) noexcept {
  return Value::Dyad{StaticConvertCopy<Unit, OldUnit, NewUnit, 9>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP
