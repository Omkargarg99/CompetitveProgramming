#include "bits/stdc++.h"
using namespace std;

#define MOD 998244353

#define int long long int
#define pb emplace_back              

long long powermod(long long base,long long x){long long ans=1;while(x){if(x&1){ans=(base*ans)%MOD;}base=(base*base)%MOD;x>>=1;}return ans;}

void solve(){
    int n;
    cin>>n;

    vector<int>v(powermod(2,n));
    for(int i=0;i<powermod(2,n);i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x=powermod(2,i);
        for(int j=0;j<powermod(2,n);j+=x)
        {
            int a=j,b=j+x/2,c=0;
            for(int k=0;k<x/2;k++)
            {
                if(v[a+k]<v[b+k])break;
                if(v[a+k]>v[b+k])
                {
                    c=1;
                    break;
                }


            }
            a=j;
            b=j+x/2;
            if(c)
            {
                for(int k=0;k<x/2;k++)
                {
                    swap(v[a+k],v[b+k]);


                }

            }
        }
    }
    for(int i=0;i<powermod(2,n);i++)cout<<v[i]<<" ";
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