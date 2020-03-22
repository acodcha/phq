#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

class Temperature : public DimensionalScalarQuantity<Unit::Temperature> {

public:

  constexpr Temperature() noexcept : DimensionalScalarQuantity<Unit::Temperature>() {}

  constexpr Temperature(const DimensionalScalarQuantity<Unit::Temperature>& quantity) noexcept : DimensionalScalarQuantity<Unit::Temperature>(quantity) {}

  constexpr Temperature(double value, Unit::Temperature unit) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

};

} // namespace PhQ
