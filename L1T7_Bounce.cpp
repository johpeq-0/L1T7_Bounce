#include <iostream>
#include <iomanip> /* Input Output Manipulation
 Needed to fix whitespace problem. Makes it possible to adjust size of
the stream */
using namespace std;

void welcome_message()
{
	cout << "This program prints all numbers between 0 and n, first\n";
	cout << "in descending and then in ascending order.\n";
}

int get_value_of_n_from_user()
{
	int n;
	cout << "Enter a value for n: ";
	cin >> setw(1) >> n; //Only one argument allowed

	//Checks if the user has made a correct imput.
	while (cin.good() == false) //Can also be written !cin.good()
	{
		//Clears the stream
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect input. Only numberals allowed. \n";
		cout << "Enter a value for n: ";
		cin >> setw(1) >> n; //Only one argument allowed
	}
	//Clears the stream
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return n;
}

int check_if_n_is_negative(int number)
{
	if (number < 0)
	{
		cout << "n can not be a negetive number.\n";
		number = get_value_of_n_from_user();
		int num = check_if_n_is_negative(number);
		return num;
	}
	return number;
}

void print_bounce(int num)
{
	int d = num;
	while (d >= -num)
	{
		int e = abs(d);
		cout << e << endl;
		d--;
	}
}

int main()
{
	welcome_message();
	int number = get_value_of_n_from_user();
	int num = check_if_n_is_negative(number);
	print_bounce(num);
	cin.get();  /* This makes the program pause. A recommended alternative to
				System("pause"). */
	return 0;
}