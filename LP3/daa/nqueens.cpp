#include<iostream>
using namespace std;

class Node{
    public:
     int r,c;
     Node(){
        r= c=0;
     }
};

class Stack{
    public:
        int top;
        Node *s[100];
        Stack(){
            top = -1;
            for(int i = 0;i<100;i++){
                s[i] = NULL;
            }
        }
        void push(Node *n);
        Node* pop();
};

void Stack :: push(Node *n){
    if(top < 99){
        top++;
        s[top] = n;
    }
}

Node* Stack :: pop(){
    if(top >= 0){
        int temp = top;
        top--;
        return s[temp];
    } else {
        return NULL;
    }
}

class Nqueen{
    public:
        int matsize,frow,fcol;
        int** mat;
        int *pd,*nd,*rows,*cols;
        Stack s;
        void initializeQueen();
        void setQueens();
        void printMat();
};

void Nqueen :: printMat(){
    cout<<"Matrix : "<<endl;
    for(int i = 0;i<matsize;i++){
        for(int j = 0;j<matsize;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void initarray(int *arr,int size){
    for(int i = 0;i<size;i++){
        arr[i] = 0;
    }
}

void Nqueen :: initializeQueen(){
    matsize = 4;
    mat = new int*[matsize];
    for(int i = 0;i<matsize;i++){
        mat[i] = new int[matsize];
    }
    for(int i = 0;i<matsize;i++){
        for(int j = 0;j<matsize;j++){
            mat[i][j] = 0;
        }
    }

    cout<<"Enter row : ";
    cin>>frow;
    cout<<"Enter column : ";
    cin>>fcol;

    pd = new int[matsize*2];
    initarray(pd,matsize*2);

    nd = new int[matsize*2];
    initarray(nd,matsize*2);

    rows = new int[matsize];
    initarray(pd,matsize);

    cols = new int[matsize];
    initarray(cols,matsize);

    nd[frow - fcol + matsize - 1] = 1;
    pd[frow + fcol] = 1;
    cols[fcol] = 1;
    rows[frow] = 1;
    mat[frow][fcol] = 1;
    printMat();
}

void Nqueen :: setQueens(){
    bool pushedonce = false;
    int i = 0,j=0;
    Node *temp;
    while(true){
        bool pushed = false;
        if(i != frow && i < matsize){
            while(j < matsize){
                if(cols[j] == 0 && pd[i + j] == 0 && nd[i - j + matsize -1] == 0){
                    temp = new Node();
                    temp->c = j;
                    temp->r = i;
                    // cout<<"pushed : "<<temp->r<<" "<<temp->c<<endl;
                    rows[i] = cols[j] = pd[i+j] = nd[i-j+matsize-1] = 1;
                    mat[i][j] = 1;
                    printMat();
                    s.push(temp);
                    pushed = true;
                    pushedonce = true;
                    break;
                }
                j++;
            }
        }

        if(s.top == matsize-2){
            printMat();
            break;
        }

        if(!pushed){
            temp = s.pop();
            // cout<<"poped : "<<endl;
            if(temp == NULL && pushedonce){
                cout<<"No combination possible"<<endl;
                break;
            }
            if(temp != NULL){
                // cout<<temp->r<<endl;
                i = temp->r;
                j = temp->c;
                // cout<<"Inside not null"<<endl;
                mat[i][j] = 0;
                printMat();
                rows[i] = cols[j] = pd[i+j] = nd[i-j+matsize-1] = 0;
                j++;
                continue;
            }
        }
        i++;
        if(i == frow) i++;
        j = 0;
    }
}

int main(){
    Nqueen q;
    q.initializeQueen();
    q.setQueens();
    return 0;
}