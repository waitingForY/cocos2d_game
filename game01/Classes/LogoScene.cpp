#include "LogoNode.h"
#include "LogoScene.h"
#include "HelloWorldScene.h"

LogoScene::LogoScene(){

}

LogoScene::~LogoScene(){

}

bool LogoScene::init()
{
	if (!Layer::init())
		return false;
	
	auto layer = Layer::create();
	auto bg = Sprite::create("bg2.jpg");
	layer->setPosition(Director::getInstance()->getVisibleSize() / 2);
	layer->addChild(bg);
	addChild(layer);
	auto logo = LogoNode::create();

	layer->addChild(logo);

	//Ìí¼ÓÒ»¸ölabel
	auto next_label = Label::createWithTTF("First Scene", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	next_label->setPosition(Vec2(Director::getInstance()->getVisibleOrigin().x + Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleOrigin().y + Director::getInstance()->getVisibleSize().height - next_label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(next_label, 1);


	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->onTouchBegan = [next_label](Touch *t, Event *e){
		if (next_label->getBoundingBox().containsPoint(t->getLocation()))
		{
			auto first_scene = HelloWorld::createScene();
			auto transition = TransitionFadeTR::create(1, first_scene);
			Director::getInstance()->replaceScene(transition);
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch_listener, next_label);

	return true;
}

Scene* LogoScene::createScene(){
	auto scene = Scene::create();
	auto layer = LogoScene::create();
	scene->addChild(layer);
	return scene;
}