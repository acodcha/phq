// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Vector.hpp"

namespace PhQ {

namespace Value {

class SymmetricDyadic {

public:

  constexpr SymmetricDyadic() noexcept : xx_xy_xz_yy_yz_zz_() {}

  constexpr SymmetricDyadic(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept : xx_xy_xz_yy_yz_zz_(xx_xy_xz_yy_yz_zz) {}

  constexpr SymmetricDyadic(double xx, double xy, double xz, double yy, double yz, double zz) noexcept : xx_xy_xz_yy_yz_zz_({xx, xy, xz, yy, yz, zz}) {}

  constexpr std::array<double, 6> xx_xy_xz_yy_yz_zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_;
  }

  constexpr double xx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[0];
  }

  constexpr double xy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  constexpr double xz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  constexpr double yx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[1];
  }

  constexpr double yy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[3];
  }

  constexpr double yz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  constexpr double zx() const noexcept {
    return xx_xy_xz_yy_yz_zz_[2];
  }

  constexpr double zy() const noexcept {
    return xx_xy_xz_yy_yz_zz_[4];
  }

  constexpr double zz() const noexcept {
    return xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr bool is_symmetric() const noexcept {
    return true;
  }

  constexpr double trace() const noexcept {
    return xx() + yy() + zz();
  }

  constexpr double determinant() const noexcept {
    return
      xx() * (yy() * zz() - yz() * yz()) +
      xy() * (xz() * yz() - xy() * zz()) +
      xz() * (xy() * yz() - xz() * yy());
  }

  constexpr SymmetricDyadic transpose() const noexcept {
    return *this;
  }

  constexpr SymmetricDyadic cofactors() const noexcept {
    const double cofactor_xx{yy() * zz() - yz() * yz()};
    const double cofactor_xy{xz() * yz() - xy() * zz()};
    const double cofactor_xz{xy() * yz() - xz() * yy()};
    const double cofactor_yy{xx() * zz() - xz() * xz()};
    const double cofactor_yz{xy() * xz() - xx() * yz()};
    const double cofactor_zz{xx() * yy() - xy() * xy()};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yy, cofactor_yz, cofactor_zz};
  }

  constexpr SymmetricDyadic adjugate() const noexcept {
    return cofactors().transpose();
  }

  constexpr SymmetricDyadic inverse() const {
    const double determinant_{determinant()};
    if (determinant_ != 0.0) {
      return adjugate() / determinant_;
    } else {
      throw std::runtime_error{"Cannot compute the inverse of " + print() + " because its determinant is 0."};
    }
  }

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) + "; " +
      PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) + "; " +
      PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  std::string json() const noexcept {
    return
      "{\"xx\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) +
      ", \"xy\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) +
      ", \"xz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) +
      ", \"yy\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) +
      ", \"yz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) +
      ", \"zz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  std::string xml() const noexcept {
    return
      "<xx>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) +
      "</xx><xy>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) +
      "</xy><xz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) +
      "</xz><yy>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) +
      "</yy><yz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) +
      "</yz><zz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + "</zz>";
  }

  constexpr bool operator==(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return
      xx_xy_xz_yy_yz_zz_[0] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0] &&
      xx_xy_xz_yy_yz_zz_[1] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1] &&
      xx_xy_xz_yy_yz_zz_[2] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2] &&
      xx_xy_xz_yy_yz_zz_[3] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3] &&
      xx_xy_xz_yy_yz_zz_[4] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4] &&
      xx_xy_xz_yy_yz_zz_[5] == symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr bool operator!=(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return
      xx_xy_xz_yy_yz_zz_[0] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0] ||
      xx_xy_xz_yy_yz_zz_[1] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1] ||
      xx_xy_xz_yy_yz_zz_[2] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2] ||
      xx_xy_xz_yy_yz_zz_[3] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3] ||
      xx_xy_xz_yy_yz_zz_[4] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4] ||
      xx_xy_xz_yy_yz_zz_[5] != symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr SymmetricDyadic operator+(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0],
      xx_xy_xz_yy_yz_zz_[1] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1],
      xx_xy_xz_yy_yz_zz_[2] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2],
      xx_xy_xz_yy_yz_zz_[3] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3],
      xx_xy_xz_yy_yz_zz_[4] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4],
      xx_xy_xz_yy_yz_zz_[5] + symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5]
    };
  }

  constexpr void operator+=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr SymmetricDyadic operator-(const SymmetricDyadic& symmetric_dyadic) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0],
      xx_xy_xz_yy_yz_zz_[1] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1],
      xx_xy_xz_yy_yz_zz_[2] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2],
      xx_xy_xz_yy_yz_zz_[3] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3],
      xx_xy_xz_yy_yz_zz_[4] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4],
      xx_xy_xz_yy_yz_zz_[5] - symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5]
    };
  }

  constexpr void operator-=(const SymmetricDyadic& symmetric_dyadic) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= symmetric_dyadic.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr SymmetricDyadic operator*(double real) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] * real,
      xx_xy_xz_yy_yz_zz_[1] * real,
      xx_xy_xz_yy_yz_zz_[2] * real,
      xx_xy_xz_yy_yz_zz_[3] * real,
      xx_xy_xz_yy_yz_zz_[4] * real,
      xx_xy_xz_yy_yz_zz_[5] * real
    };
  }

  constexpr Vector operator*(const Vector& vector) const noexcept {
    return {
      xx() * vector.x() + xy() * vector.y() + xz() * vector.z(),
      yx() * vector.x() + yy() * vector.y() + yz() * vector.z(),
      zx() * vector.x() + zy() * vector.y() + zz() * vector.z()
    };
  }

  constexpr Dyadic operator*(const SymmetricDyadic& symmetric_dyadic) const noexcept;

  constexpr Dyadic operator*(const Dyadic& dyadic) const noexcept;

  constexpr void operator*=(double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= real;
    xx_xy_xz_yy_yz_zz_[1] *= real;
    xx_xy_xz_yy_yz_zz_[2] *= real;
    xx_xy_xz_yy_yz_zz_[3] *= real;
    xx_xy_xz_yy_yz_zz_[4] *= real;
    xx_xy_xz_yy_yz_zz_[5] *= real;
  }

  constexpr SymmetricDyadic operator/(double real) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] / real,
      xx_xy_xz_yy_yz_zz_[1] / real,
      xx_xy_xz_yy_yz_zz_[2] / real,
      xx_xy_xz_yy_yz_zz_[3] / real,
      xx_xy_xz_yy_yz_zz_[4] / real,
      xx_xy_xz_yy_yz_zz_[5] / real
    };
  }

  constexpr void operator/=(double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] /= real;
    xx_xy_xz_yy_yz_zz_[1] /= real;
    xx_xy_xz_yy_yz_zz_[2] /= real;
    xx_xy_xz_yy_yz_zz_[3] /= real;
    xx_xy_xz_yy_yz_zz_[4] /= real;
    xx_xy_xz_yy_yz_zz_[5] /= real;
  }

protected:

  std::array<double, 6> xx_xy_xz_yy_yz_zz_;

};

} // namespace Value

template <> constexpr bool sort(const Value::SymmetricDyadic& symmetric_dyadic_1, const Value::SymmetricDyadic& symmetric_dyadic_2) noexcept {
  if (symmetric_dyadic_1.xx() == symmetric_dyadic_2.xx()) {
    if (symmetric_dyadic_1.xy() == symmetric_dyadic_2.xy()) {
      if (symmetric_dyadic_1.xz() == symmetric_dyadic_2.xz()) {
        if (symmetric_dyadic_1.yy() == symmetric_dyadic_2.yy()) {
          if (symmetric_dyadic_1.yz() == symmetric_dyadic_2.yz()) {
            return symmetric_dyadic_1.zz() < symmetric_dyadic_2.zz();
          } else {
            return symmetric_dyadic_1.yz() < symmetric_dyadic_2.yz();
          }
        } else {
          return symmetric_dyadic_1.yy() < symmetric_dyadic_2.yy();
        }
      } else {
        return symmetric_dyadic_1.xz() < symmetric_dyadic_2.xz();
      }
    } else {
      return symmetric_dyadic_1.xy() < symmetric_dyadic_2.xy();
    }
  } else {
    return symmetric_dyadic_1.xx() < symmetric_dyadic_2.xx();
  }
}

} // namespace PhQ

constexpr PhQ::Value::SymmetricDyadic operator*(double real, const PhQ::Value::SymmetricDyadic& symmetric_dyadic) noexcept {
  return {symmetric_dyadic * real};
}

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::SymmetricDyadic& symmetric_dyadic) noexcept {
  output_stream << symmetric_dyadic.print();
  return output_stream;
}
