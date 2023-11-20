#include <bits/stdc++.h>
using namespace std;

long long caldp(vector<vector<int>> &mtx, int idx, int w, vector<vector<long long>> &dp)
{
  if (idx == 0)
  {
    return (w >= mtx[idx][0]) ? mtx[idx][1] : 0;
  }
  else if (idx < 0)
  {
    return 0;
  }

  if (dp[idx][w] != -1)
  {
    return dp[idx][w];
  }

  long long ttk = 0, ntt = 0;
  if (w - mtx[idx][0] >= 0)
  {
    ttk = mtx[idx][1] + caldp(mtx, idx - 1, w - mtx[idx][0], dp);
  }
  ntt = caldp(mtx, idx - 1, w, dp);

  dp[idx][w] = max(ttk, ntt);
  return dp[idx][w];
}

int main()
{
  int n, w;
  cin >> n >> w;

  vector<vector<int>> mtx(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> mtx[i][0] >> mtx[i][1];
  }

  vector<vector<long long>> dp(105, vector<long long>(100005, -1));
  // cout << caldp(mtx, n - 1, w, dp);
  vector<vector<long long>> dp2(105, vector<long long>(100005, 0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      
    }
  }

  return 0;
}
