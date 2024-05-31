# Copyright © 2020-2024 Alexandre Coderre-Chabot
#
# This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
# models, and units of measure for scientific computing.
#
# Physical Quantities (PhQ) is hosted at:
#     https://github.com/acodcha/phq
#
# Physical Quantities (PhQ) is licensed under the MIT License:
#     https://mit-license.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
# OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

"""
Defines the Bazel macros used in the Physical Quantities (PhQ) library.
"""

def phq_library(name, hdrs, deps = [], **kwargs):
    """
    C++ header-only library used in the Physical Quantities (PhQ) library.

    Args:
      name: Required. Name of the library target.
      hdrs: Required. List of header files.
      deps: Optional. List of dependencies.
      **kwargs: Additional arguments passed to the native cc_library rule.
    """
    native.cc_library(
        name = name,
        hdrs = hdrs,
        deps = deps,
        copts = [
            "-ffast-math",
            "-O3",
            "-Wall",
            "-Wextra",
            "-Wno-return-type",
            "-Wpedantic",
            "-std=c++17",
        ],
        **kwargs
    )

def phq_test(name, srcs, deps = [], **kwargs):
    """
    C++ test used in the Physical Quantities (PhQ) library.

    Args:
      name: Required. Name of the library target.
      srcs: Required. List of source files.
      deps: Optional. List of dependencies.
      **kwargs: Additional arguments passed to the native cc_test rule.
    """
    native.cc_test(
        name = name,
        srcs = srcs,
        size = "small",
        deps = deps + ["@gtest//:gtest_main"],
        copts = [
            "-ffast-math",
            "-O3",
            "-Wall",
            "-Wextra",
            "-Wno-return-type",
            "-Wpedantic",
            "-std=c++17",
        ],
        **kwargs
    )
