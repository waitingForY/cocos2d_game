#include "PointNode.h"


PointNode::PointNode()
{
	
}


PointNode::~PointNode()
{
}

bool PointNode::init()
{
	if (!Node::init())
		return false;
	auto visible_size = Director::getInstance()->getVisibleSize();
	
	_point = DrawNode::create();
	_point->drawDot(Vec2(0, 0), 5, Color4F(1.0, 1.0, 1.0, 1.0));
	addChild(_point);
	_direction.set(random(-1.0f, 1.0f), random(-1.0f, 1.0f));
	_direction.normalize();
	_point->setPosition(visible_size/ 2);
	schedule([this, visible_size](float f){
		auto pos = _point->getPosition();
		if (pos.x<0 || pos.x>visible_size.width)
			_direction.x *= -1;
		else if (pos.y<0 || pos.y>visible_size.height)
			_direction.y *= -1;
		_point->setPosition(pos + _direction * 10);
	}, "test");
	return true;
}