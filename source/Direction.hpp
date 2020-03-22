#pragma once

#include "Base/String.hpp"
#include "Base/Type.hpp"

namespace PhQ {

// Forward declarations.
namespace Value {
class Vector;
} // namespace Value
template <typename Unit> class DimensionalScalarQuantity;
template <typename Unit> class DimensionalVectorQuantity;

class Direction {

public:

  Direction() noexcept : x_y_z_{1.0, 0.0, 0.0} {}

  Direction(const std::array<double, 3>& x_y_z) {
    const double magnitude{std::sqrt(std::pow(x_y_z[0], 2) + std::pow(x_y_z[1], 2) + std::pow(x_y_z[2], 2))};
    if (magnitude > 0.0) {
      x_y_z_[0] = x_y_z[0] / magnitude;
      x_y_z_[1] = x_y_z[1] / magnitude;
      x_y_z_[2] = x_y_z[2] / magnitude;
    } else {
      throw std::runtime_error{"Attempting to create a cartesian direction from (0, 0, 0)."};
    }
  }

  Direction(double x, double y, double z) {
    const double magnitude{std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2))};
    if (magnitude > 0.0) {
      x_y_z_[0] = x / magnitude;
      x_y_z_[1] = y / magnitude;
      x_y_z_[2] = z / magnitude;
    } else {
      throw std::runtime_error{"Attempting to create a cartesian direction from (0, 0, 0)."};
    }
  }

  Direction(const Value::Vector& vector);

  constexpr std::array<double, 3> x_y_z() const noexcept {
    return x_y_z_;
  }

  constexpr double x() const noexcept {
    return x_y_z_[0];
  }

  constexpr double y() const noexcept {
    return x_y_z_[1];
  }

  constexpr double z() const noexcept {
    return x_y_z_[2];
  }

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(x_y_z_[0]) + ", " + PhQ::number_to_string(x_y_z_[1]) + ", " + PhQ::number_to_string(x_y_z_[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\":" + PhQ::number_to_string(x_y_z_[0]) + ", \"y\":" + PhQ::number_to_string(x_y_z_[1]) + ", \"z\":" + PhQ::number_to_string(x_y_z_[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + PhQ::number_to_string(x_y_z_[0]) + "</x><y>" + PhQ::number_to_string(x_y_z_[1]) + "</y><z>" + PhQ::number_to_string(x_y_z_[2]) + "</z>";
  }

  constexpr bool operator==(const Direction& direction) const noexcept {
    return x_y_z_[0] == direction.x_y_z_[0] && x_y_z_[1] == direction.x_y_z_[1] && x_y_z_[2] == direction.x_y_z_[2];
  }

  constexpr bool operator!=(const Direction& direction) const noexcept {
    return x_y_z_[0] != direction.x_y_z_[0] || x_y_z_[1] != direction.x_y_z_[1] || x_y_z_[2] != direction.x_y_z_[2];
  }

  template <typename Unit> constexpr DimensionalVectorQuantity<Unit> operator*(const DimensionalScalarQuantity<Unit>& scalar) const noexcept;

  constexpr double dot(const Direction& direction) const noexcept {
    return x_y_z_[0] * direction.x_y_z_[0] + x_y_z_[1] * direction.x_y_z_[1] + x_y_z_[2] * direction.x_y_z_[2];
  }

  constexpr double dot(const Value::Vector& vector) const noexcept;

private:

  std::array<double, 3> x_y_z_;

};

template <> constexpr bool sort(const Direction& direction1, const Direction& direction2) noexcept {
  if (direction1.x() < direction2.x()) {
    return true;
  } else if (direction1.x() > direction2.x()) {
    return false;
  } else {
    if (direction1.y() < direction2.y()) {
      return true;
    } else if (direction1.y() > direction2.y()) {
      return false;
    } else {
      return direction1.z() < direction2.z();
    }
  }
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Direction& direction) noexcept {
  output_stream << direction.print();
  return output_stream;
}
