#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#define LL_SCREEN_SCALE_VALUE (CCDirector::sharedDirector()->getWinSize().height/1024)
#define LL_BUTTON_SCALE_VALUE (0.6*LL_SCREEN_SCALE_VALUE)

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;


class GameLayer : public cocos2d::CCLayer
{
protected:
    bool bPaused;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

public:
    ~GameLayer();
    
    // Init method
    virtual bool init();

	// Draw method
	virtual void draw();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    

	void instructionButtonClick(CCObject *sender);
	void startButtonClick(CCObject *sender);
	void finishButtonClick(CCObject *sender);
	void cancelButtonClick(CCObject *sender);
	void leaderboardButtonClick(CCObject *sender);
	void inputButtonClick(CCObject *sender);
	
	//�û�����
	virtual bool onTextFieldAttachWithIME(CCTextFieldTTF * sender);
//    ���û��ر�������̵�ʱ��ص�����
    virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * sender);
    //    ���û��������� ������̵�ʱ��ص�����
    virtual bool onTextFieldInsertText(CCTextFieldTTF * sender, const char * text, int nLen);
    //    ���û�����ɾ������ ������̵�ʱ��ص�����
    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * sender, const char * delText, int nLen);
};

#endif // __GAMELAYER_H__

