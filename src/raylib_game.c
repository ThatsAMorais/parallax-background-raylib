#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib - parallax background demo");

    // Load background images from the resources directory
    Texture2D bgFar = LoadTexture("src/resources/background_far.png");   
    Texture2D bgMid = LoadTexture("src/resources/background_mid.png");   
    Texture2D bgNear = LoadTexture("src/resources/background_near.png"); 

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 0.1f;
        scrollingMid -= 0.25f;
        scrollingFore -= 1.0f;

        if (scrollingBack <= -bgFar.width) scrollingBack = 0;
        if (scrollingMid <= -bgMid.width) scrollingMid = 0;
        if (scrollingFore <= -bgNear.width) scrollingFore = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw the background layers
        DrawTextureEx(bgFar, (Vector2){ scrollingBack, 0 }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(bgFar, (Vector2){ bgFar.width + scrollingBack, 0 }, 0.0f, 1.0f, WHITE);

        DrawTextureEx(bgMid, (Vector2){ scrollingMid, 0 }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(bgMid, (Vector2){ bgMid.width + scrollingMid, 0 }, 0.0f, 1.0f, WHITE);

        DrawTextureEx(bgNear, (Vector2){ scrollingFore, 0 }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(bgNear, (Vector2){ bgNear.width + scrollingFore, 0 }, 0.0f, 1.0f, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(bgFar);
    UnloadTexture(bgMid);
    UnloadTexture(bgNear);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
