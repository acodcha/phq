#pragma once

#include "../../Unit/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalQuantity : public Quantity {

public:

  constexpr DimensionalQuantity() noexcept : Quantity() {}

  Dimension::Set dimension() const noexcept {
    return PhQ::dimension<Unit>;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string print(Unit unit) const noexcept = 0;

  virtual std::string print(System system) const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string json(Unit unit) const noexcept = 0;

  virtual std::string json(System system) const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

  virtual std::string xml(Unit unit) const noexcept = 0;

  virtual std::string xml(System system) const noexcept = 0;

};

template <typename Unit> std::ostream& operator<<(std::ostream& stream, const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.print();
  return stream;
}

} // namespace PhQ
