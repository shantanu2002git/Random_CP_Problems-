#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int call(vector<int> &arr, int idx, int k, vector<int> &dp)
{
  if (idx == 0)
  {
    return 0;
  }
  if (idx < 0)
  {
    return INT_MAX;
  }

  if (dp[idx] != -1)
  {
    return dp[idx];
  }
  int mi = 1e9;
  for (int i = 1; i <= k; i++)
  {
    if (idx - i >= 0)
    {
      int ttk = call(arr, idx - i, k, dp) + abs(arr[idx] - arr[idx - i]);
      mi = min(mi, ttk);
    }
  }
  return dp[idx] = mi;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> dp(n + 1, -1);
  cout << call(arr, n - 1, k, dp);

  vector<int> nwdp(n, 1e9);
  nwdp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        nwdp[i] = min(nwdp[i], (nwdp[i - j] + abs(arr[i] - arr[i - j])));
      }
    }
  }
  // cout << nwdp[n - 1];

  return 0;
}