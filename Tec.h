#pragma once
#include <iostream>
#include <string>
using namespace std;
class Tech
{
public:
    class Price
    {
    public:
        string rubles; // цена в рублях
        string coins; // цена в копейках
        int check_price(string word); // Функция проверки ввода
        void fill_price(); // заполнение цены
    };
    static string warehouse; // Название склада
    string name; //Название товара
    string brand; //Название бренда
    string country; //страна выпуска
    string year; //год издания
    Price price;// цена
    void fill_tech(); // заполнение класса техника
};