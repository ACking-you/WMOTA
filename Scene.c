//
// Created by Alone on 2021-12-23.
//

#include "Scene.h"
#include "Hero.h"

int _flag;

extern TScene *cur_scene;

int isMonster(int code);

TScene *CreateScene(int map[][N]) {
    // ��������
    TScene *scene = (TScene *) malloc(sizeof(TScene));
    scene->kind = 0;
    scene->baseIndex = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            TBase *base = CreateBaseByType(map[i][j], i + 1, j + 1);
            if (base) {
                scene->bases[scene->baseIndex++] = base;
                if (isMonster(map[i][j]))
                    scene->kind |= map[i][j];//���µ�ͼ���еĹ�������
            }
        }
    }
    return scene;
}

void PrintHelp() {
    printf("\033[2;90H===================");
    printf("\033[3;90H|  "_RED"��Ϸ����˵��"_END"   |");
    printf("\033[4;90H|W A S D"_YELLOW"��"_END"�ƶ�    |");
    printf("\033[5;90H|H ��ȡ��Ϸ����   |");
    printf("\033[6;90H|H2ȡ����Ϸ����   |");
    printf("\033[7;90H|"_LIGHT_BLUE"ì:��,��,�������"_END"|");
    printf("\033[8;90H|"_PURPLE"��:��,�ص�,����"_END"  |");
    printf("\033[9;90H|M �����ֲ�       |");
    printf("\033[10;90H|C �ؿ���Խ:%-2d��   |", GetHero()->nums);
    printf("\033[11;90H===================");
}

void PrintMonMap() {
    int row = 17;
    printf("\033[%d;40H|  ����  |%s����%s|%s����%s|%s����%s|%s���%s|", row++, _RED, _END, _GREEN, _END, _BLUE, _END, _YELLOW,
           _END);
    if (cur_scene->kind & E_REDSLIME)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "��ʷ��ķ", 100, 70, 120, 10);
    if (cur_scene->kind & E_GREENSLIME)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "��ʷ��ķ", 80, 60, 100, 5);
    if (cur_scene->kind & E_MASTER)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "������ʦ", 140, 40, 120, 10);
    if (cur_scene->kind & E_SKULL)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "а������", 120, 90, 150, 15);
    if (cur_scene->kind & E_BAT)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "��������", 200, 100, 120, 15);
}

void ClearMonMap() {
    int row = 17;
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
}

void PrintScene(TScene *scene) {
    for (int i = 0; i < scene->baseIndex; ++i) {
        TBase *base = scene->bases[i];
        printf("\033[%d;%dH%s", base->x, base->y * 2, base->printName);
    }
    PrintHeroInfo(GetHero());
    PrintHelp();
    if (GetHero()->hasMap && _flag) {
        PrintMonMap();
    }
    if (GetHero()->hasMap && !_flag) {
        ClearMonMap();
    }
    printf(_RED"\033[15;50H��Ӯ�ˣ���Ұ����꣡����g�ɽ������ҳ��"_END);
}

// -1 0 1
void UpdateScene(TScene *scene, int dirX, int dirY) {
    scene->kind = 0;
    THero *pHero = GetHero();
    int x = pHero->base.x + dirX;
    int y = pHero->base.y + dirY;

    int bFlag = 1;
    for (int i = 0; i < scene->baseIndex; ++i) {
        TBase *base = scene->bases[i];
        if (isMonster(base->type))
            scene->kind |= base->type;//���µ�ǰ������ӵ�еĹ�������
        if (base->x == x && base->y == y && base->collionCB(pHero, base)) // ��ѯ��һ��λ���Ƿ��������
        {
            bFlag = 0;//��ֱ����������Ϊ����Ҫ���µ�ǰ��ͼӵ�е�����
        }
    }
    // TODO  �ж� �Ƿ������ƶ�
    if (bFlag) {
        printf("\033[%d;%dH  ", pHero->base.x, pHero->base.y * 2);
        pHero->base.x += dirX;
        pHero->base.y += dirY;

    }
}


TScene *GetScene() {
    return cur_scene;
}
