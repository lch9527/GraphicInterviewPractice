// Tesla Q10: Implement Doubly Linked List
/*
Goal:
Build a functional doubly linked list that supports push/pop at both ends and
can be traversed forward and backward.
*/

#include "MathTypes.h"
#include <vector>

class DoublyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prv;
        Node(int v): val(v), next(nullptr), prv(nullptr){}
    };

    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList(): head(nullptr), tail(nullptr), size(0){}

    void PushFront(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prv = newNode;
            head = newNode;
        }
        size++;
    }

    void PushBack(int value) {
        Node* newNode = new Node(value);
        if(tail == nullptr){
            tail = newNode;
            head = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prv = tail;
            tail = newNode;
        }
        size++;
    }

    bool PopFront(int& outValue) {
        if(head==nullptr){
            return false;
        }

        Node* needDelete = head;
        head = head->next;
        if(head){
            head->prv = nullptr;
        }
        else{
            tail = nullptr;
        }
        outValue = needDelete->val;
        delete needDelete;
        size--;
        return true;
    }

    bool PopBack(int& outValue) {
        if(tail == nullptr){
            return false;
        }

        Node* needDelete = tail;
        tail = tail->prv;
        if(tail){
            tail->next = nullptr;
        }
        else{
            head = nullptr;
        }
        outValue = needDelete->val;
        delete needDelete;
        size--;
        return true;
    }

    int Size() const {
        return size;
    }

    std::vector<int> ToVectorForward() const {
        Node* curr = head;
        std::vector<int> ans;
        ans.reserve(size);

        while(curr){
            ans.emplace_back(curr->val);
            curr = curr->next;
        }
        return ans;
    }

    std::vector<int> ToVectorBackward() const {
        Node* curr = tail;
        std::vector<int> ans;
        ans.reserve(size);

        while(curr){
            ans.emplace_back(curr->val);
            curr = curr->prv;
        }
        return ans;
    }
};

bool RunTests() {
    DoublyLinkedList list;
    int value = -1;
    EXPECT_FALSE(list.PopFront(value));
    list.PushBack(2);
    list.PushFront(1);
    list.PushBack(3);
    EXPECT_TRUE(list.ToVectorForward() == std::vector<int>({1,2,3}));
    EXPECT_TRUE(list.ToVectorBackward() == std::vector<int>({3,2,1}));
    EXPECT_EQ_INT(list.Size(), 3);
    EXPECT_TRUE(list.PopFront(value));
    EXPECT_EQ_INT(value, 1);
    EXPECT_TRUE(list.PopBack(value));
    EXPECT_EQ_INT(value, 3);
    EXPECT_TRUE(list.ToVectorForward() == std::vector<int>({2}));
    return true;
}

RUN_TESTS()

