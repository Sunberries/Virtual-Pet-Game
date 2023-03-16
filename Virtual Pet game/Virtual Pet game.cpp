#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//Declare classes: customers (young ,pensioner, premium?), pets, other?

class Customer 
{
protected:
	string customerName;
	int age;
public:
	Customer(string nameIn, int ageIn);
	string getName() { return customerName; }
	int getAge() { return age; }
	void display();
};

Customer::Customer(string nameIn, int ageIn)
{
	customerName = nameIn;
	age = ageIn;
}

void Customer::display()
{
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
}

class Pet
{
protected:
	string petName;
	float mood;
	float energy;
	float hunger;
	float friendliness;
	float price;
	int popularity;
	char type;
public:
	Pet(string nameIn, char typeIn);
};

Pet::Pet(string nameIn, char typeIn)
{
	petName = nameIn;
	type = typeIn;
}

vector<Customer> customerList;

void createCustomer();

void displayMenu()
{
	cout << "Welcome, user! What would you like to do?" << endl << endl;
	cout << "Make a new customer (M)" << endl;
	cout << "Display customer list (D)" << endl;
	cout << "View pet details (V)" << endl;

	string input;

	cin >> input;

	if (input == "M" || input == "m") createCustomer();
}

void createCustomer()
{
	cout << "Please enter the customer's first name" << endl;
	string nameIn;
	int ageIn;

	cin >> nameIn;

	cout << "Please enter the customer's age" << endl;

	cin >> ageIn;

	cout << endl;

	Customer newCustomer(nameIn, ageIn);
	customerList.push_back(newCustomer);

	newCustomer.display();




}

int main()
{
	displayMenu();
}
