#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCourse.h"
#include "clsInputValidation.h"
#include <iomanip>
#include "clsDate.h"


class clsAddCourseScreen : protected clsScreen
{

private:

    static void _ReadCourseInfo(clsCourse& Course)
    {
        cout << "\nEnter Subject: ";
        Course.Subject= clsInputValidate<string>::ReadString();

        cout << "\nEnter Price : ";
        Course.Price = clsInputValidate<float>::ReadNumber();

    }

    static void _PrintCourse(clsCourse Course)
    {
        cout << "\nCourse Card:";
        cout << "\n___________________";
        cout << "\nCode    : " << Course.Code();
        cout << "\nSubject : " << Course.Subject;
        cout << "\nPrice   : " << Course.Price;
        cout << "\n___________________\n";

    }

public:

    static void ShowAddNewCourseScreen()
    {

        _DrawScreenHeader("\t  Add New Course Screen");

        string Code = "";

        cout << "\nPlease Enter Course Code: ";
        Code = clsInputValidate<string>::ReadString();
        while (clsCourse::IsCourseExist(Code))
        {
            cout << "\nCourse Code Is Already Used, Choose another one: ";
            Code = clsInputValidate<string>::ReadString();
        }

        clsCourse NewCourse = clsCourse::GetAddNewCourseObject(Code);

        _ReadCourseInfo(NewCourse);

        clsCourse::enSaveResults SaveResult;

        SaveResult = NewCourse.Save();

        switch (SaveResult)
        {
        case  clsCourse::enSaveResults::svSucceeded:
        {
            cout << "\nCourse Addeded Successfully :-)\n";
            _PrintCourse(NewCourse);
            break;
        }
        case clsCourse::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Course was not saved because it's Empty";
            break;

        }
        case clsCourse::enSaveResults::svFaildUserExists:
        {
            cout << "\nError Course was not saved because Course_Id is used!\n";
            break;

        }
        }
    }



};
