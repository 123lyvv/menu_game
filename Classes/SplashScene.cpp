//
//  SplashScene.cpp
//  MenuPlay
//
//  Created by loaner on 2014-06-12.
//
//

#include "SplashScene.h"
#include "MenuScene.h"

USING_NS_CC;

CCScene* SplashScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SplashScene *layer = SplashScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // add "SplashScene" splash screen"
    CCSprite* pSprite = CCSprite::create("splash.jpg");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void SplashScene::onEnterTransitionDidFinish() {
    this->scheduleOnce(schedule_selector(SplashScene::gotoMenu), 3);
}


void SplashScene::gotoMenu(float dt) {
    menuCloseCallback(NULL);
}


void SplashScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
    
}
