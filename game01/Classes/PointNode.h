#ifndef _PointNode_HEAD
#define _PointNode_HEAD

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class PointNode:public Node
{
public:
	DrawNode *_point;
	Vec2  _direction;
public:
	PointNode();
	virtual ~PointNode();
	virtual bool init();
	CREATE_FUNC(PointNode);
};

#endif //_PointNode_HEAD
