#include <fstream>
#ifndef TWO_SIDED_LIST_H
#define TWO_SIDED_LIST_H

struct tnode {
    int info;
    tnode* next;
    tnode* prev;
};

typedef tnode* pnode;

void forming_list(pnode start, pnode& end); // формування списку
void output_primary(pnode start); // вивід списку у звичайному порядку
void output_reverse(pnode end); // вивід списку у зворотньому порядку
void symmetry(pnode start, pnode end); // перевірка списку на симетричність
void del_el(pnode start, int info_to_del); // видалення заданого елементу
void add_el_before(pnode start, int info); // додавання елементу перед заданим
void add_el_after(pnode start, int info); // додавання елементу після заданого
int count_el(pnode start); // підрахунок кількості елементів у списку
void del_list(pnode start, pnode end); // видалення списку

#endif
