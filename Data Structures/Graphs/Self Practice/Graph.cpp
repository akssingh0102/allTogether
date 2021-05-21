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

class Graph{

    int V;                                  //number of Vertices
    vector<int> *adj;                       //adjacency list

    public:
    Graph(int v){                           //Constructor
        this->V=v;
        adj = new vector<int>[V]; 
    }

    void addEdgeDir(int v,int u){           //add directed edges
        adj[v].push_back(u);
    }

    void addEdge(int v,int u){              //add non-directed edge
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void print(){
        for (int i = 0; i < V; i++)
        {
            cout<<"For node "<<i<<" ::  ";
            for (int j = 0; j<adj[i].size() ; j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;            
        }        
    }

//***************************** BFS for connected graphs ***************
    void BFS(int x){                        //BFS
        int u;
        u=x;
        vector<bool>visited(V,false);                                                                                                                
        queue<int> q;

        q.push(u);
        visited[u]=true;

        while (!q.empty())
        {
            int uu=q.front();
            q.pop();
            cout<<uu<<" ";
            for(auto X:adj[uu]){
                if(!visited[X]){
                    visited[X]=true;
                    q.push(X);
                }
            }
        }        
    }
//***************************** BFS for disconnected graphs ***************

    void BFSUtil(int u,vector <bool> &visited){
        visited[u]=true;
        queue<int> q;

        q.push(u);

        while (!q.empty())
        {
            int uu=q.front();
            q.pop();
            cout<<uu<<" ";
            for(auto X:adj[uu]){
                if(!visited[X]){
                    visited[X]=true;
                    q.push(X);
                }
            }
        }        

    }

    void BFSdis(int u){                      
        vector <bool> visited(V+1,false);
        visited[u]=true;
        BFSUtil(u,visited);
        for (int i = 0; i < V; i++)
        {
            if(!visited[i])
                BFSUtil(i,visited);
        }
        
    }


//************************************ DFS of Graphs *******************************************
    void DFSRec(int u,vector <bool> &visited){
        visited[u]=true;
        cout<<u<<" ";
        for(auto x:adj[u]){
            if(!visited[x]){
                DFSRec(x,visited);
            }
        }
    }

    void DFS(int u){
        vector <bool> visited(V,false);
        visited[u]=true;
        DFSRec(u,visited);

        for (int i = 0; i < V; i++)
        {
            if(!visited[i]){
                DFSRec(i,visited);
            }
        }                                                                                                                                                                                                                                                                                                                                                                                                                            
    }

//******************************* Cycle Detection **************************
    bool isCyclicHelper(int u,vector<bool> &visited,vector <bool> &recStack){
        visited[u]=true;
        recStack[u]=true;

        for(auto X:adj[u]){
            if((!visited[X]) && (isCyclicHelper(X,visited,recStack)))
                return true;
            else if(recStack[X])
                return true;
        }
        recStack[u]=false;
        return false;
    }

    bool isCyclic(){
        vector <bool> visited(V,false);
        vector <bool> recStack(V,false);

        for (int i = 0; i < V; i++)
        {
            if(!visited[i]){
                if(isCyclicHelper(i,visited,recStack)){
                    return true;
                }
            }
        }
        return false;
        
    }

//******************************** Topological Sort ****************************

    void topologicalSort() 
{ 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        cout<<u<<" "; 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
    } 
}

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif

    Graph g(4);

    g.addEdgeDir(0,1);
    // g.addEdgeDir(0,2);
    g.addEdgeDir(1,2);
    // g.addEdgeDir(2,0);
    g.addEdgeDir(2,3);
    g.addEdgeDir(3,0);

    // cout<<g.
    g.print();

    g.BFS(0);
    cout<<endl;
    g.BFSdis(0);
    cout<<endl;
    g.DFS(0);
    cout<<endl;
    if(g.isCyclic()){
        cout<<"Their is a cycle "<<endl;
    }
    else{
        cout<<"Their is no Cycle"<<endl;
    }


    
    
    return 0;
}