#include "linked_list.h"
#include "manage_sys.h"

void delete_record(struct LinkedList* plist)
{
	wchar_t temp_id[50];
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
		
		wprintf(L"请输入待注销学生的学号，输入EOF以结束删除过程。\n等待输入：");
		while (wscanf(L"%ls", temp_id) == 1)
		{
			find_res = stu_ID_search(plist, temp_id);
			if (find_res != NULL)
			{
				list_deletion(plist, find_res);
				wprintf(L"删除成功。请输入下一个学号，或输入EOF以结束删除过程。\n等待输入：");
			}
			else
			{
				wprintf(L"该学号不存在于数据文件。请重新输入学号：");
			}
		}
	}
	return;
}