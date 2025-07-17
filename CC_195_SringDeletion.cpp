#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])c++;
    }
    if(c==0||c==1)
    {
        cout<<n<<endl;
        return;
    }
    int ans=2,i=1,j=n-2;
    while(i<n)
    {
        if(s[i]!=s[i-1])break;
        i++;
        ans++;
    }
    while(j>=0)
    {
        if(s[j]!=s[j+1])break;
        j--;
        ans++;
    }
    if(s[0]!=s[n-1])
        ans++;
    
    cout<<ans+1<<endl;
    
   
    
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