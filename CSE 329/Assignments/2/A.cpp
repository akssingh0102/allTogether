#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define ll                  long long int 
#define llmin               -1e18
#define ff                  first
#define ss                  second
#define pb                  push_back
#define vi                  vector<int>
#define take(a,n)           vector <int> a; for(int i=0;i<n;i++){int aa; cin>>aa; a.pb(aa);}
#define vll                 vector<ll> 
#define full(a)             (a.begin(),a.end())
#define vc                  vector<char>
#define iz(n)               int n; cin>>n;
#define iz2(n,m)             int n,m; cin>>n>>m;
#define mii                 map<int,int>
#define setbits(x)          __builtin_popcountll(x)
#define zerobits(x)         __builtin_ctzll(x)    //zeros before first 1
#define com                 int t; cin>>t; while(t--)
#define forn(n)             for(int i=0;i<n;i++)
#define fo(x,y)             for(int i=x;i<y;i++)

int check(int n)  
{ 
    int maximum = -1; 
      
    while (!(n % 2))  
    { 
        maximum = max(maximum, 2); 
        n = n/2; 
    } 
  
    for (int i = 3; i <= sqrt(n); i += 2) 
    { 
        while (n % i == 0)  
        {    
            maximum = max(maximum,i);  
            n = n / i; 
        } 
    } 
  
    if (n > 2) 
        maximum = max(maximum, n); 
      
    return maximum; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    take(a,n)
    bool flag=false;
    int res=1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>=2 ){
            // if(flag==true){
            //     if(setbits(a[i])>setbits(res)){
            //         continue;
            //     }
                
            // }
            int x=check(a[i]);
            int y=((x*x)+1);
            y=check(y);
            if((a[i]*2) <= y){
                res=a[i];
            }
            flag=true;
        }
    }
   cout<<res;

    return 0;
}