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
#define pq                  priority_queue <int, vector<int>, greater<int> >
#define mod                 1000000007


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    com{
        int n,m;
        cin>>n>>m;
        // take(a,n)
        string s;
        cin>>s;
        vi a;
        for (int i = 0; i < n; i++)
        {
            
            a.push_back(s[i]-'0');

        }
        
        for (int i = 0; i < n; i++)
        {
            int back,forward;
            back=i-1;
            forward=i+1;
            if(a[i]==0 && back>=0 && forward<n){
                if(a[back]==1 && a[forward]==1){
                    a[i]=-1;
                }
            }
        }

            int power=0;

            for (int i = 0; i < n; i++)
            {
                if(a[i]==1){
                    power=m;
                }
                else if(a[i]!=1 && a[i]!=-1 && power){
                    a[i]=11;
                    power--;
                }
            }
            power=0;
            for (int i = n-1; i >= 0; i--)
            {
                if(a[i]==1){
                    power=m;
                }
                else if(a[i]!=1 && a[i]!=-1 && power){
                    a[i]=11;
                    power--;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if(a[i]==-1){
                    cout<<0;
                }
                else if(a[i]==11){
                    cout<<1;
                }
                else{
                    cout<<a[i];
                }
            }
            cout<<endl;
            
        
        
    }
    return 0;
}