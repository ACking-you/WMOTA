//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_KEY_H
#define WMOTA_KEY_H

#include "Base.h"

/*
E_REDKEY,		//��ɫԿ��
E_YELLOWKEY,	//��ɫԿ��
E_BLUEKEY,		//��ɫԿ��
E_YELLOWDOOR,	//��ɫ��
E_REDDOOR,		//��ɫ��
E_BLUEDOOR,		//��ɫ��
*/
typedef struct Key {
    TBase base;
} Tkey;

Tkey *CreartRedKey(int x, int y);

Tkey *CreatYellowKey(int x, int y);

Tkey *CreatBlueKey(int x, int y);

#endif //WMOTA_KEY_H
