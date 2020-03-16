#pragma once

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
    const ElectricCurrent& electricCurrent = {},
    const Temperature& temperature = {},
    const SubstanceAmount& substanceAmount = {},
    const LuminousIntensity& luminousIntensity = {})
  : myLength(length),
    myMass(mass),
    myTime(time),
    myElectricCurrent(electricCurrent),
    myTemperature(temperature),
    mySubstanceAmount(substanceAmount),
    myLuminousIntensity(luminousIntensity) {}

  constexpr const Length& length() const noexcept {
    return myLength;
  }

  constexpr const Mass& mass() const noexcept {
    return myMass;
  }

  constexpr const Time& time() const noexcept {
    return myTime;
  }

  constexpr const ElectricCurrent& electricCurrent() const noexcept {
    return myElectricCurrent;
  }

  constexpr const Temperature& temperature() const noexcept {
    return myTemperature;
  }

  constexpr const SubstanceAmount& substanceAmount() const noexcept {
    return mySubstanceAmount;
  }

  constexpr const LuminousIntensity& luminousIntensity() const noexcept {
    return myLuminousIntensity;
  }

  std::string string() const noexcept {
    std::string text;
    const std::string length{myLength.string()};
    const std::string mass{myMass.string()};
    const std::string time{myTime.string()};
    const std::string electricCurrent{myElectricCurrent.string()};
    const std::string temperature{myTemperature.string()};
    const std::string substanceAmount{mySubstanceAmount.string()};
    const std::string luminousIntensity{myLuminousIntensity.string()};
    text.append(length);
    if (!length.empty() && (!mass.empty() || !time.empty() || !electricCurrent.empty() || !temperature.empty() || !substanceAmount.empty() || !luminousIntensity.empty())) {
      text.append("·");
    }
    text.append(mass);
    if (!mass.empty() && (!time.empty() || !electricCurrent.empty() || !temperature.empty() || !substanceAmount.empty() || !luminousIntensity.empty())) {
      text.append("·");
    }
    text.append(time);
    if (!time.empty() && (!electricCurrent.empty() || !temperature.empty() || !substanceAmount.empty() || !luminousIntensity.empty())) {
      text.append("·");
    }
    text.append(electricCurrent);
    if (!electricCurrent.empty() && (!temperature.empty() || !substanceAmount.empty() || !luminousIntensity.empty())) {
      text.append("·");
    }
    text.append(temperature);
    if (!temperature.empty() && (!substanceAmount.empty() || !luminousIntensity.empty())) {
      text.append("·");
    }
    text.append(substanceAmount);
    if (!substanceAmount.empty() && !luminousIntensity.empty()) {
      text.append("·");
    }
    text.append(luminousIntensity);
    if (!text.empty()) {
      return text;
    } else {
      return "1";
    }
  }

  constexpr bool operator==(const Set& other) const noexcept {
    return myLength == other.myLength && myMass == other.myMass && myTime == other.myTime && myElectricCurrent == other.myElectricCurrent && myTemperature == other.myTemperature && mySubstanceAmount == other.mySubstanceAmount && myLuminousIntensity == other.myLuminousIntensity;
  }

  constexpr bool operator!=(const Set& other) const noexcept {
    return myLength != other.myLength || myMass != other.myMass || myTime != other.myTime || myElectricCurrent != other.myElectricCurrent || myTemperature != other.myTemperature || mySubstanceAmount != other.mySubstanceAmount || myLuminousIntensity != other.myLuminousIntensity;
  }

private:

  Length myLength;

  Mass myMass;

  Time myTime;

  ElectricCurrent myElectricCurrent;

  Temperature myTemperature;

  SubstanceAmount mySubstanceAmount;

  LuminousIntensity myLuminousIntensity;

};

std::ostream& operator<<(std::ostream& outputStream, const Set& set) {
  outputStream << set.string();
  return outputStream;
}

} // namespace Dimension

} // namespace PhQ
