//
//  HelpScene.h
//  MenuPlay
//
//  Created by loaner on 2014-06-12.
//
//

#ifndef __MenuPlay__HelpScene__
#define __MenuPlay__HelpScene__

#include <iostream>
#include "cocos2d.h"

class HelpScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelpScene);
};
#endif /* defined(__MenuPlay__HelpScene__) */
