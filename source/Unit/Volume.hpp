#pragma once

#include "Base.hpp"

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

} // namespace PhQ
