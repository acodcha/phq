#pragma once

#include "../../Unit/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalQuantity : public Quantity {

public:

  constexpr DimensionalQuantity() noexcept : Quantity() {}

  constexpr Dimension::Set dimension() const noexcept {
    return PhQ::dimension<Unit>();
  }

  virtual std::string print(Unit unit = standard_unit<Unit>) const noexcept = 0;

  virtual std::string json(Unit unit = standard_unit<Unit>) const noexcept = 0;

  virtual std::string xml(Unit unit = standard_unit<Unit>) const noexcept = 0;

};

template <typename Unit> std::ostream& operator<<(std::ostream& stream, const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.print();
  return stream;
}

} // namespace PhQ
