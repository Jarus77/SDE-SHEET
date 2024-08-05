//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    

bool checkPalindrome(string &s){
    
        int n=s.size();
        for(int i=0;i<n/2;i++){
            
            
            if(s[i]!=s[n-1-i]) return false;
        }
        
        return true;
}


void partitionIntoK(string s,int start,int k,vector<string>&path,vector<vector<string>>&result){
    
    
    if(path.size() == k && start == s.size()){
        result.push_back(path);
    }
    
    if(path.size() == k){
        return;
    }
    
    
    for(int i = start; i < s.size(); i++){
        path.push_back(s.substr(start, i - start + 1));
        partitionIntoK(s, i + 1, k, path, result);
        path.pop_back();
    }
    
    
    
    
}



bool function(string s, int k){
    vector<vector<string>> result;
    vector<string> path;
    
    partitionIntoK(s, 0, k, path, result);
    
    for(auto &it : result){
        int c = 0;
        for(auto &it2 : it){
            if(checkPalindrome(it2)) c++;
        }
        if(c == k) return true;
    }
    return false;
}





    
    
public:
    int palindromicPartition(string str){
        int n = str.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(function(str, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return high;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
