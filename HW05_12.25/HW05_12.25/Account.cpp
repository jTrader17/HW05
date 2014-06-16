#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
public:
	int year, month, day;
	Date(){
		year=2000;
		month=1;
		day=1;
	}
	Date (int a){ //seconds past Jan 1, 1970
		int x, y,z;
		x=a/(365*24*60*60);
		year= x+1970;
		y=a%(365*24*60*60);
		month=y/(30*24*60*60);
		z=y%(30*24*60*60);
		day=z/(24*60*60);
	}
	Date(int mm, int dd, int yyyy){
		month=mm;
		day=dd;
		year=yyyy;
	}
	int getDay(){
		return day;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return year;
	}
	void setDate(int elapsedTime){
		int x,y,z;
		x=elapsedTime/(365*24*60*60);
		year= x+year;
		y=elapsedTime%(365*24*60*60);
		month=y/(30*24*60*60);
		if (month>12){
			month-=12;
			year++;
		}
		z=y%(30*24*60*60);
		day=z/(24*60*60);
	}
};

class Transaction{
private:
	Date date;
	char type;
	double amount;
	double balance;
	string description;
public:
	double getAmount(){
		return amount;
	}
	char getType(){
		return type;
	}
	double getBalance(){
		return balance;
	}
	string getDescription(){
		return description;
	}
	Transaction(char type2, double amount2, double balance2, string description2){
		type=type2;
		amount=amount2;
		balance=balance2;
		description=description2;
	}
};
class Account{
private:
	int id;
	double balance;
	string name;
	static double annualInterestRate;
public:
	vector<Transaction> transactions;
	Account (){
		id=0;
		balance=0;
	}
	Account (int a, double b, string d){
		id=a;
		balance=b;
		name=d;
	}
	int getID(){
		return id;
	}
	void setID(int a){
		id=a;
	}
	double getBalance(){
		return balance;
	}
	void setBalance(double a){
		balance=a;
	}
	double getAnnualInterestRate(){
		return annualInterestRate;
	}
	void setAnnualInterestRate(double a){
		annualInterestRate=a;
	}
	double getMonthlyInterestRate(){
		return (annualInterestRate/12);
	}
	string getName(){
		return name;
	}
	void withdraw(double amount){
		balance=balance-amount;
		Transaction w('w',amount,balance,"withdrawl");
		transactions.push_back(w);
	}
	void deposit(double amount){
		balance=balance+amount;
		Transaction d('d',amount,balance,"deposit");
		transactions.push_back(d);
	}
};
double Account::annualInterestRate=1.5;

int main(){
	Account George(1122,1000,"George");
	George.deposit(30);
	George.deposit(40);
	George.deposit(50);
	George.withdraw(5);
	George.withdraw(4);
	George.withdraw(2);
	cout << "Account Summary: " << endl << "Name: " << George.getName() << endl << "Interest Rate: " << George.getAnnualInterestRate() << endl;
	cout << "Balance: " << George.getBalance() << endl;
	int z=George.transactions.size();
	for (int i=0; i<z; i++){
		cout << i+1 << ")" << endl << George.transactions[i].getDescription() << " $" << George.transactions[i].getAmount() << endl;
		cout << "Balance: " << George.transactions[i].getBalance() << endl << endl;
	}
	return 0;
}