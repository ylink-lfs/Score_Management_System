#include "linked_list.h"
#include "manage_sys.h"

void modify_info(struct StuInfo* pstu)
{
	int new_m, new_p, new_e;
	wprintf(L"�����������ѧ������ѧ������Ӣ���³ɼ���");
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
		wprintf(L"��ṹ�����ڡ�������ֹ��\n");
		return NULL;
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"��ṹ��СΪ0��������ֹ��\n");
		return NULL;
	}
	else
	{
		
		wprintf(L"����������ĳɼ���ѧ��ѧ�ţ�");
		wscanf(L"%ls", temp_id);
		return &(stu_ID_search(plist, temp_id)->item);
	}
	

}