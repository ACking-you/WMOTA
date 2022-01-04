#include "Hero.h"
#include <string.h>

static THero *g_pHero;


int HeroCollionCB(THero *hero, void *p) {
    return 1;
}


TBase *CreateHero(int x, int y) {
    // ֻ�ܱ�����һ��,���ǿ����ظ�ʹ�� 
    static THero *_pHero = NULL;

    // ������HERO���������
    if (_pHero == NULL) {
        _pHero = malloc(sizeof(THero));
        g_pHero = _pHero;
        _pHero->base.printName = "��";
        _pHero->base.x = x;
        _pHero->base.y = y;
        _pHero->hasMap = 0;
        _pHero->base.type = E_HERO;
        _pHero->hp = 350;
        _pHero->att = 84;
        _pHero->gold = 1000;
        _pHero->def = 60;
        _pHero->maxHp = 350;
        _pHero->nums = 1;
        _pHero->armornlib = _pHero->weaponlib = 0;
        _pHero->red_key = _pHero->yellow_key = _pHero->blue_key = _pHero->red_key = 0;
        _pHero->base.collionCB = HeroCollionCB;
        return &(_pHero->base);
    }
    return _pHero;
}

THero *GetHero() {
    // ����  �ж� g_pHero �Ƿ����

    return g_pHero;
}

void fill_msg(char *msg, int state) {
    if (state & E_YITIANSWORD)strcat(msg, "���콣 ");
    if (state & E_TULONGSWORD)strcat(msg, "������ ");
    if (state & E_BOSSSWORD)strcat(msg, "������� ");
    if (state & E_LONGSHIELD)strcat(msg, "�˱����� ");
    if (state & E_BACKSHIELD)strcat(msg, "�ص��� ");
    if (state & E_PENGSHIELD)strcat(msg, "������ ");
}

void PrintHeroInfo(THero *hero) {
    char msg1[100] = {0};
    char msg2[100] = {0};
    fill_msg(msg1, hero->weaponlib);
    fill_msg(msg2, hero->armornlib);
    printf(_PURPLE"\033[15;1H==========================\n"_END);
    printf("\033[16;1H| ����ֵ ==> "_RED"%-3d"_END"         \n", hero->hp);
    printf("\033[17;1H| ������ ==> "_RED"%-3d"_END"         \n", hero->att);
    printf("\033[18;1H| ������ ==> "_RED"%-3d"_END"         \n", hero->def);
    printf("\033[19;1H| ���   ==> "_RED"%-5d"_END"       \n", hero->gold);
    printf("\033[20;1H| "_YELLOW"��Կ��"_END" ==> "_YELLOW"%-2d"_END"          \n", hero->yellow_key);
    printf("\033[21;1H| "_BLUE"��Կ��"_END" ==> "_BLUE"%-2d"_END"          \n", hero->blue_key);
    printf("\033[22;1H| "_RED"��Կ��"_END" ==> "_RED"%-2d"_END"          \n", hero->red_key);
    printf("\033[23;1H| "_PURPLE"��  ��"_END" ==> "_LIGHT_BLUE"%s"_END"          \n", msg1[0] ? msg1 : "��");
    printf("\033[24;1H| "_PURPLE"��  ��"_END" ==> "_LIGHT_BLUE"%s"_END"          \n", msg2[0] ? msg2 : "��");
    printf("\033[25;1H| ��ǰ���ڹؿ���%-2d", hero->nums);
    printf("\033[26;1H| Ӣ��λ�� x:%-2d,y:%-2d", hero->base.x, hero->base.y);
    printf(_PURPLE"\033[27;1H==========================\n"_END);
}