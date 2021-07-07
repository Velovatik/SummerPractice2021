#include <iostream> 
#include <map>      //Для словаря
#include <string>   //Для строки
#include <clocale>  //Для русского языка
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian"); //Русский язык в консоли
    SetConsoleCP(1251);           //<-Русский язык в консоли
    SetConsoleOutputCP(1251);     //<-для всего текста
    string forcontinue = "1"; //Переменная, отвечающая за повторы цикла
    int let = 1; //Счетчик количества букв в строке для теста, если let = 0, то просит ввести текст снова
    int a = 1;
    while (a == 1) {
        string forcontinue; //Переменная, отвечающая за повторы цикла
        string text; //Текст для анализа, вводимый с клавиатуры
        int let = 0;
        cout << "Скопируйте нужный текст в файл data.txt и откройте приложение еще раз " << endl;
        cout << "\n";
        while (let == 0) {
            string path = "data.txt"; //Произведем чтение текста из файла
            ifstream fin;
            fin.open(path);
            if (!fin.is_open())
            {
                cout << "Ошибка открытия файла. Создайте файл data.txt в одной папке с приложением с кодировкой Ansi и попробуйте снова" << endl;
                cout << "\n";
                system("PAUSE");
            }
            else
            {
                cout << "Файл открыт" << endl;
                cout << "\n";
                cout << "Ожидайте, происходит обработка текста . . ." <<endl;
                cout << "\n";
                string str;
                while (!fin.eof()) //Метод eof отлавливает конец файла
                {
                    fin >> str;
                    text += str;
                    for (int i = 0; i < text.size(); i++) { // идем по символам
                        while (let == 0) {
                            if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' ||
                                text[i] >= 'А' && text[i] <= 'Я' || text[i] >= 'а' && text[i] <= 'я' ||
                                text[i] == 'Ё' || text[i] == 'ё')
                            {
                                let++;
                            }
                        }
                    }
                    if (let == 0) {
                        cout << "В предложенном вами тексте отсутствуют буквы, "
                            << "должно быть, вы ошиблись" << endl;
                        cout << "Попробуйте ввести другой текст в файл <<data.txt>> и запустите программу снова..." << endl;
                        system("PAUSE");
                    }
                }
            }
            fin.close();
        }

        map <char, int> letters; //Создание словаря
        for (int i = 0; i < text.size(); i++) //Проход по каждому символу текста
        {
            char current = text[i];
            if (text[i] <= 'Z' && text[i] >= 'A')
            {
                current = (char)((int)text[i] - (int)'A' + (int)'a'); //Приведение всех символов англ алфавита к нижнему регистру
            }
            if (text[i] <= 'Я' && text[i] >= 'А')
            {
                current = (char)((int)text[i] - (int)'А' + (int)'а'); //Приведение всех символов рус алфавита к нижнему регистру
            }
            if ((current <= 'z' && current >= 'a') || (current >= 'а' && current <= 'я')) //Проверка, использовался ли уже такой символ
            {
                if (letters.find(current) == letters.end()) letters[current] = 1; //Если отсутствует
                else letters[current]++;//Если уже есть
            }
        }
        //Сортировка и вывод
        map<int, char> letters_sorted;
        map<char, int>::iterator p = letters.begin();
        for (;p != letters.end();++p)
        {
            int f2 = p->first;
            double f1 = p->second;
            letters_sorted[f1] = f2;
        }
        map<int, char>::iterator p2 = letters_sorted.begin();
        //Конец сортировки
        //Вывод отсортированного массива на экран
        for (const auto& p : letters_sorted) { //этот цикл - фишка с++11 range based for loops
            
            cout << p.first << " = " << p.second << "\n";
        }
        cout << "Если хотите завершить, введите любой символ  "
            << "Если хотите продолжить, внесите изменения в data.txt и введите 1: ";
        getline(cin, forcontinue);

        if (forcontinue == "1") a = 1;
        else {
            a = 0;
        }
    }
    cout << "Для завершения работы закройте окно...";
    system("PAUSE");
    return 0;
}