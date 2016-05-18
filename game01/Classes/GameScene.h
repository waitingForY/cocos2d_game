#ifndef _GameScene_H
#define _GameScene_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
class GameScene : public Layer
{
public:
	GameScene();
	virtual ~GameScene();
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(GameScene);
	void menuCloseCallback(cocos2d::Ref* pSender);
};

#endif //_GameScene_H