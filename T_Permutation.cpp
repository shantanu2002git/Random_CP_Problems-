#include <bits/stdc++.h>
using namespace std;
char g='<',l='>';
int cal(vector<int>ar, string s){
for(int i=1; i<ar.size(); i++){
  if(s[i]==g){
ar[i-1]<ar[i];
  }
}
}
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
 vector<int>arr(n);
 for(int i=1; i<=n; i++){
arr[i-1]=i;
 }
vector<vector<int>>per;
do{
per.push_back(arr);
}while(next_permutation(arr.begin(),arr.end()));

for(auto it : per){
  for( auto i : it){
    s=s+cal(i,s);
cout<<i<<" " ;
  }
  cout<<endl;
}
  return 0;
}