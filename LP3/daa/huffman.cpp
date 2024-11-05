#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Node{
    public:
        Node *l,*r;
        char c;
        int freq;
        string data;
        Node(){
            l = r = 0;
            c = '\0';
            data = "";
            freq = 0;
        }
};


class Huffman{
    public:
        string s;
        map<char,int> mf;
        map<char,string> mc;
        vector<Node *> v;
        Node *r;
        Huffman(){
            s = "bccabbddaeccbbaeddcc";

            for(int i = 0;i<s.length();i++){
                mf[s[i]]++;
            }
        }
        void buildTree();
        void displayVector();
        void getCode(Node *r, string str);
        void displayCode();
};

void Huffman :: displayCode(){
    cout<<"Codes : "<<endl;
    for(const auto& i : mc){
        cout<<i.first<<" : "<<i.second<<endl;
    }
}

void Huffman :: getCode(Node *r, string str){
    if(r == NULL) return;
    r->data = str;
    if(r->l == NULL){
        mc[r->c] = r->data;
    } else {
        getCode(r->l,str+"0");
        getCode(r->r,str+"1");
    }

}

void Huffman :: displayVector(){
    cout<<"Vector : "<<endl;
    for(int i = 0;i<v.size();i++){
        cout<<v[i]->c<<" "<<v[i]->freq<<endl;
    }
    cout<<endl;
}

bool compare(Node *n1,Node *n2){
    return n1->freq < n2->freq;
}

void Huffman :: buildTree(){
    Node *temp;
    for(const auto& i : mf){
        temp = new Node();
        temp->c = i.first;
        temp->freq = i.second;
        v.push_back(temp);
    }

    Node *n1,*n2,*n3;
    while(v.size() >= 2){
        sort(v.begin(),v.begin()+v.size(),compare);
        displayVector();

        n1 = v[0];
        n2 = v[1];

        v.erase(v.begin());
        v.erase(v.begin());

        n3 = new Node();
        n3->freq = n1->freq + n2->freq;
        if(n1->freq < n2->freq){
            n3->l = n1;
            n3->r = n2;
        } else {
            n3->l = n2;
            n3->r = n1;
        }
        v.push_back(n3);
    }
    r = v[0];
    getCode(r,"");
}

int main(){
    Huffman h;
    h.buildTree();
    h.displayCode();
    return 0;
}