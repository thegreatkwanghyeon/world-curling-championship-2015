#include "stdafx.h"
#include "TeamIndicator.h"
#include "Global.h"

TeamIndicator::TeamIndicator(){
	texTeamboard.loadFromFile("image/ui/teamboard.png");
	font.loadFromFile("font/italicNumber.ttf");

	left.spTeamboard.setTexture(texTeamboard);
	left.spTeamboard.setPosition(150.0f, 7.0f);
	right.spTeamboard.setTexture(texTeamboard);
	right.spTeamboard.setPosition(left.spTeamboard.getPosition().x , left.spTeamboard.getPosition().y+left.spTeamboard.getTexture()->getSize().y);
	left.txtTeamName.setFont(font);
	left.txtTeamName.setPosition(left.spTeamboard.getPosition().x +30.0f, left.spTeamboard.getPosition().y +7.0f);
	right.txtTeamName.setFont(font);
	right.txtTeamName.setPosition(left.spTeamboard.getPosition().x +30.0f, left.spTeamboard.getPosition().y +57.0f);


}

TeamIndicator::~TeamIndicator(){
}

void TeamIndicator::update(){
}

void TeamIndicator::draw(RenderWindow &window){
	window.draw(left.spTeamboard);
	window.draw(right.spTeamboard);
	window.draw(left.txtTeamName);
	window.draw(right.txtTeamName);
}

void TeamIndicator::setLeft(String name){
	left.txtTeamName.setString(name);
	if(name == "Canada")
		globalTeamNameLeft = "CAN";
	else if(name == "Denmark")
		globalTeamNameLeft = "DEN";
	else if(name == "Japan")
		globalTeamNameLeft = "JPN";
	else if(name == "Korea")
		globalTeamNameLeft = "KOR";
	else if(name == "Russia")
		globalTeamNameLeft = "RUS";
	else if(name == "Sweden")
		globalTeamNameLeft = "SWE";
	else if(name == "Swiss")
		globalTeamNameLeft = "SWI";

}

void TeamIndicator::setRight(String name){
	right.txtTeamName.setString(name);
	if(name == "Canada")
		globalTeamNameRight = "CAN";
	else if(name == "Denmark")
		globalTeamNameRight = "DEN";
	else if(name == "Japan")
		globalTeamNameRight = "JPN";
	else if(name == "Korea")
		globalTeamNameRight = "KOR";
	else if(name == "Russia")
		globalTeamNameRight = "RUS";
	else if(name == "Sweden")
		globalTeamNameRight = "SWE";
	else if(name == "Swiss")
		globalTeamNameRight = "SWI";
}

bool TeamIndicator::isValid(){
	return ((globalTeamNameRight != globalTeamNameLeft) && (globalTeamNameLeft != "") && (globalTeamNameRight != ""));
}