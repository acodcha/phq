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

#ifndef PHQ_UNIT_ENERGY_FLUX_HPP
#define PHQ_UNIT_ENERGY_FLUX_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Energy flux units.
enum class EnergyFlux : int8_t {
  // Watt per square metre (W/m^2) energy flux unit.
  WattPerSquareMetre,

  // Nanowatt per square millimetre (nW/mm^2) energy flux unit.
  NanowattPerSquareMillimetre,

  // Foot-pound per square foot per second (ft·lbf/ft^2/s) energy flux unit.
  FootPoundPerSquareFootPerSecond,

  // Inch-pound per square inch per second (in·lbf/in^2/s) energy flux unit.
  InchPoundPerSquareInchPerSecond,
};

}  // namespace Unit

// Standard energy flux unit: watt per square metre (W/m^2).
template <>
inline constexpr const Unit::EnergyFlux Standard<Unit::EnergyFlux>{
    Unit::EnergyFlux::WattPerSquareMetre};

// Physical dimension set of energy flux units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::EnergyFlux>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::EnergyFlux unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::EnergyFlux> ConsistentUnits<Unit::EnergyFlux>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::EnergyFlux::WattPerSquareMetre             },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {UnitSystem::FootPoundSecondRankine,     Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

template <>
inline const std::map<Unit::EnergyFlux, UnitSystem> RelatedUnitSystems<Unit::EnergyFlux>{
    {Unit::EnergyFlux::WattPerSquareMetre,              UnitSystem::MetreKilogramSecondKelvin },
    {Unit::EnergyFlux::NanowattPerSquareMillimetre,     UnitSystem::MillimetreGramSecondKelvin},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, UnitSystem::FootPoundSecondRankine    },
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::EnergyFlux, std::string_view> Abbreviations<Unit::EnergyFlux>{
    {Unit::EnergyFlux::WattPerSquareMetre,              "W/m^2"        },
    {Unit::EnergyFlux::NanowattPerSquareMillimetre,     "nW/mm^2"      },
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, "ft·lbf/ft^2/s"},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, "in·lbf/in^2/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::EnergyFlux> Spellings<Unit::EnergyFlux>{
    {"W/m^2",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"W/m2",            Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2·s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2*s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2·s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2*s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m^2/s",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m2/s",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m·s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m*s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/m/s",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s^3",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s3",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"nW/mm^2",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nW/mm2",          Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2·s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2*s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2·s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2*s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm^2/s",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm2/s",        Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s^3",           Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s3",            Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"ft·lbf/(ft^2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/(ft2·s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft^2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft2*s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft·s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft*s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/ft/s",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s^3",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s3",         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"in·lbf/(in^2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/(in2·s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in^2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in2*s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in·s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in*s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/in/s",        Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s^3",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s3",       Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::NanowattPerSquareMillimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::NanowattPerSquareMillimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.0254L);
}

template <typename Number>
inline const std::map<Unit::EnergyFlux, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::EnergyFlux, Number>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         Conversions<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::FromStandard<Number>},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::NanowattPerSquareMillimetre>::FromStandard<Number>                     },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::FromStandard<Number>                 },
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::FromStandard<Number>                 },
};

template <typename Number>
inline const std::map<Unit::EnergyFlux,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::EnergyFlux, Number>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         Conversions<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::ToStandard<Number>},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::NanowattPerSquareMillimetre>::ToStandard<Number>                     },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::ToStandard<Number>                 },
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::ToStandard<Number>                 },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ENERGY_FLUX_HPP
