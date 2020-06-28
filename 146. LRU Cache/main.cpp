#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct LinkNode {
        int key, value;
        LinkNode *prv;
        LinkNode *nxt;
        LinkNode() : key(0), value(0), prv(nullptr), nxt(nullptr) {}
        LinkNode(int k, int v) : key(k), value(v), prv(nullptr), nxt(nullptr) {}
    } *head, *tail;
    unordered_map<int, LinkNode*> hash;
    int cap;
    void addToTail(LinkNode* p) {
        p->nxt = tail;
        p->prv = tail->prv;
        p->prv->nxt = p;
        tail->prv = p;
    }
    void remove(LinkNode* p) {
        p->prv->nxt = p->nxt;
        p->nxt->prv = p->prv;
    }
    void moveToTail(LinkNode* p) {
        remove(p);
        addToTail(p);
    }
    bool destoryHead() {
        auto p = head->nxt;
        if (p == tail) return false;
        head->nxt = p->nxt;
        p->nxt->prv = head;
        hash.erase(p->key);
        p->prv = p->nxt = nullptr;
        delete p;
        return true;
    }
public:

    LRUCache(int capacity): cap(capacity) {
        head = new LinkNode();
        tail = new LinkNode();
        head->nxt = tail;
        tail->prv = head;
    }
    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto p = hash[key];
        moveToTail(p);
        return p->value;
    }
    
    void put(int key, int value) {
        if (hash.count(key) != 0) {
            auto p = hash[key];
            p->value = value;
            moveToTail(p);
        } else {
            if (hash.size() == cap) {
                if (!destoryHead())
                    return;
            }
            auto p = new LinkNode(key, value);
            hash[key] = p;
            addToTail(p);
        }
    }
};

int main()
{
    LRUCache cache = LRUCache( 2 /* 缓存容量 */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4

    return 0;
}