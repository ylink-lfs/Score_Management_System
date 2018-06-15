#include "linked_list.h"
#include "manage_sys.h"

void display_menu(void)
{
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"|      学生成绩管理系统        |\n");
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"|      1---成绩输入            |\n");
	wprintf(L"|      2---成绩修改            |\n");
	wprintf(L"|      3---查询成绩            |\n");
	wprintf(L"|      4---显示成绩            |\n");
	wprintf(L"|      5---统计成绩            |\n");
	wprintf(L"|      6---注销学生            |\n");
	wprintf(L"|      7---成绩导入            |\n");
	wprintf(L"|      8---退出系统            |\n");
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"请输入数字(0~7)以选择相应功能：");
	return;
}

int switch_option(int option, struct LinkedList* opt_list)
{
	switch (option)
	{
	case 1:
		add_record(opt_list);
		break;
	case 2:
		modify_info(modify_which(opt_list));
		break;
	case 3:
		stu_query(opt_list);
		break;
	case 4:
		display_all_score(opt_list);
		break;
	case 5:
		wprintf(L"请输入想选择的排序模式：0-总成绩 1-数学 2-物理 3-英语：");
		int opt;
		wscanf(L"%d", &opt);
		score_sort(opt_list, opt);
		break;
	case 6:
		delete_record(opt_list);
		break;
	case 7:
		add_record(opt_list);
		break;
	case 0:
		break;
	defalut:
		wprintf(L"序号输入错误。");
		break;
	}
	return option;
}