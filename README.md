# C++ Binary Fixed-Point Arithmetic

[![Build Status](https://travis-ci.org/johnmcfarlane/fixed_point.svg?branch=master)](https://travis-ci.org/johnmcfarlane/fixed_point)
[![Build status](https://ci.appveyor.com/api/projects/status/p60lpkq9u90h83fi/branch/master?svg=true)](https://ci.appveyor.com/project/johnmcfarlane/fixed-point/branch/master)

## Introduction

The [fixed_point](https://github.com/johnmcfarlane/fixed_point)
library is designed to represent binary fixed-point real numbers using integer types. It is developed as part of
[SG14](https://groups.google.com/a/isocpp.org/forum/#!forum/sg14) and SG6.
For an overview of the API, see proposal,
[LEWG, EWG, SG14, SG6: P0037](http://johnmcfarlane.github.io/fixed_point/doc/papers/p0037.html).

## Repository

The library is [hosted](https://github.com/johnmcfarlane/fixed_point) on GitHub:

    git clone https://github.com/johnmcfarlane/fixed_point.git

## Usage

1. Add the [*include*](include) directory to your list of system headers. 

1. Essential definitions are in [*fixed_point.h*](include/fixed_point.h):
   ```
   #include <fixed_point.h>
   ```

1. Supplemental definitions are in [*fixed_point_utils.h*](include/fixed_point_utils.h):
   ```
   #include <fixed_point_utils.h>
   ```

1. All definitions are in the `sg14` namespace:
   ```
   using namespace sg14;
   ```
   
1. Use the `fixed_point` type to define variables.
   ```
   fixed_point<std::int32_t, -28> pi(3.1415926535);
   std::cout << "pi=" << std::setprecision(10) << pi;
   ```
   
   Output:
   
   >pi=3.141592652

1. Alternatively, use `make_fixed` and `make_ufixed` to instantiate signed and unsigned variables 
   with exactly the number of integer and fractional digits you require:
   ```
   make_fixed<3, 28> pi(3.1415926535);
   ```

1. See proposal, [P0037](http://johnmcfarlane.github.io/fixed_point/doc/papers/p0037.html),
   for mode details.

## Tests and Benchmarks

### Linux / UNIX

Tested on [Travis](https://travis-ci.org/johnmcfarlane/fixed_point) (Ubuntu 12.04) using GCC 4.8 and Clang 3.5
and [Debian GNU/Linux 8.2](https://www.debian.org/releases/stable/) using GCC 4.9.2 and Clang 3.5.0. 

To build from the project directory:

    cmake -DCMAKE_BUILD_TYPE=Release
    make

To disable exception handling, add `-DEXCEPTIONS=OFF` to the `cmake` command:

    cmake -DCMAKE_BUILD_TYPE=Release -DEXCEPTIONS=OFF
    make

To run tests:

    ./fp_tests

To run benchmarks:

    ./fp_benchmarks

To profile benchmarks:

1. in *src/benchmark/CMakeLists.txt*, append `-fno-omit-frame-pointer` to `COMPILE_FLAGS`:
   ```
   PROPERTIES COMPILE_FLAGS "${COMMON_CXX_FLAGS} -fno-omit-frame-pointer"
   ```

2. then run:
   ```
   perf stat ./run_benchmarks
   perf report -g 'graph,0.5,caller'`
   ```

### Windows

Tested on [AppVeyor](https://ci.appveyor.com/project/johnmcfarlane/fixed-point/branch/master)
and on *Windows 7 Professional* with *CMake 3.4.0*. Requires:

- MSBuild 14.0
- CMake 2.8.4

To build *vs/Release/fp_test.exe* and *vs/Release/fp_benchmark.exe*:

    cmake .
    MSBuild.exe /m fixed_point.sln /p:Configuration=Release

For 64-bit builds, append `Win64` to the `-G` option above:

    cmake -G "Visual Studio 14 2015 Win64" .

### Cleaning

To clean the project files:

    git clean -Xdff .

(Use with caution!)
