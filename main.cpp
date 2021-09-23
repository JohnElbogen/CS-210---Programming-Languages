//============================================================================
// Name        : CS210Project2.cpp
// Author      : John Elbogen
// Class	   : CS 210
// Version     : 1.0
// Copyright   : None
// Description : Airgead Banking App
//============================================================================

#include <iostream>
#include "AirgeadBankingApp.h"

using namespace std;

int main() {
	//BankingApp obj created
	BankingApp ba;

	//initial display
	ba.PrintData();
	ba.DisplayMenu();

	//shows menu until exit command
	ba.MenuChoice();

	return 0;
}
