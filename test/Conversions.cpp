#include "../lib/Unit/Angle.hpp"
#include "../lib/Unit/Force.hpp"
#include "../lib/Unit/Mass.hpp"
#include "../lib/Unit/Pressure.hpp"
#include "../lib/Unit/Temperature.hpp"
#include "../lib/Unit/Time.hpp"
#include "../lib/Unit/Volume.hpp"

template <typename Unit> void test_conversions(const std::string& name, double value, const std::set<Unit>& units) {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << name << ":" << std::endl;
  for (const Unit& unit1 : units) {
    for (const Unit& unit2 : units) {
      if (unit1 != unit2) {
        std::cout << PhQ::number_to_string(value) << " " << PhQ::abbreviation(unit1) << " = " << PhQ::number_to_string(PhQ::convert(value, unit1, unit2)) << " " << PhQ::abbreviation(unit2) << std::endl;
      }
    }
  }
}

void test_angle() noexcept {
  test_conversions<PhQ::Unit::Angle>("Angle", 1.0, {
    PhQ::Unit::Angle::Degree,
    PhQ::Unit::Angle::Radian,
    PhQ::Unit::Angle::Arcminute,
    PhQ::Unit::Angle::Arcsecond
  });
}

void test_area() noexcept {
  test_conversions<PhQ::Unit::Area>("Area", 1.0, {
    PhQ::Unit::Area::SquareMetre,
    PhQ::Unit::Area::SquareMile,
    PhQ::Unit::Area::SquareKilometre,
    PhQ::Unit::Area::SquareYard,
    PhQ::Unit::Area::SquareMetre,
    PhQ::Unit::Area::SquareFoot,
    PhQ::Unit::Area::SquareDecimetre,
    PhQ::Unit::Area::SquareInch,
    PhQ::Unit::Area::SquareCentimetre,
    PhQ::Unit::Area::SquareMillimetre,
    PhQ::Unit::Area::SquareMilliinch,
    PhQ::Unit::Area::SquareMicrometre,
    PhQ::Unit::Area::SquareMicroinch
  });
}

void test_force() noexcept {
  test_conversions<PhQ::Unit::Force>("Force", 1.0, {
    PhQ::Unit::Force::Newton,
    PhQ::Unit::Force::Micronewton,
    PhQ::Unit::Force::Pound
  });
}

void test_length() noexcept {
  test_conversions<PhQ::Unit::Length>("Length", 1.0, {
    PhQ::Unit::Length::Mile,
    PhQ::Unit::Length::Kilometre,
    PhQ::Unit::Length::Yard,
    PhQ::Unit::Length::Metre,
    PhQ::Unit::Length::Foot,
    PhQ::Unit::Length::Decimetre,
    PhQ::Unit::Length::Inch,
    PhQ::Unit::Length::Centimetre,
    PhQ::Unit::Length::Millimetre,
    PhQ::Unit::Length::Milliinch,
    PhQ::Unit::Length::Micrometre,
    PhQ::Unit::Length::Microinch
  });
}

void test_mass() noexcept {
  test_conversions<PhQ::Unit::Mass>("Mass", 1.0, {
    PhQ::Unit::Mass::Kilogram,
    PhQ::Unit::Mass::Gram,
    PhQ::Unit::Mass::Slug,
    PhQ::Unit::Mass::Slinch,
    PhQ::Unit::Mass::Pound
  });
}

void test_pressure() noexcept {
  test_conversions<PhQ::Unit::Pressure>("Pressure", 1.0, {
    PhQ::Unit::Pressure::Pascal,
    PhQ::Unit::Pressure::PoundPerSquareFoot,
    PhQ::Unit::Pressure::PoundPerSquareInch
  });
}

void test_temperature() noexcept {
  test_conversions<PhQ::Unit::Temperature>("Temperature", 100.0, {
    PhQ::Unit::Temperature::Kelvin,
    PhQ::Unit::Temperature::Celsius,
    PhQ::Unit::Temperature::Rankine,
    PhQ::Unit::Temperature::Fahrenheit
  });
}

void test_time() noexcept {
  test_conversions<PhQ::Unit::Time>("Time", 1.0, {
    PhQ::Unit::Time::Hour,
    PhQ::Unit::Time::Minute,
    PhQ::Unit::Time::Second
  });
}

void test_volume() noexcept {
  test_conversions<PhQ::Unit::Volume>("Volume", 1.0, {
    PhQ::Unit::Volume::CubicMile,
    PhQ::Unit::Volume::CubicKilometre,
    PhQ::Unit::Volume::CubicYard,
    PhQ::Unit::Volume::CubicMetre,
    PhQ::Unit::Volume::CubicFoot,
    PhQ::Unit::Volume::CubicDecimetre,
    PhQ::Unit::Volume::Litre,
    PhQ::Unit::Volume::CubicInch,
    PhQ::Unit::Volume::CubicCentimetre,
    PhQ::Unit::Volume::Millilitre,
    PhQ::Unit::Volume::CubicMillimetre,
    PhQ::Unit::Volume::CubicMilliinch,
    PhQ::Unit::Volume::CubicMicrometre,
    PhQ::Unit::Volume::CubicMicroinch
  });
}

int main(int argc, char *argv[]) {
  test_angle();
  test_area();
  test_force();
  test_length();
  test_mass();
  test_pressure();
  test_temperature();
  test_time();
  test_volume();
  return EXIT_SUCCESS;
}
