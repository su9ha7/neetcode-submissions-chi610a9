class LFUCache {
private:
    struct Node {
        int key;
        int val;
        int freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct List {
        Node* head;
        Node* tail;
        
        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }

        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        bool isEmpty() {
            return head->next == tail;
        }
    };

    int cap;
    int minFreq;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, List*> freqToList;

    void updateFreq(Node* node) {
        int f = node->freq;
        freqToList[f]->removeNode(node);
        
        // If the lowest frequency list is now empty, bump minFreq
        if (freqToList[f]->isEmpty() && f == minFreq) {
            minFreq++;
        }
        
        // Promote node to next frequency level
        node->freq++;
        int newFreq = node->freq;
        
        if (freqToList.find(newFreq) == freqToList.end()) {
            freqToList[newFreq] = new List();
        }
        freqToList[newFreq]->addNode(node);
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        Node* node = keyToNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

        if (keyToNode.find(key) != keyToNode.end()) {
            // Update existing key
            Node* node = keyToNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            // Evict if cache is full
            if (keyToNode.size() == cap) {
                List* minList = freqToList[minFreq];
                Node* lruNode = minList->tail->prev; // LRU item in lowest frequency list
                keyToNode.erase(lruNode->key);
                minList->removeNode(lruNode);
                delete lruNode;
            }
            
            // Insert brand-new key
            Node* newNode = new Node(key, value);
            minFreq = 1; // Reset minFreq to 1 for new insertion
            keyToNode[key] = newNode;
            
            if (freqToList.find(1) == freqToList.end()) {
                freqToList[1] = new List();
            }
            freqToList[1]->addNode(newNode);
        }
    }
};