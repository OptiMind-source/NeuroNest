#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsStudentManagmentScreen.h"
#include "clsCoursesMangamentScreen.h"
using namespace std;

class clsManagmentScreen :protected clsScreen
{
private:
	enum enManagmentOperations { Student = 1, Course= 2 , Trainer = 3 ,General = 4 ,Main = 5  };

	static short _ReadOperationChoice()
	{
		short Choice = 0;
		cout << setw(37) << left << "" << "Please Enter Your Choice [1 - 5 ] : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1,5);

		return Choice;
	}

	static void _BackToManagmentMenu()
	{
		cout << setw(37) << left << "" << "Press any key to go back to Managment Menu Screen ....";
		system("pause >0");
		ShowManagmentScreen();

	}

	static void  _ShowStudentsManagmentScreeen()
	{
		clsStudentManagmentScreen::ShowStudentsManagmentScreen();

	}
	
	static void  _ShowCoursesManagmentScreeen()
	{
		clsCourseManagmentScreen::ShowCoursesManagmentScreen();

	}

	static void  _ShowTrainersManagmentScreeen()
	{
		cout << "\n\Trainers Managment screen will be here\n\n ";

	}

	static void  _ShowGeneralScreeen()
	{
		cout << "\n\nGenerals screen will be here\n\n ";

	}

	static void _PerformManagmentOperations(enManagmentOperations Choice)
	{
		switch (Choice)
		{
		case clsManagmentScreen::Student:
			system("cls");
			_ShowStudentsManagmentScreeen();
			_BackToManagmentMenu();
			break;
		case clsManagmentScreen::Course:
			system("cls");
			_ShowCoursesManagmentScreeen();
			_BackToManagmentMenu();
			break;
		case clsManagmentScreen::Trainer:
			system("cls");
			_ShowTrainersManagmentScreeen();
			_BackToManagmentMenu();
			break;
		case clsManagmentScreen::General:
			system("cls");
			_ShowGeneralScreeen();
			_BackToManagmentMenu();
			break;
		case clsManagmentScreen::Main:
		{

			//doing nothing will handle it 
		}

		}

	}

public :
	static void ShowManagmentScreen() 
	{
		system("cls");
		_DrawScreenHeader("\t     Managment Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] Students Managment.\n";
		cout << setw(37) << left << "" << "[2] Courses Managment.\n";
		cout << setw(37) << left << "" << "[3] Trainers Managment.\n";
		cout << setw(37) << left << "" << "[4] Generals.\n";
		cout << setw(37) << left << "" << "[5] Back To Main.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		
		_PerformManagmentOperations(enManagmentOperations(_ReadOperationChoice()));

	}
};

