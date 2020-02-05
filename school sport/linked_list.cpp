#include<iostream>
#include<stdio.h>
#include "linked_list.h"

//������Ŀ����������

//����һ��������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->game = game;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(GameListNode* pHead ,Game game) {
	GameListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->game = game;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
void deleteNode(GameListNode *p) {
	p->game = p->next->game;//����һ���ڵ�����ݷ���p��
	GameListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
	//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
}
//����ͷ�ڵ�,�����ж��ٸ��ڵ�
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
//���ļ��ж�ȡ����
GameListNode* readGamelist() {
	FILE *fp;//�ļ�ָ��
	GameListNode* pHead;
	int line_long=0;
	Game game;
	/*�ļ��Ĵ�*/
	fp = fopen("/game.txt", "r");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
	fscanf_s(fp, "%d\n", &line_long);
	if (fp == NULL||line_long==0) {//�ж�����ļ�ָ��Ϊ��
		fclose(fp);
		return NULL;
	}
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "%d\n", &game.name.id);//id
		fscanf_s(fp, "%s\n", &game.name.name,99);//����
		fscanf_s(fp, "%s\n", &game.type,5);//����
		fscanf_s(fp, "%s\n", &game.place,7);//�ص�
		fscanf_s(fp, "%d\n", &game.number);//����
		fscanf_s(fp, "%d,%d,%d,%d\n", &game.starttime.month, &game.starttime.date, &game.starttime.hour, &game.starttime.minute);//��ʼʱ��
		fscanf_s(fp, "%d,%d,%d,%d\n", &game.endtime.month, &game.endtime.date, &game.endtime.hour, &game.endtime.minute);//����ʱʱ��
		for (int j = 0; j < game.number; j++)
			fscanf_s(fp, "%d\n", &game.playerid[j]);//������Աid
		if (i == 0) pHead = createpHead(game);
		else addNode(pHead, game);
	}
	fclose(fp);
	return pHead;

}
//�����������ļ���
void saveGamelist(GameListNode* pHead) {
	FILE *fp;//�ļ�ָ��
	fp = fopen("game.txt", "w");
	int line_long = longNode(pHead);//�������ж��ٸ��ڵ�
	GameListNode* p = pHead;
	Game game;

	fprintf(fp, "%d", line_long);//�����ж��ٸ��ڵ�
	for (int i = 0; i < line_long; i++) {
		game = p->game;
		fprintf(fp, "%d\n", game.name.id/*id*/);
		fprintf(fp, "%s\n", game.name.name/*����*/);
		fprintf(fp, "%s\n", game.type/*����*/);
		fprintf(fp, "%s\n", game.place/*�ص�*/);
		fprintf(fp, "%d\n", game.number/*��������*/);
		fprintf(fp, "%d,%d,%d,%d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/);
		fprintf(fp, "%d,%d,%d,%d\n", game.endtime.month, game.endtime.date, game.endtime.hour, game.endtime.minute/*����ʱ��*/);
		for (int j = 0; j < game.number; j++)//���汨����Աid
			fprintf(fp, "%d\n", game.playerid[j]);
	}
	fclose(fp);
}

//�˶�Ա����������

//����һ��������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
PlayerListNode* createpHead(Player player) {
	PlayerListNode* pHeadNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->player = player;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(PlayerListNode* pHead, Player player) {
	PlayerListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	PlayerListNode* pNewNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->player = player;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(PlayerListNode *p, Player player) {
	PlayerListNode* pNewNode = new PlayerListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->player = player;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
void deleteNode(PlayerListNode *p) {
	p->player = p->next->player;//����һ���ڵ�����ݷ���p��
	PlayerListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
							//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
}




//�����������

//����һ��������ͷ�ڵ�,��������ֵΪ�ýڵ�ָ��
GroupListNode* createpHead(Group group) {
	GroupListNode* pHeadNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pHeadNode->group = group;//��gmae��ֵ���Ľڵ���
	pHeadNode->next = NULL;//�ýڵ��nextָ��NULL
	return pHeadNode;
}
//���������������һ���ڵ�,�����ڵ������Ϊplayer,pHeadΪ����������һָ��ڵ�.
void addNode(GroupListNode* pHead, Group group) {
	GroupListNode* p = pHead;
	while (p->next != NULL) {//�ҵ����Ľڵ�ָ��
		p = p->next;
	}
	GroupListNode* pNewNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->group = group;//��gmae��ֵ���Ľڵ���
	pNewNode->next = NULL;//�ýڵ��nextָ��NULL
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//p�ڵ�����ֵΪplayer�Ľڵ�
void insertNode(GroupListNode *p, Group group) {
	GroupListNode* pNewNode = new GroupListNode;//����һ���µ�ָ��ڵ㲢����ռ�
	pNewNode->group = group;//��gmae��ֵ���Ľڵ���
	pNewNode->next = p->next;//���½ڵ��nextָ��p����һ���ڵ�
	p->next = pNewNode;//�����Ľڵ�ָ��ָ���µĽڵ�
}
//ɾ���ڵ�p
void deleteNode(GroupListNode *p) {
	p->group = p->next->group;//����һ���ڵ�����ݷ���p��
	GroupListNode *p_next = p->next;//��¼ָ��
	p->next = p->next->next;//����һ���ڵ��next����p��,
							//�൱�ڶ�ʧ�˽�p��һ���ڵ㸴�Ƶ�p��,����ʧ��p��һ���ڵ�
	free(p_next);//�ͷ������ڴ�
	p_next = NULL;
}