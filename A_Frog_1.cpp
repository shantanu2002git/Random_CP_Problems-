#include <bits/stdc++.h>
using namespace std;
int call(vector<int> arr, int idx, vector<int> &dp)
{
  if (idx == 0)
  {
    return 0;
  }
  if (idx < 0)
  {
    return INT16_MAX;
  }
  if (dp[idx] != -1)
  {
    return dp[idx];
  }
  int t1 = call(arr, idx - 1, dp) + abs(arr[idx] - arr[idx - 1]);
  int t2 = call(arr, idx - 2, dp) + abs(arr[idx] - arr[idx - 2]);
  return dp[idx] = min(t1, t2);
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // vector<int> dp(n + 1, -1);
  //  cout<< call(arr,n-1,dp);

  vector<int> nwdp(n, 0);
  nwdp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int t1 = nwdp[i - 1] + abs(arr[i] - arr[i - 1]);
    int t2 = (i > 1) ? nwdp[i - 2] + abs(arr[i] - arr[i - 2]) : INT_MAX;
    nwdp[i] = min(t1, t2);
  }
  cout<< nwdp[n-1];
  return 0;
}