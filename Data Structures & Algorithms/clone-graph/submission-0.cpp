#include <unordered_map>
#include <vector>

class Solution {
private:
    std::unordered_map<Node*, Node*> oldToNew;

public:
    Node* cloneGraph(Node* node) {
        // Base case: empty graph
        if (!node) return nullptr;

        // If this node is already cloned, return the cloned copy
        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }

        // 1. Create a clone for the current node
        Node* copy = new Node(node->val);
        
        // 2. Map original node to its clone
        oldToNew[node] = copy;

        // 3. Clone all neighbors recursively
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};