// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#include "../lib/Acceleration.hpp"
#include "../lib/AngularSpeed.hpp"
#include "../lib/AreaVector.hpp"
#include "../lib/BulkDynamicViscosity.hpp"
#include "../lib/DisplacementGradient.hpp"
#include "../lib/DynamicViscosity.hpp"
#include "../lib/HeatFlux.hpp"
#include "../lib/IsentropicBulkModulus.hpp"
#include "../lib/IsothermalBulkModulus.hpp"
#include "../lib/LameFirstModulus.hpp"
#include "../lib/LinearThermalExpansionCoefficient.hpp"
#include "../lib/MassRate.hpp"
#include "../lib/MemoryRate.hpp"
#include "../lib/PoissonRatio.hpp"
#include "../lib/Position.hpp"
#include "../lib/PrandtlNumber.hpp"
#include "../lib/PWaveModulus.hpp"
#include "../lib/ReynoldsNumber.hpp"
#include "../lib/ShearModulus.hpp"
#include "../lib/SpecificGasConstant.hpp"
#include "../lib/SpecificPower.hpp"
#include "../lib/StrainRate.hpp"
#include "../lib/Stress.hpp"
#include "../lib/TemperatureGradient.hpp"
#include "../lib/ThermalConductivity.hpp"
#include "../lib/ThermalDiffusivity.hpp"
#include "../lib/TotalKinematicPressure.hpp"
#include "../lib/Traction.hpp"
#include "../lib/VelocityGradient.hpp"
#include "../lib/VolumeRate.hpp"
#include "../lib/VolumetricThermalExpansionCoefficient.hpp"
#include "../lib/YoungModulus.hpp"

int main(int argc, char *argv[]) {
  std::chrono::high_resolution_clock::time_point start{std::chrono::high_resolution_clock::now()};

  PhQ::Time time{10.0, PhQ::Unit::Time::Minute};
  time /= 2.0;
  std::cout << time << std::endl;

  PhQ::Value::Vector u{10.0, 20.0, 30.0};
  PhQ::Value::Vector v{-10.0, 40.0, -50.0};
  u += v;
  u *= 2;
  std::cout << u * 2.0 << std::endl;

  PhQ::ReynoldsNumber re{1000.0};
  re *= 10.0;
  std::cout << re << std::endl;

  std::cout << PhQ::abbreviation(PhQ::System::MetreKilogramSecondKelvin) << std::endl;

  PhQ::Length length1{10.0, PhQ::Unit::Length::Inch};
  std::cout << length1 << " = " << length1.print(PhQ::Unit::Length::Inch) << std::endl;
  PhQ::Length length2{10.0, PhQ::Unit::Length::Centimetre};
  std::cout << length2 << std::endl;
  std::cout << PhQ::Length{length1 - length2} << std::endl;

  PhQ::Position position1{{10.0, 20.0, 30.0}, PhQ::Unit::Length::Inch};
  std::cout << "Position = " <<  position1 << " = " << position1.print(PhQ::Unit::Length::Inch) << ". Magnitude = " << position1.magnitude() << "." << std::endl;

  PhQ::Mass mass1{10.0, PhQ::Unit::Mass::Pound};
  std::cout << mass1 << std::endl;

  const auto duration{std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start)};
  std::cout << "Runtime: " << duration.count() << " microseconds." << std::endl;
  return EXIT_SUCCESS;
}
