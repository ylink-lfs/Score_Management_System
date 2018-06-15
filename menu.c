#include "linked_list.h"
#include "manage_sys.h"

void display_menu(void)
{
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"|      ѧ���ɼ�����ϵͳ        |\n");
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"|      1---�ɼ�����            |\n");
	wprintf(L"|      2---�ɼ��޸�            |\n");
	wprintf(L"|      3---��ѯ�ɼ�            |\n");
	wprintf(L"|      4---��ʾ�ɼ�            |\n");
	wprintf(L"|      5---ͳ�Ƴɼ�            |\n");
	wprintf(L"|      6---ע��ѧ��            |\n");
	wprintf(L"|      7---�ɼ�����            |\n");
	wprintf(L"|      8---�˳�ϵͳ            |\n");
	wprintf(L"|----------------------------------------------------|\n");
	wprintf(L"����������(0~7)��ѡ����Ӧ���ܣ�");
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
		wprintf(L"��������ѡ�������ģʽ��0-�ܳɼ� 1-��ѧ 2-���� 3-Ӣ�");
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
		wprintf(L"����������");
		break;
	}
	return option;
}