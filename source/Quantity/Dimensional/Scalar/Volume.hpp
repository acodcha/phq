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
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print(PhQ::standard_system) + " by " + length.print(PhQ::standard_system) + "."};
    }
  }

  Length operator/(const Area& area) const noexcept {
    if (area.value_ != 0.0) {
      return {value_ / area.value_};
    } else {
      throw std::runtime_error{"Division of " + print(PhQ::standard_system) + " by " + area.print(PhQ::standard_system) + "."};
    }
  }

protected:

  constexpr Volume(double value) noexcept : DimensionalScalarQuantity<Unit::Volume>(value) {}

  friend class Area;

  friend class Length;

};

Volume Length::operator*(const Area& area) const noexcept {
  return {value_ * area.value_};
}

Volume Area::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}


} // namespace PhQ
