#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define pb emplace_back              
#define all(x) (x).begin(),(x).end()  

void solve(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        maxi=max(maxi,v[i]);
    }

    vector<int>a(v);
    vector<int>b(n);

    int sum=0;
    for(int i=0;i<n;i++)sum+=v[i];
    if((sum&1)||maxi>sum/2)
    {
        cout<<-1<<endl;
        return;
    }
    int x=sum/2,val=0,y=-1,pos=-1;
    for(int i=0;i<n;i++)
    {
        val+=v[i];
        if(val>x)
        {
            y=(val-x);
            a[i]-=(y);
            b[i]=y;
            
            pos=i;
            break;
        }
        else if(val==x)
        {
            cout<<1<<endl;
            for(int i=0;i<n;i++)cout<<v[i]<<" ";
            cout<<endl;
            return;

        }
    }
    int s1=0;
    for(int k=pos-1;k>=0;k--)
    {
        if(s1+v[k]>=y)
        {
            b[k]=y-s1;
            a[k]-=b[k];
            break;
        }
        b[k]=a[k];
        s1+=b[k];
        a[k]=0;

    }

    cout<<2<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<b[i]<<" ";
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