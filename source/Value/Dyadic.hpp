#pragma once

#include "SymmetricDyadic.hpp"

namespace PhQ {

namespace Value {

class CartesianDyadic {

public:

  CartesianDyadic() noexcept = default;

  constexpr CartesianDyadic(const std::array<double, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz) noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_{xx_xy_xz_yx_yy_yz_zx_zy_zz} {}

  constexpr CartesianDyadic(double xx, double xy, double xz, double yx, double yy, double yz, double zx, double zy, double zz) noexcept : xx_xy_xz_yx_yy_yz_zx_zy_zz_{xx, xy, xz, yx, yy, yz, zx, zy, zz} {}

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

  std::string print() const noexcept {
    return "(" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) + "; " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) + "; " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) + ", " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + ")";
  }

  std::string json() const noexcept {
    return "{\"xx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) + ", \"xy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) + ", \"xz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) + ", \"yx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) + ", \"yy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) + ", \"yz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) + ", \"zx\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) + ", \"zy\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) + ", \"zz\": " + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + "}";
  }

  std::string xml() const noexcept {
    return "<xx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[0]) + "</xx><xy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[1]) + "</xy><xz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[2]) + "</xz><yx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[3]) + "</yx><yy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[4]) + "</yy><yz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[5]) + "</yz><zx>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[6]) + "</zx><zy>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[7]) + "</zy><zz>" + PhQ::number_to_string(xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]) + "</zz>";
  }

  constexpr bool is_symmetric() const noexcept {
    return xy() == yx() && xz() == zx() && yz() == zy();
  }

  constexpr double trace() const noexcept {
    return xx() + yy() + zz();
  }

  constexpr double determinant() const noexcept {
    return xx() * (yy() * zz() - yz() * zy()) + xy() * (yz() * zx() - yx() * zz()) + xz() * (yx() * zy() - yy() * zx());
  }

  constexpr CartesianDyadic transpose() const noexcept {
    return {xx(), yx(), zx(), xy(), yy(), zy(), xz(), yz(), zz()};
  }

  constexpr CartesianDyadic cofactors() const noexcept {
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

  constexpr CartesianDyadic adjugate() const noexcept {
    return cofactors().transpose();
  }

  constexpr CartesianDyadic inverse() const {
    const double determinant_{determinant()};
    if (determinant_ != 0.0) {
      return adjugate() / determinant_;
    } else {
      throw std::runtime_error{"Cannot compute the inverse of " + print() + " because its determinant is 0."};
    }
  }

  constexpr CartesianVector dot(const CartesianVector& vector) const noexcept {
    return {xx() * vector.x() + xy() * vector.y() + xz() * vector.z(), yx() * vector.x() + yy() * vector.y() + yz() * vector.z(), zx() * vector.x() + zy() * vector.y() + zz() * vector.z()};
  }

  constexpr bool operator==(const CartesianDyadic& dyad) const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] && xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] == dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr bool operator!=(const CartesianDyadic& dyad) const noexcept {
    return xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] || xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] != dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8];
  }

  constexpr CartesianDyadic operator+(const CartesianDyadic& dyad) const noexcept {
    return {xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0], xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1], xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2], xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3], xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4], xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5], xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6], xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7], xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] + dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]};
  }

  constexpr void operator+=(const CartesianDyadic& dyad) noexcept {
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

  constexpr CartesianDyadic operator-(const CartesianDyadic& dyad) const noexcept {
    return {xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[0], xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[1], xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[2], xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[3], xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[4], xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[5], xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[6], xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[7], xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] - dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_[8]};
  }

  constexpr void operator-=(const CartesianDyadic& dyad) noexcept {
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

  constexpr CartesianDyadic operator*(double real) const noexcept {
    return {xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] * real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] * real};
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

  constexpr CartesianDyadic operator/(double real) const {
    if (real != 0.0) {
      return {xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] / real, xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr void operator/=(double real) {
    if (real != 0.0) {
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[0] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[1] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[2] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[3] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[4] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[5] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[6] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[7] /= real;
      xx_xy_xz_yx_yy_yz_zx_zy_zz_[8] /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

protected:

  std::array<double, 9> xx_xy_xz_yx_yy_yz_zx_zy_zz_;

};

} // namespace Value

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::SymmetricCartesianDyadic& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}
