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
        string fileName;
        string forcontinue; //Переменная, отвечающая за повторы цикла
        string text; //Текст для анализа, вводимый с клавиатуры
        int let = 0;
        cout << "Файл должен быть в формате .txt"<<endl;
        cout << "\n";
        cout << "Для корректной обработки рекомендуется кодировка Ansi" << endl;
        cout << "\n";
        cout << "Имя файла вводится без указания формата" << endl;
        cout << "\n";
        cout << "Введите имя файла: ";
        //cin.ignore();
        fileName.erase();
        getline(cin, fileName);
        //cin >> fileName;
        fileName += ".txt";
        while (let == 0) {
            ifstream fin;
            fin.open(fileName);//Произведем чтение текста из файла
            while (!fin.is_open())
            {
                cout << " Ошибка открытия файла. Переместите необходимый файл в одну папку с приложением с кодировкой Ansi " <<endl;
                cout << " и попробуйте снова: ";
                fileName.erase();
                getline(cin, fileName); //Продолжает просить ввести имя файла, пока не будет открыт
                fileName += ".txt";
                fin.open(fileName);
                
            }
            
            cout << "Файл открыт" << endl; 
            cout << "\n";
            cout << "Ожидайте, происходит обработка текста . . ." << endl;
            cout << "\n";
            string str;
            while (!fin.eof()) //Метод eof отлавливает конец файла
            {
                fin >> str;
                text += str;
                for (int i = 0; i < text.length(); i++) { // идем по символам
                    if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' ||
                        text[i] >= 'А' && text[i] <= 'Я' || text[i] >= 'а' && text[i] <= 'я' ||
                        text[i] == 'Ё' || text[i] == 'ё')
                    {
                        let++;
                        break;
                    
                    }
                }
                if (let == 0) {
                    cout << "В предложенном вами тексте отсутствуют буквы, "
                         << "должно быть, вы ошиблись" << endl;
                    cout << "Для продолжения введите название другого файла: ";
                    fileName.erase();
                    getline(cin, fileName); //Продолжает просить ввести имя файла, пока не будет открыт
                    fileName += ".txt";
                    fin.open(fileName);
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
                else letters[current]++; //Если уже есть
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
             << "Если хотите продолжить, введите 1: ";
        cout << "\n";
        fileName.erase();
        cin >> forcontinue;
        cin.ignore();
        if (forcontinue == "1") a = 1;
            else {
                a = 0;
            }
        
    }
    cout << "Для завершения работы закройте окно..." << endl;
    system("PAUSE");
    return 0;
}