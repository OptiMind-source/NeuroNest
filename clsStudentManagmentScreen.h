#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsStudentsListScreen.h"
#include "clsAddStudentScreen.h"
#include "clsDeleteStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsFindStudentScreen.h"
using namespace std;

class clsStudentManagmentScreen : protected clsScreen
{

private:

	enum enStudentsManagmentOperations { sList = 1 , sAdd = 2, sDelete = 3, sUpdate = 4, sFind = 5 , sBack = 6  };

	static short _ReadOperationChoice()
	{
		short Choice = 0;
		cout << setw(37) << left << "" << "Please Enter Your Choice [1 - 6 ] : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1,6);

		return Choice;
	}

	static void _BackToStudentsManagmentMenu()
	{
		cout << setw(37) << left << "" << "Press any key to go back to Students Managment Menu Screen ....";
		system("pause >0");
		ShowStudentsManagmentScreen();

	}

	static void _ShowAddStudentScreen() 
	{
		clsAddStudentScreen::ShowAddNewStudentScreen();

	}

	static void _ShowListStudentsScreen()
	{
		clsStudentsListScreen::ShowStudentsList();

	}

	static void _ShowDeleteStudentScreen()
	{
		clsDeleteStudentScreen::ShowDeleteStudentScreen();

	}

	static void _ShowUpdateStudentScreen()
	{
		clsUpdateStudentScreen::ShowUpdateStudentScreen();
	}

	static void _ShowFindStudentScreen()
	{
		clsFindStudentScreen::ShowFindStudentScreen();

	}

	static void _PerformStudentsManagmentOperations(enStudentsManagmentOperations Choice)
	{
		switch (Choice)
		{

		case clsStudentManagmentScreen::sList:
			system("cls");
			_ShowListStudentsScreen();
			_BackToStudentsManagmentMenu();
			break;
		case clsStudentManagmentScreen::sAdd:
			system("cls");
			_ShowAddStudentScreen();
			_BackToStudentsManagmentMenu();
			break;
		case clsStudentManagmentScreen::sDelete:
			system("cls");
			_ShowDeleteStudentScreen();
			_BackToStudentsManagmentMenu();
			break;
		case clsStudentManagmentScreen::sUpdate:
			system("cls");
			_ShowUpdateStudentScreen();
			_BackToStudentsManagmentMenu();
			break;
		case clsStudentManagmentScreen::sFind:
			system("cls");
			_ShowFindStudentScreen();
			_BackToStudentsManagmentMenu();
			break;
		case clsStudentManagmentScreen::sBack:
		{
			// doing nothing , it will handle in managment screen 
		}
		}
		

	}


public:

	static void ShowStudentsManagmentScreen() 
	{

		system("cls");
		_DrawScreenHeader("\t   Students Managment Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] List Students.\n";
		cout << setw(37) << left << "" << "[2] Add Student.\n";
		cout << setw(37) << left << "" << "[3] Delete Student.\n";
		cout << setw(37) << left << "" << "[4] Update Student.\n";
		cout << setw(37) << left << "" << "[5] Find Student.\n";
		cout << setw(37) << left << "" << "[6] Back To Managment.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformStudentsManagmentOperations(enStudentsManagmentOperations(_ReadOperationChoice()));
	}

};

