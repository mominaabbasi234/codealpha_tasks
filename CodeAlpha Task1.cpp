#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Course
{
public:
    string courseName;
    string grade;
    int creditHours;
    double gradePoint;

    void inputCourse()
    {
        cout << "\nEnter Course Name: ";
        cin.ignore();
        getline(cin, courseName);

        cout << "Enter Grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
        cin >> grade;

        cout << "Enter Credit Hours: ";
        cin >> creditHours;

        gradePoint = convertGrade(grade);
    }

    double convertGrade(string g)
    {
        if (g == "A") return 4.0;
        else if (g == "A-") return 3.7;
        else if (g == "B+") return 3.3;
        else if (g == "B") return 3.0;
        else if (g == "B-") return 2.7;
        else if (g == "C+") return 2.3;
        else if (g == "C") return 2.0;
        else if (g == "C-") return 1.7;
        else if (g == "D+") return 1.3;
        else if (g == "D") return 1.0;
        else return 0.0;
    }
};

class CGPACalculator
{
private:
    vector<Course> courses;
    double semesterGPA;
    double overallCGPA;

public:

    void inputData()
    {
        int n;

        cout << "=====================================\n";
        cout << "        CGPA CALCULATOR SYSTEM       \n";
        cout << "=====================================\n";

        cout << "\nEnter Number of Courses: ";
        cin >> n;

        courses.resize(n);

        for (int i = 0; i < n; i++)
        {
            cout << "\nCourse " << i + 1 << endl;
            courses[i].inputCourse();
        }
    }

    void calculateSemesterGPA()
    {
        double totalGradePoints = 0;
        int totalCredits = 0;

        for (int i = 0; i < courses.size(); i++)
        {
            totalGradePoints += courses[i].gradePoint * courses[i].creditHours;
            totalCredits += courses[i].creditHours;
        }

        semesterGPA = totalGradePoints / totalCredits;
    }

    void calculateOverallCGPA()
    {
        char choice;
        cout << "\nDo you have previous semesters? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            double previousCGPA;
            int previousCredits;

            cout << "Enter Previous CGPA: ";
            cin >> previousCGPA;

            cout << "Enter Total Previous Credit Hours: ";
            cin >> previousCredits;

            int currentCredits = 0;

            for (int i = 0; i < courses.size(); i++)
                currentCredits += courses[i].creditHours;

            overallCGPA =
                ((previousCGPA * previousCredits) +
                    (semesterGPA * currentCredits))
                /
                (previousCredits + currentCredits);
        }
        else
        {
            overallCGPA = semesterGPA;
        }
    }

    void displayResult()
    {
        int totalCredits = 0;

        cout << "\n\n==============================================";
        cout << "\n             COURSE DETAILS";
        cout << "\n==============================================";

        cout << left
            << setw(20) << "Course"
            << setw(10) << "Grade"
            << setw(10) << "Credits"
            << setw(10) << "Points";

        cout << endl;

        for (int i = 0; i < courses.size(); i++)
        {
            cout << left
                << setw(20) << courses[i].courseName
                << setw(10) << courses[i].grade
                << setw(10) << courses[i].creditHours
                << setw(10) << courses[i].gradePoint
                << endl;

            totalCredits += courses[i].creditHours;
        }

        cout << "\n----------------------------------------------";
        cout << "\nTotal Credits : " << totalCredits;
        cout << fixed << setprecision(2);
        cout << "\nSemester GPA  : " << semesterGPA;
        cout << "\nOverall CGPA  : " << overallCGPA;
        cout << "\n==============================================\n";
    }
};

int main()
{
    CGPACalculator calculator;

    calculator.inputData();
    calculator.calculateSemesterGPA();
    calculator.calculateOverallCGPA();
    calculator.displayResult();

    return 0;
}