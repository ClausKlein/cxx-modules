# Use C++ Modules with CMake

I will briefly describe to use this working cmake project which is able to use C++20 modules. Kitware people are providing a more detailed blog post on the topic [here](https://www.kitware.com/import-cmake-c20-modules/).

- Clone the latest nightly build/release candidate  of CMake and build it. I used 3.26 RC4. 
- You need a compiler which supports [p1689](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2022/p1689r5.html)
  - MSVC since v19.34 (not covered in this example)
  - GCC not upstream, a patched version is [here](https://github.com/mathstuf/gcc/tree/p1689r5)
  - Clang not upstream, a patched version is [here](https://github.com/mathstuf/llvm-project/tree/p1689r5)
- If you're using gcc or clang, clone the linked repos, checkout the according tag and build it.
- You need in Ninja in Version 1.11 or newer
  - Install or build from source
- Adjust the provided CMakePresets file with your paths for the compiler and ninja
- You have to use the provided CMake files, which enables the usage of C++ modules in CMake
  - It enables the "experimental" feature for c++ modules
  - It enables dynamic dependencies mode
  - It tells cmake how to scan the dynamic dependencies for gcc and clang (for MSVC it is already implemented in CMake)
- If you followed all the steps you should be able to run:

```
<pathTo>/cmake --preset=<presetName> .
cd out/build/<presetName>
<pathTo>/cmake --build . -j 4 && ./idc
```