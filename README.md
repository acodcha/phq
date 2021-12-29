[![build and test](https://github.com/acodcha/physical-quantities/actions/workflows/build_and_test.yml/badge.svg?branch=main)](https://github.com/acodcha/physical-quantities/actions/workflows/build_and_test.yml)

C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.

- [Setup](#setup)
    - [Installation](#setup-installation)
    - [Testing](#setup-testing)
    - [Documentation](#setup-documentation)
- [Usage](#usage)
    - [Configuration](#usage-configuration)
    - [Physical Quantities](#usage-physical-quantities)
    - [Units of Measure](#usage-units-of-measure)
    - [Physical Models](#usage-physical-models)
- [License](#license)

# Setup

- [Installation](#setup-installation)
- [Testing](#setup-testing)
- [Documentation](#setup-documentation)

[(Back to Top)](#)

## Setup: Installation

The following packages are required:

- **C++17 Compiler:** Any C++17 compiler will do, such as GCC or Clang. On Ubuntu, install GCC with `sudo apt install g++` or Clang with `sudo apt install clang`.
- **CMake:** On Ubuntu, install with `sudo apt install cmake`.

Configure the library with:

```
mkdir build
cd build
cmake ..
```

This is a header-only library, so no compilation is needed.

Install the library from the `build` directory with:

```
sudo make install
```

On most systems, this installs the library headers to `/usr/local/include/PhQ` and writes configuration files to `/usr/local/share/PhQ`. You can uninstall the library by simply deleting these directories.

[(Back to Setup)](#setup)

## Setup: Testing

Testing is optional and disabled by default but can be done from the `build` directory with:

```
cmake .. -DBUILD_TESTING=ON
make -j
make test
```

This builds and runs the unit tests.

[(Back to Setup)](#setup)

## Setup: Documentation

Building the documentation requires additional packages:

- **Doxygen:** On Ubuntu, install with `sudo apt install doxygen`.
- **Graphviz:** On Ubuntu, install with `sudo apt install graphviz`.
- **TeX Live:** On Ubuntu, install with `sudo apt install texlive texlive-fonts-extra`.

Documentation is optional and disabled by default but can be generated from the `build` directory with:

```
cmake .. -DBUILD_DOCS=ON
make docs
```

This generates HTML documentation using Doxygen. The documentation is located in `docs/html`. Open the `docs/html/index.html` file in any web browser to view the documentation.

[(Back to Setup)](#setup)

# Usage

- [Configuration](#usage-configuration)
- [Physical Quantities](#usage-physical-quantities)
- [Units of Measure](#usage-units-of-measure)
- [Physical Models](#usage-physical-models)

[(Back to Top)](#)

## Usage: Configuration

To use the library in one of your projects, first install it to your system as described in the Setup section.

In your project's `CMakeLists.txt` file, set your project's C++ standard to C++17 or higher:

```
set(CMAKE_CXX_STANDARD 17)
```

Some environments automatically detect used libraries; in such cases, no further action is needed. Otherwise, explicitly add the library as a dependency in your project's `CMakeLists.txt` file:

```
target_link_libraries(${EXECUTABLE_NAME} [other-options] PhQ)
```

Once this is done, simply include the headers you need in your project's source files, such as `#include <PhQ/Position.hpp>`. The `PhQ::` namespace encapsulates the library's contents.

[(Back to Usage)](#usage)

## Usage: Physical Quantities

Physical quantities are constructed from a value and a unit. Values can be scalars, vectors, or dyadics. For example, `PhQ::Temperature{15.0, PhQ::Unit::Temperature::Celsius}` creates a temperature quantity of 15 °C, while `PhQ::Force{ {100.0, 200.0, 300.0}, PhQ::Unit::Force::Pound}` creates a force quantity of (100, 200, 300) lbf. Vector and dyadic quantities are represented internally in a Cartesian (x-y-z) coordinate system.

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. For example, a `PhQ::Velocity` divided by a `PhQ::Duration` returns a `PhQ::Acceleration`, while a `PhQ::Force` divided by a `PhQ::Area` returns a `PhQ::Traction`.

Similarly, other meaningful mathematical operations are supported via member methods. For example, `PhQ::Displacement` has a `magnitude()` method that returns a `PhQ::Length` and a `direction()` method that returns a `PhQ::Direction`.

Warning: As always, some operations can result in divisions by zero. C++ compilers support floating-point divisions by zero, for example with `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. This library makes no attempt to detect, report, or avoid divisions by zero. Instead, it is the implementer's responsibility to determine whether such cases warrant special consideration, for example through the use of conditional statements, try-catch blocks, or standard C++ utilities such as `isfinite()`.

[(Back to Usage)](#usage)

## Usage: Units of Measure

Unit conversions are handled automatically. Internally, physical quantities maintain their values in a consistent unit system: the metre-kilogram-second-kelvin system. A physical quantity's value can be obtained in any unit through its `value()` method, which takes as argument either a unit or a unit system. For example, `PhQ::Mass{10.0, PhQ::Unit::Mass::Pound}.value(PhQ::Unit::Mass::Kilogram);` creates a 10 lbm mass and prints its value as 4.535924 kg.

Unit conversions can also be done without the use of physical quantities through the `PhQ::convert()` method, which takes a value, an old unit, and a new unit. For example, `PhQ::convert(10.0, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound)` converts 10 J to 7.375621 ft·lbf.

[(Back to Usage)](#usage)

## Usage: Physical Models

Some physical models and related operations are also supported. For example, a `PhQ::ConstitutiveModel::ElasticIsotropicSolid` can be constructed from a `PhQ::YoungModulus` and a `PhQ::PoissonRatio`, and has a `stress()` method that returns a `PhQ::Stress` given a `PhQ::Strain`.

[(Back to Usage)](#usage)

# License

This work is maintained by Alexandre Coderre-Chabot (<https://github.com/acodcha>) and licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the `LICENSE` file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

[(Back to Top)](#)
