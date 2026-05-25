#pragma once

#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

constexpr float EPSILON = 1e-5f;
constexpr float PI_F = 3.1415926535f;

struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;
};

struct Vec3 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Vec3 operator+(const Vec3& rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }
    Vec3 operator-(const Vec3& rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }
    Vec3 operator*(float s) const { return {x * s, y * s, z * s}; }
    Vec3 operator/(float s) const { return {x / s, y / s, z / s}; }
};

inline Vec3 operator*(float s, const Vec3& v) { return v * s; }

struct Vec4 {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;
};

struct Mat4 {
    // OpenGL-style column-major storage with column-vector math:
    // m[column][row], result = M * vec4(x, y, z, w).
    float m[4][4] = {};
};

struct Plane {
    Vec3 normal;
    float d = 0.0f;
};

struct CameraBasis {
    Vec3 forward;
    Vec3 right;
    Vec3 up;
};

struct UIQuad {
    int textureId = 0;
};

inline bool AlmostEqual(float a, float b, float eps = EPSILON) {
    return std::fabs(a - b) <= eps;
}

inline bool AlmostEqual(const Vec2& a, const Vec2& b, float eps = EPSILON) {
    return AlmostEqual(a.x, b.x, eps) && AlmostEqual(a.y, b.y, eps);
}

inline bool AlmostEqual(const Vec3& a, const Vec3& b, float eps = EPSILON) {
    return AlmostEqual(a.x, b.x, eps) && AlmostEqual(a.y, b.y, eps) && AlmostEqual(a.z, b.z, eps);
}

inline bool AlmostEqual(const Mat4& a, const Mat4& b, float eps = EPSILON) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (!AlmostEqual(a.m[r][c], b.m[r][c], eps)) return false;
        }
    }
    return true;
}

inline void PrintVec3(const Vec3& v) {
    std::cout << "{" << v.x << ", " << v.y << ", " << v.z << "}";
}

inline void PrintVec2(const Vec2& v) {
    std::cout << "{" << v.x << ", " << v.y << "}";
}

inline Mat4 Identity4() {
    Mat4 result{};
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;
    return result;
}

inline float DotHelper(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename V>
inline float Dot(const V& a, const V& b) {
    return DotHelper(a, b);
}

template <typename V>
inline float dot(const V& a, const V& b) {
    return DotHelper(a, b);
}

inline float LengthHelper(const Vec3& v) {
    return std::sqrt(DotHelper(v, v));
}

inline float DistanceHelper(const Vec3& a, const Vec3& b) {
    return LengthHelper(a - b);
}

inline float LengthBetween(const Vec3& a, const Vec3& b) {
    return DistanceHelper(a, b);
}

template <typename V>
inline float Distance(const V& a, const V& b) {
    return DistanceHelper(a, b);
}

inline Vec3 NormalizeHelper(const Vec3& v) {
    float len = LengthHelper(v);
    if (len < EPSILON) return {0, 0, 0};
    return v / len;
}

inline Vec3 CrossHelper(const Vec3& a, const Vec3& b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

template <typename V>
inline Vec3 Cross(const V& a, const V& b) {
    return CrossHelper(a, b);
}

template <typename V>
inline Vec3 cross(const V& a, const V& b) {
    return CrossHelper(a, b);
}

inline float DegreesToRadiansHelper(float degrees) {
    return degrees * PI_F / 180.0f;
}

inline Vec4 Mul(const Mat4& m, const Vec4& v) {
    return {
        m.m[0][0] * v.x + m.m[1][0] * v.y + m.m[2][0] * v.z + m.m[3][0] * v.w,
        m.m[0][1] * v.x + m.m[1][1] * v.y + m.m[2][1] * v.z + m.m[3][1] * v.w,
        m.m[0][2] * v.x + m.m[1][2] * v.y + m.m[2][2] * v.z + m.m[3][2] * v.w,
        m.m[0][3] * v.x + m.m[1][3] * v.y + m.m[2][3] * v.z + m.m[3][3] * v.w
    };
}

inline Mat4 Mul(const Mat4& a, const Mat4& b) {
    Mat4 result{};
    for (int c = 0; c < 4; ++c) {
        for (int r = 0; r < 4; ++r) {
            for (int k = 0; k < 4; ++k) {
                result.m[c][r] += a.m[k][r] * b.m[c][k];
            }
        }
    }
    return result;
}

#define EXPECT_TRUE(expr) do { if (!(expr)) { std::cerr << "FAILED: " #expr << " at line " << __LINE__ << "\n"; return false; } } while(0)
#define EXPECT_FALSE(expr) EXPECT_TRUE(!(expr))
#define EXPECT_NEAR(a,b) do { if (!AlmostEqual((a),(b))) { std::cerr << "FAILED: " #a " ~= " #b << " at line " << __LINE__ << ". Got " << (a) << ", expected " << (b) << "\n"; return false; } } while(0)
#define EXPECT_VEC3(actual, ...) do { \
    Vec3 _actual = (actual); \
    Vec3 _expected = __VA_ARGS__; \
    if (!AlmostEqual(_actual, _expected)) { \
        std::cerr << "FAILED: " #actual " ~= expected at line " << __LINE__ << ". Got "; \
        PrintVec3(_actual); \
        std::cerr << ", expected "; \
        PrintVec3(_expected); \
        std::cerr << "\n"; \
        return false; \
    } \
} while(0)
#define EXPECT_VEC2(actual, ...) do { \
    Vec2 _actual = (actual); \
    Vec2 _expected = __VA_ARGS__; \
    if (!AlmostEqual(_actual, _expected)) { \
        std::cerr << "FAILED: " #actual " ~= expected at line " << __LINE__ << ". Got "; \
        PrintVec2(_actual); \
        std::cerr << ", expected "; \
        PrintVec2(_expected); \
        std::cerr << "\n"; \
        return false; \
    } \
} while(0)
#define EXPECT_EQ_INT(a,b) do { if ((a) != (b)) { std::cerr << "FAILED: " #a " == " #b << " at line " << __LINE__ << ". Got " << (a) << ", expected " << (b) << "\n"; return false; } } while(0)

#define RUN_TESTS() int main() { if (RunTests()) { std::cout << "All tests passed!\n"; return 0; } return 1; }
