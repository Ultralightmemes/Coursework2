#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "fort.hpp"
#include <conio.h>
using namespace std;
class Data {
public:
    string login;
    string password;
};

class Person { // абстрактный класс человека
protected:
    void encrypt(Data dat, string path); //Шифрование
public:
    friend Data decipher(Person &pers, string path); // Дешифрование
    vector<Data> data;
    virtual int add(Person &p, string path) = 0; //Виртуальные функции
    virtual int user_delete(Person& p, string path) = 0;
};

class User : public Person { //дочерний класс
public:
    int add(Person &p, string path) override; // переопределённый метод добавления пользователя
    int user_delete(Person& p, string path) override; // переопределенный метода удаления пользователя
};

class Admin : public Person { // дочерний класс
public:
    int add(Person& p, string path) override; // переопределённый метод добавления администратора
    int user_delete(Person& p, string path) override;// переопределенный метода удаления администратора
};