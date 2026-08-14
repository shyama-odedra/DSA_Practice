class MyHashSet {
private:
    bool v[1000001];

public:
    MyHashSet() {
        for (int i = 0; i <= 1000000; i++) {
            v[i] = false;
        }
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    bool contains(int key) {
        return v[key];
    }
};