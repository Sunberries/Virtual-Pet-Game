#include <iostream>
#include <string.h>
using namespace std;

//Declare classes: customers (young ,pensioner, premium?), pets, other?

class Customer 
{
protected:
	string customerName;
	string address;
	int age;
public:
	Customer(string name);
	string getCustomerName() { return customerName; }
};

Customer::Customer(string name)
{
	customerName = name;
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
};

int main()
{

	Customer newCustomer("Ro");

	cout << "customer's name is " << newCustomer.getCustomerName() << endl;
}
