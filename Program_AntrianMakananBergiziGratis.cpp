#include <iostream>
using namespace std;
const int MAXN = 100;
string q[MAXN];
int frontIdx = -1, rearIdx = -1;
bool isEmpty() { return frontIdx == -1; }
bool isFull() { return (rearIdx + 1) % MAXN == frontIdx; }
void enqueue(string x)
{
    if (isFull())
    {
        cout << "Antrian penuh\n";
        return;
    }
    if (isEmpty())
    {
        frontIdx = rearIdx = 0;
    }
    else
    {
        rearIdx = (rearIdx + 1) % MAXN;
    }
    q[rearIdx] = x;
    cout << x << " Kamu berada pada Antrian ke-" << rearIdx + 1 << endl;
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian Masih kosong\n";
        return;
    }
    cout << "Atas Nama " << q[frontIdx] << " Antrian ke-" << frontIdx + 1 << " Mengambil Makanan Bergizi Gratis" << endl;
    if (frontIdx == rearIdx)
    {
        frontIdx = rearIdx = -1;
    }
    else
    {
        frontIdx = (frontIdx + 1) % MAXN;
    }
}
void peek()
{
    if (isEmpty())
    {
        cout << "Antrian Masih kosong\n";
        return;
    }
    cout << "Nomer Antrian ke-" << frontIdx + 1 << " Atas Nama " << q[frontIdx] << " Akan dipanggil Selanjutnya" << endl;
}
void display()
{
    if (isEmpty())
    {
        cout << "Antrian Masih kosong\n";
        return;
    }
    cout << "Urutan Antrian : " << endl;
    int i = frontIdx;
    while (true)
    {
        cout << "Antrian ke-" << i + 1 << " Atas Nama " << q[i] << endl;
        if (i == rearIdx)
            break;
        i = (i + 1) % MAXN;
    }
    cout << '\n';
}
int main()
{
    int pilih;
    string nama;

    do
    {
        cout << "\n=== Sistem Antrian Makanan Bergizi Gratis ===\n";
        cout << "1. Ambil Nomor Antrian" << endl;
        cout << "2. Ambil Makanan Bergizi Gratis" << endl;
        cout << "3. Melihat Antrian yang mengambil MBG selanjutnya" << endl;
        cout << "4. Melihat Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cout << endl;
        switch (pilih)
        {
        case 1:
            cout << "MASUKAN NAMA = ";
            cin >> nama;
            enqueue(nama);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (pilih != 5);
    return 0;
}
