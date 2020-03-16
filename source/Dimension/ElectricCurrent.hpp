#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class ElectricCurrent : public Base {

public:

  constexpr ElectricCurrent(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "I";
  }

};

} // namespace Dimension

} // namespace PhQ
