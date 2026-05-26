// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q01_Vec3_Basic_Operations.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q01 && ../../questions_artifacts/coderpad_rendering/coderpad_q01

/*
CoderPad Rendering Question 1: Vec3 Basic Operations

Task:
Implement addition, subtraction, scalar multiplication, dot product, cross product,
length, and safe normalization for Vec3.

Concepts tested:
- vector math
- dot/cross product
- safe normalization with an epsilon
*/

#include "MathTypes.h"
#include <iostream>

constexpr float LOCAL_EPSILON = 1e-6f;

Vec3 Add(const Vec3& a, const Vec3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 Subtract(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 Multiply(const Vec3& v, float s) {
    return {v.x * s, v.y * s, v.z * s};
}

float Dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Cross(const Vec3& a, const Vec3& b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

float Length(const Vec3& v) {
    return std::sqrt(Dot(v, v));
}

Vec3 NormalizeSafe(const Vec3& v) {
    float len = Length(v);
    if (len < LOCAL_EPSILON) {
        return {0,0,0};
    }
    return v / len;
}

bool RunTests() {
    EXPECT_VEC3(Add({1,2,3}, {4,5,6}), Vec3{5,7,9});
    EXPECT_VEC3(Subtract({5,7,9}, {1,2,3}), Vec3{4,5,6});
    EXPECT_VEC3(Multiply({1,-2,3}, 2.5f), Vec3{2.5f,-5.0f,7.5f});
    EXPECT_NEAR(Dot({1,2,3}, {4,5,6}), 32.0f);
    EXPECT_VEC3(Cross({1,0,0}, {0,1,0}), Vec3{0,0,1});
    EXPECT_NEAR(Length({0,3,4}), 5.0f);
    EXPECT_VEC3(NormalizeSafe({0,3,4}), Vec3{0,0.6f,0.8f});
    EXPECT_VEC3(NormalizeSafe({0,0,0}), Vec3{0,0,0});
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q01 Vec3 Basic Operations\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Dot product measures alignment. Cross product creates a perpendicular vector.
Safe normalization checks an epsilon before division to avoid invalid results.
*/
