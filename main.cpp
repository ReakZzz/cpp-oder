#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


void CheckItems() {
	int id;
	double amount;
	string name;

	ifstream ItemsFile("./list/items.txt");

	cout << "--------[ITEMS LIST]--------" << endl;
	cout << "-> ID, Name, Amount" << endl;
	while (ItemsFile >> id >> name >> amount) {
		cout<< "-> "<< id << ", " << name << ", " << amount << "$" << endl;
	}
	cout << "----------------------------" << endl;
}

void OrderItems() {
	ifstream ItemsFile("./list/items.txt");

	int item_id, amount_item;
	double item_amount;
	string name, item_name;

	cout << "Enter item name or id: ";
	cin >> name; 
	cout << "Enter amount item: ";
	cin >> amount_item;

	bool item_found = false;


	while (ItemsFile >> item_id >> item_name >> item_amount) {
		if (name == item_name || name == to_string(item_id)) {
			item_found = true;
			cout << "----------------------" << endl;
			cout << "> Item found:\n";
			cout << "> ID: " << item_id << endl;
			cout << "> Name: " << item_name << endl;
			cout << "> Amount: " << item_amount * amount_item << "$" << endl;
			cout << "----------------------" << endl;
		}
	}

	if (!item_found) {
		cout << "Item not found\n";
		OrderItems();
	}
	ItemsFile.close();
}

void AllMenu() {
	int menu;
	cout << "----------------------" << endl;
	cout << "All Menu" << "\n 1, Oder Items" << "\n 2, Check Items" << "\n 3, Add more items" << endl;
	cout << "----------------------" << endl;
	cout << "Enter Menu: "; cin >> menu;
	switch (menu)
	{
	case 1:
		OrderItems();
		break;
	case 2:
		CheckItems();
		break;
	default:
		AllMenu();
		break;
	}
}

int main() {

	AllMenu();

	system("pause");
	return 0;

}