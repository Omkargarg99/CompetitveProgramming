#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb emplace_back               
#define mp make_pair
#define ss second
#define ff first

void solve(){
    int q;
    cin>>q;

    deque<pair<int,int>>v;
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
        {
            int c;
            cin>>c;
            v.push_back(mp(c,b));
        }
        else 
        {
            int ans=0;
            while(!v.empty()&&b)
            {
                pair<int,int>p=v.front();
                v.pop_front();
                if(b>=p.ss)
                {
                    ans+=p.ff*p.ss;
                    b-=p.ss;
                }
                else 
                {
                    
                    ans+=b*p.ff;
                    p.ss-=b;
                    b=0;
                    v.push_front(p);
                }
            }
            cout<<ans<<endl;
            
        }
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