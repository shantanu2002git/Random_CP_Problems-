// #include <bits/stdc++.h>
// using namespace std;

// int caldp(string s1, string s2, int idx1, int idx2, vector<vector<int>>& dp) {
//   if (idx1 < 0 || idx2 < 0) {
//     return 0;
//   }

//   if (dp[idx1][idx2] != -1) {
//     return dp[idx1][idx2];
//   }

//   if (s1[idx1] == s2[idx2]) {
//     dp[idx1][idx2] = 1 + caldp(s1, s2, idx1 - 1, idx2 - 1, dp);
//   } else {
//     dp[idx1][idx2] = max(caldp(s1, s2, idx1 - 1, idx2, dp), caldp(s1, s2, idx1, idx2 - 1, dp));
//   }

//   return dp[idx1][idx2];
// }

// int main() {
//   string s1, s2;
//   cin >> s1 >> s2;
//   int n1 = s1.size(), n2 = s2.size();
//   vector<vector<int>> dp(n1, vector<int>(n2, -1));
//   int result = caldp(s1, s2, n1 - 1, n2 - 1, dp);
//   cout << result << endl;

//   return 0;
// }


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<string>> dp(3001, vector<string>(3001, ""));

string LCS(string& s, string& t, int i, int j)
{
    if(i < 0 || j < 0)
        return "";
    if(dp[i][j] != "")
        return dp[i][j];
    if(s[i] == t[j])
        return dp[i][j] = LCS(s, t, i-1, j-1) + s[i];
    string option1 = LCS(s, t, i-1, j);
    string option2 = LCS(s, t, i, j-1);
    if(option1.size() > option2.size())
        return dp[i][j] = option1;
    return dp[i][j] = option2;
}

signed main(){
   
    string s, t; cin>>s>>t;
    int n = s.size(), m = t.size();
    
    string ans = LCS(s, t, n-1, m-1);
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}
