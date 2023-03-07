// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class LameFirstModulus : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr LameFirstModulus() noexcept
      : DimensionalScalarQuantity<Unit::Pressure>() {}

  LameFirstModulus(const double value, const Unit::Pressure unit) noexcept
      : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  inline LameFirstModulus operator+(
      const LameFirstModulus& lame_first_modulus) const noexcept {
    return LameFirstModulus{value_ + lame_first_modulus.value_};
  }

  inline LameFirstModulus operator-(
      const LameFirstModulus& lame_first_modulus) const noexcept {
    return LameFirstModulus{value_ - lame_first_modulus.value_};
  }

  inline LameFirstModulus operator*(const double number) const noexcept {
    return LameFirstModulus{value_ * number};
  }

  inline LameFirstModulus operator/(const double number) const noexcept {
    return LameFirstModulus{value_ / number};
  }

  inline constexpr void operator+=(
      const LameFirstModulus& lame_first_modulus) noexcept {
    value_ += lame_first_modulus.value_;
  }

  inline constexpr void operator-=(
      const LameFirstModulus& lame_first_modulus) noexcept {
    value_ -= lame_first_modulus.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr LameFirstModulus(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const LameFirstModulus& left,
                                 const LameFirstModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const LameFirstModulus& left,
                                 const LameFirstModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const LameFirstModulus& left,
                                const LameFirstModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const LameFirstModulus& left,
                                const LameFirstModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const LameFirstModulus& left,
                                 const LameFirstModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const LameFirstModulus& left,
                                 const LameFirstModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const LameFirstModulus& lame_first_modulus) noexcept {
  stream << lame_first_modulus.Print();
  return stream;
}

inline LameFirstModulus operator*(
    const double number, const LameFirstModulus& lame_first_modulus) noexcept {
  return lame_first_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::LameFirstModulus> {
  size_t operator()(const PhQ::LameFirstModulus& lame_first_modulus) const {
    return hash<double>()(lame_first_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP
