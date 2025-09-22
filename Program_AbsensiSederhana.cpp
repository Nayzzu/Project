#include <iostream>
using namespace std;

struct Vector
{
    string *data;
    int capacity;
    int length;
};

void init(Vector &v)
{
    v.capacity = 2;
    v.length = 0;
    v.data = new string[v.capacity];
}

void resize(Vector &v, int newCap)
{
    string *newData = new string[newCap];
    for (int i = 0; i < v.length; i++)
    {
        newData[i] = v.data[i];
    }
    delete[] v.data;
    v.data = newData;
    v.capacity = newCap;
}

void push_back(Vector &v, string value)
{
    if (v.length == v.capacity)
    {
        resize(v, v.capacity * 2);
    }
    v.data[v.length] = value;
    v.length++;
}

void pop_back(Vector &v)
{
    if (v.length > 0)
    {
        v.length--;
    }
}

string get(Vector &v, int index)
{
    if (index >= 0 && index < v.length)
    {
        return v.data[index];
    }
    return "";
}
void set(Vector &v, int index, string value)
{
    if (index >= 0 && index < v.length)
    {
        v.data[index] = value;
    }
}

int size(Vector &v)
{
    return v.length;
}

void display(Vector &v)
{
    for (int i = 0; i < v.length; i++)
    {
        cout << 1 + i << ". " << v.data[i] << endl;
    }
}

void clear(Vector &v)
{
    delete[] v.data;
    v.data = nullptr;
    v.capacity = 0;
    v.length = 0;
}

int main()
{
    Vector v;
    init(v);
    string namaMHS;
    string newName;
    char tambahNama;
    int pilihan;
    bool running = true;

    while (running)
    {
        cout << endl;
        cout << "Program Absensi Sederhana =\n";
        cout << "1. Tambah Nama Mahasiswa\n";
        cout << "2. Tampilkan Daftar Absensi\n";
        cout << "3. Ganti Nama Mahasiswa urutan ke\n";
        cout << "4. Hapus Nama Mahasiswa Terakhir\n";
        cout << "5. Jumlah Mahasiswa yang Terdaftar\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            do
            {
                cout << endl;
                cout << "Masukan Nama Mahasiswa: ";
                getline(cin, namaMHS);
                push_back(v, namaMHS);

                cout << "Tambah nama lagi? (y/n): ";
                cin >> tambahNama;
                cin.ignore();
            } while (tambahNama == 'y' || tambahNama == 'Y');
            break;

        case 2:
            cout << endl;
            cout << "\tDaftar Absensi: " << endl;
            display(v);
            system("pause");
            break;

        case 3:
            cout << endl;
            int index;
            cout << "Masukan urutan nama mahasiswa yang ingin diganti: ";
            cin >> index;
            cin.ignore();
            cout << "Masukan Nama Mahasiswa: ";
            getline(cin, newName);
            set(v, index - 1, newName);
            break;
        case 4:
            cout << endl;
            pop_back(v);
            cout << "Nama mahasiswa terakhir telah dihapus." << endl;
            break;
        case 5:
            cout << endl;
            cout << "Jumlah Mahasiswa yang Terdaftar: " << size(v) << endl;
            break;
        case 6:
            running = false;
            break;
        }
    }
    clear(v);
    return 0;
}
