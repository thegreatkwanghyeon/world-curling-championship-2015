#include "stdafx.h"
#include "GameScene.h"
#include "Global.h"
#include "TitleScene.h"

#include <algorithm>

GameScene::GameScene() : lastStone(NULL), applyImpulse(true), linearDamping(0.2f), moveView(false), turn(false) {

	printf("make GameScene\n");

	redStoneTexture.loadFromFile("image/stone_red.png");
	yellowStoneTexture.loadFromFile("image/stone_yellow.png");
	redStoneTexture.setSmooth(true);
	yellowStoneTexture.setSmooth(true);

	groundTexture.loadFromFile("image/ground.png");

	groundSprite.setTexture(groundTexture);
	groundSprite.setPosition(0, -8000+600);

	b2Vec2 gravity(0.0f, 0.0f);
	world = new b2World(gravity);

	uiScene = new UIScene();

	//createStone(400, -7000);
	createStone(400, 500, turn);

	//view.setCenter(Vector2f(400, lastStone->GetPosition().y * SCALE));

}
GameScene::~GameScene(){
	delete world;
	delete uiScene;
}


void GameScene::createStone(const int &x, const int &y, const int &color)
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
	FixtureDef.restitution = 0.75f;
	Body->CreateFixture(&FixtureDef);

	if(color == 0)
	{
		Body->SetUserData(BodyData("Red"));
	}
	else
	{
		Body->SetUserData("Yellow");
	}

	lastStone = Body;
}

void GameScene::update()
{
	//화면 밖으로 나간 바디 삭제
	for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if (BodyIterator->GetType() == b2_dynamicBody)
		{
			if ((BodyIterator->GetPosition().x * SCALE < 0 || BodyIterator->GetPosition().x * SCALE > 800) || BodyIterator->GetPosition().y * SCALE < -8000)
			{
				if (lastStone == BodyIterator)
				{
					lastStone = NULL;
				}
				world->DestroyBody(BodyIterator);
			}
		}
	}

	uiScene->update();

	world->Step(1/60.f, 8, 3);


	//cout << lastStone->GetLinearVelocity().y << endl;
	
	//std::cout << "stone : " << 600-(lastStone->GetPosition().y * SCALE) << std::endl;

	if (lastStone != NULL && !moveView && view.getCenter().y - view.getSize().y / 2 >= -8000 + 600 + 27)
	{
		//view.move(0, lastStone->GetLinearVelocity().y * 0.01);//뷰 이동
		view.setCenter(Vector2f(400, (lastStone->GetPosition().y * SCALE) - 200));
	}

	if (applyImpulse)
	{

		if (Keyboard::isKeyPressed(Keyboard::Space) && lastStone != NULL){
			//std::cout << "-------------------------\nPower : " + to_string(uiScene->getPower()) + "\nDirection : " + to_string(uiScene->getDirection()) + "\n-------------------------\n" << std::endl;
			lastStone->ApplyLinearImpulse(b2Vec2(cos(uiScene->getDirection()) * uiScene->getPower() * SPEED * delta.getElapsedTime().asSeconds(), sin(uiScene->getDirection()) * uiScene->getPower() * SPEED *  delta.getElapsedTime().asSeconds()), lastStone->GetWorldCenter(), true);//한번에 충격 주는 함수
			lastStone->SetLinearDamping(linearDamping);//감속
			lastStone->SetAngularDamping(0.15f);
			//lastStone->ApplyForceToCenter(b2Vec2(cos(uiScene->getDirection()) * uiScene->getPower() * SPEED, sin(uiScene->getDirection()) * uiScene->getPower() * SPEED), true);//1초간 지속적으로 충격을 주는 함수
			//lastStone->ApplyTorque(100.f, true);//회전력
			applyImpulse = false;
		}
	}
	else
	{
		linearDamping = 0.15 - (uiScene->getSpeed() / 500);

		if (lastStone!=NULL)
			lastStone->SetLinearDamping(linearDamping);//감속
		
		if (!moveView && (lastStone == NULL || lastStone->GetLinearVelocity().y >= -0.9))
		{

			// ------------------점수 계산-------------

			std::map<float, b2Body*> stoneInfo;
			std::vector<float> distances;

			for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
			{
				if (BodyIterator->GetType() == b2_dynamicBody)
				{
					float x = BodyIterator->GetPosition().x * SCALE, y = BodyIterator->GetPosition().y * SCALE;
					float distance = sqrt((x - 400)*(x - 400) + (y + 7173 - 600)*(y + 7173 - 600));

					distances.push_back(distance);
					stoneInfo[distance] = BodyIterator;
				}
			}

			std::sort(distances.begin(), distances.end(), [](const float a, const float b)->bool{return a < b; });

			int scoreCount = 0;
			int color = -1;
			bool goNextEnd = false;

			for (std::vector<float>::iterator it = distances.begin(); it != distances.end(); it++)
			{

				if (color == -1){
					if (stoneInfo[*it]->GetUserData() == "Red")
					{
						color = Minimap::red;
						scoreCount += 1;
					}
					else
					{
						color = Minimap::yellow;
						scoreCount += 1;
					}
				}
				else
				{
					if (color == Minimap::red)
					{

						if (stoneInfo[*it]->GetUserData() != "Red")
						{
							break;
						}
						else
						{
							scoreCount += 1;
							printf("%d\n", scoreCount);
						}
					}
					else
					{

						if (stoneInfo[*it]->GetUserData() != "Yellow")
						{
							break;
						}
						else
						{
							scoreCount += 1;
							printf("%d\n", scoreCount);
						}
					}
				}


			}

			//----------------------------------------------

			uiScene->nextTurn();

				if (color == Minimap::yellow)
				{
					goNextEnd = uiScene->pushScore(0, scoreCount);
				}
				else
				{
					goNextEnd = uiScene->pushScore(scoreCount, 0);
				}

			if (goNextEnd)
			{
				cout << goNextEnd << endl;

				turn = uiScene->getCurrentTurn();
				turn = !turn;

				for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
				{
					world->DestroyBody(BodyIterator);
				}

				Director::getInstance()->replaceScene(new TitleScene());

			}

			moveView = true;
			viewMovingSpeed = abs((view.getCenter().y + 300) / 20);

		}
		
	}
	
	if (moveView)
	{
		view.move(0, viewMovingSpeed);

		if (view.getCenter().y >= 300)
		{
			turn = !turn;

			uiScene->clearStone();

		for (b2Body* BodyIterator = world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
			{
				if (BodyIterator->GetType() == b2_dynamicBody)
				{
					if(BodyIterator->GetUserData() == "Red")
					{
						
						uiScene->pushStone((BodyIterator->GetPosition().x * SCALE - 400)/3.375, (-(600-(BodyIterator->GetPosition().y * SCALE) - 7173))/3.375, Minimap::red);

					}
					else
					{
						
						uiScene->pushStone((BodyIterator->GetPosition().x * SCALE - 400)/3.375, (-(600-(BodyIterator->GetPosition().y * SCALE) - 7173))/3.375, Minimap::yellow);
							//cout << BodyIterator->GetPosition().x * SCALE - 400 << "\t" << -( 600-(BodyIterator->GetPosition().y * SCALE) - 7173) << endl;
					}
				}
			}

			createStone(400, 500, turn);
			applyImpulse = true;

			moveView = false;
		}
	}

	//cout << lastStone->GetPosition().x * SCALE - 400 << "\t" << -( 600-(lastStone->GetPosition().y * SCALE) - 7173) << endl;
	delta.restart();
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

			if(BodyIterator->GetUserData() == "Red"){
				sprite.setTexture(redStoneTexture);
			}
			else
			{
				sprite.setTexture(yellowStoneTexture);
			}

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