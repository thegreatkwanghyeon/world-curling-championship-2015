#include "stdafx.h"
#include "Global.h"
#include "Director.h"
#include "TitleScene.h"


using namespace sf;
using namespace std; 


int main(){

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Director *m_pDirector = Director::getInstance();
	m_pDirector->pushScene(new TitleScene());

	view.reset(FloatRect(0, 0, constants::INTERNAL_WIDTH, constants::INTERNAL_HEIGHT));

	sf::RenderWindow window(sf::VideoMode(constants::INTERNAL_WIDTH, constants::INTERNAL_HEIGHT), "Fisheries Simulator 2015", sf::Style::Default);
	window.setFramerateLimit(60);
	while (window.isOpen()){

        	sf::Event event;

        	while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed){
				m_pDirector->freeInstance();
				m_pDirector = NULL;
				window.close();
				return 0;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			m_pDirector->freeInstance();
			m_pDirector = NULL;
			window.close();
			return 0;
		}

		window.clear();

		window.setView(view);

		m_pDirector->update();
		if (m_pDirector == NULL){
			window.close();
			return 0;
		}
		m_pDirector->draw(window);


        window.display();

	}

	return 0;

}