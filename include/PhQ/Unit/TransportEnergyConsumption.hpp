// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Energy consumption in transport units.
enum class TransportEnergyConsumption : int8_t {
  /// \brief Joule per metre (J/m) transport energy consumption unit.
  JoulePerMetre,

  /// \brief Joule per mile (J/mi) transport energy consumption unit.
  JoulePerMile,

  /// \brief Joule per kilometre (J/km) transport energy consumption unit.
  JoulePerKilometre,

  /// \brief Nanojoule per millimetre (nJ/mm) transport energy consumption unit.
  NanojoulePerMillimetre,

  /// \brief Kilojoule per mile (kJ/mi) transport energy consumption unit.
  KilojoulePerMile,

  /// \brief Watt-minute per mile (W·min/mi) transport energy consumption unit.
  WattMinutePerMile,

  /// \brief Watt-hour per mile (W·hr/mi) transport energy consumption unit.
  WattHourPerMile,

  /// \brief Watt-minute per kilometre (W·min/km) transport energy consumption unit.
  WattMinutePerKilometre,

  /// \brief Watt-hour per kilometre (W·hr/km) transport energy consumption unit.
  WattHourPerKilometre,

  /// \brief Watt-minute per metre (W·min/m) transport energy consumption unit.
  WattMinutePerMetre,

  /// \brief Watt-hour per metre (W·hr/m) transport energy consumption unit.
  WattHourPerMetre,

  /// \brief Kilowatt-minute per mile (kW·min/mi) transport energy consumption unit.
  KilowattMinutePerMile,

  /// \brief Kilowatt-hour per mile (kW·hr/mi) transport energy consumption unit.
  KilowattHourPerMile,

  /// \brief Kilowatt-minute per kilometre (kW·min/km) transport energy consumption unit.
  KilowattMinutePerKilometre,

  /// \brief Kilowatt-hour per kilometre (kW·hr/km) transport energy consumption unit.
  KilowattHourPerKilometre,

  /// \brief Kilowatt-minute per metre (kW·min/m) transport energy consumption unit.
  KilowattMinutePerMetre,

  /// \brief Kilowatt-hour per metre (kW·hr/m) transport energy consumption unit.
  KilowattHourPerMetre,

  /// \brief Foot-pound per foot (ft·lbf/ft) transport energy consumption unit.
  FootPoundPerFoot,

  /// \brief Inch-pound per inch (in·lbf/in) transport energy consumption unit.
  InchPoundPerInch,
};

}  // namespace Unit

/// \brief Standard transport energy consumption unit: joule per metre (J/m).
template <>
inline constexpr const Unit::TransportEnergyConsumption Standard<Unit::TransportEnergyConsumption>{
    Unit::TransportEnergyConsumption::JoulePerMetre};

/// \brief Physical dimension set of transport energy consumption units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TransportEnergyConsumption>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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

// clang-format off

template <>
inline const std::map<Unit::TransportEnergyConsumption, std::string_view>
    Abbreviations<Unit::TransportEnergyConsumption>{
        {Unit::TransportEnergyConsumption::JoulePerMetre,              "J/m"      },
        {Unit::TransportEnergyConsumption::JoulePerMile,               "J/mi"     },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,          "J/km"     },
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
        {"J/m",       Unit::TransportEnergyConsumption::JoulePerMetre             },
        {"J/mi",      Unit::TransportEnergyConsumption::JoulePerMile              },
        {"J/km",      Unit::TransportEnergyConsumption::JoulePerKilometre         },
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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMetre>::
    FromStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMetre>::
    ToStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerMile>::
    ToStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerKilometre>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::JoulePerKilometre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::KilojoulePerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.609344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::KilojoulePerMile>::
    ToStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.609344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMile>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMile>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::WattMinutePerKilometre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.06L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::WattMinutePerKilometre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.06L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::WattHourPerKilometre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::WattHourPerKilometre>::ToStandard(NumericType&
                                                                                   value) noexcept {
  value *= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMetre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattMinutePerMetre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMetre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::WattHourPerMetre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerMile>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerMile>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::KilowattHourPerMile>::ToStandard(NumericType&
                                                                                  value) noexcept {
  value *= static_cast<NumericType>(3600000.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::TransportEnergyConsumption,
                                 Unit::TransportEnergyConsumption::KilowattHourPerMetre>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption,
           Unit::TransportEnergyConsumption::KilowattHourPerMetre>::ToStandard(NumericType&
                                                                                   value) noexcept {
  value *= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::FootPoundPerFoot>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::FootPoundPerFoot>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::InchPoundPerInch>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TransportEnergyConsumption, Unit::TransportEnergyConsumption::InchPoundPerInch>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L);
}

template <typename NumericType>
inline const std::map<Unit::TransportEnergyConsumption,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TransportEnergyConsumption, NumericType>{
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>::FromStandard<NumericType>         },
        {Unit::TransportEnergyConsumption::JoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>::FromStandard<NumericType>          },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>::FromStandard<NumericType>     },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::FromStandard<NumericType>},
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>::FromStandard<NumericType>      },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>::FromStandard<NumericType>     },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>::FromStandard<NumericType>       },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>::FromStandard<NumericType>},
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>::FromStandard<NumericType>  },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>::FromStandard<NumericType>    },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>::FromStandard<NumericType>      },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>::FromStandard<NumericType> },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>::FromStandard<NumericType>   },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
             FromStandard<NumericType>                                                       },
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::
             FromStandard<NumericType>                                                       },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::FromStandard<NumericType>},
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>::FromStandard<NumericType>  },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>::FromStandard<NumericType>      },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>::FromStandard<NumericType>      },
};

template <typename NumericType>
inline const std::map<Unit::TransportEnergyConsumption,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TransportEnergyConsumption, NumericType>{
        {Unit::TransportEnergyConsumption::JoulePerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMetre>::ToStandard<NumericType>           },
        {Unit::TransportEnergyConsumption::JoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerMile>::ToStandard<NumericType>            },
        {Unit::TransportEnergyConsumption::JoulePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::JoulePerKilometre>::ToStandard<NumericType>       },
        {Unit::TransportEnergyConsumption::NanojoulePerMillimetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::NanojoulePerMillimetre>::ToStandard<NumericType>  },
        {Unit::TransportEnergyConsumption::KilojoulePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilojoulePerMile>::ToStandard<NumericType>        },
        {Unit::TransportEnergyConsumption::WattMinutePerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMile>::ToStandard<NumericType>       },
        {Unit::TransportEnergyConsumption::WattHourPerMile,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMile>::ToStandard<NumericType>         },
        {Unit::TransportEnergyConsumption::WattMinutePerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerKilometre>::ToStandard<NumericType>  },
        {Unit::TransportEnergyConsumption::WattHourPerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerKilometre>::ToStandard<NumericType>    },
        {Unit::TransportEnergyConsumption::WattMinutePerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattMinutePerMetre>::ToStandard<NumericType>      },
        {Unit::TransportEnergyConsumption::WattHourPerMetre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::WattHourPerMetre>::ToStandard<NumericType>        },
        {Unit::TransportEnergyConsumption::KilowattMinutePerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMile>::ToStandard<NumericType>   },
        {Unit::TransportEnergyConsumption::KilowattHourPerMile,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMile>::ToStandard<NumericType>     },
        {Unit::TransportEnergyConsumption::KilowattMinutePerKilometre,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerKilometre>::
             ToStandard<NumericType>                                                         },
        {Unit::TransportEnergyConsumption::KilowattHourPerKilometre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerKilometre>::ToStandard<NumericType>},
        {Unit::TransportEnergyConsumption::KilowattMinutePerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattMinutePerMetre>::ToStandard<NumericType>  },
        {Unit::TransportEnergyConsumption::KilowattHourPerMetre,
         Conversions<
             Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::KilowattHourPerMetre>::ToStandard<NumericType>    },
        {Unit::TransportEnergyConsumption::FootPoundPerFoot,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::FootPoundPerFoot>::ToStandard<NumericType>        },
        {Unit::TransportEnergyConsumption::InchPoundPerInch,
         Conversions<Unit::TransportEnergyConsumption,
         Unit::TransportEnergyConsumption::InchPoundPerInch>::ToStandard<NumericType>        },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TRANSPORT_ENERGY_CONSUMPTION_HPP
