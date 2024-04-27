// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_DIMENSIONS_HPP
#define PHQ_DIMENSIONS_HPP

#include "Base.hpp"
#include "Dimension/ElectricCurrent.hpp"
#include "Dimension/Length.hpp"
#include "Dimension/LuminousIntensity.hpp"
#include "Dimension/Mass.hpp"
#include "Dimension/SubstanceAmount.hpp"
#include "Dimension/Temperature.hpp"
#include "Dimension/Time.hpp"

namespace PhQ {

// Physical dimension set of a unit of measure or physical quantity. Composed of the seven
// independent base physical dimensions: time (T), length (L), mass (M), electric current (I),
// temperature (Θ), amount of substance (N), and luminous intensity (J). Units of measure that share
// the same physical dimension set are of the same type and can be converted between one another.
//
// For example, the metre per second and the mile per hour are both units of measure that have the
// same physical dimension set of T^(-1)·L, which is the physical dimension set of speed, so these
// two units of measure can be converted between one another.
//
// On the other hand, the kilogram per cubic metre is a unit of measure with physical dimension set
// L^(-3)·M, which is the physical dimension set of mass density, so this unit of measure cannot be
// converted to either the metre per second or the mile per hour, which have a different physical
// dimension set.
class Dimensions {
public:
  // Default constructor. Constructs a dimensionless physical dimension set where all base physical
  // dimensions are zero.
  constexpr Dimensions() = default;

  // Constructor. Constructs a physical dimension set from the given base physical dimensions.
  // Omitted base physical dimensions are initialized to a value of zero.
  explicit constexpr Dimensions(
      const Dimension::Time& time, const Dimension::Length& length = {},
      const Dimension::Mass& mass = {}, const Dimension::ElectricCurrent& electric_current = {},
      const Dimension::Temperature& temperature = {},
      const Dimension::SubstanceAmount& substance_amount = {},
      const Dimension::LuminousIntensity& luminous_intensity = {})
    : time(time), length(length), mass(mass), electric_current(electric_current),
      temperature(temperature), substance_amount(substance_amount),
      luminous_intensity(luminous_intensity) {}

  // Destructor. Destroys this physical dimension set.
  ~Dimensions() noexcept = default;

  // Copy constructor. Constructs a physical dimension set by copying another one.
  constexpr Dimensions(const Dimensions& other) = default;

  // Move constructor. Constructs a physical dimension set by moving another one.
  constexpr Dimensions(Dimensions&& other) noexcept = default;

  // Copy assignment operator. Assigns the base physical dimensions of this physical dimension set
  // by copying from another one.
  constexpr Dimensions& operator=(const Dimensions& other) = default;

  // Move assignment operator. Assigns the base physical dimensions of this physical dimension set
  // by moving another one.
  constexpr Dimensions& operator=(Dimensions&& other) noexcept = default;

  // Base physical dimension of time of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::Time& Time() const noexcept {
    return time;
  }

  // Base physical dimension of length of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::Length& Length() const noexcept {
    return length;
  }

  // Base physical dimension of mass of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::Mass& Mass() const noexcept {
    return mass;
  }

  // Base physical dimension of electric current of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::ElectricCurrent& ElectricCurrent() const noexcept {
    return electric_current;
  }

  // Base physical dimension of temperature of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::Temperature& Temperature() const noexcept {
    return temperature;
  }

  // Base physical dimension of amount of substance of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::SubstanceAmount& SubstanceAmount() const noexcept {
    return substance_amount;
  }

  // Base physical dimension of luminous intensity of this physical dimension set.
  [[nodiscard]] constexpr const Dimension::LuminousIntensity& LuminousIntensity() const noexcept {
    return luminous_intensity;
  }

  // Prints this physical dimension set as a string.
  [[nodiscard]] std::string Print() const {
    std::string text;
    text.append(time.Print());
    {
      const std::string length_string{length.Print()};
      if (!length_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(length_string);
      }
    }
    {
      const std::string mass_string{mass.Print()};
      if (!mass_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(mass_string);
      }
    }
    {
      const std::string electric_current_string{electric_current.Print()};
      if (!electric_current_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(electric_current_string);
      }
    }
    {
      const std::string temperature_string{temperature.Print()};
      if (!temperature_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(temperature_string);
      }
    }
    {
      const std::string substance_amount_string{substance_amount.Print()};
      if (!substance_amount_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(substance_amount_string);
      }
    }
    {
      const std::string luminous_intensity_string{luminous_intensity.Print()};
      if (!luminous_intensity_string.empty()) {
        if (!text.empty()) {
          text.append("·");
        }
        text.append(luminous_intensity_string);
      }
    }
    if (text.empty()) {
      return "1";
    }
    return text;
  }

  // Serializes this physical dimension set as a JSON message.
  [[nodiscard]] std::string JSON() const {
    std::string text;
    if (time.Value() != 0) {
      text.append(
          "\"" + SnakeCaseCopy(Dimension::Time::Label()) + "\":" + std::to_string(time.Value()));
    }
    if (length.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(Dimension::Length::Label())
                  + "\":" + std::to_string(length.Value()));
    }
    if (mass.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(
          "\"" + SnakeCaseCopy(Dimension::Mass::Label()) + "\":" + std::to_string(mass.Value()));
    }
    if (electric_current.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(Dimension::ElectricCurrent::Label())
                  + "\":" + std::to_string(electric_current.Value()));
    }
    if (temperature.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(Dimension::Temperature::Label())
                  + "\":" + std::to_string(temperature.Value()));
    }
    if (substance_amount.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(Dimension::SubstanceAmount::Label())
                  + "\":" + std::to_string(substance_amount.Value()));
    }
    if (luminous_intensity.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append("\"" + SnakeCaseCopy(Dimension::LuminousIntensity::Label())
                  + "\":" + std::to_string(luminous_intensity.Value()));
    }
    return "{" + text + "}";
  }

  // Serializes this physical dimension set as an XML message.
  [[nodiscard]] std::string XML() const {
    std::string text;
    if (time.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::Time::Label())};
      text.append("<" + label + ">" + std::to_string(time.Value()) + "</" + label + ">");
    }
    if (length.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::Length::Label())};
      text.append("<" + label + ">" + std::to_string(length.Value()) + "</" + label + ">");
    }
    if (mass.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::Mass::Label())};
      text.append("<" + label + ">" + std::to_string(mass.Value()) + "</" + label + ">");
    }
    if (electric_current.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::ElectricCurrent::Label())};
      text.append(
          "<" + label + ">" + std::to_string(electric_current.Value()) + "</" + label + ">");
    }
    if (temperature.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::Temperature::Label())};
      text.append("<" + label + ">" + std::to_string(temperature.Value()) + "</" + label + ">");
    }
    if (substance_amount.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::SubstanceAmount::Label())};
      text.append(
          "<" + label + ">" + std::to_string(substance_amount.Value()) + "</" + label + ">");
    }
    if (luminous_intensity.Value() != 0) {
      const std::string label{SnakeCaseCopy(Dimension::LuminousIntensity::Label())};
      text.append(
          "<" + label + ">" + std::to_string(luminous_intensity.Value()) + "</" + label + ">");
    }
    return text;
  }

  // Serializes this physical dimension set as a YAML message.
  [[nodiscard]] std::string YAML() const {
    std::string text;
    if (time.Value() != 0) {
      text.append(SnakeCaseCopy(Dimension::Time::Label()) + ":" + std::to_string(time.Value()));
    }
    if (length.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::Length::Label()) + ":" + std::to_string(length.Value()));
    }
    if (mass.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::Mass::Label()) + ":" + std::to_string(mass.Value()));
    }
    if (electric_current.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::ElectricCurrent::Label()) + ":"
                  + std::to_string(electric_current.Value()));
    }
    if (temperature.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::Temperature::Label()) + ":"
                  + std::to_string(temperature.Value()));
    }
    if (substance_amount.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::SubstanceAmount::Label()) + ":"
                  + std::to_string(substance_amount.Value()));
    }
    if (luminous_intensity.Value() != 0) {
      if (!text.empty()) {
        text.append(",");
      }
      text.append(SnakeCaseCopy(Dimension::LuminousIntensity::Label()) + ":"
                  + std::to_string(luminous_intensity.Value()));
    }
    return "{" + text + "}";
  }

private:
  // Base physical dimension of time of this physical dimension set.
  Dimension::Time time;

  // Base physical dimension of length of this physical dimension set.
  Dimension::Length length;

  // Base physical dimension of mass of this physical dimension set.
  Dimension::Mass mass;

  // Base physical dimension of electric current of this physical dimension set.
  Dimension::ElectricCurrent electric_current;

  // Base physical dimension of temperature of this physical dimension set.
  Dimension::Temperature temperature;

  // Base physical dimension of amount of substance of this physical dimension set.
  Dimension::SubstanceAmount substance_amount;

  // Base physical dimension of luminous intensity of this physical dimension set.
  Dimension::LuminousIntensity luminous_intensity;
};

inline constexpr bool operator==(const Dimensions& left, const Dimensions& right) noexcept {
  return left.Time() == right.Time() && left.Length() == right.Length()
         && left.Mass() == right.Mass() && left.ElectricCurrent() == right.ElectricCurrent()
         && left.Temperature() == right.Temperature()
         && left.SubstanceAmount() == right.SubstanceAmount()
         && left.LuminousIntensity() == right.LuminousIntensity();
}

inline constexpr bool operator!=(const Dimensions& left, const Dimensions& right) noexcept {
  return left.Time() != right.Time() || left.Length() != right.Length()
         || left.Mass() != right.Mass() || left.ElectricCurrent() != right.ElectricCurrent()
         || left.Temperature() != right.Temperature()
         || left.SubstanceAmount() != right.SubstanceAmount()
         || left.LuminousIntensity() != right.LuminousIntensity();
}

inline constexpr bool operator<(const Dimensions& left, const Dimensions& right) noexcept {
  if (left.Time() != right.Time()) {
    return left.Time() < right.Time();
  }
  if (left.Length() != right.Length()) {
    return left.Length() < right.Length();
  }
  if (left.Mass() != right.Mass()) {
    return left.Mass() < right.Mass();
  }
  if (left.ElectricCurrent() != right.ElectricCurrent()) {
    return left.ElectricCurrent() < right.ElectricCurrent();
  }
  if (left.Temperature() != right.Temperature()) {
    return left.Temperature() < right.Temperature();
  }
  if (left.SubstanceAmount() != right.SubstanceAmount()) {
    return left.SubstanceAmount() < right.SubstanceAmount();
  }
  return left.LuminousIntensity() < right.LuminousIntensity();
}

inline constexpr bool operator>(const Dimensions& left, const Dimensions& right) noexcept {
  if (left.Time() != right.Time()) {
    return left.Time() > right.Time();
  }
  if (left.Length() != right.Length()) {
    return left.Length() > right.Length();
  }
  if (left.Mass() != right.Mass()) {
    return left.Mass() > right.Mass();
  }
  if (left.ElectricCurrent() != right.ElectricCurrent()) {
    return left.ElectricCurrent() > right.ElectricCurrent();
  }
  if (left.Temperature() != right.Temperature()) {
    return left.Temperature() > right.Temperature();
  }
  if (left.SubstanceAmount() != right.SubstanceAmount()) {
    return left.SubstanceAmount() > right.SubstanceAmount();
  }
  return left.LuminousIntensity() > right.LuminousIntensity();
}

inline constexpr bool operator<=(const Dimensions& left, const Dimensions& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(const Dimensions& left, const Dimensions& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(std::ostream& stream, const Dimensions& dimensions) {
  stream << dimensions.Print();
  return stream;
}

// Dimensionless physical dimension set. This dimension set has all base dimensions of zero. Applies
// to all dimensionless units of measure and dimensionless physical quantities.
inline constexpr Dimensions Dimensionless;

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Dimensions> {
  inline size_t operator()(const PhQ::Dimensions& dimensions) const {
    size_t result{17};
    result = 31 * result + dimensions.Time().Value();
    result = 31 * result + dimensions.Length().Value();
    result = 31 * result + dimensions.Mass().Value();
    result = 31 * result + dimensions.ElectricCurrent().Value();
    result = 31 * result + dimensions.Temperature().Value();
    result = 31 * result + dimensions.SubstanceAmount().Value();
    result = 31 * result + dimensions.LuminousIntensity().Value();
    return result;
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONS_HPP
