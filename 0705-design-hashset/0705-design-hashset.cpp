class MyHashSet {
public:
    map<int,int> m;
    MyHashSet() {
        
    }
    
    void add(int key) {
        m[key]++;
    }
    
    void remove(int key) {
        if(m[key]!=0) m.erase(key);
    }
    
    bool contains(int key) {
        if(m[key]!=0) return true;
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