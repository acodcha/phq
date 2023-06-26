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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Frequency : int_least8_t {
  Hertz,
  Kilohertz,
  Megahertz,
  Gigahertz,
};

}  // namespace Unit

template<> inline constexpr const Unit::Frequency StandardUnit<Unit::Frequency>{
    Unit::Frequency::Hertz};

template<> inline constexpr const Dimension::Set Dimensions<Unit::Frequency>{
    Dimension::Set{Dimension::Time{-1}}};

template<> inline const std::map<UnitSystem, Unit::Frequency>
    ConsistentUnits<Unit::Frequency>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::Frequency::Hertz},
        {UnitSystem::MillimetreGramSecondKelvin, Unit::Frequency::Hertz},
        {UnitSystem::FootPoundSecondRankine,     Unit::Frequency::Hertz},
        {UnitSystem::InchPoundSecondRankine,     Unit::Frequency::Hertz},
};

template<> inline const std::map<Unit::Frequency, UnitSystem>
    RelatedUnitSystems<Unit::Frequency>{};

template<> inline const std::map<Unit::Frequency, std::string_view>
    Abbreviations<Unit::Frequency>{
        {Unit::Frequency::Hertz,     "Hz" },
        {Unit::Frequency::Kilohertz, "kHz"},
        {Unit::Frequency::Megahertz, "MHz"},
        {Unit::Frequency::Gigahertz, "GHz"},
};

template<> inline const std::unordered_map<std::string_view, Unit::Frequency>
    Spellings<Unit::Frequency>{
        {"Hz",  Unit::Frequency::Hertz    },
        {"1/s", Unit::Frequency::Hertz    },
        {"/s",  Unit::Frequency::Hertz    },
        {"kHz", Unit::Frequency::Kilohertz},
        {"MHz", Unit::Frequency::Megahertz},
        {"GHz", Unit::Frequency::Gigahertz},
};

namespace Internal {

template<> inline constexpr void
ConversionFromStandard<Unit::Frequency, Unit::Frequency::Hertz>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::Frequency, Unit::Frequency::Kilohertz>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Frequency, Unit::Frequency::Megahertz>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Frequency, Unit::Frequency::Gigahertz>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Frequency, Unit::Frequency::Hertz>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::Frequency, Unit::Frequency::Kilohertz>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Frequency, Unit::Frequency::Megahertz>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Frequency, Unit::Frequency::Gigahertz>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline const std::map<
    Unit::Frequency, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Frequency>{
        {Unit::Frequency::Hertz,
         ConversionsFromStandard<Unit::Frequency, Unit::Frequency::Hertz>    },
        {Unit::Frequency::Kilohertz,
         ConversionsFromStandard<Unit::Frequency, Unit::Frequency::Kilohertz>},
        {Unit::Frequency::Megahertz,
         ConversionsFromStandard<Unit::Frequency, Unit::Frequency::Megahertz>},
        {Unit::Frequency::Gigahertz,
         ConversionsFromStandard<Unit::Frequency, Unit::Frequency::Gigahertz>},
};

template<> inline const std::map<
    Unit::Frequency,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Frequency>{
        {Unit::Frequency::Hertz,
         ConversionsToStandard<Unit::Frequency, Unit::Frequency::Hertz>    },
        {Unit::Frequency::Kilohertz,
         ConversionsToStandard<Unit::Frequency, Unit::Frequency::Kilohertz>},
        {Unit::Frequency::Megahertz,
         ConversionsToStandard<Unit::Frequency, Unit::Frequency::Megahertz>},
        {Unit::Frequency::Gigahertz,
         ConversionsToStandard<Unit::Frequency, Unit::Frequency::Gigahertz>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP
