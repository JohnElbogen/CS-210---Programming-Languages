/*
 * AirgeadBankingApp.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: John Elbogen
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>

#include "AirgeadBankingApp.h"

using namespace std;

//gets input and returns an initial amount
double BankingApp::GetInitAmt(){

	//while loop makes sure data entered matches correct data type
	//ex. user enteres initial value as "hello", prints error and
	//requests another cin.
	//Used in all Get Functions.

	while(cout << "Enter initial amount: " && !(cin >> *initAmtPtr)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Entry, Try Again" << endl;
	}

	return *initAmtPtr;
}

//gets input and returns a monthly deposit amount
double BankingApp::GetMonthlyDep(){
	while(cout << "Enter monthly deposit amount: " && !(cin >> *monthlyDepPtr)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Entry, Try Again" << endl;
	}

	return *monthlyDepPtr;
}

//gets input and returns annual interest rate
double BankingApp::GetAnnualInterest(){

	while(cout << "Enter annual interest rate: " && !(cin >> *annualInterestPtr)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Entry, Try Again" << endl;
	}

	return *annualInterestPtr;
}

//gets input and returns number of years
int BankingApp::GetNumYears(){

	while(cout << "Enter number of years: " && !(cin >> *numYearsPtr)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Entry, Try Again" << endl;
	}
	return *numYearsPtr;
}

//displays menu
void BankingApp::DisplayMenu(){
	cout << "Select from the following: \n"
			"1: Change initial amount \n"
			"2: Change monthly deposit \n"
			"3: Change annual interest rate \n"
			"4: Change number of years \n"
			"5: Display reports \n"
			"E: to exit \n";
}

//prints current user initial values
void BankingApp::PrintData(){
	cout << setprecision(2) << fixed << "Initial Investment Amount:  $" << *initAmtPtr << endl;
	cout << setprecision(2) << fixed << "Monthly Deposit:  $" << *monthlyDepPtr << endl;
	cout << setprecision(2) << fixed << "Annual Interest:  %" << *annualInterestPtr << endl;
	cout << "Number of Years:  " << *numYearsPtr << endl << endl;
}

//displays reports with user values from printdata()
void BankingApp::DisplayReports(){

	double depositedAmt = *monthlyDepPtr;
	double interestRate = *annualInterestPtr;
	double interestEarned;
	double accountBal;
	int numYears = *numYearsPtr;

	//Starting account balance
	accountBal = *initAmtPtr;
	//header text
	cout << "Balance and Interest without Additional Monthly Deposits\n"
			"````````````````````````````````````````````````````````````````\n"
			"Year	Year End Balance	Year End Earned Interest\n"
			"````````````````````````````````````````````````````````````````\n";
	//loops for selected number of years chosen
	for (int year = 1; year <= numYears; ++year){
		//Initializes interested earned start value
		interestEarned = 0;
		//calculates year end balance and year end earned interest
		interestEarned = accountBal * (interestRate/100);
		accountBal = accountBal + interestEarned;
		//formatting
		cout << left
			 << setw(8) << year << "$"
			 << setw(23) << accountBal << "$"
			 << setw(20) << interestEarned << endl;

	}
	//Resets starting account balance
	accountBal = *initAmtPtr;

	cout << endl;
	//header text
	cout << "Balance and Interest with Additional Monthly Deposits\n"
			"````````````````````````````````````````````````````````````````\n"
			"Year	Year End Balance	Year End Earned Interest\n"
			"````````````````````````````````````````````````````````````````\n";
	//loops for selected number of years chosen
	for (int year = 1; year <= numYears; ++year){
		//resets interest calculation for each year
		interestEarned = 0;
		//loop to calculate interest each month
		for (int i = 0; i < 12; ++i){
			interestEarned = interestEarned + (accountBal + depositedAmt) * (interestRate/100/12);
			accountBal = (accountBal + depositedAmt) * (1 + interestRate/100/12);
		}
		//formating
		cout << left
			 << setw(8) << year << "$"
			 << setw(23) << accountBal << "$"
			 << setw(20) << interestEarned << endl;
	}
	cout << endl;
}
//menu to select what to edit
void BankingApp::MenuChoice(){
	char choice;
	cin >> choice;
	while (choice != 'e' && choice != 'E'){
			//clears screen on each loop
			switch(choice){
				case '1':
					GetInitAmt();
					system("CLS");
					break;
				case '2':
					GetMonthlyDep();
					system("CLS");
					break;
				case '3':
					GetAnnualInterest();
					system("CLS");
					break;
				case '4':
					GetNumYears();
					system("CLS");
					break;
				case '5':
					system("CLS");
					DisplayReports();
					break;
				default:
					cout << "Invalid entry, please try again";

			}
			//re-displays settings and menu options
			PrintData();
			DisplayMenu();
			cin >> choice;
		};
}
