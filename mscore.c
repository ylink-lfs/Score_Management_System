#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "linked_list.h"
#include "manage_sys.h"

struct LinkedList* global_list;

void assign_to_list(struct LinkedList* plist, FILE* pfile);
void assign_to_file(FILE* pfile, struct LinkedList* plist);

int main(void)
{
	FILE* ptr_to_src = fopen("stu.dat", "r");
	int option_sentinal = 0;

	setlocale(LC_CTYPE, "chs");
	global_list = initialize_linked_list(global_list);
	assign_to_list(global_list, ptr_to_src);
	fclose(ptr_to_src);

	display_menu();
	while (wscanf(L"%d", &option_sentinal) == 1 && option_sentinal != 0)
	{
		switch_option(option_sentinal, global_list);
		wprintf(L"请输入下一个数字以选择功能：");
	}
	ptr_to_src = fopen("stu.dat", "w");
	assign_to_file(ptr_to_src, global_list);
	wipe_list(global_list);

	return 0;
}

void assign_to_list(struct LinkedList* plist, FILE* pfile)
{
	wchar_t large_temp_str[200];
	wchar_t temp_id[50];
	wchar_t temp_name[50];
	struct StuInfo* temp_struct = NULL;
	int t_m, t_p, t_e, t_t;
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
		list_insertion(plist, NULL, temp_struct);
	}
	return;
}

void assign_to_file(FILE* pfile, struct LinkedList* plist)
{
	struct LinkedNode* current = plist->head->next;
	fwprintf(pfile, L"学号，姓名，数学，物理，外语，总成绩\n");
	while (current)
	{
		fwprintf(pfile, L"%ls，%ls，%d,%d,%d,%d\n", current->item.ID, current->item.name,
			current->item.math_score, current->item.phy_score,
			current->item.en_score, current->item.tot_score);
		current = current->next;
	}
	return;
}