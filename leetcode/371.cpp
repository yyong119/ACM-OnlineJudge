class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = ((unsigned int)a & (unsigned int)b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
