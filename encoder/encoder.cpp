#include "TextWork.h"
using namespace lib;

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    int length = 1;
    bool loopWhile = true;

    while (loopWhile)
    {
        

        cout << "Добро пожаловать в программу шифрования. Выберите нужное вам действие"
            << endl << "1. Зашифровать файл и поставить цифровую подпись."
            << endl << "2. Разшифровать файл и проверить цифровую подпись."
            << endl << "3. Инфо."
            << endl << "4. Выход." << endl;

        string check;
        cin >> check;

        if (check == "1")
        {
            string way;
            int lengthKey;
            CheckCorrectWayLengthKey(way, lengthKey);
            EncoderUI(way, lengthKey);
            cout << "Шифрованине завершено. Файл сохранен на указаном пути.";
            _getch();
        }
        else if (check == "2")
        {
            string way;
            int lengthKey;
            CheckCorrectWayLengthKey(way, lengthKey);
            DecoderUI(way, lengthKey);
            cout << "Дешифрованине завершено. Файл сохранен на указаном пути.";
            _getch();
        }
        else if (check == "3")
        {
            cout << "Данная программа является шифратором на основе алгоритма ThreeFish. Реализация поддерживает выбор длины ключа на 32, 64 или 128 байтов."
                << endl << "Так же данная утилита производит цифровую подпись через алгоритм HMAC-SHA256." << endl;
            _getch();
        }
        else if(check == "4")
            loopWhile = false;
        else
        {
            cout << "Неверное значение. Нажмите Enter и введите число заново" << endl;
            _getch();
        }
        system("cls");
    }
}