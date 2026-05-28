// Data Structure Builder Q17: Prepare Buffer For Send
/*
Goal:
You have scene data stored in C++ structs that contain vectors. Prepare a
contiguous byte buffer before passing it to:

    void send(const char* buffer, size_t size);

Do not send the raw Scene struct with reinterpret_cast. std::vector stores
its elements elsewhere, so the Scene object only contains vector bookkeeping
like pointers, size, and capacity. A robust buffer should explicitly serialize
the data layout you want to transmit.

Required binary layout for this exercise, in order:
1. uint32_t carCount
2. uint32_t signCount
3. For each car:
   - location x/y/z as float
   - direction x/y/z as float
   - size x/y/z as float
   - type as int32_t
4. For each sign:
   - location x/y/z as float
   - normal x/y/z as float
   - type as int32_t
   - value as int32_t
*/

#include "MathTypes.h"
#include <cstdint>
#include <cstring>
#include <vector>

struct Car {
    Vec3 location;
    Vec3 direction;
    Vec3 size;
    int type = 0;
};

struct Sign {
    Vec3 location;
    Vec3 normal;
    int type = 0;
    int value = 0;
};

struct Scene {
    std::vector<Car> cars;
    std::vector<Sign> signs;
};

using ByteBuffer = std::vector<char>;

void send(const char* buffer, size_t size) {
    // Placeholder for the interview prompt's external send function.
    (void)buffer;
    (void)size;
}

ByteBuffer PrepareSendBuffer(const Scene& scene) {
    // TODO: build a contiguous byte buffer using the required binary layout.
    // Hint: append counts first, then append each scalar field explicitly with
    // std::memcpy into a std::vector<char>.
    (void)scene;
    return {};
}

template <typename T>
bool ReadValue(const ByteBuffer& buffer, size_t& offset, T& outValue) {
    if (offset + sizeof(T) > buffer.size()) {
        return false;
    }
    std::memcpy(&outValue, buffer.data() + offset, sizeof(T));
    offset += sizeof(T);
    return true;
}

bool ReadVec3(const ByteBuffer& buffer, size_t& offset, Vec3& outValue) {
    return ReadValue(buffer, offset, outValue.x) &&
           ReadValue(buffer, offset, outValue.y) &&
           ReadValue(buffer, offset, outValue.z);
}

bool RunTests() {
    Scene scene;
    scene.cars.push_back({{1, 2, 3}, {0, 0, 1}, {4, 5, 6}, 7});
    scene.cars.push_back({{8, 9, 10}, {1, 0, 0}, {2, 2, 2}, 3});
    scene.signs.push_back({{11, 12, 13}, {0, 1, 0}, 4, 55});

    ByteBuffer buffer = PrepareSendBuffer(scene);

    const size_t expectedSize =
        sizeof(uint32_t) * 2 +
        scene.cars.size() * (sizeof(float) * 9 + sizeof(int32_t)) +
        scene.signs.size() * (sizeof(float) * 6 + sizeof(int32_t) * 2);
    EXPECT_EQ_INT(static_cast<int>(buffer.size()), static_cast<int>(expectedSize));

    size_t offset = 0;
    uint32_t carCount = 0;
    uint32_t signCount = 0;
    EXPECT_TRUE(ReadValue(buffer, offset, carCount));
    EXPECT_TRUE(ReadValue(buffer, offset, signCount));
    EXPECT_EQ_INT(static_cast<int>(carCount), 2);
    EXPECT_EQ_INT(static_cast<int>(signCount), 1);

    Vec3 value{};
    int32_t type = 0;
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{1, 2, 3});
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{0, 0, 1});
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{4, 5, 6});
    EXPECT_TRUE(ReadValue(buffer, offset, type));
    EXPECT_EQ_INT(type, 7);

    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{8, 9, 10});
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{1, 0, 0});
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{2, 2, 2});
    EXPECT_TRUE(ReadValue(buffer, offset, type));
    EXPECT_EQ_INT(type, 3);

    int32_t signValue = 0;
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{11, 12, 13});
    EXPECT_TRUE(ReadVec3(buffer, offset, value));
    EXPECT_VEC3(value, Vec3{0, 1, 0});
    EXPECT_TRUE(ReadValue(buffer, offset, type));
    EXPECT_TRUE(ReadValue(buffer, offset, signValue));
    EXPECT_EQ_INT(type, 4);
    EXPECT_EQ_INT(signValue, 55);
    EXPECT_EQ_INT(static_cast<int>(offset), static_cast<int>(buffer.size()));

    send(buffer.data(), buffer.size());
    return true;
}

RUN_TESTS()
