//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include"bits/stdc++.h"


int laba=0;//控制喇叭绑定的叉号精灵的是否可见
int wenzi=1;//文字介绍界面精灵显示顺序
///////////////////////////////////////////////////////////////////////////////////////////
//
// 主函数入口
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	// 初始化游戏引擎
	if( !dInitGameEngine( hInstance, lpCmdLine ) )
		return 0;

	// To do : 在此使用API更改窗口标题
	dSetWindowTitle("wine");
    dLoadMap("wine.t2d");
	// 引擎主循环，处理屏幕图像刷新等工作
	while( dEngineMainLoop() )
	{
		// 获取两次调用之间的时间差，传递给游戏逻辑处理
		float	fTimeDelta	=	dGetTimeDelta();

		// 执行游戏主循环
		//printf("1\n");//测试刷新频率
        dSetSpriteVisible("chahao",laba%2 );//控制叉号精灵的出现与消失
        if(wenzi<=1)
        {
            wenzi=1;
            dSetSpriteVisible("wenzi1",1);
            dSetSpriteVisible("wenzi2",0);
            dSetSpriteVisible("wenzi3",0);
            dSetSpriteVisible("wenzi4",0);
        }
        if(wenzi==2)
        {
            dSetSpriteVisible("wenzi1",0);
            dSetSpriteVisible("wenzi3",0);
            dSetSpriteVisible("wenzi2",1);
            dSetSpriteVisible("wenzi4",0);
        }
        if(wenzi==3)
        {
            dSetSpriteVisible("wenzi1",0);
            dSetSpriteVisible("wenzi2",0);
            dSetSpriteVisible("wenzi4",0);
            dSetSpriteVisible("wenzi3",1);
        }
         if(wenzi>=4)
        {
            wenzi=4;
            dSetSpriteVisible("wenzi1",0);
            dSetSpriteVisible("wenzi2",0);
            dSetSpriteVisible("wenzi3",0);
            dSetSpriteVisible("wenzi4",1);
        }

		GameMainLoop( fTimeDelta );
	};

	// 关闭游戏引擎
	dShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	if(dIsPointInSprite("kaishi",fMouseX,fMouseY))
    {
        dSetSpriteWidth("kaishi",30);
        dSetSpriteHeight("kaishi",12);
        //dPlaySound("mouse",0,1);
    }

    if(dIsPointInSprite("jieshao",fMouseX,fMouseY))
    {
        dSetSpriteWidth("jieshao",30);
        dSetSpriteHeight("jieshao",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("laba",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("laba",7);
        dSetSpriteHeight("laba",7);
    }
    if(dIsPointInSprite("laba",fMouseX,fMouseY))
    {
        dSetSpriteWidth("laba",9);
        dSetSpriteHeight("laba",9);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("kaishi",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("kaishi",25);
        dSetSpriteHeight("kaishi",10);
    }

    if(dIsPointInSprite("jieshao",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("jieshao",25);
        dSetSpriteHeight("jieshao",10);
    }
    if(dIsPointInSprite("zhongzhi",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("zhongzhi",25);
        dSetSpriteHeight("zhongzhi",10);
    }

    if(dIsPointInSprite("zhongzhi",fMouseX,fMouseY))
    {
        dSetSpriteWidth("zhongzhi",30);
        dSetSpriteHeight("zhongzhi",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("niangzao",fMouseX,fMouseY))
    {
        dSetSpriteWidth("niangzao",30);
        dSetSpriteHeight("niangzao",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("niangzao",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("niangzao",25);
        dSetSpriteHeight("niangzao",10);
    }
    if(dIsPointInSprite("gongchangtu",fMouseX,fMouseY))
    {
        dSetSpriteWidth("gongchangtu",48);
        dSetSpriteHeight("gongchangtu",36);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("gongchangtu",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("gongchangtu",40);
        dSetSpriteHeight("gongchangtu",30);
    }
    if(dIsPointInSprite("nongchangtu",fMouseX,fMouseY))
    {
        dSetSpriteWidth("nongchangtu",48);
        dSetSpriteHeight("nongchangtu",36);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("nongchangtu",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("nongchangtu",40);
        dSetSpriteHeight("nongchangtu",30);
    }
	OnMouseMove(fMouseX, fMouseY );

}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	if(iMouseType==0 && dIsPointInSprite("kaishi",fMouseX,fMouseY))
    {
        dLoadMap("guanka.t2d");
    }
	if(iMouseType==0 && dIsPointInSprite("jieshao",fMouseX,fMouseY))
    {
        dLoadMap("jieshao.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("fanhui1",fMouseX,fMouseY))
    {
        dLoadMap("wine.t2d");
        wenzi=1;
    }
    if(iMouseType==0 && dIsPointInSprite("fanhui2",fMouseX,fMouseY))
    {
        dLoadMap("wine.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("fanhui3",fMouseX,fMouseY))
    {
        dLoadMap("guanka.t2d");
    }
    /*if(iMouseType==0 && dIsPointInSprite("nongchangtu",fMouseX,fMouseY))
    {
        dLoadMap("nongchang.t2d");
    }*/
    if(iMouseType==0 && dIsPointInSprite("zhongzhi",fMouseX,fMouseY))
    {
        dLoadMap("nongchang.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("laba",fMouseX,fMouseY))
    {
        laba=laba+1;
        //此处添加控制声音播放函数
    }
    if(iMouseType==0 && dIsPointInSprite("shangye",fMouseX,fMouseY))
    {
        wenzi=wenzi-1;//文字介绍上翻页
    }
    if(iMouseType==0 && dIsPointInSprite("xiaye",fMouseX,fMouseY))
    {
        wenzi=wenzi+1;//文字介绍下翻页
    }
	OnMouseClick(iMouseType, fMouseX, fMouseY);

}
//==========================================================================
//
// 引擎捕捉鼠标弹起消息后，将调用到本函数
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
//
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
	OnMouseUp(iMouseType, fMouseX, fMouseY);

}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
//
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
	// 可以在此添加游戏需要的响应函数
	OnKeyDown(iKey, iAltPress, iShiftPress, iCtrlPress);
}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
//
void dOnKeyUp( const int iKey )
{
	// 可以在此添加游戏需要的响应函数
	OnKeyUp(iKey);
}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵发送及接受碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
//
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	// 可以在此添加游戏需要的响应函数
	OnSpriteColSprite(szSrcName, szTarName);
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// 精灵之间要产生碰撞，必须在编辑器或者代码里设置精灵的世界边界限制
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
//
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// 可以在此添加游戏需要的响应函数
	OnSpriteColWorldLimit(szName, iColSide);
}

