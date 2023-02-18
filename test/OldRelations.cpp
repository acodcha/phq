// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/Acceleration.hpp"
#include "../include/PhQ/AngularSpeed.hpp"
#include "../include/PhQ/AreaVector.hpp"
#include "../include/PhQ/BulkDynamicViscosity.hpp"
#include "../include/PhQ/DisplacementGradient.hpp"
#include "../include/PhQ/DynamicViscosity.hpp"
#include "../include/PhQ/HeatFlux.hpp"
#include "../include/PhQ/IsentropicBulkModulus.hpp"
#include "../include/PhQ/IsothermalBulkModulus.hpp"
#include "../include/PhQ/LameFirstModulus.hpp"
#include "../include/PhQ/LinearThermalExpansionCoefficient.hpp"
#include "../include/PhQ/MassRate.hpp"
#include "../include/PhQ/MemoryRate.hpp"
#include "../include/PhQ/PoissonRatio.hpp"
#include "../include/PhQ/Position.hpp"
#include "../include/PhQ/PrandtlNumber.hpp"
#include "../include/PhQ/PWaveModulus.hpp"
#include "../include/PhQ/ReynoldsNumber.hpp"
#include "../include/PhQ/ShearModulus.hpp"
#include "../include/PhQ/SpecificGasConstant.hpp"
#include "../include/PhQ/SpecificPower.hpp"
#include "../include/PhQ/StrainRate.hpp"
#include "../include/PhQ/Stress.hpp"
#include "../include/PhQ/TemperatureGradient.hpp"
#include "../include/PhQ/ThermalConductivity.hpp"
#include "../include/PhQ/ThermalDiffusivity.hpp"
#include "../include/PhQ/TotalKinematicPressure.hpp"
#include "../include/PhQ/Traction.hpp"
#include "../include/PhQ/VelocityGradient.hpp"
#include "../include/PhQ/VolumeRate.hpp"
#include "../include/PhQ/VolumetricThermalExpansionCoefficient.hpp"
#include "../include/PhQ/YoungModulus.hpp"

int main(int argc, char *argv[]) {
  std::chrono::high_resolution_clock::time_point start{std::chrono::high_resolution_clock::now()};

  std::cout << "Hash: " << std::hash<PhQ::Value::Vector>()(PhQ::Value::Vector{1.0, 2.0, 3.0}) << std::endl;
  std::cout << "Hash: " << std::hash<PhQ::Displacement>()(PhQ::Displacement{{3.0, 2.0, 1.0}, PhQ::Unit::Length::Metre}) << std::endl;

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
