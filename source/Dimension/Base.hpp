#pragma once

#include "../Base.hpp"

namespace PhQ {

namespace Dimension {

class Base {

public:

  constexpr Base(int_least8_t value = 0) noexcept : myValue(value) {}

  constexpr const int_least8_t& value() const noexcept {
    return myValue;
  }

  std::string string() const noexcept {
    if (myValue == 0) {
      return {};
    } else if (myValue == 1) {
      return abbreviation();
    } else if (myValue > 0) {
      return abbreviation() + "^" + std::to_string(myValue);
    } else {
      return abbreviation() + "^(" + std::to_string(myValue) + ")";
    }
  }

  virtual std::string abbreviation() const noexcept = 0;

  constexpr bool operator==(const Base& other) const noexcept {
    return myValue == other.myValue;
  }

  constexpr bool operator!=(const Base& other) const noexcept {
    return myValue != other.myValue;
  }

  constexpr bool operator<(const Base& other) const noexcept {
    return myValue < other.myValue;
  }

  constexpr bool operator<=(const Base& other) const noexcept {
    return myValue <= other.myValue;
  }

  constexpr bool operator>(const Base& other) const noexcept {
    return myValue > other.myValue;
  }

  constexpr bool operator>=(const Base& other) const noexcept {
    return myValue >= other.myValue;
  }

protected:

  int_least8_t myValue;

};

std::ostream& operator<<(std::ostream& outputStream, const Base& base) noexcept {
  outputStream << base.string();
  return outputStream;
}

} // namespace Dimension

} // namespace PhQ
