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
#define in(x)               cin>>x;

void pal_count(int &diff,int n,string &s){
    int l=0,h=n;
    while(l<=h){
        if(s[l]!=s[h]){
            diff++;
            s[l]='1';
            s[h]='1';
        }
        l++;
        h--;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    com{
        int player_1=0,player_2=0;
        iz(n)
        string s;
        in(s)
        int diff=0;
        pal_count(diff,s.length()-1,s);
        player_2+=diff;
        
        int count_0=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='0') count_0++;
        }
       if(diff==0){
            if(count_0 == 1 ){
            cout<<"BOB"<<endl;
        }
        else if(count_0%2==1){
            cout<<"ALICE"<<endl;
        }
        else if(s.length()==1 && s[0]=='1'){
            cout<<"DRAW"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }
       
    }
    else{
        if(diff==1 && count_0==1){
            cout<<"DRAW"<<endl;
        }
        else{
            cout<<"ALICE"<<endl;
        }
    }
    
    }
    return 0;
}