#include "bits/stdc++.h"
using namespace std;

#define pi pair<int,int>
#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  
#define mp make_pair
#define ss second
#define ff first

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }
    int maxi=0;
    for(int i=0;i<=n;i++)
    {
        maxi=i;
        if(m.count(i)==0)break;
    }
    vector<pair<int,int>>x;
    for(auto i:m)
    {
        if(i.ff<=maxi)
        x.pb(mp(i.ss,i.ff));

    }
    sort(all(x));
    
    vector<int>ans(n+1);
    ans[0]=1;
    ans[n]=1;
    int j=0;
    for(int i=1;i<=n;i++)
    {
        int val=0;
        while(j<x.size()&&x[j].ff<=i)
        {
            j++;
            val++;
        }
        ans[i]=ans[i-1]+val;

    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=min(ans[i],n-i+1);
    }
    for(int i=0;i<=n;i++)
    {
        cout<<ans[i]<<" ";
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