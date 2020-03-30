#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Angle.hpp"

namespace PhQ {

// Forward declarations.
class Position;
class Displacement;
class Velocity;
class Acceleration;
class Force;

class Angle : public DimensionalScalarQuantity<Unit::Angle> {

public:

  constexpr Angle() noexcept : DimensionalScalarQuantity<Unit::Angle>() {}

  constexpr Angle(double value, Unit::Angle unit) noexcept : DimensionalScalarQuantity<Unit::Angle>(value, unit) {}

  constexpr Angle(const Direction& direction1, const Direction& direction2) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction1.angle(direction2)) {}

  constexpr Angle(const Direction& direction, const Value::Vector& vector) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction.angle(vector)) {}

  constexpr Angle(const Value::Vector& vector, const Direction& direction) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector.angle(direction)) {}

  constexpr Angle(const Value::Vector& vector1, const Value::Vector& vector2) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector1.angle(vector2)) {}

  constexpr Angle(const Position& position1, const Position& position2) noexcept;

  constexpr Angle(const Displacement& displacement1, const Displacement& displacement2) noexcept;

  constexpr Angle(const Velocity& velocity1, const Velocity& velocity2) noexcept;

  constexpr Angle(const Acceleration& acceleration1, const Acceleration& acceleration2) noexcept;

  constexpr Angle(const Force& force1, const Force& force2) noexcept;

  constexpr bool operator==(const Angle& angle) const noexcept {
    return value_ == angle.value_;
  }

  constexpr bool operator!=(const Angle& angle) const noexcept {
    return value_ != angle.value_;
  }

  constexpr bool operator<(const Angle& angle) const noexcept {
    return value_ < angle.value_;
  }

  constexpr bool operator<=(const Angle& angle) const noexcept {
    return value_ <= angle.value_;
  }

  constexpr bool operator>(const Angle& angle) const noexcept {
    return value_ > angle.value_;
  }

  constexpr bool operator>=(const Angle& angle) const noexcept {
    return value_ >= angle.value_;
  }

  constexpr Angle operator+(const Angle& angle) const noexcept {
    return {value_ + angle.value_};
  }

  constexpr void operator+=(const Angle& angle) noexcept {
    value_ += angle.value_;
  }

  constexpr Angle operator-(const Angle& angle) const noexcept {
    return {value_ - angle.value_};
  }

  constexpr void operator-=(const Angle& angle) noexcept {
    value_ -= angle.value_;
  }

protected:

  constexpr Angle(double value) noexcept : DimensionalScalarQuantity<Unit::Angle>(value) {}

  friend Angle Direction::angle(const Direction& direction) const noexcept;

  friend Angle Direction::angle(const Value::Vector& vector) const noexcept;

  friend Angle Value::Vector::angle(const Direction& direction) const noexcept;

  friend Angle Value::Vector::angle(const Value::Vector& vector) const noexcept;

};

constexpr Angle Direction::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction))};
}

constexpr Angle Direction::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / vector.magnitude())};
}

constexpr Angle Value::Vector::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction) / magnitude())};
}

constexpr Angle Value::Vector::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / (magnitude() * vector.magnitude()))};
}

} // namespace PhQ
