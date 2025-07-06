#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>maxi(n);
    maxi[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--)
    {
        maxi[i]=max(maxi[i+1],v[i]);

    }
    string ans;
    ans.push_back('1');
    int mini=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]<mini||v[i]>=maxi[i])ans.push_back('1');
        else ans.push_back('0');
        mini=min(mini,v[i]);

    }
    cout<<ans<<endl;

    
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