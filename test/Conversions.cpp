// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#include "../lib/Unit/Acceleration.hpp"
#include "../lib/Unit/Angle.hpp"
#include "../lib/Unit/AngularAcceleration.hpp"
#include "../lib/Unit/AngularSpeed.hpp"
#include "../lib/Unit/Area.hpp"
#include "../lib/Unit/Diffusivity.hpp"
#include "../lib/Unit/DynamicViscosity.hpp"
#include "../lib/Unit/Energy.hpp"
#include "../lib/Unit/Force.hpp"
#include "../lib/Unit/Frequency.hpp"
#include "../lib/Unit/HeatCapacity.hpp"
#include "../lib/Unit/Length.hpp"
#include "../lib/Unit/Mass.hpp"
#include "../lib/Unit/MassDensity.hpp"
#include "../lib/Unit/MassRate.hpp"
#include "../lib/Unit/Memory.hpp"
#include "../lib/Unit/MemoryRate.hpp"
#include "../lib/Unit/Power.hpp"
#include "../lib/Unit/Pressure.hpp"
#include "../lib/Unit/SpecificEnergy.hpp"
#include "../lib/Unit/SpecificPower.hpp"
#include "../lib/Unit/Speed.hpp"
#include "../lib/Unit/Temperature.hpp"
#include "../lib/Unit/Time.hpp"
#include "../lib/Unit/Volume.hpp"
#include "../lib/Unit/VolumeRate.hpp"

const std::string test_separator{"----------------------------------------"};

template <typename Unit> void test_conversions(const std::string& name, double value, const std::set<Unit>& units) {
  std::cout << test_separator << std::endl;
  std::cout << name << ":" << std::endl;
  for (const Unit& unit1 : units) {
    for (const Unit& unit2 : units) {
      if (unit1 != unit2) {
        std::cout << PhQ::number_to_string(value) << " " << PhQ::abbreviation(unit1) << " = " << PhQ::number_to_string(PhQ::convert(value, unit1, unit2)) << " " << PhQ::abbreviation(unit2) << std::endl;
      }
    }
  }
}

void test_acceleration() noexcept {
  test_conversions<PhQ::Unit::Acceleration>("Acceleration", 1.0, {
    PhQ::Unit::Acceleration::MilePerSquareSecond,
    PhQ::Unit::Acceleration::KilometrePerSquareSecond,
    PhQ::Unit::Acceleration::YardPerSquareSecond,
    PhQ::Unit::Acceleration::MetrePerSquareSecond,
    PhQ::Unit::Acceleration::FootPerSquareSecond,
    PhQ::Unit::Acceleration::DecimetrePerSquareSecond,
    PhQ::Unit::Acceleration::InchPerSquareSecond,
    PhQ::Unit::Acceleration::CentimetrePerSquareSecond,
    PhQ::Unit::Acceleration::MillimetrePerSquareSecond,
    PhQ::Unit::Acceleration::MilliinchPerSquareSecond,
    PhQ::Unit::Acceleration::MicrometrePerSquareSecond,
    PhQ::Unit::Acceleration::MicroinchPerSquareSecond
  });
}

void test_angle() noexcept {
  test_conversions<PhQ::Unit::Angle>("Angle", 1.0, {
    PhQ::Unit::Angle::Radian,
    PhQ::Unit::Angle::Degree,
    PhQ::Unit::Angle::Arcminute,
    PhQ::Unit::Angle::Arcsecond
  });
}

void test_angular_acceleration() noexcept {
  test_conversions<PhQ::Unit::AngularAcceleration>("Angular Acceleration", 1.0, {
    PhQ::Unit::AngularAcceleration::RadianPerSquareSecond,
    PhQ::Unit::AngularAcceleration::RadianPerSquareMinute,
    PhQ::Unit::AngularAcceleration::RadianPerSquareHour,
    PhQ::Unit::AngularAcceleration::DegreePerSquareSecond,
    PhQ::Unit::AngularAcceleration::DegreePerSquareMinute,
    PhQ::Unit::AngularAcceleration::DegreePerSquareHour,
    PhQ::Unit::AngularAcceleration::RevolutionPerSquareSecond,
    PhQ::Unit::AngularAcceleration::RevolutionPerSquareMinute,
    PhQ::Unit::AngularAcceleration::RevolutionPerSquareHour
  });
}

void test_angular_speed() noexcept {
  test_conversions<PhQ::Unit::AngularSpeed>("Angular Speed", 1.0, {
    PhQ::Unit::AngularSpeed::RadianPerSecond,
    PhQ::Unit::AngularSpeed::RadianPerMinute,
    PhQ::Unit::AngularSpeed::RadianPerHour,
    PhQ::Unit::AngularSpeed::DegreePerSecond,
    PhQ::Unit::AngularSpeed::DegreePerMinute,
    PhQ::Unit::AngularSpeed::DegreePerHour,
    PhQ::Unit::AngularSpeed::RevolutionPerSecond,
    PhQ::Unit::AngularSpeed::RevolutionPerMinute,
    PhQ::Unit::AngularSpeed::RevolutionPerHour
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

void test_diffusivity() noexcept {
  test_conversions<PhQ::Unit::Diffusivity>("Diffusivity", 1.0, {
    PhQ::Unit::Diffusivity::SquareMetrePerSecond,
    PhQ::Unit::Diffusivity::SquareMilePerSecond,
    PhQ::Unit::Diffusivity::SquareKilometrePerSecond,
    PhQ::Unit::Diffusivity::SquareYardPerSecond,
    PhQ::Unit::Diffusivity::SquareMetrePerSecond,
    PhQ::Unit::Diffusivity::SquareFootPerSecond,
    PhQ::Unit::Diffusivity::SquareDecimetrePerSecond,
    PhQ::Unit::Diffusivity::SquareInchPerSecond,
    PhQ::Unit::Diffusivity::SquareCentimetrePerSecond,
    PhQ::Unit::Diffusivity::SquareMillimetrePerSecond,
    PhQ::Unit::Diffusivity::SquareMilliinchPerSecond,
    PhQ::Unit::Diffusivity::SquareMicrometrePerSecond,
    PhQ::Unit::Diffusivity::SquareMicroinchPerSecond
  });
}

void test_dynamic_viscosity() noexcept {
  test_conversions<PhQ::Unit::DynamicViscosity>("Dynamic Viscosity", 1.0, {
    PhQ::Unit::DynamicViscosity::PascalSecond,
    PhQ::Unit::DynamicViscosity::KilopascalSecond,
    PhQ::Unit::DynamicViscosity::MegapascalSecond,
    PhQ::Unit::DynamicViscosity::GigapascalSecond,
    PhQ::Unit::DynamicViscosity::PoundSecondPerSquareFoot,
    PhQ::Unit::DynamicViscosity::PoundSecondPerSquareInch
  });
}

void test_energy() noexcept {
  test_conversions<PhQ::Unit::Energy>("Energy", 1.0, {
    PhQ::Unit::Energy::Joule,
    PhQ::Unit::Energy::Millijoule,
    PhQ::Unit::Energy::Microjoule,
    PhQ::Unit::Energy::Nanojoule,
    PhQ::Unit::Energy::Kilojoule,
    PhQ::Unit::Energy::Megajoule,
    PhQ::Unit::Energy::Gigajoule,
    PhQ::Unit::Energy::FootPound,
    PhQ::Unit::Energy::InchPound
  });
}

void test_force() noexcept {
  test_conversions<PhQ::Unit::Force>("Force", 1.0, {
    PhQ::Unit::Force::Newton,
    PhQ::Unit::Force::Micronewton,
    PhQ::Unit::Force::Pound
  });
}

void test_frequency() noexcept {
  test_conversions<PhQ::Unit::Frequency>("Frequency", 1.0, {
    PhQ::Unit::Frequency::Hertz,
    PhQ::Unit::Frequency::Kilohertz,
    PhQ::Unit::Frequency::Megahertz,
    PhQ::Unit::Frequency::Gigahertz
  });
}


void test_heat_capacity() noexcept {
  test_conversions<PhQ::Unit::HeatCapacity>("Heat Capacity", 1.0, {
    PhQ::Unit::HeatCapacity::JoulePerKelvin,
    PhQ::Unit::HeatCapacity::NanojoulePerKelvin,
    PhQ::Unit::HeatCapacity::FootPoundPerRankine,
    PhQ::Unit::HeatCapacity::InchPoundPerRankine
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

void test_mass_density() noexcept {
  test_conversions<PhQ::Unit::MassDensity>("Mass Density", 1.0, {
    PhQ::Unit::MassDensity::KilogramPerCubicMetre,
    PhQ::Unit::MassDensity::GramPerCubicMillimetre,
    PhQ::Unit::MassDensity::SlugPerCubicFoot,
    PhQ::Unit::MassDensity::SlinchPerCubicInch,
    PhQ::Unit::MassDensity::PoundPerCubicFoot,
    PhQ::Unit::MassDensity::PoundPerCubicInch
  });
}

void test_mass_rate() noexcept {
  test_conversions<PhQ::Unit::MassRate>("Mass Rate", 1.0, {
    PhQ::Unit::MassRate::KilogramPerSecond,
    PhQ::Unit::MassRate::GramPerSecond,
    PhQ::Unit::MassRate::SlugPerSecond,
    PhQ::Unit::MassRate::SlinchPerSecond,
    PhQ::Unit::MassRate::PoundPerSecond
  });
}

void test_memory() noexcept {
  test_conversions<PhQ::Unit::Memory>("Memory", 1.0, {
    PhQ::Unit::Memory::Bit,
    PhQ::Unit::Memory::Byte,
    PhQ::Unit::Memory::Kilobyte,
    PhQ::Unit::Memory::Megabyte,
    PhQ::Unit::Memory::Gigabyte,
    PhQ::Unit::Memory::Terabyte
  });
}

void test_memory_rate() noexcept {
  test_conversions<PhQ::Unit::MemoryRate>("Memory Rate", 1.0, {
    PhQ::Unit::MemoryRate::BitPerSecond,
    PhQ::Unit::MemoryRate::BytePerSecond,
    PhQ::Unit::MemoryRate::KilobytePerSecond,
    PhQ::Unit::MemoryRate::MegabytePerSecond,
    PhQ::Unit::MemoryRate::GigabytePerSecond,
    PhQ::Unit::MemoryRate::TerabytePerSecond
  });
}

void test_power() noexcept {
  test_conversions<PhQ::Unit::Power>("Power", 1.0, {
    PhQ::Unit::Power::Watt,
    PhQ::Unit::Power::Milliwatt,
    PhQ::Unit::Power::Microwatt,
    PhQ::Unit::Power::Nanowatt,
    PhQ::Unit::Power::Kilowatt,
    PhQ::Unit::Power::Megawatt,
    PhQ::Unit::Power::Gigawatt,
    PhQ::Unit::Power::FootPoundPerSecond,
    PhQ::Unit::Power::InchPoundPerSecond
  });
}

void test_pressure() noexcept {
  test_conversions<PhQ::Unit::Pressure>("Pressure", 1.0, {
    PhQ::Unit::Pressure::Pascal,
    PhQ::Unit::Pressure::Kilopascal,
    PhQ::Unit::Pressure::Megapascal,
    PhQ::Unit::Pressure::Gigapascal,
    PhQ::Unit::Pressure::PoundPerSquareFoot,
    PhQ::Unit::Pressure::PoundPerSquareInch
  });
}

void test_specific_energy() noexcept {
  test_conversions<PhQ::Unit::SpecificEnergy>("Specific Energy", 1.0, {
    PhQ::Unit::SpecificEnergy::JoulePerKilogram,
    PhQ::Unit::SpecificEnergy::NanojoulePerGram,
    PhQ::Unit::SpecificEnergy::FootPoundPerSlug,
    PhQ::Unit::SpecificEnergy::InchPoundPerSlinch
  });
}

void test_specific_power() noexcept {
  test_conversions<PhQ::Unit::SpecificPower>("Specific Power", 1.0, {
    PhQ::Unit::SpecificPower::WattPerKilogram,
    PhQ::Unit::SpecificPower::NanowattPerGram,
    PhQ::Unit::SpecificPower::FootPoundPerSlugPerSecond,
    PhQ::Unit::SpecificPower::InchPoundPerSlinchPerSecond
  });
}

void test_speed() noexcept {
  test_conversions<PhQ::Unit::Speed>("Speed", 1.0, {
    PhQ::Unit::Speed::MilePerSecond,
    PhQ::Unit::Speed::KilometrePerSecond,
    PhQ::Unit::Speed::YardPerSecond,
    PhQ::Unit::Speed::MetrePerSecond,
    PhQ::Unit::Speed::FootPerSecond,
    PhQ::Unit::Speed::DecimetrePerSecond,
    PhQ::Unit::Speed::InchPerSecond,
    PhQ::Unit::Speed::CentimetrePerSecond,
    PhQ::Unit::Speed::MillimetrePerSecond,
    PhQ::Unit::Speed::MilliinchPerSecond,
    PhQ::Unit::Speed::MicrometrePerSecond,
    PhQ::Unit::Speed::MicroinchPerSecond
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

void test_volume_rate() noexcept {
  test_conversions<PhQ::Unit::VolumeRate>("Volume Rate", 1.0, {
    PhQ::Unit::VolumeRate::CubicMilePerSecond,
    PhQ::Unit::VolumeRate::CubicKilometrePerSecond,
    PhQ::Unit::VolumeRate::CubicYardPerSecond,
    PhQ::Unit::VolumeRate::CubicMetrePerSecond,
    PhQ::Unit::VolumeRate::CubicFootPerSecond,
    PhQ::Unit::VolumeRate::CubicDecimetrePerSecond,
    PhQ::Unit::VolumeRate::LitrePerSecond,
    PhQ::Unit::VolumeRate::CubicInchPerSecond,
    PhQ::Unit::VolumeRate::CubicCentimetrePerSecond,
    PhQ::Unit::VolumeRate::MillilitrePerSecond,
    PhQ::Unit::VolumeRate::CubicMillimetrePerSecond,
    PhQ::Unit::VolumeRate::CubicMilliinchPerSecond,
    PhQ::Unit::VolumeRate::CubicMicrometrePerSecond,
    PhQ::Unit::VolumeRate::CubicMicroinchPerSecond
  });
}

int main(int argc, char *argv[]) {
  test_acceleration();
  test_angle();
  test_angular_acceleration();
  test_angular_speed();
  test_area();
  test_diffusivity();
  test_dynamic_viscosity();
  test_energy();
  test_force();
  test_frequency();
  test_heat_capacity();
  test_length();
  test_mass();
  test_mass_density();
  test_mass_rate();
  test_memory();
  test_memory_rate();
  test_power();
  test_pressure();
  test_specific_energy();
  test_specific_power();
  test_speed();
  test_temperature();
  test_time();
  test_volume();
  test_volume_rate();
  std::cout << test_separator << std::endl;
  return EXIT_SUCCESS;
}
