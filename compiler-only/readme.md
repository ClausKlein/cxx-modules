# Compiler only example

This resembles exactly the example which was shown in the presentation.
In the following the compiler commands for clang and gcc are provided. As I don't know how to use msvc from cmd-line, I'm not providing a msvc example. Feel free to create a pull request :smiley:

Compiler Versions:
- gcc: 12
- clang: 16

## GCC
Beware of the order of the files.

```
g++ -std=c++20 -fmodules-ts -x c++ add.cppm add.cpp main.cpp
```

## Clang
```
clang++ -fmodules-ts --precompile add.cppm
clang++ -fmodules-ts -c add.pcm -o add.i.o 
clang++ -fmodules-ts -fmodule-file=add.pcm add.i.o main.cpp add.cpp
```

## Result
After compilation the following cmd should print out the sown result

```
a.out | echo $?
69
```