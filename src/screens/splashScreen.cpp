#include "splashScreen.h"

void SplashScreen::initialize()
{
    TRACE;
    this->dragonSprite = {
    // animation
    {
        // frameTimes
        { 0.2, 0.2, 0.2, 0.2, 0.2 },
        // framePos
        {   {0.0,0.0,32.0,32.0},
            {32.0,0.0,32.0,32.0},
            {64.0,0.0,32.0,32.0},
            {96.0,0.0,32.0,32.0},
            {128.0,0.0,32.0,32.0}
        },
        0,
        0.0
    },
    {100.0,100.0},
    {13.0,0.0},
    {32.0,32.0},
    LoadTexture("images/dragon_0_20240112_01.png")
    };

    SetWindowSize(640, 480);
    SetTargetFPS(60);
    InitAudioDevice();
    this->fireBreath = LoadSound("audio/Firebreath_Level_1.mp3");

}
void SplashScreen::finalize()
{
    TRACE;
    UnloadTexture(this->dragonSprite.texture);
    UnloadSound(this->fireBreath);

}
void SplashScreen::enter()
{
    TRACE;
    SetWindowTitle("START THE GAME");
}
void SplashScreen::exit()
{
    TRACE;

}
void SplashScreen::update()
{
    this->draw();
}
void SplashScreen::draw()
{
    TRACE;
    BeginDrawing();
        float delta = GetFrameTime();
        if ( IsMouseButtonReleased(MOUSE_BUTTON_LEFT)
                && CheckCollisionPointRec(GetMousePosition(),
                    {this->dragonSprite.position.x * 2, this->dragonSprite.position.y * 2,
                    this->dragonSprite.spriteSize.x * 2, this->dragonSprite.spriteSize.y * 2}) )
        {
            /// TODO this is NOT the way to do such stuff !!!
            this->isDone = true;
            PlaySound(this->fireBreath);
        }
        ClearBackground(BLACK);
            DrawRectangleLinesEx({this->dragonSprite.position.x * 2, this->dragonSprite.position.y * 2,
                    this->dragonSprite.spriteSize.x * 2, this->dragonSprite.spriteSize.y * 2}, 1.0, RED);
            DrawText("click on dragon to start level", 100,100,30,ORANGE);

        drawChar(delta, &dragonSprite);
    EndDrawing();

}
