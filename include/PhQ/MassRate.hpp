// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_MASS_RATE_HPP
#define PHQ_MASS_RATE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Mass.hpp"
#include "Time.hpp"
#include "Unit/MassRate.hpp"

namespace PhQ {

// Mass rate. Can represent the time rate of change of a mass or a mass flow
// rate.
template <typename Number = double>
class MassRate : public DimensionalScalar<Unit::MassRate, Number> {
public:
  // Default constructor. Constructs a mass rate with an uninitialized value.
  MassRate() = default;

  // Constructor. Constructs a mass rate with a given value expressed in a given mass rate unit.
  MassRate(const Number value, const Unit::MassRate unit)
    : DimensionalScalar<Unit::MassRate, Number>(value, unit) {}

  // Constructor. Constructs a mass rate from a given mass and time using the definition of mass
  // rate.
  constexpr MassRate(const Mass<Number>& mass, const Time<Number>& time)
    : MassRate<Number>(mass.Value() / time.Value()) {}

  // Constructor. Constructs a mass rate from a given mass and frequency using the definition of
  // mass rate.
  constexpr MassRate(const Mass<Number>& mass, const Frequency<Number>& frequency)
    : MassRate<Number>(mass.Value() * frequency.Value()) {}

  // Destructor. Destroys this mass rate.
  ~MassRate() noexcept = default;

  // Copy constructor. Constructs a mass rate by copying another one.
  constexpr MassRate(const MassRate<Number>& other) = default;

  // Copy constructor. Constructs a mass rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr MassRate(const MassRate<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a mass rate by moving another one.
  constexpr MassRate(MassRate<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this mass rate by copying another one.
  constexpr MassRate<Number>& operator=(const MassRate<Number>& other) = default;

  // Copy assignment operator. Assigns this mass rate by copying another one.
  template <typename OtherNumber>
  constexpr MassRate<Number>& operator=(const MassRate<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this mass rate by moving another one.
  constexpr MassRate<Number>& operator=(MassRate<Number>&& other) noexcept = default;

  // Statically creates a mass rate of zero.
  static constexpr MassRate<Number> Zero() {
    return MassRate<Number>{static_cast<Number>(0)};
  }

  // Statically creates a mass rate with a given value expressed in a given mass rate unit.
  template <Unit::MassRate Unit>
  static constexpr MassRate<Number> Create(const Number value) {
    return MassRate<Number>{
        StaticConvertCopy<Unit::MassRate, Unit, Standard<Unit::MassRate>>(value)};
  }

  constexpr MassRate<Number> operator+(const MassRate<Number>& mass_rate) const {
    return MassRate<Number>{value + mass_rate.value};
  }

  constexpr MassRate<Number> operator-(const MassRate<Number>& mass_rate) const {
    return MassRate<Number>{value - mass_rate.value};
  }

  constexpr MassRate<Number> operator*(const Number number) const {
    return MassRate<Number>{value * number};
  }

  constexpr Mass<Number> operator*(const Time<Number>& time) const {
    return Mass<Number>{*this, time};
  }

  constexpr MassRate<Number> operator/(const Number number) const {
    return MassRate<Number>{value / number};
  }

  constexpr Frequency<Number> operator/(const Mass<Number>& mass) const {
    return Frequency<Number>{*this, mass};
  }

  constexpr Mass<Number> operator/(const Frequency<Number>& frequency) const {
    return Mass<Number>{*this, frequency};
  }

  constexpr Number operator/(const MassRate<Number>& mass_rate) const noexcept {
    return value / mass_rate.value;
  }

  constexpr void operator+=(const MassRate<Number>& mass_rate) noexcept {
    value += mass_rate.value;
  }

  constexpr void operator-=(const MassRate<Number>& mass_rate) noexcept {
    value -= mass_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a mass rate with a given value expressed in the standard mass rate
  // unit.
  explicit constexpr MassRate(const Number value)
    : DimensionalScalar<Unit::MassRate, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const MassRate<Number>& left, const MassRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const MassRate<Number>& mass_rate) {
  stream << mass_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr MassRate<Number> operator*(
    const Number number, const MassRate<Number>& mass_rate) {
  return mass_rate * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(const Mass<Number>& mass, const MassRate<Number>& mass_rate)
  : Time<Number>(mass.Value() / mass_rate.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const MassRate<Number>& mass_rate, const Mass<Number>& mass)
  : Frequency<Number>(mass_rate.Value() / mass.Value()) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(const MassRate<Number>& mass_rate, const Time<Number>& time)
  : Mass<Number>(mass_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const MassRate<Number>& mass_rate, const Frequency<Number>& frequency)
  : Mass<Number>(mass_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Mass<Number> Time<Number>::operator*(const MassRate<Number>& mass_rate) const {
  return Mass<Number>{mass_rate, *this};
}

template <typename Number>
inline constexpr MassRate<Number> Mass<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return MassRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr MassRate<Number> Frequency<Number>::operator*(const Mass<Number>& mass) const {
  return MassRate<Number>{mass, *this};
}

template <typename Number>
inline constexpr MassRate<Number> Mass<Number>::operator/(const Time<Number>& time) const {
  return MassRate<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Mass<Number>::operator/(const MassRate<Number>& mass_rate) const {
  return Time<Number>{*this, mass_rate};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::MassRate<Number>> {
  inline size_t operator()(const PhQ::MassRate<Number>& mass_rate) const {
    return hash<Number>()(mass_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_MASS_RATE_HPP
