#include "Angle.hpp"
#include "DisplacementGradient.hpp"
#include "Mass.hpp"
#include "Position.hpp"
#include "ReynoldsNumber.hpp"
#include "Strain.hpp"
#include "Stress.hpp"
#include "Time.hpp"
#include "Temperature.hpp"
#include "Volume.hpp"

int main(int argc, char *argv[]) {
  std::chrono::high_resolution_clock::time_point start{std::chrono::high_resolution_clock::now()};

  PhQ::Dimension::Set dim{{1}, {-1}, {2}, {-2}, {3}, {-3}, {4}};
  std::cout << dim << std::endl;
  std::cout << dim.json() << std::endl;
  std::cout << dim.xml() << std::endl;

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

  PhQ::Strain strain1{{1.0, 2.0, 3.0, 4.0, 5.0, 6.0}};
  std::cout << strain1 << std::endl;

  PhQ::Stress stress1{{10.0, 20.0, 30.0, 40.0, 50.0, 60.0}, PhQ::Unit::Pressure::PoundPerSquareInch};
  std::cout << stress1 << std::endl;

  PhQ::Mass mass1{10.0, PhQ::Unit::Mass::Pound};
  std::cout << mass1 << std::endl;

  const auto duration{std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start)};
  std::cout << "Runtime: " << duration.count() << " microseconds." << std::endl;
  return EXIT_SUCCESS;
}
