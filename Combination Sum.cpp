// https://leetcode.com/problems/combination-sum/

class Solution {

    private:

    void findSum(int idx,int target,vector<int>candidates,vector<int>ds,vector<vector<int>>&ans){

    
        if(idx==candidates.size()){


            if(target==0){
                    ans.push_back(ds);


            }
                return;

        }

        if(candidates[idx]<=target){

            ds.push_back(candidates[idx]);

            findSum(idx,target-candidates[idx],candidates,ds,ans);
            ds.pop_back();

        }
        
       
       
        findSum(idx+1,target,candidates,ds,ans);



        
    }




public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {



        vector<vector<int>> ans;
        vector<int>ds;

        findSum(0,target,candidates,ds,ans);


        return ans;



    }
};
