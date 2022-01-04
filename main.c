#include "Base.h"

#define MAIN

#include "Scene.h"
#include <conio.h>
#include "print_qrcode.h"

TScene *cur_scene;
extern int _flag;
//TODO ���ڳ�ʼ���ĵ�ͼ����
int map1[N][N] = {
        {1, 1,           1,             1,            1,            1,            1,            1,            1,           1,            1,            1,            1},
        {1, E_TRANSUP,   0,             E_GREENSLIME, E_REDSLIME,   E_GREENSLIME, 0,            0,            0,           0,            0,            0,            1},
        {1, 1,           1,             1,            1,            1,            1,            1,            1,           1,            1,            0,            1},
        {1, E_REDMED,    0,             0,            E_YELLOWDOOR, 0,            1,            E_REDSTONE,   E_YELLOWKEY, 0,            1,            0,            1},
        {1, 0,           E_SKULL,       0,            1,            0,            1,            E_GREENSTONE, E_REDMED,    0,            1,            0,            1},
        {1, 1,           E_YELLOWDOOR,  1,            1,            0,            1,            1,            1,           E_YELLOWDOOR, 1,            0,            1},
        {1, E_YELLOWKEY, 0,             0,            1,            E_MONMAP,     E_YELLOWDOOR, E_BAT,        E_MASTER,    E_BAT,        1,            0,            1},
        {1, 0,           E_SKULL,       0,            1,            0,            1,            1,            1,           1,            1,            0,            1},
        {1, 1,           E_YELLOWDOOR,  1,            1,            0,            0,            0,            0,           0,            0,            0,            1},
        {1, 0,           0,             0,            1,            1,            E_YELLOWDOOR, 1,            1,           1,            E_YELLOWDOOR, 1,            1},
        {1, E_REDMED,    0,             E_YELLOWKEY,  1,            E_YELLOWKEY,  0,            0,            1,           0,            E_BAT,        0,            1},
        {1, E_REDMED,    E_YITIANSWORD, E_YELLOWKEY,  1,            0,            E_BLUEKEY,    E_HERO,       1,           E_GREENSLIME, E_GREENMED,   E_GREENSLIME, 1},
        {1, 1,           1,             1,            1,            1,            1,            1,            1,           1,            1,            1,            1},
};
//��ʱֻ��������ŵ�ͼ
int maps[5][N][N] = {
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, E_TRANSDOWN, 0,            E_BLUEDOOR, 0,           0,          0,           0, 0, 0, 0, 0,        1},
                {1, 0, 0,        1, 1,          0,           0,          0, 0, 0,            1,         1, 1},
                {1, 0,        1, 1, 1,           1,         1,           1, 0, 1, 1, 1, 1},
                {1, 0,            1, E_YELLOWKEY, E_YELLOWKEY, 1, 0, 0, 0, 1, 0, E_REDMED, 1},
                {1, 0, 1, E_YELLOWKEY, 0,     E_YELLOWDOOR, 0, 0, 0, E_YELLOWDOOR, 0, 0, 1},
                {1, 0,            1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                {1, 0,       1, E_THIEF, 0, 1, 0, 0, 0, 1, 0, E_STORE,  1},
                {1, 0,          1,           0, 0, E_YELLOWDOOR, 0, 0, 0, E_YELLOWDOOR, 0,        0,           1},
                {1, 0,        1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                {1, 0, 1, E_GREENMED, E_GREENMED, 1, 0, 0, 0, 1, 0, E_TULONGSWORD, 1},
                {1, E_TRANSUP,   1, E_GREENMED, 0, E_YELLOWDOOR, 0,      E_HERO, 0, E_YELLOWDOOR, 0, 0,         1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, E_YELLOWKEY, E_GREENSTONE, 1,          E_YELLOWKEY, E_GREENMED, E_YELLOWKEY, 1, 0, 1, 0, E_REDMED, 1},
                {1, 0, E_REDMED, 1, E_GREENMED, E_YELLOWKEY, E_GREENMED, 1, 0, E_YELLOWDOOR, E_BLUEKEY, 0, 1},
                {1, E_MASTER, 0, 1, E_YELLOWKEY, E_BLUEKEY, E_YELLOWKEY, 1, 0, 1, 1, 1, 1},
                {1, E_YELLOWDOOR, 1, 1,           1,           0, 1, 1, 0, 1, 0, 0,        1},
                {1, 0, 0, 0,           E_BAT, E_HERO,       0, 0, 0, 0,            0, 0, 1},
                {1, E_YELLOWDOOR, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                {1, E_SKULL, 0, 1,       1, 0, 1, 1, 0, 1, 0, E_REDMED, 1},
                {1, E_REDSTONE, E_YELLOWKEY, 1, 0, 0,            0, 1, 0, E_YELLOWDOOR, E_MASTER, E_YELLOWKEY, 1},
                {1, E_REDMED, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                {1, 0, 1, 1,          1,          0, 1, 1, 0, 1, 0, 0,             1},
                {1, E_TRANSDOWN, 1, 0,          0, 0,            E_HERO, 1,      0, E_YELLOWDOOR, 0, E_TRANSUP, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}
};

//TODO ���ú궨�崫������õ���Ӧ�Ĵ���
QR_CODE("./qrcode.txt")

int isMonster(int code) {
    if (code == E_GREENSLIME || code == E_REDSLIME || code == E_BAT ||
        code == E_MASTER || code == E_SKULL)
        return 1;
    return 0;
}

//TODO ���ҵĹ���ɾ������
void BUG_SOLVE() {
    TScene *t = GetScene();
    for (int i = 0; i < t->baseIndex; i++) {
        TBase *tt = t->bases[i];
        if (isMonster(tt->type)) {
            t->bases[i] = t->bases[t->baseIndex - 1];
            t->baseIndex--;
            free(tt);
        }
    }
}

//TODO �����߼��Ľ�����ӡ
void BUG_PRINT() {
    char x;
    printf(_RED"\033[16;50Hȷ�������������½���ɨ���ά���ֵ��(��q����)"_END);
    x = getch();
    if (x == 'q')
        goto end;
    print_qrcode();
    while (x != 'q') {
        x = getch();
    }
    system("cls");
    printf(_RED"֧���ɹ�����Ļ����С�ֽ���ʧ��"_END);
    BUG_SOLVE();
    end:
    system("cls");
    return;
}

//TODO �Ѷ����ͼ�ȴ�����������
void init_sene(TScene *scen) {
    TScene *node = scen;
    for (int i = 0; i < 2; i++) {
        node->next = CreateScene(maps[i]);
        node->next->pre = node;
        node = node->next;
    }
}

int main() {
    system("cls");
    InitCreateMgr();
    printf("\033[?25l");
    cur_scene = CreateScene(map1);
    init_sene(cur_scene);
    PrintScene(cur_scene);
    char c = 0;
    while (c != 'q') {
        c = _getch();
        int x, y;
        x = y = 0;
        switch (c) {
            case 'w':
            case 'W':
                x = -1;
                break;
            case 's':
            case 'S':
                x = 1;
                break;
            case 'a':
            case 'A':
                y = -1;
                break;
            case 'd':
            case 'D':
                y = 1;
                break;
            case 'g':
            case 'G':
                BUG_PRINT();
            case 'm':
            case 'M':
                _flag = !_flag;
        }
        UpdateScene(cur_scene, x, y);
        PrintScene(cur_scene);
    }
    return 0;
}
