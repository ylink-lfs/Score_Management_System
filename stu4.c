#include "linked_list.h"
#include "manage_sys.h"


/*
按要求是1页10条信息。先这样写，程序能正常跑了再调格式
*/
void display_all_score(struct LinkedList* plist)
{
	wprintf(L"\n输出当前所有学生的信息：\n");
	wprintf(L"学号\t姓名\t总成绩\t数学\t物理\t英语\n");
	list_traverse(plist, member_display);
	wprintf(L"\n");
	return;
}