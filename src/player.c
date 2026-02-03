#include "raylib.h"
#include "player.h"
#include "map.h"
#include <math.h>

void noghte_shoroo(Player* p)
{
    p->pos   = (mokhtasat){ 1.5f, 1.5f };
    p->dir   = (mokhtasat){ 1.0f, 0.0f };
    p->plane = (mokhtasat){ 0.0f, 0.66f };
}

void charkhesh(mokhtasat* v, float zavie)
{
    float ox = v->x;
    float oy = v->y;
    v->x = ox * cosf(zavie) - oy * sinf(zavie);
    v->y = ox * sinf(zavie) + oy * cosf(zavie);
}

int divar_nist(float x, float y)
{
    int mx = (int)x;
    int my = (int)y;

    if (!marz_naghshe(mx, my)) return 0;
    return (g_map[my][mx] == 0);
}

void sliding(Player* p, float newX, float newY)
{
    float radius = 0.15f;

    if (divar_nist(newX + radius, p->pos.y) && divar_nist(newX - radius, p->pos.y)) 
        p->pos.x = newX;


    if (divar_nist(p->pos.x, newY + radius) && divar_nist(p->pos.x, newY - radius))
        p->pos.y = newY;
}

void harekat_jadid(Player* p, float dt)
{
    float base_harekat = 3.0f;
    float base_charkhesh  = 2.0f;

    float sorat_harekat = base_harekat * dt;
    float sorat_charkhesh  = base_charkhesh * dt;

    mokhtasat right = (mokhtasat){ p->dir.y, -p->dir.x };

    if (IsKeyDown(KEY_W)) 
    {
        float newX = p->pos.x + p->dir.x * sorat_harekat;
        float newY = p->pos.y + p->dir.y * sorat_harekat;
        sliding(p, newX, newY);
    }
    if (IsKeyDown(KEY_S)) 
    {
        float newX = p->pos.x - p->dir.x * sorat_harekat;
        float newY = p->pos.y - p->dir.y * sorat_harekat;
        sliding(p, newX, newY);
    }

    if (IsKeyDown(KEY_A)) 
    {
        float newX = p->pos.x + right.x * sorat_harekat;
        float newY = p->pos.y + right.y * sorat_harekat;
        sliding(p, newX, newY);
    }
    if (IsKeyDown(KEY_D)) 
    {
        float newX = p->pos.x - right.x * sorat_harekat;
        float newY = p->pos.y - right.y * sorat_harekat;
        sliding(p, newX, newY);
    }

    if (IsKeyDown(KEY_LEFT)) 
    {
        charkhesh(&p->dir, -sorat_charkhesh);
        charkhesh(&p->plane, -sorat_charkhesh);
    }
    if (IsKeyDown(KEY_RIGHT)) 
    {
        charkhesh(&p->dir, +sorat_charkhesh);
        charkhesh(&p->plane, +sorat_charkhesh);
    }
}
