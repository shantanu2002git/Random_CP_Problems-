#include <bits/stdc++.h>
using namespace std;

vector<int> tree[200001];

void dfs(int curr, int prev, int count[])
{
  count[curr] = 1;
  for(auto nbr : tree[curr]) {
  	dfs(nbr, curr, count);
  	count[curr] += count[nbr];
  }

  // queue<int> q;
  // q.push(curr);

  // while (!q.empty())
  // {
  //   int node = q.front();
  //   q.pop();
  //   count[node] = 1;

  //   for (auto nbr : tree[node])
  //   {
  //     if (nbr != prev)
  //     {
  //       q.push(nbr);
  //       dfs(nbr, node, count);
  //       count[node] += count[nbr];
  //     }
  //   }
  // }
}

int main()
{
  int n;
  cin >> n;
  int emp[n - 1], x;
  for (int i = 0; i < n - 1; i++)
  {

    cin >> x;
    tree[x].push_back(i + 2);
  }
  int count[n + 1];
  dfs(1, 0, count);
  for (int i = 1; i <= n; i++)
  {
    cout << count[i] - 1 << " ";
  }
  cout << endl;
  return 0;
}