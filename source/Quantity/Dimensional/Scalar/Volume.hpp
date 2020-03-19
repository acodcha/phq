#pragma once

#include "../../../Unit/Volume.hpp"
#include "Area.hpp"

namespace PhQ {

class Volume : public DimensionalScalarQuantity<Unit::Volume> {

public:

  constexpr Volume() noexcept : DimensionalScalarQuantity<Unit::Volume>() {}

  constexpr Volume(const DimensionalScalarQuantity<Unit::Volume>& quantity) noexcept : DimensionalScalarQuantity<Unit::Volume>(quantity) {}

  constexpr Volume(double value, Unit::Volume unit) noexcept : DimensionalScalarQuantity<Unit::Volume>(value, unit) {}

  Area operator/(const Length& length) const noexcept {
    return PhQ::division<Volume, Length, Area>(*this, length);
  }

  Length operator/(const Area& area) const noexcept {
    return PhQ::division<Volume, Area, Length>(*this, area);
  }

protected:

  constexpr Volume(double value) noexcept : DimensionalScalarQuantity<Unit::Volume>(value) {}

  friend class Area;

  friend class Length;

  friend constexpr Area PhQ::division<Volume, Length, Area>(const Volume& numerator, const Length& denominator);

  friend constexpr Length PhQ::division<Volume, Area, Length>(const Volume& numerator, const Area& denominator);

};

Volume Length::operator*(const Area& area) const noexcept {
  return {value_ * area.value_};
}

Volume Area::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}


} // namespace PhQ
