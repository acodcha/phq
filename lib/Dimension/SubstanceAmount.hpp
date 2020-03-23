#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class SubstanceAmount : public Base {

public:

  constexpr SubstanceAmount(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "N";
  }

};

} // namespace Dimension

} // namespace PhQ
