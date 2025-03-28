#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsCourse : public clsScreen
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, NewMode = 2 };

	string _Code;
	float _Price;
	string _Subject;
	enMode _Mode;
	bool _MarkForDelete = false;

	static clsCourse _ConvertLineToCoureRecord(string Line)
	{
		vector<string> vCourse = clsString::Split(Line, "#//#");

		return clsCourse(enMode::UpdateMode, vCourse[0], vCourse[1], stod(vCourse[2]));

	}

	static clsCourse _GetEmptyCouresObject()
	{
		return clsCourse(enMode::EmptyMode, "", "", 0);

	}

	static string _ConvrtCourseRecordToLine(clsCourse Course,string Seperator="#//#")
	{
		string strCourse="";
		strCourse += Course.Code() + Seperator;
		strCourse += Course.Subject + Seperator;
		strCourse += Course.Price;

		return strCourse;
	}

	static vector<clsCourse> _LoadCoursesData() 
	{
		vector<clsCourse> vCourses;

		fstream myfile;
		myfile.open("Courses.txt", ios::in);
		if (myfile.is_open()) 
		{
			string Line = "";
			while (getline(myfile, Line)) 
			{
				vCourses.push_back(_ConvertLineToCoureRecord(Line));

			}

			myfile.close();
		}
		return vCourses;
	}

	static void _SaveDataToFile(vector<clsCourse> vCourses)
	{
		fstream myfile;
		myfile.open("Courses.txt", ios::out);

		if (myfile.is_open()) 
		{
			for (clsCourse& Course : vCourses) 
			{
				myfile << _ConvrtCourseRecordToLine(Course)<<"\n";

			}
			myfile.close();
		}

	}

public:

	clsCourse(enMode Mode, string Code, string Subject, float Price)
	{
		_Mode = Mode;
		_Code = Code;
		_Subject = Subject;
		_Price = Price;
	}


	//Property Get
	string Code()
	{
		return _Code;
	}

	//Property Set
	void SetSubject(string Subject)
	{
		_Subject = Subject;
	}

	//Property Get
	string GetSubject()
	{
		return _Subject;
	}
	__declspec(property(get = GetSubject, put = SetSubject)) string Subject;


	//Property Set
	void SetPrice(float Price)
	{
		_Price = Price;
	}

	//Property Get
	float GetPrice()
	{
		return _Price;
	}
	__declspec(property(get = GetPrice, put = SetPrice)) float Price;

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;

	}

	static clsCourse Find(string Code)
	{
		fstream myfile;
		myfile.open("Courses.txt", ios::in);

		if (myfile.is_open())
		{
			string Line = "";
			while (getline(myfile, Line))
			{
				clsCourse Course1 = _ConvertLineToCoureRecord(Line);
				if (Course1.Code() == Code)
				{
					return Course1;

				}
			}
			myfile.close();
		}
		return _GetEmptyCouresObject();

	}

	static bool IsCourseExist(string Code)
	{
		clsCourse Course2 = Find(Code);
		
		return !(Course2.IsEmpty());

	}

	static clsCourse GetAddNewCourseObject(string Code)
	{
		return clsCourse(enMode::NewMode, Code, "", 0);
	
	}
};

