# Use C++ Modules with CMake

I will briefly describe to use this working cmake project which is able to use C++20 modules. Kitware people are providing a more detailed blog post on the topic [here](https://www.kitware.com/import-cmake-c20-modules/).

## Step by step guide
- Use a very new CMake
   - v3.28.4 or newer
- You need a compiler which supports [p1689](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p1689r5.html)
  - MSVC since v19.34
  - Clang v17
  - GCC v14
- You need Ninja in v1.11 or newer
- Install or build from source
- If you are on windows you can also use the VS2022 Generator
- Adjust the provided [CMakePresets.json](CMakePresets.json) file with your paths for the compiler and ninja
- If you followed all the steps you should be able to run:

```
cmake --list-presets
cmake --preset=<presetName>
cd out/build/<presetName>
cmake --build . -j 4 && ctest
```

## Explanation to the CMake Files

It first try to find the exported cmake config packages idc.
If found, *add_idc_module(idc)* is used to create the C++ module idc.

In this way, it is possible to used different compiler (or different compiler settings).

### i.e.: build and install with gcc and later use it with clang++
### or build it witch C++20 and later with C++23

see:
- https://www.kitware.com/import-cmake-the-experiment-is-over/
- https://anarthal.github.io/cppblog/modules2
- https://discourse.cmake.org/t/advice-on-c-20-modules-boost/10641
- https://crascit.com/2024/04/04/cxx-modules-cmake-shared-libraries/
