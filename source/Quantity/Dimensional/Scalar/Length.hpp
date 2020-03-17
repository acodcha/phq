#pragma once

#include "../../../Unit/Length.hpp"
#include "Base.hpp"

namespace PhQ {

class Length : public DimensionalScalarQuantity<Unit::Length> {

public:

  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  constexpr Length(double value, Unit::Length unit) noexcept : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

};

} // namespace PhQ
