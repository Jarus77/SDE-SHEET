#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int getRank(string s){
    
    
    unordered_map<string,int> mpp={
        {"2",2},{"3",3},
        {"4",4},{"5",5},
        {"6",6},{"7",7},
        {"8",8},{"9",9},
        {"10",10},{"J",11},
        {"Q",12},{"K",13},
        {"A",14}
    };
    int l=s.length();
    string substr=s.substr(0,l-1);
    
    
    return mpp[substr];
    
    
}






struct Results{
    
    string set_name;
    vector<string> selected_cards;
    
};


Results solution(vector<string>&cards){
      int n=cards.size();
      
      
    // Set 4
      unordered_map<char,vector<string>>mpp4;
    
    for(int i=0;i<n;i++){
        
     char suit=cards[i].back();
    
        mpp4[suit].push_back(cards[i]);
    
    }
    
    int maxsuit=0;
    char character = 'a';
    for(auto it: mpp4){
        
        if (it.second.size()>=5){
           int suitorder=it.second[0].back()-'A';
           if(maxsuit<suitorder){
               
               maxsuit=suitorder;
               character = 'a' + maxsuit; // Update character
               
           }
        
        } 
    }
    
   
    //cout<<maxRank;
    
    vector<string> firstFive;
    if (!mpp4[character].empty()) {
        firstFive.assign(mpp4[character].begin(), mpp4[character].begin() + min(5, static_cast<int>(mpp4[character].size())));
    }

    Results result;
    result.set_name = "suit";
    result.selected_cards = firstFive;
    return result;
    
    
    
      
      
      
      //Set 3
    unordered_map<int,vector<string>>mpp3;
    
    for(int i=0;i<n;i++){
        
        int rank=getRank(cards[i]);
    
        mpp3[rank].push_back(cards[i]);
    
    }
    
    int maxRank=2;
    for(auto it: mpp3){
        
        if (it.second.size()>=3){
           int rank=getRank(it.second[0]);
           if(rank>maxRank){
               
               maxRank=rank;
               
           }
        
        } 
    }
    //cout<<maxRank;
    
    vector<string>firstThree(mpp3[maxRank].begin(),mpp3[maxRank].begin()+3);
    
    // Results result;
    // result.set_name="triple";
    // result.selected_cards=firstThree;
    // return result;
      
      
    
    //Set 2
    unordered_map<int,vector<string>>mpp2;
    

    
    for(int i=0;i<n;i++){
        
        int rank=getRank(cards[i]);
    
        mpp2[rank].push_back(cards[i]);
    
    }
    
    for(auto it: mpp2){
        
        if (it.second.size()==2){
            
                Results result;
                result.set_name="pair";
                result.selected_cards=it.second;
                return result;
        } 
    }
    
    
    
    
    
    // single Card Set 1
  
    int maxi=2;
    int idx=0;


    
    for(int i=0;i<n;i++){
  

            
            int rank=getRank(cards[i]);
            
          //  int rank=stoi(substr) ;   
        
             if(maxi<rank){
                 maxi=rank;
                 idx=i;
             }
             
    }
    
    
    // Results result;
    // vector<string>ans;
    // ans.push_back(cards[idx]);
    // result.set_name="single card";
    // result.selected_cards=ans;
    
    
    // return result;
    
    }



int main() {
    // Example input
    vector<string> cards = {"AS", "AH", "5S", "6S", "7S", "8S", "9S","KD"};

    // Call the solution function
    Results result = solution(cards);

    // Print the result
    cout << "Set Name: " << result.set_name << endl;
    cout << "Selected Cards: ";
    for (const string &card : result.selected_cards) {
        cout << card << " ";
    }
    
    cout << endl;
    

    return 0;
}
