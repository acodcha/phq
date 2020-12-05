# Physical Quantities (PhQ)
![build and test](https://github.com/acodcha/PhysicalQuantities/workflows/build%20and%20test/badge.svg?branch=main)

C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.

## Dependencies
The following packages are required:
- **C++17 Compiler:** Any C++17 compiler will do, such as GCC or Clang. On Ubuntu, install GCC with `sudo apt install g++` or Clang with `sudo apt install clang`.
- **CMake:** On Ubuntu, install with `sudo apt install cmake`.

## Configuration
Configure the library with:

```
mkdir build
cd build
cmake ..
```

This is a header-only library, so no compilation is needed.

## Installation
Once you have configured the library, install it from the `build` directory with:

```
sudo make install
```

On most systems, this installs the library headers to `/usr/local/include/PhQ` and writes the CMake `find_package()` command configuration files to `/usr/local/share/PhQ`. You can uninstall the library by simply deleting these directories.

## Documentation
Building the documentation is optional and requires additional packages:
- **Doxygen:** On Ubuntu, install with `sudo apt install doxygen`.
- **Graphviz:** On Ubuntu, install with `sudo apt install graphviz`.
- **TeX Live:** On Ubuntu, install with `sudo apt install texlive texlive-fonts-extra`.

Documentation is disabled by default but can be generated from the `build` directory with:

```
cmake .. -DBUILD_DOCS=ON
make docs
```

This generates HTML documentation using Doxygen. The documentation is located in `docs/html`. Open the `docs/html/index.html` file in any web browser to view the documentation.

## Testing
Testing is disabled by default but can be run from the `build` directory with:

```
cmake .. -DBUILD_TESTING=ON
make -j
make test
```

This builds and runs the tests.

## Usage
To use the library in one of your projects, install it to your system (see the Installation section) and add the following to your project's `CMakeLists.txt` file:

```
find_package(PhQ REQUIRED)
target_link_libraries(${PROJECT_NAME} PhQ::PhQ)
```

Once this is done, simply include the headers you need in your project's source or header files, such as `#include "PhQ/Position.hpp"`. The `PhQ::` namespace encapsulates the library's contents.

### Usage: Physical Quantities
Physical quantities are constructed from a value and a unit. Values can be scalars, vectors, or dyadics. For example, `PhQ::Temperature{15.0, PhQ::Unit::Temperature::Celsius}` creates a temperature quantity of 15 °C, while `PhQ::Force{ {100.0, 200.0, 300.0}, PhQ::Unit::Force::Pound}` creates a force quantity of (100, 200, 300) lbf. Vector and dyadic quantities are represented internally in a Cartesian (x-y-z) coordinate system.

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. For example, a `PhQ::Velocity` divided by a `PhQ::Duration` returns a `PhQ::Acceleration`, while a `PhQ::Force` divided by a `PhQ::Area` returns a `PhQ::Traction`.

Similarly, other meaningful mathematical operations are supported via member methods. For example, `PhQ::Displacement` has a `magnitude()` method that returns a `PhQ::Length` and a `direction()` method that returns a `PhQ::Direction`.

Warning: As always, some operations can result in divisions by zero. C++ compilers support floating-point divisions by zero, for example with `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. This library makes no attempt to detect, report, or avoid divisions by zero. Instead, it is the implementer's responsibility to determine whether such cases warrant special consideration, for example through the use of conditional statements, try-catch blocks, or standard C++ utilities such as `isfinite()`.

### Usage: Units of Measure
Unit conversions are handled automatically by physical quantities. Internally, physical quantities maintain their values in a consistent unit system: the metre-kilogram-second-kelvin system. A physical quantity's value can be obtained in any unit through its `value()` method, which takes as argument either a unit or a unit system. For example, `PhQ::Mass{10.0, PhQ::Unit::Mass::Pound}.value(PhQ::Unit::Mass::Kilogram);` creates a 10 lbm mass and returns its value as 4.535924 kg.

Unit conversions can also be done without the use of physical quantities through the `PhQ::convert()` method, which takes a value, an old unit, and a new unit. For example, `PhQ::convert(10.0, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound)` converts 10 J to 7.375621 ft·lbf.

### Usage: Physical Models
Some physical models and related operations are also supported. For example, a `PhQ::ConstitutiveModel::ElasticIsotropicSolid` can be constructed from a `PhQ::YoungModulus` and a `PhQ::PoissonRatio`, and has a `stress()` method that returns a `PhQ::Stress` given a `PhQ::Strain`.

## License
This work is licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the [LICENSE](LICENSE) file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

## Maintainer
- Alexandre Coderre-Chabot (<https://github.com/acodcha>)

