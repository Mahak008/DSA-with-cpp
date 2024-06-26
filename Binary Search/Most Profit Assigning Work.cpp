int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                        vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({difficulty[i], profit[i]});
    }
    sort(v.begin(), v.end());

    // Preprocessing to find the maximum profit till index i at constant time
    for (int i = 1; i < v.size(); i++) {
        v[i].second = max(v[i].second, v[i - 1].second);
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {

        // Apply Binary Search
        int l = 0, r = v.size() - 1;
        int maxProfit = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid].first <= worker[i]) {
                maxProfit = max(maxProfit, v[mid].second);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        sum += maxProfit;
    }

    return sum;
}

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
