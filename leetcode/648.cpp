class Solution {
public:
    struct Node {
        bool is_word;
        Node *next[27]{nullptr};
        Node() {
            is_word = false;
        }
    }*root;
    string replaceWords(vector<string>& dict, string sentence) {
        int n = dict.size();
        root = new Node;
        for (int i = 0; i < n; ++i) {
            int len = dict[i].length();
            Node *tmp = root;
            for (int j = 0; j < len; ++j) {
                int idx = dict[i][j] - 'a';
                if (!tmp->next[idx])
                    tmp->next[idx] = new Node();
                tmp = tmp->next[idx];
            }
            tmp->is_word = true;
        }
        stringstream ans;
        Node *tmp = root;
        int i = 0, len = sentence.length();
        while (i < len) {
            if (sentence[i] == ' ') {
                tmp = root;
                ans << " ";
                ++i;
                continue;
            }
            int idx = sentence[i] - 'a';
            if (!tmp->next[idx])
                while (sentence[i] != ' ' && i < len) ans << sentence[i++];
            else {
                tmp = tmp->next[idx];
                ans << sentence[i++];
                if (tmp->is_word)
                    while (sentence[i] != ' ' && i < len) ++i;
            }
        }
        return ans.str();
    }
};