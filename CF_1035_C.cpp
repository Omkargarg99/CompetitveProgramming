#include "bits/stdc++.h"
using namespace std;

#define int long long int

void solve(){
    
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    if((n&1))
    {
        cout<<l<<endl;
        return;
    }
    if(n==2)
    {
        cout<<-1<<endl;
        return;
    }
    int count=0;
    int x=l;
    while(x)
    {
        count++;
        x=x>>1;
    }
    x=1;
    while(count--)
    {
        x=x<<1;
    }
    if(x<=r)
    {
        if(k<n-1)
        {
            cout<<l<<endl;
        }
        else cout<<x<<endl;
    }
    else cout<<-1<<endl;

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