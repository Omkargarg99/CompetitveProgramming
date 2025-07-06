#include "bits/stdc++.h"
using namespace std;

#define int long long 

int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
int lcm(int a,int b)
{
    return a*b/gcd(min(a,b),max(a,b));
}
void solve(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans=1;
    for(int i=n-2;i>=0;i--)
    {
        int g=gcd(min(v[i],v[i+1]),max(v[i],v[i+1]));
        int x=v[i]/g;
        ans=lcm(ans,x);
        
        if(x!=1)
        v[i]/=ans;
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