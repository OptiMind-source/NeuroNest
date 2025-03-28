#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsStudent.h"
#include "clsInputValidation.h"

class clsFindStudentScreen :protected clsScreen
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

    static void ShowFindStudentScreen()
    {

        _DrawScreenHeader("\t  Find Student Screen");

        string Stu_Id;
        cout << "\nPlease Enter Student Id: ";
        Stu_Id = clsInputValidate<string>::ReadString();
        while (!clsStudent::IsStudentExist(Stu_Id))
        {
            cout << "\nStudent is not found, choose another one: ";
            Stu_Id = clsInputValidate<string>::ReadString();
        }

        clsStudent Student1 = clsStudent::Find(Stu_Id);

        if (!Student1.IsEmpty())
        {
            cout << "\nStudent Found :-)\n";
        }
        else
        {
            cout << "\nStudent Was not Found :-(\n";
        }

        _PrintStudent(Student1);

    }

};
