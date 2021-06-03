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

class Person { // ����������� ����� ��������
protected:
    void encrypt(Data dat, string path); //����������
public:
    friend Data decipher(Person &pers, string path); // ������������
    vector<Data> data;
    virtual int add(Person &p, string path) = 0; //����������� �������
    virtual int user_delete(Person& p, string path) = 0;
};

class User : public Person { //�������� �����
public:
    int add(Person &p, string path) override; // ��������������� ����� ���������� ������������
    int user_delete(Person& p, string path) override; // ���������������� ������ �������� ������������
};

class Admin : public Person { // �������� �����
public:
    int add(Person& p, string path) override; // ��������������� ����� ���������� ��������������
    int user_delete(Person& p, string path) override;// ���������������� ������ �������� ��������������
};