#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

#define MOD1 1000000007
#define MOD 998244353

#define int long long int

#define pi pair<int,int>

#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  

#define inf 1e18
#define mp make_pair
#define ss second
#define ff first

void solve(){
    
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    if(k<=2)
    {
        cout<<"YES"<<endl;
        return;
    }
    vector<pair<int,int>>x;
    for(int i=0;i<n;i++)
    {
        x.pb(mp(v[i],i+1));
    }
    
    sort(all(x));

    int q=0,p=x[k-1].ff;
    vector<int>pos,con;
    for(int i=0;i<n;i++)
    {
        if(v[i]<p)
        {
            con.pb(v[i]);
            pos.pb(i);
        }
    }
    if(con.size()==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    int i=0,j=con.size()-1;
    while(i<j)
    {
        if(con[i]!=con[j])
        {
            cout<<"NO"<<endl;
            return;
        }
        i++;j--;
    }
    i=0,j=n-1;
    int count=0,al=0;
    int ii=0,jj=pos.size()-1;
    while(ii<=jj)
    {
        int c=0;
        for(int a=i;a<pos[ii];a++)
        {
            if(v[a]==p)c++;


        }
        i=pos[ii];
        ii++;
        for(int a=j;a>pos[jj];a--)
        {
            if(v[a]==p&&c)
            {
                c--;
                al+=2;
            }


        }
        j=pos[jj];
        jj--;
        
        

    }
    if(pos.size()%2==0)
    {
        for(int i=pos[pos.size()/2-1];i<=pos[pos.size()/2];i++)
        {
            if(v[i]==p)al++;
        }
    }
    if(al+pos.size()>=k-1)
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

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