#include "Relation.h"


cartesianProduct::cartesianProduct() //our Defoult Constructor
{
    prduct = nullptr;
    noOfProduct = 0;
}

setDatas* cartesianProduct::getprduct()
{
    return prduct;
}

Relation cartesianProduct::makeRelation(int var1, int var2)
{
again:
    int total;
    cout << "\n\n Enter How many Relation you want : ";
    cin >> total;
    if (total > pow(2, (var1 * var2)))
    {
        cout << "\n Error...! Number of relation cannot be greater than Number of {2^(A * B)} ,elments.\n";
        goto again;
    }
    else if (total < 0)
    {
        cout << "\n Error...! Relation can not be Negative.\n";
        goto again;

    }
    Relation newRel(total);
    bool flag = newRel.makeCartesian(*this);
    if (!flag)
    {
        cout << "\n\nError...! Your Relation is Not Valid...!\n";
        goto again;
    }
    return newRel;
}

bool Relation::IsReflexive(cartesianProduct Car, int var1, int var2)
{
    if (var1 != var2)
    {
        cout << "Reason:\t No of set1 :" << var1 << " !=  no of set2:" << var2;
        cout << "\nResult:\t";

        return 0;
    }
    bool flag = 1;
    int ele = 0;
    for (int i = 0; i < var1; i++)
    {
        for (int j = 0; j < var1; j++)
        {
            if (i == j)
            {
                flag = false;
                for (int k = 0; k < this->noOfRelation; k++)
                {
                    if (Car.prduct[ele].data1 == this->Rel[k].data1 && Car.prduct[ele].data2 == this->Rel[k].data2)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag)
            {
                cout << "Reason:\t( " << Car.prduct[ele].data1 << "," << Car.prduct[ele].data2 << " ) Does not belongs to R";
                cout << "\nResult:\t";
                return 0;
            }
            ele++;
        }
    }
    return 1;
}

bool Relation::IsSymmetric(cartesianProduct C)
{
    bool flag = 1;
    for (int i = 0; i < this->noOfRelation; i++)
    {
        if (this->Rel[i].data1 == this->Rel[i].data2)
        {
            continue;
        }
        else
        {
            bool flag = false;
            for (int j = 0; j < this->noOfRelation; j++)
            {
                if (this->Rel[j].data1 == this->Rel[j].data2)
                {
                    continue;
                }
                else if (this->Rel[i].data2 == this->Rel[j].data1 && this->Rel[i].data1 == this->Rel[j].data2)
                {
                    flag = 1;
                }
            }
            if (!flag)
            {
                cout << "Reason:\t( " << this->Rel[i].data1 << "," << this->Rel[i].data2 << " )  belongs to Relation ";
                cout << " But (" << this->Rel[i].data2 << "," << this->Rel[i].data1 << " ) does not belongs to Relation ";
                cout << "\nResult:\t";

                return 0;
            }
        }
    }
    return 1;
}

bool Relation::IsAnitSymmetric(cartesianProduct C)
{
    bool flag = 1;
    for (int i = 0; i < this->noOfRelation; i++)
    {
        if (this->Rel[i].data1 == this->Rel[i].data2)
        {
            continue;
        }
        else
        {
            bool flag = 1;
            for (int j = 0; j < this->noOfRelation; j++)
            {
                if (this->Rel[j].data1 == this->Rel[j].data2)
                {
                    continue;
                }
                else if (this->Rel[i].data2 == this->Rel[j].data1 && this->Rel[i].data1 == this->Rel[j].data2)
                {
                    flag = 0;
                    if (this->Rel[i].data1 == this->Rel[i].data2) {  // addition in symmetric function
                        flag = 1;
                    }
                }
            }
            if (!flag)
            {
                cout << "Reason:\t( " << this->Rel[i].data1 << "," << this->Rel[i].data2 << " )  belongs to Rel ";
                cout << " and (" << this->Rel[i].data2 << "," << this->Rel[i].data1 << " )  belongs to R ";
                cout << " But " << this->Rel[i].data1 << " != " << this->Rel[i].data2;
                cout << "\nResult:\t";
                return 0;
            }
        }
    }
    return 1;
}


bool Relation::IsRandS(cartesianProduct C, int n1, int n2)
{
    return IsReflexive(C, n1, n2) && IsSymmetric(C);
}


bool Relation::IsSandAS(cartesianProduct C)
{
    return IsSymmetric(C) && IsAnitSymmetric(C);
}

bool checkValid(cartesianProduct C, Relation Re)
{
    for (int i = 0; i < Re.noOfRelation; i++)
    {
        bool check = 0;
        for (int j = 0; j < C.noOfProduct; j++)
        {
            if (Re.Rel[i].data1 == C.prduct[j].data1 && Re.Rel[i].data2 == C.prduct[j].data2)
            {
                check = 1;
                break;
            }
        }
        if (!check)
        {
            return 0;
        }
    }
    return 1;
}

void Relation::displayRelation()
{
    cout << "\n\nRelation :\n";
    cout << "R = { ";
    for (int i = 0; i < noOfRelation; i++)
    {
        cout << "(" << Rel[i].data1 << "," << Rel[i].data2 << ")";
        if (i != noOfRelation - 1)
        {
            cout << " , ";
        }
    }
    cout << " }";
}

bool Relation::makeCartesian(cartesianProduct C)
{
    for (int i = 0; i < noOfRelation; i++)
    {
        cout << "\n Enter " << i + 1 << "th Relation.\n";
        cout << "  Enter (a : ";
        cin >> Rel[i].data1;
        cout << "  Enter b) : ";
        cin >> Rel[i].data2;
    }
    system("cls");
    displayRelation();
    bool flag = checkValid(C, *this);
    return flag;
}

Relation::Relation(int ele)
{
    noOfRelation = ele;
    Rel = new setDatas[ele];
}

int cartesianProduct::TotalRelaions()
{
    return pow(2, noOfProduct);
}

int cartesianProduct::getNoOfProduct()
{
    return noOfProduct;
}

cartesianProduct::cartesianProduct(int ele)
{
    noOfProduct = ele;
    prduct = new setDatas[ele];
}
void cartesianProduct::inputFun(string*& set1, int var1, string*& set2, int var2, string choice)
{
    if (choice == "1" || choice == "2" || choice == "3")
    {
        cout << "Enter the elements of set A: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set A: ";
            cin >> set1[i];
            set2[i] = set1[i];
        }
    }

    if (choice == "4")
    {
        cout << "Enter the elements of set A: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set A: ";
            cin >> set1[i];
        }

        cout << "Enter the elements of set B: \n";
        for (int i = 0; i < var2; i++)
        {
            cout << "Enter element " << i + 1 << " of set B: ";
            cin >> set2[i];
        }
    }

    if (choice == "5")
    {
        cout << "Enter the elements of set A: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set A: ";
            cin >> set1[i];
        }

        cout << "Enter the elements of set C: \n";
        for (int i = 0; i < var2; i++)
        {
            cout << "Enter element " << i + 1 << " of set C: ";
            cin >> set2[i];
        }
    }

    if (choice == "6")
    {
        cout << "Enter the elements of set B: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set B: ";
            cin >> set1[i];
        }

        cout << "Enter the elements of set C: \n";
        for (int i = 0; i < var2; i++)
        {
            cout << "Enter element " << i + 1 << " of set C: ";
            cin >> set2[i];
        }
    }

    if (choice == "7")
    {
        cout << "Enter the elements of set B: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set B: ";
            cin >> set1[i];
        }

        cout << "Enter the elements of set A: \n";
        for (int i = 0; i < var2; i++)
        {
            cout << "Enter element " << i + 1 << " of set A: ";
            cin >> set2[i];
        }
    }

    if (choice == "8")
    {
        cout << "Enter the elements of set C: \n";
        for (int i = 0; i < var1; i++)
        {
            cout << "Enter element " << i + 1 << " of set C: ";
            cin >> set1[i];
        }

        cout << "Enter the elements of set A: \n";
        for (int i = 0; i < var2; i++)
        {
            cout << "Enter element " << i + 1 << " of set A: ";
            cin >> set2[i];
        }
    }
}

void cartesianProduct::outputFun(string* set1, int var1, string* set2, int var2)
{
    cout << "\n********************************\n";
    cout << "\n\nElements of set A :\n";
    cout << "A = { ";
    for (int i = 0; i < var1; i++)
    {
        cout << set1[i];
        if (i != var1 - 1)
        {
            cout << " , ";
        }
    }
    cout << " }";
    cout << "\n\nElements of set B :\n";
    cout << "B = { ";
    for (int i = 0; i < var2; i++)
    {
        cout << set2[i];
        if (i != var2 - 1)
        {
            cout << " , ";
        }
    }
    cout << " }";
    cout << "\n********************************\n\n";
}


void cartesianProduct::makeCartesian(string* set1, int var1, string* set2, int var2)
{
    int count = 0;
    for (int i = 0; i < var1; i++)
    {
        for (int j = 0; j < var2; j++)
        {
            prduct[count].data1 = set1[i];
            prduct[count].data2 = set2[j];
            count++;
        }
    }
}


void cartesianProduct::displayCartesian()
{
    cout << "\n****** Cartesian Product ******\n";
    cout << "AxB = { ";
    for (int i = 0; i < noOfProduct; i++)
    {
        cout << "(" << prduct[i].data1 << "," << prduct[i].data2 << ")";
        if (i != noOfProduct - 1)
        {
            cout << " , ";
        }
    }
    cout << " }";
}
bool Relation::IsTransitive(cartesianProduct C)
{
    for (int i = 0; i < this->noOfRelation; i++)
    {
        for (int j = 0; j < this->noOfRelation; j++)
        {
            if (this->Rel[i].data2 == this->Rel[j].data1 && this->Rel[i].data2 != this->Rel[j].data2)
            {
                bool found = false;
                for (int k = 0; k < this->noOfRelation; k++)
                {
                    if (this->Rel[i].data1 == this->Rel[k].data1 && this->Rel[j].data2 == this->Rel[k].data2)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "Reason:\t( " << this->Rel[i].data1 << "," << this->Rel[i].data2 << " ) and ( "
                        << this->Rel[j].data1 << "," << this->Rel[j].data2 << " ) present but ( "
                        << this->Rel[i].data1 << "," << this->Rel[j].data2 << " ) is missing from Relation";
                    cout << "\nResult:\t";
                    return false;
                }
            }
        }
    }
    return true;
}

