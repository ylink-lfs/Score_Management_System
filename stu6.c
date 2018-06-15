#include "linked_list.h"
#include "manage_sys.h"

void delete_record(struct LinkedList* plist)
{
	wchar_t temp_id[50];
	struct LinkedNode* find_res = NULL;
	if (plist == NULL)
	{
		wprintf(L"��ṹ�����ڡ�������ֹ��\n");
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"��ṹ��СΪ0��������ֹ��\n");
	}
	else
	{
		
		wprintf(L"�������ע��ѧ����ѧ�ţ�����EOF�Խ���ɾ�����̡�\n�ȴ����룺");
		while (wscanf(L"%ls", temp_id) == 1)
		{
			find_res = stu_ID_search(plist, temp_id);
			if (find_res != NULL)
			{
				list_deletion(plist, find_res);
				wprintf(L"ɾ���ɹ�����������һ��ѧ�ţ�������EOF�Խ���ɾ�����̡�\n�ȴ����룺");
			}
			else
			{
				wprintf(L"��ѧ�Ų������������ļ�������������ѧ�ţ�");
			}
		}
	}
	return;
}