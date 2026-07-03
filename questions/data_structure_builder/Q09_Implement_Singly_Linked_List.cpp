// Tesla Q09: Implement Singly Linked List
/*
Goal:
Build a functional singly linked list that supports front/back insertion,
removal by value, lookup, size, and conversion to a vector for testing.
*/

#include "MathTypes.h"
#include <vector>

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void PushFront(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void PushBack(int value) {
        Node* newNode = new Node(value);
        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool RemoveFirst(int value) {
        if(head == nullptr){
            return false;
        }

        if(head->value == value){
            Node* oldhead = head;
            head = head->next;
            if(head == nullptr){
                tail = nullptr;
            }
            delete oldhead;
            size--;
            return true;
        }
        Node* newNode = head;
        while(newNode->next){
            if(newNode->next->value == value){
                Node * todelete = newNode->next;
                newNode->next = todelete->next;
                if(todelete == tail){
                    tail = newNode;
                }
                delete todelete;
                size--;
                return true;
            }
            newNode = newNode->next;
        }
        return false;
    }

    bool Contains(int value) const {
        Node* current = head;
        while(current){
            if(current->value == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int Size() const {
        return size;
    }

    std::vector<int> ToVector() const {
        if(head == nullptr || tail == nullptr){
            return {};
        }

        Node* current = head;
        std::vector<int> ans;
        ans.reserve(size);
        while (current){
            ans.emplace_back(current->value);
            current = current->next;
        }

        return ans;
    }
};

bool RunTests() {
    SinglyLinkedList list;
    EXPECT_EQ_INT(list.Size(), 0);
    list.PushBack(2);
    list.PushFront(1);
    list.PushBack(3);
    EXPECT_TRUE(list.ToVector() == std::vector<int>({1,2,3}));
    EXPECT_EQ_INT(list.Size(), 3);
    EXPECT_TRUE(list.Contains(2));
    EXPECT_TRUE(list.RemoveFirst(2));
    EXPECT_FALSE(list.Contains(2));
    EXPECT_TRUE(list.ToVector() == std::vector<int>({1,3}));
    EXPECT_FALSE(list.RemoveFirst(99));
    return true;
}

RUN_TESTS()

