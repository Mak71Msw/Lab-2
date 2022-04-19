//
// Created by Максим Уланов on 17.03.2022.
//

#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Streamtable.h"
#include "fio.h"
using namespace std;

class fio;

class clinic
{
private:
    int specialty;
    int qualification;

public:
    fio fio_class;

    static int count;

    int GetSpec() {return specialty;};
    int GetQual() {return qualification;};

    void setSpec(int new_specialty)
    {
        specialty = new_specialty;
    }
    void setQual(int new_qualification)
    {
        qualification = new_qualification;
    }

    clinic()
    {
        specialty = 0;
        qualification = 0;
        count=0;

    }
//    ~clinic()
//    {
//        cout<<"Память почистилась"<<endl;
//    }

    friend void Search(clinic* Obj, int amount);
    friend void Input(clinic* Obj,int amount);
    friend void Filter(clinic* Obj, int amount);
    friend void Sorted(clinic* Obj, int amount);
    friend void Save(clinic* Obj, int amount, string filename);
    friend void Read(clinic* &Obj, int amount, string filename);
};