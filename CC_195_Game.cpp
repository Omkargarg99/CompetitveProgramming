#include "bits/stdc++.h"
using namespace std;
             
#define all(x) (x).begin(),(x).end()  

void solve(){
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    int sum=0,x=-1,j=n-1,count=0;
    sort(all(v));
    for(int i=1;i<=2*n;i++)
    {
        if(j>=0&&v[j]+count>=x)
        {
            sum+=v[j--]+count;
            x++;
        }
        else 
        {
            sum+=x--;
            count++;
        }
        cout<<sum<<" ";
    }
    cout<<endl;
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