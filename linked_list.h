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
假设链表存在头节点，以便于插入和删除操作。
这样，实际有两个结点时，一个结点是头节点，另一个结点存放有效数据，
count的值应该是1.其他情况以此类推。
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