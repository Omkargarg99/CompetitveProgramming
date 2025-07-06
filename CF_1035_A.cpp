#include "bits/stdc++.h"
using namespace std;
#define int long long
void solve(){
    
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a>b+1)
    {
        cout<<-1<<endl;
        return;
    }
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }
    if(a==b+1)
    {
        if((a&1))
        {
            cout<<y<<endl;
            return;
        }
        else 
        {
            cout<<-1<<endl;
            return;
        }
    }
    if(x<=y)
    {
        cout<<x*(b-a)<<endl;
        return;
    }
    if((b-a)%2==0)
    {
        cout<<(x+y)*(b-a)/2<<endl;
        return;
    }
    if(b&1)
    {
        int mid=(b-a)/2;
        cout<<x*mid+y*(mid+1)<<endl;
    }
    else
    {
        int mid=(b-a)/2;
        cout<<x*(mid+1)+y*(mid)<<endl;

    }
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