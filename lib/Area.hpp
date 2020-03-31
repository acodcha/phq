#pragma once

#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

// Forward declarations.
class ForceMagnitude;
class Pressure;

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  constexpr bool operator==(const Area& area) const noexcept {
    return value_ == area.value_;
  }

  constexpr bool operator!=(const Area& area) const noexcept {
    return value_ != area.value_;
  }

  constexpr bool operator<(const Area& area) const noexcept {
    return value_ < area.value_;
  }

  constexpr bool operator<=(const Area& area) const noexcept {
    return value_ <= area.value_;
  }

  constexpr bool operator>(const Area& area) const noexcept {
    return value_ > area.value_;
  }

  constexpr bool operator>=(const Area& area) const noexcept {
    return value_ >= area.value_;
  }

  constexpr Area operator+(const Area& area) const noexcept {
    return {value_ + area.value_};
  }

  constexpr void operator+=(const Area& area) noexcept {
    value_ += area.value_;
  }

  constexpr Area operator-(const Area& area) const noexcept {
    return {value_ - area.value_};
  }

  constexpr void operator-=(const Area& area) noexcept {
    value_ -= area.value_;
  }

  constexpr Volume operator*(const Length& length) const noexcept;

  constexpr ForceMagnitude operator*(const Pressure& pressure) const noexcept;

  Length operator/(const Length& length) const {
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + length.print() + "."};
    }
  }

protected:

  constexpr Area(double value) noexcept : DimensionalScalarQuantity<Unit::Area>(value) {}

  friend class ForceMagnitude;
  friend class Length;
  friend class Pressure;
  friend class Volume;

};

constexpr Area Length::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}

} // namespace PhQ
