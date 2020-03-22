#pragma once

#include "Base.hpp"

namespace PhQ {

class DisplacementGradient : public DimensionlessDyadicQuantity {

public:

  DisplacementGradient() noexcept : DimensionlessDyadicQuantity() {}

  constexpr DisplacementGradient(const Value::Dyadic& value) noexcept : DimensionlessDyadicQuantity(value) {}

};

} // namespace PhQ
