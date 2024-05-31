#include <iostream>

using namespace std;

int aa(int a, int& b){
    a++;
    b++;
    return a, b;
}

void teste(){
    int i = 1;
    int j = i;
    aa(i, j);
    cout << "valor de i: " << i << endl; 
    cout << "valor de j: " << j << endl; 
}

int main(){
    teste(); 
    return 0;
}