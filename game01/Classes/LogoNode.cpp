#include "LogoNode.h"


LogoNode::LogoNode() :_logo(nullptr), _cocoslog(nullptr)
{
}


LogoNode::~LogoNode()
{
}

bool LogoNode::init()
{
	if (!Node::init())
		return false;
	auto img1 = Director::getInstance()->getTextureCache()->addImage("meinv.jpg");
	auto img2 = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
	_logo = Sprite::createWithTexture(img1);
	_cocoslog = Sprite::createWithTexture(img2);

	addChild(_logo);
	addChild(_cocoslog);

	_cocoslog->setVisible(false);

	schedule([this](float f){
		_logo->setVisible(!_logo->isVisible());
		_cocoslog->setVisible(!_cocoslog->isVisible());
	}, 2, "test");

}
