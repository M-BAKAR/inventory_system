#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct inventory_data {
	string name;
	string id;
	string category;
};
void add_inventory_item()
{
    inventory_data a[100];
    int inventory_No;
    cout << "\t\t\tEnter the count of items you want to added  : ";
    cin >> inventory_No;
    cout << endl;
    for (int i = 0; i < inventory_No; i++)
    {
        ofstream output("inventroy_item_data.txt", ios::app);
		if (!output)
		{
			cout << "File Error..." << endl;
			exit(0);
		}

        cout << "Enter the name  : ";
        cin.ignore();
        getline(cin, a[i].name);
        output << a[i].name << "\n";
        cout << "Enter the id  : ";
        cin >> a[i].id;
        output << a[i].id << "\n";
        cout << "Enter the category : ";
        cin.ignore();
        cin >> a[i].category;
        output << a[i].category << "\n";
        
        cout << endl;
    }
}
void search_inventory_record(int x) {
	inventory_data a[100];
	int i = 0, opt = 0;
	ifstream output("inventroy_item_data.txt");
	if (!output)
	{
		cout << "File Error..." << endl;
		exit(0);
	}
	cin.ignore();
	string name;
	cout << "Enter the name of item whose data you want = ";
	getline(cin, name);
	cout << endl;
	while (output) {
		getline(output, a[x].name);
		getline(output, a[x].id);
		getline(output, a[x].category);
		x++;
	}
	for (int i = 0; i < x; i++)
	{
		if (a[i].name == name)
		{
			cout << "\t\t\tDetail of your required item : \n";
			cout << "\t\t\t=================================\n";
			cout << "\t\t\tName of item  is = ";
			cout << a[i].name << endl;
			cout << "\t\t\tId of item is = ";
			cout << a[i].id << endl;
			cout << "\t\t\tCategory of item is = ";
			cout << a[i].category << endl;
			cout << endl;
			opt++;
		}
	}
	if (opt == 0)
		cout << "No item Found!" << endl;
}
void delete_data(int c) {
	inventory_data a[100];
	int i = 0, n = 0, a2 = 0;
	cin.ignore();
	string name2;
	cout << "Enter the item name whose data you want to delete : ";
	getline(cin, name2);
	ifstream outputDelete("inventroy_item_data.txt");
	if (!outputDelete)
	{
		cout << "File Error..." << endl;
		exit(0);
	}
	while (!outputDelete.eof()) {
		getline(outputDelete, a[c].name);
		getline(outputDelete, a[c].id);
		getline(outputDelete, a[c].category);
		c++;
		n++;
	}
	outputDelete.close();
	for (int i = 0; i < n; i++)
	{
		if (a[i].name == name2)
		{
			a2 = i;
			cout << "Name: " << a[i].name << endl;
			cout << "ID: " << a[i].id << endl;
			cout << "Category : " << a[i].category << endl;
			cout << "This Record Is Deleted!!!";
			n--;
		}
	}

	ofstream inputDelete("inventroy_item_data.txt");
	if (!inputDelete)
	{
		cout << "File Error..." << endl;
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		if (i != a2)
		{
			inputDelete << a[i].name << "\n";
			inputDelete << a[i].id << "\n";
			inputDelete << a[i].category<< "\n";
			
		}
	}
	inputDelete.close();
	cout << endl;
}
void edit_inventroy_item(int x) {
	inventory_data a[100];
	inventory_data data;
	string id;
	int i = 0, count = 0;
	cin.ignore();
	cout << "Enter the id of item whose data you want to update : ";
	getline(cin, id);
	cout << "Now enter the new data\n";
	cout << "Enter the name  : ";
	getline(cin, data.name);
	cout << "Enter the id : ";
	getline(cin, data.id);
	cout << "Enter the category : ";
	getline(cin, data.category);
	ifstream outputDelete("inventroy_item_data.txt");
	if (!outputDelete)
	{
		cout << "File Error..." << endl;
		exit(0);
	}
	while (outputDelete)
	{
		getline(outputDelete, a[x].name);
		getline(outputDelete, a[x].id);
		getline(outputDelete, a[x].category);
		x++;
	}
	outputDelete.close();
	ofstream inputDelete("inventroy_item_data.txt");
	if (!inputDelete)
	{
		cout << "File Error..." << endl;
		exit(0);
	}
	for (int i = 0; i < x; i++)
	{
		if (a[i].id == id)
		{
			inputDelete << data.name << "\n";
			inputDelete << data.id << "\n";
			inputDelete << data.category << "\n";
		}
		else
		{
			inputDelete << a[i].name << "\n";
			inputDelete << a[i].id << "\n";
			inputDelete << a[i].category << "\n";
			

		}
	}
	inputDelete.close();
	cout << "\n";
	cout << "Record Updated Sucessfully!\n";
}

void view_all_items(int  x) {
	inventory_data a[100];
	ifstream output("inventroy_item_data.txt");
	int i = 0;

	while (output) {

		getline(output, a[x].name);
		getline(output, a[x].id);
		getline(output, a[x].category);


		x++;
	}
	for (int i = 0; i < x-1; i++)
	{
		cout << "Name of item = " << a[i].name << endl;
		cout << "Id of item = " << a[i].id << endl;
		cout << "Category of item = " << a[i].category;
		cout << endl;

	}
	output.close();
}

int main() {
	inventory_data a[100];
	int num, x = 0, c;
	string choice, name1;
	do {
		cout << endl;
		cout << "\t\t\tINVENTORY  MANAGEMENT  SYSTEM \n";
		cout << "\t\t\t*****************************\n\n";
		cout << "\t\tPress 1 : To enter the data of item." << endl;
		cout << "\t\tPress 2 : To search item data by name." << endl;
		cout << "\t\tPress 3 : To delete the item data." << endl;
		cout << "\t\tPress 4 : To edit the items data." << endl;
		cout << "\t\tPress 5 : To view all items." << endl;
		cout << "\t\tPress 6 : To exit the program." << endl << endl;
		cout << "\tEnter your choise : ";
		cin >> num;
		cout << endl;
		if (num == 1) {
			ofstream input("inventroy_item_data.txt", ios::app);
			add_inventory_item();
			cout << endl;
			system("cls");
		}
		if (num == 2) {
			ifstream output("inventroy_item_data.txt");
			search_inventory_record(x);
			cout << endl;
		}
		if (num == 3) {
			ifstream input("inventroy_item_data.txt");
			delete_data(x);
			cout << endl;
		}
		if (num == 4) {
			ofstream input("inventroy_item_data.txt", ios::app);
			edit_inventroy_item(x);
			cout << endl;

		}
		if (num == 5) {
			ofstream inputDelete("inventroy_item_data.txt", ios::app);
			view_all_items(x);
			cout << endl;
		}
		if (num == 6) {
			system("cls");
			break;
		}

	} while (num != 6);

}
