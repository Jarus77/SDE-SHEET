//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    private:
    
    void bfs(vector<int>&dist,vector<vector<int>>&adj,int src){
        
        queue<pair<int,int>>q;
        
        q.push({src,0});
        dist[src] = 0;
        
        
        while(!q.empty()){
            
            int node=q.front().first;
            int distn =q.front().second;
            
            q.pop();
            
            int tdist=1+distn;
            
            for(auto it: adj[node]){
            
                if(tdist<dist[it]){
    
                    dist[it]=tdist;
                    q.push({it,tdist});
                    
                }   
            }   
        }
        
    }
    
    
 
 
  public:
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       
        vector<vector<int>> adj(N);
        
        for (int i = 0; i < M; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       
        // code here
        vector<int>dist(N,INT_MAX);
        
        bfs(dist,adj,src);
        
        
        for (int& d : dist) {
            if (d == INT_MAX) {
                d = -1;
            }
        }

    
        return dist;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
