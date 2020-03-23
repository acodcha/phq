#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class Pressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr Pressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr Pressure(const DimensionalScalarQuantity<Unit::Pressure>& quantity) noexcept : DimensionalScalarQuantity<Unit::Pressure>(quantity) {}

  constexpr Pressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

};

} // namespace PhQ
