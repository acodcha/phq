// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP

#include "SymmetricDyad.hpp"

namespace PhQ::Value {

class Dyad {
public:
  constexpr Dyad() noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_() {}

  constexpr Dyad(const double xx, const double xy, const double xz,
                 const double yx, const double yy, const double yz,
                 const double zx, const double zy, const double zz) noexcept
      : xx_xy_xz_yx_yy_yz_zx_zy_zz_({xx, xy, xz, yx, yy, yz, zx, zy, zz}) {}

  constexpr Dyad(
      const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept
      : xx_xy_xz_yx_yy_yz_zx_zy_zz_(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  constexpr Dyad(const SymmetricDyad& symdyad) noexcept
      : xx_xy_xz_yx_yy_yz_zx_zy_zz_({symdyad.xx(), symdyad.xy(), symdyad.xz(),
                                     symdyad.yx(), symdyad.yy(), symdyad.yz(),
                                     symdyad.zx(), symdyad.zy(),
                                     symdyad.zz()}) {}

  static constexpr Dyad Zero() noexcept {
    return std::array<double, 9>{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  }

  inline constexpr const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz()
      const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  inline constexpr std::array<double, 9>&
  Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_;
  }

  inline constexpr void Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_ = xx_xy_xz_yx_yy_yz_zx_zy_zz;
  }

  inline constexpr double xx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  inline constexpr double& Mutable_xx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
  }

  inline constexpr void Set_xx(const double xx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] = xx;
  }

  inline constexpr double xy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  inline constexpr double& Mutable_xy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
  }

  inline constexpr void Set_xy(const double xy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] = xy;
  }

  inline constexpr double xz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  inline constexpr double& Mutable_xz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
  }

  inline constexpr void Set_xz(const double xz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] = xz;
  }

  inline constexpr double yx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  inline constexpr double& Mutable_yx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
  }

  inline constexpr void Set_yx(const double yx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] = yx;
  }

  inline constexpr double yy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  inline constexpr double& Mutable_yy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
  }

  inline constexpr void Set_yy(const double yy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] = yy;
  }

  inline constexpr double yz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  inline constexpr double& Mutable_yz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
  }

  inline constexpr void Set_yz(const double yz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] = yz;
  }

  inline constexpr double zx() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  inline constexpr double& Mutable_zx() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
  }

  inline constexpr void Set_zx(const double zx) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] = zx;
  }

  inline constexpr double zy() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  inline constexpr double& Mutable_zy() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
  }

  inline constexpr void Set_zy(const double zy) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] = zy;
  }

  inline constexpr double zz() const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  inline constexpr double& Mutable_zz() noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  inline constexpr void Set_zz(const double zz) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] = zz;
  }

  inline constexpr bool IsSymmetric() const noexcept {
    return xy() == yx() && xz() == zx() && yz() == zy();
  }

  inline constexpr double Trace() const noexcept { return xx() + yy() + zz(); }

  inline constexpr double Determinant() const noexcept {
    return (xx() * (yy() * zz() - yz() * zy()) +
            xy() * (yz() * zx() - yx() * zz()) +
            xz() * (yx() * zy() - yy() * zx()));
  }

  inline constexpr Dyad Transpose() const noexcept {
    return {xx(), yx(), zx(), xy(), yy(), zy(), xz(), yz(), zz()};
  }

  inline constexpr Dyad Cofactors() const noexcept {
    const double cofactor_xx{yy() * zz() - yz() * zy()};
    const double cofactor_xy{yz() * zx() - yx() * zz()};
    const double cofactor_xz{yx() * zy() - yy() * zx()};
    const double cofactor_yx{xz() * zy() - xy() * zz()};
    const double cofactor_yy{xx() * zz() - xz() * zx()};
    const double cofactor_yz{xy() * zx() - xx() * zy()};
    const double cofactor_zx{xy() * yz() - xz() * yy()};
    const double cofactor_zy{xz() * yx() - xx() * yz()};
    const double cofactor_zz{xx() * yy() - xy() * yx()};
    return {cofactor_xx, cofactor_xy, cofactor_xz, cofactor_yx, cofactor_yy,
            cofactor_yz, cofactor_zx, cofactor_zy, cofactor_zz};
  }

  inline constexpr Dyad Adjugate() const noexcept {
    return Cofactors().Transpose();
  }

  inline std::optional<Dyad> Inverse() const;

  inline std::string Print() const noexcept {
    return "(" + PhQ::Print(xx()) + ", " + PhQ::Print(xy()) + ", " +
           PhQ::Print(xz()) + "; " + PhQ::Print(yx()) + ", " +
           PhQ::Print(yy()) + ", " + PhQ::Print(yz()) + "; " +
           PhQ::Print(zx()) + ", " + PhQ::Print(zy()) + ", " +
           PhQ::Print(zz()) + ")";
  }

  inline std::string Json() const noexcept {
    return "{\"xx\":" + PhQ::Print(xx()) + ",\"xy\":" + PhQ::Print(xy()) +
           ",\"xz\":" + PhQ::Print(xz()) + ",\"yx\":" + PhQ::Print(yx()) +
           ",\"yy\":" + PhQ::Print(yy()) + ",\"yz\":" + PhQ::Print(yz()) +
           ",\"zx\":" + PhQ::Print(zx()) + ",\"zy\":" + PhQ::Print(zy()) +
           ",\"zz\":" + PhQ::Print(zz()) + "}";
  }

  inline std::string Xml() const noexcept {
    return "<xx>" + PhQ::Print(xx()) + "</xx><xy>" + PhQ::Print(xy()) +
           "</xy><xz>" + PhQ::Print(xz()) + "</xz><yx>" + PhQ::Print(yx()) +
           "</yx><yy>" + PhQ::Print(yy()) + "</yy><yz>" + PhQ::Print(yz()) +
           "</yz><zx>" + PhQ::Print(zx()) + "</zx><zy>" + PhQ::Print(zy()) +
           "</zy><zz>" + PhQ::Print(zz()) + "</zz>";
  }

  inline std::string Yaml() const noexcept {
    return "{xx:" + PhQ::Print(xx()) + ",xy:" + PhQ::Print(xy()) +
           ",xz:" + PhQ::Print(xz()) + ",yx:" + PhQ::Print(yx()) +
           ",yy:" + PhQ::Print(yy()) + ",yz:" + PhQ::Print(yz()) +
           ",zx:" + PhQ::Print(zx()) + ",zy:" + PhQ::Print(zy()) +
           ",zz:" + PhQ::Print(zz()) + "}";
  }

  inline constexpr void operator+=(const Dyad& dyad) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] += dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  inline constexpr void operator-=(const Dyad& dyad) noexcept {
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7];
    xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] -= dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  inline constexpr void operator*=(const double real) noexcept {
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

  inline constexpr void operator/=(const double real) noexcept {
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

private:
  std::array<double, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz_;
};

inline constexpr bool operator==(const Dyad& left, const Dyad& right) noexcept {
  return (left.xx() == right.xx() && left.xy() == right.xy() &&
          left.xz() == right.xz() && left.yx() == right.yx() &&
          left.yy() == right.yy() && left.yz() == right.yz() &&
          left.zx() == right.zx() && left.zy() == right.zy() &&
          left.zz() == right.zz());
}

inline constexpr bool operator!=(const Dyad& left, const Dyad& right) noexcept {
  return (left.xx() != right.xx() || left.xy() != right.xy() ||
          left.xz() != right.xz() || left.yx() != right.yx() ||
          left.yy() != right.yy() || left.yz() != right.yz() ||
          left.zx() != right.zx() || left.zy() != right.zy() ||
          left.zz() != right.zz());
}

inline constexpr Dyad operator+(const Dyad& left, const Dyad& right) noexcept {
  return {
      left.xx() + right.xx(), left.xy() + right.xy(), left.xz() + right.xz(),
      left.yx() + right.yx(), left.yy() + right.yy(), left.yz() + right.yz(),
      left.zx() + right.zx(), left.zy() + right.zy(), left.zz() + right.zz()};
}

inline constexpr Dyad operator-(const Dyad& left, const Dyad& right) noexcept {
  return {
      left.xx() - right.xx(), left.xy() - right.xy(), left.xz() - right.xz(),
      left.yx() - right.yx(), left.yy() - right.yy(), left.yz() - right.yz(),
      left.zx() - right.zx(), left.zy() - right.zy(), left.zz() - right.zz()};
}

inline constexpr Dyad operator*(const Dyad& dyad, const double real) noexcept {
  return {dyad.xx() * real, dyad.xy() * real, dyad.xz() * real,
          dyad.yx() * real, dyad.yy() * real, dyad.yz() * real,
          dyad.zx() * real, dyad.zy() * real, dyad.zz() * real};
}

inline constexpr Dyad operator*(const double real, const Dyad& dyad) noexcept {
  return {dyad * real};
}

inline constexpr Vector operator*(const Dyad& dyad,
                                  const Vector& vector) noexcept {
  return {
      dyad.xx() * vector.x() + dyad.xy() * vector.y() + dyad.xz() * vector.z(),
      dyad.yx() * vector.x() + dyad.yy() * vector.y() + dyad.yz() * vector.z(),
      dyad.zx() * vector.x() + dyad.zy() * vector.y() + dyad.zz() * vector.z()};
}

inline constexpr Dyad operator*(const SymmetricDyad& left,
                                const SymmetricDyad& right) noexcept {
  return {
      left.xx() * right.xx() + left.xy() * right.xy() + left.xz() * right.xz(),
      left.xx() * right.xy() + left.xy() * right.yy() + left.xz() * right.yz(),
      left.xx() * right.xz() + left.xy() * right.yz() + left.xz() * right.zz(),
      left.xy() * right.xx() + left.yy() * right.xy() + left.yz() * right.xz(),
      left.xy() * right.xy() + left.yy() * right.yy() + left.yz() * right.yz(),
      left.xy() * right.xz() + left.yy() * right.yz() + left.yz() * right.zz(),
      left.xz() * right.xx() + left.yz() * right.xy() + left.zz() * right.xz(),
      left.xz() * right.xy() + left.yz() * right.yy() + left.zz() * right.yz(),
      left.xz() * right.xz() + left.yz() * right.yz() + left.zz() * right.zz()};
}

inline constexpr Dyad operator*(const SymmetricDyad& symdyad,
                                const Dyad& dyad) noexcept {
  return {symdyad.xx() * dyad.xx() + symdyad.xy() * dyad.yx() +
              symdyad.xz() * dyad.zx(),
          symdyad.xx() * dyad.xy() + symdyad.xy() * dyad.yy() +
              symdyad.xz() * dyad.zy(),
          symdyad.xx() * dyad.xz() + symdyad.xy() * dyad.yz() +
              symdyad.xz() * dyad.zz(),
          symdyad.xy() * dyad.xx() + symdyad.yy() * dyad.yx() +
              symdyad.yz() * dyad.zx(),
          symdyad.xy() * dyad.xy() + symdyad.yy() * dyad.yy() +
              symdyad.yz() * dyad.zy(),
          symdyad.xy() * dyad.xz() + symdyad.yy() * dyad.yz() +
              symdyad.yz() * dyad.zz(),
          symdyad.xz() * dyad.xx() + symdyad.yz() * dyad.yx() +
              symdyad.zz() * dyad.zx(),
          symdyad.xz() * dyad.xy() + symdyad.yz() * dyad.yy() +
              symdyad.zz() * dyad.zy(),
          symdyad.xz() * dyad.xz() + symdyad.yz() * dyad.yz() +
              symdyad.zz() * dyad.zz()};
}

inline constexpr Dyad operator*(const Dyad& dyad,
                                const SymmetricDyad& symdyad) noexcept {
  return {dyad.xx() * symdyad.xx() + dyad.xy() * symdyad.yx() +
              dyad.xz() * symdyad.zx(),
          dyad.xx() * symdyad.xy() + dyad.xy() * symdyad.yy() +
              dyad.xz() * symdyad.zy(),
          dyad.xx() * symdyad.xz() + dyad.xy() * symdyad.yz() +
              dyad.xz() * symdyad.zz(),
          dyad.yx() * symdyad.xx() + dyad.yy() * symdyad.yx() +
              dyad.yz() * symdyad.zx(),
          dyad.yx() * symdyad.xy() + dyad.yy() * symdyad.yy() +
              dyad.yz() * symdyad.zy(),
          dyad.yx() * symdyad.xz() + dyad.yy() * symdyad.yz() +
              dyad.yz() * symdyad.zz(),
          dyad.zx() * symdyad.xx() + dyad.zy() * symdyad.yx() +
              dyad.zz() * symdyad.zx(),
          dyad.zx() * symdyad.xy() + dyad.zy() * symdyad.yy() +
              dyad.zz() * symdyad.zy(),
          dyad.zx() * symdyad.xz() + dyad.zy() * symdyad.yz() +
              dyad.zz() * symdyad.zz()};
}

inline constexpr Dyad operator*(const Dyad& left, const Dyad& right) noexcept {
  return {
      left.xx() * right.xx() + left.xy() * right.yx() + left.xz() * right.zx(),
      left.xx() * right.xy() + left.xy() * right.yy() + left.xz() * right.zy(),
      left.xx() * right.xz() + left.xy() * right.yz() + left.xz() * right.zz(),
      left.yx() * right.xx() + left.yy() * right.yx() + left.yz() * right.zx(),
      left.yx() * right.xy() + left.yy() * right.yy() + left.yz() * right.zy(),
      left.yx() * right.xz() + left.yy() * right.yz() + left.yz() * right.zz(),
      left.zx() * right.xx() + left.zy() * right.yx() + left.zz() * right.zx(),
      left.zx() * right.xy() + left.zy() * right.yy() + left.zz() * right.zy(),
      left.zx() * right.xz() + left.zy() * right.yz() + left.zz() * right.zz()};
}

inline constexpr Dyad operator/(const Dyad& dyad, const double real) noexcept {
  return {dyad.xx() / real, dyad.xy() / real, dyad.xz() / real,
          dyad.yx() / real, dyad.yy() / real, dyad.yz() / real,
          dyad.zx() / real, dyad.zy() / real, dyad.zz() / real};
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Dyad& dyad) noexcept {
  stream << dyad.Print();
  return stream;
}

inline std::optional<Dyad> Dyad::Inverse() const {
  const double determinant_{Determinant()};
  if (determinant_ != 0.0) {
    return Adjugate() / determinant_;
  } else {
    return std::nullopt;
  }
}

inline constexpr Dyad Vector::Dyadic(const Vector& vector) const noexcept {
  return {x_y_z_[0] * vector.x_y_z_[0], x_y_z_[0] * vector.x_y_z_[1],
          x_y_z_[0] * vector.x_y_z_[2], x_y_z_[1] * vector.x_y_z_[0],
          x_y_z_[1] * vector.x_y_z_[1], x_y_z_[1] * vector.x_y_z_[2],
          x_y_z_[2] * vector.x_y_z_[0], x_y_z_[2] * vector.x_y_z_[1],
          x_y_z_[2] * vector.x_y_z_[2]};
}

inline constexpr Dyad Direction::Dyadic(
    const Direction& direction) const noexcept {
  return {x_y_z_[0] * direction.x_y_z_[0], x_y_z_[0] * direction.x_y_z_[1],
          x_y_z_[0] * direction.x_y_z_[2], x_y_z_[1] * direction.x_y_z_[0],
          x_y_z_[1] * direction.x_y_z_[1], x_y_z_[1] * direction.x_y_z_[2],
          x_y_z_[2] * direction.x_y_z_[0], x_y_z_[2] * direction.x_y_z_[1],
          x_y_z_[2] * direction.x_y_z_[2]};
}

inline constexpr Dyad Direction::Dyadic(const Vector& vector) const noexcept {
  return {
      x_y_z_[0] * vector.x(), x_y_z_[0] * vector.y(), x_y_z_[0] * vector.z(),
      x_y_z_[1] * vector.x(), x_y_z_[1] * vector.y(), x_y_z_[1] * vector.z(),
      x_y_z_[2] * vector.x(), x_y_z_[2] * vector.y(), x_y_z_[2] * vector.z()};
}

inline constexpr Dyad Vector::Dyadic(
    const Value::Direction& direction) const noexcept {
  return {x_y_z_[0] * direction.x(), x_y_z_[0] * direction.y(),
          x_y_z_[0] * direction.z(), x_y_z_[1] * direction.x(),
          x_y_z_[1] * direction.y(), x_y_z_[1] * direction.z(),
          x_y_z_[2] * direction.x(), x_y_z_[2] * direction.y(),
          x_y_z_[2] * direction.z()};
}

}  // namespace PhQ::Value

namespace std {

template <>
struct hash<PhQ::Value::Dyad> {
  size_t operator()(const PhQ::Value::Dyad& dyad) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(dyad.xx());
    result = 31 * result + hash<double>()(dyad.xy());
    result = 31 * result + hash<double>()(dyad.xz());
    result = 31 * result + hash<double>()(dyad.yx());
    result = 31 * result + hash<double>()(dyad.yy());
    result = 31 * result + hash<double>()(dyad.yz());
    result = 31 * result + hash<double>()(dyad.zx());
    result = 31 * result + hash<double>()(dyad.zy());
    result = 31 * result + hash<double>()(dyad.zz());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_DYAD_HPP
