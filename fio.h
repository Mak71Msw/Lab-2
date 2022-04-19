//
// Created by Максим Уланов on 14.04.2022.
//

#ifndef _2_FIO_H
#define _2_FIO_H

class fio
{
private:
    char* surname;
    char* name;
    char* patronymic;

public:

    char* GetSurname() {return surname;};
    char* GetName() {return name;};
    char* GetPatronymic() {return patronymic;};

    void setSurname(char* new_surname)
    {
        surname = new char[15];
        surname = new_surname;
    }
    void setName(char* new_name)
    {
        name = new char[15];
        name = new_name;
    }
    void setPatronymic(char* new_patronymic)
    {
        patronymic = new char[15];
        patronymic = new_patronymic;
    }

    fio()
    {
        surname = new char[10];
        strcpy(surname,"surname");
        name = new char[10];
        strcpy(name,"surname");
        patronymic = new char[10];
        strcpy(patronymic,"surname");
    }
//    ~fio()
//    {
//        cout<<"Память почистилась"<<endl;
//    }

};

#endif //_2_FIO_H
