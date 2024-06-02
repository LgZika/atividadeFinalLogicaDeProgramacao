#include <iostream>
#include <vector>

using namespace std;

class Task{ // Classe Tasks que contém as informações de cada nota como objetos
    private: // private, apenas os objetos e métodos da classe podem acessar
        int id;
        string title, description, status, date;

    public: // public, pode ser acessado em qualquer escopo pelo objeto do tipo da classe
        Task(int id, string title, string description, string date, string status){ // função construtora da classe Task
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

        void setDate(string date){ // função set para informar valor para a data da tarefa
            this->date = date;
        }

        string getDate(){ // função get para retornar a data da tarefa
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
    string *date = new string;
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
    system("clear||cls");
} 

void editTask(vector<Task>& task){ // edita os atributos da tarefa indicada
    int *id = new int;
    bool *valid = new bool(false);
    int *choice = new int;
    string *str = new string;

    cout << "Enter the Task ID to edit it: ";
    cin >> *id;
    
    for(size_t i = 0; i < task.size(); ++i){ // percorre o vetor procurando pela task para editar
    	if(task[i].getId() == *id){
            cout << endl;
            cout << "ID: " << task[i].getId() << endl;
            cout << "Title: " << task[i].getTitle() << endl;
            cout << "Description: " << task[i].getDescription() << endl;
            cout << "Deadline: " << task[i].getDate() << endl;
            cout << "Status: " << task[i].getStatus() << endl;
            cout << endl;
            do{
                // menu padão da seção de edição
                cout << endl;
                cout << "What do you want to edit" << endl;
                cout << "1. Task Title" << endl;
                cout << "2. Task Description"<< endl;
                cout << "3. Task Deadline"<< endl;
                cout << "4. Task Status"<< endl;
                cout << "0. Exit Edit" << endl;
                cout << "Choose an option: "; 
                cin >> *choice;
                cout << endl;

                switch(*choice){
                    case 1:
                        cout << "Current title: " << task[i].getTitle() << endl;
                        cout << "Enter the new title: ";
                        cin.ignore();
                        getline(cin, *str);
                        task[i].setTitle(*str);
                        break;
                    case 2:
                        cout << "Current description: " << task[i].getDescription() << endl;
                        cout << "Enter the new description: ";
                        cin.ignore();
                        getline(cin, *str);
                        task[i].setDescription(*str);
                        break;
                    case 3: 
                        cout << "Current deadline: " << task[i].getDate() << endl;
                        cout << "Enter the new deadline: ";
                        cin >> *str;
                        task[i].setDate(*str);
                        break;
                    case 4: 
                        while(true){
                            cout << "Current status: " << task[i].getStatus() << endl;
                            cout << "Enter the new status (1 - Pending, 2 - In Progress, 3 - Completed): ";
                            cin.ignore();
                            cin >> *str;
                            if(*str == "1"){
                                task[i].setStatus("Pending");
                                break;
                            }else if(*str == "2"){
                                task[i].setStatus("In Progress");
                                break;
                            }else if(*str == "3"){
                                task[i].setStatus("Completed");
                                break;
                            }else{
                                cout << "Invalid Status!" << endl;
                            }
                        }
                        break;
                    case 0:
                        *valid = true;
                        break;
                    default: 
                        cout << "Invalid option. Try again." << endl; 
                        break;
                }
            }while(choice != 0);
        	break;
        }
	}
    if(*valid){
        cout << "Edited Successfully" << endl;
    }else{
        cout << "Edit Failed! Task not found." << endl;
    }
    delete id, valid, choice;
}

void deleteTask(vector<Task>& task){ // função para deletar a tarefa indicada
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
    delete id, valid;
}
void searchTask(vector<Task>& task){ // função para pesquisar tarefas por ID e Nome
    bool *valid = new bool(false);
    int *choice = new int;
    int *id = new int;
    string *title = new string;

    while(true){
        // menu padrão da função search
        cout << "Search for tasks by" << endl;
        cout << "1. Task ID" << endl;
        cout << "2. Task Title"<< endl;
        cout << "Choose a method: ";
        cin >> *choice;
    
        if(*choice == 1){ // pesquisa por ID
            cout << endl;
            cout << "Enter the ID to search: ";
            cin >> *id;
            for(size_t i = 0; i < task.size(); i++){
                if(task[i].getId() == *id){
                    cout << endl;
                    cout << "ID: " << task[i].getId() << endl;
                    cout << "Title: " << task[i].getTitle() << endl;
                    cout << "Description: " << task[i].getDescription() << endl;
                    cout << "Deadline: " << task[i].getDate() << endl;
                    cout << "Status: " << task[i].getStatus() << endl;
                    cout << endl;
                    system("pause");
                    *valid = true;
                }
            }
            break;
        }else if(*choice == 2){ // pesquisa por Título
            cout << "Enter the title to search: ";
            cin.ignore();
            getline(cin, *title);
            for(size_t i = 0; i < task.size(); i++){
                if(task[i].getTitle() == *title){
                    cout << endl;
                    cout << "ID: " << task[i].getId() << endl;
                    cout << "Title: " << task[i].getTitle() << endl;
                    cout << "Description: " << task[i].getDescription() << endl;
                    cout << "Deadline: " << task[i].getDate() << endl;
                    cout << "Status: " << task[i].getStatus() << endl;
                    cout << endl;
                    system("pause");
                    *valid = true;
                }
            }
            break;
        }else{
            cout << endl;
            cout << "Invalid method. Try again." << endl;
            cout << endl;
        }
    }
    if(!*valid){
        cout << "Task not found." << endl;
    }
    delete choice, valid, id, title;
}
void filterTask(vector<Task>& task){
    cout << "Voce escolheu a opcao 5." << endl;
}

int main(){
    vector<Task> task; // cria um vetor em que cada posição é um objeto da classe Task
    int *choice = new int;

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
        cin >> *choice;
        cout << endl;
        
        // switch case para as opcoes do menu
        switch (*choice){
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
    delete choice;
    return 0;
}