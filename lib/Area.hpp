#pragma once

#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(const DimensionalScalarQuantity<Unit::Area>& quantity) noexcept : DimensionalScalarQuantity<Unit::Area>(quantity) {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  Volume operator*(const Length& length) const noexcept;

  Length operator/(const Length& length) const {
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + length.print() + "."};
    }
  }

protected:

  constexpr Area(double value) noexcept : DimensionalScalarQuantity<Unit::Area>(value) {}

  friend class Length;

  friend class Volume;

};

Area Length::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}

} // namespace PhQ
