class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        double x = (tomatoSlices - cheeseSlices * 2) / 2.0, y = cheeseSlices - x;
        vector<int> a = {x, y}, b = {};
        if (x >= 0 && y >= 0 && x - int(x) == 0.0) return a;
        return b;
    }
};