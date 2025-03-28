#pragma once
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsManagmentScreen.h"
#include <iostream>
#include <iomanip>
using namespace std;

class clsMainMenuScreen :protected clsScreen
{
private:

	enum enMainMenuOperations { Enroll = 1 , Manage = 2 };

	static short _ReadOperationChoice() 
	{ 
		short Choice=0;
		cout << setw(37) << left << "" << "Please Enter Your Choice [1 - 2 ] : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1,2);
		
		return Choice;
	}

	static void _BackToMainMenu() 
	{
		cout << setw(37) << left << "" << "Press any key to go back to Main Menu ....";
		system("pause >0");
		ShowMainMenuScreen();

	}

	static void _ShowEnrollmentScreen() 
	{
		cout << "\n\nEnrollment Screen Will Be Here ...\n\n\n";
	}

	static void _ShowManagmentScreen()
	{
		clsManagmentScreen::ShowManagmentScreen();
	}

	static void _PerformMainMenuOperations(enMainMenuOperations Choice) 
	{
		switch (Choice)
		{
		case clsMainMenuScreen::Enroll:
			system("cls");
			_ShowEnrollmentScreen();
			_BackToMainMenu();
			break;
		case clsMainMenuScreen::Manage:
			system("cls");
			_ShowManagmentScreen();
			_BackToMainMenu();
			break;

		}

	}

public:

	static void ShowMainMenuScreen() 
	{
		system("cls");
		system("color E0");
		_DrawScreenHeader("\t     NeuroNest","A cozy place for brain growth.");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n\n";
		cout << setw(37) << left << "" << "   [1] Enrollment.";
		cout << "" << "\t    [2] Managment.\n\n\n";
		_PerformMainMenuOperations(enMainMenuOperations(_ReadOperationChoice()));

	}

};
	
