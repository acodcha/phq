#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declaration.
class Force;

class ForceMagnitude : public DimensionalScalarQuantity<Unit::Force> {

public:

  constexpr ForceMagnitude() noexcept : DimensionalScalarQuantity<Unit::Force>() {}

  constexpr ForceMagnitude(const DimensionalScalarQuantity<Unit::Force>& quantity) noexcept : DimensionalScalarQuantity<Unit::Force>(quantity) {}

  constexpr ForceMagnitude(double value, Unit::Force unit) noexcept : DimensionalScalarQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude(const Force& force) noexcept;

protected:

  constexpr ForceMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::Force>(value) {}

  friend class Force;

};

} // namespace PhQ
