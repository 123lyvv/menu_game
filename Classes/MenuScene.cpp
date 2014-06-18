//
//  MenuScene.cpp
//  MenuPlay
//
//  Created by loaner on 2014-06-12.
//
//

#include "MenuScene.h"
#include "GameScene.h"
#include "SettingsScene.h"
#include "HelpScene.h"

USING_NS_CC;

CCScene* MenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MenuScene *layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pHelpScene = CCMenuItemImage::create(
                                                          "btnHelp.png",
                                                          "btnHelp.png",
                                                          this,
                                                          menu_selector(MenuScene::goHelpScene));
    CCMenuItemImage *pGameScene = CCMenuItemImage::create(
                                                          "btnPlay.png",
                                                          "btnPlay.png",
                                                          this,
                                                          menu_selector(MenuScene::goGameScene));
    CCMenuItemImage *pSettingsScene = CCMenuItemImage::create(
                                                          "btnSetting.png",
                                                          "btnSetting.png",
                                                          this,
                                                          menu_selector(MenuScene::goSettingsScene));
    
    printf("origin: x: %f y:%f",origin.x, origin.y);
    printf("visiblesize: w: %f h:%f",visibleSize.width, visibleSize.height);
    
	pHelpScene->setPosition(ccp(origin.x + visibleSize.width/2 -300,
                                origin.y + pHelpScene->getContentSize().height/2 + 125));
    pGameScene->setPosition(ccp(origin.x + visibleSize.width/2 ,
                                origin.y + pGameScene->getContentSize().height/2 + 125));
    pSettingsScene->setPosition(ccp(origin.x + visibleSize.width/2 + 300,
                                origin.y + pSettingsScene->getContentSize().height/2 + 125));
    
    // create menu, it's an autorelease object
    CCMenu* pHelp = CCMenu::create(pHelpScene, NULL);
    pHelp->setPosition(CCPointZero);
    this->addChild(pHelp, 1);
    
    CCMenu* pGame = CCMenu::create(pGameScene, NULL);
    pGame->setPosition(CCPointZero);
    this->addChild(pGame, 1);
    
    CCMenu* pSettings = CCMenu::create(pSettingsScene, NULL);
    pSettings->setPosition(CCPointZero);
    this->addChild(pSettings, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
//    
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
    
    // add "MenuScene" splash screen"
    CCSprite* pSprite = CCSprite::create("bgMenu.jpg");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    return true;
}


void MenuScene::goHelpScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelpScene::scene());
}

void MenuScene::goSettingsScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(SettingsScene::scene());
}

void MenuScene::goGameScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(GameScene::scene());
}