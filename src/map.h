#pragma once
#include "raylib.h"

#define MAP_W 22
#define MAP_H 22
#define TILE_SIZE 32

extern int g_map[MAP_H][MAP_W];

void edit_ba_mouse(void);
int marz_naghshe(int x, int y);

void save_map(const char *filename);
void load_map(const char *filename);
