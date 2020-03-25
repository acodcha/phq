#pragma once

#include "Vector.hpp"

namespace PhQ {

namespace Value {

class SymmetricDyadic {

public:

  SymmetricDyadic() noexcept = default;

  constexpr SymmetricDyadic(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) noexcept : xx_xy_xz_yy_yz_zz_{xx_xy_xz_yy_yz_zz} {}

  constexpr SymmetricDyadic(double xx, double xy, double xz, double yy, double yz, double zz) noexcept : xx_xy_xz_yy_yz_zz_{xx, xy, xz, yy, yz, zz} {}

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

  constexpr bool operator==(const SymmetricDyadic& dyad) const noexcept {
    return
      xx_xy_xz_yy_yz_zz_[0] == dyad.xx_xy_xz_yy_yz_zz_[0] &&
      xx_xy_xz_yy_yz_zz_[1] == dyad.xx_xy_xz_yy_yz_zz_[1] &&
      xx_xy_xz_yy_yz_zz_[2] == dyad.xx_xy_xz_yy_yz_zz_[2] &&
      xx_xy_xz_yy_yz_zz_[3] == dyad.xx_xy_xz_yy_yz_zz_[3] &&
      xx_xy_xz_yy_yz_zz_[4] == dyad.xx_xy_xz_yy_yz_zz_[4] &&
      xx_xy_xz_yy_yz_zz_[5] == dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr bool operator!=(const SymmetricDyadic& dyad) const noexcept {
    return
      xx_xy_xz_yy_yz_zz_[0] != dyad.xx_xy_xz_yy_yz_zz_[0] ||
      xx_xy_xz_yy_yz_zz_[1] != dyad.xx_xy_xz_yy_yz_zz_[1] ||
      xx_xy_xz_yy_yz_zz_[2] != dyad.xx_xy_xz_yy_yz_zz_[2] ||
      xx_xy_xz_yy_yz_zz_[3] != dyad.xx_xy_xz_yy_yz_zz_[3] ||
      xx_xy_xz_yy_yz_zz_[4] != dyad.xx_xy_xz_yy_yz_zz_[4] ||
      xx_xy_xz_yy_yz_zz_[5] != dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr SymmetricDyadic operator+(const SymmetricDyadic& dyad) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] + dyad.xx_xy_xz_yy_yz_zz_[0],
      xx_xy_xz_yy_yz_zz_[1] + dyad.xx_xy_xz_yy_yz_zz_[1],
      xx_xy_xz_yy_yz_zz_[2] + dyad.xx_xy_xz_yy_yz_zz_[2],
      xx_xy_xz_yy_yz_zz_[3] + dyad.xx_xy_xz_yy_yz_zz_[3],
      xx_xy_xz_yy_yz_zz_[4] + dyad.xx_xy_xz_yy_yz_zz_[4],
      xx_xy_xz_yy_yz_zz_[5] + dyad.xx_xy_xz_yy_yz_zz_[5]
    };
  }

  constexpr void operator+=(const SymmetricDyadic& dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] += dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] += dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] += dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] += dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] += dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] += dyad.xx_xy_xz_yy_yz_zz_[5];
  }

  constexpr SymmetricDyadic operator-(const SymmetricDyadic& dyad) const noexcept {
    return {
      xx_xy_xz_yy_yz_zz_[0] - dyad.xx_xy_xz_yy_yz_zz_[0],
      xx_xy_xz_yy_yz_zz_[1] - dyad.xx_xy_xz_yy_yz_zz_[1],
      xx_xy_xz_yy_yz_zz_[2] - dyad.xx_xy_xz_yy_yz_zz_[2],
      xx_xy_xz_yy_yz_zz_[3] - dyad.xx_xy_xz_yy_yz_zz_[3],
      xx_xy_xz_yy_yz_zz_[4] - dyad.xx_xy_xz_yy_yz_zz_[4],
      xx_xy_xz_yy_yz_zz_[5] - dyad.xx_xy_xz_yy_yz_zz_[5]
    };
  }

  constexpr void operator-=(const SymmetricDyadic& dyad) noexcept {
    xx_xy_xz_yy_yz_zz_[0] -= dyad.xx_xy_xz_yy_yz_zz_[0];
    xx_xy_xz_yy_yz_zz_[1] -= dyad.xx_xy_xz_yy_yz_zz_[1];
    xx_xy_xz_yy_yz_zz_[2] -= dyad.xx_xy_xz_yy_yz_zz_[2];
    xx_xy_xz_yy_yz_zz_[3] -= dyad.xx_xy_xz_yy_yz_zz_[3];
    xx_xy_xz_yy_yz_zz_[4] -= dyad.xx_xy_xz_yy_yz_zz_[4];
    xx_xy_xz_yy_yz_zz_[5] -= dyad.xx_xy_xz_yy_yz_zz_[5];
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

  constexpr Dyadic operator*(const SymmetricDyadic& dyadic) const noexcept;

  constexpr Dyadic operator*(const Dyadic& dyadic) const noexcept;

  constexpr void operator*=(double real) noexcept {
    xx_xy_xz_yy_yz_zz_[0] *= real;
    xx_xy_xz_yy_yz_zz_[1] *= real;
    xx_xy_xz_yy_yz_zz_[2] *= real;
    xx_xy_xz_yy_yz_zz_[3] *= real;
    xx_xy_xz_yy_yz_zz_[4] *= real;
    xx_xy_xz_yy_yz_zz_[5] *= real;
  }

  constexpr SymmetricDyadic operator/(double real) const {
    if (real != 0.0) {
      return {
        xx_xy_xz_yy_yz_zz_[0] / real,
        xx_xy_xz_yy_yz_zz_[1] / real,
        xx_xy_xz_yy_yz_zz_[2] / real,
        xx_xy_xz_yy_yz_zz_[3] / real,
        xx_xy_xz_yy_yz_zz_[4] / real,
        xx_xy_xz_yy_yz_zz_[5] / real
      };
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr void operator/=(double real) {
    if (real != 0.0) {
      xx_xy_xz_yy_yz_zz_[0] /= real;
      xx_xy_xz_yy_yz_zz_[1] /= real;
      xx_xy_xz_yy_yz_zz_[2] /= real;
      xx_xy_xz_yy_yz_zz_[3] /= real;
      xx_xy_xz_yy_yz_zz_[4] /= real;
      xx_xy_xz_yy_yz_zz_[5] /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

protected:

  std::array<double, 6> xx_xy_xz_yy_yz_zz_;

};

} // namespace Value

template <> constexpr bool sort(const Value::SymmetricDyadic& dyadic1, const Value::SymmetricDyadic& dyadic2) noexcept {
  if (dyadic1.xx() < dyadic2.xx()) {
    return true;
  } else if (dyadic1.xx() > dyadic2.xx()) {
    return false;
  } else {
    if (dyadic1.yy() < dyadic2.yy()) {
      return true;
    } else if (dyadic1.yy() > dyadic2.yy()) {
      return false;
    } else {
      if (dyadic1.zz() < dyadic2.zz()) {
        return true;
      } else if (dyadic1.zz() > dyadic2.zz()) {
        return false;
      } else {
        if (dyadic1.xy() < dyadic2.xy()) {
          return true;
        } else if (dyadic1.xy() > dyadic2.xy()) {
          return false;
        } else {
          if (dyadic1.yz() < dyadic2.yz()) {
            return true;
          } else if (dyadic1.yz() > dyadic2.yz()) {
            return false;
          } else {
            return dyadic1.xz() < dyadic2.xz();
          }
        }
      }
    }
  }
}

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Value::SymmetricDyadic& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}
