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

  inline constexpr const Dimension::Length& Length() const noexcept {
    return length_;
  }

  inline constexpr const Dimension::Mass& Mass() const noexcept {
    return mass_;
  }

  inline constexpr const Dimension::Time& Time() const noexcept {
    return time_;
  }

  inline constexpr const Dimension::ElectricCurrent& ElectricCurrent()
      const noexcept {
    return electric_current_;
  }

  inline constexpr const Dimension::Temperature& Temperature() const noexcept {
    return temperature_;
  }

  inline constexpr const Dimension::SubstanceAmount& SubstanceAmount()
      const noexcept {
    return substance_amount_;
  }

  inline constexpr const Dimension::LuminousIntensity& LuminousIntensity()
      const noexcept {
    return luminous_intensity_;
  }

  std::string Print() const noexcept {
    std::string text;
    const std::string length{length_.Print()};
    const std::string mass{mass_.Print()};
    const std::string time{time_.Print()};
    const std::string electric_current{electric_current_.Print()};
    const std::string temperature{temperature_.Print()};
    const std::string substance_amount{substance_amount_.Print()};
    const std::string luminous_intensity{luminous_intensity_.Print()};
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

  std::string Json() const noexcept {
    std::string text;
    if (length_.Value() != 0) {
      text.append("\"" + SnakeCaseCopy(length_.Label()) +
                  "\":" + std::to_string(length_.Value()));
    }
    if (mass_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(mass_.Label()) +
                  "\":" + std::to_string(mass_.Value()));
    }
    if (time_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(time_.Label()) +
                  "\":" + std::to_string(time_.Value()));
    }
    if (electric_current_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(electric_current_.Label()) +
                  "\":" + std::to_string(electric_current_.Value()));
    }
    if (temperature_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(temperature_.Label()) +
                  "\":" + std::to_string(temperature_.Value()));
    }
    if (substance_amount_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(substance_amount_.Label()) +
                  "\":" + std::to_string(substance_amount_.Value()));
    }
    if (luminous_intensity_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(luminous_intensity_.Label()) +
                  "\":" + std::to_string(luminous_intensity_.Value()));
    }
    return "{" + text + "}";
  }

  std::string Xml() const noexcept {
    std::string text;
    if (length_.Value() != 0) {
      const std::string label{SnakeCaseCopy(length_.Label())};
      text.append("<" + label + ">" + std::to_string(length_.Value()) + "</" +
                  label + ">");
    }
    if (mass_.Value() != 0) {
      const std::string label{SnakeCaseCopy(mass_.Label())};
      text.append("<" + label + ">" + std::to_string(mass_.Value()) + "</" +
                  label + ">");
    }
    if (time_.Value() != 0) {
      const std::string label{SnakeCaseCopy(time_.Label())};
      text.append("<" + label + ">" + std::to_string(time_.Value()) + "</" +
                  label + ">");
    }
    if (electric_current_.Value() != 0) {
      const std::string label{SnakeCaseCopy(electric_current_.Label())};
      text.append("<" + label + ">" +
                  std::to_string(electric_current_.Value()) + "</" + label +
                  ">");
    }
    if (temperature_.Value() != 0) {
      const std::string label{SnakeCaseCopy(temperature_.Label())};
      text.append("<" + label + ">" + std::to_string(temperature_.Value()) +
                  "</" + label + ">");
    }
    if (substance_amount_.Value() != 0) {
      const std::string label{SnakeCaseCopy(substance_amount_.Label())};
      text.append("<" + label + ">" +
                  std::to_string(substance_amount_.Value()) + "</" + label +
                  ">");
    }
    if (luminous_intensity_.Value() != 0) {
      const std::string label{SnakeCaseCopy(luminous_intensity_.Label())};
      text.append("<" + label + ">" +
                  std::to_string(luminous_intensity_.Value()) + "</" + label +
                  ">");
    }
    return text;
  }

  std::string Yaml() const noexcept {
    std::string text;
    if (length_.Value() != 0) {
      text.append(SnakeCaseCopy(length_.Label()) + ":" +
                  std::to_string(length_.Value()));
    }
    if (mass_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(mass_.Label()) + ":" +
                  std::to_string(mass_.Value()));
    }
    if (time_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(time_.Label()) + ":" +
                  std::to_string(time_.Value()));
    }
    if (electric_current_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(electric_current_.Label()) + ":" +
                  std::to_string(electric_current_.Value()));
    }
    if (temperature_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(temperature_.Label()) + ":" +
                  std::to_string(temperature_.Value()));
    }
    if (substance_amount_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(substance_amount_.Label()) + ":" +
                  std::to_string(substance_amount_.Value()));
    }
    if (luminous_intensity_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(luminous_intensity_.Label()) + ":" +
                  std::to_string(luminous_intensity_.Value()));
    }
    return "{" + text + "}";
  }

private:
  Dimension::Length length_;

  Dimension::Mass mass_;

  Dimension::Time time_;

  Dimension::ElectricCurrent electric_current_;

  Dimension::Temperature temperature_;

  Dimension::SubstanceAmount substance_amount_;

  Dimension::LuminousIntensity luminous_intensity_;
};

inline constexpr bool operator==(const Set& left, const Set& right) noexcept {
  return left.Length() == right.Length() && left.Mass() == right.Mass() &&
         left.Time() == right.Time() &&
         left.ElectricCurrent() == right.ElectricCurrent() &&
         left.Temperature() == right.Temperature() &&
         left.SubstanceAmount() == right.SubstanceAmount() &&
         left.LuminousIntensity() == right.LuminousIntensity();
}

inline constexpr bool operator!=(const Set& left, const Set& right) noexcept {
  return left.Length() != right.Length() || left.Mass() != right.Mass() ||
         left.Time() != right.Time() ||
         left.ElectricCurrent() != right.ElectricCurrent() ||
         left.Temperature() != right.Temperature() ||
         left.SubstanceAmount() != right.SubstanceAmount() ||
         left.LuminousIntensity() != right.LuminousIntensity();
}

constexpr bool operator<(const Set& left, const Set& right) noexcept {
  if (left.Length() == right.Length()) {
    if (left.Mass() == right.Mass()) {
      if (left.Time() == right.Time()) {
        if (left.ElectricCurrent() == right.ElectricCurrent()) {
          if (left.Temperature() == right.Temperature()) {
            if (left.SubstanceAmount() == right.SubstanceAmount()) {
              return left.LuminousIntensity() < right.LuminousIntensity();
            } else {
              return left.SubstanceAmount() < right.SubstanceAmount();
            }
          } else {
            return left.Temperature() < right.Temperature();
          }
        } else {
          return left.ElectricCurrent() < right.ElectricCurrent();
        }
      } else {
        return left.Time() < right.Time();
      }
    } else {
      return left.Mass() < right.Mass();
    }
  } else {
    return left.Length() < right.Length();
  }
}

constexpr bool operator>(const Set& left, const Set& right) noexcept {
  if (left.Length() == right.Length()) {
    if (left.Mass() == right.Mass()) {
      if (left.Time() == right.Time()) {
        if (left.ElectricCurrent() == right.ElectricCurrent()) {
          if (left.Temperature() == right.Temperature()) {
            if (left.SubstanceAmount() == right.SubstanceAmount()) {
              return left.LuminousIntensity() > right.LuminousIntensity();
            } else {
              return left.SubstanceAmount() > right.SubstanceAmount();
            }
          } else {
            return left.Temperature() > right.Temperature();
          }
        } else {
          return left.ElectricCurrent() > right.ElectricCurrent();
        }
      } else {
        return left.Time() > right.Time();
      }
    } else {
      return left.Mass() > right.Mass();
    }
  } else {
    return left.Length() > right.Length();
  }
}

constexpr bool operator<=(const Set& left, const Set& right) noexcept {
  return !(left > right);
}

constexpr bool operator>=(const Set& left, const Set& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(std::ostream& stream, const Set& set) {
  stream << set.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::Set> {
  size_t operator()(const PhQ::Dimension::Set& set) const {
    size_t result = 17;
    result = 31 * result + set.Length().Value();
    result = 31 * result + set.Mass().Value();
    result = 31 * result + set.Time().Value();
    result = 31 * result + set.ElectricCurrent().Value();
    result = 31 * result + set.Temperature().Value();
    result = 31 * result + set.SubstanceAmount().Value();
    result = 31 * result + set.LuminousIntensity().Value();
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
