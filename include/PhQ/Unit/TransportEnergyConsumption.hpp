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

#ifndef PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP
#define PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP

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

// Energy consumption in transport units.
enum class TransportEnergyConsumption : int8_t {
  // Joule per mile (J/mi) transport energy consumption unit.
  JoulePerMile,

  // Joule per kilometre (J/km) transport energy consumption unit.
  JoulePerKilometre,

  // Joule per metre (J/m) transport energy consumption unit.
  JoulePerMetre,

  // Nanojoule per millimetre (nJ/mm) transport energy consumption unit.
  NanojoulePerMillimetre,

  // Kilojoule per mile (kJ/mi) transport energy consumption unit.
  KilojoulePerMile,

  // Watt-minute per mile (W·min/mi) transport energy consumption unit.
  WattMinutePerMile,

  // Watt-hour per mile (W·hr/mi) transport energy consumption unit.
  WattHourPerMile,

  // Watt-minute per kilometre (W·min/km) transport energy consumption unit.
  WattMinutePerKilometre,

  // Watt-hour per kilometre (W·hr/km) transport energy consumption unit.
  WattHourPerKilometre,

  // Watt-minute per metre (W·min/m) transport energy consumption unit.
  WattMinutePerMetre,

  // Watt-hour per metre (W·hr/m) transport energy consumption unit.
  WattHourPerMetre,

  // Kilowatt-minute per mile (kW·min/mi) transport energy consumption unit.
  KilowattMinutePerMile,

  // Kilowatt-hour per mile (kW·hr/mi) transport energy consumption unit.
  KilowattHourPerMile,

  // Kilowatt-minute per kilometre (kW·min/km) transport energy consumption
  // unit.
  KilowattMinutePerKilometre,

  // Kilowatt-hour per kilometre (kW·hr/km) transport energy consumption unit.
  KilowattHourPerKilometre,

  // Kilowatt-minute per metre (kW·min/m) transport energy consumption unit.
  KilowattMinutePerMetre,

  // Kilowatt-hour per metre (kW·hr/m) transport energy consumption unit.
  KilowattHourPerMetre,

  // Foot-pound per foot (ft·lbf/ft) transport energy consumption unit.
  FootPoundPerFoot,

  // Inch-pound per inch (in·lbf/in) transport energy consumption unit.
  InchPoundPerInch,
};

}  // namespace Unit

// Standard transport energy consumption unit: joule per metre (J/m).
template <>
inline constexpr const Unit::TransportEnergyConsumption Standard<Unit::TransportEnergyConsumption>{
    Unit::TransportEnergyConsumption::JoulePerMetre};

// Physical dimension set of transport energy consumption units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TransportEnergyConsumption>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::TransportEnergyConsumption unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::TransportEnergyConsumption>
    ConsistentUnits<Unit::TransportEnergyConsumption>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::TransportEnergyConsumption::JoulePerMetre   },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre                                  },
        {UnitSystem::FootPoundSecondRankine,     Unit::TransportEnergyConsumption::FootPoundPerFoot},
        {UnitSystem::InchPoundSecondRankine,     Unit::TransportEnergyConsumption::InchPoundPerInch},
};

template <>
inline const std::map<Unit::TransportEnergyConsumption, UnitSystem>
    RelatedUnitSystems<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMetre,          UnitSystem::MetreKilogramSecondKelvin},
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         UnitSystem::MillimetreGramSecondKelvin                                                         },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,       UnitSystem::FootPoundSecondRankine   },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,       UnitSystem::InchPoundSecondRankine   },
};

template <>
inline const std::map<Unit::TransportEnergyConsumption, std::string_view>
    Abbreviations<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMile,               "J/mi"     },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,          "J/km"     },
        {Unit::TransportEnergyConsumption::JoulePerMetre,              "J/m"      },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,     "nJ/mm"    },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,           "kJ/mi"    },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,          "W·min/mi" },
        {Unit::TransportEnergyConsumption::WattHourPerMile,            "W·hr/mi"  },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,     "W·min/km" },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,       "W·hr/km"  },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,         "W·min/m"  },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,           "W·hr/m"   },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,      "kW·min/mi"},
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,        "kW·hr/mi" },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre, "kW·min/km"},
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,   "kW·hr/km" },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,     "kW·min/m" },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,       "kW·hr/m"  },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,           "ft·lbf/ft"},
        {Unit::TransportEnergyConsumption::InchPoundPerInch,           "in·lbf/in"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::TransportEnergyConsumption>
    Spellings<Unit::TransportEnergyConsumption>{
        {"J/mi",      Unit::TransportEnergyConsumption::JoulePerMile              },
        {"J/km",      Unit::TransportEnergyConsumption::JoulePerKilometre         },
        {"J/m",       Unit::TransportEnergyConsumption::JoulePerMetre             },
        {"nJ/mm",     Unit::TransportEnergyConsumption::NanojoulePerMillimetre    },
        {"kJ/mi",     Unit::TransportEnergyConsumption::KilojoulePerMile          },
        {"W·min/mi",  Unit::TransportEnergyConsumption::WattMinutePerMile         },
        {"W*min/mi",  Unit::TransportEnergyConsumption::WattMinutePerMile         },
        {"W·hr/mi",   Unit::TransportEnergyConsumption::WattHourPerMile           },
        {"W*hr/mi",   Unit::TransportEnergyConsumption::WattHourPerMile           },
        {"W·min/km",  Unit::TransportEnergyConsumption::WattMinutePerKilometre    },
        {"W*min/km",  Unit::TransportEnergyConsumption::WattMinutePerKilometre    },
        {"W·hr/km",   Unit::TransportEnergyConsumption::WattHourPerKilometre      },
        {"W*hr/km",   Unit::TransportEnergyConsumption::WattHourPerKilometre      },
        {"W·min/m",   Unit::TransportEnergyConsumption::WattMinutePerMetre        },
        {"W*min/m",   Unit::TransportEnergyConsumption::WattMinutePerMetre        },
        {"W·hr/m",    Unit::TransportEnergyConsumption::WattHourPerMetre          },
        {"W*hr/m",    Unit::TransportEnergyConsumption::WattHourPerMetre          },
        {"kW·min/mi", Unit::TransportEnergyConsumption::KilowattMinutePerMile     },
        {"kW*min/mi", Unit::TransportEnergyConsumption::KilowattMinutePerMile     },
        {"kW·hr/mi",  Unit::TransportEnergyConsumption::KilowattHourPerMile       },
        {"kW*hr/mi",  Unit::TransportEnergyConsumption::KilowattHourPerMile       },
        {"kW·min/km", Unit::TransportEnergyConsumption::KilowattMinutePerKilometre},
        {"kW*min/km", Unit::TransportEnergyConsumption::KilowattMinutePerKilometre},
        {"kW·hr/km",  Unit::TransportEnergyConsumption::KilowattHourPerKilometre  },
        {"kW*hr/km",  Unit::TransportEnergyConsumption::KilowattHourPerKilometre  },
        {"kW·min/m",  Unit::TransportEnergyConsumption::KilowattMinutePerMetre    },
        {"kW*min/m",  Unit::TransportEnergyConsumption::KilowattMinutePerMetre    },
        {"kW·hr/m",   Unit::TransportEnergyConsumption::KilowattHourPerMetre      },
        {"kW*hr/m",   Unit::TransportEnergyConsumption::KilowattHourPerMetre      },
        {"ft·lbf/ft", Unit::TransportEnergyConsumption::FootPoundPerFoot          },
        {"ft·lb/ft",  Unit::TransportEnergyConsumption::FootPoundPerFoot          },
        {"in·lbf/in", Unit::TransportEnergyConsumption::InchPoundPerInch          },
        {"in·lb/in",  Unit::TransportEnergyConsumption::InchPoundPerInch          },
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::JoulePerMile>::FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::JoulePerMile>::ToStandard(Number& value) noexcept {
  value /= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerKilometre>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerKilometre>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMetre>::
    FromStandard(Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMetre>::
    ToStandard(Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::KilojoulePerMile>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1.609344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::KilojoulePerMile>::ToStandard(Number& value) noexcept {
  value /= static_cast<Number>(1.609344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMile>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMile>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMile>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::WattHourPerMile>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::WattMinutePerKilometre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(0.06L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::WattMinutePerKilometre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.06L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::WattHourPerKilometre>::FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::WattHourPerKilometre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMetre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMetre>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMetre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::WattHourPerMetre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerMile>::FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerMile>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(60000.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerMile>::FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerMile>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerMetre>::FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerMetre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::FootPoundPerFoot>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::FootPoundPerFoot>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::InchPoundPerInch>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::InchPoundPerInch>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L);
}

template <typename Number>
inline const std::map<Unit::TransportEnergyConsumption,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TransportEnergyConsumption, Number>{
        {Unit::TransportEnergyConsumption::JoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>::FromStandard<Number>              },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>::FromStandard<Number>         },
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>::FromStandard<Number>             },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::FromStandard<Number>    },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>::FromStandard<Number>          },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>::FromStandard<Number>         },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>::FromStandard<Number>           },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>::FromStandard<Number>    },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>::FromStandard<Number>      },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>::FromStandard<Number>        },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>::FromStandard<Number>          },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>::FromStandard<Number>     },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>::FromStandard<Number>       },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::FromStandard<Number>},
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::FromStandard<Number>  },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::FromStandard<Number>    },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>::FromStandard<Number>      },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>::FromStandard<Number>          },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>::FromStandard<Number>          },
};

template <typename Number>
inline const std::map<Unit::TransportEnergyConsumption,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TransportEnergyConsumption, Number>{
        {Unit::TransportEnergyConsumption::JoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>::ToStandard<Number>              },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>::ToStandard<Number>         },
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>::ToStandard<Number>             },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::ToStandard<Number>    },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>::ToStandard<Number>          },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>::ToStandard<Number>         },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>::ToStandard<Number>           },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>::ToStandard<Number>    },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>::ToStandard<Number>      },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>::ToStandard<Number>        },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>::ToStandard<Number>          },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>::ToStandard<Number>     },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>::ToStandard<Number>       },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::ToStandard<Number>},
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::ToStandard<Number>  },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::ToStandard<Number>    },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>::ToStandard<Number>      },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>::ToStandard<Number>          },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>::ToStandard<Number>          },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP
