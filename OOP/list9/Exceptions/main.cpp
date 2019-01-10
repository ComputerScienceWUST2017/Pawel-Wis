#include <iostream>
#include <string>
using namespace std;

class InvalidStudentIDException {
public:
	string what() {
		return "Invalid student identifier";
	}
};

class NonpositiveYearOfStudyException {
public:
	string what() {
		return "Nonpositive year of study";
	}
};

class Student {
	string firstName;
	string familyName;
	int studID;
	int yearOfStudy;
public:
	string getFirstName() {
		return this->firstName;
	}
	string getFamilyName() {
		return this->familyName;
	}
	int getStudID() {
		return this->studID;
	}
	int getYearOfStudy() {
		return this->yearOfStudy;
	}
	void setFirstName(string input) {
		this->firstName = input;
	}
	void setFamilyName(string input) {
		this->familyName = input;
	}
	void setStudID(int input) {
		if (input >= 100000 && input <= 999999) {
			this->studID = input;
		}
		else {
			throw InvalidStudentIDException();
		}
	}
	void setYearOfStudy(int input) {
		if (input > 0) {
			this->yearOfStudy = input;
		}
		else {
			throw NonpositiveYearOfStudyException();
		}
	}
	Student(string firName, string lasName, int studID, int yearOfStudy) {
		try {
			setFirstName(firName);
			setFamilyName(lasName);
			setStudID(studID);
			setYearOfStudy(yearOfStudy);
		}
		catch (InvalidStudentIDException e) {
			cout << e.what() << endl;
		}
		catch (NonpositiveYearOfStudyException e) {
			cout << e.what() << endl;
		}
	}
};


int main()
{
	auto s1 = new Student("pawel", "wisniewski", 232540, 2);
	auto s2 = new Student("jacek", "nowak", 2232540, 2);
	auto s3 = new Student("andzej", "rostowski", 567342, -1);
}

