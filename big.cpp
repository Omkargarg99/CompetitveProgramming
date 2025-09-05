#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

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

int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
bool check(string &a,string &b)
{
    bool ans=false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>b[i])return true;
        else if(a[i]<b[i])break;
    }
    return ans;
}
string add(string &a,string &b)
{
    int i=a.size()-1ll,j=b.size()-1ll,carry=0ll;
    string ans("");
    while(i>=0||j>=0||carry)
    {
        int sum=carry,x=0,y=0;
        if(i>=0)x=a[i--]-'0';
        if(j>=0)y=b[j--]-'0';
        sum+=x+y;
        carry=sum/10;
        sum%=10;
        ans.push_back('0'+sum);

    }
    if(ans.size()==0)return "0";
    while(ans.size()>0&&ans[ans.size()-1]=='0')ans.pop_back();
    for(int i=0;i<ans.size()/2;i++)
    {
        swap(ans[i],ans[ans.size()-1-i]);
    }
    return ans;
}
int conv(string &a)
{
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        ans=ans*10+(a[i]-'0');

    }
    return ans;
}
string solve(string &a,string &b)
{
    if(a.size()==0)return "0";
    if(b.size()==0)return "0";
    if(a=="0"||b=="0")return "0";
    string ans("");
    if(a.size()<=9&&b.size()<=9)
    {
        int val=conv(a)*conv(b);
        
        while(val)
        {
            ans.push_back(val%10+'0');
            val/=10;
        }
        
        reverse(all(ans));
        return ans;
    }
    int maxi=(max(a.size(),b.size())+1)/2;
    string x(""),y(""),z(""),Z("");
    string p(""),q(""),r(""),s("");
    int c=0;
    if(a.size()<=maxi)
    {
        q=a;
        c=1;
    }
    else 
    {
        for(int i=0;i<a.size()-maxi;i++)
        {
            p.push_back(a[i]);
        }
        for(int i=a.size()-maxi;i<a.size();i++)
        {
            q.push_back(a[i]);
        }


    }
    
    if(b.size()<=maxi)
    {
        s=b;
        c=2;
    }
    else 
    {
        for(int i=0;i<b.size()-maxi;i++)
        {
            r.push_back(b[i]);
        }
        for(int i=b.size()-maxi;i<b.size();i++)
        {
            s.push_back(b[i]);
        }
        

    }
    
    x=solve(p,r),y=solve(q,s);
    z=solve(p,s),Z=solve(q,r);
    
    z=add(z,Z);
    for(int i=0;i<maxi;i++)z.push_back('0'); 
    if(x!="0"&&x!="")
    for(int i=0;i<2*maxi;i++)x.push_back('0');
    int i=0;
    string alp;
    while(i<x.size()&&x[i]==0)i++;
    while(i<x.size())alp.push_back(x[i++]);
    x=alp;
    alp="";
    i=0;
    while(i<y.size()&&y[i]==0)i++;
    while(i<y.size())alp.push_back(y[i++]);
    y=alp;
    alp="";
    i=0;
    while(i<z.size()&&z[i]==0)i++;
    while(i<z.size())alp.push_back(z[i++]);

    ans=add(x,y);
    ans=add(ans,alp);
    alp="";
    i=0;
    while(i<ans.size()&&ans[i]==0)i++;
    while(i<ans.size())alp.push_back(ans[i++]);
    return alp;


}
void solve(){
    
    string a,b;
    string prev="";
    while(true)
    {
        try
        {
            cin>>a;

        }
        catch(...) {return;}
        cin>>b;
        string ans=solve(a,b);
        
        if(ans==prev)break;
        cout<<ans<<endl;
        prev=ans;
        if(cin.eof())break;
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
    //cin>>tt;

    while(tt--) solve();
    return 0;
    
}