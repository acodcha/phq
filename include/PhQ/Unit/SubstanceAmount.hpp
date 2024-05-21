// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#ifndef PHQ_UNIT_SUBSTANCE_AMOUNT_HPP
#define PHQ_UNIT_SUBSTANCE_AMOUNT_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/LuminousIntensity.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

/// \brief Amount of substance units.
enum class SubstanceAmount : int8_t {
  /// \brief Mole (mol) substance amount unit.
  Mole,

  /// \brief Kilomole (kmol) substance amount unit.
  Kilomole,

  /// \brief Megamole (Mmol) substance amount unit.
  Megamole,

  /// \brief Gigamole (Gmol) substance amount unit.
  Gigamole,

  /// \brief Particles (particles) substance amount unit.
  Particles,
};

}  // namespace Unit

/// \brief Standard amount of substance unit: mole (mol).
template <>
inline constexpr const Unit::SubstanceAmount Standard<Unit::SubstanceAmount>{
    Unit::SubstanceAmount::Mole};

/// \brief Physical dimension set of amount of substance units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SubstanceAmount>{
    Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{1}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SubstanceAmount unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SubstanceAmount> ConsistentUnits<Unit::SubstanceAmount>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SubstanceAmount::Mole},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SubstanceAmount::Mole},
    {UnitSystem::FootPoundSecondRankine,     Unit::SubstanceAmount::Mole},
    {UnitSystem::InchPoundSecondRankine,     Unit::SubstanceAmount::Mole},
};

template <>
inline const std::map<Unit::SubstanceAmount, UnitSystem>
    RelatedUnitSystems<Unit::SubstanceAmount>{};

template <>
inline const std::map<Unit::SubstanceAmount, std::string_view> Abbreviations<Unit::SubstanceAmount>{
    {Unit::SubstanceAmount::Mole,      "mol"      },
    {Unit::SubstanceAmount::Kilomole,  "kmol"     },
    {Unit::SubstanceAmount::Megamole,  "Mmol"     },
    {Unit::SubstanceAmount::Gigamole,  "Gmol"     },
    {Unit::SubstanceAmount::Particles, "particles"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SubstanceAmount>
    Spellings<Unit::SubstanceAmount>{
        {"mol",       Unit::SubstanceAmount::Mole     },
        {"kmol",      Unit::SubstanceAmount::Kilomole },
        {"Mmol",      Unit::SubstanceAmount::Megamole },
        {"Gmol",      Unit::SubstanceAmount::Gigamole },
        {"particles", Unit::SubstanceAmount::Particles},
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(6.02214076E23L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(6.02214076E23L);
}

template <typename Number>
inline const std::map<Unit::SubstanceAmount,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SubstanceAmount, Number>{
        {Unit::SubstanceAmount::Mole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>::FromStandard<Number>    },
        {Unit::SubstanceAmount::Kilomole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>::FromStandard<Number>},
        {Unit::SubstanceAmount::Megamole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>::FromStandard<Number>},
        {Unit::SubstanceAmount::Gigamole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>::FromStandard<Number>},
        {Unit::SubstanceAmount::Particles,
         Conversions<Unit::SubstanceAmount,
         Unit::SubstanceAmount::Particles>::FromStandard<Number>                                  },
};

template <typename Number>
inline const std::map<Unit::SubstanceAmount,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SubstanceAmount, Number>{
        {Unit::SubstanceAmount::Mole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>::ToStandard<Number>     },
        {Unit::SubstanceAmount::Kilomole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>::ToStandard<Number> },
        {Unit::SubstanceAmount::Megamole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>::ToStandard<Number> },
        {Unit::SubstanceAmount::Gigamole,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>::ToStandard<Number> },
        {Unit::SubstanceAmount::Particles,
         Conversions<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SUBSTANCE_AMOUNT_HPP
