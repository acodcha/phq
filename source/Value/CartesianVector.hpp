#pragma once

#include "../Direction.hpp"

namespace PhQ {

namespace Value {

// Forward declaration of PhQ::Value::SymmetricCartesianDyad for PhQ::Value::CartesianVector.
class SymmetricCartesianDyad;

class CartesianVector {

public:

  CartesianVector() noexcept = default;

  constexpr CartesianVector(double x, double y, double z) noexcept : xyz_{x, y, z} {}

  constexpr CartesianVector(double magnitude, const CartesianDirection& cartesianDirection) : xyz_{magnitude * cartesianDirection.x(), magnitude * cartesianDirection.y(), magnitude * cartesianDirection.z()} {}

  constexpr double x() const noexcept {
    return xyz_[0];
  }

  constexpr double y() const noexcept {
    return xyz_[1];
  }

  constexpr double z() const noexcept {
    return xyz_[2];
  }

  double magnitude() const noexcept {
    return std::sqrt(std::pow(xyz_[0], 2) + std::pow(xyz_[1], 2) + std::pow(xyz_[2], 2));
  }

  CartesianDirection direction() const {
    return {*this};
  }

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(xyz_[0]) + ", " + PhQ::number_to_string(xyz_[1]) + ", " + PhQ::number_to_string(xyz_[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\": " + PhQ::number_to_string(xyz_[0]) + ", \"y\": " + PhQ::number_to_string(xyz_[1]) + ", \"z\": " + PhQ::number_to_string(xyz_[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + PhQ::number_to_string(xyz_[0]) + "</x><y>" + PhQ::number_to_string(xyz_[1]) + "</y><z>" + PhQ::number_to_string(xyz_[2]) + "</z>";
  }

  constexpr double dot(const CartesianDirection& other) const noexcept {
    return xyz_[0] * other.x() + xyz_[1] * other.y() + xyz_[2] * other.z();
  }

  constexpr double dot(const CartesianVector& other) const noexcept {
    return xyz_[0] * other.xyz_[0] + xyz_[1] * other.xyz_[1] + xyz_[2] * other.xyz_[2];
  }

  constexpr CartesianVector cross(const CartesianDirection& other) const noexcept {
    return {xyz_[1] * other.z() - xyz_[2] * other.y(), xyz_[2] * other.x() - xyz_[0] * other.z(), xyz_[0] * other.y() - xyz_[1] * other.x()};
  }

  constexpr CartesianVector cross(const CartesianVector& other) const noexcept {
    return {xyz_[1] * other.xyz_[2] - xyz_[2] * other.xyz_[1], xyz_[2] * other.xyz_[0] - xyz_[0] * other.xyz_[2], xyz_[0] * other.xyz_[1] - xyz_[1] * other.xyz_[0]};
  }

  constexpr bool operator==(const CartesianVector& other) const noexcept {
    return xyz_[0] == other.xyz_[0] && xyz_[1] == other.xyz_[1] && xyz_[2] == other.xyz_[2];
  }

  constexpr bool operator!=(const CartesianVector& other) const noexcept {
    return xyz_[0] != other.xyz_[0] || xyz_[1] != other.xyz_[1] || xyz_[2] != other.xyz_[2];
  }

  constexpr CartesianVector operator+(const CartesianVector& other) const noexcept {
    return {xyz_[0] + other.xyz_[0], xyz_[1] + other.xyz_[1], xyz_[2] + other.xyz_[2]};
  }

  constexpr void operator+=(const CartesianVector& other) noexcept {
    xyz_[0] += other.xyz_[0];
    xyz_[1] += other.xyz_[1];
    xyz_[2] += other.xyz_[2];
  }

  constexpr CartesianVector operator-(const CartesianVector& other) const noexcept {
    return {xyz_[0] - other.xyz_[0], xyz_[1] - other.xyz_[1], xyz_[2] - other.xyz_[2]};
  }

  constexpr void operator-=(const CartesianVector& other) noexcept {
    xyz_[0] -= other.xyz_[0];
    xyz_[1] -= other.xyz_[1];
    xyz_[2] -= other.xyz_[2];
  }

  constexpr CartesianVector operator*(const double& real_number) const noexcept {
    return {xyz_[0] * real_number, xyz_[1] * real_number, xyz_[2] * real_number};
  }

  constexpr void operator*=(const double& real_number) noexcept {
    xyz_[0] *= real_number;
    xyz_[1] *= real_number;
    xyz_[2] *= real_number;
  }

  constexpr CartesianVector operator/(const double& real_number) const {
    if (real_number != 0.0) {
      return {xyz_[0] / real_number, xyz_[1] / real_number, xyz_[2] / real_number};
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

  constexpr void operator/=(const double& real_number) {
    if (real_number != 0.0) {
      xyz_[0] /= real_number;
      xyz_[1] /= real_number;
      xyz_[2] /= real_number;
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

protected:

  std::array<double, 3> xyz_;

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
  return xyz_[0] * other.x() + xyz_[1] * other.y() + xyz_[2] * other.z();
}

} // namespace PhQ
