#pragma once

#include "Quantity/DimensionalSymmetricDyadic.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class Stress : public DimensionalSymmetricDyadicQuantity<Unit::Pressure> {

public:

  constexpr Stress() noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>() {}

  constexpr Stress(const Value::SymmetricDyadic& value, Unit::Pressure unit) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>(value, unit) {}

};

} // namespace PhQ
