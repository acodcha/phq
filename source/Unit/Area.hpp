#pragma once

#include "Base.hpp"

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

template <> const std::map<System, Unit::Area> consistent_units<Unit::Area>{
  {System::MetreKilogramSecondKelvin, Unit::Area::SquareMetre},
  {System::CentimetreGramSecondKelvin, Unit::Area::SquareCentimetre},
  {System::MillimetreGramSecondKelvin, Unit::Area::SquareMillimetre},
  {System::FootPoundSecondRankine, Unit::Area::SquareFoot},
  {System::InchPoundSecondRankine, Unit::Area::SquareInch}
};

template <> const std::map<Unit::Area, System> related_systems<Unit::Area>{
  {Unit::Area::SquareMetre, System::MetreKilogramSecondKelvin},
  {Unit::Area::SquareCentimetre, System::CentimetreGramSecondKelvin},
  {Unit::Area::SquareMillimetre, System::MillimetreGramSecondKelvin},
  {Unit::Area::SquareFoot, System::FootPoundSecondRankine},
  {Unit::Area::SquareInch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Area standard_unit<Unit::Area>{Unit::Area::SquareMetre};

template <> constexpr const Dimension::Set dimension<Unit::Area>{Dimension::Set{Dimension::Length{2}}};

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

} // namespace PhQ
