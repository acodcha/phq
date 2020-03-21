#pragma once

#include "../Scalar/Length.hpp"
#include "Base.hpp"

namespace PhQ {

class Position : public DimensionalCartesianVectorQuantity<Unit::Length> {

public:

  constexpr Position() noexcept : DimensionalCartesianVectorQuantity<Unit::Length>() {}

  constexpr Position(const DimensionalCartesianVectorQuantity<Unit::Length>& quantity) noexcept : DimensionalCartesianVectorQuantity<Unit::Length>(quantity) {}

  constexpr Position(const Value::CartesianVector& value, Unit::Length unit) noexcept : DimensionalCartesianVectorQuantity<Unit::Length>(value, unit) {}

  Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  friend class Length;

};

constexpr Length::Length(const Position& position) noexcept : Length(position.value_.magnitude()) {}

} // namespace PhQ
