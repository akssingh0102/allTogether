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
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int cost=0;
        bool start=false;
        int sta=0,end=INT_MAX;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1' && start==false){
                cost+=a;
                start=true;
            }

            else if (s[i]=='1' && s[i-1]=='0')
            {
                end=i;
                int c=(end-sta)*b;
                if(c<a){
                    cost+=c;
                }
                else{
                    cost+=a;
                }
                
            }
            else if(s[i]=='0' && s[i-1]=='1' && start){
                sta=i;

            }
            
        }
        cout<<cost<<endl;
        
    }
    return 0;
}