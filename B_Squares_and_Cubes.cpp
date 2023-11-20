#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int c = 0, i, j;
  while (t--)
  {
    int n;
    cin >> n;
    set<int> st;
    for (i = 1; i * i <= n; i++)
    {
      st.insert(i * i);
    }
    cout << endl;
    for (j = 2; j * j * j <= n; j++)
    {
      st.insert(j * j * j);
    }
    cout << st.size();
  }
  return 0;
}