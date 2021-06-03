#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include "fort.hpp"
#include "Tec.h"
#include "Kur.h"
#include "Persona.h"
#include "Menus.h"

#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 4996)

using namespace std;
int admin_login();
int user_login();

string user_out = "user.txt";
string admin_out = "admin.txt";
string deal_out = "deal.txt";

class Menus
{
public:
    int menu();
    int admin_menu();
    int admin_user_manage();
    int admin_tec_manage();
    int user_menu(int memory_int);
};

class Deal :public Data {
protected:

public:
    string deal_time;
    string brand;
    string name;
    string user_time() {
        time_t now = time(0);
        char* dt = ctime(&now);
        tm* gmtm = gmtime(&now);
        dt = asctime(gmtm);
        tm* ltm = localtime(&now);
        int month_int = ltm->tm_mon + 1;
        if (month_int > 12) {
            month_int = month_int % 12;
        }
        stringstream day, month, year;
        day << ltm->tm_mday;
        month << month_int;
        year << ltm->tm_year + 1900;
        string contract_date = day.str() + "." + month.str() + "." + year.str();
        return contract_date;
    }
};

class User_Deal { //Класс для сделок
private:
    vector<Deal> DealVector; // Инкапсуляция
    vector<Deal>::iterator it; // Инкапсуляция
public:
    void file_out_deal(); // Функция записи сделок в файл
    void file_in_deal(); // Функция чтения сделки из файла
    int make_deal(int user_number, Kurs& k, User &us); // Функция совершения сделок
    int show_deal(); // Функция отображения сделок
    int show_user_deal(int user_number, User &us); // Функция отображения сделок пользователя
    int sort_up_brand(); // Сортировка сделок по бренду
    int sort_down_brand(); 
    int sort_up_login(); // Сортировка сделок по имени пользователя
    int sort_down_login();
    int sort_up_name(); // Сортировка сделок по названию товара
    int sort_down_name();
};

User user;
Admin admin;
Kurs kursach;
Menus menus;
User_Deal user_deal;

int Menus::menu()
{
    string Menu[3] = { "Войти как администратор", "Войти как пользователь", "Выход" };
    int pointer = 0;
    int choice;
    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Main Menu\n\n";

        for (int i = 0; i < 3; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }

        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 2;
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == 3)
                {
                    pointer = 0;
                }
                break;
            }
            else if (choice == 13)
            {
                switch (pointer)
                {
                case 0:
                {
                    admin_login();
                    break;
                }
                case 1:
                {
                    user_login();
                    system("pause");
                } break;
                case 2:
                {
                    exit(0);
                    return 0;
                } break;
                }
                break;
            }
        }

        Sleep(150);
    }

    return 0;
}

int Menus::admin_menu() {
    string Menu[2] = { "Управление аккаунтами", "Управление товарами"};
    int pointer = 0;
    int choice;
    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Admin Menu\n\n";

        for (int i = 0; i < 2; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }
        
        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (choice == 13)
            {
                switch (pointer)
                {
                case 0:
                {
                    admin_user_manage();
                    system("pause");
                    break;
                }
                case 1:
                {
                    admin_tec_manage();
                    system("pause");
                } break;
                }
                break;
            }
            else if (choice == 8) {
                menu();
            }
        }
        Sleep(150);
    }
    return 0;
}

int admin_login(){
    string login;
    string password;
    int flag_login = 0, flag_password = 0, mem;
    while (flag_login == 0) {
        system("cls");
        cout << "Введите логин или Back для выхода\n";
        cin >> login;
        for (int i = 0; i < admin.data.size(); i++) {
            if (login == admin.data[i].login) {
                flag_login = 1;
                mem = i;
            }
        }
        if (login == "Back") {
            system("cls");
            menus.menu();
            system("pause");
        }
        if (flag_login == 0) {
            cout << "Вы ввели неверный пароль, попробуйте заново\n";
            getchar();
        }
    }
    while (flag_password == 0) {
        system("cls");
        cout << "Введите пароль или Back для выхода\n";
        cin >> password;
        if (password == admin.data[mem].password) {
            flag_password = 1;
        }
        else if (password == "Back") {
            system("cls");
            menus.menu();
            system("pause");
        }
        if (flag_password == 0) {
            cout << "Вы ввели неверный пароль, попробуйте заново\n";
            getchar();
        }
    }
    if (flag_password == 1) {
        menus.admin_menu();
    }
    return 0;
}

int Menus::admin_user_manage() {
    string Menu[4] = { "Добавление администратора", "Удаление администратора", "Добавление пользователя", "Удаление пользователя"};
    int pointer = 0;
    int choice;
    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Меню управления пользователями\n\n";

        for (int i = 0; i < 4; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }

        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 3;
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (choice == 13)
            {
                switch (pointer)
                {
                case 0:
                {
                    admin.add(admin, admin_out);
                    break;
                }
                case 1:
                {
                    admin.user_delete(admin, admin_out);
                } break;
                case 2:
                {
                    user.add(user, user_out);
                } break;
                case 3:
                {
                    user.user_delete(user, user_out);
                }break;
                }
                break;
            }
            else if (choice == 8) {
                admin_menu();
            }
        }

        Sleep(150);
    }
    return 0;
}

int Menus::admin_tec_manage() {
    string Menu[5] = { "Добавление товара", "Удаление товара", "Просмотр товара", "Редактирование товара", "Просмотр сделок"};
    int pointer = 0;
    int choice;
    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Меню управления товарами\n\n";

        for (int i = 0; i < 5; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }

        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == 5)
                {
                    pointer = 0;
                }
                break;
            }
            else if (choice == 13)
            {
                switch (pointer)
                {
                case 0:
                {
                    add_kurs(kursach);
                    system("pause");
                    break;
                }
                case 1:
                {
                    delete_kurs(kursach);
                    system("pause");
                } break;
                case 2:
                {
                    show_kurs(kursach);
                } break;
                case 3:
                {
                    edit_kurs(kursach);
                }break;
                case 4:
                {
                    user_deal.show_deal();
                }
                }
                break;
            }
            else if (choice == 8) {
                admin_menu();
            }
        }

        Sleep(150);
    }
    return 0;
}

int Menus::user_menu(int memory_int) {
    string Menu[3] = { "Просмотр товаров", "Заключение сделки", "Просмотр сделок" };
    int pointer = 0;
    int choice;
    while (true)
    {
        system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "User Menu\n\n";

        for (int i = 0; i < 3; ++i)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << Menu[i] << endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << Menu[i] << endl;
            }
        }

        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 3;
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (choice == 13)
            {
                switch (pointer)
                {
                case 0:
                {
                    show_kurs(kursach);
                    system("pause");
                    break;
                }
                case 1:
                {
                    user_deal.make_deal(memory_int, kursach, user);
                    system("pause");
                } break;
                case 2:
                {
                    user_deal.show_user_deal(memory_int, user);
                } break;
                }
                break;
            }
            else if (choice == 8) {
                menu();
            }
        }
        Sleep(150);
    }
    return 0;
}

int user_login() {
    string login;
    string password;
    int flag_login = 0, flag_password = 0, mem;
    while (flag_login == 0) {
        system("cls");
        cout << "Введите логин или Back для выхода\n";
        cin >> login;
        for (int i = 0; i < user.data.size(); i++) {
            if (login == user.data[i].login) {
                flag_login = 1;
                mem = i;
            }
        }
        if (login == "Back") {
            system("cls");
            menus.menu();
            system("pause");
        }
        if (flag_login == 0) {
            cout << "Вы ввели неверный логин, попробуйте заново\n";
            getchar();
        }
    }
    while (flag_password == 0) {
        system("cls");
        cout << "Введите пароль или Back для выхода\n";
        cin >> password;
        if (password == user.data[mem].password) {
            flag_password = 1;
        }
        else if (password == "Back") {
            system("cls");
            menus.menu();
            system("pause");
        }
        if (flag_password == 0) {
            cout << "Вы ввели неверный пароль, попробуйте заново\n";
            getchar();
        }
    }
    if (flag_password == 1) {
        menus.user_menu(mem);
    }
    return 0;
}



void User_Deal::file_out_deal() {
    ofstream fout;
    fout.open(deal_out);
    if (!fout.is_open()) {
        cout << "Ошибка отрытия файла!\n";
    }
    else {
        vector<Deal>::iterator it;
        for (it = DealVector.begin(); it < DealVector.end() - 1; it++) {
            fout << it->name << endl;
            fout << it->brand << endl;
            fout << it->login << endl;
            fout << it->deal_time << endl;
        }
        it = DealVector.end() - 1;
        fout << it->name << endl;
        fout << it->brand << endl;
        fout << it->login << endl;
        fout << it->deal_time;
    }
    fout.close();
}

void User_Deal::file_in_deal()
{
    Deal deal_in;
    ifstream fin;
    fin.open(deal_out, ios_base::in);
    int i = 0;
    if (!fin.is_open()) {
        cout << "Ошибка отркытия файла!\n";
    }
    else {
        cout << "Файл открыт!\n";
        while (!fin.eof()) {
            getline(fin, deal_in.name);
            getline(fin, deal_in.brand);
            getline(fin, deal_in.login);
            getline(fin, deal_in.deal_time);
            DealVector.push_back(deal_in);
        }
    }
}
int User_Deal::make_deal(int user_number, Kurs &k, User &us)
{
    Deal make_deal;
    int pointer = 1;
    int choice;
    while (true)
    {
        fort::char_table table;
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        table.set_border_style(FT_BASIC2_STYLE);
        table.column(0).set_cell_text_align(fort::text_align::center);
        table.column(1).set_cell_text_align(fort::text_align::center);
        table.column(2).set_cell_text_align(fort::text_align::center);
        table.column(3).set_cell_text_align(fort::text_align::center);
        table.column(4).set_cell_text_align(fort::text_align::center);
        table.column(5).set_cell_text_align(fort::text_align::center);
        table.column(6).set_cell_text_align(fort::text_align::center);
        table.column(7).set_cell_text_align(fort::text_align::center);
        table << fort::header << "№" << "Бренд" << "Страна" << "Название" << "Цена(рублей)" << "Цена(копеек)" << "Название склада" << "Год производства" << fort::endr;
        for (int i = 0; i < k.MyVector.size(); i++) {
            if (i + 1 == pointer) {
                table.row(i + 1).set_cell_bg_color(fort::color::cyan);
                table << i + 1 << k.MyVector[i].brand << k.MyVector[i].country << k.MyVector[i].name << k.MyVector[i].price.rubles << k.MyVector[i].price.coins << k.MyVector[i].warehouse << k.MyVector[i].year << fort::endr;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                table << i + 1 << k.MyVector[i].brand << k.MyVector[i].country << k.MyVector[i].name << k.MyVector[i].price.rubles << k.MyVector[i].price.coins << k.MyVector[i].warehouse << k.MyVector[i].year << fort::endr;
            }
        }
        system("cls");
        std::cout << table.to_string() << std::endl;
        while (true)
        {
            choice = _getch();
            if (choice == 72)
            {
                pointer -= 1;
                if (pointer == 0)
                {
                    pointer = k.MyVector.size();
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == k.MyVector.size() + 1)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 13) {
                make_deal.brand = k.MyVector[pointer - 1].brand;
                make_deal.deal_time = make_deal.user_time();
                make_deal.name = k.MyVector[pointer - 1].name;
                make_deal.login = us.data[user_number].login;
                user_deal.DealVector.push_back(make_deal);
                k.MyVector.erase(k.MyVector.begin() + (pointer - 1));
                file_write(k);
                file_out_deal();
                break;
            }
            else if (choice == 8)
            {
                return 0;
                break;
            }
        }
        Sleep(150);
    }
    return 0;
}

int User_Deal::show_deal()
{
        int pointer = 1;
        int choice;
        int name_count = 0, brand_count = 0, login_count = 0, time_count = 0;
        while (true) {
            system("cls");
            fort::char_table table;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            table.set_border_style(FT_BASIC2_STYLE);
            table.column(0).set_cell_text_align(fort::text_align::center);
            table.column(1).set_cell_text_align(fort::text_align::center);
            table.column(2).set_cell_text_align(fort::text_align::center);
            table.column(3).set_cell_text_align(fort::text_align::center);
            table.column(4).set_cell_text_align(fort::text_align::center);
            table.column(5).set_cell_text_align(fort::text_align::center);
            table.column(6).set_cell_text_align(fort::text_align::center);
            table.column(7).set_cell_text_align(fort::text_align::center);
            table << fort::header << "№"<< "Пользователь" << "Бренд" << "Название" << "Дата сделки" << fort::endr;
            table.cell(0, pointer).set_cell_bg_color(fort::color::cyan);
            for (int i = 0; i < DealVector.size(); i++) {
                table << i + 1 << DealVector[i].login << DealVector[i].brand << DealVector[i].name << DealVector[i].deal_time << fort::endr;
            }
            std::cout << table.to_string() << std::endl;
            while (true)
            {
                choice = _getch();
                if (choice == 75)
                {
                    pointer -= 1;
                    if (pointer == 0)
                    {
                        pointer = 3;
                    }
                    break;
                }
                else if (choice == 77)
                {
                    pointer += 1;
                    if (pointer == 4)
                    {
                        pointer = 1;
                    }
                    break;
                }
                else if (choice == 13) {
                    switch (pointer)
                    {
                    case 1:
                    {
                        login_count++;
                        if (login_count % 2 == 1) {
                            sort_up_login();
                        }
                        else {
                            sort_down_login();
                        }
                    } break;
                    case 2:
                    {
                        brand_count++;
                        if (brand_count % 2 == 1) {
                            sort_up_brand();
                        }
                        else {
                            sort_down_brand();
                        }
                    } break;
                    case 3:
                    {
                        name_count++;
                        if (name_count % 2 == 1) {
                            sort_up_name();
                        }
                        else {
                            sort_down_name();
                        }
                    } break;
                    }
                    break;
                }
                else if (choice == 8)
                {
                    return 0;
                    break;
                }
            }
            Sleep(150);
        }
        return 0;
    
}

int User_Deal::show_user_deal(int user_number, User &us)
{
    int pointer = 1;
    int choice;
    int name_count = 0, brand_count = 0, login_count = 0, time_count = 0;
    while (true) {
        system("cls");
        fort::char_table table;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        table.set_border_style(FT_BASIC2_STYLE);
        table.column(0).set_cell_text_align(fort::text_align::center);
        table.column(1).set_cell_text_align(fort::text_align::center);
        table.column(2).set_cell_text_align(fort::text_align::center);
        table.column(3).set_cell_text_align(fort::text_align::center);
        table.column(4).set_cell_text_align(fort::text_align::center);
        table.column(5).set_cell_text_align(fort::text_align::center);
        table.column(6).set_cell_text_align(fort::text_align::center);
        table.column(7).set_cell_text_align(fort::text_align::center);
        table << fort::header << "№" << "Пользователь" << "Бренд" << "Название" << "Дата сделки" << fort::endr;
        table.cell(0, pointer).set_cell_bg_color(fort::color::cyan);
        for (int i = 0; i < DealVector.size(); i++) {
            if (DealVector[i].login == us.data[user_number].login) {
                table << i + 1 << DealVector[i].login << DealVector[i].brand << DealVector[i].name << DealVector[i].deal_time << fort::endr;
            }
        }
        std::cout << table.to_string() << std::endl;
        while (true)
        {
            choice = _getch();
            if (choice == 75)
            {
                pointer -= 1;
                if (pointer == 0)
                {
                    pointer = 3;
                }
                break;
            }
            else if (choice == 77)
            {
                pointer += 1;
                if (pointer == 4)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 13) {
                switch (pointer)
                {
                case 1:
                {
                    login_count++;
                    if (login_count % 2 == 1) {
                        sort_up_login();
                    }
                    else {
                        sort_down_login();
                    }
                } break;
                case 2:
                {
                    brand_count++;
                    if (brand_count % 2 == 1) {
                        sort_up_brand();
                    }
                    else {
                        sort_down_brand();
                    }
                } break;
                case 3:
                {
                    name_count++;
                    if (name_count % 2 == 1) {
                        sort_up_name();
                    }
                    else {
                        sort_down_name();
                    }
                } break;
                }
                break;
            }
            else if (choice == 8)
            {
                return 0;
                break;
            }
        }
        Sleep(150);
    }
    return 0;
}

int User_Deal::sort_up_brand()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].brand > DealVector[i].brand) {
                new_deal = DealVector[i];
                DealVector[i] = DealVector[j];
                DealVector[j] = new_deal;
            }
        }
    }
    return 0;
}

int User_Deal::sort_down_brand()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].brand < DealVector[i].brand) {
                new_deal = DealVector[j];
                DealVector[j] = DealVector[i];
                DealVector[i] = new_deal;
            }
        }
    }
    return 0;
}

int User_Deal::sort_up_login()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].login > DealVector[i].login) {
                new_deal = DealVector[i];
                DealVector[i] = DealVector[j];
                DealVector[j] = new_deal;
            }
        }
    }
    return 0;
}

int User_Deal::sort_down_login()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].login < DealVector[i].login) {
                new_deal = DealVector[j];
                DealVector[j] = DealVector[i];
                DealVector[i] = new_deal;
            }
        }
    }
    return 0;
}

int User_Deal::sort_up_name()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].name > DealVector[i].name) {
                new_deal = DealVector[i];
                DealVector[i] = DealVector[j];
                DealVector[j] = new_deal;
            }
        }
    }
    return 0;
}

int User_Deal::sort_down_name()
{
    Deal new_deal;
    for (int i = 0; i < DealVector.size(); i++) {
        for (int j = i; j < DealVector.size(); j++) {
            if (DealVector[j].name < DealVector[i].name) {
                new_deal = DealVector[j];
                DealVector[j] = DealVector[i];
                DealVector[i] = new_deal;
            }
        }
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    decipher(user, user_out);
    decipher(admin, admin_out);
    file_read(kursach);
    user_deal.file_in_deal();
    kursach.MyVector.erase(kursach.MyVector.begin());
    menus.menu();
    return 0;
}
