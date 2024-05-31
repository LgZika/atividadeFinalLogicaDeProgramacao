#include <iostream>
#include <vector>

using namespace std;

struct var{
};

class Task{ //Classe notas que contém as informações de cada nota como objetos
private: // private, apenas a classe pode acessar
    int idTask, date;
    string title, description, status;

public: // public, pode ser acessado em qualquer escopo
    // Notes(int id, string t, string d, int dma, string s) : idTask(id), title(t), description(d), date(dma), status(s) {}
    Task(int idTask, string title, string description, int date, string status){
        this->idTask = idTask; // usa-se "this->" para indicar qual é a variável da classe e qual a variável da função
        this->title = title;
        this->description = description;
        this->date = date;
        this->status = status;
    }
    
    // função get para idTask
    int getIdTask(){
        return idTask;
    }

    // funções get e set para date
    void setDate(int date){
        this->date = date;
        }
    int getDate(){
        return date;
    }

    // funções get e set para descrption
    void setDescription(string description){
        this->description = description;
        }
    string getDescription(){
        return description;
    }

    // funções get e set para title
    void setTitle(string title){
        this->title = title;
        }
    string getTitle(){
        return title;
    }

    // funções get e set para status
    void setStatus(string status){
        this->status = status;
        }
    string getStatus(){
        return status;
    }
};

void createTask(vector<Task>& task){
    int *idTask = new int;
    int *date = new int;
    string *title = new string;
    string *description = new string;
    string *status = new string;

    cout << "Id: ";
    cin >> *idTask;
    cout << "Title: ";
    cin >> *title;
    cout << "Description: ";
    cin >> *description;
    cout << "Date: ";
    cin >> *date;
    cout << "Status: ";
    cin >> *status;

    task.push_back(Task(*idTask, *title, *description, *date, *status));

    delete idTask, date, title, description, status;
}
void editTask(){
    cout << "Voce escolheu a opcao 2." << endl;    
}
void deleteTask(){
    cout << "Voce escolheu a opcao 3." << endl;
}
void searchTask(){
    cout << "Voce escolheu a opcao 4." << endl;
}
void filterTask(){
    cout << "Voce escolheu a opcao 5." << endl;
}
int main(){
    vector<Task> data;

    // data.push_back(Task(1, "Trabalho01", "tem que ser feito", 1092004,"fazendo"));
    // data.push_back(Notes("Mundo"));

    createTask(data);

    cout << data[0].getIdTask() << endl;
    cout << data[0].getTitle() << endl;
    cout << data[0].getDescription() << endl;
    cout << data[0].getDate() << endl;
    cout << data[0].getStatus() << endl;

/*
    int choice;

    do{
        cout << "=== Menu ===" << endl;
        cout << "1. Opcao 1" << endl;
        cout << "2. Opcao 2" << endl;
        cout << "3. Opcao 3" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        // switch case para as opcoes do menu
        switch (choice){
            case 1: opcaoUm(); break;
            case 2: opcaoDois(); break;
            case 3: opcaoTres(); break;
            default: cout << "Opcao Invalida. Tente novamente." << endl; break;
        }
    }while(choice != 6);
    */
    return 0;
}
