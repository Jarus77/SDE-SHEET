/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */




class Solution{
    
    
    private:
    
    void bfs(int src,unordered_map<int, vector<int>>adj,unordered_map<int,int>&distance){
        
        
        queue<pair<int,int>>q;
        //int n=adj.size();
        unordered_set<int>myset;
        
        
        q.push({src,0});
        myset.insert(src);
        distance[src]=0;
        
        
        while(!q.empty()){
            
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();
            
            
            
            for(auto it:adj[node]){
                
                if(myset.find(it)==myset.end()){
                    
                    myset.insert(it);
                    distance[it]=dist+1;
                    q.push({it,dist+1});
                    
                }
                
                
            }   
        }
        
        
    }
    
    
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
    
    
    unordered_map<int,vector<int>>adj;
    queue<Node*> q;
    q.push(root);
    
    
    while(!q.empty()){
        
        Node* node=q.front();
        q.pop();
        
        if(node->left){
            
            adj[node->data].push_back(node->left->data);
            adj[node->left->data].push_back(node->data);
            q.push(node->left);
            
        }
        
        if(node->right){
            
            
            adj[node->data].push_back(node->right->data);
            adj[node->right->data].push_back(node->data);
            q.push(node->right);
                
        }
    
        
    }
    
    
        unordered_map<int,int>dist;
        
        bfs(a,adj,dist);
       
        return dist[b];
    
    
        
        
        
    }
};
