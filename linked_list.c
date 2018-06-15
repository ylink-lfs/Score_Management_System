#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include "linked_list.h"
#include "manage_sys.h"

struct LinkedList* initialize_linked_list(struct LinkedList* plist)
{
	plist = malloc(sizeof(struct LinkedList));
	plist->head = malloc(sizeof(struct LinkedNode));
	plist->rear = plist->head;

	Item temp_item;
	temp_item.math_score = temp_item.phy_score = temp_item.en_score = temp_item.tot_score = -10;

	plist->head->item = temp_item;
	plist->head->next = NULL;

	plist->count = 0;

	return plist;
}

bool linked_list_is_empty(struct LinkedList* plist)
{
	return plist->count > 0 ? false : true;
}

struct LinkedNode* list_search(struct LinkedList* plist, Item* ptar_item)
{
	if (plist == NULL || ptar_item->tot_score < 0 || linked_list_is_empty(plist))
	{
		return NULL;
	}
	struct LinkedNode* current = plist->head->next;
	while (current && wcscmp(ptar_item->ID, current->item.ID) != 0)
	{
		current = current->next;
	}
	return current;
}


/*
如果ptar_node指向的item在链表中不存在(包括ptar_node直接为NULL)，那么自动插ptar_item到表尾。
否则插入ptar_item位置在ptar_node所在的位置后一位
*/
void list_insertion(struct LinkedList* plist, struct LinkedNode* ptar_node, Item* ptar_item)
{
	struct LinkedNode* pnew = malloc(sizeof(struct LinkedNode));
	pnew->item = *ptar_item;

	struct LinkedNode* find_res = NULL;
	if (ptar_node != NULL)
		find_res = list_search(plist, &(ptar_node->item));

	if (find_res == NULL)
	{
		plist->rear->next = pnew;
		pnew->next = NULL;
		plist->rear = pnew;
	}
	else
	{
		pnew->next = find_res->next;
		find_res->next = pnew;
	}
	plist->count++;
	return;
}

/*
推荐这样调用：list_deletion(test_list, list_search(test_pointer_to_item))
*/
void list_deletion(struct LinkedList* plist, struct LinkedNode* ptar_node)
{
	if (ptar_node != NULL)
	{
		struct LinkedNode* pre = plist->head;
		while (pre->next != ptar_node)
		{
			pre = pre->next;
		}
		pre->next = ptar_node->next;
		free(ptar_node);
		plist->count--;
	}
	return;
}

void list_traverse(struct LinkedList* plist, void(*pfun)(Item* pitem))
{
	if (!linked_list_is_empty(plist))
	{
		struct LinkedNode* current = plist->head->next;
		while (current)
		{
			pfun(&(current->item));
			current = current->next;
		}
	}
	return;
}

void wipe_list(struct LinkedList* plist)
{
	if (plist->count == 0)
	{
		free(plist->head);
	}
	else
	{
		struct LinkedNode* current_node = plist->head;
		struct LinkedNode* pre = NULL;
		while (current_node)
		{
			pre = current_node;
			current_node = current_node->next;
			free(pre);
		}
	}
	free(plist);
	return;
}

void list_merge(struct LinkedList* ptar, struct LinkedList* psrc)
{
	ptar->rear->next = psrc->head->next;
	ptar->count += psrc->count;
	ptar->rear = psrc->rear;
	free(psrc->head);
	free(psrc);
	return;
}