#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string st;
    int c = 0;
    cin >> st;
    while (1)
    {
      size_t pos_ab = st.find("AB");
      size_t pos_ba = st.find("BA");
      if (pos_ab != string::npos )
      {
        st.replace(pos_ab, 2, "BC");
        c++;
      }
      else if (pos_ba != string::npos )
      {
        st.replace(pos_ba, 2, "CB");
        c++;
      }
      else
      {
        break;
      }
    }
    
    cout << c << st<<endl;
  }
  return 0;
}
/*
BABA
BBCA--AB

TS1=OP2
BABA
CBBA
CBCB
*/