#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene(){

	groundTexture.loadFromFile("image/ground.png");
	boxTexture.loadFromFile("image/box.png");

	b2Vec2 gravity(0.0f, 9.8f);
	world = new b2World(gravity);

	createGround(400.f, 500.f);

	printf("make GameScene\n");


}
GameScene::~GameScene(){

}

void GameScene::createGround(const int &x, const int &y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(x / 30.f, y / 30.f);
	BodyDef.type = b2_staticBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((800.f / 2) / SCALE, (16.f / 2) / SCALE); // Creates a box shape. Divide your desired width and height by 2.
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &Shape; // Sets the shape
	Body->CreateFixture(&FixtureDef); // Apply the fixture definition

}

void GameScene::createBox(const int &x, const int &y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(mouse.x / SCALE, mouse.y / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((32.f / 2) / SCALE, (32.f / 2) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
}

void GameScene::update()
{

	world->Step(1/60.f, 8, 3);

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		createBox(mouse.x, mouse.y);
	}

}

void GameScene::draw(RenderWindow &window){

	mouse = Mouse::getPosition(window);

	for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if (BodyIterator->GetType() == b2_dynamicBody)
		{
			sf::Sprite sprite;
			sprite.setTexture(boxTexture);
			sprite.setOrigin(16.f, 16.f);
			sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
			sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
			window.draw(sprite);
		}
		else
		{
			sf::Sprite groundSprite;
			groundSprite.setTexture(groundTexture);
			groundSprite.setOrigin(400.f, 8.f);
			groundSprite.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);
			groundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
			window.draw(groundSprite);
		}
	}

}