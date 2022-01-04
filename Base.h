//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_BASE_H
#define WMOTA_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "color.h"

enum EBASE {
    E_EMPTY,        //��λ��
    E_WALL,            //ǽ
    E_REDSLIME = 0x00000002,     //��ɫʷ��ķ
    E_GREENSLIME = 0x00000004,   //��ɫʷ��ķ
    E_BAT = 0x00000008,            //����
    E_MASTER = 0x00000010,        //��ʦ
    E_SKULL = 0x00000020,        //������
    E_BUSINESSMAN,    //����
    E_CLEVER,        //����
    E_REDKEY,        //��ɫԿ��
    E_YELLOWKEY,    //��ɫԿ��
    E_BLUEKEY,        //��ɫԿ��
    E_YELLOWDOOR,    //��ɫ��
    E_REDDOOR,        //��ɫ��
    E_BLUEDOOR,        //��ɫ��
    E_GREENMED,    //��ɫѪƿ
    E_REDMED,        //��ɫѪƿ
    E_THIEF,        //С͵
    E_STORE,        //�̵�
    E_REDSTONE,        //��ɫ��ʯ
    E_GREENSTONE,    //��ɫ��ʯ
    E_HERO,            //Ӣ��
    E_TRANSUP,      //��¥
    E_TRANSDOWN,    //��¥
    E_MONMAP,        //�����ֲ�
    E_IRONDOOR,        //������
    E_IRONWALL,     //��ǽ��
    E_PASS,
    E_YITIANSWORD = 0x00000003,  //���콣
    E_TULONGSWORD = 0x00000006,    //������
    E_BOSSSWORD = 0x0000000c,    //�������
    E_LONGSHIELD = 0x00000003,   //�˱�����
    E_BACKSHIELD = 0x00000006,    //�ص���
    E_PENGSHIELD = 0x0000000c,    //������
};

//TODO ��ײ�ص����� return 1������ײ�������ƶ�  0û�з�����ײ�����ƶ�
typedef int (*CollionCB)(struct tagHero *, void *);//��ײ���Ļ�������ָ������


typedef struct tagBase  //����
{
    int x;
    int y;
    const char *name;
    const char *printName;
    enum EBASE type;
    CollionCB collionCB;
} TBase;


void InitBase(TBase *base, int x, int y, const char *name,
              const char *printN, enum EBASE type, CollionCB *collionCB);

#ifdef SCENE_H_

// ����ö�ٴ��� ��������
TBase* CreateBaseByType(enum EBASE type, int x, int y);

#endif

// ��ʼ������������
void InitCreateMgr();

#endif //WMOTA_BASE_H
