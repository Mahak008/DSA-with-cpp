
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int left[n], right[n];
    const int MOD = 1e9 + 7;

    stack<pair<int, int>> s1, s2;

    // getting number of element strictly larger
    // than A[i] on Left.
    for (int i = 0; i < n; ++i) {
        int cnt = 1;

        // get elements from stack until element
        // greater than A[i] found
        while (!s1.empty() && (s1.top().first) > arr[i]) {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({arr[i], cnt});
        left[i] = cnt;
    }

    // getting number of element larger than A[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;

        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= arr[i]) {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({arr[i], cnt});
        right[i] = cnt;
    }

    int result = 0;

    // calculating required resultult
    for (int i = 0; i < n; ++i)
        result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;

    return result;
}

// In how many subarrays an element is mnimum towards left and right
// Input: 3, 1, 2, 4
// Left: 1, 2, 1, 1 
// Right: 1, 3, 2, 1
// Output: 17

// Input: 11, 81, 94, 43, 3
// Left: 1, 1, 1, 3, 5
// Right: 1, 1, 1, 2, 4
// Output: 444
 
