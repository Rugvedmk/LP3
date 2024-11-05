#include<iostream>
#include<algorithm>
using namespace std;

// int weights[] =  {20,10,50,50};
// int profits[] = {100,60,100,200};

class Node{
    public:
        int weight,profit,id;
        float ratio;
        Node(){
            weight = profit = id = 0;
        }
};

class Fract{
    public:
        int tweights;
        int profit;
        int capacity;
        Node *nodes;
        void initializeWeights();
        void getMaxProfit();
};

bool compare(Node n1,Node n2){
    return n1.ratio > n2.ratio;
}

void Fract :: initializeWeights(){
    int weights[] =  {20,10,50,50};
    int profits[] = {100,60,100,200};
    capacity = 90;

    tweights = 4;
    nodes = new Node[4];
    for(int i = 0;i<tweights;i++){
        nodes[i].id = i+1;
        nodes[i].weight = weights[i];
        nodes[i].profit = profits[i];
        nodes[i].ratio = float(nodes[i].profit)/nodes[i].weight;
    }
    sort(nodes,nodes+tweights,compare);

    for(int i = 0;i<tweights;i++){
        cout<<nodes[i].id<<" : "<<nodes[i].ratio<<endl;
    }
}

void Fract :: getMaxProfit(){
    profit = 0;
    int curCapacity = capacity;
    int curNode = 0;
    while(curCapacity > 0 && curNode < tweights){
        if(curCapacity >= nodes[curNode].weight){
            profit += nodes[curNode].profit;
            curCapacity -= nodes[curNode].weight;
            curNode++;
        } else {
            profit += nodes[curNode].ratio*curCapacity;
            curCapacity = 0;
        }
    }
    cout<<"Max profit : "<<profit<<endl;
}

int main(){
    Fract f;
    f.initializeWeights();
    f.getMaxProfit();
    return 0;
}