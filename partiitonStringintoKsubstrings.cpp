//partiitonStringintoKsubstrings

//Q. Given a string, partition string into K parts. Return All possible answer

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void function(string s,int k,int start,vector<string>&path,vector<vector<string>>&result){
    
    
    if(path.size()==k && start==s.size()){
        
        result.push_back(path);
        return;
    }
    
    if(path.size()==k) return;
    
   
    
    for(int i=start;i<s.size();i++){
        
        
        path.push_back(s.substr(start,i-start+1));
        function(s,k,i+1,path,result);
        path.pop_back();
    }
    
}



vector<vector<string>> partitionString(const string &s, int k) {

    vector<vector<string>> result;
    vector<string>path;
        
    function(s,k,0,path,result);
    
    return result;
    

}





int main() {
    string s = "baabbc";
    int k = 3;
    vector<vector<string>> results = partitionString(s, k);
    int cnt=0;
    for (const auto &partition : results) {
        for (const auto &part : partition) {
            cout << part << " ";
        }
        cout << endl;
        cnt++;
    }
    cout<<cnt;

    return 0;
}
