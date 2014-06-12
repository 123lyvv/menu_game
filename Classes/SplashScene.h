//
//  SplashScene.h
//  MenuPlay
//
//  Created by loaner on 2014-06-12.
//
//

#ifndef __MenuPlay__SplashScene__
#define __MenuPlay__SplashScene__

#include <iostream>
#include "cocos2d.h"

class SplashScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    void onEnterTransitionDidFinish ();
    
    void gotoMenu(float dt);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SplashScene);
};

#endif /* defined(__MenuPlay__SplashScene__) */
