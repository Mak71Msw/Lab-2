#include "clinic.h"
#include "clinic_box.h"

int CheckMenu()
{
    while (true)
    {
        cout << "Диалоговое окно:" << endl;
        cout << "1)Показать кто уже имеется" << endl;
        cout << "2)Добавить нового врача" << endl;
        cout << "3)Найти врача по ФИО" << endl;
        cout << "4)Фильтр по квалификации и специальности" << endl;
        cout << "5)Сортировка врачей по алфавиту" << endl;
        cout << "6)Сохранить и выйти" << endl;
        cout << "Введите число от 1 до 6" << endl;
        int c;
        cin >> c;

        if (cin.fail() or (c < 1) or (c > 6))
        {
            cin.clear();
            cin.ignore(32767,'\n');
        }
        else
            return c;
    }
}

int clinic::count = 0;
int main()
{
    clinic_box element ;
    Read(element.MyClinic_ARRAY,clinic::count,"OOP.txt");
    int c;
    do {
        c=CheckMenu();
        switch (c)
        {
            case 1:
                element.Output();
                break;

            case 2:
                element.addElement();
                break;

            case 3:
                Search(element.MyClinic_ARRAY,clinic::count);
                break;

            case 4:
                Filter(element.MyClinic_ARRAY,clinic::count);
                break;

            case 5:
                Sorted(element.MyClinic_ARRAY,clinic::count);
                break;

            case 6:
                Save(element.MyClinic_ARRAY,clinic::count,"OOP.txt");
                break;
        }
    } while (c != 6);
    return 0;
}