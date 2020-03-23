#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class LuminousIntensity : public Base {

public:

  constexpr LuminousIntensity(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "J";
  }

};

} // namespace Dimension

} // namespace PhQ
