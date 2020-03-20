#pragma once

#include "Base.hpp"

namespace PhQ {

class Strain : public DimensionlessSymmetricCartesianDyadicQuantity {

public:

  Strain() noexcept : DimensionlessSymmetricCartesianDyadicQuantity() {}

  constexpr Strain(const Value::SymmetricCartesianDyadic& value) noexcept : DimensionlessSymmetricCartesianDyadicQuantity(value) {}

};

} // namespace PhQ
