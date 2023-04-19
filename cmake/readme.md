# Use C++ Modules with CMake

I will briefly describe to use this working cmake project which is able to use C++20 modules. Kitware people are providing a more detailed blog post on the topic [here](https://www.kitware.com/import-cmake-c20-modules/).

## Step by step guide
- Use a very new CMake
   - 3.26.x is doing the trick if you want to be extra fancy clone the latest nightly build/release candidate of CMake and build it. I used 3.26.3 
- You need a compiler which supports [p1689](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p1689r5.html)
  - MSVC since v19.34
  - Clang 16.0.1
  - GCC not upstream, a patched version is [here](https://github.com/mathstuf/gcc/tree/p1689r5)
     - If you're using gcc clone the linked repos, checkout the according tag and build it.
- You need in Ninja in Version 1.11 or newer
  - Install or build from source
- Adjust the provided CMakePresets file with your paths for the compiler and ninja
- If you followed all the steps you should be able to run:

```
<pathTo>/cmake --preset=<presetName> .
cd out/build/<presetName>
<pathTo>/cmake --build . -j 4 && ./idc
```

## Explanation to the CMake Files 
Modules support in CMake is experimental at the moment. So you have to do a couple of things to enable.
- Setting `CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API` enables the "experimental" feature for c++ modules
- Setting `CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP` enables dynamic dependencies mode
- The following snippet tells cmake how to scan the dynamic dependencies for gcc and clang in order to use the correct compile order. As MSVC did implement this a small while cmake, implemented this functionality already upstream
```
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  include(cmake/clang_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(cmake/gcc_modules.cmake)
endif()
```

