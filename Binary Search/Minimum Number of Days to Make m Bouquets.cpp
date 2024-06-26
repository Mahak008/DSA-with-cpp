// Brute Force Approach
bool possible(vector<int> &v, int day, int m, int k) {
  int cnt = 0, bq = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= day) {
      cnt++;
      if (cnt == k) { // Check if enough flowers are available for a bouquet
        bq++;
        cnt = 0;
      }
    } else {
      cnt = 0;
    }
  }
  return bq >= m;
}
int mini(vector<int> v) {
  int m = INT_MAX;
  for (auto i : v) {
    if (m > i) {
      m = i;
    }
  }
  return m;
}
int maxi(vector<int> v) {
  int m = INT_MIN;
  for (auto i : v) {
    if (m < i) {
      m = i;
    }
  }
  return m;
}
int minDays(vector<int> &bloomDay, int m, int k) {
  int low = mini(bloomDay), high = maxi(bloomDay);
  for (int i = low; i <= high; i++) {
    if (possible(bloomDay, i, m, k)) {
      return i;
    }
  }
  return -1;
}

// Optimized Approach
int minDays(vector<int> &bloomDay, int m, int k) {
  int low = mini(bloomDay), high = maxi(bloomDay), ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (possible(bloomDay, mid, m, k)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
