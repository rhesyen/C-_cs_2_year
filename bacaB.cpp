//Aniela Fendrych
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct dataBlock
{
    bool typeBool;
    int typeUChar;
    string typeFloat;
};

struct dataFromFile
{
    int typeInt;
    string typeString;
    char typeChar;

    dataBlock dataBlock_1;
    dataBlock dataBlock_2;
    dataBlock dataBlock_3;
    dataBlock dataBlock_4;
};

bool IsEqual(dataFromFile compared, dataFromFile toCompare)
{

    if ((compared.typeInt == toCompare.typeInt) && (compared.typeString == toCompare.typeString) && (compared.typeChar == toCompare.typeChar))
    {
        if ((compared.dataBlock_1.typeBool == toCompare.dataBlock_1.typeBool) && (compared.dataBlock_1.typeUChar == toCompare.dataBlock_1.typeUChar) 
        && (compared.dataBlock_1.typeFloat == toCompare.dataBlock_1.typeFloat))
        {
            if ((compared.dataBlock_2.typeBool == toCompare.dataBlock_2.typeBool) && (compared.dataBlock_2.typeUChar == toCompare.dataBlock_2.typeUChar) 
        && (compared.dataBlock_2.typeFloat == toCompare.dataBlock_2.typeFloat))
            {
                if ((compared.dataBlock_3.typeBool == toCompare.dataBlock_3.typeBool) && (compared.dataBlock_3.typeUChar == toCompare.dataBlock_3.typeUChar) 
        && (compared.dataBlock_3.typeFloat == toCompare.dataBlock_3.typeFloat))
                {
                    if ((compared.dataBlock_4.typeBool == toCompare.dataBlock_4.typeBool) && (compared.dataBlock_4.typeUChar == toCompare.dataBlock_4.typeUChar) 
        && (compared.dataBlock_4.typeFloat == toCompare.dataBlock_4.typeFloat))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void pullData (fstream &file, dataFromFile &struktura) //wyciagnij dane z pliku i wpisz do struktury
{
    file >> struktura.typeInt;
    file >> std::ws;
    getline( file , struktura.typeString);
    file.get(struktura.typeChar);
    file >> struktura.dataBlock_1.typeBool;
    file >> struktura.dataBlock_1.typeUChar;
    file >> std::ws;
    getline( file , struktura.dataBlock_1.typeFloat);
    file >> struktura.dataBlock_2.typeBool;
    file >> struktura.dataBlock_2.typeUChar;
    file >> std::ws;
    getline( file , struktura.dataBlock_2.typeFloat);
    file >> struktura.dataBlock_3.typeBool;
    file >> struktura.dataBlock_3.typeUChar;
    file >> std::ws;
    getline( file , struktura.dataBlock_3.typeFloat);
    file >> struktura.dataBlock_4.typeBool;
    file >> struktura.dataBlock_4.typeUChar;
    file >> std::ws;
    getline( file , struktura.dataBlock_4.typeFloat);
}

void pushData (fstream &file, dataFromFile &struktura) //wyciagnij dane ze struktury i wpisz do pliku
{
    file << struktura.typeInt << endl;
    file << struktura.typeString << endl;
    file << struktura.typeChar << endl;
    file << struktura.dataBlock_1.typeBool << " " << struktura.dataBlock_1.typeUChar << " " << struktura.dataBlock_1.typeFloat << endl;
    file << struktura.dataBlock_2.typeBool << " " << struktura.dataBlock_2.typeUChar << " " << struktura.dataBlock_2.typeFloat << endl;
    file << struktura.dataBlock_3.typeBool << " " << struktura.dataBlock_3.typeUChar << " " << struktura.dataBlock_3.typeFloat << endl;
    file << struktura.dataBlock_4.typeBool << " " << struktura.dataBlock_4.typeUChar << " " << struktura.dataBlock_4.typeFloat << endl;
}
//czy s1 bedzie wiekszy
bool compareStringsBigger (string s1, string s2)
{
    int numer = 0;
    while (numer < s1.length() && numer < s2.length())
    {
    if (s1.at(numer) > s2.at(numer))
    {
        return 1;
    }
    else 
    if (s1.at(numer) < s2.at(numer))
    {
        return 0;
    }
    numer++;
    }
    if (s1.length() > s2.length())
    {
        return 1;
    }
    return 0;
}
//czy s1 bedzie mniejszy
bool compareStringsLess (string s1, string s2)
{
    int numer = 0;
    while (numer < s1.length() && numer < s2.length())
    {
    if (s1.at(numer) < s2.at(numer))
    {
        return 1;
    }
    else
    if (s1.at(numer) > s2.at(numer))
    {
        return 0;
    }
    numer++;
    }
    if (s1.length() < s2.length())
    {
        return 1;
    }
    return 0;
}
void SymmetricDifference (string file1, string file2, string hfile1) 
{
    //*****************************************
    dataFromFile struktura1;
    dataFromFile struktura2;
    dataFromFile struktura3;
    fstream ff1;
    fstream ff2;
    fstream fhf1;
    ff1.open( file1.c_str(), fstream::in);
    ff2.open( file2.c_str(), fstream::in);
    fhf1.open( hfile1.c_str(), fstream::out); //fstream::app |  
    pullData(ff1 , struktura1);
    pullData(ff2 , struktura2);
    //*****************************************
    bool iCanPushThisStructToFile1 = 1; //zmienna czy moge dopisac do file1

    while (!ff2.eof()) //dopoki ff2 sie nie skonczylo
    {
        while (!ff1.eof()) //dopoki ff1 sie nie skonczyl TU WPADA W PETLE NIESKONCZONA
        {
            //cout << "bbb" << endl;
            if (IsEqual(struktura1 , struktura2)) //ten warunek nie jest kompletnie sprawdzany
            {
                //cout << "idzie " << struktura1.typeString << endl;
                pushData(fhf1, struktura2);
                //fhf1 << endl;
                //cout << "Przepisuje do fhf1" << en  dl;
                iCanPushThisStructToFile1 = 0;
                break;
            }
            else
            {
                //cout << "pobieram" << endl;
                pullData(ff1 , struktura1); //zaciagnij i sprawdz z kolejnym structem
            }
            if (ff1.eof())
            {
                break;
            }
        }
        fhf1.close(); //zeby sie zapisalo i funkcja trunc przestala dzialac
        ff1.close(); //otwieram z nowa flaga
        fhf1.open( hfile1.c_str(), fstream::app | fstream::out); //to otwieram na kolejne dodawanie elementow
        ff1.open( file1.c_str(), fstream::app | fstream::ate | fstream::out); // czy przy tych flagach informacja doda sie na koniec pliku?
        if (iCanPushThisStructToFile1)
        {
            //ff1 << endl;
            pushData(ff1, struktura2); //dopisz strukture2 na koniec pliku file1
        }
        ff1.close(); //zeby dzialal zapis na koniec
        ff1.open( file1.c_str(), fstream::in);
        pullData(ff1, struktura1); //zaciagnij pierwsza strukture z ff1
        pullData(ff2, struktura2); //zaciagnij nowa strukture 2
        //ff1.seekp(currentPosition, fstream::beg); //glowica znowu na poczatek ff1; czy  konieczne?
        iCanPushThisStructToFile1 = 1;
        if (ff2.eof())
        {
            break;
        }
    }
    ff1.close(); //tu juz na stale
    ff2.close();
    fhf1.close();
    fhf1.open(hfile1.c_str(), fstream::in);
    ff2.open(file2.c_str(), fstream::out | fstream::trunc); //otwieram i czyszcze, przepisze do niego to co zostalo w hfile1
    while (!fhf1.eof())
    {
        pullData(fhf1, struktura3);
        if (fhf1.eof())
        {
            break;
        }
        pushData(ff2, struktura3);
    }
    //*****************************************
    ff2.close();
    fhf1.close();
    fhf1.open(hfile1.c_str(), fstream::out); //czyszczenie
    fhf1.close();
}

void SortInt (string file1, string hfile1, string hfile2) 
{
    dataFromFile struktura1;
    dataFromFile struktura2;
    fstream ffile;
    fstream fhfile1;
    fstream fhfile2;
    bool not_sorted = true;
    while (not_sorted)
    {
        ffile.open( file1.c_str(), fstream::in | fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::out | fstream::trunc);
        fhfile2.open( hfile2.c_str(), fstream::out | fstream::trunc);
        pullData(ffile , struktura1);
        struktura2.typeInt = 0;
        while (!ffile.eof()) //split
        {
            if (struktura1.typeInt < struktura2.typeInt)
            {
                while (1)
                {
                    pushData(fhfile2, struktura1);
                    struktura2 = struktura1;
                    pullData(ffile , struktura1);
                    if(ffile.eof())
                    {
                        break;
                    }
                    if(struktura1.typeInt < struktura2.typeInt)
                    {
                        break;
                    }
                }
            }
            if (ffile.eof())
            {
                break;
            }
            pushData(fhfile1, struktura1);
            struktura2 = struktura1;
            pullData(ffile , struktura1);
            if (ffile.eof())
            {
                break;
            }  
        }
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec splitu
        //*****************************************
        ffile.open( file1.c_str(), fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::in);
        fhfile2.open( hfile2.c_str(), fstream::in);
        //sort
        pullData(fhfile2, struktura2);
        pullData(fhfile1, struktura1);
        do
        {
            if(fhfile1.eof() && !fhfile2.eof())
            {
                pushData(ffile, struktura2);
                pullData(fhfile2, struktura2);
            }
            if(!fhfile1.eof() && fhfile2.eof())
            {
                pushData(ffile, struktura1);
                pullData(fhfile1, struktura1);
            }
            if(!fhfile1.eof() && !fhfile2.eof())
            {
                if(struktura1.typeInt >= struktura2.typeInt)
                {
                    pushData(ffile, struktura2);
                    pullData(fhfile2, struktura2);
                }
                if(struktura1.typeInt < struktura2.typeInt)
                {
                    pushData(ffile, struktura1);
                    pullData(fhfile1, struktura1);
                }
            }
        } while (!fhfile1.eof() || !fhfile2.eof());
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec sortu
        not_sorted = false;
        //*****************************************
        //sprawdzanie sortu
        ffile.open(file1.c_str(), fstream::in | fstream::out);
        pullData(ffile, struktura1); //1 w kolejnosci
        pullData(ffile, struktura2); //2 w kolejnosci
        while(!ffile.eof())
        {
            if(struktura1.typeInt > struktura2.typeInt) //nie udalo sie posortowac:(
            {
                not_sorted = true;
                break;
            }
            struktura1 = struktura2;
            pullData(ffile, struktura2);
        }
        ffile.close();
    }
}

string IntToString(int number)
{
    string number_s = "";
    int n = (number < 0? -number : number);
    if(n == 0)
    {
        number_s = "";
    }
    while(1)
    {
        number_s = (char)((n % 10) + '0') + number_s;
        n = n / 10;
        if(n <= 0) //==0
        {
            break;
        }
    }
    if (number < 0)
    {
        number_s = '-' + number_s;
    }
    return number_s;
}

int Frequency(string str, int number) //zwraca licznosc number w stringu str
{
    int freq = 0;
    string help = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ( str.at(i) == ' ')
        {
            if (help == IntToString(number))
            {
                freq++;
            }
            help = "";
        }
        else
        {
            help += str.at(i);
        }
    }
    return freq;
}

bool leftIsFirst (dataFromFile struktura1, dataFromFile struktura2, string numbers) //struktura1 jako pierwsza
{
    int freqFrom1 = Frequency(numbers, struktura1.typeInt);
    //cout << "freq1 " << freqFrom1 << endl;
    int freqFrom2 = Frequency(numbers, struktura2.typeInt);
    //cout << "freq2 " << freqFrom2 << endl;
    if (freqFrom1 > freqFrom2)
    {
        return 1;
    }
    if (freqFrom1 < freqFrom2)
    {
        return 0;
    }
    //frekwencja taka sama
    if (struktura1.typeInt > struktura2.typeInt)
    {
        return 1;
    }
    if (struktura1.typeInt < struktura2.typeInt)
    {
        return 0;
    }
    //typeInt taki sam
    int sum1 = 0;
    int sum2 = 0;
    sum1 += struktura1.dataBlock_1.typeUChar + struktura1.dataBlock_2.typeUChar + struktura1.dataBlock_3.typeUChar + struktura1.dataBlock_4.typeUChar;
    sum2 += struktura2.dataBlock_1.typeUChar + struktura2.dataBlock_2.typeUChar + struktura2.dataBlock_3.typeUChar + struktura2.dataBlock_4.typeUChar;
    sum1 = sum1 % 256;
    sum2 = sum2 % 256;
    if (sum1 >= sum2)
    {
        return 1;
    }
    if (sum1 < sum2)
    {
        return 0;
    }
    //return 1; //jak takie same
}

void SortCount (string file1, string hfile1, string hfile2)
{
    //SORTOWANIE PO INT
    //*****************************************************
    dataFromFile struktura1;
    dataFromFile struktura2;
    fstream ffile;
    fstream fhfile1;
    fstream fhfile2;
    bool not_sorted = true;
    while (not_sorted)
    {
        ffile.open( file1.c_str(), fstream::in | fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::out | fstream::trunc);
        fhfile2.open( hfile2.c_str(), fstream::out | fstream::trunc);
        pullData(ffile , struktura1);
        struktura2.typeInt = 0;
        while (!ffile.eof()) //split
        {
            if (struktura1.typeInt < struktura2.typeInt)
            {
                while (1)
                {
                    pushData(fhfile2, struktura1);
                    struktura2 = struktura1;
                    pullData(ffile , struktura1);
                    if(ffile.eof())
                    {
                        break;
                    }
                    if(struktura1.typeInt < struktura2.typeInt)
                    {
                        break;
                    }
                }
            }
            if (ffile.eof())
            {
                break;
            }
            pushData(fhfile1, struktura1);
            struktura2 = struktura1;
            pullData(ffile , struktura1);
            if (ffile.eof())
            {
                break;
            }  
        }
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec splitu
        //*****************************************
        ffile.open( file1.c_str(), fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::in);
        fhfile2.open( hfile2.c_str(), fstream::in);
        //sort
        pullData(fhfile2, struktura2);
        pullData(fhfile1, struktura1);
        do
        {
            if(fhfile1.eof() && !fhfile2.eof())
            {
                pushData(ffile, struktura2);
                pullData(fhfile2, struktura2);
            }
            if(!fhfile1.eof() && fhfile2.eof())
            {
                pushData(ffile, struktura1);
                pullData(fhfile1, struktura1);
            }
            if(!fhfile1.eof() && !fhfile2.eof())
            {
                if(struktura1.typeInt >= struktura2.typeInt)
                {
                    pushData(ffile, struktura2);
                    pullData(fhfile2, struktura2);
                }
                if(struktura1.typeInt < struktura2.typeInt)
                {
                    pushData(ffile, struktura1);
                    pullData(fhfile1, struktura1);
                }
            }
        } while (!fhfile1.eof() || !fhfile2.eof());
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec sortu
        not_sorted = false;
        //*****************************************
        //sprawdzanie sortu
        ffile.open(file1.c_str(), fstream::in | fstream::out);
        pullData(ffile, struktura1); //1 w kolejnosci
        pullData(ffile, struktura2); //2 w kolejnosci
        while(!ffile.eof())
        {
            if(struktura1.typeInt > struktura2.typeInt) //nie udalo sie posortowac:(
            {
                not_sorted = true;
                break;
            }
            struktura1 = struktura2;
            pullData(ffile, struktura2);
        }
        ffile.close();
    }
    //*****************************************************
    //plik 1 posortowany rosnąco po int
    // -4 -4 0 0 0 1 2 2 3 3
    string numbers = ""; //ostateczny
    ffile.open( file1.c_str(), fstream::in | fstream::out);
    while (!ffile.eof())
    {
        pullData(ffile, struktura1); //zaciagam strukture
        if (ffile.eof())
        {
            break;
        }
        numbers += IntToString(struktura1.typeInt) + " ";
        //wyciagam type int
        //przeksztalcam go do string
        //dopisuje na koniec stringa numbers
        //dopisuje spacje
    }
    ffile.close();
    //cout << numbers << endl; dziala
    bool notSorted = true;
    while (notSorted)
    {
        ffile.open( file1.c_str(), fstream::in); //| fstream::out
        fhfile1.open( hfile1.c_str(), fstream::out | fstream::trunc);
        fhfile2.open( hfile2.c_str(), fstream::out | fstream::trunc);
        pullData(ffile , struktura1);
        //struktura2.typeInt = 0;
        while (!ffile.eof()) //split
        {
            if (leftIsFirst(struktura1, struktura2, numbers))
            {
                while (1)
                {
                    pushData(fhfile2, struktura1);
                    struktura2 = struktura1;
                    pullData(ffile , struktura1);
                    if(ffile.eof())
                    {
                        break;
                    }
                    if(leftIsFirst(struktura1, struktura2, numbers))
                    {
                        break;
                    }
                }
            }
            if (ffile.eof())
            {
                break;
            }
            pushData(fhfile1, struktura1);
            struktura2 = struktura1;
            pullData(ffile , struktura1);
            if (ffile.eof())
            {
                break;
            }  
        }
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec splitu
        //*****************************************
        ffile.open( file1.c_str(), fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::in);
        fhfile2.open( hfile2.c_str(), fstream::in);
        //sort
        pullData(fhfile2, struktura2);
        pullData(fhfile1, struktura1);
        do
        {
            if(fhfile1.eof() && !fhfile2.eof())
            {
                pushData(ffile, struktura2);
                pullData(fhfile2, struktura2);
            }
            if(!fhfile1.eof() && fhfile2.eof())
            {
                pushData(ffile, struktura1);
                pullData(fhfile1, struktura1);
            }
            if(!fhfile1.eof() && !fhfile2.eof())
            {
                if(!leftIsFirst(struktura1, struktura2, numbers))
                {
                    pushData(ffile, struktura2);
                    pullData(fhfile2, struktura2);
                }
                if(leftIsFirst(struktura1, struktura2, numbers))
                {
                    pushData(ffile, struktura1);
                    pullData(fhfile1, struktura1);
                }
            }
        } while (!fhfile1.eof() || !fhfile2.eof());
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec sortu
        notSorted = false;
        //*****************************************
        //sprawdzanie sortu
        ffile.open(file1.c_str(), fstream::in | fstream::out);
        pullData(ffile, struktura1); //1 w kolejnosci
        pullData(ffile, struktura2); //2 w kolejnosci
        while(!ffile.eof())
        {
            if(!leftIsFirst(struktura1, struktura2, numbers)) //nie udalo sie posortowac:(
            {
                notSorted = true;
                break;
            }
            struktura1 = struktura2;
            pullData(ffile, struktura2);
        }
        ffile.close();
    }
}

void SortString (string file1, string hfile1, string hfile2) 
{
    dataFromFile struktura1;
    dataFromFile struktura2;
    fstream ffile;
    fstream fhfile1;
    fstream fhfile2;
    bool not_sorted = true;
    while (not_sorted)
    {
        ffile.open( file1.c_str(), fstream::in | fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::out | fstream::trunc);
        fhfile2.open( hfile2.c_str(), fstream::out | fstream::trunc);
        pullData(ffile , struktura1);
        struktura2.typeString = "";
        while (!ffile.eof()) //split
        {
            if (compareStringsLess(struktura1.typeString, struktura2.typeString))
            {
                while (1)
                {
                    pushData(fhfile2, struktura1);
                    struktura2 = struktura1;
                    pullData(ffile , struktura1);
                    if(ffile.eof())
                    {
                        break;
                    }
                    if(compareStringsLess(struktura1.typeString, struktura2.typeString))
                    {
                        break;
                    }
                }
            }
            if (ffile.eof())
            {
                break;
            }
            pushData(fhfile1, struktura1);
            struktura2 = struktura1;
            pullData(ffile , struktura1);
            if (ffile.eof())
            {
                break;
            }  
        }
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec splitu
        //*****************************************
        ffile.open( file1.c_str(), fstream::out);
        fhfile1.open( hfile1.c_str(), fstream::in);
        fhfile2.open( hfile2.c_str(), fstream::in);
        //sort
        pullData(fhfile2, struktura2);
        pullData(fhfile1, struktura1);
        do
        {
            if(fhfile1.eof() && !fhfile2.eof())
            {
                pushData(ffile, struktura2);
                pullData(fhfile2, struktura2);
            }
            if(!fhfile1.eof() && fhfile2.eof())
            {
                pushData(ffile, struktura1);
                pullData(fhfile1, struktura1);
            }
            if(!fhfile1.eof() && !fhfile2.eof())
            {
                if(compareStringsBigger(struktura1.typeString, struktura2.typeString))
                {
                    pushData(ffile, struktura2);
                    pullData(fhfile2, struktura2);
                }
                if(compareStringsLess(struktura1.typeString, struktura2.typeString))
                {
                    pushData(ffile, struktura1);
                    pullData(fhfile1, struktura1);
                }
            }
        } while (!fhfile1.eof() || !fhfile2.eof());
        ffile.close();
        fhfile1.close();
        fhfile2.close(); //koniec sortu
        not_sorted = false;
        //*****************************************
        //sprawdzanie sortu
        ffile.open(file1.c_str(), fstream::in | fstream::out);
        pullData(ffile, struktura1); //1 w kolejnosci
        pullData(ffile, struktura2); //2 w kolejnosci
        while(!ffile.eof())
        {
            if(compareStringsBigger(struktura1.typeString, struktura2.typeString)) //nie udalo sie posortowac:(
            {
                not_sorted = true;
                break;
            }
            struktura1 = struktura2;
            pullData(ffile, struktura2);
        }
        ffile.close();
    }
}