//
// Created by Максим Уланов on 14.04.2022.
//
#pragma once

#include <iostream>
#include "clinic.h"
using namespace std;

class clinic;
class fio;

class clinic_box {

public:

    clinic* MyClinic_ARRAY;

    clinic_box()
    {
        MyClinic_ARRAY = new clinic[0];
    }

    void addElement()
    {
        clinic* tmp;
        tmp = (clinic*)std::realloc(MyClinic_ARRAY, (clinic::count + 1) * sizeof(clinic));
        if (tmp != nullptr)
        {
            MyClinic_ARRAY = tmp;
            Input(MyClinic_ARRAY,clinic::count);
            clinic::count++;
        }
        else
        {
            cout << "Вопросы/Ответы по желанию"  << endl;
        }
    }

    void Output()
    {

        StreamTable st(std::cout);
        st.AddCol(15);
        st.AddCol(15);
        st.AddCol(15);
        st.AddCol(15);
        st.AddCol(15);

        st.MakeBorderExt(true);
        st.SetDelimRow(true, '-');
        st.SetDelimCol(true, '|');

        st << "Surname" << "Name" << "Patronymic" << "Specialty" << "Qualification";
        for (int i = 0; i < clinic::count; i++)
        {
            st << MyClinic_ARRAY[i].fio_class.GetSurname() << MyClinic_ARRAY[i].fio_class.GetName()
            << MyClinic_ARRAY[i].fio_class.GetPatronymic() << MyClinic_ARRAY[i].GetSpec()
            << MyClinic_ARRAY[i].GetQual();
        }
    }

    ~clinic_box(){
        for (int i = 0; i < clinic::count; i++) {
            delete[] MyClinic_ARRAY[i].fio_class.GetName();
            delete[] MyClinic_ARRAY[i].fio_class.GetSurname();
            delete[] MyClinic_ARRAY[i].fio_class.GetPatronymic();
        }
    }
};