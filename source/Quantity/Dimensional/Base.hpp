#pragma once

#include "../../Unit/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalQuantity : public Quantity {

public:

  constexpr DimensionalQuantity() noexcept : Quantity() {}

  constexpr Unit unit() const noexcept {
    return PhQ::standard_unit<Unit>;
  }

  constexpr Dimension::Set dimension() const noexcept {
    return PhQ::dimension<Unit>(unit());
  }

  virtual std::string print(System system = PhQ::standard_system) const noexcept = 0;

  virtual std::string print(Unit unit = PhQ::standard_unit<Unit>) const noexcept = 0;

  virtual std::string json(System system = PhQ::standard_system) const noexcept = 0;

  virtual std::string json(Unit unit = PhQ::standard_unit<Unit>) const noexcept = 0;

  virtual std::string xml(System system = PhQ::standard_system) const noexcept = 0;

  virtual std::string xml(Unit unit = PhQ::standard_unit<Unit>) const noexcept = 0;

};

template <typename Unit> std::ostream& operator<<(std::ostream& stream, const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.print(PhQ::standard_unit<Unit>);
  return stream;
}

} // namespace PhQ
