#pragma once

#include "Base.hpp"

namespace PhQ {

// Forward declaration of PhQ::Value::CartesianVector for PhQ::CartesianDirection.
namespace Value {

class CartesianVector;

} // namespace Value

class CartesianDirection {

public:

  CartesianDirection() noexcept : xyz{1.0, 0.0, 0.0} {}

  CartesianDirection(double x, double y, double z) {
    const double magnitude{std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2))};
    if (magnitude > 0.0) {
      xyz[0] = x / magnitude;
      xyz[1] = y / magnitude;
      xyz[2] = z / magnitude;
    } else {
      throw std::runtime_error{"Attempting to create a cartesian direction from (0, 0, 0)."};
    }
  }

  CartesianDirection(const Value::CartesianVector& cartesianVector);

  constexpr double x() const noexcept {
    return xyz[0];
  }

  constexpr double y() const noexcept {
    return xyz[1];
  }

  constexpr double z() const noexcept {
    return xyz[2];
  }

  std::string print() const noexcept {
    return "(" + real_number_to_string(xyz[0]) + ", " + real_number_to_string(xyz[1]) + ", " + real_number_to_string(xyz[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\":" + real_number_to_string(xyz[0]) + ", \"y\":" + real_number_to_string(xyz[1]) + ", \"z\":" + real_number_to_string(xyz[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + real_number_to_string(xyz[0]) + "</x><y>" + real_number_to_string(xyz[1]) + "</y><z>" + real_number_to_string(xyz[2]) + "</z>";
  }

  constexpr bool operator==(const CartesianDirection& other) const noexcept {
    return xyz[0] == other.xyz[0] && xyz[1] == other.xyz[1] && xyz[2] == other.xyz[2];
  }

  constexpr bool operator!=(const CartesianDirection& other) const noexcept {
    return xyz[0] != other.xyz[0] || xyz[1] != other.xyz[1] || xyz[2] != other.xyz[2];
  }

  constexpr double dot(const CartesianDirection& other) const noexcept {
    return xyz[0] * other.xyz[0] + xyz[1] * other.xyz[1] + xyz[2] * other.xyz[2];
  }

  constexpr double dot(const Value::CartesianVector& other) const noexcept;

private:

  std::array<double, 3> xyz;

};

std::ostream& operator<<(std::ostream& outputStream, const CartesianDirection& cartesianDirection) noexcept {
  outputStream << cartesianDirection.print();
  return outputStream;
}

} // namespace PhQ
