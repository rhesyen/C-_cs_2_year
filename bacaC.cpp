//Aniela Fendrych

void Print(int n, char* s)
{
    if (n == 0) //czy n pusty
    {
        *s = 'e';
        *(s + 1) = 'm';
        *(s + 2) = 'p';
        *(s + 3) = 't';
        *(s + 4) = 'y';
        *(s + 5) = '\0';
        return;
    }
    if (n != 0)
    {
        static int a = 31; //0000 0000 0000 0000 0000 0000 0001 1111
        if (a < 0)
        {
            a = 31;
            *s = '\0';
            return;
        }
        if (n & (1 << a))
        {
            *s = ((a & (1 << 4))? '1' : '0');
            *(s + 1) = ((a & (1 << 3))? '1' : '0');
            *(s + 2) = ((a & (1 << 2))? '1' : '0');
            *(s + 3) = ((a & (1 << 1))? '1' : '0');
            *(s + 4) = ((a & (1 << 0))? '1' : '0');
            *(s + 5) = ' ';
            a--;
            Print(n, s + 6);
        }
        else
        {
            a--;
            Print(n, s);
        }
    }
}

void Insert(char* array, int* integer)
{
    if (*array == '\0')
    {
        return;
    }
    if (*array == ' ') //to przesun o jeden w prawo
    {
        Insert(array + 1, integer);
    }
    else //tu porownanie ciagu 5 znakow i wstawienie 1 lub 0 do integera
    {
        int a =   (16 * ((*array) - '0')) 
                + ( 8 * (*(array + 1) - '0')) 
                + ( 4 * (*(array + 2) - '0'))
                + ( 2 * (*(array + 3) - '0'))
                + (     (*(array + 4) - '0')); //'int a' to zamiana ciagu 5 znakow char (0 lub 1) na int
        //tu zmiana naszego integer w taki sposob, aby w miejsce przewidziane dla 'int a' wstawił 1
        *integer |= (1 << a);
        //wzor na pozycje 'int a' w integerze, zapytac jak uzywac tutaj przesuniecia bitowego
        Insert(array + 5, integer); //przesuwamy sie wzdluz tablicy array o 5
    }
}

void Emplace(char* array, int* integer)
{
    *integer = 0;
    Insert(array, integer);
}

void Erase(char* array, int* integer)
{
    if (*array == '\0')
    {
        return;
    }
    if (*array == ' ') //to przesun o jeden w prawo
    {
        Erase(array + 1, integer);
    }
    else //tu porownanie ciagu 5 znakow i wstawienie 1 lub 0 do integera
    {
        int a =   (16 * ((*array) - '0')) 
                + ( 8 * (*(array + 1) - '0')) 
                + ( 4 * (*(array + 2) - '0'))
                + ( 2 * (*(array + 3) - '0'))
                + (     (*(array + 4) - '0')); //'int a' to zamiana ciagu 5 znakow char (0 lub 1) na int
        *integer &= ~(1 << a);
        Erase(array + 5, integer); //przesuwamy sie wzdluz tablicy array o 5
    }
}

void Complement (int n, int* integer)
{
    *integer = ~n;
}
//*****************************************
bool Emptiness(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 0;
}
bool Nonempty(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1;
}
bool Member(char* array, int integer)
{
    if (*array == '\0')
    {
        return 0;
    }
    if (*array == ' ') //to przesun o jeden w prawo
    {
        Member(array + 1, integer);
    }
    else //tu porownanie ciagu 5 znakow i wstawienie 1 lub 0 do integera
    {
        int a =   (16 * ((*array) - '0')) 
                + ( 8 * (*(array + 1) - '0')) 
                + ( 4 * (*(array + 2) - '0'))
                + ( 2 * (*(array + 3) - '0'))
                + (     (*(array + 4) - '0')); //'int a' to zamiana ciagu 5 znakow char (0 lub 1) na int
        //(integer &= (1 << a)? 1 : 0);
        if (integer &= (1 << a))
        {
            return 1;
        }
        return 0;
    }
}
bool Disjoint(int n1, int n2)
{
    if ((n1 & n2) == 0)
    {
        return 1;
    }
    return 0;
}
bool Conjunctive(int n1, int n2)
{
    if ((n1 & n2) == 0)
    {
        return 0;
    }
    return 1;
}
bool Equality(int n1, int n2)
{
    if (n1 == n2)
    {
        return 1;
    }
    return 0;
}
bool Inclusion(int n1, int n2)
{
    if ((n1 | n2) == n2)
    {
        return 1;
    }
    return 0; 
}
//***********************************
/*int Cardinality(int n)
{
    static int count = 0;
    static int a = 31;
    if (a < 0)
    {
        int tempCount = count;
        a = 31;
        count = 0;
        return tempCount;
    }
    if (n & (1 << a))
    {
        count++;
        a--;
        Cardinality(n);
        return count;
    }
}*/
int Cardinality (int n)
{
    int p = 0;
    if((n & 0x00000001) != 0)
    {
        p++;
    }
    if((n & 0x00000002) != 0)
    {
        p++;
    }
    if((n & 0x00000004) != 0)
    {
        p++;
    }
    if((n & 0x00000008) != 0)
    {
        p++;
    }

    if((n & 0x00000010) != 0)
    {
        p++;
    }
    if((n & 0x00000020) != 0)
    {
        p++;
    }
    if((n & 0x00000040) != 0)
    {
        p++;
    }
    if((n & 0x00000080) != 0)
    {
        p++;
    }

    if((n & 0x00000100) != 0)
    {
        p++;
    }
    if((n & 0x00000200) != 0)
    {
        p++;
    }
    if((n & 0x00000400) != 0)
    {
        p++;
    }
    if((n & 0x00000800) != 0)
    {
        p++;
    }

    if((n & 0x00001000) != 0)
    {
        p++;
    }
    if((n & 0x00002000) != 0)
    {
        p++;
    }
    if((n & 0x00004000) != 0)
    {
        p++;
    }
    if((n & 0x00008000) != 0)
    {
        p++;
    }

    if((n & 0x00010000) != 0)
    {
        p++;
    }
    if((n & 0x00020000) != 0)
    {
        p++;
    }
    if((n & 0x00040000) != 0)
    {
        p++;
    }
    if((n & 0x00080000) != 0)
    {
        p++;
    }

    if((n & 0x00100000) != 0)
    {
        p++;
    }
    if((n & 0x00200000) != 0)
    {
        p++;
    }
    if((n & 0x00400000) != 0)
    {
        p++;
    }
    if((n & 0x00800000) != 0)
    {
        p++;
    }

    if((n & 0x01000000) != 0)
    {
        p++;
    }
    if((n & 0x02000000) != 0)
    {
        p++;
    }
    if((n & 0x04000000) != 0)
    {
        p++;
    }
    if((n & 0x08000000) != 0)
    {
        p++;
    }

    if((n & 0x10000000) != 0)
    {
        p++;
    }
    if((n & 0x20000000) != 0)
    {
        p++;
    }
    if((n & 0x40000000) != 0)
    {
        p++;
    }
    if((n & 0x80000000) != 0)
    {
        p++;
    }
    return p;
}
//***********************************
bool GreatThen(int n1, int n2)
{
    if (Cardinality(n1) > Cardinality(n2)) //?
    {
        return 1;
    }
    if (Cardinality(n1) < Cardinality(n2))
    {
        return 0;
    }
    return n1 > n2;
}
bool GreatEqual(int n1, int n2)
{
   return (GreatThen(n1, n2) || Equality(n1, n2));
}
bool LessThen(int n1, int n2)
{
    return (!GreatEqual(n1, n2));
}
bool LessEqual(int n1, int n2)
{
    return (!GreatThen(n1, n2));
}
//***********************************
void Union(int n1, int n2, int* n3)
{
    *n3 = (n1 | n2);
}
void Intersection(int n1, int n2, int* n3)
{
    *n3 = (n1 & n2);
}
void Symmetric(int n1, int n2, int* n3)
{
    *n3 = (n1 ^ n2);
}
void Difference(int n1, int n2, int* n3)
{
    *n3 = (n1 & ~n2);
}