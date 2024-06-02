#include <iostream>

using namespace std;

int main(){
    cout << (char)201;
    for(size_t i = 0; i < 31; i++){
        cout << (char)205;
    }
    cout << (char)187 << endl;
    cout << (char)186 << "      Task Manager System      " << (char)186 << endl;
    cout << (char)186 << " 1. Add Tasks                  " << (char)186 << endl;
    cout << (char)186 << " 2. Show Tasks                 " << (char)186 << endl;
    cout << (char)186 << " 3. Edit Tasks                 " << (char)186 << endl;
    cout << (char)186 << " 4. Delete Tasks               " << (char)186 << endl;
    cout << (char)186 << " 5. Search Tasks               " << (char)186 << endl;
    cout << (char)186 << " 6. Filter Tasks by Status     " << (char)186 << endl;
    cout << (char)186 << " 0. Exit                       " << (char)186 <<endl;
    cout << (char)200;
    for(size_t i = 0; i < 31; i++){
        cout << (char)205;
    }
    cout << (char)188 << endl;
    cout << "Choose an option: "; 
    
    return 0;
}