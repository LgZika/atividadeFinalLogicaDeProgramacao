#include <iostream>
#include <vector>

using namespace std;

class Task{ // Classe Tasks que contém as informações de cada nota como objetos
    private: // private, apenas os objetos e métodos da classe podem acessar
        int id, date;
        string title, description, status;

    public: // public, pode ser acessado em qualquer escopo pelo objeto do tipo da classe
        Task(int id, string title, string description, int date, string status){ // função construtora da classe Task
            this->id = id; 
            this->title = title;
            this->description = description;
            this->date = date;
            this->status = status;
            // usa-se "this->" para indicar qual é a variável da classe e qual a variável da função
        }
        // Notes(int id, string t, string d, int dma, string s) : id(id), title(t), description(d), date(dma), status(s) {}

        void setId(int id){ // função set para informar novo valor para o ID da tarefa
            this->id = id;
        }

        int getId(){ // função get para retonar o id da tarefa
            return id;
        }

        void setDate(int date){ // função set para informar valor para a data da tarefa
            this->date = date;
        }

        int getDate(){ // função get para retornar a data da tarefa
            return date;
        }

        void setDescription(string description){ // função set para informar a descrição da tarefa
            this->description = description;
        }

        string getDescription(){ // função get para retornar a descrição da tarefa
            return description;
        }

        void setTitle(string title){ // funções get e set para title
            this->title = title;
        }  

        string getTitle(){ // função get para retornar o titulo da tarefa
            return title;
        }

        void setStatus(string status){ // função set para informa o status da tarefa
            this->status = status;
        }

        string getStatus(){ // função get para retornar o status da tarefa
            return status;
        }
};

void createTask(vector<Task>& task){ // função para adicionar tarefas
    int *id = new int(task.size());
    int *date = new int;
    string *title = new string;
    string *description = new string;
    string *status = new string;

    cout << "Add new Task" << endl;
    cout << "ID: " << *id << endl;

    cout << "Title: ";
    cin.ignore();
    getline(cin, *title);

    cout << "Description: ";
    getline(cin, *description);

    cout << "Deadline: ";
    cin >> *date;

    while(true){
        cout << "Status (1 - Pending, 2 - In Progress, 3 - Completed): ";
        cin >> *status;
        if(*status == "1"){
            *status = "Pending";
            break;
        }else if(*status == "2"){
            *status = "In Progress";
            break;
        }else if(*status == "3"){
            *status = "Completed";
            break;
        }else{
            cout << "Invalid Status!" << endl;
        }
    }
    cout << "Task added successfully!" << endl;

    task.push_back(Task(*id, *title, *description, *date, *status)); // Insere os valores dos atributos do objeto por meio da 
                                                                         // função construtora da classe
    delete id, date, title, description, status;
}
void editTask(vector<Task>& task){
    cout << "Voce escolheu a opcao 2." << endl;    
}

void deleteTask(vector<Task>& task){
    int *id = new int;
    bool *valid = new bool(false);

    cout << "Enter the Task ID to delete it: ";
    cin >> *id;

    for(size_t i = 0; i < task.size(); ++i){ // percorre o vetor procurando pela task para excluir
    	if(task[i].getId() == *id){
        	task.erase(task.begin() + i); // exclui a tarefa solicitada
            for(size_t j = *id; j < task.size(); ++j){ // manipula e organiza os ID's das tarefas no vetor
                task[j].setId(j);
            }
            *valid = true;
        	break;
        }
	}
    
    if(*valid){
        cout << "Deleted Successfully" << endl;
    }else{
        cout << "Delete Failed! Task not found." << endl;
    }

    delete id;
}
void searchTask(vector<Task>& task){
    cout << "Voce escolheu a opcao 4." << endl;
}
void filterTask(vector<Task>& task){
    cout << "Voce escolheu a opcao 5." << endl;
}


void showTask(vector<Task>& task){ // função para exibir as tarefas
    for(size_t i = 0; i < task.size(); ++i){
        cout << "ID: " << task[i].getId() << endl;
        cout << "Title: " << task[i].getTitle() << endl;
        cout << "Description: " << task[i].getDescription() << endl;
        cout << "Deadline: " << task[i].getDate() << endl;
        cout << "Status: " << task[i].getStatus() << endl;
        cout << endl;
    }
    system("pause");
}

int main(){
    vector<Task> task; // cria um vetor em que cada posição é um objeto da classe Task
    int choice;

    do{ 
        // Exibição de menu padrão no terminal
        cout << endl;
        cout << "Task Manager System" << endl;
        cout << "1. Add Tasks" << endl;
        cout << "2. Show Tasks "<< endl;
        cout << "3. Edit Tasks "<< endl;
        cout << "4. Delete Tasks" << endl;
        cout << "5. Search Tasks" << endl;
        cout << "6. Filter Tasks by Status" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: "; 
        cin >> choice;
        cout << endl;
        
        // switch case para as opcoes do menu
        switch (choice){
            case 0: return false; break;
            case 1: createTask(task); break;
            case 2: showTask(task); break;
            case 3: editTask(task); break;
            case 4: deleteTask(task); break;
            case 5: searchTask(task); break;
            case 6: filterTask(task); break;
            default: cout << "Invalid option. Try again." << endl; break;
        }
    }while(true);
    return 0;
}