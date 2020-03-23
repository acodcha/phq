#pragma once

#include "Area.hpp"

namespace PhQ {

namespace Unit {

enum class Volume : uint_least8_t {
  CubicMile,
  CubicKilometre,
  CubicYard,
  CubicMetre,
  CubicFoot,
  CubicDecimetre,
  Litre,
  CubicInch,
  CubicCentimetre,
  Millilitre,
  CubicMillimetre,
  Microlitre,
  CubicMilliinch,
  CubicMicrometre,
  CubicMicroinch
};

} // namespace Unit

template <> const std::map<Unit::Volume, std::string> abbreviations<Unit::Volume>{
  {Unit::Volume::CubicMile, "mi^3"},
  {Unit::Volume::CubicKilometre, "km^3"},
  {Unit::Volume::CubicYard, "yd^3"},
  {Unit::Volume::CubicMetre, "m^3"},
  {Unit::Volume::CubicFoot, "ft^3"},
  {Unit::Volume::CubicDecimetre, "dm^3"},
  {Unit::Volume::Litre, "L"},
  {Unit::Volume::CubicInch, "in^3"},
  {Unit::Volume::CubicCentimetre, "cm^3"},
  {Unit::Volume::Millilitre, "mL"},
  {Unit::Volume::CubicMillimetre, "mm^3"},
  {Unit::Volume::Microlitre, "μL"},
  {Unit::Volume::CubicMilliinch, "thou^3"},
  {Unit::Volume::CubicMicrometre, "μm^3"},
  {Unit::Volume::CubicMicroinch, "μin^3"}
};

// TODO: Volume spellings.



template <> const std::map<System, Unit::Volume> consistent_units<Unit::Volume>{
  {System::MetreKilogramSecondKelvin, Unit::Volume::CubicMetre},
  {System::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
  {System::FootPoundSecondRankine, Unit::Volume::CubicFoot},
  {System::InchPoundSecondRankine, Unit::Volume::CubicInch}
};

template <> const std::map<Unit::Volume, System> related_systems<Unit::Volume>{
  {Unit::Volume::CubicMetre, System::MetreKilogramSecondKelvin},
  {Unit::Volume::CubicMillimetre, System::MillimetreGramSecondKelvin},
  {Unit::Volume::Microlitre, System::MillimetreGramSecondKelvin},
  {Unit::Volume::CubicFoot, System::FootPoundSecondRankine},
  {Unit::Volume::CubicInch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Volume standard_unit<Unit::Volume>{Unit::Volume::CubicMetre};

template <> constexpr const Dimension::Set dimension<Unit::Volume>{Dimension::Set{Dimension::Length{3}}};

template <> const std::map<Unit::Length, Unit::Volume> related_units<Unit::Length, Unit::Volume> {
  {Unit::Length::Metre, Unit::Volume::CubicMetre},
  {Unit::Length::Decimetre, Unit::Volume::CubicDecimetre},
  {Unit::Length::Centimetre, Unit::Volume::CubicCentimetre},
  {Unit::Length::Millimetre, Unit::Volume::CubicMillimetre},
  {Unit::Length::Micrometre, Unit::Volume::CubicMicrometre},
  {Unit::Length::Kilometre, Unit::Volume::CubicKilometre},
  {Unit::Length::Mile, Unit::Volume::CubicMile},
  {Unit::Length::Yard, Unit::Volume::CubicYard},
  {Unit::Length::Foot, Unit::Volume::CubicFoot},
  {Unit::Length::Inch, Unit::Volume::CubicInch},
  {Unit::Length::Milliinch, Unit::Volume::CubicMilliinch}
};

template <> const std::map<Unit::Area, Unit::Volume> related_units<Unit::Area, Unit::Volume> {
  {Unit::Area::SquareMetre, Unit::Volume::CubicMetre},
  {Unit::Area::SquareDecimetre, Unit::Volume::CubicDecimetre},
  {Unit::Area::SquareCentimetre, Unit::Volume::CubicCentimetre},
  {Unit::Area::SquareMillimetre, Unit::Volume::CubicMillimetre},
  {Unit::Area::SquareMicrometre, Unit::Volume::CubicMicrometre},
  {Unit::Area::SquareKilometre, Unit::Volume::CubicKilometre},
  {Unit::Area::SquareMile, Unit::Volume::CubicMile},
  {Unit::Area::SquareYard, Unit::Volume::CubicYard},
  {Unit::Area::SquareFoot, Unit::Volume::CubicFoot},
  {Unit::Area::SquareInch, Unit::Volume::CubicInch},
  {Unit::Area::SquareMilliinch, Unit::Volume::CubicMilliinch}
};

template <> const std::map<Unit::Volume, Unit::Length> related_units<Unit::Volume, Unit::Length> {
  {Unit::Volume::CubicMetre, Unit::Length::Metre},
  {Unit::Volume::CubicDecimetre, Unit::Length::Decimetre},
  {Unit::Volume::CubicCentimetre, Unit::Length::Centimetre},
  {Unit::Volume::CubicMillimetre, Unit::Length::Millimetre},
  {Unit::Volume::CubicMicrometre, Unit::Length::Micrometre},
  {Unit::Volume::CubicKilometre, Unit::Length::Kilometre},
  {Unit::Volume::Litre, Unit::Length::Decimetre},
  {Unit::Volume::Millilitre, Unit::Length::Centimetre},
  {Unit::Volume::Microlitre, Unit::Length::Millimetre},
  {Unit::Volume::CubicMile, Unit::Length::Mile},
  {Unit::Volume::CubicYard, Unit::Length::Yard},
  {Unit::Volume::CubicFoot, Unit::Length::Foot},
  {Unit::Volume::CubicInch, Unit::Length::Inch},
  {Unit::Volume::CubicMilliinch, Unit::Length::Milliinch}
};

template <> const std::map<Unit::Volume, Unit::Area> related_units<Unit::Volume, Unit::Area> {
  {Unit::Volume::CubicMetre, Unit::Area::SquareMetre},
  {Unit::Volume::CubicDecimetre, Unit::Area::SquareDecimetre},
  {Unit::Volume::CubicCentimetre, Unit::Area::SquareCentimetre},
  {Unit::Volume::CubicMillimetre, Unit::Area::SquareMillimetre},
  {Unit::Volume::CubicMicrometre, Unit::Area::SquareMicrometre},
  {Unit::Volume::CubicKilometre, Unit::Area::SquareKilometre},
  {Unit::Volume::Litre, Unit::Area::SquareDecimetre},
  {Unit::Volume::Millilitre, Unit::Area::SquareCentimetre},
  {Unit::Volume::Microlitre, Unit::Area::SquareMillimetre},
  {Unit::Volume::CubicMile, Unit::Area::SquareMile},
  {Unit::Volume::CubicYard, Unit::Area::SquareYard},
  {Unit::Volume::CubicFoot, Unit::Area::SquareFoot},
  {Unit::Volume::CubicInch, Unit::Area::SquareInch},
  {Unit::Volume::CubicMilliinch, Unit::Area::SquareMilliinch}
};

// TODO: Volume conversions.

} // namespace PhQ
