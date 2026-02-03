#include "raylib.h"
#include "map.h"
#include "player.h"
#include "render.h"

typedef enum {
    STATE_PLAY_MODE, 
    STATE_EDIT_MODE 
} GameState;

int main(void)
{
    const int arz = MAP_W * TILE_SIZE;
    const int tool = MAP_H * TILE_SIZE;

    InitWindow(arz, tool, "Phase 1 - Raycasting");
    SetTargetFPS(60);

    Player player;
    noghte_shoroo(&player);

    GameState state = STATE_PLAY_MODE;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyPressed(KEY_M)) 
        {
            state = (state == STATE_PLAY_MODE) ? STATE_EDIT_MODE : STATE_PLAY_MODE;
        }

        if (IsKeyPressed(KEY_F5))
            save_map("map.txt");

        if (IsKeyPressed(KEY_F9))
            load_map("map.txt");

        if (state == STATE_PLAY_MODE) 
            harekat_jadid(&player, dt);
        else 
            edit_ba_mouse();

        BeginDrawing();
        ClearBackground(BLACK);

        if (state == STATE_PLAY_MODE) 
        {
            naghshe_3d(&player, arz, tool);
            mini_naghshe(&player);
            DrawText("play mode", 10, 10, 20, RAYWHITE);
        } 
        else 
        {
            naghshe_edit(&player);
            DrawText("edit mode", 10, 10, 20, RAYWHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
