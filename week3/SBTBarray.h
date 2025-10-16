#include <iostream>
#include <string>
using namespace std;

class ArrayST {
private:
    static const int MAX = 100;
    string keys[MAX];
    int values[MAX];
    int n = 0;

public:
    void put(string key, int value) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }
        keys[n] = key;
        values[n] = value;
        n++;
    }

    int get(string key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key)
                return values[i];
        }
        throw runtime_error("Key not found");
    }

    bool contains(string key) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key) return true;
        return false;
    }

    int size() { return n; }
};