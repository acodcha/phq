#pragma once

#include "../Scalar/Length.hpp"
#include "Base.hpp"

namespace PhQ {

class Position : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Position() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Position(const DimensionalVectorQuantity<Unit::Length>& quantity) noexcept : DimensionalVectorQuantity<Unit::Length>(quantity) {}

  constexpr Position(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  friend class Length;

};

constexpr Length::Length(const Position& position) noexcept : Length(position.value_.magnitude()) {}

} // namespace PhQ
