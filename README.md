# Physical Quantities
![build and test](https://github.com/acodcha/PhysicalQuantities/workflows/build%20and%20test/badge.svg?branch=master)

C++17 library of physical quantities, units of measure, and related concepts for scientific computation.

## Dependencies
- **C++17 Compiler (Required):** Either GCC or Clang are recommended. On Ubuntu, install with `sudo apt install g++` or `sudo apt install clang`.
- **CMake (Optional):** CMake can optionally be used to build unit tests. On Ubuntu, install with `sudo apt install cmake`.
- **Doxygen (Optional):** Doxygen can optionally be used to generate HTML and/or LaTeX documentation. On Ubuntu, install with `sudo apt install doxygen graphviz texlive`.

## Installation
This is a header-only library, so no compilation is needed. Simply install the libray to `/usr/local/include/PhQ` with `sudo ./build/install.sh`.

You can uninstall the library with `sudo ./build/uninstall.sh`.

You can build unit tests using CMake with `./build/tests.sh`.

## Documentation
You can generate documentation using Doxygen with `./docs/generate.sh`.

## Usage
To use the library in one of your projects, add `find_package(PhQ REQUIRED)` to your project's `CMakeLists.txt` file, and include the headers you need in your project's source or header files, such as `#include "PhQ/Position.hpp"`.

Meaningful arithmetic operations between different physical quantities are supported via operator overloading. For example, a `PhQ::Velocity` divided by a `PhQ::Duration` returns a `PhQ::Acceleration`, while a `PhQ::Force` divided by a `PhQ::Area` returns a `PhQ::Traction`.

Similarly, other meaningful mathematical operations are supported via member methods. For example, `PhQ::Displacement` has a `magnitude()` method that returns a `PhQ::Length` and a `direction()` method that returns a `PhQ::Direction`.

Some physical models and related operations are also supported. For example, a `PhQ::ConstitutiveModel::ElasticIsotropicSolid` can be constructed from a `PhQ::YoungModulus` and a `PhQ::PoissonRatio`, and has a `stress()` method that returns a `PhQ::Stress` given a `PhQ::Strain`.

Warning: As always, some operations can result in divisions by zero. C++ compilers support floating-point divisions by zero, for example with `1.0/0.0 = inf`, `-1.0/0.0 = -inf`, and `0.0/0.0 = NaN`. This library makes no attempt to detect, report, or avoid divisions by zero. Instead, it is the implementer's responsibility to determine whether such cases warrant special consideration, for example through the use of conditional statements, try-catch blocks, or functions such as `isfinite()`.

## License
This work is licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the [LICENSE](LICENSE) file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

## Maintainer
- Alexandre Coderre-Chabot (<alexandre.coderre.chabot@gmail.com>)

