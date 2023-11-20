#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 != 0)
    {
      cout << "NO" << endl;
    }
    else
    {
      int k = n / 2;
      string s1 = s.substr(0, k);
      string s2 = s.substr(k);
      if (s1 == s2)
      {
        cout << "YES" << endl;
      }
      else
      {
        // cout<<s1<<" "<<s2<<endl;
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}