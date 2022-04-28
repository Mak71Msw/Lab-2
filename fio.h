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
        surname = new char[32];
        strcpy(surname, new_surname);
    }
    void setName(char* new_name)
    {
        name = new char[32];
        strcpy(name, new_name);
    }
    void setPatronymic(char* new_patronymic)
    {
        patronymic = new char[32];
        strcpy(patronymic, new_patronymic);
    }

    fio()
    {
        surname = new char[10];
        strcpy(surname,"surname");
        name = new char[10];
        strcpy(name,"name");
        patronymic = new char[10];
        strcpy(patronymic,"patronymic");
    }

};

#endif //_2_FIO_H
