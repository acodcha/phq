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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP

#include "../Unit.hpp"

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
inline constexpr const Unit::TransportEnergyConsumption
    Standard<Unit::TransportEnergyConsumption>{
        Unit::TransportEnergyConsumption::JoulePerMetre};

// Physical dimension set of transport energy consumption units.
template <>
inline constexpr const Dimensions
    RelatedDimensions<Unit::TransportEnergyConsumption>{
        Dimensions{
                   Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(
    std::ostream& stream, const Unit::TransportEnergyConsumption unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::TransportEnergyConsumption>
    ConsistentUnits<Unit::TransportEnergyConsumption>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::TransportEnergyConsumption::JoulePerMetre         },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre},
        {UnitSystem::FootPoundSecondRankine,
         Unit::TransportEnergyConsumption::FootPoundPerFoot      },
        {UnitSystem::InchPoundSecondRankine,
         Unit::TransportEnergyConsumption::InchPoundPerInch      },
};

template <>
inline const std::map<Unit::TransportEnergyConsumption, UnitSystem>
    RelatedUnitSystems<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         UnitSystem::FootPoundSecondRankine    },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         UnitSystem::InchPoundSecondRankine    },
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
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         "kW·min/km"                                                              },
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         "kW·hr/"
         "km"                                                                     },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,     "kW·min/m" },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,       "kW·hr/m"  },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,           "ft·lbf/ft"},
        {Unit::TransportEnergyConsumption::InchPoundPerInch,           "in·lbf/in"},
};

template <>
inline const std::unordered_map<std::string_view,
                                Unit::TransportEnergyConsumption>
    Spellings<Unit::TransportEnergyConsumption>{
        {"J/mi",      Unit::TransportEnergyConsumption::JoulePerMile          },
        {"J/km",      Unit::TransportEnergyConsumption::JoulePerKilometre     },
        {"J/m",       Unit::TransportEnergyConsumption::JoulePerMetre         },
        {"nJ/mm",     Unit::TransportEnergyConsumption::NanojoulePerMillimetre},
        {"kJ/mi",     Unit::TransportEnergyConsumption::KilojoulePerMile      },
        {"W·min/mi",  Unit::TransportEnergyConsumption::WattMinutePerMile     },
        {"W*min/mi",  Unit::TransportEnergyConsumption::WattMinutePerMile     },
        {"W·hr/mi",   Unit::TransportEnergyConsumption::WattHourPerMile       },
        {"W*hr/mi",   Unit::TransportEnergyConsumption::WattHourPerMile       },
        {"W·min/km",  Unit::TransportEnergyConsumption::WattMinutePerKilometre},
        {"W*min/km",  Unit::TransportEnergyConsumption::WattMinutePerKilometre},
        {"W·hr/km",   Unit::TransportEnergyConsumption::WattHourPerKilometre  },
        {"W*hr/km",   Unit::TransportEnergyConsumption::WattHourPerKilometre  },
        {"W·min/m",   Unit::TransportEnergyConsumption::WattMinutePerMetre    },
        {"W*min/m",   Unit::TransportEnergyConsumption::WattMinutePerMetre    },
        {"W·hr/m",    Unit::TransportEnergyConsumption::WattHourPerMetre      },
        {"W*hr/m",    Unit::TransportEnergyConsumption::WattHourPerMetre      },
        {"kW·min/mi", Unit::TransportEnergyConsumption::KilowattMinutePerMile },
        {"kW*min/mi", Unit::TransportEnergyConsumption::KilowattMinutePerMile },
        {"kW·hr/mi",  Unit::TransportEnergyConsumption::KilowattHourPerMile   },
        {"kW*hr/mi",  Unit::TransportEnergyConsumption::KilowattHourPerMile   },
        {"kW·min/km",
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre         },
        {"kW*min/km",
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre         },
        {"kW·hr/km",
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre           },
        {"kW*hr/km",
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre           },
        {"kW·min/m",  Unit::TransportEnergyConsumption::KilowattMinutePerMetre},
        {"kW*min/m",  Unit::TransportEnergyConsumption::KilowattMinutePerMetre},
        {"kW·hr/m",   Unit::TransportEnergyConsumption::KilowattHourPerMetre  },
        {"kW*hr/m",   Unit::TransportEnergyConsumption::KilowattHourPerMetre  },
        {"ft·lbf/ft", Unit::TransportEnergyConsumption::FootPoundPerFoot      },
        {"ft·lb/ft",  Unit::TransportEnergyConsumption::FootPoundPerFoot      },
        {"in·lbf/in", Unit::TransportEnergyConsumption::InchPoundPerInch      },
        {"in·lb/in",  Unit::TransportEnergyConsumption::InchPoundPerInch      },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::JoulePerMile>(
    double& value) noexcept {
  value *= 1609.344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::JoulePerKilometre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::JoulePerMetre>(
    double&) noexcept {}

template <>
inline constexpr void ConversionFromStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::NanojoulePerMillimetre>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::KilojoulePerMile>(
    double& value) noexcept {
  value *= 1.609344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::WattMinutePerMile>(
    double& value) noexcept {
  value *= 1609.344 / 60.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::WattHourPerMile>(
    double& value) noexcept {
  value *= 1609.344 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::WattMinutePerKilometre>(
    double& value) noexcept {
  value /= 0.06;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::WattHourPerKilometre>(
    double& value) noexcept {
  value /= 3.6;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::WattMinutePerMetre>(
    double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::WattHourPerMetre>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::KilowattMinutePerMile>(
    double& value) noexcept {
  value *= 1609.344 / 60000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::KilowattHourPerMile>(
    double& value) noexcept {
  value *= 1609.344 / 3600000.0;
}

template <>
inline constexpr void ConversionFromStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>(
    double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void ConversionFromStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerKilometre>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerMetre>(
    double& value) noexcept {
  value /= 60000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::KilowattHourPerMetre>(
    double& value) noexcept {
  value /= 3600000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::FootPoundPerFoot>(
    double& value) noexcept {
  value /= 0.45359237 * 9.80665;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TransportEnergyConsumption,
                       Unit::TransportEnergyConsumption::InchPoundPerInch>(
    double& value) noexcept {
  value /= 0.45359237 * 9.80665;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::JoulePerMile>(
    double& value) noexcept {
  value /= 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::JoulePerKilometre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::JoulePerMetre>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::NanojoulePerMillimetre>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::KilojoulePerMile>(
    double& value) noexcept {
  value /= 1.609344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattMinutePerMile>(
    double& value) noexcept {
  value *= 60.0 / 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattHourPerMile>(
    double& value) noexcept {
  value *= 3600.0 / 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattMinutePerKilometre>(
    double& value) noexcept {
  value *= 0.06;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattHourPerKilometre>(
    double& value) noexcept {
  value *= 3.6;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattMinutePerMetre>(
    double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::WattHourPerMetre>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::KilowattMinutePerMile>(
    double& value) noexcept {
  value *= 60000.0 / 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::KilowattHourPerMile>(
    double& value) noexcept {
  value *= 3600000.0 / 1609.344;
}

template <>
inline constexpr void ConversionToStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>(
    double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void ConversionToStandard<
    Unit::TransportEnergyConsumption,
    Unit::TransportEnergyConsumption::KilowattHourPerKilometre>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::KilowattMinutePerMetre>(
    double& value) noexcept {
  value *= 60000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::KilowattHourPerMetre>(
    double& value) noexcept {
  value *= 3600000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::FootPoundPerFoot>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TransportEnergyConsumption,
                     Unit::TransportEnergyConsumption::InchPoundPerInch>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665;
}

template <>
inline const std::map<
    Unit::TransportEnergyConsumption,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>              },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>         },
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>             },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>    },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>          },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>         },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>           },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>    },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>      },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>        },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>          },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>     },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>       },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>},
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>  },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>    },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>      },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>          },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         ConversionsFromStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>          },
};

template <>
inline const std::map<
    Unit::TransportEnergyConsumption,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMile,
         ConversionsToStandard<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>              },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>         },
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>             },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>    },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>          },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>         },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>           },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>    },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>      },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>        },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>          },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>     },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>       },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>},
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>  },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>    },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>      },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>          },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         ConversionsToStandard<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>          },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP
