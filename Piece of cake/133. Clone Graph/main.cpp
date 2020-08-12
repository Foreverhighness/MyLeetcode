#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    unordered_map<Node*, Node*> dic;
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        auto it = dic.find(node);
        if (it != dic.end()) return it->second;
        Node* copy = new Node(node->val);
        dic[node] = copy;
        for (auto&& neighbor : node->neighbors)
            copy->neighbors.push_back(cloneGraph(node));
        return copy;
    }
};

class Solution1 {
    unordered_set<Node*> seen;
    unordered_map<Node*, Node*> dic;
    void dfs(Node* cur, bool init) {
        if (seen.count(cur) == 1) return;
        seen.insert(cur);
        if (init) {
            dic[cur] = new Node(cur->val);
            for (auto&& neighbor : cur->neighbors) dfs(neighbor, init);
        } else {
            auto copyCur = dic[cur];
            for (auto&& neighbor : cur->neighbors) {
                copyCur->neighbors.push_back(dic[neighbor]);
                dfs(neighbor, init);
            }
        }
    }

   public:
    Node* cloneGraph(Node* node) {
        dfs(node, true);
        seen.clear();
        dfs(node, false);
        return dic[node];
    }
};

int main() { return 0; }