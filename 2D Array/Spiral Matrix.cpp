vector<int> spiralMatrix(vector<vector<int>> &mat) {
  vector<int> ans;
  int n = mat.size();
  int m = mat[0].size();
  int left = 0, right = (m - 1);
  int top = 0, bottom = (n - 1);

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; i++) {
      ans.push_back(mat[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; i++) {
      ans.push_back(mat[i][right]);
    }
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        ans.push_back(mat[bottom][i]);
      }
      bottom--;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        ans.push_back(mat[i][left]);
      }
      left++;
    }
  }
  return ans;
}

// Input :
// 1, 3, 5, 7
// 10, 11, 16, 20
// 23, 30, 34, 60

// Output : 1 3 5 7 20 60 34 30 23 10 11 16
