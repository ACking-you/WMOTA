//
// Created by Alone on 2021-12-24.
//

#include "Skull.h"
#include "Hero.h"
#include "Scene.h"
#include "Fight.h"
#include <conio.h>
//TODO ���������ɫ����
GET_COLOR_NUMS("��")
//TODO ����Ӵ�������ӡfight���̵���ײ����
PrintFight(TSkull, "а������", _BLUE)

TSkull *CreatSkull(int x, int y) {
    TSkull *obj = (TSkull *) malloc(sizeof(TSkull));
    const char *_color = COLOR_NUMS[rand() % _COLOR_LEN];
    InitBase(&obj->base, x, y, "а������", _color, E_SKULL, Collion_t);
    obj->hp = 150;
    obj->att = 120;
    obj->def = 90;
    obj->gold = 15;
    return obj;
}
