# Physical Quantities
![build and test](https://github.com/acodcha/PhysicalQuantities/workflows/build%20and%20test/badge.svg?branch=master)

C++17 library of physical quantities, units of measure, and related concepts for scientific computation.

## Dependencies
- **C++17 Compiler (Required):** Either GCC or Clang are recommended. On Ubuntu, install with `sudo apt install g++` or `sudo apt install clang`.
- **CMake (Optional):** CMake can optionally be used to build unit tests. On Ubuntu, install with `sudo apt install cmake`.
- **Doxygen (Optional):** Doxygen can optionally be used to generate HTML and/or LaTeX documentation. On Ubuntu, install with `sudo apt install doxygen graphviz texlive`.

## Installation
This is a header-only library, so no compilation is needed. Simply install the libray to `/usr/local/include/PhQ` with `sudo ./build/install.sh`.

To use the library in one of your projects, add `find_package(PhQ REQUIRED)` to your project's `CMakeLists.txt` file, and include the headers you need in your project's source or header files, such as `#include "PhQ/Position.hpp"`.

You can uninstall the library with `sudo ./build/uninstall.sh`.

You can generate unit tests using CMake with `./build/generate_tests.sh`.

## Documentation
You can generate documentation using Doxygen with `./docs/generate.sh`.

## License
This work is licensed under the GNU Lesser General Public License v3.0 (LGPL-3.0). For more details, see the [LICENSE](LICENSE) file or <https://www.gnu.org/licenses/lgpl-3.0.en.html>.

## Maintainer
- Alexandre Coderre-Chabot (<alexandre.coderre.chabot@gmail.com>)

