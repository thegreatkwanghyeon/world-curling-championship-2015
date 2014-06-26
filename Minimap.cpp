#include "stdafx.h"
#include "Minimap.h"

Minimap::Minimap():mapCoord(600.0, 0.0){
	texMap.loadFromFile("image/ui/map.png");
	texRedStone.loadFromFile("image/ui/redstone_top.png");
	texYellowStone.loadFromFile("image/ui/yellowstone_top.png");

	spMap.setTexture(texMap);
	spMap.setPosition(mapCoord);
}

Minimap::~Minimap(){
}

void Minimap::update(){
	
}

void Minimap::draw(RenderWindow &window){

	spMap.setPosition(window.mapPixelToCoords(Vector2i(600, 0)));

	for(auto &iter_stone: vecStones){

		iter_stone.spStone.setPosition(

			spMap.getPosition().x + 100.0 + iter_stone.x,
			spMap.getPosition().y + 100.0 + iter_stone.y

			);
	}

	window.draw(spMap);

	for(auto stone: vecStones){
		window.draw(stone.spStone);
	}
	
}

void Minimap::pushStone(float x, float y, int color){
	if(color == Color::red)
		vecStones.push_back(stone(x,y,texRedStone, mapCoord));
	else if(color == Color::yellow)
		vecStones.push_back(stone(x,y,texYellowStone, mapCoord));
}

void Minimap::removeStone(int idx){
	if(idx<vecStones.size()) //벡터 메모리 범위 초과 방지
		vecStones.erase(vecStones.begin() + idx);
}

void Minimap::clearStone(){
	vecStones.clear();
}