#ifndef _LogoScene_H
#define _LogoScene_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class LogoScene :public Layer{
public:
	LogoScene();
	virtual ~LogoScene();
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(LogoScene);
};

#endif  //_LogoScene_H