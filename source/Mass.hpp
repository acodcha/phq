#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

class Mass : public DimensionalScalarQuantity<Unit::Mass> {

public:

  constexpr Mass() noexcept : DimensionalScalarQuantity<Unit::Mass>() {}

  constexpr Mass(const DimensionalScalarQuantity<Unit::Mass>& quantity) noexcept : DimensionalScalarQuantity<Unit::Mass>(quantity) {}

  constexpr Mass(double value, Unit::Mass unit) noexcept : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

};

} // namespace PhQ
