#pragma once

#include "../Base.hpp"

namespace PhQ {

namespace Dimension {

class Base {

public:

  constexpr Base(int_least8_t value = 0) noexcept : value_(value) {}

  constexpr int_least8_t value() const noexcept {
    return value_;
  }

  virtual std::string abbreviation() const noexcept = 0;

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

  constexpr bool operator==(const Base& base) const noexcept {
    return value_ == base.value_;
  }

  constexpr bool operator!=(const Base& base) const noexcept {
    return value_ != base.value_;
  }

  constexpr bool operator<(const Base& base) const noexcept {
    return value_ < base.value_;
  }

  constexpr bool operator<=(const Base& base) const noexcept {
    return value_ <= base.value_;
  }

  constexpr bool operator>(const Base& base) const noexcept {
    return value_ > base.value_;
  }

  constexpr bool operator>=(const Base& base) const noexcept {
    return value_ >= base.value_;
  }

protected:

  int_least8_t value_;

};

} // namespace Dimension

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Dimension::Base& base) noexcept {
  output_stream << base.print();
  return output_stream;
}
