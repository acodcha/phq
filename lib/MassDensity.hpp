#pragma once

#include "Mass.hpp"
#include "Volume.hpp"
#include "Unit/MassDensity.hpp"

namespace PhQ {

class MassDensity : public DimensionalScalarQuantity<Unit::MassDensity> {

public:

  constexpr MassDensity() noexcept : DimensionalScalarQuantity<Unit::MassDensity>() {}

  constexpr MassDensity(double value, Unit::MassDensity unit) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value, unit) {}

  constexpr bool operator==(const MassDensity& mass_density) const noexcept {
    return value_ == mass_density.value_;
  }

  constexpr bool operator!=(const MassDensity& mass_density) const noexcept {
    return value_ != mass_density.value_;
  }

  constexpr bool operator<(const MassDensity& mass_density) const noexcept {
    return value_ < mass_density.value_;
  }

  constexpr bool operator<=(const MassDensity& mass_density) const noexcept {
    return value_ <= mass_density.value_;
  }

  constexpr bool operator>(const MassDensity& mass_density) const noexcept {
    return value_ > mass_density.value_;
  }

  constexpr bool operator>=(const MassDensity& mass_density) const noexcept {
    return value_ >= mass_density.value_;
  }

  MassDensity operator+(const MassDensity& mass_density) const noexcept {
    return {value_ + mass_density.value_};
  }

  constexpr void operator+=(const MassDensity& mass_density) noexcept {
    value_ += mass_density.value_;
  }

  MassDensity operator-(const MassDensity& mass_density) const noexcept {
    return {value_ - mass_density.value_};
  }

  constexpr void operator-=(const MassDensity& mass_density) noexcept {
    value_ -= mass_density.value_;
  }

constexpr Mass operator*(const Volume& volume) const noexcept {
  return {value_ * volume.value_};
}

protected:

  constexpr MassDensity(double value) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value) {}

  friend class Mass;
  friend class Volume;

};

MassDensity Mass::operator/(const Volume& volume) const {
  if (volume.value_ != 0.0) {
    return {value_ / volume.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + volume.print() + "."};
  }
}

constexpr Mass Volume::operator*(const MassDensity& mass_density) const noexcept {
  return {value_ * mass_density.value_};
}

} // namespace PhQ
