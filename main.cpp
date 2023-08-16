#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    int mark=0, semester, credit;
    string subject, grade, cont, out;
    float cgpa=0.00, totalCgpa=0.00, pointer=0.00, totalGpa=0.00, gpa=0.00, totalPointer=0.00, totalCredit=0.00, totalPointerAll=0.00;

    do{
        cout << "******** Grading System ********" << endl;
        cout << "Enter Semester : ";
        cin >> semester;

        do{
            cout << "\nEnter Subject : ";
            cin >> subject;
            cout << "Enter Credit : ";
            cin >> credit;
            cout << "Enter Mark : ";
            cin >> mark;

            if (mark >= 90 && mark <= 100){
                grade = "A+";
                pointer = 4.00;
            } else if (mark >= 80 && mark <= 89){
                grade = "A";
                pointer = 4.00;
            } else if (mark >= 75 && mark <= 79){
                grade = "A-";
                pointer = 3.67;
            } else if (mark >= 70 && mark <= 74){
                grade = "B+";
                pointer = 3.33;
            } else if (mark >= 65 && mark <= 69){
                grade = "B";
                pointer = 3.00;
            } else if (mark >= 60 && mark <= 64){
                grade = "B-";
                pointer = 2.67;
            } else if (mark >= 55 && mark <= 59){
                grade = "C+";
                pointer = 2.33;
            } else if (mark >= 50 && mark <= 54){
                grade = "C";
                pointer = 2.00;
            } else if (mark >= 47 && mark <= 49){
                grade = "C-";
                pointer = 1.67;
            } else if (mark >= 44 && mark <= 46){
                grade = "D+";
                pointer = 1.33;
            } else if (mark >= 40 && mark <= 43){
                grade = "D";
                pointer = 1.00;
            } else if (mark >= 30 && mark <= 39){
                grade = "E";
                pointer = 0.67;
            } else {
                grade = "F";
                pointer = 0;
            }

            cout << "Grade : " <<grade << endl;

            totalPointer = pointer * credit;
            totalPointerAll += totalPointer;
            totalCredit += credit;

            gpa = totalPointerAll / totalCredit;

            cout << "Pointer : " << pointer;
            cout << "\n\nHave any subject ? (Y-Yes | N-No)";
            cin >> cont;
        } while (cont == "Y" || cont == "y");
        cout << "\nTotal GPA for semester " <<semester <<" : " << gpa;
        cout << "\nHave any semester ? (Y-Yes | N-No) : ";
        cin >> out;
        if (out == "N" || out == "n"){
            break;
        }
    } while (true);

        cgpa = totalPointerAll / totalCredit;
        cout << "CGPA : " << cgpa;

        std::ofstream myfile;
        myfile.open ("cgpa-transcript.txt");

        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%d/%m/%Y %X", &tstruct);

        myfile << "\n\t\tCGPA Transcript";
        myfile << "\n\nCGPA     : " << cgpa;
        myfile << "\n\nThis transcript was generated on " << buf;

        MessageBox(NULL, "Transcript Has Been Generated!", "CGPA Transript", MB_OK | MB_ICONINFORMATION);
        myfile.close();
    return 0;
}
