//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
private:


    void dfs(int i,stack<int>&st,vector<vector<pair<int,int>>>&adj,vector<bool>&visited){
        

        visited[i]=true;
        
        for(auto it: adj[i]){
            
            if(!visited[it.first]){
                dfs(it.first,st,adj,visited);
            }
            
        }
        
        st.push(i);
        
        
    }



    void toposort(stack<int>&st,vector<vector<pair<int,int>>>&adj,int N,vector<bool>&visited){
        
        
        for(int i=0;i<N;i++){
            
            if(!visited[i]){
                
                    dfs(i,st,adj,visited);
            }   
        }
    }
    
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // code here
        
        
        vector<vector<pair<int,int>>>adj(N);
        
        for(int i=0;i<M;i++) adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            
        
        
        stack<int>st;
        vector<bool>visited(N,false);
        toposort(st,adj,N,visited);
        
        
        
        vector<int>dist(N,INT_MAX);
        int src=0;
        dist[src]=0;
        
        
        
        while(!st.empty()){ 
            int node =st.top();
            int distn= dist[node];
            st.pop();
            
            if (dist[node] != INT_MAX){
                 for(auto it: adj[node]){
                    int tempdist= distn+it.second;
                    if(tempdist<dist[it.first]){
                        dist[it.first]=tempdist;
                    }
                }
                
            }
               
        }
        
        for(auto &d: dist){
            if(d==INT_MAX){
                d=-1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
