 #include "GameScene.h"
#include "PointNode.h"
#include "SimpleAudioEngine.h"
#include "LogoScene.h"
GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	////添加背景


	////在场景中构建一个logo
	auto dot = PointNode::create();
	addChild(dot);

	//添加一个label
	auto next_label = Label::createWithTTF("Next Scene", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	next_label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - next_label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(next_label, 1);

	
	auto touch_listener = EventListenerTouchOneByOne::create();
	touch_listener->onTouchBegan = [next_label](Touch *t, Event *e){
		if (next_label->getBoundingBox().containsPoint(t->getLocation()))
		{
			auto logo_scene = LogoScene::createScene();
			auto transition = TransitionFadeTR::create(1,logo_scene);
			Director::getInstance()->replaceScene(transition);
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch_listener, next_label);

	return true;
}

Scene * GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}