#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsInputValidation.h"

class clsDeleteStudentScreen :protected clsScreen
{

private:
    static void _PrintStudent(clsStudent Student)
    {
        cout << "\nStudent Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Student.FullName();
        cout << "\nStu_Id      : " << Student.Id();
        cout << "\nEmail       : " << Student.Email;
        cout << "\nPhone       : " << Student.Phone;
        cout << "\nPassword    : " << Student.Password;
        cout << "\nBirth_Date  : " << Student.BirthDate;
        cout << "\nCountry     : " << Student.Country;
        cout << "\n___________________\n";

    }


public:
    static void ShowDeleteStudentScreen()
    {

        _DrawScreenHeader("\tDelete Student Screen");

        string Stu_Id = "";

        cout << "\nPlease Enter Student Id: ";
        Stu_Id = clsInputValidate<string>::ReadString();
        while (!clsStudent::IsStudentExist(Stu_Id))
        {
            cout << "\nStudent is not found, choose another one: ";
            Stu_Id = clsInputValidate<string>::ReadString();
        }

        clsStudent Student1 = clsStudent::Find(Stu_Id);
        _PrintStudent(Student1);

        cout << "\nAre you sure you want to delete this Student y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (Student1.Delete())
            {
                cout << "\nStudent Deleted Successfully :-)\n";
                _PrintStudent(Student1);
            }
            else
            {
                cout << "\nError Student Was not Deleted\n";
            }
        }
    }

};
