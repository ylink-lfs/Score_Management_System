#include "linked_list.h"
#include "manage_sys.h"


/*
��Ҫ����1ҳ10����Ϣ��������д�����������������ٵ���ʽ
*/
void display_all_score(struct LinkedList* plist)
{
	wprintf(L"\n�����ǰ����ѧ������Ϣ��\n");
	wprintf(L"ѧ��\t����\t�ܳɼ�\t��ѧ\t����\tӢ��\n");
	list_traverse(plist, member_display);
	wprintf(L"\n");
	return;
}