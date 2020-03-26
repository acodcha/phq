#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declarations.
class Area;
class Position;
class Volume;
class Time;
class Speed;

class Length : public DimensionalScalarQuantity<Unit::Length> {

public:

  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  constexpr Length(const DimensionalScalarQuantity<Unit::Length>& quantity) noexcept : DimensionalScalarQuantity<Unit::Length>(quantity) {}

  constexpr Length(double value, Unit::Length unit) noexcept : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  constexpr Length(const Position& position) noexcept;

  Area operator*(const Length& length) const noexcept;

  Volume operator*(const Area& area) const noexcept;

  Speed operator/(const Time& time) const;

protected:

  constexpr Length(double value) noexcept : DimensionalScalarQuantity<Unit::Length>(value) {}

  friend class Area;

  friend class Position;

  friend class Volume;

  friend class Time;

  friend class Speed;

};

} // namespace PhQ
