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
  constexpr Set(const Length& length = {}, const Mass& mass = {},
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

  inline constexpr const Length& length() const noexcept { return length_; }

  inline constexpr const Mass& mass() const noexcept { return mass_; }

  inline constexpr const Time& time() const noexcept { return time_; }

  inline constexpr const ElectricCurrent& electric_current() const noexcept {
    return electric_current_;
  }

  inline constexpr const Temperature& temperature() const noexcept {
    return temperature_;
  }

  inline constexpr const SubstanceAmount& substance_amount() const noexcept {
    return substance_amount_;
  }

  inline constexpr const LuminousIntensity& luminous_intensity()
      const noexcept {
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
    if (!mass.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(mass);
    }
    if (!time.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(time);
    }
    if (!electric_current.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(electric_current);
    }
    if (!temperature.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(temperature);
    }
    if (!substance_amount.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(substance_amount);
    }
    if (!luminous_intensity.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(luminous_intensity);
    }
    if (text.empty()) {
      return "1";
    }
    return text;
  }

  std::string json() const noexcept {
    std::string text;
    if (length_.value() != 0) {
      text.append("\"" + snake_case_copy(length_.label()) +
                  "\":" + std::to_string(length_.value()));
    }
    if (mass_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(mass_.label()) +
                  "\":" + std::to_string(mass_.value()));
    }
    if (time_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(time_.label()) +
                  "\":" + std::to_string(time_.value()));
    }
    if (electric_current_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(electric_current_.label()) +
                  "\":" + std::to_string(electric_current_.value()));
    }
    if (temperature_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(temperature_.label()) +
                  "\":" + std::to_string(temperature_.value()));
    }
    if (substance_amount_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(substance_amount_.label()) +
                  "\":" + std::to_string(substance_amount_.value()));
    }
    if (luminous_intensity_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + snake_case_copy(luminous_intensity_.label()) +
                  "\":" + std::to_string(luminous_intensity_.value()));
    }
    return "{" + text + "}";
  }

  std::string xml() const noexcept {
    std::string text;
    if (length_.value() != 0) {
      const std::string label{snake_case_copy(length_.label())};
      text.append("<" + label + ">" + std::to_string(length_.value()) + "</" +
                  label + ">");
    }
    if (mass_.value() != 0) {
      const std::string label{snake_case_copy(mass_.label())};
      text.append("<" + label + ">" + std::to_string(mass_.value()) + "</" +
                  label + ">");
    }
    if (time_.value() != 0) {
      const std::string label{snake_case_copy(time_.label())};
      text.append("<" + label + ">" + std::to_string(time_.value()) + "</" +
                  label + ">");
    }
    if (electric_current_.value() != 0) {
      const std::string label{snake_case_copy(electric_current_.label())};
      text.append("<" + label + ">" +
                  std::to_string(electric_current_.value()) + "</" + label +
                  ">");
    }
    if (temperature_.value() != 0) {
      const std::string label{snake_case_copy(temperature_.label())};
      text.append("<" + label + ">" + std::to_string(temperature_.value()) +
                  "</" + label + ">");
    }
    if (substance_amount_.value() != 0) {
      const std::string label{snake_case_copy(substance_amount_.label())};
      text.append("<" + label + ">" +
                  std::to_string(substance_amount_.value()) + "</" + label +
                  ">");
    }
    if (luminous_intensity_.value() != 0) {
      const std::string label{snake_case_copy(luminous_intensity_.label())};
      text.append("<" + label + ">" +
                  std::to_string(luminous_intensity_.value()) + "</" + label +
                  ">");
    }
    return text;
  }

  std::string yaml() const noexcept {
    std::string text;
    if (length_.value() != 0) {
      text.append(snake_case_copy(length_.label()) + ":" +
                  std::to_string(length_.value()));
    }
    if (mass_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(mass_.label()) + ":" +
                  std::to_string(mass_.value()));
    }
    if (time_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(time_.label()) + ":" +
                  std::to_string(time_.value()));
    }
    if (electric_current_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(electric_current_.label()) + ":" +
                  std::to_string(electric_current_.value()));
    }
    if (temperature_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(temperature_.label()) + ":" +
                  std::to_string(temperature_.value()));
    }
    if (substance_amount_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(substance_amount_.label()) + ":" +
                  std::to_string(substance_amount_.value()));
    }
    if (luminous_intensity_.value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(snake_case_copy(luminous_intensity_.label()) + ":" +
                  std::to_string(luminous_intensity_.value()));
    }
    return "{" + text + "}";
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
  return left.length() == right.length() && left.mass() == right.mass() &&
         left.time() == right.time() &&
         left.electric_current() == right.electric_current() &&
         left.temperature() == right.temperature() &&
         left.substance_amount() == right.substance_amount() &&
         left.luminous_intensity() == right.luminous_intensity();
}

constexpr bool operator!=(const Set& left, const Set& right) noexcept {
  return left.length() != right.length() || left.mass() != right.mass() ||
         left.time() != right.time() ||
         left.electric_current() != right.electric_current() ||
         left.temperature() != right.temperature() ||
         left.substance_amount() != right.substance_amount() ||
         left.luminous_intensity() != right.luminous_intensity();
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

constexpr bool operator<=(const Set& left, const Set& right) noexcept {
  return !(left > right);
}

constexpr bool operator>=(const Set& left, const Set& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(std::ostream& stream, const Set& set) {
  stream << set.print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::Set> {
  size_t operator()(const PhQ::Dimension::Set& set) const {
    size_t result = 17;
    result = 31 * result + set.length().value();
    result = 31 * result + set.mass().value();
    result = 31 * result + set.time().value();
    result = 31 * result + set.electric_current().value();
    result = 31 * result + set.temperature().value();
    result = 31 * result + set.substance_amount().value();
    result = 31 * result + set.luminous_intensity().value();
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
