#include "stdafx.h"
#include "Director.h"

Director* Director::pInstance = NULL;

Director::Director(){

}

Director::~Director(){
	size_t size = sceneList.size();
	for(unsigned int i=0;i<size;i++){
		delete *(sceneList.begin());
		sceneList.erase(sceneList.begin());
	}
}

Director* Director::getInstance(){
	if (NULL == pInstance){

		pInstance = new Director();

	}

	return pInstance;
}

void Director::freeInstance(){

	if (NULL != pInstance){
		delete pInstance;
		pInstance = NULL;

	}
}

void Director::pushScene(SceneBase* scene){
	sceneList.push_back(scene);
}

void Director::popScene(){
	delete sceneList.back();
	sceneList.pop_back();
}

void Director::replaceScene(SceneBase* scene){
	delete sceneList.back();
	sceneList.push_back(scene);
}

void Director::update(){
	sceneList.back()->update();
	printf("%d\n",sceneList.size());
}

void Director::draw(sf::RenderWindow& window){
	sceneList.back()->draw(window);
}
void Director::setNewScene(){
    if(sceneList.size() <= 1)
        return;
    delete sceneList[0];
    sceneList.erase(sceneList.begin());
}