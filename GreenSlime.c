//
// Created by Alone on 2021-12-24.
//

#include "GreenSlime.h"
#include "Hero.h"
#include "Scene.h"
#include "Fight.h"
#include <conio.h>

PrintFight(TGreenSlime, "��ʷ��ķ", _GREEN)

TGreenSlime *CreatGreenSlime(int x, int y) {
    TGreenSlime *_pGreenSlime = malloc(sizeof(TGreenSlime));
    InitBase(&_pGreenSlime->base, x, y, "��ʷ��ķ", _GREEN"ʷ"_END, E_REDSLIME, Collion_t);
    _pGreenSlime->hp = 100;
    _pGreenSlime->att = 80;
    _pGreenSlime->def = 60;
    _pGreenSlime->gold = 5;
    return _pGreenSlime;
}
