#include <iostream>
#include <vector>

using namespace std;

class Item{
public:
	string name;
	int quantity;
    
	Item(string n, int q) : name(n), quantity(q) {}
};

void printItems(const vector<Item>& items) {
	for(size_t i = 0; i < items.size(); ++i) {
    	cout << "Item: " << items[i].name << ", Quantity: " << items[i].quantity << endl;
	}
}

void addItem(vector<Item>& items, const string& name, int quantity) {
	items.push_back(Item(name, quantity));
}

void removeItem(vector<Item>& items, const string& name) {
	for (size_t i = 0; i < items.size(); ++i) {
    	if (items[i].name == name) {
        	items.erase(items.begin() + i);
        	break;
    	}
	}
}

int main() {
	vector<Item> inventory;
	string name;
	int quantity;
	int choice;

	do {
    	cout << "Inventory Management System" << endl;
    	cout << "1. Add Item" << endl;
    	cout << "2. Remove Item" << endl;
    	cout << "3. List Items" << endl;
    	cout << "4. Exit" << endl;
   	 	cout << "Enter your choice: ";
    	cin >> choice;

   	 	switch(choice){
        	case 1:
            	cout << "Enter item name: ";
            	cin >> name;
            	cout << "Enter item quantity: ";
            	cin >> quantity;
            	addItem(inventory, name, quantity);
            	break;
        	case 2:
            	cout << "Enter item name to remove: ";
            	cin >> name;
            	removeItem(inventory, name);
            	break;
        	case 3:
            	printItems(inventory);
            	break;
        	case 4:
            	cout << "Exiting program." << endl;
            	break;
        	default:
            	cout << "Invalid choice. Try again." << endl;
            	break;
    		}
	}while(choice != 4);
	return 0;
}