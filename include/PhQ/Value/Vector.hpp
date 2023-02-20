// Copyright 2020 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP

#include "../Direction.hpp"

namespace PhQ {

namespace Value {

class Vector {
public:
  constexpr Vector() noexcept : x_y_z_() {}

  constexpr Vector(const double x, const double y, const double z) noexcept
      : x_y_z_({x, y, z}) {}

  constexpr Vector(const std::array<double, 3>& x_y_z) noexcept
      : x_y_z_(x_y_z) {}

  constexpr Vector(double value, const Direction& direction) noexcept
      : x_y_z_(std::array<double, 3>{value * direction.x(),
                                     value * direction.y(),
                                     value * direction.z()}) {}

  static constexpr Vector Zero() noexcept {
    return std::array<double, 3>{0.0, 0.0, 0.0};
  }

  inline constexpr const std::array<double, 3>& Value() const noexcept {
    return x_y_z_;
  }

  inline constexpr double x() const noexcept { return x_y_z_[0]; }

  inline constexpr double y() const noexcept { return x_y_z_[1]; }

  inline constexpr double z() const noexcept { return x_y_z_[2]; }

  inline constexpr double MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1] +
           x_y_z_[2] * x_y_z_[2];
  }

  inline double Magnitude() const noexcept {
    return std::sqrt(MagnitudeSquared());
  }

  PhQ::Direction Direction() const { return {*this}; }

  inline constexpr double Dot(const PhQ::Direction& direction) const noexcept {
    return x_y_z_[0] * direction.x() + x_y_z_[1] * direction.y() +
           x_y_z_[2] * direction.z();
  }

  inline constexpr double Dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1] +
           x_y_z_[2] * vector.x_y_z_[2];
  }

  inline constexpr Vector Cross(
      const PhQ::Direction& direction) const noexcept {
    return {x_y_z_[1] * direction.z() - x_y_z_[2] * direction.y(),
            x_y_z_[2] * direction.x() - x_y_z_[0] * direction.z(),
            x_y_z_[0] * direction.y() - x_y_z_[1] * direction.x()};
  }

  inline constexpr Vector Cross(const Vector& vector) const noexcept {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
            x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
            x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  inline constexpr Dyad Dyadic(const PhQ::Direction& direction) const noexcept;

  inline constexpr Dyad Dyadic(const Vector& vector) const noexcept;

  inline constexpr PhQ::Angle Angle(
      const PhQ::Direction& direction) const noexcept;

  inline constexpr PhQ::Angle Angle(const Vector& vector) const noexcept;

  inline std::string Print() const noexcept {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", " +
           PhQ::Print(x_y_z_[2]) + ")";
  }

  inline std::string Json() const noexcept {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) +
           ",\"y\":" + PhQ::Print(x_y_z_[1]) +
           ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  inline std::string Xml() const noexcept {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1]) +
           "</y><z>" + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  inline std::string Yaml() const noexcept {
    return "{x:" + PhQ::Print(x_y_z_[0]) + ",y:" + PhQ::Print(x_y_z_[1]) +
           ",z:" + PhQ::Print(x_y_z_[2]) + "}";
  }

  inline constexpr void operator+=(const Vector& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  inline constexpr void operator-=(const Vector& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  inline constexpr void operator*=(const double real) noexcept {
    x_y_z_[0] *= real;
    x_y_z_[1] *= real;
    x_y_z_[2] *= real;
  }

  inline constexpr void operator/=(const double real) noexcept {
    x_y_z_[0] /= real;
    x_y_z_[1] /= real;
    x_y_z_[2] /= real;
  }

private:
  std::array<double, 3> x_y_z_;
};

inline constexpr bool operator==(const Vector& left,
                                 const Vector& right) noexcept {
  return left.x() == right.x() && left.y() == right.y() &&
         left.z() == right.z();
}

inline constexpr bool operator!=(const Vector& left,
                                 const Vector& right) noexcept {
  return left.x() != right.x() || left.y() != right.y() ||
         left.z() != right.z();
}

inline constexpr Vector operator+(const Vector& left,
                                  const Vector& right) noexcept {
  return {left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

inline constexpr Vector operator-(const Vector& left,
                                  const Vector& right) noexcept {
  return {left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

inline constexpr Vector operator*(const Vector& vector,
                                  const double real) noexcept {
  return {vector.x() * real, vector.y() * real, vector.z() * real};
}

inline constexpr Vector operator*(const double real,
                                  const Vector& vector) noexcept {
  return {vector * real};
}

inline constexpr Vector operator/(const Vector& vector,
                                  const double real) noexcept {
  return {vector.x() / real, vector.y() / real, vector.z() / real};
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Vector& vector) noexcept {
  stream << vector.Print();
  return stream;
}

}  // namespace Value

Direction::Direction(const Value::Vector& vector)
    : Direction(vector.x(), vector.y(), vector.z()) {}

inline constexpr double Direction::Dot(
    const Value::Vector& vector) const noexcept {
  return x_y_z_[0] * vector.x() + x_y_z_[1] * vector.y() +
         x_y_z_[2] * vector.z();
}

inline constexpr Value::Vector Direction::Cross(
    const Value::Vector& vector) const noexcept {
  return {x_y_z_[1] * vector.z() - x_y_z_[2] * vector.y(),
          x_y_z_[2] * vector.x() - x_y_z_[0] * vector.z(),
          x_y_z_[0] * vector.y() - x_y_z_[1] * vector.x()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Value::Vector> {
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
