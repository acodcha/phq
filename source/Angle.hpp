#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Angle.hpp"

namespace PhQ {

class Angle : public DimensionalScalarQuantity<Unit::Angle> {

public:

  constexpr Angle() noexcept : DimensionalScalarQuantity<Unit::Angle>() {}

  constexpr Angle(const DimensionalScalarQuantity<Unit::Angle>& quantity) noexcept : DimensionalScalarQuantity<Unit::Angle>(quantity) {}

  constexpr Angle(double value, Unit::Angle unit) noexcept : DimensionalScalarQuantity<Unit::Angle>(value, unit) {}

};

} // namespace PhQ
