#include<iostream>
#include<stdio.h>
#include "linked_list.h"

//比赛项目的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//创建一个新的指针节点并分配空间
	pHeadNode->game = game;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(GameListNode* pHead ,Game game) {
	GameListNode* p = pHead;
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为player的节点
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
void deleteNode(GameListNode *p) {
	p->game = p->next->game;//将下一个节点的内容放入p中
	GameListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
	//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}
//传入头节点,返回有多少个节点
int longNode(GameListNode *pHead) {
	int i=0;
	GameListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//从文件中读取链表
GameListNode* readGamelist() {
	FILE *fp;//文件指针
	GameListNode* pHead;
	int line_long=0;
	Game game;
	/*文件的打开*/
	fp = fopen("/game.txt", "r");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
	fscanf_s(fp, "%d\n", &line_long);
	if (fp == NULL||line_long==0) {//判断如果文件指针为空
		fclose(fp);
		return NULL;
	}
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "%d\n", &game.name.id);//id
		fscanf_s(fp, "%s\n", &game.name.name,99);//名称
		fscanf_s(fp, "%s\n", &game.type,5);//类型
		fscanf_s(fp, "%s\n", &game.place,7);//地点
		fscanf_s(fp, "%d\n", &game.number);//人数
		fscanf_s(fp, "%d,%d,%d,%d\n", &game.starttime.month, &game.starttime.date, &game.starttime.hour, &game.starttime.minute);//开始时间
		fscanf_s(fp, "%d,%d,%d,%d\n", &game.endtime.month, &game.endtime.date, &game.endtime.hour, &game.endtime.minute);//结束时时间
		for (int j = 0; j < game.number; j++)
			fscanf_s(fp, "%d\n", &game.playerid[j]);//报名人员id
		if (i == 0) pHead = createpHead(game);
		else addNode(pHead, game);
	}
	fclose(fp);
	return pHead;

}
//把链表存入文件中
void saveGamelist(GameListNode* pHead) {
	FILE *fp;//文件指针
	fp = fopen("game.txt", "w");
	int line_long = longNode(pHead);//该链表有多少个节点
	GameListNode* p = pHead;
	Game game;

	fprintf(fp, "%d", line_long);//储存有多少个节点
	for (int i = 0; i < line_long; i++) {
		game = p->game;
		fprintf(fp, "%d\n", game.name.id/*id*/);
		fprintf(fp, "%s\n", game.name.name/*名称*/);
		fprintf(fp, "%s\n", game.type/*类型*/);
		fprintf(fp, "%s\n", game.place/*地点*/);
		fprintf(fp, "%d\n", game.number/*报名人数*/);
		fprintf(fp, "%d,%d,%d,%d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*开始时间*/);
		fprintf(fp, "%d,%d,%d,%d\n", game.endtime.month, game.endtime.date, game.endtime.hour, game.endtime.minute/*结束时间*/);
		for (int j = 0; j < game.number; j++)//储存报名人员id
			fprintf(fp, "%d\n", game.playerid[j]);
	}
	fclose(fp);
}

//运动员的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
PlayerListNode* createpHead(Player player) {
	PlayerListNode* pHeadNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pHeadNode->player = player;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(PlayerListNode* pHead, Player player) {
	PlayerListNode* p = pHead;
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	PlayerListNode* pNewNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pNewNode->player = player;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为player的节点
void insertNode(PlayerListNode *p, Player player) {
	PlayerListNode* pNewNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pNewNode->player = player;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
void deleteNode(PlayerListNode *p) {
	p->player = p->next->player;//将下一个节点的内容放入p中
	PlayerListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
							//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}




//组的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
GroupListNode* createpHead(Group group) {
	GroupListNode* pHeadNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pHeadNode->group = group;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(GroupListNode* pHead, Group group) {
	GroupListNode* p = pHead;
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	GroupListNode* pNewNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pNewNode->group = group;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为player的节点
void insertNode(GroupListNode *p, Group group) {
	GroupListNode* pNewNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pNewNode->group = group;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
void deleteNode(GroupListNode *p) {
	p->group = p->next->group;//将下一个节点的内容放入p中
	GroupListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
							//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}