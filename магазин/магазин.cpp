
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    string sok[9] = {
         "Яблочный", 
        "Апельсиновйы", 
        "Абрикосовый",
        "Грушевый", 
        "Томатный", 
        "Луковый",
        "Огуречный", 
        "Чесночный чай", 
        "Петрушевый чай"
    };



    int price[9] = { 100, 120, 110, 130, 90, 80, 95, 70, 75 };
    int kol[9] = { 0 };



    int choice, litr;
    double summa = 0;
    double skidka = 0;



    while (true){
        cout << "\n=== МАГАЗИН СОКА ===\n";

        for (int i = 0; i < 9; i++)
        {
            cout << i + 1 << ". " << sok[i]
                << " - " << price[i] << " руб.\n";
        }

        cout << "0. Закончить покупку\n";

        cout << "\nВыберите товар: ";
        cin >> choice;

        if (choice == 0){
             break;
        }

        if (choice < 1 || choice > 9)
        {
            cout << "Нет такого товара\n";
            continue;

        }



        cout << "Количество литров: ";
        cin >> litr;

        if (litr <= 0)
        {
            cout << "Неверное количество\n";
            continue;
        }

        kol[choice - 1] += litr;

        cout << "Добавлено\n";
    }

    cout << "\n=== Чек ===\n";

    for (int i = 0; i < 9; i++)
    {
        if (kol[i] > 0)
        {
            int cena = kol[i] * price[i];

            if (i == 5){
                cena = (kol[i] - kol[i] / 4) * price[i];
            }

            cout << sok[i] << " " << kol[i]
                << " л. - " << cena << " руб.\n";

            summa += cena;
        }
    }

    if (kol[8] >= 3)
    {
        skidka = kol[8] * price[8] * 0.05;
    }

    if (summa > 1000)
    {
        skidka += (summa - skidka) * 0.13;
    }

    cout << "\nСумма: " << summa << " руб.\n";
    cout << "Скидка: " << skidka << " руб.\n";
    cout << "Итого: " << summa - skidka << " руб.\n";

    return 0;
}