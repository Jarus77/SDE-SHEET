// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {

private:

    bool checkBipartite(int i,queue<int>&st,vector<bool>&visited,vector<int>&color,vector<vector<int>>& graph){


        st.push(i);
        color[i]=0;
        visited[i]=true;

        while(!st.empty()){

           int i= st.front();

            st.pop();

            for(auto it:graph[i]){

                if(!visited[it]){

                    st.push(it);
                    visited[it]=true;

                    if(color[i]==0){

                        color[it]=1;
                    }
                    else{

                        color[it]=0;
                    }

                    
                }

                else if(color[it]==color[i]) return false;
        }
        }
        
        return true;

    }




public:



    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();

        vector<bool> visited(V,false);
        vector<int> color(V,-1);
        queue<int>st;


        for(int i=0;i<V;i++){


            if(!visited[i]){

                if(!checkBipartite(i,st,visited,color,graph)) return false;


            }

        }


        return true;



    }
};
