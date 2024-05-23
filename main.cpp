#include <iostream>

using namespace std;

struct {
} variaveis;

// Funcao que imprimea mensagem de escolha
void opcaoUm(){
    cout << "Voce escolheu a opcao 1." << endl;
}
void opcaoDois(){
    cout << "Voce escolheu a opcao 2." << endl;    
}

void opcaoTres(){
    cout << "Voce escolheu a opcao 3." << endl;
}

int main(){
    int escolha;

    do{
        cout << "=== Menu ===" << endl;
        cout << "1. Opcao 1" << endl;
        cout << "2. Opcao 2" << endl;
        cout << "3. Opcao 3" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        // switch case para as opcoes do menu
        switch (escolha){
        case 1:
            opcaoUm();
            break;
        case 2:
            opcaoDois();
            break;
        case 3:
            opcaoTres();
            break;
        default:
            cout << "Opcao Invalida. Tente novamente." << endl;
            break;
        }
    }while(escolha != 4);
    return 0;
}