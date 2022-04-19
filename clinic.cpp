//
// Created by Максим Уланов on 17.03.2022.
//

#include "clinic.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int CheckSpec()
{
    while (true)
    {
        cout << "Специальность(1-терапевт, 2-кардиолог, 3-стоматолог): ";
        int a;
        cin >> a;

        if (cin.fail() or (a < 1) or (a > 3))
        {
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else
            return a;
    }
}

int CheckQual()
{
    while (true)
    {
        cout << "Квалификация(0-высшая, 1-первая, 2-вторая): ";
        int a;
        cin >> a;

        if (cin.fail() or (a < 0) or (a > 2))
        {
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else
            return a;
    }
}

char * CheckSurname(){
    int i;
    char *str;
    str = new char[40];
    char *Obj = new char[40];
    do{
        cout<<"Фамилия: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Зачем вы ввели не буквы..."<<endl<<"Повторите ввод!!!"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
}

char * CheckName(){
    int i;
    char *str;
    str = new char[40];
    char *Obj = new char[40];
    do{
        cout<<"Имя: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Зачем вы ввели не буквы..."<<endl<<"Повторите ввод!!!"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
}

char * CheckPatronymic(){
    int i;
    char *str;
    str = new char[40];
    char *Obj = new char[40];
    do{
        cout<<"Отчество: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"Зачем вы ввели не буквы..."<<endl<<"Повторите ввод!!!"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
}

void Input(clinic* Obj,int amount)
{
    Obj[amount].setSpec(CheckQual()) ;
    cin.get();

    Obj[amount].setQual(CheckSpec()) ;
    cin.get();

    Obj[amount].fio_class.setSurname((CheckSurname()));

    Obj[amount].fio_class.setName((CheckName()));

    Obj[amount].fio_class.setPatronymic((CheckPatronymic()));

    cout << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Search(clinic* Obj, int amount)
{
    char* n;
    char* m;
    char* l;

    n=CheckSurname();
    m=CheckName();
    l=CheckPatronymic();

    StreamTable st(std::cout);
    st.AddCol(12);
    st.AddCol(10);
    st.AddCol(15);
    st.AddCol(15);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Surname" << "Name" << "Patronymic" << "Specialty" << "Qualification";

    for (int i = 0; i < amount; i++)
    {
        if (strcmp(Obj[i].fio_class.GetSurname(), n) == 0 and strcmp(Obj[i].fio_class.GetName(), m) == 0 and strcmp(Obj[i].fio_class.GetPatronymic(), l) == 0)
        {
            st << Obj[i].fio_class.GetSurname() << Obj[i].fio_class.GetName()
               << Obj[i].fio_class.GetPatronymic() << Obj[i].GetSpec()
               << Obj[i].GetQual();
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Filter(clinic* Obj, int amount)
{
    int s;
    int q;

    s=CheckSpec();
    q=CheckQual();

    StreamTable st(std::cout);
    st.AddCol(12);
    st.AddCol(10);
    st.AddCol(15);
    st.AddCol(15);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Surname" << "Name" << "Patronymic" << "Specialty" << "Qualification";

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].GetSpec() == s && Obj[i].GetQual() == q)
        {
            st << Obj[i].fio_class.GetSurname() << Obj[i].fio_class.GetName()
               << Obj[i].fio_class.GetPatronymic() << Obj[i].GetSpec()
               << Obj[i].GetQual();
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Sorted(clinic* Obj, int amount)
{
//    char a[40];
//    char b[40];
//    char c[40];
//    int d;
//    int e;
//
//    CheckSurname();
//    cin.getline(a, 40, '\n');
//    CheckName();
//    cin.getline(b, 40, '\n');
//    CheckPatronymic();
//    cin.getline(c, 40, '\n');
//    d=CheckSpec();
//    e=CheckQual();
//
//    for (int i = 0; i < amount - 1; i++)
//        for(int j=i+1;j<amount;j++)
//        {
//            if(strcmp(Obj[i].fio_class.GetSurname(),Obj[j].fio_class.GetSurname())>0)
//            {   strcpy(a,Obj[i].fio_class.GetSurname());
//                strcpy(Obj[i].fio_class.GetSurname(),Obj[j].fio_class.GetSurname());
//                strcpy(Obj[j].fio_class.GetSurname(),a);
//
//                strcpy(b,Obj[i].fio_class.GetName());
//                strcpy(Obj[i].fio_class.GetName(),Obj[j].fio_class.GetName());
//                strcpy(Obj[j].fio_class.GetName(),b);
//
//                strcpy(c,Obj[i].fio_class.GetPatronymic());
//                strcpy(Obj[i].fio_class.GetPatronymic(),Obj[j].fio_class.GetPatronymic());
//                strcpy(Obj[j].fio_class.GetPatronymic(),c);
//
//                d = Obj[i].GetSpec();
//                Obj[i].GetSpec() = Obj[j].GetSpec();
//                Obj[j].GetSpec() = d;
//
//                e = Obj[i].GetQual();
//                Obj[i].GetQual() = Obj[j].GetQual();
//                Obj[j].GetQual() = e;
//            }
//        }

    clinic tmp;

    for (int i = 0; i < amount - 1; i++) {
        for (int j = i + 1; j < amount; j++) {
            if (strcmp(Obj[i].fio_class.GetSurname(), Obj[j].fio_class.GetSurname()) > 0) {
                tmp = Obj[i];
                Obj[i] = Obj[j];
                Obj[j] = tmp;
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(12);
    st.AddCol(10);
    st.AddCol(15);
    st.AddCol(15);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Surname" << "Name" << "Patronymic" << "Specialty" << "Qualification";

    for (int i = 0; i < amount; i++)
    {
        {
            st << Obj[i].fio_class.GetSurname() << Obj[i].fio_class.GetName()
               << Obj[i].fio_class.GetPatronymic() << Obj[i].GetSpec()
               << Obj[i].GetQual();
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Read(clinic* &Obj, int amount, string filename) {
    ifstream myfile(filename);
    int count=0;
    char *str = new char [1024];
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile.getline(str, 1024, '\n');
            count++;
        }
        delete[] str;
    }

    amount=count-1;
    myfile.close();


    ifstream reading(filename);
    if (reading)
    {

        Obj = new clinic[amount];

        for (int i = 0; i<amount; i++)
        {
            int specialty;
            int qualification;
            char* surname;
            char* name;
            char* patronymic;

            reading >> specialty >> qualification >> surname >> name >> patronymic;
            Obj[i].setSpec(specialty);
            Obj[i].setQual(qualification);
            Obj[i].fio_class.setSurname(surname);
            Obj[i].fio_class.setName(name);
            Obj[i].fio_class.setPatronymic(patronymic);
        }
    }
    myfile.close();
    clinic::count=amount;
    cout<<"Количество считанных объектов: "<<clinic::count<<"\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Save(clinic* Obj, int amount, string filename){

    ofstream record(filename, ios::out);

    if (record)
    {
        for (int i=0; i<amount; i++)
        {
            record << Obj[i].GetSpec()<<" "<< Obj[i].GetQual()<<" "
            <<Obj[i].fio_class.GetSurname()<<" "<<Obj[i].fio_class.GetName()<<" "
            <<Obj[i].fio_class.GetPatronymic()<<endl;
        }
    }

    else
    {
        cout<<"Че-то не записывается(("<<endl;
    }
    record.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~