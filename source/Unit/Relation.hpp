#pragma once

#include "Angle.hpp"
#include "Area.hpp"
#include "Force.hpp"
#include "Length.hpp"
#include "Pressure.hpp"
#include "Temperature.hpp"
#include "Time.hpp"
#include "Volume.hpp"

namespace PhQ {

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

} // namespace PhQ
