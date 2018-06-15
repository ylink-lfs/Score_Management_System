#include <stdlib.h>
#include "linked_list.h"
#include "manage_sys.h"


/*
这个函数的正常工作需要这些前置条件：
输入的dat文件严格按照这个格式保存数据：
学号（中文逗号）姓名（中文逗号）数学（中文逗号）物理（中文逗号）外语（中文逗号）总成绩
学号（中文逗号）姓名（中文逗号）数学（英文逗号）物理（英文逗号）外语（英文逗号）总成绩

我也不知道为什么作业的dat输入文件的排版格式要搞这么奇怪
*/
void append_file(struct LinkedList* plist)
{
	wchar_t large_temp_str[200];
	wchar_t temp_id[50];
	wchar_t temp_name[50];
	char file_name[200];
	struct LinkedList* sublist = NULL;
	FILE* pfile = NULL;
	int t_m, t_p, t_e, t_t;
	struct StuInfo* temp_struct = NULL;

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
		sublist = initialize_linked_list(sublist);
		wprintf(L"请输入待合并的文件名：");
		scanf("%s", file_name);
		if ((pfile = fopen(file_name, "r")) == NULL)
		{
			wprintf(L"文件不存在。过程终止。\n");
		}
		else
		{
			
			fwscanf(pfile, L"%ls", large_temp_str);
			while (fwscanf(pfile, L"%ls", large_temp_str) == 1)
			{
				wchar_t* opt_pt;

				opt_pt = wcschr(large_temp_str, L'，');
				*opt_pt = '\n';
				opt_pt = wcschr(large_temp_str, L'，');
				*opt_pt = '\n';

				opt_pt = wcschr(large_temp_str, L',');
				*opt_pt = '\n';
				opt_pt = wcschr(large_temp_str, L',');
				*opt_pt = '\n';
				opt_pt = wcschr(large_temp_str, L',');
				*opt_pt = '\n';

				swscanf(large_temp_str, L"%ls%ls%d%d%d%d", temp_id, temp_name, &t_m, &t_p, &t_e, &t_t);
				
				
				temp_struct = malloc(sizeof(struct StuInfo));
				wcscpy(temp_struct->ID, temp_id);
				wcscpy(temp_struct->name, temp_name);
				temp_struct->math_score = t_m;
				temp_struct->phy_score = t_p;
				temp_struct->en_score = t_e;
				temp_struct->tot_score = t_t;
				list_insertion(sublist, NULL, temp_struct);
			}
			list_merge(plist, sublist);
			fclose(pfile);
		}
	}
	return;
}