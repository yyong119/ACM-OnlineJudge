unordered_map<char, int> rule;
class Solution {
public:
    static bool cmp(char a, char b) {
        return rule[a] < rule[b];
    }
    string customSortString(string S, string T) {
        int num = S.length();
        for (int i = 0; i < num; ++i)
            rule[S[i]] = i;
        for (int i = 0; i < T.length(); ++i)
            if (rule.find(T[i]) == rule.end())
                rule[T[i]] = num++;
        sort(T.begin(), T.end(), cmp);
        return T;
    }
};
