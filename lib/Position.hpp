#pragma once

#include "Angle.hpp"
#include "Length.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration.
class Displacement;

class Position : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Position() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Position(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Position& position) const noexcept {
    return value_.angle(position.value_);
  }

  constexpr bool operator==(const Position& position) const noexcept {
    return value_ == position.value_;
  }

  constexpr bool operator!=(const Position& position) const noexcept {
    return value_ != position.value_;
  }

  constexpr Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  constexpr Position operator+(const Displacement& displacement) const noexcept;

  constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  constexpr void operator+=(const Displacement& displacement) noexcept;

  constexpr Displacement operator-(const Position& position) const noexcept;

  constexpr Position operator-(const Displacement& displacement) const noexcept;

  constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept;

protected:

  constexpr Position(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Displacement;
  friend class Length;

};

constexpr Angle::Angle(const Position& position1, const Position& position2) noexcept : DimensionalScalarQuantity<Unit::Angle>(position1.angle(position2)) {}

} // namespace PhQ
