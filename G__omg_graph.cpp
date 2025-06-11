#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
#define MOD1 998244353

#define int long long int

#define pi pair<int,int>

#define printo(a) cout << a << " "; cout << endl
#define printp(a) cout << a.first << " " << a.second << endl
#define printv(a,x,y) for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl


#define pb emplace_back           
#define sz(x) (int)(x).size()    
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr << "[" << _LINE_ << "] "#x" = " << (x) << endl   

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
    for(int i=3;i<=sqrt(x);i+=2)
    {
        if(seive[i])
        {
            for(int j=i;i*j<x;j++)
            {
                seive[i*j]=0;
            }
        }
    }
    for(int i=2;i<x;i++)
    {
        if(seive[i])prime.pb(i);
    }
}

//Code starts here 



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

void solve(){
    int n,m;
    cin>>n>>m;
    
    
    vector<int>parent(n);
    vector<int>size(n,1);
    for(int i=0;i<n;i++)parent[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a;
        if(a==0)continue;
        cin>>b;
        b--;
        for(int j=1;j<=a-1;j++)
        {
            int v;
            cin>>v;
            v--;
            uni(v,b,parent,size);
        }
        
        
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        ans[i]=size[findparent(i,parent)];
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
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
    //cin>>tt;

    while(tt--) solve();
    return 0;
    
}