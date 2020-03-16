#pragma once

#include "CartesianVector.hpp"

namespace PhQ {

namespace Value {

class SymmetricCartesianDyad {

public:

  SymmetricCartesianDyad() noexcept = default;

  constexpr SymmetricCartesianDyad(double xx, double xy, double xz, double yy, double yz, double zz) noexcept : xx_xy_xz_yy_yz_zz{xx, xy, xz, yy, yz, zz} {}

  constexpr double xx() const noexcept {
    return xx_xy_xz_yy_yz_zz[0];
  }

  constexpr double xy() const noexcept {
    return xx_xy_xz_yy_yz_zz[1];
  }

  constexpr double xz() const noexcept {
    return xx_xy_xz_yy_yz_zz[2];
  }

  constexpr double yx() const noexcept {
    return xx_xy_xz_yy_yz_zz[1];
  }

  constexpr double yy() const noexcept {
    return xx_xy_xz_yy_yz_zz[3];
  }

  constexpr double yz() const noexcept {
    return xx_xy_xz_yy_yz_zz[4];
  }

  constexpr double zx() const noexcept {
    return xx_xy_xz_yy_yz_zz[2];
  }

  constexpr double zy() const noexcept {
    return xx_xy_xz_yy_yz_zz[4];
  }

  constexpr double zz() const noexcept {
    return xx_xy_xz_yy_yz_zz[5];
  }

  std::string print() const noexcept {
    return "(" + real_number_to_string(xx_xy_xz_yy_yz_zz[0]) + ", " + real_number_to_string(xx_xy_xz_yy_yz_zz[1]) + ", " + real_number_to_string(xx_xy_xz_yy_yz_zz[2]) + ", " + real_number_to_string(xx_xy_xz_yy_yz_zz[3]) + ", " + real_number_to_string(xx_xy_xz_yy_yz_zz[4]) + ", " + real_number_to_string(xx_xy_xz_yy_yz_zz[5]) + ")";
  }

  std::string json() const noexcept {
    return "{\"xx\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[0]) + ", \"xy\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[1]) + ", \"xz\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[2]) + ", \"yy\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[3]) + ", \"yz\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[4]) + ", \"zz\": " + real_number_to_string(xx_xy_xz_yy_yz_zz[5]) + "}";
  }

  std::string xml() const noexcept {
    return "<xx>" + real_number_to_string(xx_xy_xz_yy_yz_zz[0]) + "</xx><xy>" + real_number_to_string(xx_xy_xz_yy_yz_zz[1]) + "</xy><xz>" + real_number_to_string(xx_xy_xz_yy_yz_zz[2]) + "</xz><yy>" + real_number_to_string(xx_xy_xz_yy_yz_zz[3]) + "</yy><yz>" + real_number_to_string(xx_xy_xz_yy_yz_zz[4]) + "</yz><zz>" + real_number_to_string(xx_xy_xz_yy_yz_zz[5]) + "</zz>";
  }

protected:

  std::array<double, 6> xx_xy_xz_yy_yz_zz;

};

} // namespace Value

} // namespace PhQ
