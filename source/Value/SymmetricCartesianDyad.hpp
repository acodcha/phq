#pragma once

#include "CartesianVector.hpp"

namespace PhQ {

namespace Value {

class SymmetricCartesianDyad {

public:

  SymmetricCartesianDyad() noexcept = default;

  constexpr SymmetricCartesianDyad(double xx, double xy, double xz, double yy, double yz, double zz) noexcept : xx_xy_xz_yy_yz_zz_{xx, xy, xz, yy, yz, zz} {}

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

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) + ", " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) + ", " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) + ", " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) + ", " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) + ", " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + ")";
  }

  std::string json() const noexcept {
    return "{\"xx\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) + ", \"xy\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) + ", \"xz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) + ", \"yy\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) + ", \"yz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) + ", \"zz\": " + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + "}";
  }

  std::string xml() const noexcept {
    return "<xx>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[0]) + "</xx><xy>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[1]) + "</xy><xz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[2]) + "</xz><yy>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[3]) + "</yy><yz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[4]) + "</yz><zz>" + PhQ::number_to_string(xx_xy_xz_yy_yz_zz_[5]) + "</zz>";
  }

protected:

  std::array<double, 6> xx_xy_xz_yy_yz_zz_;

};

} // namespace Value

} // namespace PhQ
