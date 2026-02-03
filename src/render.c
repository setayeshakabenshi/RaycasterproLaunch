#include "render.h"
#include "map.h"
#include "raylib.h"
#include <math.h>

void naghshe_3d(const Player* p, int arz, int tool)
{

    DrawRectangle(0, 0, arz, tool / 2, (Color){ 100, 140, 255, 255 });
    DrawRectangle(0, tool / 2, arz, tool / 2, (Color){ 50, 50, 50, 255 });

    for (int x = 0; x < arz; x++)
    {
        double cameraX = 2.0 * x / (double)arz - 1.0;

        double rayDirX = (double)p->dir.x + (double)p->plane.x * cameraX;
        double rayDirY = (double)p->dir.y + (double)p->plane.y * cameraX;

        int mapX = (int)p->pos.x;
        int mapY = (int)p->pos.y;

        double fasele_x = (rayDirX == 0.0) ? 1e30 : fabs(1.0 / rayDirX);
        double fasele_y = (rayDirY == 0.0) ? 1e30 : fabs(1.0 / rayDirY);

        double side_fasele_x, side_fasele_y;
        int step_x, step_y;

        if (rayDirX < 0.0) 
        {
            step_x = -1;
            side_fasele_x = ((double)p->pos.x - mapX) * fasele_x;
        }

        else 
        {
            step_x = 1;
            side_fasele_x = (mapX + 1.0 - (double)p->pos.x) * fasele_x;
        }

        if (rayDirY < 0.0) 
        {
            step_y = -1;
            side_fasele_y = ((double)p->pos.y - mapY) * fasele_y;
        } 
        
        else 
        {
            step_y = 1;
            side_fasele_y = (mapY + 1.0 - (double)p->pos.y) * fasele_y;
        }

        int hit = 0;
        int side = 0;

        while (!hit)
        {
            if (side_fasele_x < side_fasele_y) 
            {
                side_fasele_x += fasele_x;
                mapX += step_x;
                side = 0;
            } 
            
            else 
            {
                side_fasele_y += fasele_y;
                mapY += step_y;
                side = 1;
            }

            if (!marz_naghshe(mapX, mapY)) 
            {
                hit = 1;
                break;
            }

            if (g_map[mapY][mapX] > 0) hit = 1;
        }

        double fasele_divar;
        if (side == 0)
            fasele_divar = (mapX - (double)p->pos.x + (1 - step_x) / 2.0) / rayDirX;
        else
            fasele_divar = (mapY - (double)p->pos.y + (1 - step_y) / 2.0) / rayDirY;

        if (fasele_divar <= 0.0001) fasele_divar = 0.0001;

        int ertefa_divar = (int)(tool / fasele_divar);

        int shoroo = -ertefa_divar / 2 + tool / 2;
        if (shoroo < 0) shoroo = 0;

        int payan = ertefa_divar / 2 + tool / 2;
        if (payan >= tool) payan = tool - 1;

        Color color = RED;
        if (side == 1) 
        {
            color = MAROON;
        }

        DrawLine(x, shoroo, x, payan, color);
    }
}

void mini_naghshe(const Player* p)
{
    float scale = 0.25f;
    int mini_tile = (int)(TILE_SIZE * scale);

    int mini_arz = MAP_W * mini_tile;
    int mini_tool = MAP_H * mini_tile;

    DrawRectangle(0, 529, mini_arz, mini_tool, (Color){ 0, 0, 0, 150 });

    for (int y = 0; y < MAP_H; y++) {
        for (int x = 0; x < MAP_W; x++) {
            Color c = (g_map[y][x] > 0) ? DARKGRAY : RAYWHITE;
            DrawRectangle(x * mini_tile, y * mini_tile + 529, mini_tile, mini_tile, c);
        }
    }

    int px = (int)(p->pos.x * mini_tile);
    int py = (int)(p->pos.y * mini_tile);
    DrawCircle(px, py + 529, mini_tile / 4, BLUE);

    int dx = (int)(px + p->dir.x * mini_tile * 2);
    int dy = (int)(py + p->dir.y * mini_tile * 2);
    DrawLine(px, py + 529, dx, dy + 529, BLUE);
}

void naghshe_edit(const Player* p)
{
    for (int y = 0; y < MAP_W; y++) {
        for (int x = 0; x < MAP_H; x++) {
            Color c = (g_map[y][x] > 0) ? DARKGRAY : RAYWHITE;
            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, c);
        }
    }

    int px = (int)(p->pos.x * TILE_SIZE);
    int py = (int)(p->pos.y * TILE_SIZE);
    DrawCircle(px, py, TILE_SIZE / 6, BLUE);

    int dx = (int)(px + p->dir.x * TILE_SIZE);
    int dy = (int)(py + p->dir.y * TILE_SIZE);
    DrawLine(px, py, dx, dy, BLUE);
}
