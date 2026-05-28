# C++ Graphics Math Interview Practice

This project contains 36 standalone C++ practice questions for graphics/math interviews.

Each question is a separate `.cpp` file inside `questions/`.
You edit the TODO function, compile the file, and run its built-in tests.

## Folder structure

```text
include/MathTypes.h      Shared Vec2, Vec3, Mat4, test macros, helpers
questions/3D math/Q##_*.cpp
                         3D graphics math practice problems
questions/data_structure_builder/Q##_*.cpp
                         Data-structure construction and serialization problems
scripts/run_all.sh       Compiles and runs every question
CMakeLists.txt           Optional CMake build
```

## Run one question

From the `questions/3D math` folder:

```bash
g++ -std=c++17 -I../../include Q04_Compute_Dot_Product.cpp -o q04
./q04
```

On Windows with Visual Studio Developer Command Prompt, you can use:

```bat
cl /std:c++17 /EHsc /I..\..\include Q04_Compute_Dot_Product.cpp
Q04_Compute_Dot_Product.exe
```

## Run all questions

From the project root:

```bash
bash scripts/run_all.sh
```

At first, most tests will fail because the TODO functions are empty. That is expected.

## Suggested practice order

1. Q04 Dot product
2. Q05 Cross product
3. Q07 NormalizeSafe
4. Q12 Triangle normal
5. Q10 Angle between vectors
6. Q11 FOV check
7. Q19 Transform point
8. Q20 Transform direction
9. Q26 Ray-plane intersection
10. Q27 Ray-sphere intersection
11. Q28 Ray-AABB intersection
12. Q25 WorldToScreen
13. Q33 Frustum culling

## Interview tip

For each function, practice explaining:

1. What the math means visually
2. The formula
3. Where it is used in rendering/game/UI work
4. Edge cases, like zero-length vectors or parallel rays
