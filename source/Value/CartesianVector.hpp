#pragma once

#include "../Direction.hpp"

namespace PhQ {

namespace Value {

// Forward declaration of PhQ::Value::SymmetricCartesianDyad for PhQ::Value::CartesianVector.
class SymmetricCartesianDyad;

class CartesianVector {

public:

  CartesianVector() noexcept = default;

  constexpr CartesianVector(double x, double y, double z) noexcept : xyz{x, y, z} {}

  constexpr CartesianVector(double magnitude, const CartesianDirection& cartesianDirection) : xyz{magnitude * cartesianDirection.x(), magnitude * cartesianDirection.y(), magnitude * cartesianDirection.z()} {}

  constexpr double x() const noexcept {
    return xyz[0];
  }

  constexpr double y() const noexcept {
    return xyz[1];
  }

  constexpr double z() const noexcept {
    return xyz[2];
  }

  double magnitude() const noexcept {
    return std::sqrt(std::pow(xyz[0], 2) + std::pow(xyz[1], 2) + std::pow(xyz[2], 2));
  }

  CartesianDirection direction() const {
    return {*this};
  }

  std::string print() const noexcept {
    return "(" + real_number_to_string(xyz[0]) + ", " + real_number_to_string(xyz[1]) + ", " + real_number_to_string(xyz[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\": " + real_number_to_string(xyz[0]) + ", \"y\": " + real_number_to_string(xyz[1]) + ", \"z\": " + real_number_to_string(xyz[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + real_number_to_string(xyz[0]) + "</x><y>" + real_number_to_string(xyz[1]) + "</y><z>" + real_number_to_string(xyz[2]) + "</z>";
  }

  constexpr double dot(const CartesianDirection& other) const noexcept {
    return xyz[0] * other.x() + xyz[1] * other.y() + xyz[2] * other.z();
  }

  constexpr double dot(const CartesianVector& other) const noexcept {
    return xyz[0] * other.xyz[0] + xyz[1] * other.xyz[1] + xyz[2] * other.xyz[2];
  }

  constexpr CartesianVector cross(const CartesianDirection& other) const noexcept {
    return {xyz[1] * other.z() - xyz[2] * other.y(), xyz[2] * other.x() - xyz[0] * other.z(), xyz[0] * other.y() - xyz[1] * other.x()};
  }

  constexpr CartesianVector cross(const CartesianVector& other) const noexcept {
    return {xyz[1] * other.xyz[2] - xyz[2] * other.xyz[1], xyz[2] * other.xyz[0] - xyz[0] * other.xyz[2], xyz[0] * other.xyz[1] - xyz[1] * other.xyz[0]};
  }

  constexpr bool operator==(const CartesianVector& other) const noexcept {
    return xyz[0] == other.xyz[0] && xyz[1] == other.xyz[1] && xyz[2] == other.xyz[2];
  }

  constexpr bool operator!=(const CartesianVector& other) const noexcept {
    return xyz[0] != other.xyz[0] || xyz[1] != other.xyz[1] || xyz[2] != other.xyz[2];
  }

  constexpr CartesianVector operator+(const CartesianVector& other) const noexcept {
    return {xyz[0] + other.xyz[0], xyz[1] + other.xyz[1], xyz[2] + other.xyz[2]};
  }

  constexpr void operator+=(const CartesianVector& other) noexcept {
    xyz[0] += other.xyz[0];
    xyz[1] += other.xyz[1];
    xyz[2] += other.xyz[2];
  }

  constexpr CartesianVector operator-(const CartesianVector& other) const noexcept {
    return {xyz[0] - other.xyz[0], xyz[1] - other.xyz[1], xyz[2] - other.xyz[2]};
  }

  constexpr void operator-=(const CartesianVector& other) noexcept {
    xyz[0] -= other.xyz[0];
    xyz[1] -= other.xyz[1];
    xyz[2] -= other.xyz[2];
  }

  constexpr CartesianVector operator*(const double& real_number) const noexcept {
    return {xyz[0] * real_number, xyz[1] * real_number, xyz[2] * real_number};
  }

  constexpr void operator*=(const double& real_number) noexcept {
    xyz[0] *= real_number;
    xyz[1] *= real_number;
    xyz[2] *= real_number;
  }

  constexpr CartesianVector operator/(const double& real_number) const {
    if (real_number != 0.0) {
      return {xyz[0] / real_number, xyz[1] / real_number, xyz[2] / real_number};
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

  constexpr void operator/=(const double& real_number) {
    if (real_number != 0.0) {
      xyz[0] /= real_number;
      xyz[1] /= real_number;
      xyz[2] /= real_number;
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

protected:

  std::array<double, 3> xyz;

};

constexpr CartesianVector operator*(double number, const CartesianVector& cartesian_vector) noexcept {
  return {cartesian_vector * number};
}

std::ostream& operator<<(std::ostream& stream, const CartesianVector& cartesian_vector) noexcept {
  stream << cartesian_vector.print();
  return stream;
}

} // namespace Value

CartesianDirection::CartesianDirection(const Value::CartesianVector& cartesian_vector) : CartesianDirection(cartesian_vector.x(), cartesian_vector.y(), cartesian_vector.z()) {}

constexpr double CartesianDirection::dot(const Value::CartesianVector& other) const noexcept {
  return xyz[0] * other.x() + xyz[1] * other.y() + xyz[2] * other.z();
}

} // namespace PhQ
