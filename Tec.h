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
        string rubles; // ���� � ������
        string coins; // ���� � ��������
        int check_price(string word); // ������� �������� �����
        void fill_price(); // ���������� ����
    };
    static string warehouse; // �������� ������
    string name; //�������� ������
    string brand; //�������� ������
    string country; //������ �������
    string year; //��� �������
    Price price;// ����
    void fill_tech(); // ���������� ������ �������
};