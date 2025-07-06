#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
   cin>>n;

   if(n%4==0)cout<<"BOB"<<endl;
   else cout<<"ALICE"<<endl;

    
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