//
// Created by Alone on 2021-12-24.
//

#ifndef WMOTA_FIGHT_H
#define WMOTA_FIGHT_H

#define PrintFight(type, name, color) static void Remove_t(type * dst){\
    int find_index = 0;\
    TScene * src = GetScene();\
    int len = src->baseIndex;\
    for(int i=0;i<len;i++){\
        if(src->bases[i]==dst){\
            find_index = i;\
            break;}}\
    src->bases[find_index] = src->bases[len-1];\
    src->baseIndex--;\
    free(dst);}\
static int Collion_t(THero* hero,void * p){\
    type * tar = (type *)p;\
    int attack = hero->att-tar->def;\
    int hurt = tar->att-hero->def;\
    if(attack<=0){\
        printf("\033[%d;%dH�϶��򲻹�����Ҫ��1000��ҹ���ŭ����Ҫƴ��һ����?(����y��ʾȷ��)",2,15*2);\
        if(getch()=='y'){ hero->gold -= 1000;if(hero->gold<0){hero->gold+=1000;printf("\033[3;30H��Ҳ��㣡");Sleep(1000);system("cls");return 1;}  attack = 50; system("cls");goto flag;}\
        else  system("cls");\
        return 1;}\
    if(hurt<=0){\
        printf("\033[3;40H�����̫ǿ�����ﵥ���氤�򣬹�����������ڵ�����" );\
        hero->gold += tar->gold;\
        Remove_t(tar);\
        Sleep(1000);\
        system("cls");\
        return 1;}\
        flag: \
    printf("\033[%d;%dH=============",2,20*2);\
    printf("\033[%d;%dH=============",8,20*2);\
    printf("\033[%d;%dHս��״̬��ս����",7,20*2);\
    printf("\033[%d;%dH�������ƣ�%s%s%s",3,20*2,color,name,_END);\
    int sum_hurt = 0;\
    while(hero->hp>0&&tar->hp>0){\
        printf("\033[%d;%dH�����������%d",4,20*2,tar->def);\
        printf("\033[%d;%dH���﹥������%d",5,20*2,tar->att);\
        printf("\033[%d;%dH��������ֵ��%-3d",6,20*2,tar->hp);\
        tar->hp -= attack;\
        hero->hp -= hurt;\
        sum_hurt += hurt;\
        Sleep(500);}\
    if(hero->hp<=0){\
        printf("\033[%d;%dH����ս������Ϸ����",4,20*2);\
        Sleep(2000);\
        exit(0);}\
    printf("\033[%d;%dHս����������ʧ������%d",1,20*2,sum_hurt);\
    Sleep(1000);\
    system("cls");\
    hero->gold += tar->gold;\
    Remove_t(tar);}\

#endif //WMOTA_FIGHT_H
