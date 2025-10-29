#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

enum SlotState
{
    EMPTY,
    OCCUPIED,
    DELETED
};

struct Entry
{
    string key;
    string value;
    SlotState state;
};

int hashFunction(const string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 31 + c) % SIZE;
    }
    return hash;
}

void initTable(Entry table[])
{
    for (int i = 0; i < SIZE; ++i)
    {
        table[i].state = EMPTY;
    }
}

bool insert(Entry table[], const string &key, const string &value)
{
    int idx = hashFunction(key);
    int firstDeleted = -1;

    for (int step = 0; step < SIZE; ++step)
    {
        int i = (idx + step) % SIZE;

        if (table[i].state == OCCUPIED)
        {
            if (table[i].key == key)
            {
                table[i].value = value;
                return true;
            }
        }
        else if (table[i].state == DELETED)
        {
            if (firstDeleted == -1)
                firstDeleted = i;
        }
        else
        {
            if (firstDeleted != -1)
                i = firstDeleted;
            table[i].key = key;
            table[i].value = value;
            table[i].state = OCCUPIED;
            return true;
        }
    }

    if (firstDeleted != -1)
    {
        table[firstDeleted].key = key;
        table[firstDeleted].value = value;
        table[firstDeleted].state = OCCUPIED;
        return true;
    }
    return false;
}

Entry *search(Entry table[], const string &key)
{
    int idx = hashFunction(key);

    for (int step = 0; step < SIZE; ++step)
    {
        int i = (idx + step) % SIZE;

        if (table[i].state == EMPTY)
        {
            return nullptr;
        }
        if (table[i].state == OCCUPIED && table[i].key == key)
        {
            return &table[i];
        }
    }
    return nullptr;
}

bool removeKey(Entry table[], const string &key)
{
    Entry *e = search(table, key);
    if (!e)
        return false;
    e->state = DELETED;
    return true;
}

void display(Entry table[])
{
    cout << "Data Plat nomer dan Kotanya ";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << i << ": ";
        if (table[i].state == EMPTY)
            cout << "EMPTY\n";
        else if (table[i].state == DELETED)
            cout << "DELETED\n";
        else
            cout << "(" << table[i].key << " Plat " << table[i].value << ")\n";
    }
}

int main()
{
    Entry table[SIZE];
    initTable(table);

    insert(table, "F", "Bogor");
    insert(table, "P", "Banyuwangi");
    insert(table, "BE", "Lampung");
    insert(table, "B", "Jakarta");
    insert(table, "D", "Bandung");

    display(table);

    Entry *hasil = search(table, "BE");
    if (hasil)
        cout << "\nPlat " << hasil->key << " ditemukan, Kota = " << hasil->value << "\n";
    else
        cout << "\nPlat BE tidak ditemukan\n";

    removeKey(table, "BE");
    cout << "\nSetelah menghapus plat BE:\n";

    display(table);

    return 0;
}
