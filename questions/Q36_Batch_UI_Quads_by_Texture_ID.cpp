// Build: cmake --build build --config Debug --target Q36_Batch_UI_Quads_by_Texture_ID
// Run: .\build\Debug\Q36_Batch_UI_Quads_by_Texture_ID.exe
/*
Question 36: Batch UI Quads by Texture ID

Description:
If canReorder=true, count unique texture IDs. If false, count consecutive texture groups.

Task:
Implement this function:
    int CountUIBatches(const std::vector<UIQuad>& quads, bool canReorder);

How to run this file:
    g++ -std=c++17 -I../include Q36_Batch_UI_Quads_by_Texture_ID.cpp -o q36 && ./q36

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

int CountUIBatches(const std::vector<UIQuad>& quads, bool canReorder) {
    // TODO: implement this function.

    if(quads.empty()){
        return 0;
    }
    if (canReorder){
            std::unordered_set <int> uset;
        for(auto i: quads){
        uset.insert(i.textureId);
    }
    return uset.size();
    }

    int res = 1;
    for (int i = 1; i<quads.size(); ++i){
        if(quads[i].textureId != quads[i-1].textureId){
            res ++;
        }
    }
    return res;
}

bool RunTests() {

    std::vector<UIQuad> quads = {{1},{1},{2},{2},{1},{3}};
    EXPECT_EQ_INT(CountUIBatches(quads, true), 3);
    EXPECT_EQ_INT(CountUIBatches(quads, false), 4);
    EXPECT_EQ_INT(CountUIBatches({}, true), 0);
    EXPECT_EQ_INT(CountUIBatches({{7},{7},{7}}, false), 1);

    return true;
}

RUN_TESTS()


