#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class Mass : public Base {

public:

  constexpr Mass(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "M";
  }

};

} // namespace Dimension

} // namespace PhQ
