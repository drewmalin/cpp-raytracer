# Hello C++

## Prerequisites

* cmake
* clang-format
* cppcheck

### Build
```
> cmake -S . -B build
```

### Compile
```
> cmake --build build
```

### Run
```
> ./build/HelloCpp
```

### Format (clang-format)
```
> cmake --build build --target clang-format
```

### Static Analysis (cppcheck)
```
> cmake --build build --target cppcheck
```

### Test
```
> cmake --build build --target test
```

### Clean
```
> cmake --build build --target clean
```
