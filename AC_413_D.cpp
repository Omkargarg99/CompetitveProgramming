#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  
#define mp make_pair
#define ss second
#define ff first

int gcd(int a,int b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}

void solve(){
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        x[i]=abs(v[i]);
    }
    vector<pair<int,int>>qu;
    for(int i=0;i<n;i++)
    {
        qu.pb(mp(abs(v[i]),(v[i]>0)));
    }
    sort(all(qu));
    sort(all(x));
    int g=gcd(min(x[0],x[1]),max(x[0],x[1]));
    pair<int,int>p={x[1]/g,x[0]/g};
    for(int i=2;i<n;i++)
    {
        int k=x[i-1]*p.ff;
        if(k%p.ss==0&&k/p.ss==x[i])
        {
            continue;
        }
        else 
        {
            cout<<"No"<<endl;
            return;
        }

    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=qu[i].ss;
    }
    if(count==0||count==n)
    {
        cout<<"Yes"<<endl;
        return;
    }
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[v[i]]++;
        
    }
    int c=0;
    if(m[x[0]])
    {
        int d=1;
        m[x[0]]--;
        for(int i=1;i<n;i++)
        {
            int k=x[i-1]*p.ff/p.ss;
            if(i%2)k=-k;
            if(m[k]==0)
            {
                d=0;
                break;
            }
            m[k]--;
            
        }
        if(d)c=1;

    }
    
    map<int,int>ma;
    for(int i=0;i<n;i++)ma[v[i]]++;
    if(ma[-x[0]])
    {
        int d=1;
        ma[-x[0]]--;
        for(int i=1;i<n;i++)
        {
            int k=x[i-1]*p.ff/p.ss;
            if(i%2==0)k=-k;
            if(ma[k]==0)
            {
                d=0;
                break;
            }
            ma[k]--;
            
        }
        if(d)c=1;

    }
    if(c)
    cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

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