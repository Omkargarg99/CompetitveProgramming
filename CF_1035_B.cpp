#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  

void solve(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<n;i++)cin>>v[i];
    if(n==1)
    {
        int k=(c-a)*(c-a)+(d-b)*(d-b);
        if(k==v[0]*v[0])
        {
            cout<<"Yes"<<endl;
            return;
        }
        else 
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    sort(all(v));
    int x=0,y=v[n-1];
    
    for(int i=0;i<n;i++)x+=v[i];
    for(int i=0;i<n-1;i++)y-=v[i];
    y=max(y,0ll);
    y=y*y;
    x=x*x;
    int k=(c-a)*(c-a)+(d-b)*(d-b);
        if(k>=y&&k<=x)
        {
            cout<<"Yes"<<endl;
            return;
        }
        else 
        {
            cout<<"NO"<<endl;
            return;
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