#include <bits/stdc++.h>
using namespace std;
struct LinkedList {
    int key, value;
    LinkedList *prev, *next;
    LinkedList(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
    LinkedList() : LinkedList(0, 0) {}
};
class LRUCache {
    int cap;
    unordered_map<int, LinkedList*> cache;
    LinkedList *head, *tail;  // dummy head and dummy tail
    void remove(LinkedList* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->prev = nullptr;
        cur->next = nullptr;
    }
    void addToTail(LinkedList* cur) {
        cur->prev = tail->prev;
        cur->next = tail;
        tail->prev->next = cur;
        tail->prev = cur;
    }
    void moveToTail(LinkedList* cur) {
        remove(cur);
        addToTail(cur);
    }
    void destroyHead() {
        LinkedList* cur = head->next;
        auto it = cache.find(cur->key);
        cache.erase(it);
        remove(cur);
        delete cur;
    }

   public:
    ~LRUCache() { delete head, tail; }
    LRUCache() = delete;
    LRUCache(int capacity) : cap(capacity) {
        if (capacity <= 0) throw std::invalid_argument("capacity should be a positive number.");
        head = new LinkedList();
        tail = new LinkedList();
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        moveToTail(it->second);
        return it->second->value;
    }
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->value = value;
            moveToTail(it->second);
        } else {
            if (cache.size() == cap) destroyHead();
            LinkedList* tmp = new LinkedList(key, value);
            cache[key] = tmp;
            addToTail(tmp);
        }
    }
};

int main() { return 0; }