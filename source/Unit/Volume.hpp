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

template <> constexpr const Volume standard<Volume>{Volume::CubicMetre};

template <> constexpr const Dimension::Set dimension<Volume>{Dimension::Set{Dimension::Length{3}}};

template <> const std::map<Volume, std::string> abbreviations<Volume>{
  {Volume::CubicMile, "mi^3"},
  {Volume::CubicKilometre, "km^3"},
  {Volume::CubicYard, "yd^3"},
  {Volume::CubicMetre, "m^3"},
  {Volume::CubicFoot, "ft^3"},
  {Volume::CubicDecimetre, "dm^3"},
  {Volume::Litre, "L"},
  {Volume::CubicInch, "in^3"},
  {Volume::CubicCentimetre, "cm^3"},
  {Volume::Millilitre, "mL"},
  {Volume::CubicMillimetre, "mm^3"},
  {Volume::Microlitre, "μL"},
  {Volume::CubicMilliinch, "thou^3"},
  {Volume::CubicMicrometre, "μm^3"},
  {Volume::CubicMicroinch, "μin^3"}
};

} // namespace Unit

template <> const std::map<System, Unit::Volume> consistent_units<Unit::Volume>{
  {System::MetreKilogramSecondKelvin, Unit::Volume::CubicMetre},
  {System::CentimetreGramSecondKelvin, Unit::Volume::CubicCentimetre},
  {System::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
  {System::FootPoundSecondRankine, Unit::Volume::CubicFoot},
  {System::InchPoundSecondRankine, Unit::Volume::CubicInch}
};

template <> const std::map<Unit::Volume, System> related_systems<Unit::Volume>{
  {Unit::Volume::CubicMetre, System::MetreKilogramSecondKelvin},
  {Unit::Volume::CubicCentimetre, System::CentimetreGramSecondKelvin},
  {Unit::Volume::Millilitre, System::CentimetreGramSecondKelvin},
  {Unit::Volume::CubicMillimetre, System::MillimetreGramSecondKelvin},
  {Unit::Volume::Microlitre, System::MillimetreGramSecondKelvin},
  {Unit::Volume::CubicFoot, System::FootPoundSecondRankine},
  {Unit::Volume::CubicInch, System::InchPoundSecondRankine},
};

} // namespace PhQ
