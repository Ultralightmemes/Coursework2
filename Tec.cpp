#include "Tec.h"
void Tech::fill_tech()
{
    cout << "������� �������� ������:\n";
    cin >> name;
    cout << "������� �������� ������:\n";
    cin >> brand;
    cout << "������� ������ �������:\n";
    cin >> country;
    cout << "������� ��� ������������:\n";
    cin >> year;
    price.fill_price();
}

int Tech::Price::check_price(string word)
{
    string price = "0123456789" ;
    int word_counter = 0, counter = 0;
    for (int i = 0;i < word.size(); i++) {
        for (int k = 0; k < price.size();k++) {
            if (word[i] == price[k]) {
                word_counter++;
            }
        }
        if (word_counter != 0) {
            counter++;
        }
    }
    if (counter == word.size()) {
        return 1;
    }
    return 0;
}

void Tech::Price::fill_price()
{
    int check_rubles = 0, check_coins = 0;
    cout << "������� ��������� � ������:\n";
    while (check_rubles == 0) {
        cin >> rubles;
        check_rubles = check_price(rubles);
        if (check_rubles == 0) {
            cout << "���������� ��� ���\n";
        }
    }
    cout << "������� ��������� � ��������:\n";
    while (check_coins == 0) {
        cin >> coins;
        check_coins = check_price(coins);
        if (check_coins == 0) {
            cout << "���������� ��� ���\n";
        }
    }
}

string Tech::warehouse = "������";