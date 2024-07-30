//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
    
    
public:

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
       int n=arr.size();
       
       vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
       
       for(int i=0;i<n;i++) dp[i][0]=true;
    
        dp[0][arr[0]]=true;
        
        
    
        for(int idx=1;idx<n;idx++){
            
            for(int target=1;target<=sum;target++){
                
                bool nottake=dp[idx-1][target];
                bool take=false;
                
                if(arr[idx]<=target){
                    
                    take=dp[idx-1][target-arr[idx]];   
                }
                
                dp[idx][target]=take|nottake;
                
            }
        }
        
        
        
    
        return dp[n-1][sum];
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
