#include "bits/stdc++.h"
using namespace std;

void solve(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int a=v[0];
    for(int i=1;i<n;i++)
    {
        if(a>v[i])
        {
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<a<<" "<<v[i]<<endl;
            return;
        }
        a=max(a,v[i]);
    }
    cout<<"NO"<<endl;
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