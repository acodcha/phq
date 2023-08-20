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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_PRECISION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_PRECISION_HPP

#include "Enumeration.hpp"

namespace PhQ {

// Precision used when printing a floating-point number as a string. All
// floating-point numbers in this library use double precision. However, when
// printing a floating-point number as a string, double precision is not always
// needed; sometimes, single precision is sufficient.
enum class Precision : int_least8_t {
  Double,
  Single,
};

namespace Internal {

template<>
inline const std::map<Precision, std::string_view> Abbreviations<Precision>{
    {Precision::Double, "Double"},
    {Precision::Single, "Single"},
};

template<> inline const std::unordered_map<std::string_view, Precision>
    Spellings<Precision>{
        {"DOUBLE", Precision::Double},
        {"Double", Precision::Double},
        {"double", Precision::Double},
        {"SINGLE", Precision::Single},
        {"Single", Precision::Single},
        {"single", Precision::Single},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_PRECISION_HPP
