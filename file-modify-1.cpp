#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void showMenu(); // function declaration

// controlling the file pointer
// use tellg() to get and use tellp() to put position in file
// seekg(parameter: position) & seekp(parameter: position)
// seekg to find position & seekp to put data in that position
// return parameter is "streampos type"

class Product
{
public: // specifier
	char p_name[30];
	char p_id[10];
	//		char p_category[30];
	//		int p_qty;
	char p_type[15];
	int credit;

public:
	void addProduct()
	{
		cout << "Input product name: ";
		cin >> p_name;
		cout << "Input product ID: ";
		cin >> p_id;
		cout << "Input product type (Gold, Silver, Ordinary): ";
		cin >> p_type;

		if (p_type == "Gold" || p_type == "Silver")
		{
			cout << "Enter Credit Point: ";
			cin >> credit;
		}
		else
		{
			credit == 0; // if Ordinary
		}
	}
	void showProduct()
	{
		cout << p_name << " " << p_id << " " << p_type << " " << credit << endl;
	}
	void modify() // read & write operation
	{
		char new_name[30];
		char new_type[15];
		int newCredit;
		cout << "Enter new data\n";
		cout << "Input new product name";
		cin >> new_name;
		cout << "Input new product type";
		cin >> new_type;
		if (strcmp(new_type, "Gold") == 0 || strcmp(new_type, "Silver") == 0) // strcmp >> string compare
																			  // strcmp return >> zero, greater than zero, last than zero
		{
			cout << "Enter new credit point: ";
			cin >> newCredit;
		}
		else
		{
			newCredit = 0;
		}
		// source	//destination
		strcpy(p_name, new_name); // strcpy >> string copy // modify
		strcpy(p_type, new_type);
		credit = newCredit;
	}
};

void showMenu()
{
	cout << "---------- Main Menu ----------" << endl;
	cout << "Choose 1 to add new product to the file" << endl;
	cout << "Choose 2 to modify product to the file" << endl;			 // read & write >> fstream
	cout << "Choose 3 to display product details from the file" << endl; // read operation >> ifstream
	cout << "Choose 4 to exit process" << endl;
}

int main()
{
	Product P; // create object
	int choice;
	char ans;
	showMenu();
	cout << "Choose the option(1-4): ";
	cin >> choice;

	do
	{
		if (choice == 1)
		{
			ofstream outfile("PRODUCT_E.txt", ios::app); // create file

			if (outfile.is_open())
			{
				do // add operation
				{
					P.addProduct(); // data assign into P object
					outfile.write((char *)&P, sizeof(P));
					cout << "Record added to the file" << endl;
					cout << "Would you like to add more(y/n): ";
					cin >> ans;
				} while (ans == 'y' || ans == 'Y');
				outfile.close();
			}
			else
			{
				cout << "File is not opened!";
			}
		}
		else if (choice == 2)
		{
			char n_id[10];
			bool found = false;
			cout << "Enter product ID that you want to modify: ";
			cin >> n_id;
			fstream file("PRODUCT_E.txt", ios::in | ios::out);
			if (file.is_open())
			{
				while (file.read((char *)&P, sizeof(P)))
				{
					if (strcmp(P.p_id, n_id) == 0)
					{
						P.showProduct();
						P.modify();

						// seekp >> put operation
						file.seekp(file.tellg() - std::streamoff(sizeof(P)), ios::beg);
						// ios::beg >> at the beginning of the file

						file.write((char *)&P, sizeof(P));
						found = true;
						cout << "Successfully modified!!";
						break; // out of looping
					}
					if (found == false)
					{
						cout << "Not found ID";
					}
				}
			}
			else
			{
				cout << "File Open Failed";
			}
		}
		else if (choice == 3)
		{
			ifstream infile("PRODUCT_E.txt");
			if (infile.is_open())
			{
				while (infile.read((char *)&P, sizeof(P)))
				{
					P.showProduct();
				}
				infile.close();
			}
			else
			{
				cout << "File is not opened at reading operation.";
			}
		}
		else if (choice == 4)
		{
			cout << "Process Exit!";
			exit(0);
		}
		else
		{
		}
		cout << "Do you want to continue(1-4)?" << endl;
		showMenu();
		cin >> choice;
	} while (choice >= 1 && choice <= 4);

	return 0;
}
