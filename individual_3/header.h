// Реалізувати АТД Упорядкована множина (Sorted Set). На базі
// хеш-таблиці у вигляді масиву упорядкованих списків.

#ifndef SORTED_SET
#define SORTED_SET

struct tnode {
    int info;
    tnode* next;
};

typedef tnode* pnode;

bool isExist(pnode& head, int value);
void insertSorted(pnode& head, int value);
void displayList(pnode head);
void removeByValue(pnode& head, int value);
void deleteList(pnode& head);


class SortedSet {
private:
    static const int SIZE = 10;
    tnode* array[SIZE];

    int hash_map(int value);

public:
    SortedSet();
    void insertInto(int value);
    void deleteItem(int value);
    bool isExistInSet(int value);
    void output();
    int number_of_elem();
    ~SortedSet();
};

#endif
