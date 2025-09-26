#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

class List {
private:
    int* arr;
    int capacity;
    int size;

public:
    List(int cap = 100) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    List() {
        delete[] arr;
    }


    int get(int i) {
        if (i < 0 || i >= size) throw out_of_range("Invalid index");
        return arr[i];
    }


    void insertHead(int val) {
        if (size == capacity) throw overflow_error("List full");
        for (int i = size; i > 0; --i)
            arr[i] = arr[i - 1];
        arr[0] = val;
        size++;
    }


    void insertTail(int val) {
        if (size == capacity) throw overflow_error("List full");
        arr[size++] = val;
    }


    void insertAt(int i, int val) {
        if (i < 0 || i > size || size == capacity) throw out_of_range("Invalid index or full");
        for (int j = size; j > i; --j)
            arr[j] = arr[j - 1];
        arr[i] = val;
        size++;
    }


    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        size--;
    }


    void deleteTail() {
        if (size == 0) return;
        size--;
    }


    void deleteAt(int i) {
        if (i < 0 || i >= size) throw out_of_range("Invalid index");
        for (int j = i; j < size - 1; ++j)
            arr[j] = arr[j + 1];
        size--;
    }


    void traverseForward() {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }


    void traverseBackward() {
        for (int i = size - 1; i >= 0; --i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

