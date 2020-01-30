class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum1 = 0, sum2 = 0, a = min(start, destination), b = max(start, destination);
        for (int i = 0; i < a; ++i)
            sum1 += distance[i];
        for (int i = b; i < distance.size(); ++i)
            sum1 += distance[i];
        for (int i = a; i < b; ++i)
            sum2 += distance[i];
        return min(sum1, sum2);
    }
};
