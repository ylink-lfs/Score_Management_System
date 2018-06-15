#ifndef MANAGE_
#define MANAGE_
#include <stdio.h>
#include <wchar.h>
#include "linked_list.h"

void display_menu(void);

int switch_option(int option, struct LinkedList* opt_list);

void add_record(struct LinkedList* plist);

void modify_info(struct StuInfo* pstu);

struct StuInfo* modify_which(struct LinkedList* plist);

void stu_query(struct LinkedList* plist);

void member_display(struct StuInfo* pstu);

void display_all_score(struct LinkedList* plist);

void score_sort(struct LinkedList* plist, int accordance);

void delete_record(struct LinkedList* plist);

void append_file(struct LinkedList* plist);

struct LinkedNode* stu_ID_search(struct LinkedList* plist, wchar_t* ptr_to_id);

struct LinkedNode* stu_name_search(struct LinkedList* plist, wchar_t* ptr_to_name);

#endif