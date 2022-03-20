#include <iostream>
using namespace std;

// deklarasi dari simpul
struct DLNode
{
    int bil;
    struct DLNode *back;
    struct DLNode *next;
};
struct DLNode *head, *tail;

void bentuk_awal()
{
    struct DLNode *awal;
    int j = 0;
    char jawab[2];
    
    do
    {
        awal = (struct DLNode *)malloc(sizeof(struct DLNode));

        cout << "Masukkan bilangan : ";
        scanf("%d", &awal->bil);

        if (j == 0)
        {
            awal->back = NULL;
            awal->next = NULL;
            tail = awal;
            head = awal;
        }
        else
        {
            head->next = awal;
            awal->next = NULL;
            awal->back = head;
            head = awal;
        }

        cout << "Ada data lagi(y/t):";
        cin >> jawab;
        cout << endl;

        if (jawab == "y" || jawab == "Y")
        {
            j++;
            continue;
        }

    } while (jawab == "y" || jawab == "y");
    
}

void tampil_list_lifo()
{
    struct DLNode *lifo;
    cout << "Data Bilangan yang Telah Diinputkan secara LIFO :\n";
    lifo = tail;
    while (lifo != NULL)
    {
        printf("%d\t", lifo->bil);
        lifo = lifo->next;
    }
    cout << "\n";
}

void tampil_list_fifo()
{
    struct DLNode *fifo;
    cout << "Data Bilangan yang Telah Diinputkan secara FIFO :\n";
    fifo = head;
    while (fifo != NULL)
    {
        printf("%d\t", fifo->bil);
        fifo = fifo->back;
    }
    cout << "\n";
}

void sisip_simpul_tengah()
{
    int num;
    struct DLNode *sisip, *stl, *sbl;
    sisip = (struct DLNode *)malloc(sizeof(struct DLNode));

    cout << "Tuliskan bilangan yang akan disisipkan : ";
    scanf("%d", &sisip->bil);
    sisip->next = NULL;
    sisip->back = NULL;
    cout << "Bilangan disisipkan sebelum data : ";
    scanf("%d", &num);
    stl = tail;
    do
    {
        sbl = stl;
        stl = stl->next;
    } while (stl->bil != num);
    sisip->next = stl;
    sisip->back = sbl;
    sbl->next = sisip;
    stl->back = sisip;
}

void hapus_simpul()
{
    int num;
    struct DLNode *sbl, *hapus, *stl;
    cout << "Masukkan data yang akan dihapus : ";
    scanf("%d", &num);
    hapus = tail;

    // Menghapus Simpul Awal
    if (hapus->bil == num)
    {
        tail = tail->next;
        tail->back = NULL;
        free(hapus);
    }
    else
    {
        do
        {
            sbl = hapus;
            hapus = hapus->next;
        } while (hapus->bil != num);

        // Menghapus Simpul Terakhir
        if (hapus->next == NULL)
        {
            sbl->next = NULL;
            tail = sbl;
            free(hapus);
        }

        // Menghapus Simpul di Tengah
        else
        {
            stl = hapus->next;
            sbl->next = stl;
            stl->back = sbl;
            free(hapus);
        }
    }
}

int main()
{

    int pil;
    bentuk_awal();

    do
    {

        cout << endl;
        cout << "==============================" << endl;
        cout << " PROGRAM DOUBLE LINKED LIST " << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Data LIFO" << endl;
        cout << "2. Tampilkan Data FIFO" << endl;
        cout << "3. Sisipkan Data" << endl;
        cout << "4. Hapus Data Belakang" << endl;
        cout << "==============================" << endl;
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;
        cout << endl;

        switch (pil)
        {
        case 1: /* system("cls"); */
            tampil_list_lifo();
            cout << endl;
            break;
        case 2: /* system("cls"); */
            tampil_list_fifo();
            cout << endl;
            break;
        case 3: /* system("cls"); */
            sisip_simpul_tengah();
            cout << endl;
            break;
        case 4: /* system("cls"); */
            hapus_simpul();
            cout << endl;
            break;
        default: /* system("cls"); */
            cout << "\nMaaf, Pilihan Anda Salah";
            cout << endl;
        }

    } while (pil <= 4);
}