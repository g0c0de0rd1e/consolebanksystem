#ifdef _WIN32
#include <conio.h>
#include <windows.h>

#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#include "header.hpp"
#include "check.hpp"
#include "menu.hpp"
#include "listfunctions.hpp"
#include <iostream>
#include <thread>
#include <locale>

int main() {
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);


    displayMenu();

    My_List *list = nullptr;
    int ItemsPerPage = 10, currentPage = 1;
    
    int choice = 1;

    while (true) {
        choice = show_menu(choice);
        if (choice == 14) {
            bool exit_menu2 = false;
            while(!exit_menu2){
                int save_choice = show_menu2();
                
                int key2 = _getch();
              
                switch (key2){
                
                case 72:
                
                        if (save_choice >= 1){
                            --save_choice;
                        }
                        break;
                   
    case 80:
   
                        if (save_choice < 5){
                            ++save_choice;
                        }
                        break;
                    
                    case 13:
                   
                        switch (save_choice){
                            case 1:
                                save_to_text_file(list);
                                std::cout << "Файл успешно сохранен";
                                break;
                            case 2: 
                                save_to_binary_file(list);
                                std::cout << "Файл успешно сохранен";
                                break;
                            case 3:
                                save_to_text_file(list);
                                save_to_binary_file(list);
                                std::cout << "Файл успешно сохранен";
                                break;
                            case 4:
                                exit_menu2 = true;
                                break;
                            case 5:
                                bool exit_menu3 = false;
                                while(!exit_menu3){
                                    int new_choice = show_menu3();
                                    
                                    int key3 = _getch();
                                    
                                    switch (key3){ 
                                        
    case 72:
    
                                            if(new_choice >= 1){
                                                --new_choice;
                                            }
                                            break;
                                        
    case 80:
    
                                            if (new_choice < 2){
                                                ++new_choice;
                                            }
                                            break;
                    
                                        case 13:
                                            switch (new_choice){
                                                case 1:
                                                system(CLEAR_SCREEN);
                                                    std::cout << 
"Выход...";
                                                    clear_data(list);
                                                    exit(0);
                                                case 2:
                                                    exit_menu3 = true;
                                                    break;
                                            }
                                            break;
                                    }
                                }
                                break;
                        }
                        break;
                }
            }
        }
        int key = _getch();
        switch (key) {
        case 72:
                if (choice >= 1) {
                    --choice;
                }
                break;
            case 80:
                if (choice < 12) {
                    ++choice;
                }
                break;
            case 13:
                switch (choice) {
                    case 14:
                        break;
                    case 1:
                        create_my_list(&list);
                        break;
                    case 2:
                        showbase(list, ItemsPerPage, currentPage);
                        break;
                    case 3: 
                        sort(list);
                        break;
                    case 4:
                        delete_node(&list);
                        break;
                    case 5:
                        findTop5LargestDepositors(list);
                        break;
                    case 6:
                    findMax(list);
                    break;
                    case 7:
                        printClientInfo(list);
                        break;
                    case 8:
                    edit_field(list);
                    break;
                    case 9:
                        save_to_text_file(list);
                        break;
                    case 10:
                        save_to_binary_file(list);
                        break;
                    case 11:
                        read_from_text_file(&list);
                        break;
                    case 12:
                        read_from_binary_file(&list);
                        break;
                    case 13:
                    system("start https://github.com/FPWex4mple");
                    break;
                    default:
                        std::cout << "Неверный выбор, попробуйте еще 
раз\n";
                        break;
                }
                break;
        }
    }
    
    return 0;
}

