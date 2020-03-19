#pragma once

#include "../../../Unit/Area.hpp"
#include "Length.hpp"

namespace PhQ {

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(const DimensionalScalarQuantity<Unit::Area>& quantity) noexcept : DimensionalScalarQuantity<Unit::Area>(quantity) {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  Length operator/(const Length& length) const noexcept {
    return PhQ::division<Area, Length, Length>(*this, length);
  }

  Volume operator*(const Length& length) const noexcept;

protected:

  constexpr Area(double value) noexcept : DimensionalScalarQuantity<Unit::Area>(value) {}

  friend class Length;

  friend class Volume;

  friend constexpr Length PhQ::division<Area, Length, Length>(const Area& numerator, const Length& denominator);

};

Area Length::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}

} // namespace PhQ
