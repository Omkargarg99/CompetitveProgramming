#include "bits/stdc++.h"
using namespace std;

#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  

void findprime(int x,vector<int>&prime)
{
    vector<int>seive(x,1);
    for(int i=4;i<x;i+=2)seive[i]=0;
    for(int i=3;i<=sqrt(x);i+=2){if(seive[i]){for(int j=i;i*j<x;j++){seive[i*j]=0;}}}
    for(int i=2;i<x;i++){if(seive[i])prime.pb(i);}
}

void d(vector<int>&v,int x,vector<int>&vis)
{
    vis[x-1]=1;
    int prev=x;
    int a=x;
    while(a<=v.size())
    {
        if(!vis[a-1])
        {
            v[a-1]=prev;
            prev=a;
        }
        vis[a-1]=1;
        a+=x;
    }
    v[x-1]=prev;

}
void solve(vector<int>&prime){
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++)v[i]=i+1;
    vector<int>vis(n);
    vis[0]=1;

    int maxi=-1;
    for(int i=0;i<prime.size();i++)
    {
        if(prime[i]<=n)maxi=i;
        else break;
    }
    for(int i=maxi;i>=0;i--)
    {
        int p=prime[i];
        d(v,p,vis);


    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
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
    vector<int>prime;
    findprime(1e5+1,prime);
    while(tt--) solve(prime);
    return 0;
    
}