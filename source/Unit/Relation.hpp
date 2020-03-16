#pragma once

#include "Angle.hpp"
#include "Area.hpp"
#include "Length.hpp"
#include "Temperature.hpp"
#include "Time.hpp"
#include "Volume.hpp"

namespace PhQ {

namespace Unit {

template <typename Type, typename RelatedType> const std::map<Type, RelatedType> relations;

template <> const std::map<Length, Area> relations<Length, Area> {
  {Length::Metre, Area::SquareMetre},
  {Length::Decimetre, Area::SquareDecimetre},
  {Length::Centimetre, Area::SquareCentimetre},
  {Length::Millimetre, Area::SquareMillimetre},
  {Length::Micrometre, Area::SquareMicrometre},
  {Length::Kilometre, Area::SquareKilometre},
  {Length::Mile, Area::SquareMile},
  {Length::Yard, Area::SquareYard},
  {Length::Foot, Area::SquareFoot},
  {Length::Inch, Area::SquareInch},
  {Length::Milliinch, Area::SquareMilliinch}
};

template <> const std::map<Length, Volume> relations<Length, Volume> {
  {Length::Metre, Volume::CubicMetre},
  {Length::Decimetre, Volume::CubicDecimetre},
  {Length::Centimetre, Volume::CubicCentimetre},
  {Length::Millimetre, Volume::CubicMillimetre},
  {Length::Micrometre, Volume::CubicMicrometre},
  {Length::Kilometre, Volume::CubicKilometre},
  {Length::Mile, Volume::CubicMile},
  {Length::Yard, Volume::CubicYard},
  {Length::Foot, Volume::CubicFoot},
  {Length::Inch, Volume::CubicInch},
  {Length::Milliinch, Volume::CubicMilliinch}
};

template <> const std::map<Area, Length> relations<Area, Length> {
  {Area::SquareMetre, Length::Metre},
  {Area::SquareDecimetre, Length::Decimetre},
  {Area::SquareCentimetre, Length::Centimetre},
  {Area::SquareMillimetre, Length::Millimetre},
  {Area::SquareMicrometre, Length::Micrometre},
  {Area::SquareKilometre, Length::Kilometre},
  {Area::SquareMile, Length::Mile},
  {Area::SquareYard, Length::Yard},
  {Area::SquareFoot, Length::Foot},
  {Area::SquareInch, Length::Inch},
  {Area::SquareMilliinch, Length::Milliinch}
};

template <> const std::map<Area, Volume> relations<Area, Volume> {
  {Area::SquareMetre, Volume::CubicMetre},
  {Area::SquareDecimetre, Volume::CubicDecimetre},
  {Area::SquareCentimetre, Volume::CubicCentimetre},
  {Area::SquareMillimetre, Volume::CubicMillimetre},
  {Area::SquareMicrometre, Volume::CubicMicrometre},
  {Area::SquareKilometre, Volume::CubicKilometre},
  {Area::SquareMile, Volume::CubicMile},
  {Area::SquareYard, Volume::CubicYard},
  {Area::SquareFoot, Volume::CubicFoot},
  {Area::SquareInch, Volume::CubicInch},
  {Area::SquareMilliinch, Volume::CubicMilliinch}
};

template <> const std::map<Volume, Length> relations<Volume, Length> {
  {Volume::CubicMetre, Length::Metre},
  {Volume::CubicDecimetre, Length::Decimetre},
  {Volume::CubicCentimetre, Length::Centimetre},
  {Volume::CubicMillimetre, Length::Millimetre},
  {Volume::CubicMicrometre, Length::Micrometre},
  {Volume::CubicKilometre, Length::Kilometre},
  {Volume::Litre, Length::Decimetre},
  {Volume::Millilitre, Length::Centimetre},
  {Volume::Microlitre, Length::Millimetre},
  {Volume::CubicMile, Length::Mile},
  {Volume::CubicYard, Length::Yard},
  {Volume::CubicFoot, Length::Foot},
  {Volume::CubicInch, Length::Inch},
  {Volume::CubicMilliinch, Length::Milliinch}
};

template <> const std::map<Volume, Area> relations<Volume, Area> {
  {Volume::CubicMetre, Area::SquareMetre},
  {Volume::CubicDecimetre, Area::SquareDecimetre},
  {Volume::CubicCentimetre, Area::SquareCentimetre},
  {Volume::CubicMillimetre, Area::SquareMillimetre},
  {Volume::CubicMicrometre, Area::SquareMicrometre},
  {Volume::CubicKilometre, Area::SquareKilometre},
  {Volume::Litre, Area::SquareDecimetre},
  {Volume::Millilitre, Area::SquareCentimetre},
  {Volume::Microlitre, Area::SquareMillimetre},
  {Volume::CubicMile, Area::SquareMile},
  {Volume::CubicYard, Area::SquareYard},
  {Volume::CubicFoot, Area::SquareFoot},
  {Volume::CubicInch, Area::SquareInch},
  {Volume::CubicMilliinch, Area::SquareMilliinch}
};

/// \brief Obtain a related unit of measure of a different type.
/// \details For example, PhQ::Unit::related_unit<PhQ::Unit::Volume>(PhQ::Unit::Length::Millimetre) returns PhQ::Unit::Volume::CubicMillimetre.
template <typename Unit, typename RelatedUnit> std::optional<RelatedUnit> relation(Unit unit) noexcept {
  const typename std::map<Unit, RelatedUnit>::const_iterator related_unit{relations<Unit, RelatedUnit>.find(unit)};
  if (related_unit != relations<Unit, RelatedUnit>.cend()) {
    return {related_unit->second};
  } else {
    return {};
  }
}

} // namespace Unit

} // namespace PhQ
