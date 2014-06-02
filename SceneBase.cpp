#include "stdafx.h"
#include "SceneBase.h"

SceneBase::SceneBase(){
	printf("make SceneBase\n");
}

SceneBase::~SceneBase(){
	printf("delete SceneBase\n");
}

int SceneBase::changeScene(){
	return -1;
}