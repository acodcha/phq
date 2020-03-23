#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class Length : public Base {

public:

  constexpr Length(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "L";
  }

};

} // namespace Dimension

} // namespace PhQ
