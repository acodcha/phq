#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Angle.hpp"

namespace PhQ {

class Angle : public DimensionalScalarQuantity<Unit::Angle> {

public:

  constexpr Angle() noexcept : DimensionalScalarQuantity<Unit::Angle>() {}

  constexpr Angle(const DimensionalScalarQuantity<Unit::Angle>& quantity) noexcept : DimensionalScalarQuantity<Unit::Angle>(quantity) {}

  constexpr Angle(double value, Unit::Angle unit) noexcept : DimensionalScalarQuantity<Unit::Angle>(value, unit) {}

  Angle(const Direction& direction1, const Direction& direction2) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction1.angle(direction2)) {}

  Angle(const Direction& direction, const Value::Vector& vector) noexcept : DimensionalScalarQuantity<Unit::Angle>(direction.angle(vector)) {}

  Angle(const Value::Vector& vector, const Direction& direction) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector.angle(direction)) {}

  Angle(const Value::Vector& vector1, const Value::Vector& vector2) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector1.angle(vector2)) {}

protected:

  constexpr Angle(double value) noexcept : DimensionalScalarQuantity<Unit::Angle>(value) {}

  friend Angle Direction::angle(const Direction& direction) const noexcept;

  friend Angle Direction::angle(const Value::Vector& vector) const noexcept;

  friend Angle Value::Vector::angle(const Direction& direction) const noexcept;

  friend Angle Value::Vector::angle(const Value::Vector& vector) const noexcept;

};

Angle Direction::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction))};
}

Angle Direction::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / vector.magnitude())};
}

Angle Value::Vector::angle(const Direction& direction) const noexcept {
  return {std::acos(dot(direction) / magnitude())};
}

Angle Value::Vector::angle(const Value::Vector& vector) const noexcept {
  return {std::acos(dot(vector) / (magnitude() * vector.magnitude()))};
}

} // namespace PhQ
