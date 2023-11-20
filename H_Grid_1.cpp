#include <bits/stdc++.h>
using namespace std;

long long n, m;
static long mod = 1e9 + 7;
long long caldp(vector<vector<char>> mtx, long long x, long long y, vector<vector<long long>> &dp)
{
  if (x == n - 1 && y == m - 1)
  {
    return 1;
  }
  else if (x >= n || y >= m || mtx[x][y] == '#')
  {
    return 0;
  }
  else if (dp[x][y] != -1)
  {
    return dp[x][y];
  }

  long long rg = caldp(mtx, x, y + 1, dp);
  long long dw = caldp(mtx, x + 1, y, dp);

  dp[x][y] = (rg + dw) % mod;

  return dp[x][y];
}

int main()
{
  cin >> n >> m;

  vector<vector<char>> mtx(n, vector<char>(m, 0));

  for (long long i = 0; i < n; i++)
  {
    for (long long j = 0; j < m; j++)
    {
      cin >> mtx[i][j];
    }
  }

  vector<vector<long long>> dp1(n + 1, vector<long long>(m + 1, -1));

  // cout << caldp(mtx, 0, 0, dp1);

  vector<vector<long long>> dp(n, vector<long long>(m, 0));

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      if (i == n - 1 && j == m - 1)
      {
        dp[i][j] = 1;
      }
      else
      {
        if (i + 1 < n && mtx[i + 1][j] != '#')
        {
          dp[i][j] += dp[i + 1][j] % mod;
        }
        if (j + 1 < m && mtx[i][j + 1] != '#')
        {
          dp[i][j] += dp[i][j + 1] % mod;
        }
      }
    }
  }

  cout << dp[0][0] % mod;
  return 0;
}
