#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n,j,k;
   cin>>n>>j>>k;

   vector<int>v(n);
   for(int i=0;i<n;i++)cin>>v[i];

   if(k>1)
   {
    cout<<"YES"<<endl;
    return;
   }
   int maxi=0;
   for(int i=0;i<n;i++)maxi=max(maxi,v[i]);
   if(maxi==v[j-1])cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

    
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
    cin>>tt;

    while(tt--) solve();
    return 0;
    
}