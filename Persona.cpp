#include "Persona.h"

#define ENG 26
#define RUS 32

Data decipher(Person &pers, string path)
{
    ifstream fin;
    Data file_data;
    fin.open(path, ios_base::in);
    if (!fin.is_open()) {
        cout << "Ошибка отркытия файла!\n";
    }
    else {
        while (!fin.eof()) {
            getline(fin, file_data.login);
            getline(fin, file_data.password);
            pers.data.push_back(file_data);
        }
        pers.data.pop_back();
    }
    int flag, i, n = 5, j;
    char c, user_buf_name[50], user_buf_password[50];
    char name[50], pass[50];
    for (i = 0; i < pers.data.size(); i++)
    {
        file_data = pers.data[i];
        strcpy_s(user_buf_name, file_data.login.c_str());
        strcpy_s(user_buf_password, file_data.password.c_str());
        j = 0;
        while (j < strlen(user_buf_name))
        {
            c = user_buf_name[j];
            flag = 0;
            if (c >= 'A' && c <= 'Z')
            {
                c = c - (n % ENG);
                if (c < 'A') c = 'Z' - ('A' - c) + 1;
                name[j] = c;
                flag = 1;
            }
            if (c >= 'a' && c <= 'z')
            {
                c = c - (n % ENG);
                if (c < 'a') c = 'z' - ('a' - c) + 1;
                name[j] = c;
                flag = 1;
            }
            if (c >= 'А' && c <= 'Я')
            {
                c = c - (n % RUS);
                if (c < 'А') c = 'Я' - ('А' - c) + 1;
                name[j] = c;
                flag = 1;
            }
            if (c >= 'а' && c <= 'я')
            {
                c = c - (n % RUS);
                if (c < 'а') c = 'я' - ('а' - c) + 1;
                name[j] = c;
                flag = 1;
            }
            if (c >= '0' && c <= '9')
            {
                c = c - (n % ENG);
                if (c < '0') c = '9' - ('0' - c) + 1;
                name[j] = c;
                flag = 1;
            }
            if (!flag)
                name[j] = c;
            j++;
        }
        name[strlen(user_buf_name)] = '\0';
        string perem_log(name, sizeof(name));
        perem_log.erase(perem_log.begin() + pers.data[i].login.length(), perem_log.end());
        file_data.login = perem_log;
        j = 0;
        while (j < strlen(user_buf_password))
        {
            c = user_buf_password[j];
            flag = 0;
            if (c >= 'A' && c <= 'Z')
            {
                c = c - (n % ENG);
                if (c < 'A') c = 'Z' - ('A' - c) + 1;
                pass[j] = c;
                flag = 1;
            }
            if (c >= 'a' && c <= 'z')
            {
                c = c - (n % ENG);
                if (c < 'a') c = 'z' - ('a' - c) + 1;
                pass[j] = c;
                flag = 1;
            }
            if (c >= 'А' && c <= 'Я')
            {
                c = c - (n % RUS);
                if (c < 'А') c = 'Я' - ('А' - c) + 1;
                pass[j] = c;
                flag = 1;
            }
            if (c >= 'а' && c <= 'я')
            {
                c = c - (n % RUS);
                if (c < 'а') c = 'я' - ('а' - c) + 1;
                pass[j] = c;
                flag = 1;
            }
            if (c >= '0' && c <= '9')
            {
                c = c - (n % ENG);
                if (c < '0') c = '9' - ('0' - c) + 1;
                pass[j] = c;
                flag = 1;
            }
            if (!flag)
                pass[j] = c;
            j++;
        }
        pass[strlen(user_buf_password)] = '\0';
        string perem_pas(pass, sizeof(pass));
        perem_pas.erase(perem_pas.begin() + pers.data[i].password.length(), perem_pas.end());
        file_data.password = perem_pas;;
        pers.data[i] = file_data;
    }
    fin.close();
    return file_data;
}

void Person::encrypt(Data dat, string path)
{
    ofstream fout;
    fout.open(path, ios_base::app);
    int flag, j = 0, n = 5;
    char c;
    char buf_login[50], buf_password[50];
    strcpy_s(buf_login, dat.login.c_str());
    strcpy_s(buf_password, dat.password.c_str());
    c = buf_login[j];
    while (j != strlen(buf_login))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c + (n % RUS);
            if (c > 'Я') c = 'А' + (c - 'Я') - 1;
            flag = 1;
        }
        if (c >= 'а' && c <= 'я')
        {
            c = c + (n % RUS);
            if (c > 'я') c = 'а' + (c - 'я') - 1;
            flag = 1;
        }
        if (c >= '0' && c <= '9')
        {
            c = c + (n % ENG);
            if (c > '9') c = '0' + (c - '9') - 1;
            flag = 1;
        }
        buf_login[j] = c;
        j++;
        c = buf_login[j];
    }
    j = 0;
    c = buf_password[j];
    while (j != strlen(buf_password))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            flag = 1;
        }
        if (c >= 'А' && c <= 'Я')
        {
            c = c + (n % RUS);
            if (c > 'Я') c = 'А' + (c - 'Я') - 1;
            flag = 1;
        }
        if (c >= 'а' && c <= 'я')
        {
            c = c + (n % RUS);
            if (c > 'я') c = 'а' + (c - 'я') - 1;
            flag = 1;
        }
        if (c >= '0' && c <= '9')
        {
            c = c + (n % ENG);
            if (c > '9') c = '0' + (c - '9') - 1;
            flag = 1;
        }
        buf_password[j] = c;
        j++;
        c = buf_password[j];
    }
    string str_name(buf_login, sizeof(dat.login)), str_password(buf_password, sizeof(dat.password));
    str_name.erase(str_name.begin() + dat.login.length(), str_name.end());
    str_password.erase(str_password.begin() + dat.password.length(), str_password.end());
    fout << str_name << endl;
    fout << str_password << endl;
    fout.close();
}

int Admin::add(Person& p, string path)
{
    Data admin_dat;
    int flag_login = 0, mem;
    system("cls");
    cout << "Введите логин\n";
    while (flag_login == 0) {
        mem = 0;
        cin >> admin_dat.login;
        for (int i = 0; i < p.data.size(); i++) {
            if (admin_dat.login == p.data[i].login) {
                mem = 1;
            }
        }
        if (mem == 0) {
            flag_login = 1;
        }
        else {
            system("cls");
            cout << "Такой логин уже существует, попробуйте заново\n";
            getchar();
        }
    }
    system("cls");
    cout << "Введите пароль\n";
    cin >> admin_dat.password;
    p.data.push_back(admin_dat);
    encrypt(admin_dat, path);
    return 0;
}

int User::add(Person& p, string path) {
    system("cls");
    Data user_dat;
    int flag_login = 0, mem;
    system("cls");
    cout << "Введите логин\n";
    while (flag_login == 0) {
        mem = 0;
        cin >> user_dat.login;
        for (int i = 0; i < p.data.size(); i++) {
            if (user_dat.login == p.data[i].login) {
                mem = 1;
            }
        }
        if (mem == 0) {
            flag_login = 1;
        }
        else {
            system("cls");
            cout << "Такой логин уже существует, попробуйте заново\n";
            getchar();
        }
    }
    cout << "Введите пароль\n";
    cin >> user_dat.password;
    p.data.push_back(user_dat);
    encrypt(user_dat, path);
    return 0;
}

int User::user_delete(Person& p, string path) {
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
        table << fort::header << "№" << "Логин" << "Пароль" << fort::endr;
        for (int i = 0; i < p.data.size(); i++) {
            if (i + 1 == pointer) {
                table.row(i + 1).set_cell_bg_color(fort::color::cyan);
                table << i + 1 << p.data[i].login << p.data[i].password << fort::endr;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                table << i + 1 << p.data[i].login << p.data[i].password << fort::endr;
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
                    pointer = p.data.size();
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == p.data.size() + 1)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 13) {
                p.data.erase(p.data.begin() + (pointer - 1));
                std::ofstream ofs;
                ofs.open(path, std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                for (int i = 0;i < p.data.size();i++) {
                    encrypt(p.data[i], path);
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

int Admin::user_delete(Person& p, string path) {
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
        table << fort::header << "№" << "Логин" << "Пароль" << fort::endr;
        for (int i = 0; i < p.data.size(); i++) {
            if (i + 1 == pointer) {
                table.row(i + 1).set_cell_bg_color(fort::color::cyan);
                table << i + 1 << p.data[i].login << p.data[i].password << fort::endr;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                table << i + 1 << p.data[i].login << p.data[i].password << fort::endr;
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
                    pointer = p.data.size();
                }
                break;
            }
            else if (choice == 80)
            {
                pointer += 1;
                if (pointer == p.data.size() + 1)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 13) {
                p.data.erase(p.data.begin() + (pointer - 1));
                std::ofstream ofs;
                ofs.open(path, std::ofstream::out | std::ofstream::trunc);
                ofs.close();
                for (int i = 0;i < p.data.size();i++) {
                    encrypt(p.data[i], path);
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