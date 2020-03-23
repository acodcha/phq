#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class Temperature : public Base {

public:

  constexpr Temperature(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "Θ";
  }

};

} // namespace Dimension

} // namespace PhQ
