class Solution {

private:

bool findsubsetsum(vector<int>&nums,int sum,int n){



    vector<vector<bool>>dp(n,vector<bool>(sum+1,false));

    for(int i=0;i<n;i++) dp[i][0]=true;

    
        if(nums[0]<=sum) dp[0][nums[0]]=true;



    for(int target=1;target<=sum;target++){

        for(int i=1;i<n;i++){

            bool nottake=dp[i-1][target];
            bool take=false;

            if(nums[i]<=target){
                
                take=dp[i-1][target-nums[i]];

            }


            dp[i][target]=take|nottake;


        }

    }
    return dp[n-1][sum];


}



public:
    int minimumDifference(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }


        for(int i=sum/2;i>=0;i--){

            if(findsubsetsum(nums,i,n)){

                int ans=sum-2*i;
                return ans;

            } 

        }

        return -1;

    }

};
