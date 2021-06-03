//#include "Menus.h"
//int Menus::menu()
//{
//    string Menu[3] = { "Войти как администратор", "Войти как пользователь", "Выход" };
//    int pointer = 0;
//    int choice;
//    while (true)
//    {
//        system("cls");
//
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        std::cout << "Main Menu\n\n";
//
//        for (int i = 0; i < 3; ++i)
//        {
//            if (i == pointer)
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//                std::cout << Menu[i] << endl;
//            }
//            else
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//                cout << Menu[i] << endl;
//            }
//        }
//
//        while (true)
//        {
//            choice = _getch();
//            if (choice == 72)
//            {
//                pointer -= 1;
//                if (pointer == -1)
//                {
//                    pointer = 2;
//                }
//                break;
//            }
//            else if (choice == 80)
//            {
//                pointer += 1;
//                if (pointer == 3)
//                {
//                    pointer = 0;
//                }
//                break;
//            }
//            else if (choice == 13)
//            {
//                switch (pointer)
//                {
//                case 0:
//                {
//                    admin_login();
//                    break;
//                }
//                case 1:
//                {
//                    user_login();
//                    system("pause");
//                } break;
//                case 2:
//                {
//                    exit(0);
//                    return 0;
//                } break;
//                }
//                break;
//            }
//        }
//
//        Sleep(150);
//    }
//
//    return 0;
//}
//
//int Menus::admin_menu() {
//    string Menu[3] = { "Управление аккаунтами", "Управление товарами", "Сортировка товаров" };
//    int pointer = 0;
//    int choice;
//    while (true)
//    {
//        system("cls");
//
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        std::cout << "Admin Menu\n\n";
//
//        for (int i = 0; i < 3; ++i)
//        {
//            if (i == pointer)
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//                std::cout << Menu[i] << endl;
//            }
//            else
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//                cout << Menu[i] << endl;
//            }
//        }
//
//        while (true)
//        {
//            choice = _getch();
//            if (choice == 72)
//            {
//                pointer -= 1;
//                if (pointer == -1)
//                {
//                    pointer = 2;
//                }
//                break;
//            }
//            else if (choice == 80)
//            {
//                pointer += 1;
//                if (pointer == 3)
//                {
//                    pointer = 0;
//                }
//                break;
//            }
//            else if (choice == 13)
//            {
//                switch (pointer)
//                {
//                case 0:
//                {
//                    admin_user_manage();
//                    system("pause");
//                    break;
//                }
//                case 1:
//                {
//                    admin_tec_manage();
//                    system("pause");
//                } break;
//                case 2:
//                {
//
//                } break;
//                }
//                break;
//            }
//            else if (choice == 75) {
//                menu();
//            }
//        }
//        Sleep(150);
//    }
//    return 0;
//}
//
//int Menus::admin_tec_manage() {
//    string Menu[4] = { "Добавление товара", "Удаление товара", "Редактирование товара", "Просмотр сделок" };
//    int pointer = 0;
//    int choice;
//    while (true)
//    {
//        system("cls");
//
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        std::cout << "Меню управления пользователями\n\n";
//
//        for (int i = 0; i < 4; ++i)
//        {
//            if (i == pointer)
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//                std::cout << Menu[i] << endl;
//            }
//            else
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//                cout << Menu[i] << endl;
//            }
//        }
//
//        while (true)
//        {
//            choice = _getch();
//            if (choice == 72)
//            {
//                pointer -= 1;
//                if (pointer == -1)
//                {
//                    pointer = 4;
//                }
//                break;
//            }
//            else if (choice == 80)
//            {
//                pointer += 1;
//                if (pointer == 5)
//                {
//                    pointer = 0;
//                }
//                break;
//            }
//            else if (choice == 13)
//            {
//                switch (pointer)
//                {
//                case 0:
//                {
//                    add_kurs(kursach);
//                    system("pause");
//                    break;
//                }
//                case 1:
//                {
//                    /*user_login();*/
//                    system("pause");
//                } break;
//                case 2:
//                {
//                    change_tech(kursach);
//                } break;
//                case 3:
//                {
//
//                }break;
//                }
//                break;
//            }
//            else if (choice == 75) {
//                admin_menu();
//            }
//        }
//
//        Sleep(150);
//    }
//    return 0;
//}
//
//int Menus::user_menu() {
//    string Menu[4] = { "Просмотр товаров", "Сортировка товаров", "Заключение сделки", "Просмотр сделок" };
//    int pointer = 0;
//    int choice;
//    while (true)
//    {
//        system("cls");
//
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        std::cout << "Admin Menu\n\n";
//
//        for (int i = 0; i < 4; ++i)
//        {
//            if (i == pointer)
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//                std::cout << Menu[i] << endl;
//            }
//            else
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//                cout << Menu[i] << endl;
//            }
//        }
//
//        while (true)
//        {
//            choice = _getch();
//            if (choice == 72)
//            {
//                pointer -= 1;
//                if (pointer == -1)
//                {
//                    pointer = 3;
//                }
//                break;
//            }
//            else if (choice == 80)
//            {
//                pointer += 1;
//                if (pointer == 4)
//                {
//                    pointer = 0;
//                }
//                break;
//            }
//            else if (choice == 13)
//            {
//                switch (pointer)
//                {
//                case 0:
//                {
//                    admin_user_manage();
//                    system("pause");
//                    break;
//                }
//                case 1:
//                {
//                    admin_tec_manage();
//                    system("pause");
//                } break;
//                case 2:
//                {
//
//                } break;
//                case 3:
//                {
//
//                } break;
//                }
//                break;
//            }
//            else if (choice == 75) {
//                menu();
//            }
//        }
//        Sleep(150);
//    }
//    return 0;
//}
//
//int Menus::admin_user_manage() {
//    string Menu[4] = { "Добавление администратора", "Удаление администратора", "Добавление пользователя", "Удаление пользователя" };
//    int pointer = 0;
//    int choice;
//    while (true)
//    {
//        system("cls");
//
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        std::cout << "Меню управления пользователями\n\n";
//
//        for (int i = 0; i < 4; ++i)
//        {
//            if (i == pointer)
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
//                std::cout << Menu[i] << endl;
//            }
//            else
//            {
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//                cout << Menu[i] << endl;
//            }
//        }
//
//        while (true)
//        {
//            choice = _getch();
//            if (choice == 72)
//            {
//                pointer -= 1;
//                if (pointer == -1)
//                {
//                    pointer = 4;
//                }
//                break;
//            }
//            else if (choice == 80)
//            {
//                pointer += 1;
//                if (pointer == 5)
//                {
//                    pointer = 0;
//                }
//                break;
//            }
//            else if (choice == 13)
//            {
//                switch (pointer)
//                {
//                case 0:
//                {
//                    admin.add(admin, admin_out);
//                    system("pause");
//                    break;
//                }
//                case 1:
//                {
//                    /*user_login();*/
//                    system("pause");
//                } break;
//                case 2:
//                {
//                    user.add(user, user_out);
//                } break;
//                case 3:
//                {
//
//                }break;
//                }
//                break;
//            }
//            else if (choice == 75) {
//                admin_menu();
//            }
//        }
//
//        Sleep(150);
//    }
//    return 0;
//}
