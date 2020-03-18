#pragma once

#include "../../../Unit/Volume.hpp"
#include "Base.hpp"

namespace PhQ {

class Volume : public DimensionalScalarQuantity<Unit::Volume> {

public:

  constexpr Volume() noexcept : DimensionalScalarQuantity<Unit::Volume>() {}

  constexpr Volume(const DimensionalScalarQuantity<Unit::Volume>& quantity) noexcept : DimensionalScalarQuantity<Unit::Volume>(quantity) {}

  constexpr Volume(double value, Unit::Volume unit) noexcept : DimensionalScalarQuantity<Unit::Volume>(value, unit) {}

};

} // namespace PhQ
