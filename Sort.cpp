#include "TXLib.h"

//=============================================================================

int CountEX = 0;

//=============================================================================

void Print (int data[], int size);

//=============================================================================

void Zapolnitel(int data[], int size, int start);

//=============================================================================

void Obmen(int data[], int ES1, int ES2);

//=============================================================================

void BubbleSort(int data[], int size);

//=============================================================================

void ShakerSort(int data[], int size);

//=============================================================================

int MinEl (int data[], int size, int start);

//=============================================================================

void SortPass(int data[], int l, int r);

//=============================================================================

void SelectionSort(int data[], int size);

//=============================================================================

void ROR (int data[], int size, int start, int finish);

//=============================================================================

void InsertionSort (int data[], int size, int start);

//=============================================================================

int BinarySearch (int data[], int size, int el);

//=============================================================================

void PrintData (int data[], int size, int min, int max, int mid);

//=============================================================================

void QuickSort (int data[], int size, int left, int right);

//=============================================================================

void PrintDataMid (int data[], int size, int mid);

//=============================================================================

int ElFind (int data[], int size, int el);

//=============================================================================

int main ()
    {
    const int Size = 10;
    int data[Size] = {};
    //PrintData (data, Size, 0, Size - 1, (Size - 1) / 2);
    Zapolnitel (data, Size, 0);
    InsertionSort (data, Size, 0);
    Print (data, Size);
    return 0;
    }

//=============================================================================

void Print (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        $g;
        assert (0 <= i && i < size);
        printf ("%d ", data[i]);
        }
    }

//=============================================================================

void Zapolnitel(int data[], int size, int start)
    {
    int i = start;
    while (i < size)
        {
        printf ("i = %d\n", i);
        data[i] =  rand() % 10 * 100 + i;
        i++;
        }
    }

//=============================================================================

void Obmen(int data[], int ES1, int ES2)
    {
    int help = data[ES1];
    data[ES1] = data[ES2];
    data[ES2] = help;
    }

//=============================================================================

void BubbleSort(int data[], int size)
    {
    int a = 0;
    while (a < size - 1)
        {
        int o = size - 1;
        while (o > 0)
            {
            if (data[o - 1] > data[o])
                {
                Obmen (data, o - 1, o);
                }
            o--;
            }
        a++;
        }
    }

//=============================================================================

void ShakerSort(int data[], int size)
    {
    int left = 0;
    int right = size - 1;
    while (0 < right)
        {
        SortPass(data, left, right);
        right--;
        SortPass(data, right, left);
        left++;
        }
    }

//=============================================================================

int MinEl (int data[], int size, int begin)
    {
    int i = begin + 1;
    int Min = begin;
    while (i < size)
        {
        if (data[i] < data[Min])
            {
            Min = i;
            }
        i++;
        }
    return Min;
    }

//=============================================================================

void SortPass(int data[], int l, int r)
    {
    for (int e = l; e < r; e++)
           {
           if (data[e] > data[e + 1])
               {
               Obmen (data, e, e + 1);
               }
           }
    }

//=============================================================================

void SelectionSort(int data[], int size)
    {
    int start = 0;
    while (start < size)
        {
        Obmen (data, MinEl(data, size, start), start);
        start++;
        CountEX++;
        printf ("CountEX = %d ",CountEX);
        }
    }


//=============================================================================

void ROR (int data[], int size, int start, int finish)
    {
    int step = data [finish];
    for (int i = finish; i >= start; i--)
    data[i] = data[i - 1];
    data[start] = step;
    }

//=============================================================================

void InsertionSort (int data[], int size, int start)
    {
    if (start == 0)
        {
        if (data[0] > data[1])
            {
            Obmen (data, 0, 1);
            }
            start = 2;
        }
    int i = start;
    while (i <= size)
        {
        ROR (data, size, ElFind (data, size, i), i);
        i++;
        }
    }

//=============================================================================

int BinarySearch (int data[], int size, int el)
    {
    int min, mid, max, i;
    i = 0;
    min = 0;
    max = size - 1;
    while (min <= max)
        {
        mid = (min + max)/2;
        i++;
        PrintData (data, size, min, max, mid);
        if (data[el] < data[mid])
            {
            max = mid - 1;
            }
        else if (data[el] > data[mid])
            {
            min = mid + 1;
            }
        else if (data[el] = data[mid])
            {
            return mid;
            }

        }

    return min;
    }

//=============================================================================

void PrintData (int data[], int size, int min, int max, int mid)
    {
    {
    for (int i = 0; i < size; i++)
        {
         if (i != mid && i != min && i != max)
            {
            $y;
            }
        if (i == mid)
            {
            $c;
            }
         if (i == min)
            {
            $r;
            }
         if (i == max)
            {
            $g;
            }
        assert (0 <= i && i < size);
        printf ("%d ", data[i]);
        }
    }
        $d;
        printf ("%s: распечатала массив, left = %d, right = %d, mid = %d, data[left] = %d, data[right] = %d, data[mid] = %d\n", __PRETTY_FUNCTION__, min, max, mid, data[min], data[max], data[mid  ]);
        //Sleep(500);
        getch();
        txClear;
    }


//=============================================================================

void QuickSort (int data[],int size, int left, int right)
    {
    int mid = (left + right)/ 2;
    int count1 = left;
    int count2 = right;
    while (count1 <= count2)
        {
        while (data[count1] < data[mid])
            {
            count1++;
            }
        while (data[count2] > data[mid])
            {
            count2--;
            }
        if (count1 <= count2)
            {
            Obmen (data, count1, count2);
            count1++;
            count2--;
            }
        }
    if (count1 < right)
        {
        QuickSort (data, size, count1, right);
        }
    if (count2 > left)
       {
        QuickSort (data, size, left, count2);
       }
    }
 //=============================================================================

void PrintDataMid (int data[], int size, int mid)
    {
    for (int i = 0; i < size; i++)
        {
        if (i != mid)
            {
            $g;
            }
        if (i == mid)
            {
            $c;
            }
        assert (0 <= i && i < size);
        printf ("%d ", data[i]);
        }
    }

//=============================================================================
int ElFind (int data[], int size, int el)
    {
    int i = 0;
    while (data[i] > el)
        {
        i++;
        }
    return i;
    }
