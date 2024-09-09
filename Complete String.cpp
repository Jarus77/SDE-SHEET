#include <bits/stdc++.h> 

struct Node{

    Node*links[26];
    bool flag=false;

    bool isContain(char ch){

        return links[ch-'a']!=nullptr;

    }

    void put(char ch,Node*node){

        links[ch-'a']=node;
    }


    Node* get(char ch){

        return links[ch-'a'];

    }

    void setEnd(){

        flag=true;
    }

    bool isEnd(){

        return flag;

    }


};


class Trie {

private:

Node*root;

public:
    Trie() {
        
    root=new Node();


    }
    
    void insert(string word) {

        Node* node=root;
        int n=word.size();

        for(int i=0;i<n;i++){

            if(!node->isContain(word[i])) {
                
                node->put(word[i],new Node());

            }
            node=node->get(word[i]);

        }

        node->setEnd();

    }
    
    bool search(string word) {
        
        int n=word.size();
        Node*node=root;

        for(int i=0;i<n;i++){

            if(!node->isContain(word[i])) return false;
            node=node->get(word[i]);

        }

        return node->isEnd();

    }

    
    bool startsWith(string prefix) {

        Node*node=root;

        for(int i=0;i<prefix.size();i++){

            if(!node->isContain(prefix[i])) return false;
            node=node->get(prefix[i]);
        }

        return true;
    }

    bool check(string s){

        Node*node=root;

        for(int i=0;i<s.size();i++){

            node=node->get(s[i]);

            if (!node || !node->isEnd()) return false; 
            

        }

        return node->isEnd();


    }   






};




string completeString(int n, vector<string> &a){
    // Write your code here.


    Trie t;


    for(int i=0;i<n;i++){

        t.insert(a[i]);        

    }

    string ans="None";

    int maxlen=0;


    for(int i=0;i<n;i++){



        if(t.check(a[i])){

        if(maxlen<a[i].size()){
            ans=a[i];
            maxlen=a[i].size();
        }

        else if(maxlen==a[i].size()&& a[i]<ans){
            ans=a[i];

        }

           
        }



    }

    return ans;

}
