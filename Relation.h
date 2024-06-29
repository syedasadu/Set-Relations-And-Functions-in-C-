#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
using namespace std;

class cartesianProduct;

struct setDatas
{
    string data1;
    string data2;
};

class Relation
{
    setDatas* Rel;
    int noOfRelation;
public:
    Relation(int);
    bool makeCartesian(cartesianProduct);
    void displayRelation();
    friend bool checkValid(cartesianProduct, Relation);
    bool IsReflexive(cartesianProduct, int, int);
    bool IsSymmetric(cartesianProduct);
    bool IsAnitSymmetric(cartesianProduct);
    bool IsRandS(cartesianProduct, int, int);
    bool IsSandAS(cartesianProduct);
    bool IsTransitive(cartesianProduct);
};

class cartesianProduct
{
    setDatas* prduct;
    int noOfProduct;
    friend class Relation;
    friend bool checkValid(cartesianProduct, Relation); // friend function of both class bcz want to access private members of both
public:

    int getNoOfProduct();
    cartesianProduct(int); //our parametrized Constructor
    cartesianProduct();  //our Defoult Constructor
    setDatas* getprduct();
    void inputFun(string*&, int, string*&, int, string);
    void outputFun(string*, int, string*, int);
    void makeCartesian(string*, int, string*, int);
    void displayCartesian();
    int TotalRelaions(); // total number of relations can be made
    Relation makeRelation(int, int);

};
