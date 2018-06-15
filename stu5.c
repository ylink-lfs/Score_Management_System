#include "linked_list.h"
#include "manage_sys.h"

void score_sort(struct LinkedList* plist, int accordance)
{
	struct LinkedNode* upper_ptr = NULL;
	struct LinkedNode* lower_ptr = NULL;
	struct StuInfo temp_struct;
	if (plist == NULL)
	{
		wprintf(L"表结构不存在。过程终止。\n");
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"表结构大小为0。过程终止。\n");
	}
	else
	{
		for (upper_ptr = plist->head->next; upper_ptr->next != NULL; upper_ptr = upper_ptr->next)
		{
			for (lower_ptr = upper_ptr->next; lower_ptr != NULL; lower_ptr = lower_ptr->next)
			{			
				switch (accordance)
				{
				case 0:
					if (upper_ptr->item.tot_score > lower_ptr->item.tot_score)
					{
						temp_struct = upper_ptr->item;
						upper_ptr->item = lower_ptr->item;
						lower_ptr->item = temp_struct;
					}
					break;
				case 1:
					if (upper_ptr->item.math_score > lower_ptr->item.math_score)
					{
						temp_struct = upper_ptr->item;
						upper_ptr->item = lower_ptr->item;
						lower_ptr->item = temp_struct;
					}
					break;
				case 2:
					if (upper_ptr->item.phy_score > lower_ptr->item.phy_score)
					{
						temp_struct = upper_ptr->item;
						upper_ptr->item = lower_ptr->item;
						lower_ptr->item = temp_struct;
					}
					break;
				case 3:
					if (upper_ptr->item.en_score > lower_ptr->item.en_score)
					{
						temp_struct = upper_ptr->item;
						upper_ptr->item = lower_ptr->item;
						lower_ptr->item = temp_struct;
					}
					break;
				}
			}
		}
		wprintf(L"排序完成。\n");
	}
	return;
}