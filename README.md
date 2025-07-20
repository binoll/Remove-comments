# Remove comments 

## Overview
A program to remove all comments from the source code. It is intended for use with source texts: C/C++/Java.
The "tests" directory contains examples of source files before and after using this program.

**ATTENTION**: It is important that the source code is syntactically correct!

## Dependencies

```bash
sudo apt install cmake gcc -y
```

## Build
From the root of the repository, run following commands:

```bash
mkdir build && cd build
```

```bash
cmake ..
```

```bash
cmake --build .
```

## Run

```bash
./remove
```
