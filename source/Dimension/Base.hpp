#pragma once

#include "../Base.hpp"

namespace PhQ {

namespace Dimension {

class Base {

public:

  constexpr Base(int_least8_t value = 0) noexcept : value_(value) {}

  constexpr const int_least8_t& value() const noexcept {
    return value_;
  }

  std::string print() const noexcept {
    if (value_ == 0) {
      return {};
    } else if (value_ == 1) {
      return abbreviation();
    } else if (value_ > 0) {
      return abbreviation() + "^" + std::to_string(value_);
    } else {
      return abbreviation() + "^(" + std::to_string(value_) + ")";
    }
  }

  virtual std::string abbreviation() const noexcept = 0;

  constexpr bool operator==(const Base& other) const noexcept {
    return value_ == other.value_;
  }

  constexpr bool operator!=(const Base& other) const noexcept {
    return value_ != other.value_;
  }

  constexpr bool operator<(const Base& other) const noexcept {
    return value_ < other.value_;
  }

  constexpr bool operator<=(const Base& other) const noexcept {
    return value_ <= other.value_;
  }

  constexpr bool operator>(const Base& other) const noexcept {
    return value_ > other.value_;
  }

  constexpr bool operator>=(const Base& other) const noexcept {
    return value_ >= other.value_;
  }

protected:

  int_least8_t value_;

};

std::ostream& operator<<(std::ostream& stream, const Base& base) noexcept {
  stream << base.print();
  return stream;
}

} // namespace Dimension

} // namespace PhQ
