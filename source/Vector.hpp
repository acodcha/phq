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

  constexpr CartesianVector(double r, const CartesianDirection& d) : x_y_z_{r * d.x(), r * d.y(), r * d.z()} {}

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

  constexpr double dot(const CartesianDirection& direction) const noexcept {
    return x_y_z_[0] * direction.x() + x_y_z_[1] * direction.y() + x_y_z_[2] * direction.z();
  }

  constexpr double dot(const CartesianVector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1] + x_y_z_[2] * vector.x_y_z_[2];
  }

  constexpr CartesianVector cross(const CartesianDirection& direction) const noexcept {
    return {x_y_z_[1] * direction.z() - x_y_z_[2] * direction.y(), x_y_z_[2] * direction.x() - x_y_z_[0] * direction.z(), x_y_z_[0] * direction.y() - x_y_z_[1] * direction.x()};
  }

  constexpr CartesianVector cross(const CartesianVector& vector) const noexcept {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1], x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2], x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  constexpr bool operator==(const CartesianVector& vector) const noexcept {
    return x_y_z_[0] == vector.x_y_z_[0] && x_y_z_[1] == vector.x_y_z_[1] && x_y_z_[2] == vector.x_y_z_[2];
  }

  constexpr bool operator!=(const CartesianVector& vector) const noexcept {
    return x_y_z_[0] != vector.x_y_z_[0] || x_y_z_[1] != vector.x_y_z_[1] || x_y_z_[2] != vector.x_y_z_[2];
  }

  constexpr CartesianVector operator+(const CartesianVector& vector) const noexcept {
    return {x_y_z_[0] + vector.x_y_z_[0], x_y_z_[1] + vector.x_y_z_[1], x_y_z_[2] + vector.x_y_z_[2]};
  }

  constexpr void operator+=(const CartesianVector& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr CartesianVector operator-(const CartesianVector& vector) const noexcept {
    return {x_y_z_[0] - vector.x_y_z_[0], x_y_z_[1] - vector.x_y_z_[1], x_y_z_[2] - vector.x_y_z_[2]};
  }

  constexpr void operator-=(const CartesianVector& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  constexpr CartesianVector operator*(double real) const noexcept {
    return {x_y_z_[0] * real, x_y_z_[1] * real, x_y_z_[2] * real};
  }

  constexpr void operator*=(double real) noexcept {
    x_y_z_[0] *= real;
    x_y_z_[1] *= real;
    x_y_z_[2] *= real;
  }

  constexpr CartesianVector operator/(double real) const {
    if (real != 0.0) {
      return {x_y_z_[0] / real, x_y_z_[1] / real, x_y_z_[2] / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr void operator/=(double real) {
    if (real != 0.0) {
      x_y_z_[0] /= real;
      x_y_z_[1] /= real;
      x_y_z_[2] /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

protected:

  std::array<double, 3> x_y_z_;

};

std::ostream& operator<<(std::ostream& output_stream, const CartesianVector& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}

} // namespace Value

CartesianDirection::CartesianDirection(const Value::CartesianVector& vector) : CartesianDirection(vector.x(), vector.y(), vector.z()) {}

constexpr double CartesianDirection::dot(const Value::CartesianVector& vector) const noexcept {
  return x_y_z_[0] * vector.x() + x_y_z_[1] * vector.y() + x_y_z_[2] * vector.z();
}

} // namespace PhQ
