#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void tukar(string *x, string *y)
{
    string z = *x;
    *x = *y;
    *y = z;
}

int main()
{
    int n;
    string pilih;
    bool looping = true;

    cout << "Masukkan jumlah Nama yang ingin disimpan: ";
    cin >> n;

    string arr[n];

    cout << "Masukkan Nama yang akan disimpan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". ";
        getline(cin >> ws, arr[i]);
        transform(arr[i].begin(), arr[i].end(), arr[i].begin(), ::toupper);
    }

    cout << "Data nama yang telah disimpan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i] << " ";
        cout << endl;
    }

    while (looping)
    {
        cout << "Urutkan data nama (A-Z)? (Ya/Tidak): " << endl;
        cin >> pilih;

        if (pilih == "Ya" || pilih == "ya" || pilih == "YA")
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        tukar(&arr[i], &arr[j]);
                    }
                }
            }

            cout << "Nama setelah di urutkan (A-Z): " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". " << arr[i] << " ";
                cout << endl;
            }
            looping = false;
        }
        else if (pilih == "Tidak" || pilih == "tidak" || pilih == "TIDAK")
        {
            cout << "Nama tidak di urutkan : " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << ". ";
                cout << arr[i] << " ";
                cout << endl;
            }
            looping = false;
        }
        else
        {
            cout << "Pilihan tidak valid" << endl;
        }
    }
    return 0;
}