class Allocator {
    vector<int> memory; 
public:
    Allocator(int n) {
        memory.resize(n); 
    }
    
    int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < memory.size(); ++i) {
            if (memory[i] == 0) {
                if (++cnt == size) {
                    for (; size; --size) 
                        memory[i--] = mID; 
                    return ++i; 
                }
            } else cnt = 0; 
        }
        return -1; 
    }
    
    int free(int mID) {
        int ans = 0; 
        for (int i = 0; i < memory.size(); ++i) {
            if (memory[i] == mID) {
                memory[i] = 0; 
                ++ans; 
            }
        }
        return ans; 
    }
};
