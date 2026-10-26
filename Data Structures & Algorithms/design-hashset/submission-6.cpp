class MyHashSet {
public:
    // A vector of lists (Linked Lists) to handle collisions
    vector<list<int>> buckets;
    int size = 1000;

    MyHashSet() {
        buckets.resize(size); // Only 1000 buckets instead of 1 million!
    }
    
    // Helper to find the index (Hash Function)
    int hash(int key) {
        return key % size; 
    }

    void add(int key) {
        int i = hash(key);
        // NeetCode Logic: Only add if it's not already there
        if (!contains(key)) {
            buckets[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        // Use the built-in list remove to delete the specific value
        buckets[i].remove(key);
    }
    
    bool contains(int key) {
        int i = hash(key);
        // Scan the small linked list in that bucket
        for (int element : buckets[i]) {
            if (element == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */