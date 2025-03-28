#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
//#include "clsCoursesListScreen.h"
//#include "clsAddCourseScreen.h"
//#include "clsDeleteCourseScreen.h"
//#include "clsUpdateCourseScreen.h"
//#include "clsFindCourseScreen.h"
using namespace std;

class clsCourseManagmentScreen : protected clsScreen
{

private:

	enum enCoursesManagmentOperations { sList = 1, sAdd = 2, sDelete = 3, sUpdate = 4, sFind = 5, sBack = 6 };

	static short _ReadOperationChoice()
	{
		short Choice = 0;
		cout << setw(37) << left << "" << "Please Enter Your Choice [1 - 6 ] : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 6);

		return Choice;
	}

	static void _BackToCoursesManagmentMenu()
	{
		cout << setw(37) << left << "" << "Press any key to go back to Courses Managment Menu Screen ....";
		system("pause >0");
		ShowCoursesManagmentScreen();

	}

	static void _ShowAddCourseScreen()
	{
		cout << "Add course screen will be here\n\n";
		//clsAddCourseScreen::ShowAddNewCourseScreen();

	}

	static void _ShowListCoursesScreen()
	{
		cout << "show courses list screen will be here\n\n";
		//clsCoursesListScreen::ShowCoursesList();

	}

	static void _ShowDeleteCourseScreen()
	{
		cout << "Delete course screen will be here\n\n";
		//clsDeleteCourseScreen::ShowDeleteCourseScreen();

	}

	static void _ShowUpdateCourseScreen()
	{
		cout << "Update course screen will be here\n\n";
		//clsUpdateCourseScreen::ShowUpdateCourseScreen();
	}

	static void _ShowFindCourseScreen()
	{
		cout << "Find course screen will be here\n\n";
		//clsFindCourseScreen::ShowFindCourseScreen();

	}

	static void _PerformCoursesManagmentOperations(enCoursesManagmentOperations Choice)
	{
		switch (Choice)
		{

		case clsCourseManagmentScreen::sList:
			system("cls");
			_ShowListCoursesScreen();
			_BackToCoursesManagmentMenu();
			break;
		case clsCourseManagmentScreen::sAdd:
			system("cls");
			_ShowAddCourseScreen();
			_BackToCoursesManagmentMenu();
			break;
		case clsCourseManagmentScreen::sDelete:
			system("cls");
			_ShowDeleteCourseScreen();
			_BackToCoursesManagmentMenu();
			break;
		case clsCourseManagmentScreen::sUpdate:
			system("cls");
			_ShowUpdateCourseScreen();
			_BackToCoursesManagmentMenu();
			break;
		case clsCourseManagmentScreen::sFind:
			system("cls");
			_ShowFindCourseScreen();
			_BackToCoursesManagmentMenu();
			break;
		case clsCourseManagmentScreen::sBack:
		{
			// doing nothing , it will handle in managment screen 
		}
		}


	}


public:

	static void ShowCoursesManagmentScreen()
	{

		system("cls");
		_DrawScreenHeader("\t   Courses Managment Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] List Courses.\n";
		cout << setw(37) << left << "" << "[2] Add Course.\n";
		cout << setw(37) << left << "" << "[3] Delete Course.\n";
		cout << setw(37) << left << "" << "[4] Update Course.\n";
		cout << setw(37) << left << "" << "[5] Find Course.\n";
		cout << setw(37) << left << "" << "[6] Back To Managment.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCoursesManagmentOperations(enCoursesManagmentOperations(_ReadOperationChoice()));
	}

};

