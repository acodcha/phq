#pragma once

#include "../../../Unit/Length.hpp"
#include "Base.hpp"

namespace PhQ {

// Forward declarations.
class Area;
class Position;
class Volume;

class Length : public DimensionalScalarQuantity<Unit::Length> {

public:

  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  constexpr Length(const DimensionalScalarQuantity<Unit::Length>& quantity) noexcept : DimensionalScalarQuantity<Unit::Length>(quantity) {}

  constexpr Length(double value, Unit::Length unit) noexcept : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  constexpr Length(const Position& position) noexcept;

  Area operator*(const Length& length) const noexcept;

  Volume operator*(const Area& area) const noexcept;

protected:

  constexpr Length(double value) noexcept : DimensionalScalarQuantity<Unit::Length>(value) {}

  friend class Area;

  friend class Position;

  friend class Volume;

};

} // namespace PhQ
