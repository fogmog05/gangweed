#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "raylib.h"

using namespace std;



class Character {
	public:
		int HP,MaxHP,Mana,ID;
		int Moves[4] = {0,1,2,3};
		Texture2D Sprite;
		Character(int a, int b, int c){
			HP = a;
			MaxHP = b;
			ID = c;
			Mana = 0;
		}
		bool Damage(int damage){//returns whether the character is alive
			HP -= damage;
			if(HP>0)
				return true;
			return false;
		}
		bool Heal(int healAmount){
			if(HP>0){
				return false;
			}
			HP += healAmount;
			return true;
		}
		bool HasMove(int move){
			return(std::find(std::begin(Moves), std::end(Moves), move) != std::end(Moves));
		}
};
Font FourBySix;
RenderTexture2D target;
const int canvasWidth = 256;
const int canvasHeight = 192;
int screenWidth = 512;
int screenHeight = 384;
float xScale = 2;
float yScale = 2;

enum gameState{
	GS_BATTLE = 0,
	GS_OVRWORLD,
	GS_TITLE
};

bool mouseWithinRect(int lowx, int lowy, int highx, int highy){
	int mouseX = GetMouseX();
	int mouseY = GetMouseY();
	if(xScale>yScale){
		mouseX -= (screenWidth/yScale/2-canvasWidth/2);
	}else
		mouseY -= (screenHeight/xScale/2-canvasHeight/2);
	if(mouseX<lowx||mouseX>=highx||mouseY<lowy||mouseY>=highy)
		return false;
	return true;
}

#include "battle.cpp"
int main(){

	InitWindow(screenWidth, screenHeight, "Battle Screen Mockup");
	SetMouseScale(1/xScale, 1/yScale);
	target = LoadRenderTexture(canvasWidth, canvasHeight);
	FourBySix = LoadFont("Sprites/font.png");
	ClearBackground(BLACK);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(60);

	vector<Character*> characters;
	characters.push_back(new Character(19,31,0));
	characters.push_back(new Character(32,34,1));
	int state = GS_BATTLE;

	battleinit(characters,5);
// 	while (!WindowShouldClose()||IsKeyPressed(KEY_ESCAPE))    // Detect window close button or ESC key
// 	{
// 		if(IsWindowResized()){
// 			screenHeight = GetScreenHeight();
// 			screenWidth = GetScreenWidth();
// 			yScale=(float)screenHeight/canvasHeight;
// 			xScale=(float)screenWidth/canvasWidth;
// 			SetMouseScale(xScale, yScale);
// 		}
//
// 		BeginDrawing();
//
// 		ClearBackground(RAYWHITE);
// 		EndDrawing();
// 	}
	UnloadRenderTexture(target);
	CloseWindow();
	return 0;
}
