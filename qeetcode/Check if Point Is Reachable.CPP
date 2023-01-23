class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        for (; targetX % 2 == 0; targetX >>= 1); 
        for (; targetY % 2 == 0; targetY >>= 1); 
        while (targetX > 1 && targetY > 1) {
            swap(targetX, targetY); 
            targetX %= targetY; 
        }
        return targetX == 1 || targetY == 1; 
    }
};
