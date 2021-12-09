#include <iostream>
#include <string>

using namespace std;
template<typename K, typename D>

class HashNode
{
public:
    K key;
    D data;
    HashNode(K key, D data)
    {
        this->data = data;
        this->key = key;
    }
};
template<typename K, typename D>
class HashTable
{
    HashNode<K, D>** arr;
    HashNode<K, D>* arrSec;
    int capacity;
    int size;

public:
    HashTable()
    {
        capacity = 20;
        size = 0;
        arr = new HashNode<K, D> *[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
        arrSec = new HashNode<K, D>(-1, "");
    }
    int hashFunc(K key)
    {
        return key % capacity;
    }
    void insertNode(K key, D data)
    {
        setlocale(LC_ALL, "Russian");
        HashNode<K, D>* temp = new HashNode<K, D>(key, data);
        long int hashIndex = hashFunc(key);
        int count = 1;
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
            && arr[hashIndex]->key != -1)
        {
            hashIndex = (hashIndex + (count * count) * (20 / capacity));
            count++;
        }
        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }
    D get(long long int key)
    {
        long int hashIndex = hashFunc(key);
        int counter = 0;
        while (arr[hashIndex] != NULL)
        {
            int counter = 0;
            if (counter++ > capacity)
                return NULL;
            if (arr[hashIndex]->key == key)
                cout << "Данные под ключом " << arr[hashIndex]->key << " : ";
            return arr[hashIndex]->data;
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }
    D deleteNode(long long int key)
    {
        long int hashIndex = hashFunc(key);
        while (arr[hashIndex] != NULL)
        {
            if (arr[hashIndex]->key == key)
            {
                HashNode<K, D>* temp = arr[hashIndex];
                arr[hashIndex] = arrSec;
                size--;
                return temp->data;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }
    void DispHashFunc(K key) {
        long int HashIndex = 0;
        int count = 1;
        HashIndex = key % capacity;
        while (arr[HashIndex] != NULL && arr[HashIndex]->key != key
            && arr[HashIndex]->key != -1)
        {
            HashIndex = (HashIndex + (count * count) * (20 / capacity));
            count++;
        }
        cout << "      |" << HashIndex << "|  ";
    }
    void display()
    {
        setlocale(LC_ALL, "Russian");
        cout << "Хэш-код| ";
        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] != NULL && arr[i]->key != -1) {
                DispHashFunc(arr[i]->key);
            }
        }
        cout << endl << "Ключ|     ";
        for (int i = 0; i < capacity; i++)
        {

            if (arr[i] != NULL && arr[i]->key != -1) {

                cout << "|" << arr[i]->key << "|";
            }

        }
        cout << endl << "Значение| ";
        for (int i = 0; i < capacity; i++)
        {

            if (arr[i] != NULL && arr[i]->key != -1) {

                cout << "|" << arr[i]->data << "|";
            }

        }
    }
};  

int coun;
void dialog(int C, long long int K, string D) {
    setlocale(LC_ALL, "Russian");
    int c = 0;
    
    HashTable<long long int, string>* h = new HashTable<long long int, string>;
   
        c=C;
        long long int key = K;
        string data = D;
        while (c <= 4) {
            switch (c) {
            case 1:

                cout << "Выбрана функция 1" << endl;
                h->insertNode(key, data);
                cout << "Элемент с ключом: " << key << " вставлен" << endl;
                cout << "Содержимое: " << data << endl;
                coun++;
                break;

            case 2:
                cout << "Выбрана функция 2" << endl;

                if (coun == 0) {
                    cout << "Таблица пуста" << endl;
                    break;
                }
                else {
                    cout << h->get(key);
                    break;
                }
            case 3:
                cout << "Выбрана функция 3" << endl;

                if (coun == 0) {
                    cout << "Таблица пуста" << endl;
                    break;
                }
                else {
                    h->deleteNode(key);
                    cout << "Элемент удален " << endl;
                    coun--;
                    break;
                }

            case 4:
                cout << "Выбрана функция 4" << endl;
                if (coun == 0) {
                    cout << "Таблица пуста" << endl;
                    break;
                }
                else {
                    h->display();
                    break;
                }
            }
            c++;
        }


}


void input() {
    cout << "1.Вставить элемент " << endl;
    cout << "2.Поиск элемента  " << endl;
    cout << "3.Удалить элемент" << endl;
    cout << "4.Вывод таблицы " << endl << endl;

    long long int key = 8988888888;
    string data = "St.Pushkina5";
    if (key == NULL) {
        cout << "Ключ не введен";
        exit(0);

    }
    else if (key < 0) {
        cout << "Введен отрицательный ключ";
        exit(0);

    }
    if (data == "") {
        cout << "Данные не введены";
        exit(0);
    }

    dialog(2, key, data);
 
}
int main()
{
    setlocale(LC_ALL, "Russian");
    input();
    return 0;
}
/*  if (coun == 0) {
                cout << "Таблица пуста" << endl;
                break;
            }*/