#include "linked_list.h"
#include "manage_sys.h"

void stu_query(struct LinkedList* plist)
{
	int sentinal = 0;
	wchar_t temp_id[50];
	wchar_t temp_name[50];
	struct LinkedNode* find_res = NULL;
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
		
		wprintf(L"请决定查询方式。若使用学号查询请输入1。若使用姓名查询请输入2。\n等待输入：");
		while (wscanf(L"%d", &sentinal) != 1)
		{
			wprintf(L"请输入正确的模式代号。若使用学号查询请输入1。若使用姓名查询请输入2。\n等待输入：");
		}
		if (sentinal == 1)
		{
			
			wprintf(L"请输入待查询学生的学号，输入EOF以结束查询过程。\n等待输入：");
			while (wscanf(L"%ls", temp_id) == 1)
			{
				find_res = stu_ID_search(plist, temp_id);
				if (find_res != NULL)
				{
					member_display(&(find_res->item));
					wprintf(L"查询成功。请输入下一个学号，或输入EOF以结束查询过程。\n等待输入：");
				}
				else
				{
					wprintf(L"该学号不存在于数据文件。请重新输入学号：");
				}
			}
		}
		else
		{
			
			wprintf(L"请输入待查询学生的姓名，输入EOF以结束查询过程。\n等待输入：");
			while (wscanf(L"%ls", temp_name) == 1)
			{
				find_res = stu_name_search(plist, temp_name);
				if (find_res != NULL)
				{
					member_display(&(find_res->item));
					wprintf(L"查询成功。请输入下一个姓名，或输入EOF以结束查询过程。\n等待输入：");
				}
				else
				{
					wprintf(L"该姓名不存在于数据文件。请重新输入姓名：");
				}
			}
		}
	}
	return;
}

/*
这个函数打印结构信息会自带一个换行
*/
void member_display(struct StuInfo* pstu)
{
	if (pstu)
	{
		wprintf(L"%ls\t%ls\t%d\t%d\t%d\t%d\n", pstu->ID, pstu->name,
			pstu->tot_score, pstu->math_score, pstu->phy_score, pstu->en_score);
	}
	return;
}

struct LinkedNode* stu_ID_search(struct LinkedList* plist, wchar_t* ptr_to_id)
{
	if (plist == NULL || ptr_to_id == NULL || linked_list_is_empty(plist))
	{
		return NULL;
	}
	struct LinkedNode* current = plist->head->next;
	while (current && wcscmp(ptr_to_id, current->item.ID) != 0)
	{
		current = current->next;
	}
	return current;
}

struct LinkedNode* stu_name_search(struct LinkedList* plist, wchar_t* ptr_to_name)
{
	if (plist == NULL || ptr_to_name == NULL || linked_list_is_empty(plist))
	{
		return NULL;
	}
	struct LinkedNode* current = plist->head->next;
	while (current && wcscmp(ptr_to_name, current->item.name) != 0)
	{
		current = current->next;
	}
	return current;
}