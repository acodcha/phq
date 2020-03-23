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
    const LuminousIntensity& luminous_intensity = {})
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
    return "{\"" + length_.abbreviation() + "\": " + std::to_string(length_.value()) + ", \"" + mass_.abbreviation() + "\": " + std::to_string(mass_.value()) + ", \"" + time_.abbreviation() + "\": " + std::to_string(time_.value()) + ", \"" + electric_current_.abbreviation() + "\": " + std::to_string(electric_current_.value()) + ", \"" + temperature_.abbreviation() + "\": " + std::to_string(temperature_.value()) + ", \"" + substance_amount_.abbreviation() + "\": " + std::to_string(substance_amount_.value()) + ", \"" + luminous_intensity_.abbreviation() + "\": " + std::to_string(luminous_intensity_.value()) + "}";
  }

  std::string xml() const noexcept {
    return "<" + length_.abbreviation() + ">" + std::to_string(length_.value()) + "</" + length_.abbreviation() + "><" + mass_.abbreviation() + ">" + std::to_string(mass_.value()) + "</" + mass_.abbreviation() + "><" + time_.abbreviation() + ">" + std::to_string(time_.value()) + "</" + time_.abbreviation() + "><" + electric_current_.abbreviation() + ">" + std::to_string(electric_current_.value()) + "</" + electric_current_.abbreviation() + "><" + temperature_.abbreviation() + ">" + std::to_string(temperature_.value()) + "</" + temperature_.abbreviation() + "><" + substance_amount_.abbreviation() + ">" + std::to_string(substance_amount_.value()) + "</" + substance_amount_.abbreviation() + "><" + luminous_intensity_.abbreviation() + ">" + std::to_string(luminous_intensity_.value()) + "</" + luminous_intensity_.abbreviation() + ">";
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

template <> constexpr bool sort(const Dimension::Set& set1, const Dimension::Set& set2) noexcept {
  if (set1.length() < set2.length()) {
    return true;
  } else if (set1.length() > set2.length()) {
    return false;
  } else {
    if (set1.mass() < set2.mass()) {
      return true;
    } else if (set1.mass() > set2.mass()) {
      return false;
    } else {
      if (set1.time() < set2.time()) {
        return true;
      } else if (set1.time() > set2.time()) {
        return false;
      } else {
        if (set1.electric_current() < set2.electric_current()) {
          return true;
        } else if (set1.electric_current() > set2.electric_current()) {
          return false;
        } else {
          if (set1.temperature() < set2.temperature()) {
            return true;
          } else if (set1.temperature() > set2.temperature()) {
            return false;
          } else {
            if (set1.substance_amount() < set2.substance_amount()) {
              return true;
            } else if (set1.substance_amount() > set2.substance_amount()) {
              return false;
            } else {
              return set1.luminous_intensity() < set2.luminous_intensity();
            }
          }
        }
      }
    }
  }
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Dimension::Set& set) {
  output_stream << set.print();
  return output_stream;
}
