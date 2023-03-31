#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <time.h>
#include <conio.h>
using namespace std;

//Declare classes: customers (young ,pensioner, premium?), pets, other?

class Customer 
{
protected:
	string customerName;
	string surname;
	string address;
	int age;
	float discount = 1.00;
	bool premium;
	float funds;
public:
	Customer(string nameIn, string surnameIn, int ageIn, string addressIn);
	string getName() { return customerName; }
	string getSurname() { return surname; }
	int getAge() { return age; }
	string getAddress() { return address; }
	bool hasPremium() { return premium; }
	void setPremium(bool valueIn) { premium = valueIn; }
	float getDiscount() { return discount; }
	void setFunds(float fundsIn) { funds = fundsIn; }
	float getFunds() { return funds; }
	void display();
};

Customer::Customer(string nameIn, string surnameIn, int ageIn, string addressIn)
{
	customerName = nameIn;
	surname = surnameIn;
	age = ageIn;
	address = addressIn;
	premium = false;
	funds = 100.00;
}

void Customer::display()
{
	cout << "Name: " << getName() << " " << getSurname() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Funds: " << funds << endl;
	cout << "Premium? " << premium << endl;
}

class YoungCustomer : public Customer
{
protected:
	float discount = 0.75;
public:
	void display();
};

class Pensioner : public Customer
{
protected:
	float discount = 0.50;
public:
	void display();
};

void YoungCustomer::display()
{
	cout << "Name: " << getName() << " " << getSurname() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Funds: " << funds << endl;
	cout << "Premium? " << premium << endl;

	cout << "As a young customer, pets can be purchased at a discount." << endl;
}

void Pensioner::display()
{
	cout << "Name: " << getName() << " " << getSurname() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Funds: " << funds << endl;
	cout << "Premium? " << premium << endl;

	cout << "As a pensioner, pets can be purchased at a discount." << endl;
}

class Pet
{
protected:
	string petName;
	float mood;
	float energy;
	float hunger;
	int friendliness;
	float price;
	int popularity;
	string type;
	string color;
	int id;
	string owner;
public:
	Pet(string nameIn, string typeIn, string colorIn, int popularityIn, int friendlinessIn);
	void setMood(float moodIn) { mood = moodIn; }
	float getMood() { return mood; }
	void setEnergy(float energyIn) { energy = energyIn; }
	float getEnergy() { return energy; }
	void setHunger(float hungerIn) { hunger = hungerIn; }
	float getHunger() { return hunger; }
	void setFriendliness(int friendlinessIn) { friendliness = friendlinessIn; }
	int getFriendliness() { return friendliness; }
	void setPopularity(int popularityIn) { popularity = popularityIn; }
	int getPopularity() { return popularity; }
	string getType() { return type; }
	string getColor() { return color; }
	void setName(string nameIn) { petName = nameIn; }
	string getName() { return petName; }
	void setId(int valueIn) { id = valueIn; }
	int getId() { return id; }

	void display();
};

Pet::Pet(string nameIn, string typeIn, string colorIn, int popularityIn, int friendlinessIn)
{
	
	petName = nameIn;
	type = typeIn;
	mood = 100;
	energy = 100;
	hunger = 0;
	color = colorIn;
	friendliness = friendlinessIn;
	popularity = popularityIn;
}

void Pet::display()
{
	cout << "Name: " << petName << endl;
	cout << "Species: " << type << endl;
	cout << "Colour: " << color << endl;
	cout << "Mood: " << mood << endl;
	cout << "Energy: " << energy << endl;
	cout << "Friendliness: " << friendliness << endl;
}

void buyPet(string nameIn);
void viewPets(string nameIn);
void viewSelf(string nameIn);
void interactWithPets(string nameIn);
void buyPremium(string nameIn);

void displayMenu(string nameIn)
{
	cout << "\033[2J\033[1;1H";
	
	cout << "Welcome, " << nameIn << "! What would you like to do?" << endl << endl;
	cout << "Buy a pet (B)" << endl;
	cout << "View pet details (V)" << endl;
	cout << "View customer details (C)" << endl;
	cout << "Interact with your pets (I)" << endl;
	cout << "Pay for premium (P)" << endl;


	string input;

	cin >> input;

	if (input == "b" || input == "B")
	{
		buyPet(nameIn);
	}
	if (input == "v" || input == "V")
	{
		viewPets(nameIn);
	}
	if (input == "C" || input == "c")
	{
		viewSelf(nameIn);
	}
	if (input == "i" || input == "I")
	{
		interactWithPets(nameIn);
	}
	if (input == "p" || input == "P")
	{
		buyPremium(nameIn);
	}
}

vector<Pet> petList;
vector<Customer> customerList;

void createCustomer()
{
	cout << "Hello new user! Welcome to CPlusPets!" << endl << endl;
	cout << "Please enter your first name" << endl;
	string nameIn;
	string surnameIn;
	int ageIn;
	string addressIn = "";

	cin >> nameIn;

	cout << "Please enter your surname" << endl;

	cin >> surnameIn;

	cout << "Please enter your age" << endl;

	cin >> ageIn;

	cout << "Please enter your address" << endl;

	cin.ignore();
	getline(cin, addressIn, '\n');

	cout << endl;

	if (ageIn < 18)
	{
		YoungCustomer::Customer newCustomer(nameIn, surnameIn, ageIn, addressIn);
	}
	else if (ageIn >= 60)
	{
		Pensioner::Customer newCustomer(nameIn, surnameIn, ageIn, addressIn);
	}
	Customer newCustomer(nameIn, surnameIn, ageIn, addressIn);
	customerList.push_back(newCustomer);

	string input;

	while (input != "Y" || input != "y")
	{
		cout << "\033[2J\033[1;1H";
		
		newCustomer.display();
		cout << "As a new customer you start with 100 funds." << endl;

		cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

		cin >> input;

		if (input == "Y" || input == "y")

		{
			cout << "\033[2J\033[1;1H";

			displayMenu(nameIn);
		}
	}


}

void buyCat(string nameIn);
void buyDog(string nameIn);
void buyBird(string nameIn);
void buyHamster(string nameIn);
void buyRabbit(string nameIn);


void buyPet(string nameIn)
{
	for (Customer newCustomer : customerList)
	{
		cout << "\033[2J\033[1;1H";

		if (petList.size() == 0)
		{
			string input;

			while (input != "c" || input != "C" || input != "d" || input != "D")
			{
				cout << "\033[2J\033[1;1H";
				cout << "Since you have no pets, the first pet is free!" << endl;
				cout << "You may choose either a Cat[C] or a Dog[D]" << endl;
				cin >> input;
				if (input == "C" || input == "c")
				{
					buyCat(nameIn);
				}
				if (input == "D" || input == "d")
				{
					buyDog(nameIn);
				}
			}
		}

		else if (petList.size() > 3 && newCustomer.hasPremium() == 0)
		{
			
			string input;

			while (input != "Y" || input != "y")
			{
				cout << "\033[2J\033[1;1H";

				cout << "Uh oh! Non-premium members can only have up to 3 pets! Either purchase premium or put a pet up for adoption!" << endl;
				cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

				cin >> input;

				if (input == "Y" || input == "y")

				{
					cout << "\033[2J\033[1;1H";

					displayMenu(nameIn);
				}
			}
		}

		else
		{
			string input;

			while (input != "b" || input != "B" || input != "c" || input != "C" || input != "d" || input != "D" || input != "h" || input != "H" || input != "r" || input != "R")
			{
				cout << "\033[2J\033[1;1H";
				cout << "You may buy: " << endl;
				cout << "A Bird (B)" << endl << "A Cat (C)" << endl << "A Dog (D)" << endl << "A Hamster (H)" << endl << "A Rabbit (R)" << endl;

				cin >> input;
				if (input == "C" || input == "c")
				{
					buyCat(nameIn);
				}
				if (input == "D" || input == "d")
				{
					buyDog(nameIn);
				}
				if (input == "B" || input == "b")
				{
					buyBird(nameIn);
				}
				if (input == "H" || input == "h")
				{
					buyHamster(nameIn);
				}
				if (input == "R" || input == "r")
				{
					buyRabbit(nameIn);
				}

			}

		}
	}
}

void buyCat(string nameIn)
{
	for (Customer newCustomer : customerList)
	{

		srand(time(NULL));
		cout << "\033[2J\033[1;1H";
		if (petList.size() == 0)
		{
			cout << "Since you have no pets, the first pet is free!" << endl;
		}
		string color[7] = { "brown", "black", "white", "calico", "tortoiseshell", "tuxedo", "tabby" };
		int color1 = rand() % 7;
		int color2 = rand() % 7;
		int color3 = rand() % 7;
		int friend1 = rand() % 100;
		int friend2 = rand() % 100;
		int friend3 = rand() % 100;
		int popularity = 50;
		float price1 = popularity * (color1 / 10 + 1) * (friend1 / 10 + 1) * newCustomer.getDiscount();
		float price2 = popularity * (color2 / 10 + 1) * (friend2 / 10 + 1) * newCustomer.getDiscount();
		float price3 = popularity * (color3 / 10 + 1) * (friend3 / 10 + 1) * newCustomer.getDiscount();

		cout << "If you were to define the abstract concept of 'popularity' on a scale of 1 to 100, cats have about " << popularity << " popularity." << endl << endl;
		
		cout << "The first cat is a very cute " << color[color1] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this cat's friendliness would be " << friend1 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This cat costs " << price1 << "funds." << endl << endl;
		}

		cout << "The second cat is a very cute " << color[color2] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this cat's friendliness would be " << friend2 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This cat costs " << price1 << "funds." << endl << endl;
		}

		cout << "The third cat is a very cute " << color[color3] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this cat's friendliness would be " << friend3 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This cat costs " << price1 << "funds." << endl << endl;
		}

		int input = 0;

		if (petList.size() == 0)
		{

			while (input != 1 || input != 2 || input != 3)
			{
				cout << "Which cat would you like to buy? [1-3]" << endl;
				cin >> input;

				if (input == 1 || input == 2 || input == 3)
				{
					cout << "What would you like to name your new cat?" << endl;
					string name = "";

					cin.ignore();
					getline(cin, name, '\n');

					if (input == 1)
					{
						Pet newPet(name, "cat", color[color1], popularity, friend1);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 2)
					{
						Pet newPet(name, "cat", color[color2], popularity, friend2);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 3)
					{
						Pet newPet(name, "cat", color[color3], popularity, friend3);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}

					string input;

					while (input != "Y" || input != "y")
					{
						cout << "\033[2J\033[1;1H";

						cout << "Congratulations on your new " << name << "!" << endl;
						cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

						cin >> input;

						if (input == "Y" || input == "y")

						{
							cout << "\033[2J\033[1;1H";

							displayMenu(nameIn);
						}
					}
				}
			}
		}
		else
		{
			while (input != 1 || input != 2 || input != 3)
			{
				cout << "Which cat would you like to buy? [1-3]" << endl;
				cin >> input;

				if (input == 1 || input == 2 || input == 3)
				{
					string name = "";


					if (input == 1 && newCustomer.getFunds() >= price1)
					{
						cout << "What would you like to name your new cat?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "cat", color[color1], popularity, friend1);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 2 && newCustomer.getFunds() >= price2)
					{
						cout << "What would you like to name your new cat?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "cat", color[color2], popularity, friend2);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 3 && newCustomer.getFunds() >= price3)
					{
						cout << "What would you like to name your new cat?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "cat", color[color3], popularity, friend3);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else
					{
						cout << "You can't afford this cat!" << endl;
			
						displayMenu(nameIn);
					}

					string input;

					while (input != "Y" || input != "y")
					{
						cout << "\033[2J\033[1;1H";

						cout << "Congratulations on your new " << name << "!" << endl;
						cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

						cin >> input;

						if (input == "Y" || input == "y")

						{
							cout << "\033[2J\033[1;1H";

							displayMenu(nameIn);
						}
					}
				}
			}
		}
	}
}

void buyDog(string nameIn)
{
	for (Customer newCustomer : customerList)
	{

		srand(time(NULL));
		cout << "\033[2J\033[1;1H";
		if (petList.size() == 0)
		{
			cout << "Since you have no pets, the first pet is free!" << endl;
		}
		string color[5] = { "brown", "black", "white", "gold", "silver" };
		int color1 = rand() % 5;
		int color2 = rand() % 5;
		int color3 = rand() % 5;
		int friend1 = rand() % 100;
		int friend2 = rand() % 100;
		int friend3 = rand() % 100;
		int popularity = 60;
		float price1 = popularity * (color1 / 10 + 1) * (friend1 / 10 + 1) * newCustomer.getDiscount();
		float price2 = popularity * (color2 / 10 + 1) * (friend2 / 10 + 1) * newCustomer.getDiscount();
		float price3 = popularity * (color3 / 10 + 1) * (friend3 / 10 + 1) * newCustomer.getDiscount();

		cout << "If you were to define the abstract concept of 'popularity' on a scale of 1 to 100, dogs have about " << popularity << " popularity." << endl << endl;

		cout << "The first dog is a very cute " << color[color1] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this dog's friendliness would be " << friend1 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This dog costs " << price1 << "funds." << endl << endl;
		}

		cout << "The second dog is a very cute " << color[color2] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this dog's friendliness would be " << friend2 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This dog costs " << price1 << "funds." << endl << endl;
		}

		cout << "The third dog is a very cute " << color[color3] << " kitty." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this dog's friendliness would be " << friend3 << "." << endl << endl;
		if (petList.size() != 0)
		{
			cout << "This dog costs " << price1 << "funds." << endl << endl;
		}

		int input = 0;

		if (petList.size() == 0)
		{

			while (input != 1 || input != 2 || input != 3)
			{
				cout << "Which dog would you like to buy? [1-3]" << endl;
				cin >> input;

				if (input == 1 || input == 2 || input == 3)
				{
					cout << "What would you like to name your new dog?" << endl;
					string name = "";

					cin.ignore();
					getline(cin, name, '\n');

					if (input == 1)
					{
						Pet newPet(name, "dog", color[color1], popularity, friend1);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 2)
					{
						Pet newPet(name, "dog", color[color2], popularity, friend2);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 3)
					{
						Pet newPet(name, "dog", color[color3], popularity, friend3);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}

					string input;

					while (input != "Y" || input != "y")
					{
						cout << "\033[2J\033[1;1H";

						cout << "Congratulations on your new " << name << "!" << endl;
						cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

						cin >> input;

						if (input == "Y" || input == "y")

						{
							cout << "\033[2J\033[1;1H";

							displayMenu(nameIn);
						}
					}
				}
			}
		}
		else
		{
			while (input != 1 || input != 2 || input != 3)
			{
				cout << "Which dog would you like to buy? [1-3]" << endl;
				cin >> input;

				if (input == 1 || input == 2 || input == 3)
				{
					string name = "";


					if (input == 1 && newCustomer.getFunds() >= price1)
					{
						cout << "What would you like to name your new dog?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "dog", color[color1], popularity, friend1);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 2 && newCustomer.getFunds() >= price2)
					{
						cout << "What would you like to name your new dog?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "dog", color[color2], popularity, friend2);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else if (input == 3 && newCustomer.getFunds() >= price3)
					{
						cout << "What would you like to name your new dog?" << endl;

						cin.ignore();
						getline(cin, name, '\n');

						Pet newPet(name, "dog", color[color3], popularity, friend3);
						newPet.setId(petList.size());
						petList.push_back(newPet);
					}
					else
					{
						cout << "You can't afford this dog!" << endl;
		
						displayMenu(nameIn);
					}

					string input;

					while (input != "Y" || input != "y")
					{
						cout << "\033[2J\033[1;1H";

						cout << "Congratulations on your new " << name << "!" << endl;
						cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

						cin >> input;

						if (input == "Y" || input == "y")

						{
							cout << "\033[2J\033[1;1H";

							displayMenu(nameIn);
						}
					}
				}
			}
		}
	}
}

void buyBird(string nameIn)
{
	for (Customer newCustomer : customerList)
	{

		srand(time(NULL));
		cout << "\033[2J\033[1;1H";

		string color[5] = { "parrot", "parakeet", "cockatiel", "macaw", "dove" };
		int color1 = rand() % 5;
		int color2 = rand() % 5;
		int color3 = rand() % 5;
		int friend1 = rand() % 100;
		int friend2 = rand() % 100;
		int friend3 = rand() % 100;
		int popularity = 30;
		float price1 = popularity * (color1 / 10 + 1) * (friend1 / 10 + 1) * newCustomer.getDiscount();
		float price2 = popularity * (color2 / 10 + 1) * (friend2 / 10 + 1) * newCustomer.getDiscount();
		float price3 = popularity * (color3 / 10 + 1) * (friend3 / 10 + 1) * newCustomer.getDiscount();

		cout << "If you were to define the abstract concept of 'popularity' on a scale of 1 to 100, birds have about " << popularity << " popularity." << endl << endl;
		
		cout << "The first bird is a very cute " << color[color1] << "." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this bird's friendliness would be " << friend1 << "." << endl;
		cout << "This bird costs " << price1 << "funds." << endl << endl;

		cout << "The second bird is a very cute " << color[color2] << "." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this bird's friendliness would be " << friend2 << "." << endl;
		cout << "This bird costs " << price2 << "funds." << endl << endl;

		cout << "The third bird is a very cute " << color[color3] << "." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this bird's friendliness would be " << friend3 << "." << endl;
		cout << "This bird costs " << price3 << "funds." << endl << endl;

		int input = 0;

		while (input != 1 || input != 2 || input != 3)
		{
			cout << "Which bird would you like to buy? [1-3]" << endl;
			cin >> input;

			if (input == 1 || input == 2 || input == 3)
			{
				string name = "";


				if (input == 1 && newCustomer.getFunds() >= price1)
				{
					cout << "What would you like to name your new bird?" << endl;
					
					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "bird", color[color1], popularity, friend1);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 2 && newCustomer.getFunds() >= price2)
				{
					cout << "What would you like to name your new bird?" << endl;
					
					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "bird", color[color2], popularity, friend2);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 3 && newCustomer.getFunds() >= price3)
				{
					cout << "What would you like to name your new bird?" << endl;
					
					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "bird", color[color3], popularity, friend3);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else
				{
					cout << "You can't afford this bird!" << endl;
		
					displayMenu(nameIn);
				}

				string input;

				while (input != "Y" || input != "y")
				{
					cout << "\033[2J\033[1;1H";

					cout << "Congratulations on your new " << name << "!" << endl;
					cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

					cin >> input;

					if (input == "Y" || input == "y")

					{
						cout << "\033[2J\033[1;1H";

						displayMenu(nameIn);
					}
				}
			}
		}
	}
}
void buyHamster(string nameIn)
{
	for (Customer newCustomer : customerList)
	{

		srand(time(NULL));
		cout << "\033[2J\033[1;1H";

		string color[5] = { "gold", "brown", "black", "white", "silver" };
		int color1 = rand() % 5;
		int color2 = rand() % 5;
		int color3 = rand() % 5;
		int friend1 = rand() % 100;
		int friend2 = rand() % 100;
		int friend3 = rand() % 100;
		int popularity = 30;
		float price1 = popularity * (color1 / 10 + 1) * (friend1 / 10 + 1) * newCustomer.getDiscount();
		float price2 = popularity * (color2 / 10 + 1) * (friend2 / 10 + 1) * newCustomer.getDiscount();
		float price3 = popularity * (color3 / 10 + 1) * (friend3 / 10 + 1) * newCustomer.getDiscount();

		cout << "If you were to define the abstract concept of 'popularity' on a scale of 1 to 100, hamsters have about " << popularity << " popularity." << endl << endl;

		cout << "The first hamster is a very cute " << color[color1] << " hamster." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this hamster's friendliness would be " << friend1 << "." << endl;
		cout << "This hamster costs " << price1 << "funds." << endl << endl;

		cout << "The second hamster is a very cute " << color[color2] << " hamster." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this hamster's friendliness would be " << friend2 << "." << endl;
		cout << "This hamster costs " << price2 << "funds." << endl << endl;

		cout << "The third hamster is a very cute " << color[color3] << " hamster." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this hamster's friendliness would be " << friend3 << "." << endl;
		cout << "This hamster costs " << price3 << "funds." << endl << endl;

		int input = 0;

		while (input != 1 || input != 2 || input != 3)
		{
			cout << "Which hamster would you like to buy? [1-3]" << endl;
			cin >> input;

			if (input == 1 || input == 2 || input == 3)
			{
				string name = "";


				if (input == 1 && newCustomer.getFunds() >= price1)
				{
					cout << "What would you like to name your new hamster?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "hamster", color[color1], popularity, friend1);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 2 && newCustomer.getFunds() >= price2)
				{
					cout << "What would you like to name your new hamster?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "hamster", color[color2], popularity, friend2);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 3 && newCustomer.getFunds() >= price3)
				{
					cout << "What would you like to name your new hamster?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "hamster", color[color3], popularity, friend3);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else
				{
					cout << "You can't afford this hamster!" << endl;
		
					displayMenu(nameIn);
				}

				string input;

				while (input != "Y" || input != "y")
				{
					cout << "\033[2J\033[1;1H";

					cout << "Congratulations on your new " << name << "!" << endl;
					cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

					cin >> input;

					if (input == "Y" || input == "y")

					{
						cout << "\033[2J\033[1;1H";

						displayMenu(nameIn);
					}
				}
			}
		}
	}
}
void buyRabbit(string nameIn)
{
	for (Customer newCustomer : customerList)
	{

		srand(time(NULL));
		cout << "\033[2J\033[1;1H";

		string color[5] = { "gold", "brown", "black", "white", "silver" };
		int color1 = rand() % 5;
		int color2 = rand() % 5;
		int color3 = rand() % 5;
		int friend1 = rand() % 100;
		int friend2 = rand() % 100;
		int friend3 = rand() % 100;
		int popularity = 30;
		float price1 = popularity * (color1 / 10 + 1) * (friend1 / 10 + 1) * newCustomer.getDiscount();
		float price2 = popularity * (color2 / 10 + 1) * (friend2 / 10 + 1) * newCustomer.getDiscount();
		float price3 = popularity * (color3 / 10 + 1) * (friend3 / 10 + 1) * newCustomer.getDiscount();

		cout << "If you were to define the abstract concept of 'popularity' on a scale of 1 to 100, rabbits have about " << popularity << " popularity." << endl << endl;

		cout << "The first rabbit is a very cute " << color[color1] << " rabbit." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this rabbit's friendliness would be " << friend1 << "." << endl;
		cout << "This rabbit costs " << price1 << "funds." << endl << endl;

		cout << "The second rabbit is a very cute " << color[color2] << " rabbit." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this rabbit's friendliness would be " << friend2 << "." << endl;
		cout << "This rabbit costs " << price2 << "funds." << endl << endl;

		cout << "The third rabbit is a very cute " << color[color3] << " rabbit." << endl;
		cout << "If you were to define the abstract concept of 'friendliness' on a scale of 1 to 100, this rabbit's friendliness would be " << friend3 << "." << endl;
		cout << "This rabbit costs " << price3 << "funds." << endl << endl;

		int input = 0;

		while (input != 1 || input != 2 || input != 3)
		{
			cout << "Which rabbit would you like to buy? [1-3]" << endl;
			cin >> input;

			if (input == 1 || input == 2 || input == 3)
			{
				string name = "";


				if (input == 1 && newCustomer.getFunds() >= price1)
				{
					cout << "What would you like to name your new rabbit?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "rabbit", color[color1], popularity, friend1);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 2 && newCustomer.getFunds() >= price2)
				{
					cout << "What would you like to name your new rabbit?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "rabbit", color[color2], popularity, friend2);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else if (input == 3 && newCustomer.getFunds() >= price3)
				{
					cout << "What would you like to name your new rabbit?" << endl;

					cin.ignore();
					getline(cin, name, '\n');

					Pet newPet(name, "rabbit", color[color3], popularity, friend3);
					newPet.setId(petList.size());
					petList.push_back(newPet);
				}
				else
				{
					cout << "You can't afford this rabbit!" << endl;
			
					displayMenu(nameIn);
				}

				string input;

				while (input != "Y" || input != "y")
				{
					cout << "\033[2J\033[1;1H";

					cout << "Congratulations on your new " << name << "!" << endl;
					cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

					cin >> input;

					if (input == "Y" || input == "y")

					{
						cout << "\033[2J\033[1;1H";

						displayMenu(nameIn);
					}
				}
			}
		}
	}
}

void viewPets(string nameIn)
{
	if (petList.size() == 0)
	{

		string input;

		while (input != "Y" || input != "y")
		{
			cout << "\033[2J\033[1;1H";
			cout << "You have no pets! Go buy one! The first one is free!" << endl;
			cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

			cin >> input;

			if (input == "Y" || input == "y")

			{
				cout << "\033[2J\033[1;1H";

				displayMenu(nameIn);
			}
		}
	}

	else
	{
		for (Pet newPet : petList)
		{
			newPet.display();
			cout << endl;
		}

		string input;

		while (input != "Y" || input != "y")
		{
			cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

			cin >> input;

			if (input == "Y" || input == "y")

			{
				cout << "\033[2J\033[1;1H";

				displayMenu(nameIn);
			}
		}
	}
}

void viewSelf(string nameIn)
{
	cout << "\033[2J\033[1;1H";
	
	for (Customer newCustomer : customerList)
	{
		newCustomer.display();
		cout << endl;
	}

	string input;

	while (input != "Y" || input != "y")
	{
		cout << endl << "Would you like to return to the menu? (Y/N)" << endl;

		cin >> input;

		if (input == "Y" || input == "y")

		{
			cout << "\033[2J\033[1;1H";

			displayMenu(nameIn);
		}
	}
}

void buyPremium(string nameIn)
{
	cout << "\033[2J\033[1;1H";

	for (Customer newCustomer : customerList)
	{
		string input;

		if (newCustomer.hasPremium() == 1)
		{
			cout << "You already have premium!" << endl;
			displayMenu(nameIn);
		}
		else
		{

			while (input != "y" || input != "Y" || input != "n" || input != "N")
			{
				cout << "Premium allows you to buy more than three pets! But it costs 1000 funds!" << endl;
				cout << "Would you like to pay for premium? [Y/N]" << endl;

				if ((input == "y" || input == "Y") && newCustomer.getFunds() >= 1000)
				{
					newCustomer.setPremium(1);
					cout << "You now have premium!" << endl;
			
					displayMenu(nameIn);
				}
				else if ((input == "y" || input == "Y") && newCustomer.getFunds() < 1000)
				{
					cout << "You don't have enough for premium!" << endl;
			
					displayMenu(nameIn);
				}
				else if (input == "n" || input == "N")
				{
					displayMenu(nameIn);
				}
			}
		}
	}
}

void interactWithPets(string nameIn)
{
	cout << "\033[2J\033[1;1H";
	
	

		for (Pet newPet : petList)
		{

			cout << "This is your beloved " << newPet.getName() << ". Their mood is currently " << newPet.getMood() << ". They currently have " << newPet.getEnergy() << " energy. They have " << newPet.getHunger() << " hunger." << endl << endl;
			
		}
		
		string strinput;

		while (strinput != "i" || strinput != "I" || strinput != "w" || strinput != "W" || strinput != "m" || strinput != "M")
		{
			cout << "Would you like to interact with your pets (I), wait a day (W), or go back to the menu (M)?" << endl;

			cin >> strinput;

			if (strinput == "i" || strinput == "I")
			{
				
				int input = 0;

				while (input < 1 || input > petList.size())
				{
					cout << "Which pet would you like to interact with? [1 - " << petList.size() << "]" << endl;

					cin >> input;

					for (Pet newPet : petList)
					{
						for (Customer newCustomer : customerList)
						{
							if (input == newPet.getId() + 1)
							{
								string strinput;

								while (strinput != "p" || strinput != "P" || strinput != "f" || strinput != "F")
								{
									cout << "You currently have " << newCustomer.getFunds() << " funds." << endl;
									cout << "Would you like to play with your pet (P) or feed your pet (F)? (Feeding costs 10 funds)" << endl;

									cin >> strinput;

									
									if ((strinput == "p" || strinput == "P") && newPet.getEnergy() <= 0)
									{
										cout << newPet.getName() << " has no more energy to play." << endl;
									
										interactWithPets(nameIn);
									}
									else if ((strinput == "f" || strinput == "F") && newPet.getHunger() == 0)
									{
										cout << newPet.getName() << " is not hungry." << endl;
									
										interactWithPets(nameIn);
									}
									else if ((strinput == "f" || strinput == "F") && newPet.getHunger() > 0 && newCustomer.getFunds() >= 10)
									{
										newPet.setHunger(newPet.getHunger() - 50);
										if (newPet.getHunger() < 0) newPet.setHunger(0);
										newPet.setEnergy(newPet.getEnergy() + 50);
										if (newPet.getEnergy() > 100) newPet.setEnergy(100);
										cout << "You feed " << newPet.getName() << ". Their hunger is now " << newPet.getHunger() << ". Their energy is now " << newPet.getEnergy() << "." << endl;
								
										interactWithPets(nameIn);
									}
									else if ((strinput == "f" || strinput == "F") && newPet.getHunger() > 0 && newCustomer.getFunds() < 10)
									{
										cout << "You can't afford the pet food!" << endl;
				
										interactWithPets(nameIn);
									}
									else if ((strinput == "p" || strinput == "P") && newPet.getEnergy() > 0)
									{
										newPet.setMood(newPet.getMood() + 25);
										if (newPet.getMood() > 100) newPet.setMood(100);
										newPet.setEnergy(newPet.getEnergy() - 50);
										if (newPet.getEnergy() < 0) newPet.setEnergy(0);
										int random = rand() % newPet.getFriendliness();
										newCustomer.setFunds(newCustomer.getFunds() + random);
										cout << "You play with " << newPet.getName() << ". Their mood is now " << newPet.getMood() << ". Their energy is now " << newPet.getEnergy() << endl;
										cout << "It looks like " << newPet.getName() << " found " << random << " funds while playing!" << endl;
										interactWithPets(nameIn);
									}
								}
							}
						}
					}
				}
			}
			else if (strinput == "w" || strinput == "W")
			{
				for (Pet newPet : petList)
				{
					newPet.setMood(newPet.getMood() - 50);
					if (newPet.getMood() < 0) newPet.setMood(0);
					newPet.setEnergy(100);
					newPet.setHunger(newPet.getHunger() + 50);
					if (newPet.getHunger() > 100) newPet.setHunger(100);
				}

				cout << "Another day passes..." << endl;
				interactWithPets(nameIn);
			}

			else if (strinput == "m" || strinput == "M")
			{
				displayMenu(nameIn);
			}
		}
}

int main()
{
	createCustomer();
}
