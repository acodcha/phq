# Physical Quantities
![build and test](https://github.com/acodcha/PhysicalQuantities/workflows/build%20and%20test/badge.svg?branch=master)

C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.

## Dependencies
- **C++17 Compiler (Required):** Either GCC or Clang are recommended. On Ubuntu, install with `sudo apt install g++` or `sudo apt install clang`.
- **CMake (Required):** On Ubuntu, install with `sudo apt install cmake`.
- **Doxygen (Optional):** Doxygen can optionally be used to generate documentation. On Ubuntu, install with `sudo apt install doxygen graphviz texlive`.

## Configuration
Configure the library with CMake:

```
mkdir build
cd build
cmake ..
```

## Installation
This is a header-only library, so no compilation is needed. Once you have configured the library, it can be installed from the `build` folder with:

```
sudo make install
```

On most systems, this installs the library headers to `/usr/local/include/PhQ` and writes the CMake `find_package()` command configuration files to `/usr/local/share/PhQ`. You can uninstall the library by simply deleting these folders.

## Documentation
Documentation is disabled by default but can be enabled from the `build` folder with:

```
cmake .. -DBUILD_DOCS=ON
make docs
```

This generates HTML documentation using Doxygen. The documentation is located in `docs/html`.

## Testing
Testing is disabled by default but can be enabled from the `build` folder with:

```
cmake .. -DBUILD_TESTING=ON
make -j
make test
```

This configures the library with testing enabled, builds the tests, and runs the tests.

## Usage
To use the library in one of your projects, install it on your system (see Installation), and add the following to your project's `CMakeLists.txt` file:

```
find_package(PhQ REQUIRED)
target_link_libraries(${PROJECT_NAME} PhQ::PhQ)
```

Once this is done, simply include the headers you need in your project's source or header files, such as `#include "PhQ/Position.hpp"`.

Quantities are constructed from a value and a unit. Values can be scalars, vectors, or dyadics. For example, `PhQ::Temperature{15.0, PhQ::Unit::Temperature::Celsius}` creates a temperature quantity of 15 °C, while `PhQ::Force{ {100.0, 200.0, 300.0}, PhQ::Unit::Force::Pound}` creates a force quantity of (100, 200, 300) lbf. Vector and dyadic quantities are represented in a Cartesian (x-y-z) coordinate system.

Unit conversions are done through the `PhQ::convert()` method, which takes a value, an old unit, and a new unit. For example, `PhQ::convert(10.0, PhQ::Unit::Energy::Joule, PhQ::Unit::Energy::FootPound)` converts 10 J to 7.375621 ft·lbf.

Unit conversions are handled automatically by quantities. Internally, quantities maintain their values in a consistent unit system: the metre-kilogram-second-kelvin system. A quantity's value can be obtained in any unit through its `value()` method, which takes as argument either a unit or a unit system. For example, `PhQ::Mass{10.0, PhQ::Unit::Mass::Pound}.value(PhQ::Unit::Mass::Kilogram);` creates a 10 lbm mass and returns its value as 4.535924 kg.

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. For example, a `PhQ::Velocity` divided by a `PhQ::Duration` returns a `PhQ::Acceleration`, while a `PhQ::Force` divided by a `PhQ::Area` returns a `PhQ::Traction`.

Similarly, other meaningful mathematical operations are supported via member methods. For example, `PhQ::Displacement` has a `magnitude()` method that returns a `PhQ::Length` and a `direction()` method that returns a `PhQ::Direction`.

Some physical models and related operations are also supported. For example, a `PhQ::ConstitutiveModel::ElasticIsotropicSolid` can be constructed from a `PhQ::YoungModulus` and a `PhQ::PoissonRatio`, and has a `stress()` method that returns a `PhQ::Stress` given a `PhQ::Strain`.

Warning: As always, some operations can result in divisions by zero. C++ compilers support floating-point divisions by zero, for example with `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. This library makes no attempt to detect, report, or avoid divisions by zero. Instead, it is the implementer's responsibility to determine whether such cases warrant special consideration, for example through the use of conditional statements, try-catch blocks, or functions such as `isfinite()`.

## License
This work is licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the [LICENSE](LICENSE) file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

## Maintainer
- Alexandre Coderre-Chabot (<alexandre.coderre.chabot@gmail.com>)

