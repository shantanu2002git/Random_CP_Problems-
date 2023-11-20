#include <bits/stdc++.h>
using namespace std;

int caldp(vector<vector<int>>& mtx, int s, int x, int y, vector<vector<int>>& dp) {
  if (x == 0) {
    return mtx[x][y];
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  int ix0 = 0, ix1 = 0, ix2 = 0;
  if (y == 0) {
    ix1 = caldp(mtx, mtx[x - 1][1], x - 1, 1, dp);
    ix2 = caldp(mtx, mtx[x - 1][2], x - 1, 2, dp);
  } else if (y == 1) {
    ix0 = caldp(mtx, mtx[x - 1][0], x - 1, 0, dp);
    ix2 = caldp(mtx, mtx[x - 1][2], x - 1, 2, dp);
  } else if (y == 2) {
    ix0 = caldp(mtx, mtx[x - 1][0], x - 1, 0, dp);
    ix1 = caldp(mtx, mtx[x - 1][1], x - 1, 1, dp);
  }
  
  dp[x][y] = s + max(ix0, max(ix1, ix2));
  return dp[x][y];
}

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> mtx(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> mtx[i][j];
    }
  }
  
  vector<vector<int>> dp(n, vector<int>(3, -1));
  
  int id0 = caldp(mtx, mtx[n-1][0], n-1, 0, dp);
  int id1 = caldp(mtx, mtx[n-1][1], n-1, 1, dp);
  int id2 = caldp(mtx, mtx[n-1][2], n-1, 2, dp);
  
  int maxPoints ;
  // maxPoints= max(id0, max(id1, id2));
  
   // Base cases -TABULATION :::
  vector<vector<int>> dp2(n, vector<int>(3,0));
  dp2[n-1][0] = mtx[n-1][0];
  dp2[n-1][1] = mtx[n-1][1];
  dp2[n-1][2] = mtx[n-1][2];
  
  // Dynamic programming
  for (int i = n-2; i >= 0; i--) {
    dp2[i][0] = mtx[i][0] + max(dp2[i+1][1], dp2[i+1][2]);
    dp2[i][1] = mtx[i][1] + max(dp2[i+1][0], dp2[i+1][2]);
    dp2[i][2] = mtx[i][2] + max(dp2[i+1][0], dp2[i+1][1]);
  }
  
  maxPoints = max(dp2[0][0], max(dp2[0][1], dp2[0][2]));
  
  cout << maxPoints << endl;
  
  return 0;
}
