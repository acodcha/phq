#pragma once

#include "Position.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Velocity;

class Displacement : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Displacement() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Displacement(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr bool operator==(const Displacement& displacement) const noexcept {
    return value_ == displacement.value_;
  }

  constexpr bool operator!=(const Displacement& displacement) const noexcept {
    return value_ != displacement.value_;
  }

  Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  Displacement operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value_};
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  Displacement operator-(const Position& position) const noexcept {
    return {value_ - position.value_};
  }

  Displacement operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value_};
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  Velocity operator/(const Duration& duration) const;

protected:

  constexpr Displacement(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Length;

  friend class Duration;

  friend class Position;

  friend class Velocity;

};

constexpr Length::Length(const Displacement& displacement) noexcept : Length(displacement.magnitude()) {}

Position Position::operator+(const Displacement& displacement) const noexcept {
  return {value_ + displacement.value_};
}

Displacement Position::operator-(const Position& position) const noexcept {
  return {value_ - position.value_};
}

Position Position::operator-(const Displacement& displacement) const noexcept {
  return {value_ - displacement.value_};
}

constexpr void Position::operator+=(const Displacement& displacement) noexcept {
  value_ += displacement.value_;
}

constexpr void Position::operator-=(const Displacement& displacement) noexcept {
  value_ -= displacement.value_;
}

} // namespace PhQ
