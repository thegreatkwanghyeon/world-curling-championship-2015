#include "stdafx.h"
#include "GameScene.h"
#include "Global.h"

GameScene::GameScene() : lastStone(NULL), applyImpulse(true) {

	printf("make GameScene\n");

	stoneTexture.loadFromFile("image/stone.png");
	groundTexture.loadFromFile("image/ground.png");

	groundSprite.setTexture(groundTexture);
	groundSprite.setPosition(0, -8000+600);

	b2Vec2 gravity(0.0f, 0.0f);
	world = new b2World(gravity);

	uiScene = new UIScene();

	//createStone(400, -7000);
	createStone(400, 500);

	//view.setCenter(Vector2f(400, lastStone->GetPosition().y * SCALE));

}
GameScene::~GameScene(){
	delete world;
	delete uiScene;
}

void GameScene::createGround()
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(0, -8000+600);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2CircleShape Shape;
	Shape.m_radius = STONE_DIAMETER / 2;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.5f;
	FixtureDef.friction = 1000.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.restitution = 0.7f;
	Body->CreateFixture(&FixtureDef);

	lastStone = Body;
}

void GameScene::createStone(const int &x, const int &y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(x / SCALE, y / SCALE);
	BodyDef.type = b2_dynamicBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2CircleShape Shape;
	Shape.m_radius = STONE_DIAMETER / 2;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.5f;
	FixtureDef.friction = 1000.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.restitution = 0.7f;
	Body->CreateFixture(&FixtureDef);

	lastStone = Body;
}

void GameScene::update()
{

	uiScene->update();

	world->Step(1/60.f, 8, 3);
	
	std::cout << "stone" << 600-(lastStone->GetPosition().y * SCALE) << std::endl;

	if (view.getCenter().y - view.getSize().y / 2 >= -8000 + 600 + 27)
	{
		//view.move(0, lastStone->GetLinearVelocity().y * 0.01);//뷰 이동
		view.setCenter(Vector2f(400, (lastStone->GetPosition().y * SCALE) - 200));
	}

	if ( applyImpulse && Keyboard::isKeyPressed(Keyboard::Space))
	{
		std::cout << "-------------------------\nPower : " + to_string(uiScene->getPower()) + "\nDirection : " + to_string(uiScene->getDirection()) + "\n-------------------------\n" << std::endl;
		lastStone->ApplyLinearImpulse(b2Vec2(cos(uiScene->getDirection()) * uiScene->getPower() * SPEED, sin(uiScene->getDirection()) * uiScene->getPower() * SPEED), lastStone->GetWorldCenter(), true);//한번에 충격 주는 함수
		lastStone->SetLinearDamping(0.1f);//감속
	//	lastStone->SetAngularDamping(1000.0f);
		//lastStone->ApplyForceToCenter(b2Vec2(cos(uiScene->getDirection()) * uiScene->getPower() * SPEED, sin(uiScene->getDirection()) * uiScene->getPower() * SPEED), true);//1초간 지속적으로 충격을 주는 함수
		//lastStone->ApplyTorque(100.f, true);//회전력
		applyImpulse = false;
	}
	
}

void GameScene::draw(RenderWindow &window){

	window.draw(groundSprite);

	mouse = Mouse::getPosition(window);

	uiScene->draw(window);

	for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if (BodyIterator->GetType() == b2_dynamicBody)
		{
			sf::Sprite sprite;

			sprite.setTexture(stoneTexture);
			sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
			sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
			sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
			window.draw(sprite);
		}
		else
		{

		}
	}

}