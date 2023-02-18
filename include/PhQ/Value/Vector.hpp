// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP

#include "../Direction.hpp"

namespace PhQ {

namespace Value {

class Vector {
public:
  constexpr Vector() noexcept : x_(), y_(), z_() {}

  constexpr Vector(const double x, const double y, const double z) noexcept : x_(x), y_(y), z_(z) {}

  constexpr Vector(const std::array<double, 3>& x_y_z) noexcept : x_(x_y_z[0]), y_(x_y_z[1]), z_(x_y_z[2]) {}

  constexpr Vector(double value, const Direction& direction) noexcept : x_(value * direction.x()), y_(value * direction.y()), z_(value * direction.z()) {}

  static constexpr Vector Zero() noexcept {
    return {0.0, 0.0, 0.0};
  }

  constexpr double x() const noexcept {
    return x_;
  }

  constexpr double y() const noexcept {
    return y_;
  }

  constexpr double z() const noexcept {
    return z_;
  }

  constexpr double magnitude_squared() const noexcept {
    return x_ * x_ + y_ * y_ + z_ * z_;
  }

  double magnitude() const noexcept {
    return std::sqrt(magnitude_squared());
  }

  Direction direction() const {
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
        x_ * direction.y() - y_ * direction.x()};
  }

  constexpr Vector cross(const Vector& vector) const noexcept {
    return {
        y_ * vector.z_ - z_ * vector.y_,
        z_ * vector.x_ - x_ * vector.z_,
        x_ * vector.y_ - y_ * vector.x_};
  }

  constexpr Dyadic dyadic(const Direction& direction) const noexcept;

  constexpr Dyadic dyadic(const Vector& vector) const noexcept;

  constexpr Angle angle(const Direction& direction) const noexcept;

  constexpr Angle angle(const Vector& vector) const noexcept;

  std::string print() const noexcept {
    return "(" + PhQ::print(x_) + ", " + PhQ::print(y_) + ", " + PhQ::print(z_) + ")";
  }

  std::string json() const noexcept {
    return "{\"x\":" + PhQ::print(x_) + ",\"y\":" + PhQ::print(y_) + ",\"z\":" + PhQ::print(z_) + "}";
  }

  std::string xml() const noexcept {
    return "<x>" + PhQ::print(x_) + "</x><y>" + PhQ::print(y_) + "</y><z>" + PhQ::print(z_) + "</z>";
  }

  std::string yaml() const noexcept {
    return "{x:" + PhQ::print(x_) + ",y:" + PhQ::print(y_) + ",z:" + PhQ::print(z_) + "}";
  }

  constexpr void operator+=(const Vector& vector) noexcept {
    x_ += vector.x_;
    y_ += vector.y_;
    z_ += vector.z_;
  }

  constexpr void operator-=(const Vector& vector) noexcept {
    x_ -= vector.x_;
    y_ -= vector.y_;
    z_ -= vector.z_;
  }

  constexpr void operator*=(const double real) noexcept {
    x_ *= real;
    y_ *= real;
    z_ *= real;
  }

  constexpr void operator/=(const double real) noexcept {
    x_ /= real;
    y_ /= real;
    z_ /= real;
  }

protected:
  double x_;

  double y_;

  double z_;
};

constexpr bool operator==(const Vector& left, const Vector& right) noexcept {
  return left.x() == right.x() && left.y() == right.y() && left.z() == right.z();
}

constexpr bool operator!=(const Vector& left, const Vector& right) noexcept {
  return left.x() != right.x() || left.y() != right.y() || left.z() != right.z();
}

constexpr Vector operator+(const Vector& left, const Vector& right) noexcept {
  return {left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

constexpr Vector operator-(const Vector& left, const Vector& right) noexcept {
  return {left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

constexpr Vector operator*(const Vector& vector, const double real) noexcept {
  return {vector.x() * real, vector.y() * real, vector.z() * real};
}

constexpr Vector operator*(const double real, const Vector& vector) noexcept {
  return {vector * real};
}

constexpr Vector operator/(const Vector& vector, const double real) noexcept {
  return {vector.x() / real, vector.y() / real, vector.z() / real};
}

std::ostream& operator<<(std::ostream& output_stream, const Vector& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}

}  // namespace Value

Direction::Direction(const Value::Vector& vector) : Direction(vector.x(), vector.y(), vector.z()) {}

constexpr double Direction::dot(const Value::Vector& vector) const noexcept {
  return x_ * vector.x() + y_ * vector.y() + z_ * vector.z();
}

constexpr Value::Vector Direction::cross(const Value::Vector& vector) const noexcept {
  return {
      y_ * vector.z() - z_ * vector.y(),
      z_ * vector.x() - x_ * vector.z(),
      x_ * vector.y() - y_ * vector.x()};
}

}  // namespace PhQ

namespace std {

template <> struct hash<PhQ::Value::Vector> {
  size_t operator()(const PhQ::Value::Vector& vector) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(vector.x());
    result = 31 * result + hash<double>()(vector.y());
    result = 31 * result + hash<double>()(vector.z());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP
