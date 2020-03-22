#pragma once

#include "../Quantity/Direction.hpp"

namespace PhQ {

namespace Value {

class Vector {

public:

  Vector() noexcept = default;

  constexpr Vector(const std::array<double, 3>& x_y_z) noexcept : x_y_z_{x_y_z} {}

  constexpr Vector(double x, double y, double z) noexcept : x_y_z_{x, y, z} {}

  constexpr Vector(double r, const Direction& d) : x_y_z_{r * d.x(), r * d.y(), r * d.z()} {}

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

  Direction direction() const {
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

  constexpr double dot(const Direction& direction) const noexcept {
    return x_y_z_[0] * direction.x() + x_y_z_[1] * direction.y() + x_y_z_[2] * direction.z();
  }

  constexpr double dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1] + x_y_z_[2] * vector.x_y_z_[2];
  }

  constexpr Vector cross(const Direction& direction) const noexcept {
    return {x_y_z_[1] * direction.z() - x_y_z_[2] * direction.y(), x_y_z_[2] * direction.x() - x_y_z_[0] * direction.z(), x_y_z_[0] * direction.y() - x_y_z_[1] * direction.x()};
  }

  constexpr Vector cross(const Vector& vector) const noexcept {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1], x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2], x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  constexpr bool operator==(const Vector& vector) const noexcept {
    return x_y_z_[0] == vector.x_y_z_[0] && x_y_z_[1] == vector.x_y_z_[1] && x_y_z_[2] == vector.x_y_z_[2];
  }

  constexpr bool operator!=(const Vector& vector) const noexcept {
    return x_y_z_[0] != vector.x_y_z_[0] || x_y_z_[1] != vector.x_y_z_[1] || x_y_z_[2] != vector.x_y_z_[2];
  }

  constexpr Vector operator+(const Vector& vector) const noexcept {
    return {x_y_z_[0] + vector.x_y_z_[0], x_y_z_[1] + vector.x_y_z_[1], x_y_z_[2] + vector.x_y_z_[2]};
  }

  constexpr void operator+=(const Vector& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr Vector operator-(const Vector& vector) const noexcept {
    return {x_y_z_[0] - vector.x_y_z_[0], x_y_z_[1] - vector.x_y_z_[1], x_y_z_[2] - vector.x_y_z_[2]};
  }

  constexpr void operator-=(const Vector& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  constexpr Vector operator*(double real) const noexcept {
    return {x_y_z_[0] * real, x_y_z_[1] * real, x_y_z_[2] * real};
  }

  constexpr void operator*=(double real) noexcept {
    x_y_z_[0] *= real;
    x_y_z_[1] *= real;
    x_y_z_[2] *= real;
  }

  constexpr Vector operator/(double real) const {
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

} // namespace Value

template <> constexpr bool sort(const Value::Vector& vector1, const Value::Vector& vector2) noexcept {
  if (vector1.x() < vector2.x()) {
    return true;
  } else if (vector1.x() > vector2.x()) {
    return false;
  } else {
    if (vector1.y() < vector2.y()) {
      return true;
    } else if (vector1.y() > vector2.y()) {
      return false;
    } else {
      return vector1.z() < vector2.z();
    }
  }
}

Direction::Direction(const Value::Vector& vector) : Direction(vector.x(), vector.y(), vector.z()) {}

constexpr double Direction::dot(const Value::Vector& vector) const noexcept {
  return x_y_z_[0] * vector.x() + x_y_z_[1] * vector.y() + x_y_z_[2] * vector.z();
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::Vector& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}
