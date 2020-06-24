// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Direction.hpp"

namespace PhQ {

namespace Value {

class Vector {

public:

  constexpr Vector() noexcept : x_(), y_(), z_() {}

  constexpr Vector(double x, double y, double z) noexcept : x_(x), y_(y), z_(z) {}

  constexpr Vector(const std::array<double, 3>& x_y_z) noexcept : x_(x_y_z[0]), y_(x_y_z[1]), z_(x_y_z[2]) {}

  constexpr Vector(double value, const Direction& direction) noexcept : x_(value * direction.x()), y_(value * direction.y()), z_(value * direction.z()) {}

  constexpr double x() const noexcept {
    return x_;
  }

  constexpr double y() const noexcept {
    return y_;
  }

  constexpr double z() const noexcept {
    return z_;
  }

  constexpr double magnitude() const noexcept {
    return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2) + std::pow(z_, 2));
  }

  constexpr Direction direction() const {
    return {*this};
  }

  constexpr double dot(const Direction& direction) const noexcept {
    return x_ * direction.x() + y_ * direction.y() + z_ * direction.z();
  }

  constexpr double dot(const Vector& vector) const noexcept {
    return x_ * vector.x_ + y_ * vector.y_ + z_ * vector.z_;
  }

  constexpr Vector cross(const Direction& direction) const noexcept {
    return {
      y_ * direction.z() - z_ * direction.y(),
      z_ * direction.x() - x_ * direction.z(),
      x_ * direction.y() - y_ * direction.x()
    };
  }

  constexpr Vector cross(const Vector& vector) const noexcept {
    return {
      y_ * vector.z_ - z_ * vector.y_,
      z_ * vector.x_ - x_ * vector.z_,
      x_ * vector.y_ - y_ * vector.x_
    };
  }

  constexpr Dyadic dyadic(const Direction& direction) const noexcept;

  constexpr Dyadic dyadic(const Vector& vector) const noexcept;

  constexpr Angle angle(const Direction& direction) const noexcept;

  constexpr Angle angle(const Vector& vector) const noexcept;

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(x_) + ", " +
      PhQ::number_to_string(y_) + ", " +
      PhQ::number_to_string(z_) + ")";
  }

  std::string yaml() const noexcept {
    return
      "{x:" + PhQ::number_to_string(x_) +
      " , y:" + PhQ::number_to_string(y_) +
      " , z:" + PhQ::number_to_string(z_) + "}";
  }

  std::string json() const noexcept {
    return
      "{\"x\": " + PhQ::number_to_string(x_) +
      " , \"y\": " + PhQ::number_to_string(y_) +
      " , \"z\": " + PhQ::number_to_string(z_) + "}";
  }

  std::string xml() const noexcept {
    return
      "<x>" + PhQ::number_to_string(x_) +
      "</x><y>" + PhQ::number_to_string(y_) +
      "</y><z>" + PhQ::number_to_string(z_) + "</z>";
  }

  constexpr bool operator==(const Vector& vector) const noexcept {
    return x_ == vector.x_ && y_ == vector.y_ && z_ == vector.z_;
  }

  constexpr bool operator!=(const Vector& vector) const noexcept {
    return x_ != vector.x_ || y_ != vector.y_ || z_ != vector.z_;
  }

  constexpr Vector operator+(const Vector& vector) const noexcept {
    return {x_ + vector.x_, y_ + vector.y_, z_ + vector.z_};
  }

  constexpr void operator+=(const Vector& vector) noexcept {
    x_ += vector.x_;
    y_ += vector.y_;
    z_ += vector.z_;
  }

  constexpr Vector operator-(const Vector& vector) const noexcept {
    return {x_ - vector.x_, y_ - vector.y_, z_ - vector.z_};
  }

  constexpr void operator-=(const Vector& vector) noexcept {
    x_ -= vector.x_;
    y_ -= vector.y_;
    z_ -= vector.z_;
  }

  constexpr Vector operator*(double real) const noexcept {
    return {x_ * real, y_ * real, z_ * real};
  }

  constexpr void operator*=(double real) noexcept {
    x_ *= real;
    y_ *= real;
    z_ *= real;
  }

  constexpr Vector operator/(double real) const noexcept {
    return {x_ / real, y_ / real, z_ / real};
  }

  constexpr void operator/=(double real) noexcept {
    x_ /= real;
    y_ /= real;
    z_ /= real;
  }

protected:

  double x_;

  double y_;

  double z_;

};

} // namespace Value

template <> constexpr bool sort(const Value::Vector& vector_1, const Value::Vector& vector_2) noexcept {
  if (vector_1.x() == vector_2.x()) {
    if (vector_1.y() == vector_2.y()) {
      return vector_1.z() < vector_2.z();
    } else {
      return vector_1.y() < vector_2.y();
    }
  } else {
    return vector_1.x() < vector_2.x();
  }
}

constexpr Direction::Direction(const Value::Vector& vector) : Direction(vector.x(), vector.y(), vector.z()) {}

constexpr double Direction::dot(const Value::Vector& vector) const noexcept {
  return x_ * vector.x() + y_ * vector.y() + z_ * vector.z();
}

constexpr Value::Vector Direction::cross(const Value::Vector& vector) const noexcept {
  return {
    y_ * vector.z() - z_ * vector.y(),
    z_ * vector.x() - x_ * vector.z(),
    x_ * vector.y() - y_ * vector.x()
  };
}

} // namespace PhQ

constexpr PhQ::Value::Vector operator*(double real, const PhQ::Value::Vector& vector) noexcept {
  return {vector * real};
}

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::Vector& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}
