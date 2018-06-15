#include <stdlib.h>
#include "linked_list.h"
#include "manage_sys.h"


/*
�������������������Ҫ��Щǰ��������
�����dat�ļ��ϸ��������ʽ�������ݣ�
ѧ�ţ����Ķ��ţ����������Ķ��ţ���ѧ�����Ķ��ţ��������Ķ��ţ�������Ķ��ţ��ܳɼ�
ѧ�ţ����Ķ��ţ����������Ķ��ţ���ѧ��Ӣ�Ķ��ţ�����Ӣ�Ķ��ţ����Ӣ�Ķ��ţ��ܳɼ�

��Ҳ��֪��Ϊʲô��ҵ��dat�����ļ����Ű��ʽҪ����ô���
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
		wprintf(L"��ṹ�����ڡ�������ֹ��\n");
	}
	else if (linked_list_is_empty(plist))
	{
		wprintf(L"��ṹ��СΪ0��������ֹ��\n");
	}
	else
	{
		sublist = initialize_linked_list(sublist);
		wprintf(L"��������ϲ����ļ�����");
		scanf("%s", file_name);
		if ((pfile = fopen(file_name, "r")) == NULL)
		{
			wprintf(L"�ļ������ڡ�������ֹ��\n");
		}
		else
		{
			
			fwscanf(pfile, L"%ls", large_temp_str);
			while (fwscanf(pfile, L"%ls", large_temp_str) == 1)
			{
				wchar_t* opt_pt;

				opt_pt = wcschr(large_temp_str, L'��');
				*opt_pt = '\n';
				opt_pt = wcschr(large_temp_str, L'��');
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