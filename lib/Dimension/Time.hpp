#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class Time : public Base {

public:

  constexpr Time(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "T";
  }

};

} // namespace Dimension

} // namespace PhQ
