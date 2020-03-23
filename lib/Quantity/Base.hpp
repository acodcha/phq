#pragma once

#include "../Dimension/Set.hpp"

namespace PhQ {

class Quantity {

public:

  constexpr Quantity() noexcept = default;

  virtual Dimension::Set dimension() const noexcept = 0;

};

} // namespace PhQ
