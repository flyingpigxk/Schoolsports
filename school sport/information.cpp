#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"


void information_game(GameListNode* pnewHead,int situation) {//输入头节点和对应的位置(第几个)
	int i = 1;
	GameListNode* p=pnewHead;
	Game game;
	char entry[99];

	while (i != situation) {//找到所选择的节点
		p = p->next;
		i++;
	}

	system("CLS");
	game = p->game;
	printf( "项目信息:\n");//打印项目基本信息
	printf("名称:%s\n", game.name.name/*名称*/);
	printf("类型:%s\n", game.type/*类型*/);
	printf("地点:%s\n", game.place/*地点*/);
	printf("人数:%d\n", game.number/*报名人数*/);
	printf("时间:%d月%d日%d : %d-%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*开始时间*/, game.endtime.hour, game.endtime.minute/*结束时间*/);
	printf("报名人员ID:");
	if (game.playerid[0] == NULL|| game.playerid[0]<=0) printf("无");
	else for (int j = 0; j < game.number; j++) printf("%d   ", game.playerid[j]);//报名人员id
	printf("\n\n\n");


	printf("操作:\n");//操作
	printf("1.修改\n2.删除\n3.返回\n");//选项

	int x=0;
	char entry_s[99];
	while (x == 0)//输入检测
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 3);
		if (x == 0)printf("输入有误,请重新输入:");
	}
	switch (x)
	{
	case 1: reviseGame(game); break;//修改
	case 2:
	{
		GameListNode* pHead = readGamelist();
		p = pHead;
		while (p->game.name.id!=game.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
			p = p->next;
		}
		pHead = deleteNode(pHead, p);
		saveGamelist(pHead);
		printf("\n\n删除完成\n");
		system("pause");
	}
		break;//删除
	case 3:break;//返回
	}
}

void information_player(PlayerListNode* pnewHead, int situation) {
	int i = 1;
	PlayerListNode* p = pnewHead;
	Player player;
	char entry[99];

	while (i != situation) {//找到所选择的节点
		p = p->next;
		i++;
	}

	system("CLS");
	player = p->player;
	printf("运动员信息:\n");//打印项目基本信息
	printf("ID:%d\n", player.name.id);//id
	printf("名称:%s\n", player.name.name);//名称
	printf("性别:%s\n", player.gender);//性别
	printf("年龄:%d\n", player.year);//id
	printf("小组ID:%d\n", player.group_id);//小组ID
	printf("总分数:%d\n", player.fullscore);//总分数
	printf("比赛数:%d\n", player.game_number);//比赛数

	printf("比赛项目:\n", player.game_number);//比赛数
	if (player.game_number == 0) printf("无\n");
	else 
	for (int j = 0; j < player.game_number; j++) {
		printf("项目名称:%s ", player.score->name.name);//项目名称
		printf("项目成绩:%f ", player.score->score);//项目成绩
		printf("项目得分:%d \n", player.score->point);//项目成绩
	}


	printf("\n\n\n");
	printf("操作:\n");//操作
	printf("1.修改\n2.删除\n3.返回\n");//选项

	int x = 0;
	char entry_s[99];
	while (x == 0)//输入检测
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 3);
		if (x == 0)printf("输入有误,请重新输入:");
	}
	switch (x)
	{
	case 1: revisePlayer(player); break;//修改
	case 2:
	{
		PlayerListNode* pHead = readPlayerlist();
		p = pHead;
		while (p->player.name.id != player.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
			p = p->next;
		}
		pHead = deleteNode(pHead, p);
		savePlayerlist(pHead);
		printf("\n\n删除完成\n");
		system("pause");
	}//删除
	break;
	case 3:break;//返回
	}
}