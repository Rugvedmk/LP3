#include<iostream>
using namespace std;

int fibRecursive(int num){
    if(num <= 1) return 0;
    else if(num == 2) return 1;
    else {
        return fibRecursive(num-1) + fibRecursive(num-2);
    }
}

int iterative(int num){
    int n1,n2,n3;
    n1 = 0;
    n2 = 1;
    if(num <= 1) return 0;
    else if(num == 2) return 1;
    else {
        for(int i = 3;i<=num;i++){
            n3 = n2 + n1;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

int main(){
    // cout<<fibRecursive(7);

    for(int i = 1;i<=9;i++){
        cout<<iterative(i)<<endl;
    }
    return 0;
}