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

template <> constexpr const Area standard<Area>{Area::SquareMetre};

template <> constexpr const Dimension::Set dimension<Area>{Dimension::Set{Dimension::Length{2}}};

template <> const std::map<Area, std::string> abbreviations<Area>{
  {Area::SquareMile, "mi^2"},
  {Area::SquareKilometre, "km^2"},
  {Area::Hectare, "ha"},
  {Area::Acre, "ac"},
  {Area::SquareYard, "yd^2"},
  {Area::SquareMetre, "m^2"},
  {Area::SquareFoot, "ft^2"},
  {Area::SquareDecimetre, "dm^2"},
  {Area::SquareInch, "in^2"},
  {Area::SquareCentimetre, "cm^2"},
  {Area::SquareMillimetre, "mm^2"},
  {Area::SquareMilliinch, "thou^2"},
  {Area::SquareMicrometre, "μm^2"},
  {Area::SquareMicroinch, "μin^2"}
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

} // namespace PhQ
