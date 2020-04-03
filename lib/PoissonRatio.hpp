#pragma once

#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

class PoissonRatio : public DimensionlessScalarQuantity {

public:

  PoissonRatio() noexcept : DimensionlessScalarQuantity() {}

  constexpr PoissonRatio(double value) noexcept : DimensionlessScalarQuantity(value) {}

};

} // namespace PhQ
