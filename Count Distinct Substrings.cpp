struct Node{


    Node*root;
    Node*links[26];

    bool flag=false;


    bool  contains(char ch){

        return links[ch-'a']!=nullptr;


    }

    Node* get(char ch){

        return links[ch-'a'];

    }

    void setEnd(){
        flag=true;
    }

    void put(char ch, Node* node){

        links[ch-'a']=node;

    }






};









int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    Node*root=new Node();

    int n=s.size();

    int cnt=0;

    for(int i=0;i<n;i++){

        Node* node=root;

        for(int j=i;j<n;j++){

        if(!node->contains(s[j])){
                node->put(s[j], new Node);
                cnt++;
            }

            node=node->get(s[j]);
        }

      //  node->setEnd();

        


    }

    return cnt+1;


}
