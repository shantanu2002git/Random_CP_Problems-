// #include <bits/stdc++.h>
// using namespace std;
// const int mod=10000007;
// int cal(vector<vector<char>> &arr, int i, int j, int n, vector<vector<int>> &dp)
// {
//   if (i == n - 1 && j == n - 1)
//   {
//     return 1;
//   }

//   if (i < 0 || i >= n || j < 0 || j >= n || arr[i][j] == '*')
//   {
//     return false;
//   }

//   if (dp[i][j] != -1)
//   {
//     return dp[i][j];
//   }
//   long long ttk1 = 0, ttk2 = 0;

//   ttk1 = ttk1 + cal(arr, i + 1, j, n, dp);
//   ttk2 = ttk2 + cal(arr, i, j + 1, n, dp);

//   return dp[i][j] = (ttk1 + ttk2) % mod;
// }
// int main()
// {
//   int n;
//   cin >> n;
//   vector<vector<char>> arr(n, vector<char>(n, -1));
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       cin >> arr[i][j];
//     }
//   }
//   if (arr[0][0] == '*' || arr[n - 1][n - 1] == '*')
//   {
//     cout << 0 << endl;
//     return 0;
//   }
//   vector<vector<int>> dp(n, vector<int>(n, 0));
//   // cout << cal(arr, 0, 0, n, dp);

//   for (int i = n - 1; i >= 0; i--)
//   {
//     for (int j = n - 1; j >= 0; j--)
//     {
//       if (arr[i][j] == '*')
//       {
//         dp[i][j] = 0;
//       }
//       else if (i == n - 1 && j == n - 1)
//       {
//         dp[n - 1][n - 1] = 1;
//       }
//       else
//       {
//         if (i + 1 < n)
//         {
//           dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
//         }
//         if (j + 1 < n)
//         {
//           dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
//         }
//       }
//     }
//   }
//   cout << dp[0][0];
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int mod = 10000007;

int main()
{
  int n;
  cin >> n;

  vector<vector<char>> arr(n, vector<char>(n, '.'));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }

  if (arr[0][0] == '*' || arr[n - 1][n - 1] == '*')
  {
    cout << 0 << endl;
    return 0;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (arr[i][j] == '*')
      {
        dp[i][j] = 0;
      }
      else if (i == n - 1 && j == n - 1)
      {
        dp[n - 1][n - 1] = 1;
      }
      else
      {
        if (i + 1 < n)
        {
          dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
        }
        if (j + 1 < n)
        {
          dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
        }
      }
    }
  }

  cout << dp[0][0] << endl;

  return 0;
}
