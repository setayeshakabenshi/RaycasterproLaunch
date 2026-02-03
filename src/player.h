#pragma once

typedef struct mokhtasat {
    float x, y;
} mokhtasat;

typedef struct Player {
    mokhtasat pos;
    mokhtasat dir;
    mokhtasat plane;
} Player;

void noghte_shoroo(Player* p);
void harekat_jadid(Player* p, float dt);
