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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    com{
        iz(n)
        take(a,n)
        int maximum=0;
        int count=0;
        
        for (int i = 0; i < n; i++)
        {
            if(a[i]>a[maximum]){
                maximum=i;
            }
            if(a[i]==a[0]){
                count++;
            }
        }
        if(count==n){
            cout<<-1<<endl;
            continue;
        }
        if((a[maximum]==a[0] && a[1]<a[0]) ){
            maximum=0;
        }
        else if((a[n-1]>a[n-2] && a[n-1]==a[maximum])){
            maximum=n-1;
        }
        else{
        for (int i = 1; i < n-1; i++)
        {
            if(a[i]==a[maximum]){
                if(a[i-1]<a[maximum] || a[i+1]<a[maximum]){
                    maximum=i;
                    break;
                }
            }
        }
        }
        cout<<maximum+1<<endl;
        
        
    }
    return 0;
}