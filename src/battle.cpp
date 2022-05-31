#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <iterator>

string SpriteIDList[] = {"Sprites/Characters/Battle/Aidan.png",
			"Sprites/Characters/Battle/bts1.png"};

string Names[] = 	{"Aidan Orth",
			"BTS 1"};

string moveNames[] =	{"",
			"Attack1",
			"Attack2",
			"Attack3"};

bool battleMove(char moveID, Character *target){
	int damage;
	switch(moveID) {
	case 0:
		damage = 11;
		break;
	case 1:
		damage = 22;
		break;
	case 2:
		damage = 44;
		break;

	}
	if(target->Damage(damage)){
// 		cout << Names[target->ID] << " took " << damage << " damage!" << endl;
		return true;
	}
// 	cout << Names[target->ID] << " was defeated!" << endl;
	return false;
}

int selectMove(int curTurn, Character *player){
	for(int i=0;i<4;i++){
		if(mouseWithinRect(54*curTurn+8,8*i+158,54*curTurn+48,8*i+166)){
			DrawTextEx(FourBySix,moveNames[player->Moves[i]].c_str(),Vector2{(float)54*curTurn+8,(float)8*i+158},FourBySix.baseSize,1,DARKPURPLE);
		}
		else{
			DrawTextEx(FourBySix,moveNames[player->Moves[i]].c_str(),Vector2{(float)54*curTurn+8,(float)8*i+158},FourBySix.baseSize,1,WHITE);
		}

	}
	return 0;
}

int selectTarget(){
	return 0;
}

void battle(int curTurn, vector<Character*> *players, vector<Character*> *enemies) {
	int selectedMoveID = selectMove(curTurn, (*players)[curTurn]);
	int selectedSlotID;
	// Checks to see if ally has selected move.
// 	cin >> selectedSlotID;
	if (selectedSlotID>=enemies->size()){
		return;

	}
	if(battleMove(selectedMoveID, (*enemies)[selectedSlotID]))
		return;
	std::vector<Character*>::iterator it = enemies->begin();
	std::advance( it, selectedSlotID);
	enemies->erase(it);
	return;
}

void displayHealthBar(int x, int y, int HP, int MaxHP, Texture2D healthBar){
	DrawTexture(healthBar, x, y, DARKGRAY);
	BeginScissorMode(x, y, 48*((float)HP/MaxHP), 4);
	DrawTexture(healthBar, x, y, WHITE);
	EndScissorMode();
}

void LoadSprites(vector<Character*> charData){
	for(int i=0;i<charData.size();i++){

		charData[i]->Sprite = LoadTexture(SpriteIDList[charData[i]->ID].c_str());
	}
}

void UnloadSprites(vector<Character*> charData){
	for(int i=0;i<charData.size();i++){
		UnloadTexture(charData[i]->Sprite);
	}
}

void battleinit(vector<Character*> players, int location){
	Texture2D BG = LoadTexture("Sprites/Backdrops/battle.png");
	Texture2D healthBar = LoadTexture("Sprites/Backdrops/healthbar.png");
	//load encounter data based on location
	vector<Character*> enemyData;
	enemyData.push_back(new Character(15,15,1));
	enemyData.push_back(new Character(15,15,1));
	LoadSprites(enemyData);
	char hp=0;
	bool inbattle=true;

	while(inbattle==true&&(!WindowShouldClose()||IsKeyPressed(KEY_ESCAPE))){
		if(IsWindowResized()){
			screenHeight = GetScreenHeight();
			screenWidth = GetScreenWidth();
			yScale=(float)screenHeight/canvasHeight;
			xScale=(float)screenWidth/canvasWidth;
			if(xScale>yScale)
				SetMouseScale(1/yScale,1/yScale);
			else
				SetMouseScale(1/xScale,1/xScale);
		}
		BeginTextureMode(target);
		ClearBackground(BLACK);
		DrawTexture(BG,0,0,WHITE);
		for(int curTurn = 0;curTurn<players.size();curTurn++)
			battle(curTurn, &players,&enemyData);
		displayHealthBar(8,151,hp,60,healthBar);
		displayHealthBar(62,151,hp,27,healthBar);
		displayHealthBar(116,151,hp,200,healthBar);
		EndTextureMode();
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexturePro(target.texture,
			       Rectangle{ 0, 0, (float)target.texture.width, (float)-target.texture.height },
			       xScale>yScale
			       ?Rectangle{screenWidth/2-canvasWidth/2*yScale,0,canvasWidth*yScale,(float)screenHeight}
			       :Rectangle{0,screenHeight/2-canvasHeight/2*xScale,(float)screenWidth,canvasHeight*xScale},
			       Vector2{}, 0, WHITE);
		EndDrawing();
	}
	UnloadTexture(BG);
	UnloadTexture(healthBar);
	UnloadSprites(enemyData);
}
