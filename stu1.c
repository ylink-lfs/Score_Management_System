#include "linked_list.h"
#include "manage_sys.h"

void add_record(struct LinkedList* plist)
{
	struct StuInfo* temp_info = malloc(sizeof(struct StuInfo));
	wchar_t temp_str[200];
	int math, ph, eng;
	wprintf(L"��������ѧ����ѧ�ţ�����EOF����ֹ���룺");
	while (wscanf(L"%ls", temp_str) == 1)
	{
		wcscpy(temp_info->ID, temp_str);

		wprintf(L"��������ѧ����������");
		wscanf(L"%ls", temp_str);
		wcscpy(temp_info->name, temp_str);

		wprintf(L"������������ѧ������ѧ������Ӣ��ɼ���");
		wscanf(L"%d%d%d", &math, &ph, &eng);
		temp_info->math_score = math;
		temp_info->phy_score = ph;
		temp_info->en_score = eng;
		temp_info->tot_score = math + ph + eng;

		/*
		����ADT���壬����������ֱ��β��
		*/
		list_insertion(plist, NULL, temp_info);
		wprintf(L"��������һλ����¼ѧ����ѧ�ţ�����EOF����ֹ���룺");
	}
	return;
}