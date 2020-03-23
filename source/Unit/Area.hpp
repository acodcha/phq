#pragma once

#include "Length.hpp"

namespace PhQ {

namespace Unit {

enum class Area : uint_least8_t {
  SquareMile,
  SquareKilometre,
  Hectare,
  Acre,
  SquareYard,
  SquareMetre,
  SquareFoot,
  SquareDecimetre,
  SquareInch,
  SquareCentimetre,
  SquareMillimetre,
  SquareMilliinch,
  SquareMicrometre,
  SquareMicroinch
};

} // namespace Unit

template <> const std::map<Unit::Area, std::string> abbreviations<Unit::Area>{
  {Unit::Area::SquareMile, "mi^2"},
  {Unit::Area::SquareKilometre, "km^2"},
  {Unit::Area::Hectare, "ha"},
  {Unit::Area::Acre, "ac"},
  {Unit::Area::SquareYard, "yd^2"},
  {Unit::Area::SquareMetre, "m^2"},
  {Unit::Area::SquareFoot, "ft^2"},
  {Unit::Area::SquareDecimetre, "dm^2"},
  {Unit::Area::SquareInch, "in^2"},
  {Unit::Area::SquareCentimetre, "cm^2"},
  {Unit::Area::SquareMillimetre, "mm^2"},
  {Unit::Area::SquareMilliinch, "thou^2"},
  {Unit::Area::SquareMicrometre, "μm^2"},
  {Unit::Area::SquareMicroinch, "μin^2"}
};

template <> const std::unordered_map<std::string, Unit::Area> spellings<Unit::Area>{
  {"mi^2", Unit::Area::SquareMile},
  {"mi2", Unit::Area::SquareMile},
  {"km^2", Unit::Area::SquareKilometre},
  {"km2", Unit::Area::SquareKilometre},
  {"ha", Unit::Area::Hectare},
  {"ac", Unit::Area::Acre},
  {"yd^2", Unit::Area::SquareYard},
  {"yd2", Unit::Area::SquareYard},
  {"m^2", Unit::Area::SquareMetre},
  {"m2", Unit::Area::SquareMetre},
  {"ft^2", Unit::Area::SquareFoot},
  {"ft2", Unit::Area::SquareFoot},
  {"dm^2", Unit::Area::SquareDecimetre},
  {"dm2", Unit::Area::SquareDecimetre},
  {"in^2", Unit::Area::SquareInch},
  {"in2", Unit::Area::SquareInch},
  {"cm^2", Unit::Area::SquareCentimetre},
  {"cm2", Unit::Area::SquareCentimetre},
  {"mm^2", Unit::Area::SquareMillimetre},
  {"mm2", Unit::Area::SquareMillimetre},
  {"thou^2", Unit::Area::SquareMilliinch},
  {"thou2", Unit::Area::SquareMilliinch},
  {"mil^2", Unit::Area::SquareMilliinch},
  {"mil2", Unit::Area::SquareMilliinch},
  {"millinch^2", Unit::Area::SquareMilliinch},
  {"millinch2", Unit::Area::SquareMilliinch},
  {"milliinch^2", Unit::Area::SquareMilliinch},
  {"milliinch2", Unit::Area::SquareMilliinch},
  {"μm^2", Unit::Area::SquareMicrometre},
  {"μm2", Unit::Area::SquareMicrometre},
  {"μin^2", Unit::Area::SquareMicroinch},
  {"μin2", Unit::Area::SquareMicroinch}
};

template <> const std::map<System, Unit::Area> consistent_units<Unit::Area>{
  {System::MetreKilogramSecondKelvin, Unit::Area::SquareMetre},
  {System::MillimetreGramSecondKelvin, Unit::Area::SquareMillimetre},
  {System::FootPoundSecondRankine, Unit::Area::SquareFoot},
  {System::InchPoundSecondRankine, Unit::Area::SquareInch}
};

template <> const std::map<Unit::Area, System> related_systems<Unit::Area>{
  {Unit::Area::SquareMetre, System::MetreKilogramSecondKelvin},
  {Unit::Area::SquareMillimetre, System::MillimetreGramSecondKelvin},
  {Unit::Area::SquareFoot, System::FootPoundSecondRankine},
  {Unit::Area::SquareInch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Area standard_unit<Unit::Area>{Unit::Area::SquareMetre};

template <> constexpr const Dimension::Set dimension<Unit::Area>{Dimension::Set{Dimension::Length{2}}};

template <> const std::map<Unit::Length, Unit::Area> related_units<Unit::Length, Unit::Area> {
  {Unit::Length::Metre, Unit::Area::SquareMetre},
  {Unit::Length::Decimetre, Unit::Area::SquareDecimetre},
  {Unit::Length::Centimetre, Unit::Area::SquareCentimetre},
  {Unit::Length::Millimetre, Unit::Area::SquareMillimetre},
  {Unit::Length::Micrometre, Unit::Area::SquareMicrometre},
  {Unit::Length::Kilometre, Unit::Area::SquareKilometre},
  {Unit::Length::Mile, Unit::Area::SquareMile},
  {Unit::Length::Yard, Unit::Area::SquareYard},
  {Unit::Length::Foot, Unit::Area::SquareFoot},
  {Unit::Length::Inch, Unit::Area::SquareInch},
  {Unit::Length::Milliinch, Unit::Area::SquareMilliinch}
};

template <> const std::map<Unit::Area, Unit::Length> related_units<Unit::Area, Unit::Length> {
  {Unit::Area::SquareMetre, Unit::Length::Metre},
  {Unit::Area::SquareDecimetre, Unit::Length::Decimetre},
  {Unit::Area::SquareCentimetre, Unit::Length::Centimetre},
  {Unit::Area::SquareMillimetre, Unit::Length::Millimetre},
  {Unit::Area::SquareMicrometre, Unit::Length::Micrometre},
  {Unit::Area::SquareKilometre, Unit::Length::Kilometre},
  {Unit::Area::SquareMile, Unit::Length::Mile},
  {Unit::Area::SquareYard, Unit::Length::Yard},
  {Unit::Area::SquareFoot, Unit::Length::Foot},
  {Unit::Area::SquareInch, Unit::Length::Inch},
  {Unit::Area::SquareMilliinch, Unit::Length::Milliinch}
};

// TODO: Area conversions.

} // namespace PhQ
