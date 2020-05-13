// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "SymmetricDyadic.hpp"

namespace PhQ {

namespace Value {

class Dyadic {

public:

  constexpr Dyadic() noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_() {}

  constexpr Dyadic(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  constexpr Dyadic(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz) noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_({xx, xy, xz, yx, yy, yz, zx, zy, zz}) {}

  constexpr Dyadic(const SymmetricDyadic& symmetric_dyadic) noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_({symmetric_dyadic.xx(), symmetric_dyadic.xy(), symmetric_dyadic.xz(), symmetric_dyadic.yx(), symmetric_dyadic.yy(), symmetric_dyadic.yz(), symmetric_dyadic.zx(), symmetric_dyadic.zy(), symmetric_dyadic.zz()}) {}

  constexpr std::array<double, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  constexpr double xx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  constexpr double xy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  constexpr double xz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  constexpr double yx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  constexpr double yy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  constexpr double yz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  constexpr double zx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  constexpr double zy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  constexpr double zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr bool is_symmetric() const noexcept {
    return xy() == yx() && xz() == zx() && yz() == zy();
  }

  constexpr double trace() const noexcept {
    return xx() + yy() + zz();
  }

  constexpr double determinant() const noexcept {
    return
      xx() * (yy() * zz() - yz() * zy()) +
      xy() * (yz() * zx() - yx() * zz()) +
      xz() * (yx() * zy() - yy() * zx());
  }

  constexpr Dyadic transpose() const noexcept {
    return {xx(), yx(), zx(), xy(), yy(), zy(), xz(), yz(), zz()};
  }

  constexpr Dyadic cofactors() const noexcept {
    const double cofactor_xx{yy() * zz() - yz() * zy()};
    const double cofactor_xy{yz() * zx() - yx() * zz()};
    const double cofactor_xz{yx() * zy() - yy() * zx()};
    const double cofactor_yx{xz() * zy() - xy() * zz()};
    const double cofactor_yy{xx() * zz() - xz() * zx()};
    const double cofactor_yz{xy() * zx() - xx() * zy()};
    const double cofactor_zx{xy() * yz() - xz() * yy()};
    const double cofactor_zy{xz() * yx() - xx() * yz()};
    const double cofactor_zz{xx() * yy() - xy() * yx()};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy, cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  constexpr Dyadic adjugate() const noexcept {
    return cofactors().transpose();
  }

  Dyadic inverse() const {
    const double determinant_{determinant()};
    if (determinant_ != 0.0) {
      return adjugate() / determinant_;
    } else {
      throw std::runtime_error{"Cannot compute the inverse of " + print() + " because its determinant is 0."};
    }
  }

  std::string print() const noexcept {
    return
      "(" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) + "; " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) + "; " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) + ", " +
      PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + ")";
  }

  std::string json() const noexcept {
    return
      "{\"xx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) +
      ", \"xy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) +
      ", \"xz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) +
      ", \"yx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) +
      ", \"yy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) +
      ", \"yz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) +
      ", \"zx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) +
      ", \"zy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) +
      ", \"zz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + "}";
  }

  std::string xml() const noexcept {
    return
      "<xx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) +
      "</xx><xy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) +
      "</xy><xz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) +
      "</xz><yx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) +
      "</yx><yy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) +
      "</yy><yz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) +
      "</yz><zx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) +
      "</zx><zy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) +
      "</zy><zz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + "</zz>";
  }

  constexpr bool operator==(const Dyadic& dyadic) const noexcept {
    return
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] &&
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] == dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr bool operator!=(const Dyadic& dyadic) const noexcept {
    return
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] ||
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] != dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr Dyadic operator+(const Dyadic& dyadic) const noexcept {
    return {
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] + dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]
    };
  }

  constexpr void operator+=(const Dyadic& dyadic) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] += dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr Dyadic operator-(const Dyadic& dyadic) const noexcept {
    return {
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7],
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] - dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]
    };
  }

  constexpr void operator-=(const Dyadic& dyadic) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] -= dyadic.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr Dyadic operator*(double real) const noexcept {
    return {
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] * real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] * real
    };
  }

  constexpr Vector operator*(const Vector& vector) const noexcept {
    return {
      xx() * vector.x() + xy() * vector.y() + xz() * vector.z(),
      yx() * vector.x() + yy() * vector.y() + yz() * vector.z(),
      zx() * vector.x() + zy() * vector.y() + zz() * vector.z()
    };
  }

  constexpr Dyadic operator*(const SymmetricDyadic& dyadic) const noexcept {
    return {
      xx() * dyadic.xx() + xy() * dyadic.yx() + xz() * dyadic.zx(),
      xx() * dyadic.xy() + xy() * dyadic.yy() + xz() * dyadic.zy(),
      xx() * dyadic.xz() + xy() * dyadic.yz() + xz() * dyadic.zz(),
      yx() * dyadic.xx() + yy() * dyadic.yx() + yz() * dyadic.zx(),
      yx() * dyadic.xy() + yy() * dyadic.yy() + yz() * dyadic.zy(),
      yx() * dyadic.xz() + yy() * dyadic.yz() + yz() * dyadic.zz(),
      zx() * dyadic.xx() + zy() * dyadic.yx() + zz() * dyadic.zx(),
      zx() * dyadic.xy() + zy() * dyadic.yy() + zz() * dyadic.zy(),
      zx() * dyadic.xz() + zy() * dyadic.yz() + zz() * dyadic.zz()
    };
  }

  constexpr Dyadic operator*(const Dyadic& dyadic) const noexcept {
    return {
      xx() * dyadic.xx() + xy() * dyadic.yx() + xz() * dyadic.zx(),
      xx() * dyadic.xy() + xy() * dyadic.yy() + xz() * dyadic.zy(),
      xx() * dyadic.xz() + xy() * dyadic.yz() + xz() * dyadic.zz(),
      yx() * dyadic.xx() + yy() * dyadic.yx() + yz() * dyadic.zx(),
      yx() * dyadic.xy() + yy() * dyadic.yy() + yz() * dyadic.zy(),
      yx() * dyadic.xz() + yy() * dyadic.yz() + yz() * dyadic.zz(),
      zx() * dyadic.xx() + zy() * dyadic.yx() + zz() * dyadic.zx(),
      zx() * dyadic.xy() + zy() * dyadic.yy() + zz() * dyadic.zy(),
      zx() * dyadic.xz() + zy() * dyadic.yz() + zz() * dyadic.zz()
    };
  }

  constexpr void operator*=(double real) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] *= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] *= real;
  }

  constexpr Dyadic operator/(double real) const noexcept {
    return {
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] / real,
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] / real
    };
  }

  constexpr void operator/=(double real) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] /= real;
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] /= real;
  }

protected:

  std::array<double, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz_;

};

constexpr Dyadic Vector::dyadic(const Vector& vector) const noexcept {
  return {
    x() * vector.x(), x() * vector.y(), x() * vector.z(),
    y() * vector.x(), y() * vector.y(), y() * vector.z(),
    z() * vector.x(), z() * vector.y(), z() * vector.z()
  };
}

constexpr Dyadic SymmetricDyadic::operator*(const SymmetricDyadic& symmetric_dyadic) const noexcept {
  return {
    xx() * symmetric_dyadic.xx() + xy() * symmetric_dyadic.yx() + xz() * symmetric_dyadic.zx(),
    xx() * symmetric_dyadic.xy() + xy() * symmetric_dyadic.yy() + xz() * symmetric_dyadic.zy(),
    xx() * symmetric_dyadic.xz() + xy() * symmetric_dyadic.yz() + xz() * symmetric_dyadic.zz(),
    yx() * symmetric_dyadic.xx() + yy() * symmetric_dyadic.yx() + yz() * symmetric_dyadic.zx(),
    yx() * symmetric_dyadic.xy() + yy() * symmetric_dyadic.yy() + yz() * symmetric_dyadic.zy(),
    yx() * symmetric_dyadic.xz() + yy() * symmetric_dyadic.yz() + yz() * symmetric_dyadic.zz(),
    zx() * symmetric_dyadic.xx() + zy() * symmetric_dyadic.yx() + zz() * symmetric_dyadic.zx(),
    zx() * symmetric_dyadic.xy() + zy() * symmetric_dyadic.yy() + zz() * symmetric_dyadic.zy(),
    zx() * symmetric_dyadic.xz() + zy() * symmetric_dyadic.yz() + zz() * symmetric_dyadic.zz()
  };
}

constexpr Dyadic SymmetricDyadic::operator*(const Dyadic& dyadic) const noexcept {
  return {
    xx() * dyadic.xx() + xy() * dyadic.yx() + xz() * dyadic.zx(),
    xx() * dyadic.xy() + xy() * dyadic.yy() + xz() * dyadic.zy(),
    xx() * dyadic.xz() + xy() * dyadic.yz() + xz() * dyadic.zz(),
    yx() * dyadic.xx() + yy() * dyadic.yx() + yz() * dyadic.zx(),
    yx() * dyadic.xy() + yy() * dyadic.yy() + yz() * dyadic.zy(),
    yx() * dyadic.xz() + yy() * dyadic.yz() + yz() * dyadic.zz(),
    zx() * dyadic.xx() + zy() * dyadic.yx() + zz() * dyadic.zx(),
    zx() * dyadic.xy() + zy() * dyadic.yy() + zz() * dyadic.zy(),
    zx() * dyadic.xz() + zy() * dyadic.yz() + zz() * dyadic.zz()
  };
}

} // namespace Value

constexpr Value::Dyadic Direction::dyadic(const Direction& direction) const noexcept {
  return {
    x() * direction.x(), x() * direction.y(), x() * direction.z(),
    y() * direction.x(), y() * direction.y(), y() * direction.z(),
    z() * direction.x(), z() * direction.y(), z() * direction.z()
  };
}

constexpr Value::Dyadic Direction::dyadic(const Value::Vector& vector) const noexcept {
  return {
    x() * vector.x(), x() * vector.y(), x() * vector.z(),
    y() * vector.x(), y() * vector.y(), y() * vector.z(),
    z() * vector.x(), z() * vector.y(), z() * vector.z()
  };
}

constexpr Value::Dyadic Value::Vector::dyadic(const Direction& direction) const noexcept {
  return {
    x() * direction.x(), x() * direction.y(), x() * direction.z(),
    y() * direction.x(), y() * direction.y(), y() * direction.z(),
    z() * direction.x(), z() * direction.y(), z() * direction.z()
  };
}

template <> constexpr bool sort(const Value::Dyadic& dyadic_1, const Value::Dyadic& dyadic_2) noexcept {
  if (dyadic_1.xx() == dyadic_2.xx()) {
    if (dyadic_1.xy() == dyadic_2.xy()) {
      if (dyadic_1.xz() == dyadic_2.xz()) {
        if (dyadic_1.yx() == dyadic_2.yx()) {
          if (dyadic_1.yy() == dyadic_2.yy()) {
            if (dyadic_1.yz() == dyadic_2.yz()) {
              if (dyadic_1.zx() == dyadic_2.zx()) {
                if (dyadic_1.zy() == dyadic_2.zy()) {
                  return dyadic_1.zz() < dyadic_2.zz();
                } else {
                  return dyadic_1.zy() < dyadic_2.zy();
                }
              } else {
                return dyadic_1.zx() < dyadic_2.zx();
              }
            } else {
              return dyadic_1.yz() < dyadic_2.yz();
            }
          } else {
            return dyadic_1.yy() < dyadic_2.yy();
          }
        } else {
          return dyadic_1.yx() < dyadic_2.yx();
        }
      } else {
        return dyadic_1.xz() < dyadic_2.xz();
      }
    } else {
      return dyadic_1.xy() < dyadic_2.xy();
    }
  } else {
    return dyadic_1.xx() < dyadic_2.xx();
  }
}

} // namespace PhQ

constexpr PhQ::Value::Dyadic operator*(double real, const PhQ::Value::Dyadic& dyadic) noexcept {
  return {dyadic * real};
}

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::Dyadic& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}
