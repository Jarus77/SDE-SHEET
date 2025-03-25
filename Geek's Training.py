#User function Template for python3

class Solution:
    def maximumPoints(self, arr):
        # Code here
        
        
        n=len(arr)
        
        dp=[[0 for _ in range(4)] for _ in range(n)]
        
        # Base case: for the last day
        for last in range(4):
            dp[n-1][last] = max(arr[n-1][i] for i in range(3) if i != last)

        
        for day in range(n-2,-1,-1):
            
            for last in range(4):
                maxi=0
                for curr in range(3):
                    if curr!=last:
                        maxi=max(dp[day+1][curr]+arr[day][curr],maxi)
                
                dp[day][last]=maxi
            
                        
        
        return dp[0][3]
                
                
                
        
        
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = [list(map(int, input().split())) for _ in range(n)]
        ob = Solution()
        print(ob.maximumPoints(arr))
        print("~")
# } Driver Code Ends
