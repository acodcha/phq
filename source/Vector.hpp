#pragma once

#include "Direction.hpp"

namespace PhQ {

namespace Value {

// Forward declaration of PhQ::Value::SymmetricCartesianDyad for PhQ::Value::CartesianVector.
class SymmetricCartesianDyad;

class CartesianVector {

public:

  CartesianVector() noexcept = default;

  constexpr CartesianVector(const std::array<double, 3>& x_y_z) noexcept : x_y_z_{x_y_z} {}

  constexpr CartesianVector(double x, double y, double z) noexcept : x_y_z_{x, y, z} {}

  constexpr CartesianVector(double magnitude, const CartesianDirection& cartesianDirection) : x_y_z_{magnitude * cartesianDirection.x(), magnitude * cartesianDirection.y(), magnitude * cartesianDirection.z()} {}

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

  constexpr double magnitude() const noexcept {
    return std::sqrt(std::pow(x_y_z_[0], 2) + std::pow(x_y_z_[1], 2) + std::pow(x_y_z_[2], 2));
  }

  CartesianDirection direction() const {
    return {*this};
  }

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(x_y_z_[0]) + ", " + PhQ::number_to_string(x_y_z_[1]) + ", " + PhQ::number_to_string(x_y_z_[2]) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\": " + PhQ::number_to_string(x_y_z_[0]) + ", \"y\": " + PhQ::number_to_string(x_y_z_[1]) + ", \"z\": " + PhQ::number_to_string(x_y_z_[2]) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + PhQ::number_to_string(x_y_z_[0]) + "</x><y>" + PhQ::number_to_string(x_y_z_[1]) + "</y><z>" + PhQ::number_to_string(x_y_z_[2]) + "</z>";
  }

  constexpr double dot(const CartesianDirection& other) const noexcept {
    return x_y_z_[0] * other.x() + x_y_z_[1] * other.y() + x_y_z_[2] * other.z();
  }

  constexpr double dot(const CartesianVector& other) const noexcept {
    return x_y_z_[0] * other.x_y_z_[0] + x_y_z_[1] * other.x_y_z_[1] + x_y_z_[2] * other.x_y_z_[2];
  }

  constexpr CartesianVector cross(const CartesianDirection& other) const noexcept {
    return {x_y_z_[1] * other.z() - x_y_z_[2] * other.y(), x_y_z_[2] * other.x() - x_y_z_[0] * other.z(), x_y_z_[0] * other.y() - x_y_z_[1] * other.x()};
  }

  constexpr CartesianVector cross(const CartesianVector& other) const noexcept {
    return {x_y_z_[1] * other.x_y_z_[2] - x_y_z_[2] * other.x_y_z_[1], x_y_z_[2] * other.x_y_z_[0] - x_y_z_[0] * other.x_y_z_[2], x_y_z_[0] * other.x_y_z_[1] - x_y_z_[1] * other.x_y_z_[0]};
  }

  constexpr bool operator==(const CartesianVector& other) const noexcept {
    return x_y_z_[0] == other.x_y_z_[0] && x_y_z_[1] == other.x_y_z_[1] && x_y_z_[2] == other.x_y_z_[2];
  }

  constexpr bool operator!=(const CartesianVector& other) const noexcept {
    return x_y_z_[0] != other.x_y_z_[0] || x_y_z_[1] != other.x_y_z_[1] || x_y_z_[2] != other.x_y_z_[2];
  }

  constexpr CartesianVector operator+(const CartesianVector& other) const noexcept {
    return {x_y_z_[0] + other.x_y_z_[0], x_y_z_[1] + other.x_y_z_[1], x_y_z_[2] + other.x_y_z_[2]};
  }

  constexpr void operator+=(const CartesianVector& other) noexcept {
    x_y_z_[0] += other.x_y_z_[0];
    x_y_z_[1] += other.x_y_z_[1];
    x_y_z_[2] += other.x_y_z_[2];
  }

  constexpr CartesianVector operator-(const CartesianVector& other) const noexcept {
    return {x_y_z_[0] - other.x_y_z_[0], x_y_z_[1] - other.x_y_z_[1], x_y_z_[2] - other.x_y_z_[2]};
  }

  constexpr void operator-=(const CartesianVector& other) noexcept {
    x_y_z_[0] -= other.x_y_z_[0];
    x_y_z_[1] -= other.x_y_z_[1];
    x_y_z_[2] -= other.x_y_z_[2];
  }

  constexpr CartesianVector operator*(const double& number) const noexcept {
    return {x_y_z_[0] * number, x_y_z_[1] * number, x_y_z_[2] * number};
  }

  constexpr void operator*=(const double& number) noexcept {
    x_y_z_[0] *= number;
    x_y_z_[1] *= number;
    x_y_z_[2] *= number;
  }

  constexpr CartesianVector operator/(const double& number) const {
    if (number != 0.0) {
      return {x_y_z_[0] / number, x_y_z_[1] / number, x_y_z_[2] / number};
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

  constexpr void operator/=(const double& number) {
    if (number != 0.0) {
      x_y_z_[0] /= number;
      x_y_z_[1] /= number;
      x_y_z_[2] /= number;
    } else {
      throw std::runtime_error{"Scalar division of " + print() + " by zero."};
    }
  }

protected:

  std::array<double, 3> x_y_z_;

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
  return x_y_z_[0] * other.x() + x_y_z_[1] * other.y() + x_y_z_[2] * other.z();
}

} // namespace PhQ
