# Physical Quantities

[![tests](https://github.com/acodcha/phq/actions/workflows/tests.yaml/badge.svg?branch=main)](https://github.com/acodcha/phq/actions/workflows/tests.yaml)

Physical Quantities (PhQ) is a C++ library of physical quantities, physical models, and units of measure for scientific computing. The Physical Quantities library is hosted at <https://github.com/acodcha/phq> and its documentation is hosted at <https://acodcha.github.io/phq-docs>.

Contents:

- [Introduction](#introduction)
- [Configuration](#configuration): [CMake](#configuration-cmake), [Bazel](#configuration-bazel)
- [Background](#background): [Theory](#background-theory), [Design](#background-design)
- [User Guide](#user-guide): [Basics](#user-guide-basics), [Vectors and Tensors](#user-guide-vectors-and-tensors), [Operations](#user-guide-operations), [Models](#user-guide-models), [Units](#user-guide-units), [Unit Systems](#user-guide-unit-systems), [Dimensions](#user-guide-dimensions)
- [Features](#features): [Physical Quantities](#features-physical-quantities), [Models](#features-models), [Units](#features-units), [Unit Systems](#features-unit-systems)
- [Developer Guide](#developer-guide): [Documentation](#developer-guide-documentation), [Installation](#developer-guide-installation), [Testing](#developer-guide-testing), [Coverage](#developer-guide-coverage)
- [License](#license)

## Introduction

The following example illustrates the use of the Physical Quantities library:

```C++
PhQ::Velocity velocity{{6.0, -3.0, 2.0}, PhQ::Unit::Speed::MetrePerSecond};

PhQ::Speed speed = velocity.Magnitude();
std::cout << "Speed: " << speed << std::endl;
// Speed: 7.00000000000000000 m/s

PhQ::Direction direction = velocity.Direction();
std::cout << "Direction: " << direction << std::endl;
// Direction: (0.857142857142857095, -0.428571428571428548, 0.285714285714285698)

PhQ::Time{0.5, PhQ::Unit::Time::Minute};
PhQ::Displacement displacement = velocity * time;
std::cout << "Displacement: " << displacement.Print(PhQ::Unit::Length::Centimetre) << std::endl;
// Displacement: (1.80000000000000000e+04, -9000.00000000000000, 6000.00000000000000) cm
```

The above example creates a velocity quantity, obtains and prints its magnitude and direction, and computes and prints the resulting displacement that occurs over the course of half a minute.

If you have ever made a unit conversion error, or if you have ever asked yourself questions such as _"what is the correct unit of mass density in the foot-pound-second system?"_, _"how do I compute a stress field given a strain field?"_, or _"what is a slug unit?"_, then this library is for you!

- Physical quantities have no memory overhead compared to using plain floating-point numbers to represent the same data.
- Mathematical operations between physical quantities have no runtime overhead compared to using plain floating-point numbers to perform the same operations.
- Unit conversions are handled automatically when physical quantities are constructed such that physical quantities are guaranteed to always be in a consistent state. No more unit conversion errors!
- Physical models enable tedious mathematical computations involving physical quantities to be performed easily. No more tensor-vector multiplication errors when computing stresses!
- Unit systems allow scientific data to be expressed in several consistent systems of units for use across applications. Never again will you accidentally use pounds when you should have used slugs!

[(Back to Top)](#physical-quantities)

## Configuration

The Physical Quantities library is a header-only library written in C++17 and therefore requires a C++ compiler with support for the C++17 standard or any more recent standard. Any recent C++ compiler should do, such as GCC or Clang. Install GCC on Ubuntu with `sudo apt install g++` or visit <https://gcc.gnu.org> for alternate means of installation. Install Clang on Ubuntu with `sudo apt install clang` or visit <https://clang.llvm.org> for alternate means of installation.

The Physical Quantities library also requires a build system. Currently, both the CMake build system and the Bazel build system are supported:

- [CMake](#configuration-cmake)
- [Bazel](#configuration-bazel)

[(Back to Top)](#physical-quantities)

### Configuration: CMake

Install the CMake build system on Ubuntu with `sudo apt install cmake` or visit <https://cmake.org> for alternate means of installation.

To use the Physical Quantities library in one of your CMake C++ projects, add the following code to your project's `CMakeLists.txt` file:

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
    )  # You can also use a specific version such as v1.0.0 instead of the main branch.
    FetchContent_MakeAvailable(PhQ)
    message(STATUS "The PhQ library was fetched from https://github.com/acodcha/phq.git")
endif()

[...]

target_link_libraries(your_target_name [your_other_options] PhQ)
```

The above code first checks whether the Physical Quantities library is installed on your system (see the [Developer Guide](#developer-guide) section). If found, the library is linked to your target. Otherwise, the library is automatically downloaded from its GitHub repository and linked to your target.

Once this is done, simply include the Physical Quantities library's C++ headers in your project's C++ source files, such as `#include <PhQ/Position.hpp>` for the `PhQ::Position` class. The `PhQ::` namespace encapsulates all of the Physical Quantities library's contents.

[(Back to Configuration)](#configuration)

### Configuration: Bazel

Follow the instructions at <https://bazel.build/install> to install the Bazel build system on your system.

To use the Physical Quantities library in one of your Bazel C++ projects, first add the following code to your project's `WORKSPACE.bazel` file:

```bazel
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
git_repository(
    name = "PhQ",
    remote = "https://github.com/acodcha/phq.git",
    branch = "main",
)
# Alternatively, you can use a version tag instead of a branch, such as: tag = "v1.0.0",
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
        "-std=c++17",  # Or any more recent C++ standard.
    ],
)
```

The above code adds the dependencies for the `PhQ::Position` and `PhQ::ConstitutiveModel::ElasticIsotropicSolid` classes to your Bazel C++ library.

Finally, simply include the Physical Quantities library's C++ headers in your project's C++ source files, such as `#include <PhQ/Position.hpp>` for the `PhQ::Position` class. The `PhQ::` namespace encapsulates all of the Physical Quantities library's contents.

[(Back to Configuration)](#configuration)

## Background

This section explains the theoretical foundation and the software design of the Physical Quantities library:

- [Theory](#background-theory)
- [Design](#background-design)

[(Back to Top)](#physical-quantities)

### Background: Theory

In engineering and science, the field of dimensional analysis describes the relationships between physical dimensions, physical dimension sets, units of measure, consistent systems of units of measure, and physical quantities.

Seven independent base physical dimensions form the physical dimension set of any unit of measure. These seven independent base physical dimensions are: time (T), length (L), mass (M), electric current (I), temperature (Θ), amount of substance (N), and luminous intensity (J). Each unit of measure therefore has a physical dimension set of the form T^a·L^b·M^c·I^d·Θ^e·N^f·J^g, where a, b, c, d, e, f, and g are integers.

Units of measure that share the same physical dimension set are of the same type and can be converted between one another. For example, the metre per second (m/s) and the mile per hour (mi/hr) are both units of measure that have the same physical dimension set of T^(-1)·L, which is the physical dimension set of speed, so these two units of measure can be converted between one another. On the other hand, the kilogram per cubic metre (kg/m^3) is a unit of measure with physical dimension set L^(-3)·M, which is the physical dimension set of mass density, so this unit of measure cannot be converted to the speed units, which have a different physical dimension set.

A physical quantity consists of a value expressed in a unit of measure. A physical quantity's value can be a scalar, a vector, or a tensor. For example, static pressure is a scalar quantity, traction is a vector quantity, and stress is a dyadic tensor quantity even though all three of these quantities share the same physical dimension set of pressure.

A physical quantity inherits the physical dimension set of its unit of measure. Physical quantities with the same physical dimension set are of the same type and support mathematical operations between one another, though if their units of measure differ, their values should first be converted to a common unit of measure. For example, a physical quantity of 5 meters per second (5 m/s) and a physical quantity of 10 miles per hour (10 mi/hr) are both physical quantities of speed and can be added or subtracted from each other provided that they are both first converted to the same unit of measure.

Physical quantities of different physical dimension sets can also support mathematical operations between one another if such operations are scientifically meaningful. In such cases, the operation is performed on both the values and the units of measure of the physical quantities, yielding a new physical quantity in a different unit of measure and therefore a new physical dimension set. For example, a speed quantity of 240 feet per minute (240 ft/min) divided by a time quantity of 2 seconds (2 s) results in an acceleration quantity of 120 feet per minute per second (120 ft/min/s). This result can be simplified to 2 feet per square second (2 ft/s^2) by converting minutes into seconds. The speed quantity and the time quantity have physical dimension sets of T^(-1)·L and T respectively, so T^(-1)·L/T yields the physical dimension set of acceleration, which is T^(-2)·L.

Some physical quantities are dimensionless: they have no unit of measure and their physical dimension set is simply the null set. These physical quantities essentially behave like numbers and never require unit conversions. For example, the Mach number is a dimensionless scalar physical quantity while strain is a dimensionless symmetric dyadic tensor physical quantity.

A consistent system of units of measure can be constructed from units of measure whose conversion factors are all unity. For example, the International System of Units (SI) defines the metre-kilogram-second-kelvin (m·kg·s·K) system. In this system, the physical dimension of length is expressed in the metre (m), mass is expressed in kilograms (kg), time in seconds (s), temperature in kelvin (K), electric current in amperes (A), amount of substance in moles (mol), and luminous intensity in candela (cd). All other units of measure are expressed as combinations of these basic units with multiplicative factors of unity. For example, the unit of speed is simply the metre per second (m/s), the unit of force is the newton (N), which equals 1 kg·m/s^2, the unit of energy is the joule (J), which equals 1 N·m = 1 kg·m^2/s^2, the unit of power is the Watt (W), which equals 1 J/s = 1 kg·m^2/s^3, and so on. When physical quantities express their values in units of measure that belong to a consistent system of units, no unit conversions are needed on operations between such physical quantities.

[(Back to Background)](#background)

### Background: Design

A naive design for a physical quantity might be an object that contains a value and a unit of measure. However, this design has many shortcomings. First, it would have a larger memory footprint than a plain floating-point number that contained only the value. Second, a unit conversion would be required on every mathematical operation between physical quantities. For example, computing 20 centimeters + 3 feet would first require converting the 3 feet quantity into centimeters, which would require looking up the conversion operation in a table and then performing the conversion operation. This would be much more computationally expensive than simply adding two plain floating-point numbers. Thus, such a design would impose significant memory and runtime costs compared to using plain floating-point numbers.

Instead, the Physical Quantities library employs a better design: each physical quantity only stores a value and always maintain this value in a consistent system of units. The constructors, accessors, and mutators of physical quantities are carefully designed to always enforce this requirement. This way, a physical quantity has the same memory footprint as a plain floating-point number.

In addition, since the value of each physical quantity is always maintained in a consistent system of units, mathematical operations between physical quantities require no unit conversions and remain just as computationally efficient as mathematical operations between plain floating-point numbers. The only required unit conversion occurs during the initial construction of the physical quantity. However, this unit conversion is avoided when physical quantities are default-constructed, and in other cases, this unit conversion can be optimized to be a compile-time constant expression if the physical quantity's value and unit of measure are known at compile time.

Thus, in the Physical Quantities library, physical quantities have no memory overhead compared to using plain floating-point numbers to represent the same data, mathematical operations between physical quantities have no runtime overhead compared to using plain floating-point numbers to perform the same operations, and unit conversions are handled automatically when physical quantities are constructed such that physical quantities are guaranteed to always be in a consistent state. These advantages make the Physical Quantities library suitable for use in scientific computing applications with tight performance requirements.

[(Back to Background)](#background)

## User Guide

This section presents a basic guide on the use of the Physical Quantities library:

- [Basics](#user-guide-basics)
- [Vectors and Tensors](#user-guide-vectors-and-tensors)
- [Operations](#user-guide-operations)
- [Models](#user-guide-models)
- [Units](#user-guide-units)
- [Unit Systems](#user-guide-unit-systems)
- [Dimensions](#user-guide-dimensions)

In addition to this user guide, the full documentation of the Physical Quantities library is hosted at <https://acodcha.github.io/phq-docs>.

[(Back to Top)](#physical-quantities)

### User Guide: Basics

Physical quantities are constructed from a value and a unit and support standard arithmetic operations. For example:

```C++
PhQ::Temperature low{10.0, PhQ::Unit::Temperature::Celsius};
PhQ::Temperature high{68.0, PhQ::Unit::Temperature::Fahrenheit};
PhQ::Temperature average = 0.5 * (low + high);
std::cout << "Average: " << average.Print(PhQ::Unit::Temperature::Celsius) << std::endl;
// Average: 15.0000000000000000 °C
```

The above example creates two temperature quantities, computes their average, and prints the result.

Physical quantities support the `float`, `double`, and `long double` floating-point numeric types. A physical quantity's type is inferred from its constructor arguments and can also be explicitly specified. If no type is explicitly specified and the default constructor is used, the `double` type is used by default. For example:

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

Physical quantities are implemented efficiently with no memory overhead compared to using plain floating-point numbers to represent the same data. For example:

```C++
PhQ::Volume<double> volume{10.0, PhQ::Unit::Volume::Litre};
assert(sizeof(volume) == sizeof(double));

PhQ::Position<float> position{{-1.11F, 2.22F, -3.33F}, PhQ::Unit::Length::Mile};
assert(sizeof(position) == 3 * sizeof(float));
```

The only circumstance in which the Physical Quantities library throws an exception is a memory allocation failure due to running out of memory on your system when instantiating a new C++ object. In this case, C++ throws a `std::bad_alloc` exception.

If maintaining a strong exception guarantee is a concern, use `try` and `catch` blocks when instantiating new objects to handle this exception. Other than this case, the Physical Quantities library does not throw exceptions. Where applicable, the Physical Quantities library's functions and methods are marked `noexcept`.

[(Back to User Guide)](#user-guide)

### User Guide: Vectors and Tensors

Physical quantities' values can be scalars, vectors, or dyadic tensors. Vectors and dyadic tensors are defined in three-dimensional Euclidean space and use Cartesian coordinates. For example:

```C++
PhQ::HeatFlux heat_flux{{-200.0,  // x
                          300.0,  // y
                         -600.0}, // z
                        PhQ::Unit::EnergyFlux::WattPerSquareMetre};
heat_flux /= 7.0;
PhQ::ScalarHeatFlux magnitude = heat_flux.Magnitude();
std::cout << "Magnitude: " << magnitude.Print() << std::endl;
// Magnitude: 100.000000000000000 W/m^2
```

The above example creates a heat flux of (-200, 300, -600) W/m^2, divides it by 7, and computes and prints its magnitude, which results in 100 W/m^2.

Two-dimensional planar vectors in the XY plane are also supported. For example:

```C++
PhQ::PlanarForce planar_force{{-300.0,  // x
                                400.0}, // y
                              PhQ::Unit::Force::Pound};
planar_force *= 2.0;
PhQ::ScalarForce magnitude = planar_force.Magnitude();
std::cout << "Magnitude: " << magnitude.Print(PhQ::Unit::Force::Pound) << std::endl;
// Magnitude: 1000.00000000000000 lbf
```

The above example creates a planar force of (-300, 400) lbf, doubles it, computes its magnitude, and prints the magnitude in pounds, which results in 1,000 lbf.

The components of dyadic tensors are listed in alphabetical order: xx, xy, xz, yx, yy, yz, zx, zy, and zz. Some dyadic tensor physical quantities are symmetric while others are asymmetric. Symmetric dyadic tensors only need to specify their upper triangular components: xx, xy, xz, yy, yz, and zz. For example:

```C++
PhQ::Stress stress{{32.0,  // xx
                    -4.0,  // xy = yx
                    -2.0,  // xz = zx
                    16.0,  // yy
                    -1.0,  // yz = zy
                     8.0}, // zz
                   PhQ::Unit::Pressure::Megapascal};
assert(stress.Value().xy() == stress.Value().yx());
std::cout << "Equivalent von Mises stress: " << stress.VonMises() << std::endl;
// Equivalent von Mises stress: 2.26053091109146290e+07 Pa
```

The above example creates a stress tensor, asserts that it is symmetric, and computes and prints its equivalent von Mises stress.

[(Back to User Guide)](#user-guide)

### User Guide: Operations

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. Mathematical operations between physical quantities are implemented efficiently with no runtime overhead compared to using plain floating-point numbers to represent the same data. For example:

```C++
PhQ::Velocity velocity{{50.0, -10.0, 20.0}, PhQ::Unit::Speed::MetrePerSecond};
PhQ::Time time{10.0, PhQ::Unit::Time::Second};
PhQ::Acceleration acceleration = velocity / time;
std::cout << "Acceleration: " << acceleration << std::endl;
// Acceleration: (5.00000000000000000, -1.00000000000000000, 2.00000000000000000) m/s^2
```

The above example creates a velocity of (50, -10, 20) m/s and a time of 10 s, then divides the velocity by the time to produce an acceleration of (5, -1, 2) m/s^2.

Similarly, other meaningful mathematical operations are supported via member methods and constructors. For example:

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

The above example creates a displacement of (0, 6, 0) in, computes and prints its magnitude and direction, then creates a second displacement of (0, 0, -3) ft, and computes and prints the angle between the two displacements, which is 90 deg.

Physical quantities define the standard comparison operators (`==`, `!=`, `<`, `>`, `<=`, and `>=`) and specialize the `std::hash` function object such that they can be used in standard containers such as `std::set`, `std::unordered_set`, `std::map`, and `std::unordered_map`. For example:

```C++
assert(PhQ::MachNumber(0.8) == PhQ::MachNumber(0.8));
assert(PhQ::ReynoldsNumber(5000.0) > PhQ::ReynoldsNumber(200.0));

std::set<PhQ::AngularSpeed<>> angular_speed_set{
  PhQ::AngularSpeed(1.23, PhQ::Unit::AngularSpeed::RadianPerSecond),
  PhQ::AngularSpeed(4.56, PhQ::Unit::AngularSpeed::RevolutionPerMinute),
};  // Uses the less-than comparison operator (<).

std::unordered_set<PhQ::StaticPressure<>> static_pressure_unordered_set{
  PhQ::StaticPressure(1.23, PhQ::Unit::Pressure::Kilopascal),
  PhQ::StaticPressure(4.56, PhQ::Unit::Pressure::Bar),
};  // Uses std::hash<PhQ::StaticPressure<>>.
```

The Physical Quantities library checks for divisions by zero in certain critical internal arithmetic operations. For example, `PhQ::Direction` carefully checks for the zero vector case when normalizing its magnitude, and `PhQ::Dyad` and `PhQ::SymmetricDyad` carefully check for a zero determinant when computing their inverse.

However, in general, divisions by zero can occur during arithmetic operations between physical quantities. For example, `PhQ::Length<>::Zero() / PhQ::Time<>::Zero()` results in a `PhQ::Speed` with a value of "not-a-number" (`NaN`). C++ uses the IEEE 754 floating-point arithmetic standard such that divisions by zero result in `inf`, `-inf`, or `NaN`. If any of these special cases are a concern, use `try` and `catch` blocks or standard C++ utilities such as `std::isfinite`.

Similarly, floating-point overflows and underflows can occur during arithmetic operations between physical quantities. If this is a concern, query the status of the C++ floating-point environment with `std::fetestexcept`.

[(Back to User Guide)](#user-guide)

### User Guide: Models

The Physical Quantities library supports certain physical models. These physical models allow tedious mathematical calculations to be performed easily. For example:

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

[(Back to User Guide)](#user-guide)

### User Guide: Units

The Physical Quantities library handles unit conversions automatically, and all unit conversions are exact to within floating-point arithmetic precision.

When a physical quantity object is constructed, its value is immediately converted to the standard unit of measure in the standard system of units: the metre-kilogram-second-kelvin (m·kg·s·K) system from the International System of Units (SI). This way, all physical quantities maintain their values in a consistent system of units. This approach greatly minimizes the number of unit conversions during program execution; when arithmetic operations are performed between physical quantities, no unit conversion is needed.

The only other instances where a physical quantity undergoes a unit conversion is when its value is explicitly requested in a different unit of measure or when the physical quantity itself is printed as a string expressed in a different unit of measure. These cases are illustrated in the following examples.

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

The above example creates a 1234.56789 Hz frequency and prints it both in hertz (Hz) and in kilohertz (kHz).

Unit conversions can also be performed directly on plain floating-point numbers through the `PhQ::Convert`, `PhQ::ConvertInPlace`, and `PhQ::ConvertStatically` functions, which take one or more floating-point values, an original unit, and a new unit. For example:

```C++
std::vector<double> values = {10.0, 20.0, 30.0, 40.0};
PhQ::ConvertInPlace(values, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound);
for (const double value : values) {
  std::cout << value << std::endl;
}
// 7.37562
// 14.7512
// 22.1269
// 29.5025
```

The above example converts a collection of values from joules (J) to foot-pounds (ft·lbf). The same results can also be achieved using physical quantities instead of plain floating-point values. For example:

```C++
const std::vector<PhQ::Energy<>> energies{
    {10.0, PhQ::Unit::Energy::Joule},
    {20.0, PhQ::Unit::Energy::Joule},
    {30.0, PhQ::Unit::Energy::Joule},
    {40.0, PhQ::Unit::Energy::Joule},
};
for (const PhQ::Energy& energy : energies) {
  std::cout << energy.Value(PhQ::Unit::Energy::FootPound) << std::endl;
}
// 7.37562
// 14.7512
// 22.1269
// 29.5025
```

In general, when it comes to unit conversions, it is simpler to use the `Value` or `Print` member methods of physical quantities rather than to explicitly invoke the `PhQ::Convert`, `PhQ::ConvertInPlace`, or `PhQ::ConvertStatically` functions.

[(Back to User Guide)](#user-guide)

### User Guide: Unit Systems

Internally, physical quantities store their values in the metre-kilogram-second-kelvin (m·kg·s·K) system from the International System of Units (SI). Unit conversions are performed automatically when physical quantity objects are constructed. The Physical Quantities library also defines other common systems of units of measure:

- Metre-kilogram-second-kelvin (m·kg·s·K) system
- Millimetre-gram-second-kelvin (mm·g·s·K) system
- Foot-pound-second-rankine (ft·lbf·s·°R) system
- Inch-pound-second-rankine (in·lbf·s·°R) system

Data can be expressed in the consistent units of any of these unit systems. The unit of measure of a given type that corresponds to a given system of units can be obtained with the `PhQ::ConsistentUnit` function. For example:

```C++
PhQ::UnitSystem system = PhQ::UnitSystem::FootPoundSecondRankine;
PhQ::Unit::SpecificEnergy consistent_unit = PhQ::ConsistentUnit<PhQ::Unit::SpecificEnergy>(system);
std::cout << consistent_unit << std::endl;
// ft·lbf/slug

PhQ::SpecificEnergy specific_energy{10.0, PhQ::Unit::SpecificEnergy::JoulePerKilogram};
double value = specific_energy.Value(consistent_unit);
std::cout << value << std::endl;
// 107.639
```

The above example obtains the consistent unit of mass-specific energy in the foot-pound-second-rankine (ft·lbf·s·°R) system, creates a mass-specific energy of 10 J/kg, and expresses this mass-specific energy in the consistent unit.

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

[(Back to User Guide)](#user-guide)

### User Guide: Dimensions

Seven independent base physical dimensions form the physical dimension set of any unit of measure or physical quantity. These seven independent base physical dimensions are: time (T), length (L), mass (M), electric current (I), temperature (Θ), amount of substance (N), and luminous intensity (J). Units of measure that share the same physical dimension set are of the same type and can be converted between one another.

The Physical Quantities library organizes units of measure into types, where each type roughly corresponds to a given physical dimension set. The physical dimension set of a unit of measure can be obtained with the `PhQ::RelatedDimensions` global variable. For example:

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

[(Back to User Guide)](#user-guide)

## Features

This section provides an overview of the features of the Physical Quantities library:

- [Physical Quantities](#features-physical-quantities)
- [Models](#features-models)
- [Units](#features-units)
- [Unit Systems](#features-unit-systems)

[(Back to Top)](#physical-quantities)

### Features: Physical Quantities

The Physical Quantities library features the following physical quantities:

- [PhQ::Acceleration](include/PhQ/Acceleration.hpp)
- [PhQ::Angle](include/PhQ/Angle.hpp)
- [PhQ::AngularSpeed](include/PhQ/AngularSpeed.hpp)
- [PhQ::Area](include/PhQ/Area.hpp)
- [PhQ::BulkDynamicViscosity](include/PhQ/BulkDynamicViscosity.hpp)
- [PhQ::Direction](include/PhQ/Direction.hpp)
- [PhQ::Displacement](include/PhQ/Displacement.hpp)
- [PhQ::DisplacementGradient](include/PhQ/DisplacementGradient.hpp)
- [PhQ::DynamicKinematicPressure](include/PhQ/DynamicKinematicPressure.hpp)
- [PhQ::DynamicPressure](include/PhQ/DynamicPressure.hpp)
- [PhQ::DynamicViscosity](include/PhQ/DynamicViscosity.hpp)
- [PhQ::ElectricCharge](include/PhQ/ElectricCharge.hpp)
- [PhQ::ElectricCurrent](include/PhQ/ElectricCurrent.hpp)
- [PhQ::Energy](include/PhQ/Energy.hpp)
- [PhQ::Force](include/PhQ/Force.hpp)
- [PhQ::Frequency](include/PhQ/Frequency.hpp)
- [PhQ::GasConstant](include/PhQ/GasConstant.hpp)
- [PhQ::HeatCapacityRatio](include/PhQ/HeatCapacityRatio.hpp)
- [PhQ::HeatFlux](include/PhQ/HeatFlux.hpp)
- [PhQ::IsentropicBulkModulus](include/PhQ/IsentropicBulkModulus.hpp)
- [PhQ::IsobaricHeatCapacity](include/PhQ/IsobaricHeatCapacity.hpp)
- [PhQ::IsochoricHeatCapacity](include/PhQ/IsochoricHeatCapacity.hpp)
- [PhQ::IsothermalBulkModulus](include/PhQ/IsothermalBulkModulus.hpp)
- [PhQ::KinematicViscosity](include/PhQ/KinematicViscosity.hpp)
- [PhQ::LameFirstModulus](include/PhQ/LameFirstModulus.hpp)
- [PhQ::Length](include/PhQ/Length.hpp)
- [PhQ::LinearThermalExpansionCoefficient](include/PhQ/LinearThermalExpansionCoefficient.hpp)
- [PhQ::MachNumber](include/PhQ/MachNumber.hpp)
- [PhQ::Mass](include/PhQ/Mass.hpp)
- [PhQ::MassDensity](include/PhQ/MassDensity.hpp)
- [PhQ::MassRate](include/PhQ/MassRate.hpp)
- [PhQ::Memory](include/PhQ/Memory.hpp)
- [PhQ::MemoryRate](include/PhQ/MemoryRate.hpp)
- [PhQ::PWaveModulus](include/PhQ/PWaveModulus.hpp)
- [PhQ::PlanarAcceleration](include/PhQ/PlanarAcceleration.hpp)
- [PhQ::PlanarDirection](include/PhQ/PlanarDirection.hpp)
- [PhQ::PlanarDisplacement](include/PhQ/PlanarDisplacement.hpp)
- [PhQ::PlanarForce](include/PhQ/PlanarForce.hpp)
- [PhQ::PlanarHeatFlux](include/PhQ/PlanarHeatFlux.hpp)
- [PhQ::PlanarPosition](include/PhQ/PlanarPosition.hpp)
- [PhQ::PlanarTemperatureGradient](include/PhQ/PlanarTemperatureGradient.hpp)
- [PhQ::PlanarTraction](include/PhQ/PlanarTraction.hpp)
- [PhQ::PlanarVelocity](include/PhQ/PlanarVelocity.hpp)
- [PhQ::PoissonRatio](include/PhQ/PoissonRatio.hpp)
- [PhQ::Position](include/PhQ/Position.hpp)
- [PhQ::Power](include/PhQ/Power.hpp)
- [PhQ::PrandtlNumber](include/PhQ/PrandtlNumber.hpp)
- [PhQ::ReynoldsNumber](include/PhQ/ReynoldsNumber.hpp)
- [PhQ::ScalarAcceleration](include/PhQ/ScalarAcceleration.hpp)
- [PhQ::ScalarAngularAcceleration](include/PhQ/ScalarAngularAcceleration.hpp)
- [PhQ::ScalarDisplacementGradient](include/PhQ/ScalarDisplacementGradient.hpp)
- [PhQ::ScalarForce](include/PhQ/ScalarForce.hpp)
- [PhQ::ScalarHeatFlux](include/PhQ/ScalarHeatFlux.hpp)
- [PhQ::ScalarStrain](include/PhQ/ScalarStrain.hpp)
- [PhQ::ScalarStrainRate](include/PhQ/ScalarStrainRate.hpp)
- [PhQ::ScalarStress](include/PhQ/ScalarStress.hpp)
- [PhQ::ScalarTemperatureGradient](include/PhQ/ScalarTemperatureGradient.hpp)
- [PhQ::ScalarThermalConductivity](include/PhQ/ScalarThermalConductivity.hpp)
- [PhQ::ScalarTraction](include/PhQ/ScalarTraction.hpp)
- [PhQ::ScalarVelocityGradient](include/PhQ/ScalarVelocityGradient.hpp)
- [PhQ::ShearModulus](include/PhQ/ShearModulus.hpp)
- [PhQ::SolidAngle](include/PhQ/SolidAngle.hpp)
- [PhQ::SoundSpeed](include/PhQ/SoundSpeed.hpp)
- [PhQ::SpecificEnergy](include/PhQ/SpecificEnergy.hpp)
- [PhQ::SpecificGasConstant](include/PhQ/SpecificGasConstant.hpp)
- [PhQ::SpecificIsobaricHeatCapacity](include/PhQ/SpecificIsobaricHeatCapacity.hpp)
- [PhQ::SpecificIsochoricHeatCapacity](include/PhQ/SpecificIsochoricHeatCapacity.hpp)
- [PhQ::SpecificPower](include/PhQ/SpecificPower.hpp)
- [PhQ::Speed](include/PhQ/Speed.hpp)
- [PhQ::StaticKinematicPressure](include/PhQ/StaticKinematicPressure.hpp)
- [PhQ::StaticPressure](include/PhQ/StaticPressure.hpp)
- [PhQ::Strain](include/PhQ/Strain.hpp)
- [PhQ::StrainRate](include/PhQ/StrainRate.hpp)
- [PhQ::Stress](include/PhQ/Stress.hpp)
- [PhQ::SubstanceAmount](include/PhQ/SubstanceAmount.hpp)
- [PhQ::Temperature](include/PhQ/Temperature.hpp)
- [PhQ::TemperatureDifference](include/PhQ/TemperatureDifference.hpp)
- [PhQ::TemperatureGradient](include/PhQ/TemperatureGradient.hpp)
- [PhQ::ThermalConductivity](include/PhQ/ThermalConductivity.hpp)
- [PhQ::ThermalDiffusivity](include/PhQ/ThermalDiffusivity.hpp)
- [PhQ::Time](include/PhQ/Time.hpp)
- [PhQ::TotalKinematicPressure](include/PhQ/TotalKinematicPressure.hpp)
- [PhQ::TotalPressure](include/PhQ/TotalPressure.hpp)
- [PhQ::Traction](include/PhQ/Traction.hpp)
- [PhQ::TransportEnergyConsumption](include/PhQ/TransportEnergyConsumption.hpp)
- [PhQ::VectorArea](include/PhQ/VectorArea.hpp)
- [PhQ::Velocity](include/PhQ/Velocity.hpp)
- [PhQ::VelocityGradient](include/PhQ/VelocityGradient.hpp)
- [PhQ::Volume](include/PhQ/Volume.hpp)
- [PhQ::VolumeRate](include/PhQ/VolumeRate.hpp)
- [PhQ::VolumetricThermalExpansionCoefficient](include/PhQ/VolumetricThermalExpansionCoefficient.hpp)
- [PhQ::YoungModulus](include/PhQ/YoungModulus.hpp)

[(Back to Features)](#features)

### Features: Models

The Physical Quantities library features the following physical models:

- [PhQ::ConstitutiveModel](include/PhQ/ConstitutiveModel.hpp)
  - [PhQ::ConstitutiveModel::CompressibleNewtonianFluid](include/PhQ/ConstitutiveModel/CompressibleNewtonianFluid.hpp)
  - [PhQ::ConstitutiveModel::ElasticIsotropicSolid](include/PhQ/ConstitutiveModel/ElasticIsotropicSolid.hpp)
  - [PhQ::ConstitutiveModel::IncompressibleNewtonianFluid](include/PhQ/ConstitutiveModel/IncompressibleNewtonianFluid.hpp)

[(Back to Features)](#features)

### Features: Units

The Physical Quantities library features the following units of measure:

- [PhQ::Unit::Acceleration](include/PhQ/Unit/Acceleration.hpp)
- [PhQ::Unit::Angle](include/PhQ/Unit/Angle.hpp)
- [PhQ::Unit::AngularAcceleration](include/PhQ/Unit/AngularAcceleration.hpp)
- [PhQ::Unit::AngularSpeed](include/PhQ/Unit/AngularSpeed.hpp)
- [PhQ::Unit::Area](include/PhQ/Unit/Area.hpp)
- [PhQ::Unit::Diffusivity](include/PhQ/Unit/Diffusivity.hpp)
- [PhQ::Unit::DynamicViscosity](include/PhQ/Unit/DynamicViscosity.hpp)
- [PhQ::Unit::ElectricCharge](include/PhQ/Unit/ElectricCharge.hpp)
- [PhQ::Unit::ElectricCurrent](include/PhQ/Unit/ElectricCurrent.hpp)
- [PhQ::Unit::Energy](include/PhQ/Unit/Energy.hpp)
- [PhQ::Unit::EnergyFlux](include/PhQ/Unit/EnergyFlux.hpp)
- [PhQ::Unit::Force](include/PhQ/Unit/Force.hpp)
- [PhQ::Unit::Frequency](include/PhQ/Unit/Frequency.hpp)
- [PhQ::Unit::HeatCapacity](include/PhQ/Unit/HeatCapacity.hpp)
- [PhQ::Unit::Length](include/PhQ/Unit/Length.hpp)
- [PhQ::Unit::Mass](include/PhQ/Unit/Mass.hpp)
- [PhQ::Unit::MassDensity](include/PhQ/Unit/MassDensity.hpp)
- [PhQ::Unit::MassRate](include/PhQ/Unit/MassRate.hpp)
- [PhQ::Unit::Memory](include/PhQ/Unit/Memory.hpp)
- [PhQ::Unit::MemoryRate](include/PhQ/Unit/MemoryRate.hpp)
- [PhQ::Unit::Power](include/PhQ/Unit/Power.hpp)
- [PhQ::Unit::Pressure](include/PhQ/Unit/Pressure.hpp)
- [PhQ::Unit::ReciprocalTemperature](include/PhQ/Unit/ReciprocalTemperature.hpp)
- [PhQ::Unit::SolidAngle](include/PhQ/Unit/SolidAngle.hpp)
- [PhQ::Unit::SpecificEnergy](include/PhQ/Unit/SpecificEnergy.hpp)
- [PhQ::Unit::SpecificHeatCapacity](include/PhQ/Unit/SpecificHeatCapacity.hpp)
- [PhQ::Unit::SpecificPower](include/PhQ/Unit/SpecificPower.hpp)
- [PhQ::Unit::Speed](include/PhQ/Unit/Speed.hpp)
- [PhQ::Unit::SubstanceAmount](include/PhQ/Unit/SubstanceAmount.hpp)
- [PhQ::Unit::Temperature](include/PhQ/Unit/Temperature.hpp)
- [PhQ::Unit::TemperatureDifference](include/PhQ/Unit/TemperatureDifference.hpp)
- [PhQ::Unit::TemperatureGradient](include/PhQ/Unit/TemperatureGradient.hpp)
- [PhQ::Unit::ThermalConductivity](include/PhQ/Unit/ThermalConductivity.hpp)
- [PhQ::Unit::Time](include/PhQ/Unit/Time.hpp)
- [PhQ::Unit::TransportEnergyConsumption](include/PhQ/Unit/TransportEnergyConsumption.hpp)
- [PhQ::Unit::Volume](include/PhQ/Unit/Volume.hpp)
- [PhQ::Unit::VolumeRate](include/PhQ/Unit/VolumeRate.hpp)

[(Back to Features)](#features)

### Features: Unit Systems

The Physical Quantities library features the following consistent systems of units of measure:

- The metre-kilogram-second-kelvin system: [PhQ::UnitSystem::MetreKilogramSecondKelvin](include/PhQ/UnitSystem.hpp)
- The millimetre-gram-second-kelvin system: [PhQ::UnitSystem::MillimetreGramSecondKelvin](include/PhQ/UnitSystem.hpp)
- The foot-pound-second-rankine system: [PhQ::UnitSystem::FootPoundSecondRankine](include/PhQ/UnitSystem.hpp)
- The inch-pound-second-rankine system: [PhQ::UnitSystem::InchPoundSecondRankine](include/PhQ/UnitSystem.hpp)

[(Back to Features)](#features)

## Developer Guide

This section presents information pertinent to software developers of the Physical Quantities library:

- [Documentation](#developer-guide-documentation)
- [Installation](#developer-guide-installation)
- [Testing](#developer-guide-testing)
- [Coverage](#developer-guide-coverage)

[(Back to Top)](#physical-quantities)

### Developer Guide: Documentation

The full documentation of the Physical Quantities library is hosted at <https://acodcha.github.io/phq-docs>.

Alternatively, the Physical Quantities library's documentation can be built locally on your system with the Doxygen documentation generator. Install the Doxygen documentation generator on Ubuntu with `sudo apt install doxygen` or visit <https://www.doxygen.nl/index.html> for alternate means of installation.

Clone the Physical Quantities library's repository and build its documentation with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
doxygen Doxyfile
```

This builds HTML documentation pages in the `PhQ/docs/html/` directory. Browse the documentation by opening the `PhQ/docs/html/index.html` file in a web browser.

[(Back to Developer Guide)](#developer-guide)

### Developer Guide: Installation

If using the CMake build system, the Physical Quantities library can optionally be installed on your system to conveniently use it in your CMake projects. Alternatively, see the [Configuration](#configuration) section for other methods of use.

Clone the Physical Quantities library's repository, configure it, and install it with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
mkdir build
cd build
cmake ..
sudo make install
```

This is a header-only library, so no compilation is needed. On most systems, the above code installs the Physical Quantities library's headers to `/usr/local/include/PhQ` and writes configuration files to `/usr/local/share/PhQ`. You can uninstall the library by simply deleting these directories.

[(Back to Developer Guide)](#developer-guide)

### Developer Guide: Testing

The Physical Quantities library makes extensive use of tests and is automatically tested before being updated. Testing can also be performed locally on your system with the GoogleTest library. Install the GoogleTest library on Ubuntu with `sudo apt install libgtest-dev` or visit <https://github.com/google/googletest> for alternate means of installation.

Testing instructions differ depending on your build system.

If using the CMake build system, test the Physical Quantities library on your system with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
mkdir build
cd build
cmake .. -D PHYSICAL_QUANTITIES_PHQ_TEST=ON
make --jobs=16
make test
```

If using the Bazel build system, test the Physical Quantities library on your system with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
bazel build //:all
bazel test //:all
```

[(Back to Developer Guide)](#developer-guide)

### Developer Guide: Coverage

Code coverage (also known as test coverage) measures the extent to which a library's source code is covered by its tests. The Physical Quantities library currently has 100% code coverage and aims to maintain this complete level of coverage going forward.

The Physical Quantities library's code coverage can be computed locally on your system with the GoogleTest library and the LCOV program. Install the GoogleTest library on Ubuntu with `sudo apt install libgtest-dev` or visit <https://github.com/google/googletest> for alternate means of installation. Install the LCOV program on Ubuntu with `sudo apt install lcov` or visit <https://github.com/linux-test-project/lcov> for alternate means of installation.

In addition to these requirements, code coverage computation also requires the CMake build system and either the GCC C++ compiler or the Clang C++ compiler; see the [Configuration](#configuration) section for more information.

Compute the Physical Quantities library's code coverage with:

```bash
git clone git@github.com:acodcha/phq.git PhQ
cd PhQ
mkdir build
cd build
cmake .. -D PHYSICAL_QUANTITIES_PHQ_COVERAGE=ON
make --jobs=16
./bin/all_tests && make coverage
```

This generates an HTML report in the `PhQ/coverage/` directory. Browse the report by opening the `PhQ/coverage/index.html` file in a web browser.

[(Back to Developer Guide)](#developer-guide)

## License

Copyright © 2020-2024 Alexandre Coderre-Chabot

Physical Quantities (PhQ) is a C++ library of physical quantities, physical models, and units of measure for scientific computing.

The Physical Quantities library is hosted at <https://github.com/acodcha/phq> and its documentation is hosted at <https://acodcha.github.io/phq-docs>. Physical Quantities is authored by Alexandre Coderre-Chabot (<https://github.com/acodcha>) and licensed under the MIT License; see the [license file](LICENSE) or <https://mit-license.org>.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

- The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[(Back to Top)](#physical-quantities)
