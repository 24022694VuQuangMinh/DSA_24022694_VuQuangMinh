#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
    Node(string k, int v) : key(k), value(v), next(nullptr) {}
};

class LinkedListST {
private:
    Node* head;

public:
    LinkedListST() : head(nullptr) {}

    void put(string key, int value) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->value = value; 
                return;
            }
        }
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    int get(string key) {
        for (Node* x = head; x != nullptr; x = x->next) {
            if (x->key == key)
                return x->value;
        }
        throw runtime_error("Key not found");
    }

    bool contains(string key) {
        for (Node* x = head; x != nullptr; x = x->next)
            if (x->key == key) return true;
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};
