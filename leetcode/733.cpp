class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        if (target >= letters[r] || target < letters[l])
            return letters[l];
        while (l < r) {
            int mid = (l + r) >> 1;
            if (letters[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return letters[r];
    }
};
