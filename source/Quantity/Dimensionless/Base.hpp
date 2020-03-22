#pragma once

#include "../Base.hpp"

namespace PhQ {

class DimensionlessQuantity : public Quantity {

public:

  constexpr DimensionlessQuantity() noexcept : Quantity() {}

  Dimension::Set dimension() const noexcept {
    return {};
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

};

std::ostream& operator<<(std::ostream& stream, const DimensionlessQuantity& quantity) noexcept {
  stream << quantity.print();
  return stream;
}

} // namespace PhQ
