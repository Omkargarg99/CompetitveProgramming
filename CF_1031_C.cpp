#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

#define MOD 1000000007
#define MOD1 998244353

#define int long long int

#define pi pair<int,int>

#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  

#define inf 1e18
#define mp make_pair
#define ss second
#define ff first

typedef long long ll;

long long powermod(long long base,long long x){long long ans=1;while(x){if(x&1){ans=(base*ans)%MOD;}base=(base*base)%MOD;x>>=1;}return ans;}

int power(int b,int x){if(x==0)return 1;int ans=power(b,x/2);ans*=ans;if((x&1))ans*=b;return ans;}

int inv(int a,int b) {return 1<a ? b-inv(b%a,a)*b/a :1;}

void findprime(int x,vector<int>&prime)
{
    vector<int>seive(x,1);
    for(int i=4;i<x;i+=2)seive[i]=0;
    for(int i=3;i<=sqrt(x);i+=2){if(seive[i]){for(int j=i;i*j<x;j++){seive[i*j]=0;}}}
    for(int i=2;i<x;i++){if(seive[i])prime.pb(i);}
}

//dsu 
int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])return u;
        return parent[u]=findparent(parent[u],parent);
    }

bool uni(int u,int v,vector<int>&parent,vector<int>&size)
    {
        int a=findparent(u,parent),b=findparent(v,parent);
        if(a==b)return false;
        if(size[a]>=size[b])
        {
            parent[b]=a;
            size[a]+=size[b];
        }
        else 
        {
            size[b]+=size[a];
            parent[a]=b;
        }
        
        return true;
    }

//dfs
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            
            dfs(i,adj,vis);
            
        }
    }
}


void solve(){
    
   int n,m,k;
   cin>>n>>m>>k;
   vector<vector<char>>s(n,vector<char>(m));
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)cin>>s[i][j];
   }
   vector<vector<int>>pre(n+1,vector<int>(m+1));
   int ans=0;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        pre[i+1][j+1]+=pre[i+1][j];
        
        if(s[i][j]=='g'){pre[i+1][j+1]++;ans++;}
    }
   }
   vector<vector<int>>pre2(n+1,vector<int>(m+1));
   
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
        pre2[i+1][j+1]=pre2[i][j+1]+pre[i+1][j+1];
    
   }
   int mini=ans;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        if(s[i][j]=='.')
        {
            int a=0,b=0,c=0,d=0;
           a=pre2[min(i+k,n)][min(j+k,m)];
            b=pre2[min(i+k,n)][max(0ll,j-k+1)];
            c=pre2[max(i-k+1,0ll)][min(j+k,m)];
            d=pre2[max(i-k+1,0ll)][max(0ll,j-k+1)];
            
            mini=min(mini,a+d-b-c);

        }
    }
   }
   cout<<ans-mini<<endl;

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