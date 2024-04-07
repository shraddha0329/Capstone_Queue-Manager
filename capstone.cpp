#include <iostream>

using namespace std;

class Random {
private:
    unsigned long long s;

public:
    Random() {
        // Initialize seed with an arbitrary value
        s = 123456789ULL;
    }

    // Generate a pseudo-random number between 0 and max
    int next(int x) {
        constexpr unsigned long long modulus = 0xFFFFFFFFFFFFFFFFULL;
        s = (6364136223846793005ULL * s + 1ULL) % modulus;
        return static_cast<int>((s >> 32) % (x + 1));
    }
};

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* rear;
public:
    Queue() {
        head = nullptr;
        rear = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        if (isEmpty()) {
            head = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
