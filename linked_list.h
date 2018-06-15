#ifndef LINKED_
#define LINKED_
#include <stdbool.h>
#include "manage_sys.h"

struct StuInfo
{
	wchar_t ID[25];
	wchar_t name[15];
	int math_score;
	int phy_score;
	int en_score;
	int tot_score;
};

typedef struct StuInfo Item;

struct LinkedNode
{
	Item item;
	struct LinkedNode* next;
};

/*
�����������ͷ�ڵ㣬�Ա��ڲ����ɾ��������
������ʵ�����������ʱ��һ�������ͷ�ڵ㣬��һ���������Ч���ݣ�
count��ֵӦ����1.��������Դ����ơ�
*/
struct LinkedList
{
	struct LinkedNode* head;
	struct LinkedNode* rear;
	size_t count;
};

struct LinkedList* initialize_linked_list(struct LinkedList* plist);

bool linked_list_is_empty(struct LinkedList* plist);

struct LinkedNode* list_search(struct LinkedList* plist, Item* ptar_item);

void list_insertion(struct LinkedList* plist, struct LinkedNode* ptar_node, Item* ptar_item);

void list_deletion(struct LinkedList* plist, struct LinkedNode* ptar_node);

void list_traverse(struct LinkedList* plist, void(*pfun)(Item* pitem));

void wipe_list(struct LinkedList* plist);

void list_merge(struct LinkedList* ptar, struct LinkedList* psrc);

#endif