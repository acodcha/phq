// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP

#include "../Base/String.hpp"
#include "ElectricCurrent.hpp"
#include "Length.hpp"
#include "LuminousIntensity.hpp"
#include "Mass.hpp"
#include "SubstanceAmount.hpp"
#include "Temperature.hpp"
#include "Time.hpp"

namespace PhQ::Dimension {

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

  inline constexpr const Length& length() const noexcept {
    return length_;
  }

  inline constexpr const Mass& mass() const noexcept {
    return mass_;
  }

  inline constexpr const Time& time() const noexcept {
    return time_;
  }

  inline constexpr const ElectricCurrent& electric_current() const noexcept {
    return electric_current_;
  }

  inline constexpr const Temperature& temperature() const noexcept {
    return temperature_;
  }

  inline constexpr const SubstanceAmount& substance_amount() const noexcept {
    return substance_amount_;
  }

  inline constexpr const LuminousIntensity& luminous_intensity() const noexcept {
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
    return "{\"" + snake_case_copy(length_.label()) + "\": " + std::to_string(length_.value()) + " , \"" + snake_case_copy(mass_.label()) + "\": " + std::to_string(mass_.value()) + " , \"" + snake_case_copy(time_.label()) + "\": " + std::to_string(time_.value()) + " , \"" + snake_case_copy(electric_current_.label()) + "\": " + std::to_string(electric_current_.value()) + " , \"" + snake_case_copy(temperature_.label()) + "\": " + std::to_string(temperature_.value()) + " , \"" + snake_case_copy(substance_amount_.label()) + "\": " + std::to_string(substance_amount_.value()) + " , \"" + snake_case_copy(luminous_intensity_.label()) + "\": " + std::to_string(luminous_intensity_.value()) + "}";
  }

  std::string xml() const noexcept {
    return "<" + snake_case_copy(length_.label()) + ">" + std::to_string(length_.value()) + "</" + snake_case_copy(length_.label()) + "><" + snake_case_copy(mass_.label()) + ">" + std::to_string(mass_.value()) + "</" + snake_case_copy(mass_.label()) + "><" + snake_case_copy(time_.label()) + ">" + std::to_string(time_.value()) + "</" + snake_case_copy(time_.label()) + "><" + snake_case_copy(electric_current_.label()) + ">" + std::to_string(electric_current_.value()) + "</" + snake_case_copy(electric_current_.label()) + "><" + snake_case_copy(temperature_.label()) + ">" + std::to_string(temperature_.value()) + "</" + snake_case_copy(temperature_.label()) + "><" + snake_case_copy(substance_amount_.label()) + ">" + std::to_string(substance_amount_.value()) + "</" + snake_case_copy(substance_amount_.label()) + "><" + snake_case_copy(luminous_intensity_.label()) + ">" + std::to_string(luminous_intensity_.value()) + "</" + snake_case_copy(luminous_intensity_.label()) + ">";
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

constexpr bool operator==(const Set& left, const Set& right) noexcept {
  return left.length() == right.length() && left.mass() == right.mass() && left.time() == right.time() && left.electric_current() == right.electric_current() && left.temperature() == right.temperature() && left.substance_amount() == right.substance_amount() && left.luminous_intensity() == right.luminous_intensity();
}

constexpr bool operator!=(const Set& left, const Set& right) noexcept {
  return left.length() != right.length() || left.mass() != right.mass() || left.time() != right.time() || left.electric_current() != right.electric_current() || left.temperature() != right.temperature() || left.substance_amount() != right.substance_amount() || left.luminous_intensity() != right.luminous_intensity();
}

constexpr bool operator<(const Set& left, const Set& right) noexcept {
  if (left.length() == right.length()) {
    if (left.mass() == right.mass()) {
      if (left.time() == right.time()) {
        if (left.electric_current() == right.electric_current()) {
          if (left.temperature() == right.temperature()) {
            if (left.substance_amount() == right.substance_amount()) {
              return left.luminous_intensity() < right.luminous_intensity();
            } else {
              return left.substance_amount() < right.substance_amount();
            }
          } else {
            return left.temperature() < right.temperature();
          }
        } else {
          return left.electric_current() < right.electric_current();
        }
      } else {
        return left.time() < right.time();
      }
    } else {
      return left.mass() < right.mass();
    }
  } else {
    return left.length() < right.length();
  }
}

constexpr bool operator<=(const Set& left, const Set& right) noexcept {
  return !(left > right);
}

constexpr bool operator>(const Set& left, const Set& right) noexcept {
  if (left.length() == right.length()) {
    if (left.mass() == right.mass()) {
      if (left.time() == right.time()) {
        if (left.electric_current() == right.electric_current()) {
          if (left.temperature() == right.temperature()) {
            if (left.substance_amount() == right.substance_amount()) {
              return left.luminous_intensity() > right.luminous_intensity();
            } else {
              return left.substance_amount() > right.substance_amount();
            }
          } else {
            return left.temperature() > right.temperature();
          }
        } else {
          return left.electric_current() > right.electric_current();
        }
      } else {
        return left.time() > right.time();
      }
    } else {
      return left.mass() > right.mass();
    }
  } else {
    return left.length() > right.length();
  }
}

constexpr bool operator>=(const Set& left, const Set& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(std::ostream& output_stream, const Set& set) {
  output_stream << set.print();
  return output_stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <> struct hash<PhQ::Dimension::Set> {
  size_t operator()(const PhQ::Dimension::Set& set) const {
    return hash<PhQ::Dimension::Length>()(set.length()) ^ hash<PhQ::Dimension::Mass>()(set.mass()) ^ hash<PhQ::Dimension::Time>()(set.time()) ^ hash<PhQ::Dimension::ElectricCurrent>()(set.electric_current()) ^ hash<PhQ::Dimension::Temperature>()(set.temperature()) ^ hash<PhQ::Dimension::SubstanceAmount>()(set.substance_amount()) ^ hash<PhQ::Dimension::LuminousIntensity>()(set.luminous_intensity());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
