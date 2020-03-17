#pragma once

#include "Base.hpp"

namespace PhQ {

// Forward declaration of PhQ::Value::CartesianVector for PhQ::CartesianDirection.
namespace Value {

class CartesianVector;

} // namespace Value

class CartesianDirection {

public:

  CartesianDirection() noexcept : xyz_{1.0, 0.0, 0.0} {}

  CartesianDirection(double x, double y, double z) {
    const double magnitude{std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2))};
    if (magnitude > 0.0) {
      xyz_[0] = x / magnitude;
      xyz_[1] = y / magnitude;
      xyz_[2] = z / magnitude;
    } else {
      throw std::runtime_error{"Attempting to create a cartesian direction from (0, 0, 0)."};
    }
  }

  CartesianDirection(const Value::CartesianVector& cartesianVector);

  constexpr double x() const noexcept {
    return xyz_[0];
  }

  constexpr double y() const noexcept {
    return xyz_[1];
  }

  constexpr double z() const noexcept {
    return xyz_[2];
  }

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(xyz_[0]) + ", " + PhQ::number_to_string(xyz_[1]) + ", " + PhQ::number_to_string(xyz_[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\":" + PhQ::number_to_string(xyz_[0]) + ", \"y\":" + PhQ::number_to_string(xyz_[1]) + ", \"z\":" + PhQ::number_to_string(xyz_[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + PhQ::number_to_string(xyz_[0]) + "</x><y>" + PhQ::number_to_string(xyz_[1]) + "</y><z>" + PhQ::number_to_string(xyz_[2]) + "</z>";
  }

  constexpr bool operator==(const CartesianDirection& other) const noexcept {
    return xyz_[0] == other.xyz_[0] && xyz_[1] == other.xyz_[1] && xyz_[2] == other.xyz_[2];
  }

  constexpr bool operator!=(const CartesianDirection& other) const noexcept {
    return xyz_[0] != other.xyz_[0] || xyz_[1] != other.xyz_[1] || xyz_[2] != other.xyz_[2];
  }

  constexpr double dot(const CartesianDirection& other) const noexcept {
    return xyz_[0] * other.xyz_[0] + xyz_[1] * other.xyz_[1] + xyz_[2] * other.xyz_[2];
  }

  constexpr double dot(const Value::CartesianVector& other) const noexcept;

private:

  std::array<double, 3> xyz_;

};

std::ostream& operator<<(std::ostream& outputStream, const CartesianDirection& cartesianDirection) noexcept {
  outputStream << cartesianDirection.print();
  return outputStream;
}

} // namespace PhQ
