//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class DisjointSet{
    
    private:
    vector<int>rank,parent;
    
    public:
    
    DisjointSet(int n){
        
    rank.resize(n+1,0);
    parent.resize(n+1);
    
    for(int i=0;i<n;i++) parent[i]=i;   
        
    }
    
    
    int findupperParent(int node){
        
        
        if(parent[node]==node) return node;
        
        return parent[node]=findupperParent(parent[node]);
        
    }
    
    void Union2edges(int u,int v){
        
        int up_u=findupperParent(u);
        int up_v=findupperParent(v);
        
        
        if(up_u==up_v) return;
        
        if(rank[up_u]<rank[up_v]){
            
            parent[up_u]=up_v;
            
        }
        
       else if(rank[up_u]>rank[up_v]){
            
            parent[up_v]=up_u;
            
        }
        
        else{
            
            parent[up_u]=up_v;
            rank[up_v]++;
        }   
    }  
    
};








class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        
        vector<pair<int,pair<int,int>>>edjes;
        
        for(int i=0;i<V;i++){
            
            for(auto it:adj[i]){
                
                int neighbour=it[0];
                int weight=it[1];
                
                edjes.push_back({weight,{i,neighbour}});
                
                
            }
            
            
        }
        
        sort(edjes.begin(),edjes.end());
        
        
        DisjointSet ds(V);
        int mstWt=0;
        
        for(auto it:edjes){
            
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findupperParent(u)!=ds.findupperParent(v)){
             
             ds.Union2edges(u,v);
             mstWt+=wt;
                
            }
            
        }
        
        
        
        return mstWt;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
