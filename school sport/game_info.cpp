#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

bool game_info() {
	char entry;
	system("CLS");
	printf("项目信息\n");
	printf("1.增加\n");
	printf("2.修改\n");
	printf("3.删除\n");
	printf("4.查询\n");
	printf("5.返回\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: if (game_info()) return true; break;
	case 1:add_info(type_game); if (game_info()) return true; break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
}