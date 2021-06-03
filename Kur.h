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
    vector<Tech> MyVector; //������ � ������� � �������
    vector<Tech>::iterator it; //�������� �������
    Tech tec;//����� �������
    Kurs(); //����������� ��� ����������
    Kurs(Tech t); //����������� � �����������;
    ~Kurs();//����������
    int sort_up_price(Kurs& k); //���������� 
    int sort_down_price(Kurs& k);
    int sort_up_year(Kurs& k);
    int sort_down_year(Kurs& k);
    int sort_up_country(Kurs &k);
    int sort_down_country(Kurs &k);
    int sort_up_brand(Kurs &k);
    int sort_down_brand(Kurs &k);
    int sort_up_name(Kurs &k);
    int sort_down_name(Kurs &k);
    friend int delete_kurs(Kurs &k);//�������� ������
    friend int show_kurs(Kurs k);//����������� ������
    friend int edit_kurs(Kurs &k);//��������� ������
    friend void add_kurs(Kurs &k);//���������� ������
    friend void file_write(Kurs k);//������ � ����
    friend void file_read(Kurs &k);//������ �� �����
    friend int change_tech(Kurs &k, int num);//��������� ����������� ������
};

