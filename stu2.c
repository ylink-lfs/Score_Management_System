#include "linked_list.h"
#include "manage_sys.h"

void modify_info(struct StuInfo* pstu)
{
	int new_m, new_p, new_e;
	wprintf(L"请依次输入该学生的数学、物理、英语新成绩：");
	wscanf(L"%d%d%d", &new_m, &new_p, &new_e);
	pstu->math_score = new_m;
	pstu->phy_score = new_p;
	pstu->en_score = new_e;
	pstu->tot_score = new_m + new_p + new_e;
	return;
}

struct StuInfo* modify_which(struct LinkedList* plist)
{
	wchar_t temp_id[50];
	if (plist == NULL)
	{
		wprintf(L"表结构不存在。过程终止。\n");
		return NULL;
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"表结构大小为0。过程终止。\n");
		return NULL;
	}
	else
	{
		
		wprintf(L"请输入待更改成绩的学生学号：");
		wscanf(L"%ls", temp_id);
		return &(stu_ID_search(plist, temp_id)->item);
	}
	

}