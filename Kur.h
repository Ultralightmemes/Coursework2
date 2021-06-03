#pragma once
#include "Tec.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include "fort.hpp"
class Kurs {
public:
    vector<Tech> MyVector; //Вектор с данными о товарах
    vector<Tech>::iterator it; //итератор вектора
    Tech tec;//Класс техники
    Kurs(); //конструктор без параметров
    Kurs(Tech t); //Конструктор с параметрами;
    ~Kurs();//Деструктор
    int sort_up_price(Kurs& k); //Сортировки 
    int sort_down_price(Kurs& k);
    int sort_up_year(Kurs& k);
    int sort_down_year(Kurs& k);
    int sort_up_country(Kurs &k);
    int sort_down_country(Kurs &k);
    int sort_up_brand(Kurs &k);
    int sort_down_brand(Kurs &k);
    int sort_up_name(Kurs &k);
    int sort_down_name(Kurs &k);
    friend int delete_kurs(Kurs &k);//удаления товара
    friend int show_kurs(Kurs k);//отображение товара
    friend int edit_kurs(Kurs &k);//изменение товара
    friend void add_kurs(Kurs &k);//Добавление товара
    friend void file_write(Kurs k);//Запись в файл
    friend void file_read(Kurs &k);//чтение из файла
    friend int change_tech(Kurs &k, int num);//изменение конкретного товара
};

