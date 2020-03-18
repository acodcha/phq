#include "Quantity/Dimensional/Scalar/Length.hpp"
#include "Quantity/Dimensionless/Scalar/ReynoldsNumber.hpp"
#include "Vector.hpp"
#include "Unit/Relation.hpp"

int main(int argc, char *argv[]) {
  std::chrono::high_resolution_clock::time_point start{std::chrono::high_resolution_clock::now()};

  PhQ::Dimension::Set dim{{1}, {-1}, {2}, {-2}, {3}, {-3}, {4}};
  std::cout << dim << std::endl;
  std::cout << dim.json() << std::endl;
  std::cout << dim.xml() << std::endl;

  double time{600.0};
  time = PhQ::Unit::convert(time, PhQ::Unit::Time::Second, PhQ::Unit::Time::Hour);
  std::cout << time << std::endl;

  std::array<double, 3> times{100.0, 200.0, 300.0};
  times = PhQ::Unit::convert(times, PhQ::Unit::Time::Second, PhQ::Unit::Time::Hour);
  std::cout << times[0] << " " << times[1] << " " << times[2] << std::endl;

  PhQ::Value::CartesianVector u{10.0, 20.0, 30.0};
  PhQ::Value::CartesianVector v{-10.0, 40.0, -50.0};
  u += v;
  u *= 2;
  std::cout << 2.0 * u << std::endl;

  PhQ::ReynoldsNumber re{1000.0};
  re *= 10.0;
  std::cout << re << std::endl;

  std::cout << PhQ::System::MetreKilogramSecondKelvin << std::endl;

  PhQ::Length length1{10.0, PhQ::Unit::Length::Inch};
  std::cout << length1 << " = " << length1.print(PhQ::Unit::Length::Inch) << std::endl;
  PhQ::Length length2{10.0, PhQ::Unit::Length::Centimetre};
  std::cout << length2 << std::endl;
  std::cout << PhQ::Length{length1 - length2} << std::endl;
  //std::cout << std::pair{length, PhQ::Unit::Length::Inch} << std::endl;
  //std::cout << std::pair{length, PhQ::System::InchPoundSecondRankine} << std::endl;

  const auto duration{std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start)};
  std::cout << duration.count() << std::endl;
  return EXIT_SUCCESS;
}
