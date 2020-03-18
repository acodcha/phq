#pragma once

#include "../../../Unit/Area.hpp"
#include "Base.hpp"

namespace PhQ {

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(const DimensionalScalarQuantity<Unit::Area>& quantity) noexcept : DimensionalScalarQuantity<Unit::Area>(quantity) {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

};

} // namespace PhQ
