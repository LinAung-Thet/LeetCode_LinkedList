#include <iostream>
using namespace std;

class Cache {
private:
    struct Node{
        int value;
        Node* next;
        Node* prev;
    };

public:
    int get() {
        return 0;
    }
};