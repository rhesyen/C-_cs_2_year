//Aniela Fendrych
#include <string>
using namespace std;

string UsunSlowo (string s1_org, int a)
{
    string s1 = s1_org;
    string afterString = "";
    int no = a;
    int numberOfWord = -1;
    int numberOfFirstWord = -1;
    int j = 0;
    bool isEmpty = true;

    for (int i = 0; i < s1.size(); i++)//czy s1 jest calkiem pusty
    {
        if (s1[i] != ' ')
        {
            isEmpty = false;
        }
    }

    if (isEmpty == true)
    {
        return afterString;
    }

    do
    {
        if (s1[j] != ' ')
        {
            numberOfFirstWord = j;
        }
        else
        {
            j++;
        }
    } while (numberOfFirstWord == -1); //poczatek pierwszego slowa
    numberOfWord = 1; //wystapilo pierwsze slowo
    for (int i = numberOfFirstWord; i < s1.size(); i++)
    {
        if (numberOfWord == no)
        {
            if (s1[i] != ' ')
            {
                s1[i] = '?'; //dziala!!
            }
            if (s1[i] == ' ' && s1[i + 1] != ' ')//poczatek kolejnego slowa
            {
                numberOfWord++;
            }
        }
        if (s1[i] == ' ' && s1[i + 1] != ' ')//poczatek kolejnego slowa
        {
            numberOfWord++;
        }
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != '?')
        {
            afterString += s1[i];
        }
    }
    return afterString;
}

string NormalizujNapis (string s1_org)
{
    string s1 = s1_org;
    string afterString = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ')
        {
            afterString += s1[i];
            if (s1[i] == '.' || s1[i] == ',')
            {
                afterString += ' ';
            }
            if (s1[i + 1] == ' ')
            {
                afterString += ' ';
                i++;
            }
        }
    }
    s1 = afterString;
    afterString = "";
    bool warning = false;
    int j = s1.size();

    do
    {
        j--;
    } while (s1[j] == ' '); //usuwanie spacji z konca
    
    for (int i = j; i >= 0; i--)
    {
        if (s1[i] == ',' || s1[i] == '.')
        {
            warning = true;
            afterString = s1[i] + afterString;
        }
        if (s1[i] == ' ' && !warning)
        {
            afterString = s1[i] + afterString;
        }
        if (s1[i] != ' ' && s1[i] != ',' && s1[i] != '.')
        {
            afterString = s1[i] + afterString;
            warning = false;  
        }
    }
    return afterString;
}

int StringToInt (string s)
{
    int suma = 0;
    for (int i = 0; i < s.size(); i++)
    {
        suma = suma * 10;
        suma += (int)s[i]-'0';
    }
    return suma;
}

string FormatujNapis (string s1_org, string s2_org, string s3_org, string s4_org)
{
    string s1 = s1_org;
    string s2 = s2_org;
    string s3 = s3_org;
    string s4 = s4_org;
    bool theseAreBrackets = false;
    bool writingA = true;
    bool writingB = false;
    bool dltStuffFrom_a = false;
    string a = ""; //ten trzyma zawartosc stringa do nawiasow
    string b = ""; //ten trzyma zawartosc stringa po nawiasach
    int l1 = 0; //potrzebne do u
    for (int i = 0; i < s1.size(); i++)
    {
        //cout << i << " " << s1[i] << endl;
        if (s1[i] == '{') //wyszukanie operacji
        {
            theseAreBrackets = true; //koniec przepisywania
            writingA = false;
            continue;
        }
        if (!theseAreBrackets && writingA && !dltStuffFrom_a)
        {
            a += s1[i];
        }
        //**************************OPERACJE****************************
        if (s1[i] == 'w' && theseAreBrackets) 
        {
            i += 2;
            if (s1[i] == '1')
            {
                a += s2;
            }
            if (s1[i] == '2')
            {
                a += s3;
            }
            if (s1[i] == '3')
            {
                a += s4;
            }
            continue;
        }
        if (s1[i] == 'p' && theseAreBrackets) 
        {
            i += 2;
            string str_num = "";
            //cout << s1[i] << " i: " << i << endl;
            //cout << s1[i + 1] << " i+1: " << i +1 << endl;
            //cout << s1[i + 2] << " i+2: " << i +2 << endl;
            while (s1[i] != ':' && i < s1.size())
            {
                //cout << s1[i] << " i: " << i << endl;
                str_num += s1[i];
                i += 1;
            }
            i += 1;
            int num = StringToInt(str_num);
            //cout << num << endl;
            //cout << str_num << endl;
            for (int j = num; j > 0; j--)
            {
                a += s1[i];
            }
            //cout << i << " " << s1[i] << endl;
            continue;
        }
        if (s1[i] == 'W' && theseAreBrackets) 
        {
            i += 2;
            string str_temp = "";
            if (s1[i] == '1')
            {
                i += 2; //tu przechodzimy do liczby m
                while (s1[i] != '}' && i < s1.size())
                {
                    str_temp += s1[i];
                    i += 1;
                } //zapisujemy m do str_temp
                int numberOfLettersInW = StringToInt(str_temp); //konwertowanie do int
                str_temp = ""; //znowu zerujemy, zmienna sie przyda
                for (int i = numberOfLettersInW; i > 0; i--) //zapelniona str_temp spacjami
                {
                    str_temp += ' ';
                }
                if (str_temp.size() <= s2.size())
                {
                    for (int i = 0; i < str_temp.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s2[i];
                    }
                }
                else
                {
                    for (int i = 0; i < s2.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s2[i];
                    }
                }
                a += str_temp;
                i -= 1;
                continue;
            }
            if (s1[i] == '2')
            {
                i += 2; //tu przechodzimy do liczby m
                while (s1[i] != '}' && i < s1.size())
                {
                    str_temp += s1[i];
                    i += 1;
                } //zapisujemy m do str_temp
                int numberOfLettersInW = StringToInt(str_temp); //konwertowanie do int
                str_temp = ""; //znowu zerujemy, zmienna sie przyda
                for (int i = numberOfLettersInW; i > 0; i--) //zapelniona str_temp spacjami
                {
                    str_temp += ' ';
                }
                if (str_temp.size() <= s3.size())
                {
                    for (int i = 0; i < str_temp.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s3[i];
                    }
                }
                else
                {
                    for (int i = 0; i < s3.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s3[i];
                    }
                }
                a += str_temp;
                i -= 1;
                continue;
            }
            if (s1[i] == '3')
            {
                i += 2; //tu przechodzimy do liczby m
                while (s1[i] != '}' && i < s1.size())
                {
                    str_temp += s1[i];
                    i += 1;
                } //zapisujemy m do str_temp
                int numberOfLettersInW = StringToInt(str_temp); //konwertowanie do int
                str_temp = ""; //znowu zerujemy, zmienna sie przyda
                for (int i = numberOfLettersInW; i > 0; i--) //zapelniona str_temp spacjami
                {
                    str_temp += ' ';
                }
                if (str_temp.size() <= s4.size())
                {
                    for (int i = 0; i < str_temp.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s4[i];
                    }
                }
                else
                {
                    for (int i = 0; i < s4.size(); i++) //zapelnianie jednym z argumentow
                    {
                        str_temp[i] = s4[i];
                    }
                }
                a += str_temp;
                i -= 1;
                continue;
            }
        }
        if (s1[i] == 'U' && theseAreBrackets)
        {
            i += 2; // przechodzimy do liczby usunietych znakow
            string str_temp = "";
            while (s1[i] != '}' && i < s1.size())
            {
                str_temp += s1[i];
                i += 1;
            } //zapisujemy m do str_temp
            int numberOfDeletedLettersInU = StringToInt(str_temp); //konwertowanie do int
            int neuA = a.size() - numberOfDeletedLettersInU; //nowe a
            string neu_a = "";
            //cout << a << endl;
            for (int j = 0; j < neuA; j++)
            {
                neu_a += a[j];
            }
            //cout << neu_a << endl;
            a = "";
            a = neu_a;
            //zeby wyszlo poza }
            theseAreBrackets = false;
            writingA = true;
            //cout << i << s1[i] << endl;
            continue;
        }
        if (s1[i] == 'u' && theseAreBrackets) //TO NIE DZIALA
        {
            i += 2; // przechodzimy do liczby usunietych znakow
            string str_temp = "";
            //cout << i << endl;
            //cout << s1[i] << endl;
            while (s1[i] != '}' && i < s1.size())
            {
                str_temp += s1[i];
                i += 1;
            } //zapisujemy m do str_temp
            int numberOfDeletedLettersInu = StringToInt(str_temp); //konwertowanie do int
            l1 = numberOfDeletedLettersInu; //tutaj ilosc znakow z a ktore trzeba zignorowac
            //cout << "l1 = " << l1 << endl;
            dltStuffFrom_a = true; //do dokonczenia*/
            i -= 1;
            continue;
        }
        //**************************OPERACJE****************************
        if (s1[i] == '}')
        {
            theseAreBrackets = false;
            writingA = true;
            continue;
        }
        if (!theseAreBrackets && dltStuffFrom_a)
        {
            if (l1 != 0)
            {
                //i += 1; //ignorujemy znak, nie przepisujemy do a
                l1 -= 1; //zmniejszamy ilosc znakow do ignorowania
                //cout << "l1 = " << l1 << endl;
                if (l1 == 0)
                {
                    dltStuffFrom_a = false;
                    continue;
                }
                continue;
            }
        }
        /*if (!theseAreBrackets && writingB)
        {
            b += s1[i];
        }*/
    }
    s1 = "";
    s1 = a + b;
    return s1;
}

string NajwiekszeSlowo (string s1_org)
{
    string s1 = NormalizujNapis(s1_org);
    string biggestWord = "";
    bool isEmpty = true;
    bool timeToChangeThisWord = true;
    bool timeToSkip = false;
    int j = 0;
    for (int i = 0; i < s1.size(); i++)//czy s1 jest calkiem pusty
    {
        if (s1[i] != ' ')
        {
            isEmpty = false;
        }
    }

    if (isEmpty == true)
    {
        return biggestWord;
    }

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != ' ' && timeToChangeThisWord) //funkcja do przepisywania bezmyslnie
        {
            biggestWord += s1[i];
        } //koniec pierwszego slowa, zostalo zapisane
        if (s1[i] == ' ')
        {
            timeToChangeThisWord = false; //przy pierwszej spacji warunek pierwszego slowa znika
            timeToSkip = false;
            j=0;
            //i++;
        }
        if (s1[i] != ' ' && !timeToChangeThisWord && !timeToSkip) //porownywanie slow miedzy soba
        {
            //cout << biggestWord[j] << " > " << s1[i] << " " << i <<  " = " << (biggestWord[j] > s1[i]) << endl;
            //cout << biggestWord[j] << " < " << s1[i] << " " << i << " = " << (biggestWord[j] < s1[i]) << endl;
            //cout << biggestWord[j] << " == " << s1[i] << " " << i << " = " << (biggestWord[j] == s1[i]) << endl;
            if (biggestWord[j] > s1[i]) //pomijamy cale to slowo, nie bedzie wieksze od biggestword
            {
                //cout << "Skipping word" << endl;
                timeToSkip = true;
            }
            if (biggestWord[j] < s1[i]) //usuniecie starego najwiekszego slowa
            {
                biggestWord = s1[i];
                //cout << biggestWord[j] << " < " <<  s1[i] << ", " << j << endl;
                timeToChangeThisWord = true;
                j=1;
                //i++;
            }
            if (biggestWord[j] == s1[i])
            {
                j++;
            }
        }
        //******************************************
        //cout << biggestWord << " i:  " <<  i << " Stan ttc " << timeToChangeThisWord << endl;
    }
    return biggestWord;
}
