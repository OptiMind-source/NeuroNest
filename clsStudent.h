#pragma once
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

class clsStudent :public clsPerson
{
private:

	enum enMode{ EmptyMode = 0 , UpdateMode = 1 , NewMode = 2 };
	
	double _Balance;
	string _Country;
	string _BirthDate;
	string _Id;
	string _Password;
	enMode _Mode;
	bool _MarkForDelete = false;

	static clsStudent _ConvertDataLineToStudentRecord(string Line) 
	{
		vector<string> vStudent=clsString::Split(Line ,"#//#");
		return clsStudent(enMode::UpdateMode ,vStudent[0], vStudent[1], vStudent[2], vStudent[3],char(vStudent[4][0]), stod(vStudent[5]), vStudent[6], vStudent[7], vStudent[8],vStudent[9]);
	}

	string _ConvertStudentRecordToLine(clsStudent Student , string seperator = "#//#")
	{
		string sStudent="";

		sStudent += Student.FirstName + seperator;
		sStudent += Student.LastName + seperator;
		sStudent += Student.Email + seperator;
		sStudent += Student.Phone + seperator;
		sStudent += Student.Gender + seperator;
		sStudent += to_string(Student.Balance) + seperator;
		sStudent += Student.BirthDate + seperator;
		sStudent += Student.Id() + seperator;
		sStudent += Student.Country + seperator;
		sStudent += Student.Password;

		return sStudent;

	}

	static clsStudent _GetEmptyStudentObject() 
	{

		return clsStudent(enMode::EmptyMode, "", "", "", "",' ', 0, "", "","", "");

	}

	static vector<clsStudent> _LoadStudentsData() 
	{
		vector<clsStudent>vStudents;
		fstream myfile;
		myfile.open("Students.txt" ,ios::in);
		if (myfile.is_open()) 
		{
			string Line = "";
			while (getline(myfile, Line)) 
			{
				vStudents.push_back(_ConvertDataLineToStudentRecord(Line));

			}
			myfile.close();
		}

		return vStudents;
	}

	void _SaveStudentsData( vector<clsStudent> vStudent ) 
	{
		fstream myfile;
		myfile.open("Students.txt",ios::out);

		if (myfile.is_open())
		{ 
			for (clsStudent& Student : vStudent) 
			{
				if(Student._MarkForDelete==false)
				myfile << _ConvertStudentRecordToLine(Student) << "\n";

			}
			myfile.close();
		}

	}

	void _AddNewStudent()
	{
		fstream myfile;

		myfile.open("Students.txt", ios::out | ios::app);

		if (myfile.is_open()) 
		{
			myfile << _ConvertStudentRecordToLine(*this) << endl;
			myfile.close();
		}
    }

	void _Update() 
	{
		vector<clsStudent>vStudent = _LoadStudentsData();
		for (clsStudent& Student : vStudent) 
		{
			if (Student.Id() == Id())
			{
				Student = *this;
				break;
			}
		}
		_SaveStudentsData(vStudent);
	}

public:
	
	clsStudent(enMode Mode , string FirstName, string LastName, string Email, string Phone,char Gender,double Balance ,string BirthDate,string Id ,string Country,string Password)
	     :clsPerson(FirstName ,LastName ,Email ,Phone,Gender)
	{
		_Mode = Mode;
		_Balance = Balance;
		_BirthDate = BirthDate;
		_Id = Id;
		_Password = Password;
		_Country = Country;

	}
    
	//Property Set
	void SetBalance(double Balance)
	{
		_Balance = Balance;
	}

	//Property Get
	double GetBalance()
	{
		return _Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance)) double Balance;

	//Property Set
	void SetCountry(string Country)
	{
		_Country = Country;
	}

	//Property Get
	string GetCountry()
	{
		return _Country;
	}
	__declspec(property(get = GetCountry, put = SetCountry)) string Country;

	//Property Set
	void SetBirthDate(string BirthDate)
	{
		_BirthDate = BirthDate;
	}

	//Property Get
	string GetBirthDate()
	{
		return _BirthDate;
	}
	__declspec(property(get = GetBirthDate, put = SetBirthDate) ) string BirthDate;


	//Property Get
	string Id()
	{
		return _Id;
	}

	//Property Set
	void SetPassword(string Password)
	{
		_Password = Password;
	}

	//Property Get
	string GetPassword()
	{
		return _Password;
	}
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

	bool IsEmpty() 
	{
		return (_Mode==enMode::EmptyMode);

	}

	void MarkForDelete() 
	{
	
		_MarkForDelete = true;

	}

	static clsStudent Find(string Id ) 
	{
		fstream myfile;
		myfile.open("Students.txt",ios::in);
		if (myfile.is_open()) 
		{
			string Line = "";
			while (getline(myfile,Line)) 
			{
				clsStudent Student1 = _ConvertDataLineToStudentRecord(Line);
				if (Student1.Id() == Id)
				{
					return Student1;

				}
			}
			myfile.close();
		}
		
		return _GetEmptyStudentObject();

	}

	static clsStudent Find(string Id, string Password) 
	{
		clsStudent Student1 = Find(Id);
		if (Student1.Password == Password)
			return Student1;
		else
			return _GetEmptyStudentObject();

	}

	static bool IsStudentExist(string Id)
	{
		clsStudent Student1 = Find(Id);
		return !Student1.IsEmpty();
	}

	static vector<clsStudent> GetStudentsData() 
	{
		return _LoadStudentsData();

	}

	static clsStudent GetAddNewStudentObject(string Stu_Id) 
	{
		return clsStudent(enMode::NewMode, "", "", "", "", ' ', 0, "", Stu_Id , "","");
	}

	enum enSaveResults { svSucceeded = 1 , svFaildUserExists = 2 , svFaildEmptyObject = 3 };

	enSaveResults Save() 
	{
		switch (_Mode)
		{
		case clsStudent::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case clsStudent::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
		case clsStudent::NewMode:
		{
			if (IsStudentExist(Id())) 
			{
				return enSaveResults::svFaildUserExists;

			}
			else 
			{
				_AddNewStudent();
				return enSaveResults::svSucceeded;

			}

		}

		}

	}

	bool Delete() 
	{
		vector <clsStudent>vStudent = _LoadStudentsData();

		for (clsStudent& Student : vStudent) 
		{
			if (Student.Id() == Id()) 
			{
				Student.MarkForDelete();
				break;
			}

		}
           
		_SaveStudentsData(vStudent);
		*this = _GetEmptyStudentObject();
		return true;


	}

	bool IsTheSame(clsStudent Stdent1) 
	{

		return (Stdent1.Balance == Balance && Stdent1.BirthDate == BirthDate &&
	     	 Stdent1.Country == Country && Stdent1.Email == Email &&
		 Stdent1.FirstName == FirstName && Stdent1.LastName == LastName
			&& Stdent1.Phone == Phone && Stdent1.Id() == Id() && Stdent1.Password == Password && Stdent1.Gender == Gender);

	}

};

