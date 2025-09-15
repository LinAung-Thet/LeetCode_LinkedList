#include <iostream>
#include <unordered_map>
using namespace std;

class Cache {
private:
    struct Node{
        int value;
        Node* next;
        Node* prev;
        Node(int v) : value(v), next(nullptr), prev(nullptr){}
    };

    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    int capacity;

    unordered_map<int, Node*> data;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNode(Node* node) {
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    Cache(int _capacity) {
        capacity = _capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (data.find(key) != data.end()) {
            Node* node = data[key];
            int result = node->value;

            // remove the existing node and add it at the beginning.
            data.erase(key);
            deleteNode(node);

            data[key] = node;
            addNode(node);

            return result;
        }
        return -1;
    }

    void put(int key, int value) {
        if (data.find(key) != data.end()) {
            Node* node = data[key];
            data.erase(key);
            deleteNode(node);
        }
        if (data.size() >= capacity) {
            data.erase(tail->prev->value);
            deleteNode(tail->prev);
        }
        addNode(new Node(value));
        data[key] = head->next;
    }
};