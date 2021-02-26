# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming languages.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure all dependencies are installed.
- C++: `clang` or `gcc`, `make` (or `MSBuild.exe` on Windows) and `cmake`.
- Java: `JDK` and `Maven`

CMake, Maven is optional, it helps you build and run project easier, but you could manual run each file separately.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone https://github.com/knguyenc/algorithms.git
$ cd algorithms
```

## Build and run C++
Using CMake:
1. Create __build__ directory inside __algorithms/cc__ folder:
```shell script
$ cd cc
$ mkdir build
$ cd build
```
2. Build project with `cmake` and `make`, remember we are currently in __build__ folder:
```shell script
$ cmake ..
$ make
```
If you are on Windows use `MSBuild.exe` instead of `make`:
```powershell
cmake ..
MSBuild.exe .\algorithms.sln
```
3. All binary files are located inside __build/bin/__ directory.

Using `clang` or `gcc` compiler:
1. Compile your desired file by compiler:
```shell script
$ clang++ -std=c++14 {path_to_source_file} -o {path_to_output_file}
```
or
```shell script
$ g++ -std=c++14 {path_to_source_file} -o {path_to_output_file}
```
2. Then run compiled binary file:
```shell script
$ ./{path_to_binary_file}
```
For example:
```shell script
$ clang++ -std=c++14 sorting/merge_sort.cc -o build/bin/merge_sort
$ ./build/bin/merge_sort
```

Add `-DCMAKE_BUILD_TYPE=Debug` or `-DCMAKE_BUILD_TYPE=Release` argument to `cmake` command for `Debug`, `Release` respectively.

## Build and run Java
Using Maven:
1. Compile project by `mvn` command, remember we are currently in project root's folder:
```shell script
$ cd java
$ mvn compile
```
2. All compiled classes locate inside _target/classes/_ directory. Use `java` to execute desired class.
```shell script
$ java {path_to_class_file}
```
3. Run unit testing by `mvn test` command:
```shell script
$ mvn test
```
or run single test:
```shell script
$ mvn -Dtest={test_class_name} test
```

Using `javac` compiler:
1. Compile your desired file by compiler:
```shell script
$ javac -d target/classes {path_to_source_file}
```
2. Then run the compiled class file:
```shell script
$ java {path_to_class_file}
```

## Algorithms explanation
TBA

## References
[C++ Documentation](https://isocpp.org/) \
[CMake Documentation](https://cmake.org/documentation/) \
[Java Documentation](https://docs.oracle.com/en/java/) \
[Maven Documentation](https://maven.apache.org/guides/index.html)
