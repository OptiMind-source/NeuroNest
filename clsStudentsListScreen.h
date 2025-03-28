#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsStudent.h"
#include <iomanip>

class clsStudentsListScreen :protected clsScreen
{

private:

    static void _PrintStudentRecordLine(clsStudent Student)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << Student.Id();
        cout << "| " << setw(25) << left << Student.FullName();
        cout << "| " << setw(12) << left << Student.Phone;
        cout << "| " << setw(20) << left << Student.Email;
        cout << "| " << setw(10) << left << Student.Password;
        cout << "| " << setw(12) << left << Student.Gender;
        cout << "| " << setw(20) << left << Student.BirthDate;
        cout << "| " << left << setw(20) << Student.Country;
    }

public:

    static void ShowStudentsList()
    {
        vector <clsStudent> vStudents = clsStudent::GetStudentsData();

        string Title = "\t  Students List Screen";
        string SubTitle = "\t    (" + to_string(vStudents.size()) + ") Student(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "__________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Stu_Id";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Gender";
        cout << "| " << left << setw(20) << "Birth_Date";
        cout << "| " << left << setw(20) << "Country";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "__________________________________________________________________________________\n" << endl;

        if (vStudents.size() == 0)
            cout << "\t\t\t\tNo Students Available In the System!";
        else

            for (clsStudent Student : vStudents)
            {

                _PrintStudentRecordLine(Student);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "__________________________________________________________________________________\n" << endl;
    }

};
