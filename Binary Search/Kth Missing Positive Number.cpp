int missingK(vector<int> arr, int n, int k) {
  for (int i = 0; i < n; i++) {
    if (arr[i] <= k) {
      ++k;
    } else {
      break;
    }
  }
  return k;
}

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
