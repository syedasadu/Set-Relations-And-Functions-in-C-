#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include "Relation.h"
using namespace std;

int main()
{
    system("color 1F");
    string choice;
    int var1 = 0, var2 = 0;

start:
    cout << "\n\n\t\t===========================================";
    cout << "\n\t\t       Cartesian Product & Relations";
    cout << "\n\t\t===========================================\n\n";
    cout << "1. AxA\n";
    cout << "2. BxB\n";
    cout << "3. CxC\n";
    cout << "4. AxB\n";
    cout << "5. AxC\n";
    cout << "6. BxC\n";
    cout << "7. BxA\n";
    cout << "8. CxA\n";
    cout << " Enter Your Choice : ";
    cin >> choice;

    if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6" || choice == "7" || choice == "8")
    {
        do
        {
            cout << "Enter the total number of Set A (must be at least 3) : ";
            cin >> var1;

        } while (var1 < 3);
        var2 = var1;
        if (choice == "2")
        {
            do
            {
                cout << "Enter the total number of Set B (must be at least 3) : ";
                cin >> var2;
            } while (var2 < 3);
        }

        system("cls");
    }
    else
    {
        system("cls");
        goto start;
    }

    cartesianProduct CP(var1 * var2);
    string* set1 = new string[var1];
    string* set2 = new string[var2];

    CP.inputFun(set1, var1, set2, var2, choice);
    cout << "\n\n\n\t\t\t Loading";
    for (int i = 0; i < 7; i++)
    {
        cout << ".";
        Sleep(500);
    }
    system("cls");

    cout << "\n\n\t\t===========================================";
    cout << "\n\t\t\t      Cartesian Product Results";
    cout << "\n\t\t===========================================\n";

    CP.outputFun(set1, var1, set2, var2);
    CP.makeCartesian(set1, var1, set2, var2);
    CP.displayCartesian();

    cout << "\n\n\t\t===========================================";
    cout << "\n\t\t\t      Relations Results";
    cout << "\n\t\t===========================================\n";

    Relation R = CP.makeRelation(var1, var2);

    cout << "\n\n1. Total number of possible Relations : " << CP.TotalRelaions();

    cout << "\n\n2.******************** Reflexive ******************** \n\n";
    if (R.IsReflexive(CP, var1, var2))
    {
        cout << "This Relation is Reflexive" << endl;
    }

    else
    {
        cout << "This Relation is not Reflexive" << endl;
    }


    cout << "\n\n3.******************** Symmetric ******************** \n\n";
    if (R.IsSymmetric(CP))
    {
        cout << "This Relation is Symmetric" << endl;
    }

    else
    {
        cout << "This Relation is not Symmetric" << endl;
    }


    cout << "\n4.******************** AntiSymmetric ******************** \n\n";

    if (R.IsAnitSymmetric(CP))
    {
        cout << "This Relation is AntiSymmetric" << endl;
    }

    else
    {
        cout << "This Relation is not AntiSymmetric" << endl;
    }


    cout << "\n5.******************** Reflexive and Symmetric ******************** \n\n";
    if (R.IsRandS(CP, var1, var2))
    {
        cout << "This Relation is (Reflexive and Symmetric) " << endl;
    }

    else
    {
        cout << "This Relation is not (Reflexive and Symmetric)" << endl;
    }


    cout << "\n6.*************** Symmetric and AntiSymmetric ******************** \n\n";
    if (R.IsSandAS(CP))
    {
        cout << "This Relation is (Reflexive and Anti Symmetric) " << endl;
    }
    else
    {
        cout << "This Relation is Not (Reflexive and Anti Symmetric) " << endl;
    }


    cout << "\n\n7.******************** Transitive ******************** \n\n";
    if (R.IsTransitive(CP))
    {
        cout << "This Relation is Transitive " << endl;
    }
    else
    {
        cout << "This Relation is Not Transitive " << endl;
    }

    cout << "\n\n\t\t Enter any Key For Continue\n\t\t OR ESC to exit ... ";
    char ch = _getch();
    if (ch != 27)
    {
        system("CLS");
        goto start;
    }
    system("CLS");

    return 0;
}
