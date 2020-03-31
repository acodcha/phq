#pragma once

#include "Position.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Velocity;
class Frequency;

class Displacement : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Displacement() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Displacement(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Displacement& displacement) const noexcept {
    return value_.angle(displacement.value_);
  }

  constexpr bool operator==(const Displacement& displacement) const noexcept {
    return value_ == displacement.value_;
  }

  constexpr bool operator!=(const Displacement& displacement) const noexcept {
    return value_ != displacement.value_;
  }

  constexpr Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  constexpr Displacement operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value_};
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  constexpr Displacement operator-(const Position& position) const noexcept {
    return {value_ - position.value_};
  }

  constexpr Displacement operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value_};
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  constexpr Velocity operator*(const Frequency& frequency) const noexcept;

  Velocity operator/(const Duration& duration) const;

protected:

  constexpr Displacement(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Length;

  friend class Duration;

  friend class Position;

  friend class Velocity;

  friend class Frequency;

};

constexpr Angle::Angle(const Displacement& displacement1, const Displacement& displacement2) noexcept : DimensionalScalarQuantity<Unit::Angle>(displacement1.angle(displacement2)) {}

constexpr Length::Length(const Displacement& displacement) noexcept : Length(displacement.magnitude()) {}

constexpr Position Position::operator+(const Displacement& displacement) const noexcept {
  return {value_ + displacement.value_};
}

constexpr Displacement Position::operator-(const Position& position) const noexcept {
  return {value_ - position.value_};
}

constexpr Position Position::operator-(const Displacement& displacement) const noexcept {
  return {value_ - displacement.value_};
}

constexpr void Position::operator+=(const Displacement& displacement) noexcept {
  value_ += displacement.value_;
}

constexpr void Position::operator-=(const Displacement& displacement) noexcept {
  value_ -= displacement.value_;
}

} // namespace PhQ
