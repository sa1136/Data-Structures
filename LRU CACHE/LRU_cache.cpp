#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Doubly linked list node
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Helper: remove a node from the list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Helper: insert a node right after head (most recent)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            node->value = value;
            insert(node);
            cache[key] = node;
        } else {
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            insert(node);
            cache[key] = node;
        }
    }
};

int main() {
    // Test Case 1: Basic operations
    cout << "Test Case 1:" << endl;
    LRUCache* cache1 = new LRUCache(2);
    cache1->put(1, 1);
    cache1->put(2, 2);
    cout << "put(1, 1), put(2, 2)" << endl;
    int result1_1 = cache1->get(1);
    cout << "get(1) = " << result1_1 << endl;
    cache1->put(3, 3);
    cout << "put(3, 3)" << endl;
    int result1_2 = cache1->get(2);
    cout << "get(2) = " << result1_2 << " (key 2 was evicted)" << endl;
    cache1->put(4, 4);
    cout << "put(4, 4)" << endl;
    int result1_3 = cache1->get(1);
    int result1_4 = cache1->get(3);
    int result1_5 = cache1->get(4);
    cout << "get(1) = " << result1_3 << " (key 1 was evicted)" << endl;
    cout << "get(3) = " << result1_4 << endl;
    cout << "get(4) = " << result1_5 << endl;
    cout << endl;
    
    // Test Case 2: Update existing key
    cout << "Test Case 2:" << endl;
    LRUCache* cache2 = new LRUCache(2);
    cache2->put(1, 1);
    cache2->put(2, 2);
    cout << "put(1, 1), put(2, 2)" << endl;
    int result2_1 = cache2->get(1);
    cout << "get(1) = " << result2_1 << endl;
    cache2->put(2, 3);
    cout << "put(2, 3) - update existing key" << endl;
    int result2_2 = cache2->get(2);
    cout << "get(2) = " << result2_2 << " (updated value)" << endl;
    cout << endl;
    
    // Test Case 3: Capacity 1
    cout << "Test Case 3:" << endl;
    LRUCache* cache3 = new LRUCache(1);
    cache3->put(1, 1);
    cache3->put(2, 2);
    cout << "put(1, 1), put(2, 2)" << endl;
    int result3_1 = cache3->get(1);
    int result3_2 = cache3->get(2);
    cout << "get(1) = " << result3_1 << " (key 1 was evicted)" << endl;
    cout << "get(2) = " << result3_2 << endl;
    cout << endl;
    
    // Test Case 4: Get updates LRU
    cout << "Test Case 4:" << endl;
    LRUCache* cache4 = new LRUCache(2);
    cache4->put(1, 1);
    cache4->put(2, 2);
    cout << "put(1, 1), put(2, 2)" << endl;
    int result4_1 = cache4->get(1);
    cout << "get(1) = " << result4_1 << " (moves 1 to front)" << endl;
    cache4->put(3, 3);
    cout << "put(3, 3)" << endl;
    int result4_2 = cache4->get(2);
    int result4_3 = cache4->get(1);
    cout << "get(2) = " << result4_2 << " (key 2 was evicted, not 1)" << endl;
    cout << "get(1) = " << result4_3 << " (key 1 still in cache)" << endl;
    cout << endl;
    
    // Test Case 5: Sequential operations
    cout << "Test Case 5:" << endl;
    LRUCache* cache5 = new LRUCache(3);
    cache5->put(1, 1);
    cache5->put(2, 2);
    cache5->put(3, 3);
    cout << "put(1, 1), put(2, 2), put(3, 3)" << endl;
    int result5_1 = cache5->get(1);
    cout << "get(1) = " << result5_1 << endl;
    cache5->put(4, 4);
    cout << "put(4, 4)" << endl;
    int result5_2 = cache5->get(2);
    cout << "get(2) = " << result5_2 << " (key 2 was evicted, not 1)" << endl;
    cout << endl;
    
    return 0;
}

