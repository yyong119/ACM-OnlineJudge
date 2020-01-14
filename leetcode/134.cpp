class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int *diff = new int[n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }
        if (sum < 0) return -1; //insufficient gas

        int start = 0, visited = 1;
        while (diff[start] < 0) ++start;
        int cur = start, rest = diff[start];
        
        while (visited < n) {
            if (++cur == n) cur = 0;
            rest += diff[cur];
            if (rest >= 0) ++visited; //sufficient gas
            else { //insufficient gas
                while (diff[cur] < 0) ++cur; // start from new place
                start = cur; visited = 1;
                rest = diff[start];
            }
        }
        return start;
    }
};