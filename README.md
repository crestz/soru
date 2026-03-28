# Soru

Soru is a C++20 library for lock-free and wait-free algorithms, data structures, and safe memory reclamation primitives such as EBR and hazard pointers. This repository is set up as the base library that can later support higher-level components such as storage engines.

At the moment the project contains the initial intrusive list implementation plus a GoogleTest-based unit test target wired through a `vcpkg` application manifest.

## Requirements

- CMake 3.24+
- A C++20 compiler
- Ninja
- `vcpkg`, with `VCPKG_ROOT` pointing at the local checkout

## Build

Configure the local development build:

```sh
cmake --preset dev
cmake --build --preset dev
ctest --preset dev
```

Configure, build, and run the user-local `vcpkg` alias preset:

```sh
cmake --preset vcpkg-debug
cmake --build --preset vcpkg-debug
ctest --preset vcpkg-debug
```

## CI

GitHub Actions CI is defined in `.github/workflows/ci.yml`. It checks formatting with `clang-format` and runs configure, build, and test jobs on Ubuntu and macOS using a CI-local `vcpkg` checkout.

## Layout

- `include/soru/`: public headers
- `src/`: target wiring plus source compatibility shims and implementation staging area
- `tests/`: unit tests
- `CMakePresets.json`: repo-owned hidden preset bases
- `CMakeUserPresets.json`: local development presets and machine-local `VCPKG_ROOT`
- `vcpkg.json` and `vcpkg-configuration.json`: application-manifest dependency setup

## Current Coverage

- `IntrusiveList`: lock-free intrusive LIFO stack/list operations with unit tests for empty state, LIFO ordering, head access, and iterator traversal
