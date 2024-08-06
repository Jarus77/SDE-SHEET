//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    
 private:

     bool checkPalindrome(string ss) {
        int n = ss.length();
        vector<int> charCount(26, 0);

        for (char c : ss) {
            charCount[c - 'a']++;
        }

        int oddCount = 0;
        for (int count : charCount) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }

        if ((n % 2 == 0 && oddCount == 0) || (n % 2 != 0 && oddCount == 1)) {
            return true;
        }
        return false;
    }
 
 
 


    
  public:
    int longestSubstring(string S) {
        // code here
        
        int n=S.length();
        int maxlen=0;
        
        for(int i=0;i<n;i++){
            
            
            for(int j=i;j<n;j++){
                
                string ss = S.substr(i, j - i + 1);
                
                
                if (checkPalindrome(ss)) {
                    maxlen = max(maxlen, j - i + 1);
                }
                
                
            }
            
            
        }
        
        return maxlen;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
