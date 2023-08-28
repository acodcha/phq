# Physical Quantities

[![build and test](https://github.com/acodcha/physical-quantities/actions/workflows/build_and_test.yml/badge.svg?branch=main)](https://github.com/acodcha/physical-quantities/actions/workflows/build_and_test.yml)

C++ library of physical quantities, physical models, and units of measure for scientific computation.

- [Requirements](#requirements)
- [Configuration](#configuration)
- [Usage](#usage)
- [Installation](#installation)
- [Testing](#testing)
- [License](#license)

## Requirements

This library requires the following packages:

- **C++17 Compiler:** Any C++17 compiler will do, such as GCC or Clang. On Ubuntu, install GCC with `sudo apt install g++` or Clang with `sudo apt install clang`.
- **CMake:** On Ubuntu, install with `sudo apt install cmake`.

[(Back to Top)](#physical-quantities)

## Configuration

To use the Physical Quantities library in one of your CMake projects, add the following to your `CMakeLists.txt` file:

```cmake
include(FetchContent)
FetchContent_Declare(
  PhQ
  GIT_REPOSITORY https://github.com/acodcha/physical-quantities.git
  GIT_TAG main
)
FetchContent_MakeAvailable(PhQ)

[...]

target_link_libraries(your-target-name [other-options] PhQ)
```

This automatically downloads, builds, and links the Physical Quantities library to your target.

Alternatively, if you have installed the Physical Quantities library on your system as described in the [Installation](#installation) section, you can instead simply add the following to your `CMakeLists.txt` file:

```cmake
find_package(PhQ CONFIG REQUIRED)

[...]

target_link_libraries(your-target-name [other-options] PhQ)
```

To use the Physical Quantities library in your source code, simply include this library's headers in your project's source files, such as `#include <PhQ/Position.hpp>` for the `PhQ::Position` class. The `PhQ::` namespace encapsulates all of the Physical Quantities library's contents.

[(Back to Top)](#physical-quantities)

## Usage

Physical quantities are constructed from a value and a unit. For example:

```C++
PhQ::Temperature low{10.0, PhQ::Unit::Temperature::Celsius};
PhQ::Temperature high{68.0, PhQ::Unit::Temperature::Fahrenheit};
PhQ::Temperature average = 0.5 * (low + high);
std::cout << "average = " << average << std::endl;
```

The above example creates two temperature quantities, computes their average, and prints the result, which is 15 °C.

Values can be scalars, vectors, or dyadic tensors. Vectors and dyadic tensors are represented internally in a Cartesian (x-y-z) coordinate system. For example:

```C++
PhQ::Force force{{300.0, 0.0, -400.0}, PhQ::Unit::Force::Pound};
force /= 5.0;
PhQ::ForceMagnitude magnitude = force.Magnitude();
std::cout << "magnitude = " << magnitude.Print(PhQ::Unit::Force::Pound) << std::endl;
```

The above example creates a force quantity of (300, 0, -400) lbf, divides it by 5, computes its magnitude, and prints the magnitude in pounds, which results in 100 lbf.

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. For example:

```C++
PhQ::Velocity velocity{{50.0, -10.0, 20.0}, PhQ::Unit::Speed::MetrePerSecond};
PhQ::Time time{10.0, PhQ::Unit::Time::Second};
PhQ::Acceleration acceleration = velocity / time;
std::cout << "acceleration = " << acceleration << std::endl;
```

The above example creates a velocity quantity of (50, -10, 20) m/s and a time quantity of 10 s, then divides the velocity by the time to produce an acceleration quantity of (5, -1, 2) m/s^2.

Similarly, other meaningful mathematical operations are supported via member methods. For example:

```C++
PhQ::Displacement displacement1{{0.0, 6.0, 0.0}, PhQ::Unit::Length::Inch};
PhQ::Length length = displacement.Magnitude();
PhQ::Direction direction = displacement.Direction();
std::cout << "length = " << length << ", direction = " << direction << std::endl;

PhQ::Displacement displacement2{{0.0, 0.0, -3.0}, PhQ::Unit::Length::Inch};
PhQ::Angle angle{displacement1, displacement2};
std::cout << "angle = " << angle.Print(PhQ::Unit::Angle::Degree) << std::endl;
```

The above example creates a displacement quantity of (0, 6, 0) in, computes and prints its magnitude and direction, then creates a second displacement of (0, 0, -3) in, and computes and prints the angle between the two displacements, which is 90 deg.

Unit conversions are handled automatically. Internally, physical quantities maintain their values in a consistent unit system: the metre-kilogram-second-kelvin system. A physical quantity's value can be obtained in any unit of measure through its `Value` method. For example:

```C++
PhQ::Mass mass{10.0, PhQ::Unit::Mass::Pound};
double kilograms = mass.Value(PhQ::Unit::Mass::Kilogram);
std::cout << kilograms << std::endl;
```

The above example creates a 10 lbm mass and prints its value as 4.535924 kg.

Unit conversions can also be done explicitly without the use of physical quantities through the `PhQ::Convert` function, which takes a value, an original unit, and a new unit. For example:

```C++
double value = 10.0;
PhQ::Convert(value, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound)
std::cout << value << std::endl;
```

The above example converts 10 J to 7.375621 ft·lbf. The same can also be achieved with:

```C++
PhQ::Energy energy{10.0, PhQ::Unit::Energy::Joule};
double foot_pounds = energy.Value(PhQ::Unit::Energy::FootPound);
std::cout << foot_pounds << std::endl;
```

In general, it is easier to use physical quantities instead of manually invoking the `PhQ::Convert` function.

Some physical models and related operations are also supported. For example:

```C++
PhQ::YoungModulus young_modulus{70.0, PhQ::Unit::Pressure::Gigapascal};
PhQ::PoissonRatio poisson_ratio{0.33};
std::unique_ptr<ConstitutiveModel> constitutive_model =
    std::make_unique<ConstitutiveModel::ElasticIsotropicSolid>(
        young_modulus, poisson_ratio);
PhQ::Strain strain{{32.0, -4.0, -2.0, 16.0, -1.0, 8.0}};
PhQ::Stress stress = constitutive_model->Stress(strain);
std::cout << stress << std::endl;
```

The above example creates an elastic isotropic solid constitutive model from a Young's modulus and a Poisson's ratio, and then uses it to compute the stress tensor given a strain tensor.

Certain operations can result in divisions by zero. C++ supports floating-point divisions by zero, for example with `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. This library makes no attempt to detect, report, or avoid divisions by zero. Instead, it is the implementer's responsibility to determine whether such cases warrant special consideration, for example through the use of try-catch blocks or standard C++ utilities such as `isfinite()`.

The Physical Quantities library does not throw exceptions, and most of this library's functions and methods are marked as `noexcept`. In practice, the only conceivable cause for an exception in this library is a memory allocation failure due to memory exhaustion, which should typically be treated as a fatal error in most applications.

[(Back to Top)](#physical-quantities)

## Installation

You may optionally install the Physical Quantities library on your system to use it in your projects. Alternatively, see the [Configuration](#configuration) section for other methods of use.

First, clone the Physical Quantities library's repository and configure it with:

```bash
git clone git@github.com:acodcha/physical-quantities.git
cd physical-quantities
mkdir build
cd build
cmake ..
```

This is a header-only library, so no compilation is needed.

Second, install the Physical Quantities library on your system from the `build` directory with:

```bash
sudo make install
```

On most systems, this installs the Physical Quantities library's headers to `/usr/local/include/PhQ` and writes configuration files to `/usr/local/share/PhQ`. You can uninstall the Physical Quantities library by simply deleting these directories.

[(Back to Top)](#physical-quantities)

## Testing

Testing is optional, disabled by default, and requires the following additional package:

- **GoogleTest**: The GoogleTest library (<https://github.com/google/googletest>) is used for testing. On Ubuntu, install it with `sudo apt install libgtest-dev`. When testing is enabled, if the GoogleTest library is not found on your system, it is automatically downloaded, built, and linked with the Physical Quantities library.

You can manually test the Physical Quantities library on your system from the `build` directory with:

```bash
cmake .. -DTEST_PHQ_LIBRARY=ON
make --jobs=16
make test
```

[(Back to Top)](#physical-quantities)

## License

This project is maintained by Alexandre Coderre-Chabot (<https://github.com/acodcha>) and licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the `LICENSE` file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

[(Back to Top)](#physical-quantities)
