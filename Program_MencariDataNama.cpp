#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    const int x = 5;
    string data[x];
    string target;
    int i = 0;
    int flag = 0;

    cout << "Masukan data Nama Yang ingin disimpan pada Array :" << endl;
    for (int i = 0; i < x - 1; i++)
    {
        cout << i + 1 << ". ";
        cin >> data[i];
        transform(data[i].begin(), data[i].end(), data[i].begin(), ::toupper);
    }

    cout << "Masukkan nama yang ingin dicari : ";
    cin >> target;
    transform(target.begin(), target.end(), target.begin(), ::toupper);

    data[x - 1] = target;

    while (data[i] != target)
    {
        i++;
    }

    if (i < x)
    {
        flag = 1;
    }

    if (flag == 1)
    {
        cout << "Nama " << target << " Ditemukan pada indeks ke-" << i << endl;
    }
    else
    {
        cout << "Nama " << target << " Tidak ditemukan" << endl;
    }

    return 0;
}
