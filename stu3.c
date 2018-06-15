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
		wprintf(L"��ṹ�����ڡ�������ֹ��\n");
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"��ṹ��СΪ0��������ֹ��\n");
	}
	else
	{
		
		wprintf(L"�������ѯ��ʽ����ʹ��ѧ�Ų�ѯ������1����ʹ��������ѯ������2��\n�ȴ����룺");
		while (wscanf(L"%d", &sentinal) != 1)
		{
			wprintf(L"��������ȷ��ģʽ���š���ʹ��ѧ�Ų�ѯ������1����ʹ��������ѯ������2��\n�ȴ����룺");
		}
		if (sentinal == 1)
		{
			
			wprintf(L"���������ѯѧ����ѧ�ţ�����EOF�Խ�����ѯ���̡�\n�ȴ����룺");
			while (wscanf(L"%ls", temp_id) == 1)
			{
				find_res = stu_ID_search(plist, temp_id);
				if (find_res != NULL)
				{
					member_display(&(find_res->item));
					wprintf(L"��ѯ�ɹ�����������һ��ѧ�ţ�������EOF�Խ�����ѯ���̡�\n�ȴ����룺");
				}
				else
				{
					wprintf(L"��ѧ�Ų������������ļ�������������ѧ�ţ�");
				}
			}
		}
		else
		{
			
			wprintf(L"���������ѯѧ��������������EOF�Խ�����ѯ���̡�\n�ȴ����룺");
			while (wscanf(L"%ls", temp_name) == 1)
			{
				find_res = stu_name_search(plist, temp_name);
				if (find_res != NULL)
				{
					member_display(&(find_res->item));
					wprintf(L"��ѯ�ɹ�����������һ��������������EOF�Խ�����ѯ���̡�\n�ȴ����룺");
				}
				else
				{
					wprintf(L"�������������������ļ�������������������");
				}
			}
		}
	}
	return;
}

/*
���������ӡ�ṹ��Ϣ���Դ�һ������
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