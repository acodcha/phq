#pragma once

#include "../../Unit/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalQuantity : public Quantity {

public:

  constexpr DimensionalQuantity() noexcept : Quantity() {}

  constexpr Unit unit() const noexcept {
    return PhQ::Unit::standard<Unit>;
  }

  constexpr Dimension::Set dimension() const noexcept {
    return PhQ::Unit::dimension<Unit>(unit());
  }

  constexpr System system() const noexcept {
    return PhQ::standard;
  }

  virtual std::string print(System system = system()) const noexcept = 0;

  virtual std::string print(Unit unit = unit()) const noexcept = 0;

  virtual std::string json(System system = system()) const noexcept = 0;

  virtual std::string json(Unit unit = unit()) const noexcept = 0;

  virtual std::string xml(System system = system()) const noexcept = 0;

  virtual std::string xml(Unit unit = unit()) const noexcept = 0;

};

template <typename Unit> std::ostream& operator<<(std::ostream& stream, const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.print(quantity.unit());
  return stream;
}

/*
template <typename Unit> std::ostream& operator<<(std::ostream& stream, std::pair<DimensionalQuantity<Unit>, System>& quantity_and_system) noexcept {
  stream << quantity_and_system->first.print(quantity_and_system->second);
  return stream;
}

template <typename Unit> std::ostream& operator<<(std::ostream& stream, std::pair<DimensionalQuantity<Unit>, Unit>& quantity_and_unit) noexcept {
  stream << quantity_and_unit->first.print(quantity_and_unit->second);
  return stream;
}
*/

} // namespace PhQ
