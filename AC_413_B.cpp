#include "bits/stdc++.h"
using namespace std;

#define pb emplace_back              

void solve(){
    int n;
    cin>>n;

    vector<string>s;
    for(int i=0;i<n;i++)
    {
        string g;
        cin>>g;
        s.pb(g);
    }
    set<string>v;
    for(int i=0;i<n;i++)
    {
        
        for(int j=i+1;j<n;j++)
        {
            v.insert(s[i]+s[j]);
            v.insert(s[j]+s[i]);
        }
    }
    cout<<v.size()<<endl;


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