class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (auto &c : s)
            ++m[c];
        sort(s.begin(), s.end(), [&](char a, char b){return m[a] != m[b]? m[a] > m[b] : a > b;});
        return s;
    }
};
