#ifndef _LogoNode_HEAD
#define _LogoNode_HEAD

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class LogoNode : public Node
{
protected:
	Sprite *_logo;
	Sprite *_cocoslog;

public:
	LogoNode();
	virtual ~LogoNode();
	virtual bool init();
	CREATE_FUNC(LogoNode);
};

#endif //_LogoNode_HEAD