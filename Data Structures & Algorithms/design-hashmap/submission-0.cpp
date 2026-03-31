class MyHashMap {
public:
    // Each bucket is a list of pairs: <Key, Value>
    vector<list<pair<int, int>>> buckets;
    int size = 1000;

    MyHashMap() {
        buckets.resize(size); // Create 1000 "rooms"
    }
    
    int hash(int key) {
        return key % size; // Simple hash function
    }

    void put(int key, int value) {
        int i = hash(key);
        // Step 1: Check if key already exists to update it
        for (auto &entry : buckets[i]) {
            if (entry.first == key) {
                entry.second = value; // Update value and exit
                return;
            }
        }
        // Step 2: If not found, add a new pair node
        buckets[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        for (auto &entry : buckets[i]) {
            if (entry.first == key) {
                return entry.second; // Return the value if found
            }
        }
        return -1; // Not found
    }
    
    void remove(int key) {
        int i = hash(key);
        // Look for the specific key-value pair to delete
        for (auto it = buckets[i].begin(); it != buckets[i].end(); it++) {
            if (it->first == key) {
                buckets[i].erase(it); // Remove this specific node
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */