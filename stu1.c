#include "linked_list.h"
#include "manage_sys.h"

void add_record(struct LinkedList* plist)
{
	struct StuInfo* temp_info = malloc(sizeof(struct StuInfo));
	wchar_t temp_str[200];
	int math, ph, eng;
	wprintf(L"请输入新学生的学号，输入EOF以终止输入：");
	while (wscanf(L"%ls", temp_str) == 1)
	{
		wcscpy(temp_info->ID, temp_str);

		wprintf(L"请输入新学生的姓名：");
		wscanf(L"%ls", temp_str);
		wcscpy(temp_info->name, temp_str);

		wprintf(L"请依次输入新学生的数学、物理、英语成绩：");
		wscanf(L"%d%d%d", &math, &ph, &eng);
		temp_info->math_score = math;
		temp_info->phy_score = ph;
		temp_info->en_score = eng;
		temp_info->tot_score = math + ph + eng;

		/*
		依据ADT定义，这样传参能直接尾插
		*/
		list_insertion(plist, NULL, temp_info);
		wprintf(L"请输入下一位待记录学生的学号，输入EOF以终止输入：");
	}
	return;
}