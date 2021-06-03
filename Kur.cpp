#include "Kur.h"
Kurs::Kurs() {
    tec.brand = '0';
    tec.country = '0';
    tec.name = '0';
    tec.price.coins = '0';
    tec.price.rubles = '0';
    tec.year = '0';
    MyVector.push_back(tec);
}

Kurs::Kurs(Tech t) {
    MyVector.push_back(tec);
}

Kurs::~Kurs() {
    MyVector.clear();
}

int edit_kurs(Kurs &k) {
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
            if (i+1 == pointer) {
                table.row(i+1).set_cell_bg_color(fort::color::cyan);
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
                if (pointer == k.MyVector.size()+1)
                {
                    pointer = 1;
                }
                break;
            }
            else if (choice == 13) {
                change_tech(k, pointer - 1);
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

void file_write(Kurs k)//запись всех итераций
{
    string path = "File.txt";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        cout << "Ошибка отрытия файла!\n";
    }
    else {
        vector<Tech>::iterator it;
        for (it = k.MyVector.begin(); it < k.MyVector.end() - 1; it++) {
            fout << it->name << endl;
            fout << it->brand << endl;
            fout << it->country << endl;
            fout << it->price.rubles << endl;
            fout << it->price.coins << endl;
            fout << it->year << endl;
        }
        it = k.MyVector.end() - 1;
        fout << it->name << endl;
        fout << it->brand << endl;
        fout << it->country << endl;
        fout << it->price.rubles << endl;
        fout << it->price.coins << endl;
        fout << it->year;
    }
    fout.close();
}

void file_read(Kurs &k)//чтение всех записей
{
    string path = "File.txt";
    ifstream fin;
    Tech t;
    fin.open(path, ios_base::in);
    int i = 0;
    if (!fin.is_open()) {
        cout << "Ошибка отркытия файла!\n";
    }
    else {
        cout << "Файл открыт!\n";
        while (!fin.eof()) {
            getline(fin, t.name);
            getline(fin, t.brand);
            getline(fin, t.country);
            getline(fin, t.price.rubles);
            getline(fin, t.price.coins);
            getline(fin, t.year);
            k.MyVector.push_back(t);
        }
    }
}

int change_tech(Kurs &k, int num)
{
    int pointer = 0;
    int choice;
    while (true)
    {
        fort::char_table table;
        system("cls");
        table.set_border_style(FT_BASIC2_STYLE);
        table.column(0).set_cell_text_align(fort::text_align::center);
        table.column(1).set_cell_text_align(fort::text_align::center);
        table.column(2).set_cell_text_align(fort::text_align::center);
        table.column(3).set_cell_text_align(fort::text_align::center);
        table.column(4).set_cell_text_align(fort::text_align::center);
        table.column(5).set_cell_text_align(fort::text_align::center);
        table.column(6).set_cell_text_align(fort::text_align::center);
        table << fort::header << "Бренд" << "Страна" << "Название" << "Цена(рублей)" << "Цена(копеек)" <<  "Год производства" << fort::endr;

        table.cell(1, pointer).set_cell_bg_color(fort::color::cyan);
        table << k.MyVector[num].brand << k.MyVector[num].country << k.MyVector[num].name << k.MyVector[num].price.rubles << k.MyVector[num].price.coins  << k.MyVector[num].year << fort::endr;
       
        system("cls");
        std::cout << table.to_string() << std::endl;
        while (true)
        {
            choice = _getch();
            if (choice == 75)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 5;
                }
                break;
            }
            else if (choice == 77)
            {
                pointer += 1;
                if (pointer == 6)
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
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].brand << ")" << endl << endl;
                    cin >> k.MyVector[num].brand;
                    file_write(k);
                    break;
                }
                case 1:
                {
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].country << ")" << endl << endl;
                    cin >> k.MyVector[num].country;
                    file_write(k);
                    system("pause");
                } break;
                case 2:
                {
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].name << ")" << endl << endl;
                    cin >> k.MyVector[num].name;
                    file_write(k);
                } break;
                case 3:
                {
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].price.rubles << ")" << endl << endl;
                    cin >> k.MyVector[num].price.rubles;
                    file_write(k);
                }break;
                case 4:
                {
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].price.coins << ")" << endl << endl;
                    cin >> k.MyVector[num].price.coins;
                    file_write(k);
                }break;
                case 5:
                {
                    cout << "Введите новое значение. (Старое значение - " << k.MyVector[num].year << ")" << endl << endl;
                    cin >> k.MyVector[num].year;
                    file_write(k);
                }break;
                }
                break;
            }
            else if (choice == 8){
                return 0;
                break;
            }
        }
        Sleep(150);
    }
    return 0;
}

void add_kurs(Kurs& k) {
    system("cls");
    Tech add_tech;
    add_tech.fill_tech();
    k.MyVector.push_back(add_tech);
    file_write(k);
}

int delete_kurs(Kurs& k) {
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
                k.MyVector.erase(k.MyVector.begin() + (pointer - 1));
                file_write(k);
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

int Kurs::sort_down_name(Kurs &k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
       for (int j = i; j < k.MyVector.size(); j++) {
           if (k.MyVector[j].name < k.MyVector[i].name) {
               new_tech = k.MyVector[j];
               k.MyVector[j] = k.MyVector[i];
               k.MyVector[i] = new_tech;
           }
       }
    }
    return 0;
}

int Kurs::sort_up_name(Kurs &k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].name > k.MyVector[i].name) {
                new_tech = k.MyVector[i];
                k.MyVector[i] = k.MyVector[j];
                k.MyVector[j] = new_tech;
            }
        }
    }
    return 0;
}
int Kurs::sort_down_brand(Kurs &k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].brand < k.MyVector[i].brand) {
                new_tech = k.MyVector[j];
                k.MyVector[j] = k.MyVector[i];
                k.MyVector[i] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_up_brand(Kurs& k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].brand > k.MyVector[i].brand) {
                new_tech = k.MyVector[i];
                k.MyVector[i] = k.MyVector[j];
                k.MyVector[j] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_down_country(Kurs &k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].country < k.MyVector[i].country) {
                new_tech = k.MyVector[j];
                k.MyVector[j] = k.MyVector[i];
                k.MyVector[i] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_up_country(Kurs &k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].country > k.MyVector[i].country) {
                new_tech = k.MyVector[i];
                k.MyVector[i] = k.MyVector[j];
                k.MyVector[j] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_down_year(Kurs& k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].year < k.MyVector[i].year) {
                new_tech = k.MyVector[j];
                k.MyVector[j] = k.MyVector[i];
                k.MyVector[i] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_up_year(Kurs& k) {
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].year > k.MyVector[i].year) {
                new_tech = k.MyVector[i];
                k.MyVector[i] = k.MyVector[j];
                k.MyVector[j] = new_tech;
            }
        }
    }
    return 0;
}

int Kurs::sort_down_price(Kurs& k)
{
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        for (int j = i; j < k.MyVector.size(); j++) {
            if (k.MyVector[j].price.rubles < k.MyVector[i].price.rubles) {
                new_tech = k.MyVector[j];
                k.MyVector[j] = k.MyVector[i];
                k.MyVector[i] = new_tech;
            }
            else if (k.MyVector[j].price.rubles == k.MyVector[i].price.rubles) {
                if (k.MyVector[j].price.coins < k.MyVector[i].price.coins) {
                    new_tech = k.MyVector[j];
                    k.MyVector[j] = k.MyVector[i];
                    k.MyVector[i] = new_tech;
                }
            }
        }
    }
    return 0;
}

int Kurs::sort_up_price(Kurs& k)
{
    Tech new_tech;
    for (int i = 0; i < k.MyVector.size(); i++) {
        int num_i = NULL;
        for (int p = 0; p < k.MyVector[i].price.rubles.length(); p++) {
            num_i = num_i * 10 + k.MyVector[i].price.rubles[p] - 0x30;
        }
        for (int j = i; j < k.MyVector.size(); j++) {
            int num_j = NULL;
            for (int l = 0; l < k.MyVector[j].price.rubles.length(); l++) {
                num_j = num_j * 10 + k.MyVector[j].price.rubles[l] - 0x30;
            }
            if (num_j > num_i) {
                new_tech = k.MyVector[i];
                k.MyVector[i] = k.MyVector[j];
                k.MyVector[j] = new_tech;
            }
            else if (num_j == num_i) {
                if (k.MyVector[j].price.coins > k.MyVector[i].price.coins) {
                    new_tech = k.MyVector[i];
                    k.MyVector[i] = k.MyVector[j];
                    k.MyVector[j] = new_tech;
                }
            }
        }
    }
    return 0;
}

int show_kurs(Kurs k) {
    int pointer = 1;
    int choice;
    int name_count = 0, brand_count = 0, country_count = 0, price_count = 0, year_count = 0;
    while(true){
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
        table << fort::header << "№" << "Бренд" << "Страна" << "Название" << "Цена(рублей)" << "Цена(копеек)" << "Название склада" << "Год производства" << fort::endr;
        if (pointer == 4) {
            table.cell(0, pointer).set_cell_bg_color(fort::color::cyan);
            table.cell(0, pointer + 1).set_cell_bg_color(fort::color::cyan);
        }
        else {
            table.cell(0, pointer).set_cell_bg_color(fort::color::cyan);
        }
        for (int i = 0; i < k.MyVector.size(); i++) {
            table << i + 1 << k.MyVector[i].brand << k.MyVector[i].country << k.MyVector[i].name << k.MyVector[i].price.rubles << k.MyVector[i].price.coins << k.MyVector[i].warehouse << k.MyVector[i].year << fort::endr;
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
                    pointer = 7;
                }
                else if (pointer == 5)
                {
                    pointer = 4;
                }
                break;
            }
            else if (choice == 77)
            {
                pointer += 1;
                if (pointer == 8)
                {
                    pointer = 1;
                }
                else if (pointer == 5)
                {
                    pointer = 6;
                }
                break;
            }
            else if (choice == 13) {
                switch (pointer)
                {
                case 1:
                {
                    brand_count++;
                    if (brand_count % 2 == 1) {
                        k.sort_up_brand(k);
                    }
                    else {
                        k.sort_down_brand(k);
                    }
                } break;
                case 2:
                {
                    country_count++;
                    if (country_count % 2 == 1) {
                        k.sort_up_country(k);
                    }
                    else {
                        k.sort_down_country(k);
                    }
                } break;
                case 3:
                {
                    name_count++;
                    if (name_count % 2 == 1) {
                        k.sort_up_name(k);
                    }
                    else {
                        k.sort_down_name(k);
                    }
                } break;
                case 4:
                {
                    price_count++;
                    if (price_count % 2 == 1) {
                        k.sort_up_price(k);
                    }
                    else {
                        k.sort_down_price(k);
                    }
                }break;
                case 6:
                {

                }break;
                case 7:
                {
                    year_count++;
                    if (year_count % 2 == 1) {
                        k.sort_up_year(k);
                    }
                    else {
                        k.sort_down_year(k);
                    }
                }break;
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