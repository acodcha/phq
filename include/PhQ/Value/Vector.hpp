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

  constexpr Vector() noexcept : x_y_z_() {}

  constexpr Vector(const std::array<double, 3>& x_y_z) noexcept : x_y_z_(x_y_z) {}

  constexpr Vector(double x, double y, double z) noexcept : x_y_z_({x, y, z}) {}

  constexpr Vector(double value, const Direction& direction) noexcept : x_y_z_({value * direction.x(), value * direction.y(), value * direction.z()}) {}

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

  constexpr Direction direction() const {
    return {*this};
  }

  constexpr double dot(const Direction& direction) const noexcept {
    return x_y_z_[0] * direction.x() + x_y_z_[1] * direction.y() + x_y_z_[2] * direction.z();
  }

  constexpr double dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1] + x_y_z_[2] * vector.x_y_z_[2];
  }

  constexpr Vector cross(const Direction& direction) const noexcept {
    return {
      x_y_z_[1] * direction.z() - x_y_z_[2] * direction.y(),
      x_y_z_[2] * direction.x() - x_y_z_[0] * direction.z(),
      x_y_z_[0] * direction.y() - x_y_z_[1] * direction.x()
    };
  }

  constexpr Vector cross(const Vector& vector) const noexcept {
    return {
      x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
      x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
      x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]
    };
  }

  constexpr Dyadic dyadic(const Direction& direction) const noexcept;

  constexpr Dyadic dyadic(const Vector& vector) const noexcept;

  constexpr Angle angle(const Direction& direction) const noexcept;

  constexpr Angle angle(const Vector& vector) const noexcept;

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(x_y_z_[0]) + ", " +
      PhQ::number_to_string(x_y_z_[1]) + ", " +
      PhQ::number_to_string(x_y_z_[2]) + ")";
  }

  std::string json() const noexcept {
    return
      "{\"x\": " + PhQ::number_to_string(x_y_z_[0]) +
      " , \"y\": " + PhQ::number_to_string(x_y_z_[1]) +
      " , \"z\": " + PhQ::number_to_string(x_y_z_[2]) + "}";
  }

  std::string xml() const noexcept {
    return
      "<x>" + PhQ::number_to_string(x_y_z_[0]) +
      "</x><y>" + PhQ::number_to_string(x_y_z_[1]) +
      "</y><z>" + PhQ::number_to_string(x_y_z_[2]) + "</z>";
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

  constexpr Vector operator/(double real) const noexcept {
    return {x_y_z_[0] / real, x_y_z_[1] / real, x_y_z_[2] / real};
  }

  constexpr void operator/=(double real) noexcept {
    x_y_z_[0] /= real;
    x_y_z_[1] /= real;
    x_y_z_[2] /= real;
  }

protected:

  std::array<double, 3> x_y_z_;

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
  return x_y_z_[0] * vector.x() + x_y_z_[1] * vector.y() + x_y_z_[2] * vector.z();
}

constexpr Value::Vector Direction::cross(const Value::Vector& vector) const noexcept {
  return {
    x_y_z_[1] * vector.z() - x_y_z_[2] * vector.y(),
    x_y_z_[2] * vector.x() - x_y_z_[0] * vector.z(),
    x_y_z_[0] * vector.y() - x_y_z_[1] * vector.x()
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
