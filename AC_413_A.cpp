#include "bits/stdc++.h"
using namespace std;

#define int long long int

void solve(){
    
   int n,m;
   cin>>n>>m;

   vector<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];

   for(int i=0;i<n;i++)
   {
    m-=v[i];
   }
   if(m>=0)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
 
}


int32_t main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 
    #endif
    
    int tt=1;
    //cin>>tt;

    while(tt--) solve();
    return 0;
    
}