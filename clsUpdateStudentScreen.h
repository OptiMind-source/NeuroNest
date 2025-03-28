#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsStudent.h"
#include "clsInputValidation.h"

class clsUpdateStudentScreen :protected clsScreen

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
        Student.Country = clsInputValidate<string>::ReadString();

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

    static void ShowUpdateStudentScreen()
    {

        _DrawScreenHeader("\tUpdate Student Screen");

        string Stu_Id = "";

        cout << "\nPlease Enter Student Id: ";
        Stu_Id = clsInputValidate<string>::ReadString();

        while (!clsStudent::IsStudentExist(Stu_Id))
        {
            cout << "\nStudent Id is not found, choose another one: ";
            Stu_Id = clsInputValidate<string>::ReadString();
        }

        clsStudent Student1 = clsStudent::Find(Stu_Id);

        _PrintStudent(Student1);

        cout << "\nAre you sure you want to update this Student y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Student Info:";
            cout << "\n____________________\n";

            clsStudent CopyStudent = Student1;

            _ReadStudentInfo(Student1);

            short answer = 0;
            while (Student1.IsTheSame(CopyStudent) && answer!=2) 
            {
                cout << "\n\nNo Changes has commited :-)\n";
                cout << "Press [1] to Reupdate the student or [2] to contiue";
                 answer = clsInputValidate<short>::ReadNumberBetween(1,2);

                if(answer==1)
                    _ReadStudentInfo(Student1);
             
            }

            clsStudent::enSaveResults SaveResult;

            SaveResult = Student1.Save();

            switch (SaveResult)
            {
            case  clsStudent::enSaveResults::svSucceeded:
            {
                cout << "\nStudent Updated Successfully :-)\n";

                _PrintStudent(Student1);
                break;
            }
            case clsStudent::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Student was not saved because it's Empty";
                break;

            }

            }

        }

    }
};
