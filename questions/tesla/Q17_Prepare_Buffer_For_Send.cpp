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

template <typename T>
void AppendValue(ByteBuffer& buffer, const T& value) {
    const size_t oldSize = buffer.size();
    buffer.resize(oldSize + sizeof(T));
    std::memcpy(buffer.data() + oldSize, &value, sizeof(T));
}

void AppendVec3(ByteBuffer& buffer, const Vec3& value) {
    AppendValue(buffer, value.x);
    AppendValue(buffer, value.y);
    AppendValue(buffer, value.z);
}

ByteBuffer PrepareSendBuffer(const Scene& scene) {
    ByteBuffer buffer;

    const uint32_t carCount = static_cast<uint32_t>(scene.cars.size());
    const uint32_t signCount = static_cast<uint32_t>(scene.signs.size());

    AppendValue(buffer, carCount);
    AppendValue(buffer, signCount);

    for (const Car& car : scene.cars) {
        AppendVec3(buffer, car.location);
        AppendVec3(buffer, car.direction);
        AppendVec3(buffer, car.size);

        const int32_t type = static_cast<int32_t>(car.type);
        AppendValue(buffer, type);
    }

    for (const Sign& sign : scene.signs) {
        AppendVec3(buffer, sign.location);
        AppendVec3(buffer, sign.normal);

        const int32_t type = static_cast<int32_t>(sign.type);
        const int32_t value = static_cast<int32_t>(sign.value);
        AppendValue(buffer, type);
        AppendValue(buffer, value);
    }

    return buffer;
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

Scene ReceiveBuffer(const ByteBuffer& buffer) {
    Scene scene;
    size_t offset = 0;

    uint32_t carCount = 0;
    uint32_t signCount = 0;
    if (!ReadValue(buffer, offset, carCount) ||
        !ReadValue(buffer, offset, signCount)) {
        return {};
    }

    scene.cars.reserve(carCount);
    for (uint32_t i = 0; i < carCount; ++i) {
        Car car;
        int32_t type = 0;
        if (!ReadVec3(buffer, offset, car.location) ||
            !ReadVec3(buffer, offset, car.direction) ||
            !ReadVec3(buffer, offset, car.size) ||
            !ReadValue(buffer, offset, type)) {
            return {};
        }
        car.type = type;
        scene.cars.push_back(car);
    }

    scene.signs.reserve(signCount);
    for (uint32_t i = 0; i < signCount; ++i) {
        Sign sign;
        int32_t type = 0;
        int32_t value = 0;
        if (!ReadVec3(buffer, offset, sign.location) ||
            !ReadVec3(buffer, offset, sign.normal) ||
            !ReadValue(buffer, offset, type) ||
            !ReadValue(buffer, offset, value)) {
            return {};
        }
        sign.type = type;
        sign.value = value;
        scene.signs.push_back(sign);
    }

    if (offset != buffer.size()) {
        return {};
    }

    return scene;
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
    Scene received = ReceiveBuffer(buffer);
    EXPECT_EQ_INT(static_cast<int>(received.cars.size()), 2);
    EXPECT_EQ_INT(static_cast<int>(received.signs.size()), 1);
    EXPECT_VEC3(received.cars[0].location, Vec3{1, 2, 3});
    EXPECT_VEC3(received.cars[0].direction, Vec3{0, 0, 1});
    EXPECT_VEC3(received.cars[0].size, Vec3{4, 5, 6});
    EXPECT_EQ_INT(received.cars[0].type, 7);
    EXPECT_VEC3(received.cars[1].location, Vec3{8, 9, 10});
    EXPECT_VEC3(received.cars[1].direction, Vec3{1, 0, 0});
    EXPECT_VEC3(received.cars[1].size, Vec3{2, 2, 2});
    EXPECT_EQ_INT(received.cars[1].type, 3);
    EXPECT_VEC3(received.signs[0].location, Vec3{11, 12, 13});
    EXPECT_VEC3(received.signs[0].normal, Vec3{0, 1, 0});
    EXPECT_EQ_INT(received.signs[0].type, 4);
    EXPECT_EQ_INT(received.signs[0].value, 55);
    return true;
}

RUN_TESTS()
