// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Mass rate. Can represent the time rate of change of a mass or a mass flow
/// rate.
template <typename Number = double>
class MassRate : public DimensionalScalar<Unit::MassRate, Number> {
public:
  /// \brief Default constructor. Constructs a mass rate with an uninitialized value.
  MassRate() = default;

  /// \brief Constructor. Constructs a mass rate with a given value expressed in a given mass rate
  /// unit.
  MassRate(const Number value, const Unit::MassRate unit)
    : DimensionalScalar<Unit::MassRate, Number>(value, unit) {}

  /// \brief Constructor. Constructs a mass rate from a given mass and time using the definition of
  /// mass rate.
  constexpr MassRate(const Mass<Number>& mass, const Time<Number>& time)
    : MassRate<Number>(mass.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a mass rate from a given mass and frequency using the
  /// definition of mass rate.
  constexpr MassRate(const Mass<Number>& mass, const Frequency<Number>& frequency)
    : MassRate<Number>(mass.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this mass rate.
  ~MassRate() noexcept = default;

  /// \brief Copy constructor. Constructs a mass rate by copying another one.
  constexpr MassRate(const MassRate<Number>& other) = default;

  /// \brief Copy constructor. Constructs a mass rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr MassRate(const MassRate<OtherNumber>& other)
    : MassRate(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a mass rate by moving another one.
  constexpr MassRate(MassRate<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this mass rate by copying another one.
  constexpr MassRate<Number>& operator=(const MassRate<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this mass rate by copying another one.
  template <typename OtherNumber>
  constexpr MassRate<Number>& operator=(const MassRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this mass rate by moving another one.
  constexpr MassRate<Number>& operator=(MassRate<Number>&& other) noexcept = default;

  /// \brief Statically creates a mass rate of zero.
  static constexpr MassRate<Number> Zero() {
    return MassRate<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a mass rate with a given value expressed in a given mass rate unit.
  template <Unit::MassRate Unit>
  static constexpr MassRate<Number> Create(const Number value) {
    return MassRate<Number>{
        StaticConvertCopy<Unit::MassRate, Unit, Standard<Unit::MassRate>>(value)};
  }

  constexpr MassRate<Number> operator+(const MassRate<Number>& mass_rate) const {
    return MassRate<Number>{this->value + mass_rate.value};
  }

  constexpr MassRate<Number> operator-(const MassRate<Number>& mass_rate) const {
    return MassRate<Number>{this->value - mass_rate.value};
  }

  constexpr MassRate<Number> operator*(const Number number) const {
    return MassRate<Number>{this->value * number};
  }

  constexpr Mass<Number> operator*(const Time<Number>& time) const {
    return Mass<Number>{*this, time};
  }

  constexpr MassRate<Number> operator/(const Number number) const {
    return MassRate<Number>{this->value / number};
  }

  constexpr Frequency<Number> operator/(const Mass<Number>& mass) const {
    return Frequency<Number>{*this, mass};
  }

  constexpr Mass<Number> operator/(const Frequency<Number>& frequency) const {
    return Mass<Number>{*this, frequency};
  }

  constexpr Number operator/(const MassRate<Number>& mass_rate) const noexcept {
    return this->value / mass_rate.value;
  }

  constexpr void operator+=(const MassRate<Number>& mass_rate) noexcept {
    this->value += mass_rate.value;
  }

  constexpr void operator-=(const MassRate<Number>& mass_rate) noexcept {
    this->value -= mass_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a mass rate with a given value expressed in the standard mass
  /// rate unit.
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
