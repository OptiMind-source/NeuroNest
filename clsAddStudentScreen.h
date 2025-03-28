#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsStudent.h"
#include "clsInputValidation.h"
#include <iomanip>
#include "clsDate.h"


class clsAddStudentScreen : protected clsScreen
{
private:
    
    static string _ReadBirthData() 
    {
        string Date;
        Date = clsInputValidate<string>::ReadString();
        clsDate BirthDate(Date);

        while (!BirthDate.IsValid())
        {
            cout << "Data Entered unapproperatly , pleas enter date again in form dd/mm/yyyy : ";
            Date = clsInputValidate<string>::ReadString();
            clsDate BirthDate(Date);
        }

        return Date;

    }

    static void _ReadStudentInfo(clsStudent& Student)
    {
        cout << "\nEnter FirstName: ";
        Student.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter LastName: ";
        Student.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Gender : ";
        Student.Gender = clsInputValidate<char>::ReadChar();

        cout << "\nEnter BirthDate in form dd/mm/yyyy : ";
        Student.BirthDate = _ReadBirthData();

        cout << "\nEnter Email: ";
        Student.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone: ";
        Student.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter Balance : ";
        Student.Balance = clsInputValidate<double>::ReadNumber();

        cout << "\nEnter Country: ";
        Student.Country= clsInputValidate<string>::ReadString();

        cout << "\nEnter Password: ";
        Student.Password = clsInputValidate<string>::ReadString();

    }

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

    static void ShowAddNewStudentScreen()
    {

        _DrawScreenHeader("\t  Add New Student Screen");

        string Stu_Id = "";

        cout << "\nPlease Enter Stu_Id: ";
        Stu_Id = clsInputValidate<string>::ReadString();
        while (clsStudent::IsStudentExist(Stu_Id))
        {
            cout << "\nStu_Id Is Already Used, Choose another one: ";
            Stu_Id = clsInputValidate<string>::ReadString();
        }

        clsStudent NewStudent = clsStudent::GetAddNewStudentObject(Stu_Id);

        _ReadStudentInfo(NewStudent);

        clsStudent::enSaveResults SaveResult;

        SaveResult = NewStudent.Save();

        switch (SaveResult)
        {
        case  clsStudent::enSaveResults::svSucceeded:
        {
            cout << "\nStudent Addeded Successfully :-)\n";
            _PrintStudent(NewStudent);
            break;
        }
        case clsStudent::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Student was not saved because it's Empty";
            break;

        }
        case clsStudent::enSaveResults::svFaildUserExists:
        {
            cout << "\nError Student was not saved because Student_Id is used!\n";
            break;

        }
        }
    }



};
