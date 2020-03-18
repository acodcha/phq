#pragma once

#include "../../../Unit/Length.hpp"
#include "Base.hpp"

namespace PhQ {

// Forward declaration of PhQ::Position for PhQ::Length.
class Position;

class Length : public DimensionalScalarQuantity<Unit::Length> {

public:

  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  constexpr Length(const DimensionalScalarQuantity<Unit::Length>& quantity) noexcept : DimensionalScalarQuantity<Unit::Length>(quantity) {}

  constexpr Length(double value, Unit::Length unit) noexcept : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  constexpr Length(const Position& position) noexcept;

protected:

  constexpr Length(double value) noexcept : DimensionalScalarQuantity<Unit::Length>(value) {}

  friend class Position;

};

} // namespace PhQ
