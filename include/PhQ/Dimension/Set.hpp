// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/Type.hpp"
#include "ElectricCurrent.hpp"
#include "Length.hpp"
#include "LuminousIntensity.hpp"
#include "Mass.hpp"
#include "SubstanceAmount.hpp"
#include "Temperature.hpp"
#include "Time.hpp"

namespace PhQ {

namespace Dimension {

class Set {

public:

  constexpr Set(
    const Length& length = {},
    const Mass& mass = {},
    const Time& time = {},
    const ElectricCurrent& electric_current = {},
    const Temperature& temperature = {},
    const SubstanceAmount& substance_amount = {},
    const LuminousIntensity& luminous_intensity = {}) noexcept
  : length_(length),
    mass_(mass),
    time_(time),
    electric_current_(electric_current),
    temperature_(temperature),
    substance_amount_(substance_amount),
    luminous_intensity_(luminous_intensity) {}

  constexpr const Length& length() const noexcept {
    return length_;
  }

  constexpr const Mass& mass() const noexcept {
    return mass_;
  }

  constexpr const Time& time() const noexcept {
    return time_;
  }

  constexpr const ElectricCurrent& electric_current() const noexcept {
    return electric_current_;
  }

  constexpr const Temperature& temperature() const noexcept {
    return temperature_;
  }

  constexpr const SubstanceAmount& substance_amount() const noexcept {
    return substance_amount_;
  }

  constexpr const LuminousIntensity& luminous_intensity() const noexcept {
    return luminous_intensity_;
  }

  std::string print() const noexcept {
    std::string text;
    const std::string length{length_.print()};
    const std::string mass{mass_.print()};
    const std::string time{time_.print()};
    const std::string electric_current{electric_current_.print()};
    const std::string temperature{temperature_.print()};
    const std::string substance_amount{substance_amount_.print()};
    const std::string luminous_intensity{luminous_intensity_.print()};
    text.append(length);
    if (!length.empty() && (!mass.empty() || !time.empty() || !electric_current.empty() || !temperature.empty() || !substance_amount.empty() || !luminous_intensity.empty())) {
      text.append("·");
    }
    text.append(mass);
    if (!mass.empty() && (!time.empty() || !electric_current.empty() || !temperature.empty() || !substance_amount.empty() || !luminous_intensity.empty())) {
      text.append("·");
    }
    text.append(time);
    if (!time.empty() && (!electric_current.empty() || !temperature.empty() || !substance_amount.empty() || !luminous_intensity.empty())) {
      text.append("·");
    }
    text.append(electric_current);
    if (!electric_current.empty() && (!temperature.empty() || !substance_amount.empty() || !luminous_intensity.empty())) {
      text.append("·");
    }
    text.append(temperature);
    if (!temperature.empty() && (!substance_amount.empty() || !luminous_intensity.empty())) {
      text.append("·");
    }
    text.append(substance_amount);
    if (!substance_amount.empty() && !luminous_intensity.empty()) {
      text.append("·");
    }
    text.append(luminous_intensity);
    if (!text.empty()) {
      return text;
    } else {
      return "1";
    }
  }

  std::string json() const noexcept {
    return "{\"" + length_.label() + "\": " + std::to_string(length_.value()) + " , \"" + mass_.label() + "\": " + std::to_string(mass_.value()) + " , \"" + time_.label() + "\": " + std::to_string(time_.value()) + " , \"" + electric_current_.label() + "\": " + std::to_string(electric_current_.value()) + " , \"" + temperature_.label() + "\": " + std::to_string(temperature_.value()) + " , \"" + substance_amount_.label() + "\": " + std::to_string(substance_amount_.value()) + " , \"" + luminous_intensity_.label() + "\": " + std::to_string(luminous_intensity_.value()) + "}";
  }

  std::string xml() const noexcept {
    return "<" + length_.label() + ">" + std::to_string(length_.value()) + "</" + length_.label() + "><" + mass_.label() + ">" + std::to_string(mass_.value()) + "</" + mass_.label() + "><" + time_.label() + ">" + std::to_string(time_.value()) + "</" + time_.label() + "><" + electric_current_.label() + ">" + std::to_string(electric_current_.value()) + "</" + electric_current_.label() + "><" + temperature_.label() + ">" + std::to_string(temperature_.value()) + "</" + temperature_.label() + "><" + substance_amount_.label() + ">" + std::to_string(substance_amount_.value()) + "</" + substance_amount_.label() + "><" + luminous_intensity_.label() + ">" + std::to_string(luminous_intensity_.value()) + "</" + luminous_intensity_.label() + ">";
  }

  constexpr bool operator==(const Set& set) const noexcept {
    return length_ == set.length_ && mass_ == set.mass_ && time_ == set.time_ && electric_current_ == set.electric_current_ && temperature_ == set.temperature_ && substance_amount_ == set.substance_amount_ && luminous_intensity_ == set.luminous_intensity_;
  }

  constexpr bool operator!=(const Set& set) const noexcept {
    return length_ != set.length_ || mass_ != set.mass_ || time_ != set.time_ || electric_current_ != set.electric_current_ || temperature_ != set.temperature_ || substance_amount_ != set.substance_amount_ || luminous_intensity_ != set.luminous_intensity_;
  }

private:

  Length length_;

  Mass mass_;

  Time time_;

  ElectricCurrent electric_current_;

  Temperature temperature_;

  SubstanceAmount substance_amount_;

  LuminousIntensity luminous_intensity_;

};

} // namespace Dimension

template <> constexpr bool sort(const Dimension::Set& set_1, const Dimension::Set& set_2) noexcept {
  if (set_1.length() == set_2.length()) {
    if (set_1.mass() == set_2.mass()) {
      if (set_1.time() == set_2.time()) {
        if (set_1.electric_current() == set_2.electric_current()) {
          if (set_1.temperature() == set_2.temperature()) {
            if (set_1.substance_amount() == set_2.substance_amount()) {
              return set_1.luminous_intensity() < set_2.luminous_intensity();
            } else {
              return set_1.substance_amount() < set_2.substance_amount();
            }
          } else {
            return set_1.temperature() < set_2.temperature();
          }
        } else {
          return set_1.electric_current() < set_2.electric_current();
        }
      } else {
        return set_1.time() < set_2.time();
      }
    } else {
      return set_1.mass() < set_2.mass();
    }
  } else {
    return set_1.length() < set_2.length();
  }
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Dimension::Set& set) {
  output_stream << set.print();
  return output_stream;
}

namespace std {

template <> struct hash<PhQ::Dimension::Set> {
  size_t operator()(const PhQ::Dimension::Set& set) const {
    return
      hash<PhQ::Dimension::Length>()(set.length())
      ^ hash<PhQ::Dimension::Mass>()(set.mass())
      ^ hash<PhQ::Dimension::Time>()(set.time())
      ^ hash<PhQ::Dimension::ElectricCurrent>()(set.electric_current())
      ^ hash<PhQ::Dimension::Temperature>()(set.temperature())
      ^ hash<PhQ::Dimension::SubstanceAmount>()(set.substance_amount())
      ^ hash<PhQ::Dimension::LuminousIntensity>()(set.luminous_intensity());
  }
};

} // namespace std
