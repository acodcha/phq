# Physical Quantities (PhQ)

[![tests](https://github.com/acodcha/phq/actions/workflows/tests.yaml/badge.svg?branch=main)](https://github.com/acodcha/phq/actions/workflows/tests.yaml)

Physical Quantities (PhQ) is a C++ library of physical quantities, physical models, and units of measure for scientific computation.

```C++
PhQ::Velocity velocity{{6.0, -3.0, 2.0}, PhQ::Unit::Speed::MetrePerSecond};

PhQ::Speed speed = velocity.Magnitude();
std::cout << "Speed: " << speed << std::endl;
// Speed: 7.00000000000000000 m/s

PhQ::Direction direction = velocity.Direction();
std::cout << "Direction: " << direction << std::endl;
// Direction: (0.857142857142857095, -0.428571428571428548, 0.285714285714285698)

PhQ::Time time{0.5, PhQ::Unit::Time::Minute};
std::cout << "Time: " << time << std::endl;
// Time: 30.0000000000000000 s

PhQ::Displacement displacement = velocity * time;
std::cout << "Displacement: " << displacement.Print(PhQ::Unit::Length::Centimetre) << std::endl;
// Displacement: (1.80000000000000000e+04, -9000.00000000000000, 6000.00000000000000) cm
```

If you have ever made a unit conversion error, or if you have ever asked yourself questions such as _"what is the correct unit of mass density in the foot-pound-second system?"_, _"how do I compute a stress field given a strain field?"_, or _"what is a slug unit?"_, then this library is for you!

- Physical quantities have no memory overhead compared to using raw floating-point numbers to represent the same data.
- Mathematical operations between physical quantities have no runtime overhead compared to using raw floating-point numbers to perform the same operations.
- Unit conversions are handled automatically when physical quantities are constructed, so physical quantities are guaranteed to always be in a consistent state. No more unit conversion errors!
- Physical models enable tedious mathematical computations involving physical quantities to be performed easily. No more tensor-vector multiplication errors when computing stresses!
- Unit systems allow scientific data to be expressed in several consistent systems of units for use across applications. Never again will you accidentally use pounds when you should have used slugs!

## Contents

- [Requirements](#requirements)
- [Configuration](#configuration)
  - [CMake](#configuration-cmake)
  - [Bazel](#configuration-bazel)
- [Usage](#usage)
  - [Basics](#usage-basics)
  - [Vectors and Tensors](#usage-vectors-and-tensors)
  - [Operations](#usage-operations)
  - [Units](#usage-units)
  - [Unit Systems](#usage-unit-systems)
  - [Physical Models](#usage-physical-models)
  - [Physical Dimensions](#usage-physical-dimensions)
  - [Divisions by Zero](#usage-divisions-by-zero)
  - [Exceptions](#usage-exceptions)
- [Documentation](#documentation)
- [Installation](#installation)
- [Testing](#testing)
- [License](#license)

## Requirements

The Physical Quantities library requires the following packages:

- **C++ Compiler:** A C++ compiler with support for the C++17 standard or any more recent standard is needed. Any recent C++ compiler will do, such as GCC or Clang. On Ubuntu, install GCC with `sudo apt install g++` or Clang with `sudo apt install clang`.
- **CMake** or **Bazel:** Either the CMake build system or the Bazel build system is required.
  - **CMake:** On Ubuntu, install CMake with `sudo apt install cmake`. Visit <https://cmake.org> for alternative means of installation.
  - **Bazel:** Follow the instructions at <https://bazel.build/install> to install Bazel on your system.

[(Back to Top)](#physical-quantities-phq)

## Configuration

The Physical Quantities library can be configured with either the CMake build system or the Bazel build system.

- [CMake](#configuration-cmake)
- [Bazel](#configuration-bazel)

[(Back to Top)](#physical-quantities-phq)

### Configuration: CMake

To use this library in one of your CMake C++ projects, add the following code to your project's `CMakeLists.txt` file:

```cmake
set(CMAKE_CXX_STANDARD 17)  # Or any more recent C++ standard.
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
find_package(PhQ CONFIG QUIET)
if(PhQ_FOUND)
    message(STATUS "The PhQ library was found at ${PhQ_CONFIG}")
else()
    FetchContent_Declare(
        PhQ
        GIT_REPOSITORY https://github.com/acodcha/phq.git
        GIT_TAG main
    )
    FetchContent_MakeAvailable(PhQ)
    message(STATUS "The PhQ library was fetched from https://github.com/acodcha/phq.git")
endif()

[...]

target_link_libraries(your_target_name [your_other_options] PhQ)
```

The above code first checks whether the Physical Quantities library is installed on your system (see the [Installation](#installation) section). If found, the library is linked to your target. Otherwise, the library is automatically downloaded from its GitHub repository and linked to your target.

Once this is done, simply include this library's C++ headers in your project's C++ source files, such as `#include <PhQ/Position.hpp>` for the `PhQ::Position` class. The `PhQ::` namespace encapsulates all of the Physical Quantities library's contents.

[(Back to Configuration)](#configuration)

### Configuration: Bazel

To use this library in one of your Bazel C++ projects, do the following.

Add the following code to your project's `WORKSPACE.bazel` file:

```bazel
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
git_repository(
    name = "PhQ",
    remote = "https://github.com/acodcha/phq.git",
    branch = "main",
)
```

The above code automatically downloads the Physical Quantities library and makes it available to your Bazel targets.

Next, add the following code to your project's `BUILD.bazel` file:

```bazel
cc_library(
    name = "your_library_name",
    hdrs = [
        "your_library_header_file_1.hpp",
        "your_library_header_file_2.hpp",
    ],
    srcs = [
        "your_library_source_file_1.cpp",
        "your_library_source_file_2.cpp",
    ],
    deps = [
        ":your_other_dependency_1",
        ":your_other_dependency_2",
        "@PhQ//:Position",
        "@PhQ//:ConstitutiveModel/ElasticIsotropicSolid",
    ],
    copts = [
        "-your-other-parameters",
        "-std=c++17"  # Or any more recent C++ standard.
    ],
)
```

The above code adds the dependencies for the `PhQ::Position` and `PhQ::ConstitutiveModel::ElasticIsotropicSolid` classes to your Bazel C++ library.

Finally, simply include this library's C++ headers in your project's C++ source files, such as `#include <PhQ/Position.hpp>` for the `PhQ::Position` class. The `PhQ::` namespace encapsulates all of this library's contents.

[(Back to Configuration)](#configuration)

## Usage

This section contains basic usage information of the Physical Quantities library; see the [Documentation](#documentation) section for the full documentation.

- [Basics](#usage-basics)
- [Vectors and Tensors](#usage-vectors-and-tensors)
- [Operations](#usage-operations)
- [Units](#usage-units)
- [Unit Systems](#usage-unit-systems)
- [Physical Models](#usage-physical-models)
- [Physical Dimensions](#usage-physical-dimensions)
- [Divisions by Zero](#usage-divisions-by-zero)
- [Exceptions](#usage-exceptions)

[(Back to Top)](#physical-quantities-phq)

### Usage: Basics

Physical quantities are constructed from a value and a unit and support standard arithmetic operations. For example:

```C++
PhQ::Temperature low{10.0, PhQ::Unit::Temperature::Celsius};
PhQ::Temperature high{68.0, PhQ::Unit::Temperature::Fahrenheit};
PhQ::Temperature average = 0.5 * (low + high);
std::cout << "Average: " << average.Print(PhQ::Unit::Temperature::Celsius) << std::endl;
// Average: 15.0000000000000000 °C
```

The above example creates two temperature quantities, computes their average, and prints the result.

Physical quantities support the `float`, `double`, and `long double` floating-point number types. A physical quantity's type is inferred from its constructor arguments and can also be explicitly specified. If no type is explicitly specified and the default constructor is used, the `double` type is used by default. For example:

```C++
// Defaults to PhQ::Area<double>.
PhQ::Area area_double;

// PhQ::Area<float> is inferred from the constructor argument.
PhQ::Area area_float{1.23F, PhQ::Unit::Area::Hectare};

// PhQ::Area<long double> is explicitly specified.
PhQ::Area<long double> area_long_double;
area_long_double = {4.56L, PhQ::Unit::Area::SquareFoot};

// Casts a PhQ::Area<long double> to a PhQ::Area<double>.
// The underlying value is cast from long double to double.
area_double = area_long_double;
```

For performance reasons, physical quantities are constructed with uninitialized values by default. Alternatively, the `Zero()` static method can be used to zero-initialize a physical quantity. For example:

```C++
PhQ::Angle<> angle;  // Uninitialized.
angle = {45.0, PhQ::Unit::Angle::Degree};

PhQ::MachNumber<> mach_number_zero = PhQ::MachNumber<>::Zero();

PhQ::Position<float> position_zero = PhQ::Position<float>::Zero();
```

Physical quantities can be constructed statically with the `Create` static method. For example:

```C++
constexpr PhQ::Power<float> power = PhQ::Power<float>::Create<PhQ::Unit::Power::Kilowatt>(5.0F);
std::cout << "Power: " << power << std::endl;
// Power: 5000.000000 W
```

Physical quantities are implemented efficiently with no memory overhead compared to using raw floating-point numbers to represent the same data. For example:

```C++
PhQ::Volume<double> volume{10.0, PhQ::Unit::Volume::Litre};
assert(sizeof(volume) == sizeof(double));

PhQ::Position<float> position{{-1.11F, 2.22F, -3.33F}, PhQ::Unit::Length::Mile};
assert(sizeof(position) == 3 * sizeof(float));
```

[(Back to Usage)](#usage)

### Usage: Vectors and Tensors

Values can be scalars, vectors, or dyadic tensors. Vectors and dyadic tensors are represented internally in a Cartesian (x-y-z) coordinate system. For example:

```C++
PhQ::Force force{{/*x=*/300.0, /*y=*/0.0, /*z=*/-400.0}, PhQ::Unit::Force::Pound};
force /= 5.0;
PhQ::ScalarForce magnitude = force.Magnitude();
std::cout << "Magnitude: " << magnitude.Print(PhQ::Unit::Force::Pound) << std::endl;
// Magnitude: 100.000000000000000 lbf
```

The above example creates a force quantity of (300, 0, -400) lbf, divides it by 5, computes its magnitude, and prints the magnitude in pounds, which results in 100 lbf.

Many dyadic tensor quantities are symmetric. For example:

```C++
PhQ::Stress stress{
    {/*xx=*/32.0, /*xy=*/-4.0, /*xz=*/-2.0, /*yy=*/16.0, /*yz=*/-1.0, /*zz=*/8.0},
    PhQ::Unit::Pressure::Megapascal};
assert(stress.Value().xy() == stress.Value().yx());
std::cout << "Equivalent von Mises stress: " << stress.VonMises() << std::endl;
// Equivalent von Mises stress: 2.26053091109146290e+07 Pa
```

The above example creates a stress quantity and computes and prints its equivalent von Mises stress.

[(Back to Usage)](#usage)

### Usage: Operations

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. Mathematical operations between physical quantities are implemented efficiently with no runtime overhead compared to using raw floating-point numbers to represent the same data. For example:

```C++
PhQ::Velocity velocity{{50.0, -10.0, 20.0}, PhQ::Unit::Speed::MetrePerSecond};
PhQ::Time time{10.0, PhQ::Unit::Time::Second};
PhQ::Acceleration acceleration = velocity / time;
std::cout << "Acceleration: " << acceleration << std::endl;
// Acceleration: (5.00000000000000000, -1.00000000000000000, 2.00000000000000000) m/s^2
```

The above example creates a velocity quantity of (50, -10, 20) m/s and a time quantity of 10 s, then divides the velocity by the time to produce an acceleration quantity of (5, -1, 2) m/s^2.

Similarly, other meaningful mathematical operations are supported via member methods. For example:

```C++
PhQ::Displacement displacement{{0.0, 6.0, 0.0}, PhQ::Unit::Length::Inch};
PhQ::Length length = displacement.Magnitude();
PhQ::Direction direction = displacement.Direction();
std::cout << "Length and direction: " << length << " and " << direction << std::endl;
// Length and direction: 0.152399999999999980 m and (0, 1.00000000000000000, 0)

PhQ::Displacement other_displacement{{0.0, 0.0, -3.0}, PhQ::Unit::Length::Foot};
PhQ::Angle angle{displacement, other_displacement};
std::cout << "Angle: " << angle.Print(PhQ::Unit::Angle::Degree) << std::endl;
// Angle: 90.0000000000000000 deg
```

The above example creates a displacement quantity of (0, 6, 0) in, computes and prints its magnitude and direction, then creates a second displacement of (0, 0, -3) ft, and computes and prints the angle between the two displacements, which is 90 deg.

[(Back to Usage)](#usage)

### Usage: Units

The Physical Quantities library handles unit conversions automatically, and all unit conversions are exact to within floating-point arithmetic precision.

When a physical quantity object is constructed, its value is immediately converted to the standard unit of measure in the standard system of units: the metre-kilogram-second-kelvin (m·kg·s·K) system. This way, all physical quantities maintain their values in a consistent system of units. This approach greatly minimizes the number of unit conversions during program execution; when arithmetic operations are performed between physical quantities, no unit conversion is needed.

The only other instances where a physical quantity undergoes a unit conversion is when its value is expressed in a different unit of measure or when the physical quantity itself is printed as a string expressed in a different unit of measure. These cases are illustrated in the following examples.

A physical quantity's value can be expressed in any unit of measure through its `Value` method. For example:

```C++
PhQ::Mass mass{10.0, PhQ::Unit::Mass::Pound};

double standard_value = mass.Value();
PhQ::Unit::Mass standard_unit = PhQ::Mass<>::Unit();
std::string_view standard_abbreviation = PhQ::Abbreviation(standard_unit);
std::cout << "Mass: " << standard_value << " " << standard_abbreviation << std::endl;
// Mass: 4.53592 kg

PhQ::Unit::Mass other_unit = PhQ::Unit::Mass::Gram;
std::string_view other_abbreviation = PhQ::Abbreviation(other_unit);
double other_value = mass.Value(other_unit);
std::cout << "Mass: " << other_value << " " << other_abbreviation << std::endl;
// Mass: 4535.92 g
```

The above example creates a 10 lbm mass and prints its value as 4.535924 kg and 4535.924 g.

A physical quantity can be expressed in any unit of measure through its `Print` method. For example:

```C++
PhQ::Frequency frequency{1234.56789, PhQ::Unit::Frequency::Hertz};
std::string standard = frequency.Print();
std::string kilohertz = frequency.Print(PhQ::Unit::Frequency::Kilohertz);
std::cout << "Frequency: " << standard << " = " << kilohertz << std::endl;
// Frequency: 1234.56789000000003 Hz = 1.23456789000000011 kHz
```

The above example creates a 1234.56789 Hz frequency and prints it both in hertz and in kilohertz.

Unit conversions can also be performed explicitly on raw floating-point numbers without the use of physical quantities through the `PhQ::Convert` function, which takes one or more floating-point values, an original unit, and a new unit. For example:

```C++
std::vector<double> values = {10.0, 20.0, 30.0, 40.0};
PhQ::Convert(values, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound);
for (const double value : values) {
  std::cout << value << std::endl;
}
// 7.37562
// 14.7512
// 22.1269
// 29.5025
```

The above example converts a collection of values from joules to foot-pounds. The same can also be achieved with:

```C++
const std::vector<PhQ::Energy<>> quantities = {
    {10.0, PhQ::Unit::Energy::Joule},
    {20.0, PhQ::Unit::Energy::Joule},
    {30.0, PhQ::Unit::Energy::Joule},
    {40.0, PhQ::Unit::Energy::Joule},
};
for (const PhQ::Energy<>& quantity : quantities) {
  std::cout << quantity.Value(PhQ::Unit::Energy::FootPound) << std::endl;
}
// 7.37562
// 14.7512
// 22.1269
// 29.5025
```

In general, when it comes to unit conversions, it is simpler to use the `Value` or `Print` member methods of physical quantities rather than explicitly invoking the `PhQ::Convert` function.

[(Back to Usage)](#usage)

### Usage: Unit Systems

Internally, physical quantities store their values in the metre-kilogram-second-kelvin (m·kg·s·K) system. Unit conversions are performed automatically when physical quantity objects are constructed. Other common systems of units of measure are also defined:

- Metre-kilogram-second-kelvin (m·kg·s·K) system
- Millimetre-gram-second-kelvin (mm·g·s·K) system
- Foot-pound-second-rankine (ft·lbf·s·°R) system
- Inch-pound-second-rankine (in·lbf·s·°R) system

Data can be expressed in the consistent units of any of these unit systems. The unit of measure of a given type that corresponds to a given system of units can be obtained with the `PhQ::ConsistentUnit` function. For example:

```C++
PhQ::UnitSystem system = PhQ::UnitSystem::FootPoundSecondRankine;
PhQ::Unit::SpecificEnergy unit = PhQ::ConsistentUnit<PhQ::Unit::SpecificEnergy>(system);
std::cout << unit << std::endl;
// ft·lbf/slug

PhQ::SpecificEnergy specific_energy{10.0, PhQ::Unit::SpecificEnergy::JoulePerKilogram};
double value = specific_energy.Value(unit);
std::cout << value << std::endl;
// 107.639
```

The above example creates a mass-specific energy quantity of 10 J/kg. Then, the mass-specific energy unit corresponding to the foot-pound-second-rankine (ft·lbf·s·°R) system is obtained, and the mass-specific energy value is expressed in this unit of measure.

Given a unit, it is also possible to obtain its related system of units, if any, with the `PhQ::RelatedUnitSystem` function. For example:

```C++
PhQ::Unit::Mass unit = PhQ::Unit::Mass::Slug;
std::optional<PhQ::UnitSystem> optional_system = PhQ::RelatedUnitSystem(unit);
assert(optional_system.has_value());
std::cout << optional_system.value() << std::endl;
// ft·lbf·s·°R
```

The above example obtains the system of units related to the slug mass unit, which is the foot-pound-second-rankine (ft·lbf·s·°R) system.

However, not all units of measure have a corresponding system of units. For example:

```C++
PhQ::Unit::Mass unit = PhQ::Unit::Mass::Pound;
std::optional<PhQ::UnitSystem> optional_system = PhQ::RelatedUnitSystem(unit);
assert(!optional_system.has_value());
```

The above example shows that the pound (lbm) mass unit does not relate to any particular system of units.

[(Back to Usage)](#usage)

### Usage: Physical Models

Some physical models and related operations are supported. Physical models allow complex mathematical calculations to be performed easily. For example:

```C++
const std::unique_ptr<const ConstitutiveModel> constitutive_model =
    std::make_unique<const ConstitutiveModel::ElasticIsotropicSolid<double>>(
        PhQ::YoungModulus<double>{70.0, PhQ::Unit::Pressure::Gigapascal},
        PhQ::PoissonRatio<double>{0.33});

PhQ::Strain<double> strain{
    /*xx=*/32.0, /*xy=*/-4.0, /*xz=*/-2.0, /*yy=*/16.0, /*yz=*/-1.0, /*zz=*/8.0};

PhQ::Stress<double> stress = constitutive_model->Stress(strain);
std::cout << stress << std::endl;
// (4.54489164086687305e+12, -2.10526315789473663e+11, -1.05263157894736832e+11;
//     3.70278637770897803e+12, -5.26315789473684158e+10; 3.28173374613003076e+12) Pa
```

The above example creates an elastic isotropic solid constitutive model from a Young's modulus and a Poisson's ratio, and then uses it to compute the stress tensor resulting from a given strain tensor.

[(Back to Usage)](#usage)

### Usage: Physical Dimensions

Seven independent base physical dimensions form the physical dimension set of any unit of measure or physical quantity. These seven independent base physical dimensions are: time (T), length (L), mass (M), electric current (I), temperature (Θ), amount of substance (N), and luminous intensity (J). Units of measure that share the same physical dimension set are of the same type and can be converted between one another.

For example, the metre per second and the mile per hour are both units of measure that have the same physical dimension set of T^(-1)·L, which is the physical dimension set of speed, so these two units of measure can be converted between one another.

On the other hand, the kilogram per cubic metre is a unit of measure with physical dimension set L^(-3)·M, which is the physical dimension set of mass density, so this unit of measure cannot be converted to either the metre per second or the mile per hour, which have a different physical dimension set.

The Physical Quantities library organizes units of measure into types, where each type roughly corresponds to a given physical dimension set.

The physical dimension set of a unit of measure can be obtained with the `PhQ::RelatedDimensions` global variable. For example:

```C++
const PhQ::Dimensions dimensions = PhQ::RelatedDimensions<Unit::HeatCapacity>;
assert(dimensions.Time() == PhQ::Dimension::Time(-2));
assert(dimensions.Length() == PhQ::Dimension::Length(2));
assert(dimensions.Mass() == PhQ::Dimension::Mass(1));
assert(dimensions.ElectricCurrent() == PhQ::Dimension::ElectricCurrent(0));
assert(dimensions.Temperature() == PhQ::Dimension::Temperature(-1));
assert(dimensions.SubstanceAmount() == PhQ::Dimension::SubstanceAmount(0));
assert(dimensions.LuminousIntensity() == PhQ::Dimension::LuminousIntensity(0));
std::cout << "Dimensions: " << dimensions << std::endl;
// Dimensions: T^(-2)·L^2·M·Θ^(-1)
```

The above example obtains the physical dimension set of heat capacity, which is T^(-2)·L^2·M·Θ^(-1).

The physical dimension set of a physical quantity is simply the physical dimension set of its unit of measure and can be obtained with the `Dimensions` method. For example:

```C++
const PhQ::Dimensions dimensions = PhQ::MassDensity<>::Dimensions();
assert(dimensions.Time() == PhQ::Dimension::Time(0));
assert(dimensions.Length() == PhQ::Dimension::Length(-3));
assert(dimensions.Mass() == PhQ::Dimension::Mass(1));
assert(dimensions.ElectricCurrent() == PhQ::Dimension::ElectricCurrent(0));
assert(dimensions.Temperature() == PhQ::Dimension::Temperature(0));
assert(dimensions.SubstanceAmount() == PhQ::Dimension::SubstanceAmount(0));
assert(dimensions.LuminousIntensity() == PhQ::Dimension::LuminousIntensity(0));
std::cout << "Dimensions: " << dimensions << std::endl;
// Dimensions: L^(-3)·M
```

The above example obtains the physical dimension set of mass density, which is L^(-3)·M.

[(Back to Usage)](#usage)

### Usage: Divisions by Zero

The Physical Quantities library carefully handles divisions by zero in its internal arithmetic operations. For example, `PhQ::Direction` carefully checks for the zero vector case when normalizing its magnitude, and `PhQ::Dyad` and `PhQ::SymmetricDyad` carefully check for a zero determinant when computing their inverse.

However, in general, divisions by zero can occur during arithmetic operations between physical quantities. For example, `PhQ::Length<>::Zero() / PhQ::Time<>::Zero()` results in a `PhQ::Speed` with a value of "not-a-number" (`NaN`). C++ uses the IEEE 754 floating-point arithmetic standard, which supports divisions by zero such as `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. If any of these special cases are a concern, use try-catch blocks or standard C++ utilities such as `std::isfinite`.

Similarly, floating-point overflows and underflows can occur during arithmetic operations between physical quantities. If this is a concern, query the status of the C++ floating-point environment with `std::fetestexcept`.

[(Back to Usage)](#usage)

### Usage: Exceptions

The only circumstance in which the Physical Quantities library throws an exception is a memory allocation failure due to running out of memory on your system when instantiating a new C++ object. In this case, C++ throws a `std::bad_alloc` exception.

If maintaining a strong exception guarantee is a concern, use `try` and `catch` blocks when instantiating new objects to handle this exception. Other than this case, the Physical Quantities library does not throw exceptions. Where applicable, this library's functions and methods are marked `noexcept`.

[(Back to Usage)](#usage)

## Documentation

The full documentation of the Physical Quantities library is hosted at <https://acodcha.github.io/phq-docs>.

Alternatively, the documentation can be built locally on your system. Doing so requires the following additional package:

- **Doxygen**: The Doxygen library (<https://www.doxygen.nl/index.html>) is used for building documentation. On Ubuntu, install it with `sudo apt install doxygen`.

Clone the Physical Quantities library's repository and build its documentation with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
doxygen Doxyfile
```

This builds HTML documentation pages in the `PhQ/docs/html/` directory. Browse the documentation by opening the `PhQ/docs/html/index.html` file in a web browser.

[(Back to Top)](#physical-quantities-phq)

## Installation

If using the CMake build system, the Physical Quantities library can optionally be installed on your system to conveniently use it in your CMake projects. Alternatively, see the [Configuration](#configuration) section for other methods of use.

Clone this library's repository, configure it, and install it with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
mkdir build
cd build
cmake ..
sudo make install
```

This is a header-only library, so no compilation is needed. On most systems, the above code installs this library's headers to `/usr/local/include/PhQ` and writes configuration files to `/usr/local/share/PhQ`. You can uninstall the library by simply deleting these directories.

[(Back to Top)](#physical-quantities-phq)

## Testing

The Physical Quantities library is automatically tested whenever it is updated.

Testing can optionally be performed locally on your system. Doing so requires the following additional package:

- **GoogleTest**: The GoogleTest library (<https://github.com/google/googletest>) is used for testing. On Ubuntu, install it with `sudo apt install libgtest-dev`. When testing is enabled, if the GoogleTest library is not found on your system, it is automatically downloaded and linked with this library.

Testing instructions differ depending on your build system.

If using the CMake build system, you can manually test the Physical Quantities library on your system with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
mkdir build
cd build
cmake .. -DTEST_PHQ_LIBRARY=ON
make --jobs=16
make test
```

If using the Bazel build system, you can manually test the Physical Quantities library on your system with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
bazel build //:all
bazel test //:all
```

[(Back to Top)](#physical-quantities-phq)

## License

Copyright © 2020-2024 Alexandre Coderre-Chabot

Physical Quantities (PhQ) is a C++ library of physical quantities, physical models, and units of measure for scientific computation.

The Physical Quantities library is hosted at <https://github.com/acodcha/phq> and its documentation is hosted at <https://acodcha.github.io/phq-docs>.

Physical Quantities is authored by Alexandre Coderre-Chabot (<https://github.com/acodcha>) and licensed under the MIT License; see the [license file](LICENSE) or <https://mit-license.org>.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

- The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[(Back to Top)](#physical-quantities-phq)
