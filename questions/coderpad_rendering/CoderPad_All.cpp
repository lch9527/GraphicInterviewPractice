// Run from project root:
//   mkdir -p questions_artifacts/coderpad_rendering && g++ -std=c++17 -Iinclude questions/coderpad_rendering/CoderPad_All.cpp -o questions_artifacts/coderpad_rendering/coderpad_all && questions_artifacts/coderpad_rendering/coderpad_all

/*
Combined CoderPad Rendering Practice

This file keeps all CoderPad rendering questions in one translation unit so you
can work through them from one editor tab and run everything with F5. Each
question is isolated in its own namespace to prevent helper names from colliding.

To reuse work from an earlier question, call it through that question namespace,
for example Q01::NormalizeSafe(v), Q01::Dot(a, b), or Q02::AngleBetweenDegrees(a, b).
*/

#include "MathTypes.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

namespace Q01 {

/*
CoderPad Rendering Question 1: Vec3 Basic Operations

Task:
Implement addition, subtraction, scalar multiplication, dot product, cross product,
length, and safe normalization for Vec3.
*/

constexpr float LOCAL_EPSILON = 1e-6f;

Vec3 Add(const Vec3& a, const Vec3& b) {
  return Vec3{a.x+b.x, a.y+b.y,a.z+b.z};
}

Vec3 Subtract(const Vec3& a, const Vec3& b) {
    return Vec3{a.x-b.x, a.y-b.y,a.z-b.z};
}

Vec3 Multiply(const Vec3& v, float s) {

    return Vec3{v.x*s, v.y*s,v.z*s};
}

float Dot(const Vec3& a, const Vec3& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 Cross(const Vec3& a, const Vec3& b) {
    Vec3 ans = { a.y*b.z - a.z*b.y,
                a.z*b.x - a.x*b.z,
                a.x*b.y - a.y*b.x
    };
    return ans;
}

float Length(const Vec3& v) {
    return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vec3 NormalizeSafe(const Vec3& v) {
    float vl = Length(v);
    Vec3 ans = {0,0,0};
    if(vl > LOCAL_EPSILON){
        ans.x = v.x/vl;
        ans.y = v.y/vl;
        ans.z = v.z/vl;
    }
    return ans;
}

bool RunTests01() {
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

} // namespace Q01

namespace Q02 {

/*
CoderPad Rendering Question 2: Angle Between Vectors

Task:
Given two vectors, return the angle between them in degrees.
*/

constexpr float LOCAL_PI = 3.1415926535f;
constexpr float LOCAL_EPSILON = 1e-6f;

float AngleBetweenDegrees(const Vec3& a, const Vec3& b) {
    Vec3 na = NormalizeHelper(a);
    Vec3 nb = NormalizeHelper(b);
    if(LengthHelper(na) < LOCAL_EPSILON || LengthHelper(nb) < LOCAL_EPSILON){
        return 0;
    }

    float dotValue = std::clamp(dot(na, nb), -1.0f, 1.0f);
    float r = acos(dotValue);

    return r * 180/LOCAL_PI;
}

bool RunTests02() {
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {1,0,0}), 0.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {0,1,0}), 90.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {-1,0,0}), 180.0f);
    EXPECT_NEAR(AngleBetweenDegrees({0,0,0}, {1,0,0}), 0.0f);
    return true;
}

} // namespace Q02

namespace Q03 {

/*
CoderPad Rendering Question 3: Field Of View Cone Test

Task:
Given an actor position, forward direction, target position, and FOV angle,
return whether the target is inside the actor's FOV cone.
*/

constexpr float LOCAL_PI = 3.1415926535f;
constexpr float LOCAL_EPSILON = 1e-6f;

bool IsTargetInFOV(const Vec3& actorPos, const Vec3& actorForward,
                   const Vec3& targetPos, float fovDegrees) {

    Vec3 ToTarget = targetPos - actorPos;

    if(LengthHelper(ToTarget) < LOCAL_EPSILON || LengthHelper(actorForward) < LOCAL_EPSILON){
        return false;
    }

    Vec3 nt = NormalizeHelper(ToTarget);
    Vec3 nf = NormalizeHelper(actorForward);

    float dotresult = dot(nt,nf);
    dotresult = std::clamp(dotresult, -1.0f, 1.0f);

    float halfFovRadians = fovDegrees/2 * LOCAL_PI/180;
    return dotresult >= cos(halfFovRadians);
}

bool RunTests03() {
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {0,0,1}, {0,0,5}, 90.0f));
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {0,0,1}, {1,0,1}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {0,0,1}, {5,0,0}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {0,0,0}, {0,0,5}, 90.0f));
    return true;
}

} // namespace Q03

namespace Q04 {

/*
CoderPad Rendering Question 4: Triangle Normal and Facing Camera

Task:
Calculate a triangle normal and check whether the triangle faces the camera.
*/

Vec3 CalculateTriangleNormal(const Vec3& a, const Vec3& b, const Vec3& c) {
    Vec3 ab = b-a;
    Vec3 ac = c-a;
    return NormalizeHelper(cross(ab,ac));
}

bool IsTriangleFacingCamera(const Vec3& a, const Vec3& b, const Vec3& c,
                            const Vec3& cameraPos) {
    Vec3 tn = CalculateTriangleNormal(a,b,c);
    Vec3 tp = NormalizeHelper(cameraPos-(a+b+c)/3);
    float dotresult = dot(tn,tp);
    return dotresult > 0;
}

bool RunTests04() {
    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {1,0,0}, {0,1,0}), Vec3{0,0,1});
    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {0,1,0}, {1,0,0}), Vec3{0,0,-1});
    EXPECT_TRUE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,5}));
    EXPECT_FALSE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,-5}));
    return true;
}

} // namespace Q04

namespace Q05 {

/*
CoderPad Rendering Question 5: TransformPoint vs TransformDirection

Task:
Implement TransformPoint and TransformDirection.
*/

Vec3 TransformPoint(const Mat4& m, const Vec3& p) {
    Vec4 ans = Mul(m,Vec4{p.x,p.y,p.z,1});
    return Vec3{ans.x,ans.y,ans.z};
}

Vec3 TransformDirection(const Mat4& m, const Vec3& dir) {
    Vec4 ans = Mul(m,Vec4{dir.x,dir.y,dir.z,0});
    return Vec3{ans.x,ans.y,ans.z};
}

Mat4 MakeTranslation(float x, float y, float z) {
    Mat4 m = Identity4();
    m.m[3][0] = x;
    m.m[3][1] = y;
    m.m[3][2] = z;
    return m;
}

bool RunTests05() {
    Mat4 translation = MakeTranslation(10.0f, 20.0f, 30.0f);
    EXPECT_VEC3(TransformPoint(translation, {1,2,3}), Vec3{11,22,33});
    EXPECT_VEC3(TransformDirection(translation, {1,2,3}), Vec3{1,2,3});

    Mat4 scale = Identity4();
    scale.m[0][0] = 2.0f;
    scale.m[1][1] = 3.0f;
    scale.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformPoint(scale, {1,2,3}), Vec3{2,6,12});
    EXPECT_VEC3(TransformDirection(scale, {1,2,3}), Vec3{2,6,12});
    return true;
}

} // namespace Q05

namespace Q06 {

/*
CoderPad Rendering Question 6: Ray-Plane Intersection

Task:
Implement ray-plane intersection and return whether the hit is in front of the ray.
*/

constexpr float LOCAL_EPSILON = 1e-6f;

bool RayPlaneIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                          const Vec3& planeNormal, const Vec3& pointOnPlane,
                          float& outT) {
/*
    dot(dt+o - p,n) = 0
    dot(dt+op,n)
    dot(dt,n) + dot(op,n)
    tdot(d,n) + dot(op,n)
    t = -dot(op,n)/dot(d,n)
*/
    Vec3 op = rayOrigin - pointOnPlane;
    float dotresult = dot(rayDir,planeNormal);

    if(fabs(dotresult) < LOCAL_EPSILON){
        return false;
    }

    outT = -dot(op,planeNormal)/dotresult;
    if(outT < 0.0f){
        return false;
    }
    return true;
}

bool RunTests06() {
    float t = -1.0f;
    EXPECT_TRUE(RayPlaneIntersection({0,0,0}, {0,1,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {1,0,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {0,-1,0}, {0,1,0}, {0,5,0}, t));
    return true;
}

} // namespace Q06

namespace Q07 {

/*
CoderPad Rendering Question 7: Ray-Sphere Intersection

Task:
Implement ray-sphere intersection and return the nearest positive t.
*/

bool RaySphereIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                           const Vec3& sphereCenter, float sphereRadius,
                           float& outT) {
    /*
    dot(o+dt -c,o+dt-c) = r^2
    dot(oc,oc) + 2dot(dt,oc) + t*tdot(d,d) - r*r = 0
    a = dot(d,d)
    b = 2dot(d,oc)
    c = dot(oc,oc) - r*r
    */
    Vec3 oc = rayOrigin - sphereCenter;
    float a = dot(rayDir, rayDir);
    if (a < 1e-6f) {
        return false;
    }
    float b = 2.0f * dot(rayDir, oc);
    float c = dot(oc, oc) - sphereRadius * sphereRadius;

    float discriminant = b*b - 4*a*c;

    if(discriminant < 0.0f){
        return false;
    }

    float sqrtDiscriminant = sqrt(discriminant);
    float t1 = (-b - sqrtDiscriminant) / (2.0f * a);
    float t2 = (-b + sqrtDiscriminant) / (2.0f * a);

    if(t1 >= 0.0f){
        outT = t1;
        return true;
    }

    if(t2 >= 0.0f){
        outT = t2;
        return true;
    }
    return false;

}

bool RunTests07() {
    float t = -1.0f;
    EXPECT_TRUE(RaySphereIntersection({0,0,0}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 4.0f);
    EXPECT_FALSE(RaySphereIntersection({0,0,0}, {0,1,0}, {0,0,5}, 1.0f, t));
    EXPECT_TRUE(RaySphereIntersection({0,0,5}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 1.0f);
    return true;
}

} // namespace Q07

namespace Q08 {

/*
CoderPad Rendering Question 8: Ray-AABB Intersection

Task:
Implement ray-AABB intersection using the slab method.
*/

constexpr float LOCAL_EPSILON = 1e-6f;

bool AABBhelper(const float& rayOrigin, const float& rayDir,
                const float& boxMin, const float& boxMax, float& Tenter, float& Texit){

    if(fabs(rayDir) < LOCAL_EPSILON){
         return rayOrigin >= boxMin && rayOrigin <= boxMax;
    }
        float t1 = (boxMin - rayOrigin)/rayDir;
        float t2 = (boxMax - rayOrigin)/rayDir;

        float Tenterx = std::min(t1,t2);
        float Texitx = std::max(t1,t2);

        Tenter = std::max(Tenterx,Tenter);
        Texit = std::min(Texitx,Texit);
        return Tenter <= Texit;
}

bool RayAABBIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                         const Vec3& boxMin, const Vec3& boxMax,
                         float& outT) {

    float Tenter = -std::numeric_limits<float>::max();
    float Texit = std::numeric_limits<float>::max();
    //const float& rayOrigin, const float& rayDir,
               // const float& boxMin, const float& boxMax, float& Tenter, float& Texit
    if (!AABBhelper(rayOrigin.x, rayDir.x, boxMin.x, boxMax.x, Tenter, Texit)) return false;
    if (!AABBhelper(rayOrigin.y, rayDir.y, boxMin.y, boxMax.y, Tenter, Texit)) return false;
    if (!AABBhelper(rayOrigin.z, rayDir.z, boxMin.z, boxMax.z, Tenter, Texit)) return false;
    if (Texit < 0.0f) {
      return false;
    }

    outT = std::max(Tenter, 0.0f);
    return true;
}

bool RunTests08() {
    float t = -1.0f;
    EXPECT_TRUE(RayAABBIntersection({0,0,0}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayAABBIntersection({0,0,0}, {0,1,0}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_TRUE(RayAABBIntersection({0,0,6}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 0.0f);
    return true;
}

} // namespace Q08

namespace Q09 {

/*
CoderPad Rendering Question 9: Sphere Frustum Culling

Task:
Given 6 frustum planes and a bounding sphere, return whether the sphere is
inside or intersecting the frustum.
*/

struct Sphere {
    Vec3 center;
    float radius = 0.0f;
};

bool SphereInFrustum(const Plane planes[6], const Sphere& sphere) {
    for(int i=0; i<6; i++){
        float distance = dot(planes[i].normal,sphere.center)+planes[i].d;
         if (distance < -sphere.radius) {
              return false;
          }

    }

    return true;
}

bool RunTests09() {
    Plane planes[6] = {
        {{ 1, 0, 0}, 1}, {{-1, 0, 0}, 1},
        {{ 0, 1, 0}, 1}, {{ 0,-1, 0}, 1},
        {{ 0, 0, 1}, 1}, {{ 0, 0,-1}, 1}
    };

    EXPECT_TRUE(SphereInFrustum(planes, {{0,0,0}, 0.5f}));
    EXPECT_TRUE(SphereInFrustum(planes, {{1.2f,0,0}, 0.3f}));
    EXPECT_TRUE(SphereInFrustum(planes, {{1.3f,0,0}, 0.3f}));
    EXPECT_FALSE(SphereInFrustum(planes, {{2.0f,0,0}, 0.3f}));
    return true;
}

} // namespace Q09

namespace Q10 {

/*
CoderPad Rendering Question 10: UI Rectangle Intersection and Clipping

Task:
Implement rectangle overlap and intersection for UI clipping/scissor logic.
*/

struct Rect {
    float xMin = 0.0f;
    float yMin = 0.0f;
    float xMax = 0.0f;
    float yMax = 0.0f;
};

bool RectsOverlap(const Rect& a, const Rect& b) {
    return a.xMin < b.xMax && a.xMax > b.xMin &&
           a.yMin < b.yMax && a.yMax > b.yMin;
}

Rect IntersectRect(const Rect& a, const Rect& b) {
    if (!RectsOverlap(a, b)) {
        return {};
    }

    return {
        std::max(a.xMin, b.xMin),
        std::max(a.yMin, b.yMin),
        std::min(a.xMax, b.xMax),
        std::min(a.yMax, b.yMax)
    };
}

bool RectNear(const Rect& a, const Rect& b) {
    return AlmostEqual(a.xMin, b.xMin) && AlmostEqual(a.yMin, b.yMin) &&
           AlmostEqual(a.xMax, b.xMax) && AlmostEqual(a.yMax, b.yMax);
}

#define EXPECT_RECT(actual, expected) do { if (!RectNear((actual), (expected))) { \
    std::cerr << "FAILED: rectangle mismatch at line " << __LINE__ << "\n"; return false; } } while(0)

bool RunTests10() {
    Rect a{0,0,10,10};
    Rect b{5,5,15,20};
    Rect c{10,10,20,20};

    Rect expectedOverlap{5,5,10,10};
    Rect expectedEmpty{0,0,0,0};

    EXPECT_TRUE(RectsOverlap(a, b));
    EXPECT_FALSE(RectsOverlap(a, c));
    EXPECT_RECT(IntersectRect(a, b), expectedOverlap);
    EXPECT_RECT(IntersectRect(a, c), expectedEmpty);
    return true;
}

} // namespace Q10

namespace Q11 {

/*
CoderPad Rendering Question 11: Count UI Batches

Task:
Given UI quads with texture IDs, count draw batches when order cannot change
and when order can change.
*/

int CountBatchesOrderCannotChange(const std::vector<UIQuad>& quads) {
    int ans = 1;
    if(quads.empty()){
        return 0;
    }
    UIQuad tmp = quads[0];
    for(int i = 1; i< quads.size(); i++){
        if(quads[i].textureId != tmp.textureId){
            ans++;
            tmp = quads[i];
        }
    }
    return ans;
}

int CountBatchesOrderCanChange(const std::vector<UIQuad>& quads) {
    int ans = 1;
    if(quads.empty()){
        return 0;
    }
    std::unordered_set<int> Uiset;
    for(auto i : quads){
        Uiset.insert(i.textureId);
    }
    return Uiset.size();

}

bool RunTests11() {
    std::vector<UIQuad> quads = {{1}, {1}, {2}, {2}, {1}, {3}};
    EXPECT_EQ_INT(CountBatchesOrderCannotChange(quads), 4);
    EXPECT_EQ_INT(CountBatchesOrderCanChange(quads), 3);
    EXPECT_EQ_INT(CountBatchesOrderCannotChange({}), 0);
    EXPECT_EQ_INT(CountBatchesOrderCanChange({}), 0);
    return true;
}

} // namespace Q11

namespace Q12 {

/*
CoderPad Rendering Question 12: Sort Render Commands

Task:
Separate opaque and transparent commands and sort them correctly.
*/

struct RenderCommand {
    int materialId = 0;
    int textureId = 0;
    bool transparent = false;
    float depth = 0.0f;
};

std::vector<RenderCommand> SortOpaqueCommands(const std::vector<RenderCommand>& commands) {
 std::vector<RenderCommand> Renders;

      for (const RenderCommand& i : commands) {
          if (!i.transparent) {
              Renders.push_back(i);
          }
      }

      std::sort(Renders.begin(), Renders.end(), [](const RenderCommand& a, const RenderCommand& b) {
          if (a.materialId != b.materialId) {
              return a.materialId < b.materialId;
          }
          return a.textureId < b.textureId;
      });

      return Renders;
}

std::vector<RenderCommand> SortTransparentCommands(const std::vector<RenderCommand>& commands) {
    std::vector<RenderCommand> renders;

    for (const RenderCommand& command : commands) {
        if (command.transparent) {
            renders.push_back(command);
        }
    }

    std::sort(renders.begin(), renders.end(), [](const RenderCommand& a, const RenderCommand& b) {
        return a.depth > b.depth;
    });

    return renders;
}

bool RunTests12() {
    std::vector<RenderCommand> commands = {
        {2, 5, false, 2.0f},
        {1, 9, false, 1.0f},
        {1, 3, false, 3.0f},
        {9, 1, true,  4.0f},
        {9, 2, true,  8.0f}
    };

    std::vector<RenderCommand> opaque = SortOpaqueCommands(commands);
    EXPECT_EQ_INT(static_cast<int>(opaque.size()), 3);
    EXPECT_EQ_INT(opaque[0].materialId, 1);
    EXPECT_EQ_INT(opaque[0].textureId, 3);
    EXPECT_EQ_INT(opaque[1].textureId, 9);
    EXPECT_EQ_INT(opaque[2].materialId, 2);

    std::vector<RenderCommand> transparent = SortTransparentCommands(commands);
    EXPECT_EQ_INT(static_cast<int>(transparent.size()), 2);
    EXPECT_NEAR(transparent[0].depth, 8.0f);
    EXPECT_NEAR(transparent[1].depth, 4.0f);
    return true;
}

} // namespace Q12

namespace Q13 {

/*
CoderPad Rendering Question 13: Texture and Render Target Memory Cost

Task:
Estimate memory cost for textures and render targets.
*/

int TextureMemoryBytes(int width, int height, int bytesPerPixel, bool hasMipmaps) {
    int baseBytes = width * height * bytesPerPixel;
    if (!hasMipmaps) {
        return baseBytes;
    }
    return baseBytes * 4 / 3;
}

int RenderTargetMemoryBytes(int width, int height, int bytesPerPixel, int sampleCount) {
    return width * height * bytesPerPixel * sampleCount;
}

bool RunTests13() {
    EXPECT_EQ_INT(TextureMemoryBytes(100, 50, 4, false), 20000);
    EXPECT_EQ_INT(TextureMemoryBytes(300, 300, 4, true), 480000);
    EXPECT_EQ_INT(RenderTargetMemoryBytes(1920, 1080, 4, 1), 8294400);
    EXPECT_EQ_INT(RenderTargetMemoryBytes(1920, 1080, 4, 4), 33177600);
    return true;
}

} // namespace Q13

namespace Q14 {

/*
CoderPad Rendering Question 14: Frame Budget and CPU/GPU Bottleneck

Task:
Implement simple frame budget and bottleneck detection helpers.
*/

constexpr float LOCAL_EPSILON_MS = 0.25f;

float FrameBudgetMs(int fps) {
    if (fps <= 0) {
        return 0.0f;
    }
    return 1000.0f / static_cast<float>(fps);
}

bool IsFrameOverBudget(float cpuFrameMs, float gpuFrameMs, float targetFps) {
    if (targetFps <= 0.0f) {
        return false;
    }
    float budgetMs = 1000.0f / targetFps;
    return std::max(cpuFrameMs, gpuFrameMs) > budgetMs;
}

const char* DetectBottleneck(float cpuFrameMs, float gpuFrameMs) {
    if (std::fabs(cpuFrameMs - gpuFrameMs) <= LOCAL_EPSILON_MS) {
        return "Balanced";
    }
    return cpuFrameMs > gpuFrameMs ? "CPU-bound" : "GPU-bound";
}

bool RunTests14() {
    EXPECT_NEAR(FrameBudgetMs(60), 16.666666f);
    EXPECT_NEAR(FrameBudgetMs(90), 11.111111f);
    EXPECT_NEAR(FrameBudgetMs(120), 8.333333f);
    EXPECT_TRUE(IsFrameOverBudget(10.0f, 17.0f, 60.0f));
    EXPECT_FALSE(IsFrameOverBudget(8.0f, 10.0f, 60.0f));
    EXPECT_TRUE(std::string(DetectBottleneck(12.0f, 8.0f)) == "CPU-bound");
    EXPECT_TRUE(std::string(DetectBottleneck(8.0f, 12.0f)) == "GPU-bound");
    EXPECT_TRUE(std::string(DetectBottleneck(10.0f, 10.1f)) == "Balanced");
    return true;
}

} // namespace Q14

int main() {
    std::cerr.rdbuf(std::cout.rdbuf());

    struct TestCase {
        const char* name;
        bool (*run)();
    };

    const TestCase tests[] = {
        {"Q01 Vec3 Basic Operations", Q01::RunTests01},
        {"Q02 Angle Between Vectors", Q02::RunTests02},
        {"Q03 Field Of View Test", Q03::RunTests03},
        {"Q04 Triangle Normal Facing Camera", Q04::RunTests04},
        {"Q05 Transform Point vs Direction", Q05::RunTests05},
        {"Q06 Ray Plane Intersection", Q06::RunTests06},
        {"Q07 Ray Sphere Intersection", Q07::RunTests07},
        {"Q08 Ray AABB Intersection", Q08::RunTests08},
        {"Q09 Sphere Frustum Culling", Q09::RunTests09},
        {"Q10 UI Rectangle Clipping", Q10::RunTests10},
        {"Q11 Count UI Batches", Q11::RunTests11},
        {"Q12 Sort Render Commands", Q12::RunTests12},
        {"Q13 Texture RenderTarget Memory Cost", Q13::RunTests13},
        {"Q14 Frame Budget CPU GPU Bottleneck", Q14::RunTests14},
    };

    int passed = 0;
    int failed = 0;

    for (const TestCase& test : tests) {
        std::cout << "==== " << test.name << " ====\n" << std::flush;
        if (test.run()) {
            std::cout << "[PASS] " << test.name << "\n" << std::flush;
            ++passed;
        } else {
            std::cout << "[FAIL] " << test.name << "\n" << std::flush;
            ++failed;
        }
        std::cout << "\n";
    }

    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    return failed == 0 ? 0 : 1;
}
