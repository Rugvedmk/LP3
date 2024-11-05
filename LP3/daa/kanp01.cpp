#include<iostream>
#include<algorithm>
using namespace std;

// int p[] = {1,2,5,6};
// int w[] = {2,3,4,5};
// capacity = 8;

class Node{
    public:
        int w,p,id;
        Node(){
            w = p = id = 0;
        }
};

class Knap{
    public:
        Node *nodes;
        int capacity,tweights;
        int **table;
        void initializeWeights();
        void fillTable();
};

bool compare(Node n1,Node n2){
    return n1.w < n2.w;
}

void Knap :: initializeWeights(){
    int p[] = {1,2,5,6};
    int w[] = {2,3,4,5};
    capacity = 8;
    tweights = 4;
    nodes = new Node[4];
    for(int i = 0;i<tweights;i++){
        nodes[i].id = i+1;
        nodes[i].w = w[i];
        nodes[i].p = p[i];
    }

    sort(nodes,nodes+tweights,compare);
    for(int i = 0;i<tweights;i++){
        cout<<nodes[i].id<<" : "<<nodes[i].w<<endl;
    }
}

void Knap :: fillTable(){
    table = new int *[tweights+1];

    for(int i = 0;i<tweights+1;i++){
        table[i] = new int [capacity+1];
    }

    for(int i = 0;i<tweights+1;i++){
        table[i][0] = 0;
    }
    for(int i = 0;i<capacity+1;i++){
        table[0][i] = 0;
    }

    for(int i = 1;i<tweights+1;i++){
        for(int j = 1;j<capacity+1;j++){
            if(j >= nodes[i-1].w){
                table[i][j] = max(table[i][j-1],table[i-1][j - nodes[i-1].w]+nodes[i-1].p);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }    

    
    for(int i = 0;i<tweights+1;i++){
        for(int j = 0;j<capacity+1;j++){
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    Knap k;
    k.initializeWeights();
    k.fillTable();
    return 0;
}