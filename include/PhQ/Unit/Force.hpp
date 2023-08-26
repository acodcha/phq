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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Force units.
enum class Force : int_least8_t {
  Newton,
  Kilonewton,
  Meganewton,
  Giganewton,
  Millinewton,
  Micronewton,
  Nanonewton,
  Dyne,
  JoulePerMile,
  JoulePerKilometre,
  KilojoulePerMile,
  WattMinutePerMile,
  WattHourPerMile,
  WattMinutePerKilometre,
  WattHourPerKilometre,
  WattMinutePerMetre,
  WattHourPerMetre,
  KilowattMinutePerMile,
  KilowattHourPerMile,
  KilowattMinutePerKilometre,
  KilowattHourPerKilometre,
  KilowattMinutePerMetre,
  KilowattHourPerMetre,
  Pound,
};

}  // namespace Unit

// Standard force unit: newton.
template<>
inline constexpr const Unit::Force Standard<Unit::Force>{Unit::Force::Newton};

// Physical dimension set of force units.
template<> inline constexpr const Dimensions RelatedDimensions<Unit::Force>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}}
};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Force> ConsistentUnits<Unit::Force>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Force::Newton     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
    {UnitSystem::FootPoundSecondRankine,     Unit::Force::Pound      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Force::Pound      },
};

template<>
inline const std::map<Unit::Force, UnitSystem> RelatedUnitSystems<Unit::Force>{
    {Unit::Force::Newton,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Force::Micronewton, UnitSystem::MillimetreGramSecondKelvin},
};

template<>
inline const std::map<Unit::Force, std::string_view> Abbreviations<Unit::Force>{
    {Unit::Force::Newton,                     "N"        },
    {Unit::Force::Kilonewton,                 "kN"       },
    {Unit::Force::Meganewton,                 "MN"       },
    {Unit::Force::Giganewton,                 "GN"       },
    {Unit::Force::Millinewton,                "mN"       },
    {Unit::Force::Micronewton,                "μN"       },
    {Unit::Force::Nanonewton,                 "nN"       },
    {Unit::Force::Dyne,                       "dyn"      },
    {Unit::Force::JoulePerMile,               "J/mi"     },
    {Unit::Force::JoulePerKilometre,          "J/km"     },
    {Unit::Force::KilojoulePerMile,           "kJ/mi"    },
    {Unit::Force::WattMinutePerMile,          "W·min/mi" },
    {Unit::Force::WattHourPerMile,            "W·hr/mi"  },
    {Unit::Force::WattMinutePerKilometre,     "W·min/km" },
    {Unit::Force::WattHourPerKilometre,       "W·hr/km"  },
    {Unit::Force::WattMinutePerMetre,         "W·min/m"  },
    {Unit::Force::WattHourPerMetre,           "W·hr/m"   },
    {Unit::Force::KilowattMinutePerMile,      "kW·min/mi"},
    {Unit::Force::KilowattHourPerMile,        "kW·hr/mi" },
    {Unit::Force::KilowattMinutePerKilometre, "kW·min/km"},
    {Unit::Force::KilowattHourPerKilometre,   "kW·hr/km" },
    {Unit::Force::KilowattMinutePerMetre,     "kW·min/m" },
    {Unit::Force::KilowattHourPerMetre,       "kW·hr/m"  },
    {Unit::Force::Pound,                      "lbf"      },
};

template<> inline const std::unordered_map<std::string_view, Unit::Force>
    Spellings<Unit::Force>{
        {"N",         Unit::Force::Newton                    },
        {"J/m",       Unit::Force::Newton                    },
        {"kJ/km",     Unit::Force::Newton                    },
        {"kg·m/s^2",  Unit::Force::Newton                    },
        {"kg*m/s^2",  Unit::Force::Newton                    },
        {"kg·m/s2",   Unit::Force::Newton                    },
        {"kg*m/s2",   Unit::Force::Newton                    },
        {"kN",        Unit::Force::Kilonewton                },
        {"MN",        Unit::Force::Meganewton                },
        {"GN",        Unit::Force::Giganewton                },
        {"mN",        Unit::Force::Millinewton               },
        {"μN",        Unit::Force::Micronewton               },
        {"uN",        Unit::Force::Micronewton               },
        {"nJ/mm",     Unit::Force::Micronewton               },
        {"g·mm/s^2",  Unit::Force::Micronewton               },
        {"g*mm/s^2",  Unit::Force::Micronewton               },
        {"g·mm/s2",   Unit::Force::Micronewton               },
        {"g*mm/s2",   Unit::Force::Micronewton               },
        {"nN",        Unit::Force::Nanonewton                },
        {"dyn",       Unit::Force::Dyne                      },
        {"J/mi",      Unit::Force::JoulePerMile              },
        {"J/km",      Unit::Force::JoulePerKilometre         },
        {"kJ/mi",     Unit::Force::KilojoulePerMile          },
        {"W·min/mi",  Unit::Force::WattMinutePerMile         },
        {"W*min/mi",  Unit::Force::WattMinutePerMile         },
        {"W·hr/mi",   Unit::Force::WattHourPerMile           },
        {"W*hr/mi",   Unit::Force::WattHourPerMile           },
        {"W·min/km",  Unit::Force::WattMinutePerKilometre    },
        {"W*min/km",  Unit::Force::WattMinutePerKilometre    },
        {"W·hr/km",   Unit::Force::WattHourPerKilometre      },
        {"W*hr/km",   Unit::Force::WattHourPerKilometre      },
        {"W·min/m",   Unit::Force::WattMinutePerMetre        },
        {"W*min/m",   Unit::Force::WattMinutePerMetre        },
        {"W·hr/m",    Unit::Force::WattHourPerMetre          },
        {"W*hr/m",    Unit::Force::WattHourPerMetre          },
        {"kW·min/mi", Unit::Force::KilowattMinutePerMile     },
        {"kW*min/mi", Unit::Force::KilowattMinutePerMile     },
        {"kW·hr/mi",  Unit::Force::KilowattHourPerMile       },
        {"kW*hr/mi",  Unit::Force::KilowattHourPerMile       },
        {"kW·min/km", Unit::Force::KilowattMinutePerKilometre},
        {"kW*min/km", Unit::Force::KilowattMinutePerKilometre},
        {"kW·hr/km",  Unit::Force::KilowattHourPerKilometre  },
        {"kW*hr/km",  Unit::Force::KilowattHourPerKilometre  },
        {"kW·min/m",  Unit::Force::KilowattMinutePerMetre    },
        {"kW*min/m",  Unit::Force::KilowattMinutePerMetre    },
        {"kW·hr/m",   Unit::Force::KilowattHourPerMetre      },
        {"kW*hr/m",   Unit::Force::KilowattHourPerMetre      },
        {"lbf",       Unit::Force::Pound                     },
        {"lb",        Unit::Force::Pound                     },
};

template<>
inline constexpr void ConversionFromStandard<Unit::Force, Unit::Force::Newton>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Kilonewton>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Meganewton>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Giganewton>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Millinewton>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Micronewton>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Nanonewton>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Dyne>(double& value) noexcept {
  value *= 100000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::JoulePerMile>(
    double& value) noexcept {
  value *= 1609.344;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::JoulePerKilometre>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilojoulePerMile>(
    double& value) noexcept {
  value *= 1.609344;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattMinutePerMile>(
    double& value) noexcept {
  value *= 1609.344 / 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattHourPerMile>(
    double& value) noexcept {
  value *= 1609.344 / 3600.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattMinutePerKilometre>(
    double& value) noexcept {
  value /= 0.06;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattHourPerKilometre>(
    double& value) noexcept {
  value /= 3.6;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattMinutePerMetre>(
    double& value) noexcept {
  value /= 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::WattHourPerMetre>(
    double& value) noexcept {
  value /= 3600.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattMinutePerMile>(
    double& value) noexcept {
  value *= 1609.344 / 60000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattHourPerMile>(
    double& value) noexcept {
  value *= 1609.344 / 3600000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattMinutePerKilometre>(
    double& value) noexcept {
  value /= 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattHourPerKilometre>(
    double& value) noexcept {
  value /= 3600.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattMinutePerMetre>(
    double& value) noexcept {
  value /= 60000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::KilowattHourPerMetre>(
    double& value) noexcept {
  value /= 3600000.0;
}

template<>
inline constexpr void ConversionFromStandard<Unit::Force, Unit::Force::Pound>(
    double& value) noexcept {
  value /= 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Newton>(double& value) noexcept {
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Kilonewton>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Meganewton>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Giganewton>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Millinewton>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Micronewton>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Nanonewton>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Dyne>(double& value) noexcept {
  value *= 0.00001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::JoulePerMile>(
    double& value) noexcept {
  value /= 1609.344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::JoulePerKilometre>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilojoulePerMile>(
    double& value) noexcept {
  value /= 1.609344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattMinutePerMile>(
    double& value) noexcept {
  value *= 60.0 / 1609.344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattHourPerMile>(
    double& value) noexcept {
  value *= 3600.0 / 1609.344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattMinutePerKilometre>(
    double& value) noexcept {
  value *= 0.06;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattHourPerKilometre>(
    double& value) noexcept {
  value *= 3.6;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattMinutePerMetre>(
    double& value) noexcept {
  value *= 60.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::WattHourPerMetre>(
    double& value) noexcept {
  value *= 3600.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattMinutePerMile>(
    double& value) noexcept {
  value *= 60000.0 / 1609.344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattHourPerMile>(
    double& value) noexcept {
  value *= 3600000.0 / 1609.344;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattMinutePerKilometre>(
    double& value) noexcept {
  value *= 60.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattHourPerKilometre>(
    double& value) noexcept {
  value *= 3600.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattMinutePerMetre>(
    double& value) noexcept {
  value *= 60000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::KilowattHourPerMetre>(
    double& value) noexcept {
  value *= 3600000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Pound>(double& value) noexcept {
  value *= 0.45359237 * 9.80665;
}

template<> inline const std::map<
    Unit::Force, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Force>{
        {Unit::Force::Newton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Newton>             },
        {Unit::Force::Kilonewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Kilonewton>         },
        {Unit::Force::Meganewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Meganewton>         },
        {Unit::Force::Giganewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Giganewton>         },
        {Unit::Force::Millinewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Millinewton>        },
        {Unit::Force::Micronewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Micronewton>        },
        {Unit::Force::Nanonewton,
         ConversionsFromStandard<Unit::Force, Unit::Force::Nanonewton>         },
        {Unit::Force::Dyne,
         ConversionsFromStandard<Unit::Force, Unit::Force::Dyne>               },
        {Unit::Force::JoulePerMile,
         ConversionsFromStandard<Unit::Force, Unit::Force::JoulePerMile>       },
        {Unit::Force::JoulePerKilometre,
         ConversionsFromStandard<Unit::Force, Unit::Force::JoulePerKilometre>  },
        {Unit::Force::KilojoulePerMile,
         ConversionsFromStandard<Unit::Force, Unit::Force::KilojoulePerMile>   },
        {Unit::Force::WattMinutePerMile,
         ConversionsFromStandard<Unit::Force, Unit::Force::WattMinutePerMile>  },
        {Unit::Force::WattHourPerMile,
         ConversionsFromStandard<Unit::Force, Unit::Force::WattHourPerMile>    },
        {Unit::Force::WattMinutePerKilometre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::WattMinutePerKilometre>                                  },
        {Unit::Force::WattHourPerKilometre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::WattHourPerKilometre>                                    },
        {Unit::Force::WattMinutePerMetre,
         ConversionsFromStandard<Unit::Force, Unit::Force::WattMinutePerMetre> },
        {Unit::Force::WattHourPerMetre,
         ConversionsFromStandard<Unit::Force, Unit::Force::WattHourPerMetre>   },
        {Unit::Force::KilowattMinutePerMile,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::KilowattMinutePerMile>                                   },
        {Unit::Force::KilowattHourPerMile,
         ConversionsFromStandard<Unit::Force, Unit::Force::KilowattHourPerMile>},
        {Unit::Force::KilowattMinutePerKilometre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::KilowattMinutePerKilometre>                              },
        {Unit::Force::KilowattHourPerKilometre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::KilowattHourPerKilometre>                                },
        {Unit::Force::KilowattMinutePerMetre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::KilowattMinutePerMetre>                                  },
        {Unit::Force::KilowattHourPerMetre,
         ConversionsFromStandard<Unit::Force,
         Unit::Force::KilowattHourPerMetre>                                    },
        {Unit::Force::Pound,
         ConversionsFromStandard<Unit::Force, Unit::Force::Pound>              },
};

template<>
inline const std::map<Unit::Force, std::function<void(double* const values,
                                                      const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Force>{
        {Unit::Force::Newton,
         ConversionsToStandard<Unit::Force, Unit::Force::Newton>               },
        {Unit::Force::Kilonewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Kilonewton>           },
        {Unit::Force::Meganewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Meganewton>           },
        {Unit::Force::Giganewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Giganewton>           },
        {Unit::Force::Millinewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Millinewton>          },
        {Unit::Force::Micronewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Micronewton>          },
        {Unit::Force::Nanonewton,
         ConversionsToStandard<Unit::Force, Unit::Force::Nanonewton>           },
        {Unit::Force::Dyne,
         ConversionsToStandard<Unit::Force, Unit::Force::Dyne>                 },
        {Unit::Force::JoulePerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::JoulePerMile>         },
        {Unit::Force::JoulePerKilometre,
         ConversionsToStandard<Unit::Force, Unit::Force::JoulePerKilometre>    },
        {Unit::Force::KilojoulePerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::KilojoulePerMile>     },
        {Unit::Force::WattMinutePerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::WattMinutePerMile>    },
        {Unit::Force::WattHourPerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::WattHourPerMile>      },
        {Unit::Force::WattMinutePerKilometre,
         ConversionsToStandard<Unit::Force,
         Unit::Force::WattMinutePerKilometre>                                  },
        {Unit::Force::WattHourPerKilometre,
         ConversionsToStandard<Unit::Force, Unit::Force::WattHourPerKilometre> },
        {Unit::Force::WattMinutePerMetre,
         ConversionsToStandard<Unit::Force, Unit::Force::WattMinutePerMetre>   },
        {Unit::Force::WattHourPerMetre,
         ConversionsToStandard<Unit::Force, Unit::Force::WattHourPerMetre>     },
        {Unit::Force::KilowattMinutePerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::KilowattMinutePerMile>},
        {Unit::Force::KilowattHourPerMile,
         ConversionsToStandard<Unit::Force, Unit::Force::KilowattHourPerMile>  },
        {Unit::Force::KilowattMinutePerKilometre,
         ConversionsToStandard<Unit::Force,
         Unit::Force::KilowattMinutePerKilometre>                              },
        {Unit::Force::KilowattHourPerKilometre,
         ConversionsToStandard<Unit::Force,
         Unit::Force::KilowattHourPerKilometre>                                },
        {Unit::Force::KilowattMinutePerMetre,
         ConversionsToStandard<Unit::Force,
         Unit::Force::KilowattMinutePerMetre>                                  },
        {Unit::Force::KilowattHourPerMetre,
         ConversionsToStandard<Unit::Force, Unit::Force::KilowattHourPerMetre> },
        {Unit::Force::Pound,
         ConversionsToStandard<Unit::Force, Unit::Force::Pound>                },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
