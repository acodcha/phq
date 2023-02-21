// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/UnitSystem.hpp"

namespace PhQ {

const std::set<UnitSystem> UnitSystems = {
    UnitSystem::MetreKilogramSecondKelvin,
    UnitSystem::MillimetreGramSecondKelvin, UnitSystem::FootPoundSecondRankine,
    UnitSystem::InchPoundSecondRankine};

template <typename Unit>
double ConvertCopy(const double old_value, const Unit old_unit,
                   const UnitSystem new_unit_system) {
  double new_value{old_value};
  Convert(new_value, old_unit, new_unit_system);
  return new_value;
}

template <typename Unit>
double ConvertCopy(const double old_value, const Unit old_unit,
                   const Unit new_unit) {
  double new_value{old_value};
  Convert(new_value, old_unit, new_unit);
  return new_value;
}

}  // namespace PhQ
