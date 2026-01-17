#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//Handbag

class Handbag {

private:
	string name;
	double price;

public:
	Handbag() {
		name = "";
		price = 0.0;
	}

	Handbag(string name, double price) {
		this->name = name;
		this->price = price;
	}

	string getName()
		const {
		return name;
	}
	double getPrice()
		const {
		return price;
	}
};


int main() {

	const int SIZE = 4;
	const double TAX_RATE = 0.06;

	//Menu of the Handbags

	Handbag menu[SIZE] = {
		Handbag("Classic tote", 25.99),
		Handbag("Crossbody bag", 34.99),
		Handbag("Leather Backpack", 49.99),
		Handbag("Travel Duffel", 99.99)
	};

	int quantities[SIZE] = { 0 };
	int choice;
	int qty;

	cout << "======== Handbags Ordering System=======" << endl;

	while (true) {
		cout << "Menu: " << endl;

		for (int i = 0; i < SIZE; i++) {
			cout << (i + 1) << ") " << menu[i].getName()<<" "
				<< "$" << fixed << setprecision(2) << menu[i].getPrice() << endl;
		}

		cout << "0)Checkout" << endl;

		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 0) {
			break;
		}

		if (choice<1 || choice>SIZE) {
			cout << "Invalid choice" << endl;
			continue;
		}

		cout << "Enter quantity: ";
		cin >> qty;

		if (qty <= 0) {
			cout << "Quantity must be more than 0" << endl;
			continue;
		}

		quantities[choice - 1] += qty;
		cout << "Added to cart" << endl;
	}
	double subtotal = 0.0;
	//Print recepit

	cout << "=====Receipt=====" << endl;

	for (int i = 0; i < SIZE; i++) {
		if (quantities[i] > 0) {
			double itemTotal = quantities[i] * menu[i].getPrice();
			subtotal += itemTotal;

			cout << quantities[i] << " x " << menu[i].getName()
				<< "$" << menu[i].getPrice() << "=$" << itemTotal << endl;
		}
	}

	if (subtotal == 0) {
		cout << "No items ordered" << endl;
		return -1;
	}

	double tax = subtotal * TAX_RATE;
	double total = subtotal + tax;

	cout << "--------------------------" << endl;
	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << total << endl;
	cout << "---------------------------" << endl;
	cout << "Thank your for your order" << endl;
	return 0;
}
