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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP

#include "../Base.hpp"
#include "ElectricCurrent.hpp"
#include "Length.hpp"
#include "LuminousIntensity.hpp"
#include "Mass.hpp"
#include "SubstanceAmount.hpp"
#include "Temperature.hpp"
#include "Time.hpp"

namespace PhQ::Dimension {

// Physical dimension set of a unit of measure or physical quantity. Composed of
// the seven independent base physical dimensions: time, length, mass, electric
// current, temperature, amount of substance, and luminous intensity. Units of
// measure that share the same physical dimension set are of the same type and
// can be converted between one another.
//
// For example, the metre per second and the mile per hour are both units of
// measure that have the same physical dimension set of T·L^(-1), which is the
// physical dimension set of speed, so these two units of measure can be
// converted between one another.
//
// On the other hand, the kilogram per cubic metre is a unit of measure with
// physical dimension set M·L^(-3), which is the physical dimension set of mass
// density, so this unit of measure cannot be converted to either the metre per
// second or the mile per hour.
class Set {
public:
  constexpr Set(
      const Time& time = {}, const Length& length = {}, const Mass& mass = {},
      const ElectricCurrent& electric_current = {},
      const Temperature& temperature = {},
      const SubstanceAmount& substance_amount = {},
      const LuminousIntensity& luminous_intensity = {}) noexcept
    : time_(time), length_(length), mass_(mass),
      electric_current_(electric_current), temperature_(temperature),
      substance_amount_(substance_amount),
      luminous_intensity_(luminous_intensity) {}

  constexpr const Dimension::Time& Time() const noexcept { return time_; }

  constexpr const Dimension::Length& Length() const noexcept { return length_; }

  constexpr const Dimension::Mass& Mass() const noexcept { return mass_; }

  constexpr const Dimension::ElectricCurrent& ElectricCurrent() const noexcept {
    return electric_current_;
  }

  constexpr const Dimension::Temperature& Temperature() const noexcept {
    return temperature_;
  }

  constexpr const Dimension::SubstanceAmount& SubstanceAmount() const noexcept {
    return substance_amount_;
  }

  constexpr const Dimension::LuminousIntensity&
  LuminousIntensity() const noexcept {
    return luminous_intensity_;
  }

  std::string Print() const noexcept {
    std::string text;
    const std::string time{time_.Print()};
    const std::string length{length_.Print()};
    const std::string mass{mass_.Print()};
    const std::string electric_current{electric_current_.Print()};
    const std::string temperature{temperature_.Print()};
    const std::string substance_amount{substance_amount_.Print()};
    const std::string luminous_intensity{luminous_intensity_.Print()};
    text.append(time);
    if (!length.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(length);
    }
    if (!mass.empty()) {
      if (!text.empty()) {
        text.append("·");
      }
      text.append(mass);
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

  std::string JSON() const noexcept {
    std::string text;
    if (time_.Value() != 0) {
      text.append("\"" + SnakeCaseCopy(time_.Label())
                  + "\":" + std::to_string(time_.Value()));
    }
    if (length_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(length_.Label())
                  + "\":" + std::to_string(length_.Value()));
    }
    if (mass_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(mass_.Label())
                  + "\":" + std::to_string(mass_.Value()));
    }
    if (electric_current_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(electric_current_.Label())
                  + "\":" + std::to_string(electric_current_.Value()));
    }
    if (temperature_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(temperature_.Label())
                  + "\":" + std::to_string(temperature_.Value()));
    }
    if (substance_amount_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(substance_amount_.Label())
                  + "\":" + std::to_string(substance_amount_.Value()));
    }
    if (luminous_intensity_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(luminous_intensity_.Label())
                  + "\":" + std::to_string(luminous_intensity_.Value()));
    }
    return "{" + text + "}";
  }

  std::string XML() const noexcept {
    std::string text;
    if (time_.Value() != 0) {
      const std::string label{SnakeCaseCopy(time_.Label())};
      text.append("<" + label + ">" + std::to_string(time_.Value()) + "</"
                  + label + ">");
    }
    if (length_.Value() != 0) {
      const std::string label{SnakeCaseCopy(length_.Label())};
      text.append("<" + label + ">" + std::to_string(length_.Value()) + "</"
                  + label + ">");
    }
    if (mass_.Value() != 0) {
      const std::string label{SnakeCaseCopy(mass_.Label())};
      text.append("<" + label + ">" + std::to_string(mass_.Value()) + "</"
                  + label + ">");
    }
    if (electric_current_.Value() != 0) {
      const std::string label{SnakeCaseCopy(electric_current_.Label())};
      text.append("<" + label + ">" + std::to_string(electric_current_.Value())
                  + "</" + label + ">");
    }
    if (temperature_.Value() != 0) {
      const std::string label{SnakeCaseCopy(temperature_.Label())};
      text.append("<" + label + ">" + std::to_string(temperature_.Value())
                  + "</" + label + ">");
    }
    if (substance_amount_.Value() != 0) {
      const std::string label{SnakeCaseCopy(substance_amount_.Label())};
      text.append("<" + label + ">" + std::to_string(substance_amount_.Value())
                  + "</" + label + ">");
    }
    if (luminous_intensity_.Value() != 0) {
      const std::string label{SnakeCaseCopy(luminous_intensity_.Label())};
      text.append(
          "<" + label + ">" + std::to_string(luminous_intensity_.Value()) + "</"
          + label + ">");
    }
    return text;
  }

  std::string YAML() const noexcept {
    std::string text;
    if (time_.Value() != 0) {
      text.append(
          SnakeCaseCopy(time_.Label()) + ":" + std::to_string(time_.Value()));
    }
    if (length_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(length_.Label()) + ":"
                  + std::to_string(length_.Value()));
    }
    if (mass_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(
          SnakeCaseCopy(mass_.Label()) + ":" + std::to_string(mass_.Value()));
    }
    if (electric_current_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(electric_current_.Label()) + ":"
                  + std::to_string(electric_current_.Value()));
    }
    if (temperature_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(temperature_.Label()) + ":"
                  + std::to_string(temperature_.Value()));
    }
    if (substance_amount_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(substance_amount_.Label()) + ":"
                  + std::to_string(substance_amount_.Value()));
    }
    if (luminous_intensity_.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(luminous_intensity_.Label()) + ":"
                  + std::to_string(luminous_intensity_.Value()));
    }
    return "{" + text + "}";
  }

private:
  Dimension::Time time_;

  Dimension::Length length_;

  Dimension::Mass mass_;

  Dimension::ElectricCurrent electric_current_;

  Dimension::Temperature temperature_;

  Dimension::SubstanceAmount substance_amount_;

  Dimension::LuminousIntensity luminous_intensity_;
};

inline constexpr bool operator==(const Set& left, const Set& right) noexcept {
  return left.Time() == right.Time() && left.Length() == right.Length()
         && left.Mass() == right.Mass()
         && left.ElectricCurrent() == right.ElectricCurrent()
         && left.Temperature() == right.Temperature()
         && left.SubstanceAmount() == right.SubstanceAmount()
         && left.LuminousIntensity() == right.LuminousIntensity();
}

inline constexpr bool operator!=(const Set& left, const Set& right) noexcept {
  return left.Time() != right.Time() || left.Length() != right.Length()
         || left.Mass() != right.Mass()
         || left.ElectricCurrent() != right.ElectricCurrent()
         || left.Temperature() != right.Temperature()
         || left.SubstanceAmount() != right.SubstanceAmount()
         || left.LuminousIntensity() != right.LuminousIntensity();
}

inline constexpr bool operator<(const Set& left, const Set& right) noexcept {
  if (left.Time() == right.Time()) {
    if (left.Length() == right.Length()) {
      if (left.Mass() == right.Mass()) {
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
        return left.Mass() < right.Mass();
      }
    } else {
      return left.Length() < right.Length();
    }
  } else {
    return left.Time() < right.Time();
  }
}

inline constexpr bool operator>(const Set& left, const Set& right) noexcept {
  if (left.Time() == right.Time()) {
    if (left.Length() == right.Length()) {
      if (left.Mass() == right.Mass()) {
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
        return left.Mass() > right.Mass();
      }
    } else {
      return left.Length() > right.Length();
    }
  } else {
    return left.Time() > right.Time();
  }
}

inline constexpr bool operator<=(const Set& left, const Set& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(const Set& left, const Set& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(std::ostream& stream, const Set& set) {
  stream << set.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template<> struct hash<PhQ::Dimension::Set> {
  inline size_t operator()(const PhQ::Dimension::Set& set) const {
    size_t result = 17;
    result = 31 * result + set.Time().Value();
    result = 31 * result + set.Length().Value();
    result = 31 * result + set.Mass().Value();
    result = 31 * result + set.ElectricCurrent().Value();
    result = 31 * result + set.Temperature().Value();
    result = 31 * result + set.SubstanceAmount().Value();
    result = 31 * result + set.LuminousIntensity().Value();
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SET_HPP
