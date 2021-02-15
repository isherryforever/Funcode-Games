//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include<math.h>
#include<stdio.h>
#include<string.h>
#include"bits/stdc++.h"
using namespace std;

#define  PI 3.1415926

int choose = 0;
int choosesi = 0;
extern int g_iGameState;
//第一关
float nv=-60;
int flag2[7] ={0};
int a=0;int flag=2;//2 开始，0 或1 未来给加速度， 3通过本关游戏，4 失败

float fPosX1;
float fPosY1;
float fPosX2;
float fPosY2;
float fTimeDelta;//删除While中对该变量的定义，将其定义为全局变量
float Time=0;
float b[10];
float x;
float y;
float TIME=0;
float X;
float Y;

//第二关
float tiaoposx, tiaoposy;
int g_iCount=0;
float wintime = 20;
float g_speed[2]={-17.5,-18.4};

char *type[2]={"shuzhi_bigmuban","shuzhi_smallmuban"};
float g_Basetime[2]={dRandomRange(4.0,7.0) , dRandomRange(3.0,5.0)};
float g_CurrentTime[2]={dRandomRange(4.0,7.0) , dRandomRange(3.0,5.0)};

int iftiao=1;
int ifqingxie=1;
int flagA=0;
int flagD=0;
int flag3=0;
int ifsi=0;

float g_fManRotation = 0.f;
float g_fManStartPosX; //存储人的初始X位置
float g_fManStartPosY; //存储人的初始Y位置
float fRotateSpeed;//

//第三关
int ifkey=0;
int ifkeyagain=1;
int iftiao2=1;
int flagsi=1;
int flagzuo=0;
int flagyou=0;
int flagpingtai1=0;
int flagpingtai2=0;
int flagpingtai3=0;


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
        dSetWindowTitle("Lesson");
    float screenright=dGetScreenRight();
    float screentop=dGetScreenTop();
    float screenbottom=dGetScreenBottom();
    float screenleft=dGetScreenLeft();//获取屏幕边界值

    dLoadMap("kaishijiemian.t2d");
    dPlaySound("fengmian",1,1);
//第一关
    if(choose == 1)
    {
        dLoadMap("guanka1.t2d");
        dPlaySound("guanka1",1,1);
      dSetSpriteWorldLimitMode("flyman", WORLD_LIMIT_NULL);
      dSetWindowTitle("FLYMAN");
        dSetTextString("space","Please click the space to enter the game.");
        dSetSpriteVisible("CE",0);
        dSetSpriteVisible("LONG",1 );
        X=dGetScreenLeft();
        Y=dGetScreenRight();
    }

//第二关
    if(choose==2)
    {
        dLoadMap("guanka2.t2d");
        dPlaySound("guanka2",1,1);

        fRotateSpeed=1.f*dGetSpriteRotation("man");//人摆动速度：偏离角度*一个数，单位：度/秒

        dSetSpriteEnable("man_dunxia",0);
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("padi",0);//第二关初始禁用情况

        tiaoposx=dGetSpritePositionX("man_tiaoyue");
        tiaoposy=dGetSpritePositionY("man_tiaoyue");//获取人物坐
    }


//第三关
    if(choose==3)
    {
        dPlaySound("guanka3",1,1);
        dLoadMap("guanka3.t2d");
        ifkey=0;

        dSetSpriteVisible("man3",0);
        dSetSpriteEnable("baoxiang_open",0);

        dSetSpriteEnable("qipao",0);
         dSetSpriteVisible("tishi",0);
         float screenbottom=dGetScreenBottom();

         dSetSpritePositionY("huo0",screenbottom-20);
        dSetSpritePositionY("huo1",screenbottom-20);
        dSetSpritePositionY("huo2",screenbottom-20);
        dSetSpritePositionY("huo3",screenbottom-20);

        dSetSpritePositionY("tianhuo1",screentop);
        dSetSpritePositionY("tianhuo2",screentop);
        dSetSpritePositionY("tianhuo3",screentop);
        dSetSpritePositionY("tianhuo4",screentop+55);
    }


	// 引擎主循环，处理屏幕图像刷新等工作
	while( dEngineMainLoop() )
	{
		// 获取两次调用之间的时间差，传递给游戏逻辑处理
        fTimeDelta	=	dGetTimeDelta();

    //第一关内容
    if(choose==1)
    {
            fPosX1=dGetSpriteLinkPointPosX("flyman",1);
	       fPosY1=dGetSpriteLinkPointPosY("flyman",1);
	       fPosX2=dGetSpriteLinkPointPosX("flyman",2);
	       fPosY2=dGetSpriteLinkPointPosY("flyman",2);
           dPlayEffect("jet",2*fTimeDelta/3,fPosX1,fPosY1,0);
           x=dGetSpritePositionX("flyman");
           y=dGetSpritePositionY("flyman");
           dSetSpritePosition("CE",x,y);
           if(flag==1)
              nv-=3*fTimeDelta;
           else if(flag==0)
              nv+=fTimeDelta*2;
         dSetTextString("SPEED",dMakeSpriteName("Speed-Y:",-nv));
        if (flag==1||flag==0)
             {
               TIME+=fTimeDelta;
             }
        if(-nv<=20||-nv>=80)
             {
                 dSetSpriteColorRed("SPEED",255);
                 dSetSpriteColorGreen("SPEED",0);
                 dSetSpriteColorBlue("SPEED",0);
             }
        if(-nv>20&&-nv<80)
             {
                 dSetSpriteColorRed("SPEED",240);
                 dSetSpriteColorGreen("SPEED",240);
                 dSetSpriteColorBlue("SPEED",240);
             }
         if(TIME>=20)
         {
             dSetSpriteColorRed("TIME",221);
             dSetSpriteColorGreen("TIME",214);
             dSetSpriteColorBlue("TIME",0);
             dSetSpriteLinearVelocity("flyman",0,0);
             flag=3;
             for(int i=1;i<7;i++)
               dSetSpriteLinearVelocity(dMakeSpriteName("guai",i),0,0);
            dLoadMap("story2.t2d");
            dCursorOn();

         }
         if(TIME<50)
         {
            dSetSpriteColorRed("TIME",240);
            dSetSpriteColorGreen("TIME",240);
            dSetSpriteColorBlue("TIME",240);
         }

         for(int i=1;i<7;i++)
         {
             b[i]=dGetSpritePositionY(dMakeSpriteName("guai",i));
         }
         for(int i=1;i<7;i++)
         {
             if(dGetSpritePositionX(dMakeSpriteName("guai",i))>=50&&(flag2[i]==1))
                {
                    dSetSpritePosition(dMakeSpriteName("guai",i),50+i*15+dRandomRange(0,40),b[i]);
                    dSetSpriteVisible(dMakeSpriteName("guai",i),1);
                    flag2[i]=2;//避免重复安排，精灵消失在屏幕中

                }
             if(dGetSpritePositionX(dMakeSpriteName("guai",i))<=-50)
                {
                    dSetSpritePosition(dMakeSpriteName("guai",i),50+i*15+dRandomRange(0,30),b[i]);
                    dSetSpriteVisible(dMakeSpriteName("guai",i),1);
                    flag2[i]=2;

                }
         }
         if(-nv<=0||-nv>=100)
         {
             dSetSpriteVisible("space",1);
             dSetTextString("space","Please click the M to enter the game again.");
             dSetSpriteLinearVelocity("flyman",0,0);
             flag=4;
             Time=0;
             for(int i=1;i<7;i++)
               dSetSpriteLinearVelocity(dMakeSpriteName("guai",i),0,0);
         }
         dSetTextString("TIME",dMakeSpriteName("Score:",TIME));
         if(flag==4&&Time<=3)
         {
            if(Time<3)
               {

                    Time+=0.01;
               }
             if(Time>3)
                {
                     Time=4;
                }
         }
    }


    //第二关内容
        if(choose==2)
        {
            if(g_iGameState == 2)
            {
                wintime = wintime - fTimeDelta;
                dSetTextValue("TimeText",(int)wintime);

            dSetSpriteWorldLimit("man",WORLD_LIMIT_NULL,dGetScreenLeft(),dGetScreenTop(),dGetScreenRight(),dGetScreenBottom());
            dSetSpriteConstantForce("man_tiaoyue",0,130,1);
            float fPosX,fPosY;

            fPosY=dGetSpritePositionY("man")+3;
            //障碍物生成
            char *szName;
            fPosX = screenright + 10;
                for(int i=0; i<2; i++)
                {
                    g_CurrentTime[i] -= fTimeDelta;
                    if(g_CurrentTime[i]<=0)
                    {
                        g_CurrentTime[i] = g_Basetime[i];

                        if(i==0)
                        {
                            szName=dMakeSpriteName("shuzhi_big",g_iCount++);
                        }
                        else if(i==1)
                        {
                            szName=dMakeSpriteName("shuzhi_small",g_iCount++);
                        }
                            dCloneSprite(type[i],szName);

                            float num=dRandomRange(0,2);
                            if(num>0.8)
                                dSetSpritePosition(szName,fPosX,fPosY);
                            else if(num<=0.8)
                                dSetSpritePosition(szName,fPosX,fPosY-7);

                            dSetSpriteLinearVelocityX(szName,g_speed[i]);
                    }
                }

                if(ifqingxie==1)//控制人物倾斜
                {
                    float fThisRotate = fRotateSpeed * fTimeDelta;

                        g_fManRotation+=fThisRotate;
                        fRotateSpeed=0.1f*g_fManRotation+4;
                        if(flagD==1)
                        {
                            float fkeyRotate = 30.f * fTimeDelta;//给D键设置一个速度常量
                            g_fManRotation+=fkeyRotate;
                        }
                        if(flagA==1)
                        {
                            float fkeyRotate = -30.f * fTimeDelta;//给A键设置一个速度常量
                            g_fManRotation+=fkeyRotate;
                        }

                        if(g_fManRotation >= 110.f || g_fManRotation <= -110.f)//判定因倾斜产生的失败条件
                        {
                            dSpriteMoveTo("ball",1000,20,50,1);
                            dDeleteSprite(szName);
                            if(dGetSpritePositionX("ball")>=30)
                            {
                                dSpriteMoveTo("man",25,30,30,1);
                                flag3=1;
                            }
                                if(flag3==1)
                                {
                                    dSetSpriteVisible("man",0);
                                    dSetSpriteEnable("padi",1);
                                    dDeleteSprite(szName);
                                }
                            if(dGetSpritePositionX("ball")>=50)
                            {
                                ifsi=1;//跳转到失败界面
                            }
                        }
                        dSetSpriteRotation("man",g_fManRotation);

                }

            }
            if(wintime<=0)
            {
                dLoadMap("story3.t2d");
            }
            if(ifsi==1)
            {
                choosesi=2;
                dLoadMap("siwang2.t2d");
                ifsi=0;
                wintime=30;
                g_fManRotation = 0.f;
                g_iGameState=0;
            }
        }
 //第三关内容
        if(choose==3)
        {
        dSetSpriteConstantForce("man3",0,100,1);
        float posxman=dGetSpritePositionX("man3");
        float posyman=dGetSpritePositionY("man3");

        //控制蘑菇，地刺
        if(dGetSpritePositionX("mogu1")>dGetSpritePositionX("beijing")-213&&dGetSpritePositionX("mogu1")<dGetSpritePositionX("beijing")-168)
        {
            if(dGetSpriteFlipX("mogu1")==0)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu1",0);
                }
            }
            if(dGetSpriteFlipX("mogu1")==1)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu1",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",0);
                }
            }
        }
        if(dGetSpritePositionX("mogu1")<=dGetSpritePositionX("beijing")-213)
            {

                    dSetSpriteLinearVelocityX("mogu1",20);
                    dSetSpriteFlipX("mogu1",0);
                    if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu1",0);
                }
            }
        if(dGetSpritePositionX("mogu1")>=dGetSpritePositionX("beijing")-168)
            {
                dSetSpriteLinearVelocityX("mogu1",-20);
                dSetSpriteFlipX("mogu1",1);
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu1",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu1",0);
                }
            }

            //mogu2
            if(dGetSpritePositionX("mogu2")>dGetSpritePositionX("beijing")-145&&dGetSpritePositionX("mogu2")<dGetSpritePositionX("beijing")-125)
        {
            if(dGetSpriteFlipX("mogu2")==0)
            {
                if(flagzuo==0&&flagyou==0)ifsi=1;
                {
                    dSetSpriteLinearVelocityX("mogu2",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu2",0);
                }
            }
            if(dGetSpriteFlipX("mogu2")==1)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu2",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",0);
                }
            }ifsi=1;
        }
        if(dGetSpritePositionX("mogu2")<=dGetSpritePositionX("beijing")-145)
            {

                    dSetSpriteLinearVelocityX("mogu2",20);
                    if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu2",0);
                }
                    dSetSpriteFlipX("mogu2",0);
            }
        if(dGetSpritePositionX("mogu2")>=dGetSpritePositionX("beijing")-125)
            {
                dSetSpriteLinearVelocityX("mogu2",-20);
                dSetSpriteFlipX("mogu2",1);
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu2",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu2",0);
                }
            }


            //mogu3
            if(dGetSpritePositionX("mogu3")>dGetSpritePositionX("beijing")-75&&dGetSpritePositionX("mogu3")<dGetSpritePositionX("beijing")-45)
        {
            if(dGetSpriteFlipX("mogu3")==0)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu3",0);
                }
            }
            if(dGetSpriteFlipX("mogu3")==1)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu3",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",0);
                }
            }
        }
        if(dGetSpritePositionX("mogu3")<=dGetSpritePositionX("beijing")-75)
            {

                    dSetSpriteLinearVelocityX("mogu3",20);
                    dSetSpriteFlipX("mogu3",0);
                    if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",20);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",40);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu3",0);
                }
            }
        if(dGetSpritePositionX("mogu3")>=dGetSpritePositionX("beijing")-45)
            {
                dSetSpriteLinearVelocityX("mogu3",-20);
                dSetSpriteFlipX("mogu3",1);
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",-20);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("mogu3",-40);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("mogu3",0);
                }
            }

            //pingtai1
        if(dGetSpritePositionX("pingtai1")>dGetSpritePositionX("beijing")-175&&dGetSpritePositionX("pingtai1")<dGetSpritePositionX("beijing")-161)
        {
                if(flagpingtai1==0)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",10);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",30);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-10);
                }
            }
            if(flagpingtai1==1)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-10);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-30);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",10);
                }
            }
        }
        if(dGetSpritePositionX("pingtai1")<=dGetSpritePositionX("beijing")-175)
            {

                    dSetSpriteLinearVelocityX("pingtai1",10);
                    flagpingtai1=0;
                    if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",10);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",30);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-10);
                }
            }
        if(dGetSpritePositionX("pingtai1")>=dGetSpritePositionX("beijing")-161)
            {
                dSetSpriteLinearVelocityX("pingtai1",-10);
                flagpingtai1=1;
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-10);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai1",-30);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai1",10);
                }
            }

        //pingtai3
        if(dGetSpritePositionX("pingtai3")>dGetSpritePositionX("beijing")+180&&dGetSpritePositionX("pingtai3")<dGetSpritePositionX("beijing")+210)
        {
                if(flagpingtai3==0)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",10);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",30);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-10);
                }
            }
            if(flagpingtai3==1)
            {
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-10);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-30);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",10);
                }
            }
        }
        if(dGetSpritePositionX("pingtai3")<=dGetSpritePositionX("beijing")+180)
            {

                    dSetSpriteLinearVelocityX("pingtai3",10);
                    flagpingtai3=0;
                    if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",10);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",30);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-10);
                }
            }
        if(dGetSpritePositionX("pingtai3")>=dGetSpritePositionX("beijing")+210)
            {
                dSetSpriteLinearVelocityX("pingtai3",-10);
                flagpingtai3=1;
                if(flagzuo==0&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-10);
                }
                if(flagzuo==0&&flagyou==1)
                {
                    dSetSpriteLinearVelocityX("pingtai3",-30);
                }
                if(flagzuo==1&&flagyou==0)
                {
                    dSetSpriteLinearVelocityX("pingtai3",10);
                }
            }


        //地面火焰
        if(dGetSpritePositionY("huo1")<=(screenbottom-20))
        {
            dSetSpriteLinearVelocityY("huo0",10);
          dSetSpriteLinearVelocityY("huo1",10);
          dSetSpriteLinearVelocityY("huo2",10);
          dSetSpriteLinearVelocityY("huo3",10);
          dSetSpriteFlipY("huo1",1);
        }
        if(dGetSpritePositionY("huo1")>=(screenbottom))
        {
            dSetSpriteLinearVelocityY("huo0",-10);
          dSetSpriteLinearVelocityY("huo1",-10);
          dSetSpriteLinearVelocityY("huo2",-10);
          dSetSpriteLinearVelocityY("huo3",-10);
        }


        //空中火焰

        if(dGetSpritePositionY("tianhuo1")<=screentop)
        {
          dSetSpriteLinearVelocityY("tianhuo1",10);
        }
        if(dGetSpritePositionY("tianhuo1")>=(screentop+30))
        {
          dSetSpriteLinearVelocityY("tianhuo1",-10);
        }
        if(dGetSpritePositionY("tianhuo2")<=screentop)
        {
          dSetSpriteLinearVelocityY("tianhuo2",17);
        }
        if(dGetSpritePositionY("tianhuo2")>=(screentop+40))
        {
          dSetSpriteLinearVelocityY("tianhuo2",-17);
        }
        if(dGetSpritePositionY("tianhuo3")<=screentop)
        {
          dSetSpriteLinearVelocityY("tianhuo3",23);
        }
        if(dGetSpritePositionY("tianhuo3")>=(screentop+50))
        {
          dSetSpriteLinearVelocityY("tianhuo3",-23);
        }
         if(dGetSpritePositionY("tianhuo4")>=(screentop+55))
        {
          dSetSpriteLinearVelocityY("tianhuo4",-20);
        }
        if(dGetSpritePositionY("tianhuo4")<=screentop+20)
        {
          dSetSpriteLinearVelocityY("tianhuo4",20);
        }


        //统一调度死亡
        if(dGetSpritePositionY("man3")>=screenbottom)
        {
                dLoadMap("siwang3.t2d");
                choosesi = 3;
                ifkeyagain=1;
        }
        if(flagsi==0)
        {
           // dSetSpriteImpulseForce("man3",0,-220,1);
            //dSetSpriteCollisionSend("man3",0);
            //dSetSpriteCollisionReceive("man3",0);
            flagsi=1;
        }

            if(dIsPointInSprite("board",posxman,posyman)==1)
            {
                dSetSpriteEnable("qipao",1);
            }
            if(dIsPointInSprite("board",posxman,posyman)!=1)
            {
                 dSetSpriteEnable("qipao",0);

            }


            if(dIsPointInSprite("baoxiang_close",posxman,posyman)==1 && ifkeyagain==1)
            {
                dSetSpritePosition("key",(screenleft+screenright)/2,(screentop+screenbottom)/2);
                ifkey=1;
                ifkeyagain=0;

                dSetSpriteEnable("baoxiang_close",0);
                dSetSpriteEnable("baoxiang_open",1);


            }
            else if(dIsPointInSprite("baoxiang_close",posxman,posyman)!=1)
            {
                dSetSpritePosition("key",screenleft-20,screenbottom+20);
                dSetSpriteEnable("baoxiang_close",1);
                dSetSpriteEnable("baoxiang_open",0);


            }
            if(dIsPointInSprite("home",posxman,posyman)==1 && ifkey==1)
            {
                dLoadMap("story4.t2d");
            }
            if(dIsPointInSprite("home",posxman,posyman)==1 && ifkey ==0)
            {
                dSetSpriteVisible("tishi",1);
                cout<<ifkey<<endl;
            }
            else
               dSetSpriteVisible("tishi",0);

        }


		// 执行游戏主循环
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

    if(dIsPointInSprite("kaishi",fMouseX,fMouseY))
    {
        dSetSpriteWidth("kaishi",30);
        dSetSpriteHeight("kaishi",10);
        //dPlaySound("mouse",0,1);
    }

    if(dIsPointInSprite("shuoming",fMouseX,fMouseY))
    {
        dSetSpriteWidth("shuoming",30);
        dSetSpriteHeight("shuoming",10);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("kaishi",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("kaishi",25);
        dSetSpriteHeight("kaishi",6.5);
    }

    if(dIsPointInSprite("shuoming",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("shuoming",24);
        dSetSpriteHeight("shuoming",6);
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
        dLoadMap("story1.t2d");
    }
	if(iMouseType==0 && dIsPointInSprite("shuoming",fMouseX,fMouseY))
    {
        dLoadMap("jieshao.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("fanhui2",fMouseX,fMouseY))
    {
        dLoadMap("kaishijiemian.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("jixuyouxi1",fMouseX,fMouseY))
    {
        choose=1;
        dStopAllSound();
        dLoadMap("guanka1.t2d");
        dPlaySound("guanka1",1,1);

      dSetSpriteWorldLimitMode("flyman", WORLD_LIMIT_NULL);
      dSetWindowTitle("FLYMAN");
        dSetTextString("space","Please click the space to enter the game.");
        dSetSpriteVisible("CE",0);
        dSetSpriteVisible("LONG",1 );
        X=dGetScreenLeft();
        Y=dGetScreenRight();
    }
    if(iMouseType==0 && dIsPointInSprite("jixuyouxi2",fMouseX,fMouseY))
    {
        choose=2;
        dStopAllSound();
        dLoadMap("guanka2.t2d");
        dPlaySound("guanka2",1,1);
        fRotateSpeed=1.f*dGetSpriteRotation("man");//人摆动速度：偏离角度*一个数，单位：度/秒

        dSetSpriteEnable("man_dunxia",0);
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("padi",0);//第二关初始禁用情况

        tiaoposx=dGetSpritePositionX("man_tiaoyue");
        tiaoposy=dGetSpritePositionY("man_tiaoyue");//获取人物坐
    }
    if(iMouseType==0 && dIsPointInSprite("jixuyouxi3",fMouseX,fMouseY))
    {
        choose=3;
        ifkey=0;
        dStopAllSound();
        dPlaySound("guanka3",1,1);
        dLoadMap("guanka3.t2d");
        dSetSpriteVisible("man3",0);
        dSetSpriteEnable("baoxiang_open",0);

        dSetSpriteEnable("qipao",0);
        dSetSpriteVisible("tishi",0);
         float screenbottom=dGetScreenBottom();
         float screentop=dGetScreenTop();

         dSetSpritePositionY("huo0",screenbottom-20);
        dSetSpritePositionY("huo1",screenbottom-20);
        dSetSpritePositionY("huo2",screenbottom-20);
        dSetSpritePositionY("huo3",screenbottom-20);

        dSetSpritePositionY("tianhuo1",screentop);
        dSetSpritePositionY("tianhuo2",screentop);
        dSetSpritePositionY("tianhuo3",screentop);
        dSetSpritePositionY("tianhuo4",screentop+55);
    }
    if(iMouseType==0 && dIsPointInSprite("fanhui",fMouseX,fMouseY))
    {
        choose=0;
        dStopAllSound();
        dLoadMap("kaishijiemian.t2d");
        dPlaySound("fengmian",1,1);
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

//第一关控制相关
if(choose==1)
{
    switch(iKey)
	{
      case KEY_SPACE:
       {
           if(flag==0||flag==1)
           {
              flag=1;
              dSetSpriteLinearVelocity("flyman",0,nv);
           }
           break;
       }
      case KEY_M:
        {
            if(flag==4)
            {
                for(int i=1;i<7;i++)
                   {
                       dSetSpritePosition(dMakeSpriteName("guai",i),55+i*40,b[i]);
                       dSetSpriteLinearVelocity(dMakeSpriteName("guai",i),-10,0);
                   }
                dSetSpritePosition("flyman",x,0);
                nv=-60;
                dSetSpriteLinearVelocity("flyman",0,25);
                TIME=0;
                dSetSpriteVisible("space",0);
                dSetSpriteLinearVelocity("LONG",-60,0);
                dCursorOff();
                flag=0;
            }
            break;//**************************************
        }
      case KEY_Q:
        {
            if(flag!=4)
            {
                dSetSpriteVisible("flyman",0);
                dSetSpriteVisible("CE",1);
                char *szname;
                szname = dMakeSpriteName("LONG",a++ );		//得到炮弹名字
                dCloneSprite("LONG",szname);		//复制炮弹模板
                dSetSpritePosition(szname,fPosX2+1,fPosY2+0.7);
                dSetSpriteLinearVelocity(szname,60,0);
                dPlayEffect("BZ",1,fPosX2,fPosY2,0);

                if(flag==0||flag==1)
                    nv=nv+5;
            }
            break;
        }
	}


	//死亡界面控制

}


//第二关控制相关
if(choose==2)
{
    if(g_iGameState==0&&iKey==KEY_SPACE)
        {
           // dDeleteSprite("GameBegin");
           g_iGameState=1;
            dSpriteMoveTo("man",-25,5,20,1);
            dSetSpriteImpulseForce("man_tiaoyue",0,-30,1);
            dSetSpriteEnable("man_tiaoyue",1);
            dSetSpriteEnable("man",0);
            dSpriteMoveTo("ball",-25,20,80,1);

        }

        if(g_iGameState==2)
        {
                if(iKey==KEY_A)
                {
                    flagA=1;
                }
                if(iKey==KEY_D)
                {
                    flagD=1;
                }
            switch(iKey)
                {
                    case KEY_SPACE:

                        if(iftiao==1)
                        {
                            dSetSpriteImpulseForce("man_tiaoyue",0,-40,1);


                            dSetSpriteEnable("man",0);
                            dSetSpriteEnable("man_tiaoyue",1);
                            dSetSpriteEnable("man_dunxia",0);
                            ifqingxie=0;
                            iftiao=0;

                        break;
                        }
                        else
                            break;

                    case KEY_S:

                        if(fabs(dGetSpriteLinearVelocityY("man"))==0)
                        {

                           dSetSpriteEnable("man",0);
                            dSetSpriteEnable("man_dunxia",1);
                            dSetSpriteEnable("man_tiaoyue",0);
                            ifqingxie=0;
                        break;
                        }
                        else
                            break;


                    case KEY_A:

                            dSetSpriteRotation("man",-90);

                    break;

                }
        }
}
if(choose==3)
{
    float man3x = dGetSpritePositionX("man3");//人物坐标
    if(iKey==KEY_SPACE && iftiao2==1 && dGetSpriteLinearVelocityY("man3")==0)
        {
            iftiao2==0;
            dSetSpriteImpulseForce("man3",0,-210,1);
            dPlaySound("jump",0,1);

        }
        if(iKey==KEY_A)
        {
            dSetSpriteFlip("man3",1,0);
            dSetSpriteFlip("man33",1,0);
            dSetSpriteVisible("man33",0);
            dSetSpriteVisible("man3",1);
            //判断背景图是否移动
            if(man3x>=-25)
            {
                flagzuo=0;
                flagyou=0;
                dSetSpriteLinearVelocityX("man3",-20);

                dSetSpriteLinearVelocityX("dimian",0);
                dSetSpriteLinearVelocityX("beijing",0);
                dSetSpriteLinearVelocityX("huo0",0);
                dSetSpriteLinearVelocityX("huo1",0);
                dSetSpriteLinearVelocityX("huo2",0);
                dSetSpriteLinearVelocityX("huo3",0);
                dSetSpriteLinearVelocityX("tianhuo1",0);
                dSetSpriteLinearVelocityX("tianhuo2",0);
                dSetSpriteLinearVelocityX("tianhuo3",0);
                dSetSpriteLinearVelocityX("tianhuo4",0);
                dSetSpriteLinearVelocityX("chuizi",0);

            }
            else
            {
                flagzuo=1;
                flagyou=0;
                dSetSpriteLinearVelocityX("dimian",20);
                dSetSpriteLinearVelocityX("beijing",20);
                dSetSpriteLinearVelocityX("huo0",20);
                dSetSpriteLinearVelocityX("huo1",20);
                dSetSpriteLinearVelocityX("huo2",20);
                dSetSpriteLinearVelocityX("huo3",20);
                dSetSpriteLinearVelocityX("tianhuo1",20);
                dSetSpriteLinearVelocityX("tianhuo2",20);
                dSetSpriteLinearVelocityX("tianhuo3",20);
                dSetSpriteLinearVelocityX("tianhuo4",20);
                dSetSpriteLinearVelocityX("chuizi",20);
            }

        }
        if(iKey==KEY_D)
        {
            dSetSpriteFlip("man3",0,0);
            dSetSpriteFlip("man33",0,0);
            dSetSpriteVisible("man33",0);
            dSetSpriteVisible("man3",1);
             //判断背景图是否移动
            if(man3x<=21)
            {
                flagzuo=0;
                flagyou=0;
                dSetSpriteLinearVelocityX("man3",20);
                dSetSpriteLinearVelocityX("dimian",0);
                dSetSpriteLinearVelocityX("beijing",0);
                dSetSpriteLinearVelocityX("huo0",0);
                dSetSpriteLinearVelocityX("huo1",0);
                dSetSpriteLinearVelocityX("huo2",0);
                dSetSpriteLinearVelocityX("huo3",0);
                dSetSpriteLinearVelocityX("tianhuo1",0);
                dSetSpriteLinearVelocityX("tianhuo2",0);
                dSetSpriteLinearVelocityX("tianhuo3",0);
                dSetSpriteLinearVelocityX("tianhuo4",0);
                dSetSpriteLinearVelocityX("chuizi",0);
            }
            else
            {
                flagzuo=0;
                flagyou=1;
                dSetSpriteLinearVelocityX("dimian",-20);
                dSetSpriteLinearVelocityX("beijing",-20);
                dSetSpriteLinearVelocityX("huo0",-20);
                dSetSpriteLinearVelocityX("huo1",-20);
                dSetSpriteLinearVelocityX("huo2",-20);
                dSetSpriteLinearVelocityX("huo3",-20);
                dSetSpriteLinearVelocityX("tianhuo1",-20);
                dSetSpriteLinearVelocityX("tianhuo2",-20);
                dSetSpriteLinearVelocityX("tianhuo3",-20);
                dSetSpriteLinearVelocityX("tianhuo4",-20);
                dSetSpriteLinearVelocityX("chuizi",-20);
            }
        }

}
        if(choosesi==3)
        {
        if(iKey==KEY_SPACE)
        {
            dLoadMap("guanka3.t2d");
            //dPlaySound("siwang",1,1);
            choosesi=0;

            dSetSpriteVisible("man3",0);
        dSetSpriteEnable("baoxiang_open",0);

        dSetSpriteEnable("qipao",0);
        int ifkeyagain=1;
         float screenbottom=dGetScreenBottom();
         float screentop=dGetScreenTop();

         dSetSpritePositionY("huo0",screenbottom-20);
        dSetSpritePositionY("huo1",screenbottom-20);
        dSetSpritePositionY("huo2",screenbottom-20);
        dSetSpritePositionY("huo3",screenbottom-20);

        dSetSpritePositionY("tianhuo1",screentop);
        dSetSpritePositionY("tianhuo2",screentop);
        dSetSpritePositionY("tianhuo3",screentop);
        dSetSpritePositionY("tianhuo4",screentop+55);
        }

        }
        if(choosesi==2)
        {
            if(iKey==KEY_SPACE)
            {
                dLoadMap("guanka2.t2d");
                //dPlaySound("siwang",1,1);
                choosesi=0;

            g_iGameState=0;
            fRotateSpeed=1.f*dGetSpriteRotation("man");//人摆动速度：偏离角度*一个数，单位：度/秒
            dSetSpriteEnable("man_dunxia",0);
            dSetSpriteEnable("man_tiaoyue",0);
            dSetSpriteEnable("padi",0);//第二关初始禁用情况

            tiaoposx=dGetSpritePositionX("man_tiaoyue");
            tiaoposy=dGetSpritePositionY("man_tiaoyue");//获取人物坐
            }

        }


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

//第一关控制系统
if(choose==1)
{
    switch(iKey)
	{
      case KEY_SPACE:
          {
              if(flag!=3&&flag!=4)
              dSetSpriteLinearVelocity("flyman",0,25);
              if(flag==2)
              {
                  for(int i=1;i<7;i++)
                   dSetSpriteLinearVelocity(dMakeSpriteName("guai",i),-10,0);
                   dSetSpriteVisible("space",0);
                   dSetSpriteLinearVelocity("LONG",-60,0);
                   dCursorOff();
                   //cout<<"a"<<endl;
              }
              if(flag==1||flag==2)
                flag=0;
              break;
          }
        // dSetSpriteImpulseForce("flyman",0,60,0);
        case KEY_Q:
        {
            dSetSpriteVisible("flyman",1);
            dSetSpriteVisible("CE",0);
            break;
        }
	}
}



//第三关控制系统
    if(choose==3)
    {
      //float man3x= dGetSpritePositionX("man3");

	if(iKey==KEY_A)
        {
            flagzuo=0;
            flagyou=0;
            dSetSpriteLinearVelocityX("man3",0);
            dSetSpriteLinearVelocityX("dimian",0);
            dSetSpriteLinearVelocityX("beijing",0);
            dSetSpriteLinearVelocityX("huo0",0);
            dSetSpriteLinearVelocityX("huo1",0);
            dSetSpriteLinearVelocityX("huo2",0);
            dSetSpriteLinearVelocityX("huo3",0);
            dSetSpriteLinearVelocityX("tianhuo1",0);
            dSetSpriteLinearVelocityX("tianhuo2",0);
            dSetSpriteLinearVelocityX("tianhuo3",0);
            dSetSpriteLinearVelocityX("tianhuo4",0);
            dSetSpriteLinearVelocityX("chuizi",0);
            dSetSpriteVisible("man33",1);
            dSetSpriteVisible("man3",0);


        }
        if(iKey==KEY_D)
        {
            flagzuo=0;
            flagyou=0;
            dSetSpriteLinearVelocityX("man3",0);
            dSetSpriteLinearVelocityX("dimian",0);
            dSetSpriteLinearVelocityX("beijing",0);
            dSetSpriteLinearVelocityX("huo0",0);
            dSetSpriteLinearVelocityX("huo1",0);
            dSetSpriteLinearVelocityX("huo2",0);
            dSetSpriteLinearVelocityX("huo3",0);
            dSetSpriteLinearVelocityX("tianhuo1",0);
            dSetSpriteLinearVelocityX("tianhuo2",0);
            dSetSpriteLinearVelocityX("tianhuo3",0);
            dSetSpriteLinearVelocityX("tianhuo4",0);
            dSetSpriteLinearVelocityX("chuizi",0);
            dSetSpriteVisible("man33",1);
            dSetSpriteVisible("man3",0);

        }
    }

	OnKeyUp(iKey);

//第二关控制系统
if(choose==2)
{
    if(g_iGameState==2&&iKey==KEY_A)
        {
            flagA=0;
        }
        if(g_iGameState==2&&iKey==KEY_D)
        {
            flagD=0;
        }

        if(g_iGameState==2)
        {
            if(iKey==KEY_S)
            {
                dSetSpriteEnable("man",1);
                dSetSpriteEnable("man_dunxia",0);
                dSetSpriteEnable("man_tiaoyue",0);
                ifqingxie=1;
            }

        }
}



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


//第一关碰撞判定
if(choose==1)
{
    for(int i=1;i<7;i++)
    {
        if(strcmp(szSrcName,"flyman")==0&&strcmp(szTarName,dMakeSpriteName("guai",i))==0)

           {
               dSetSpriteVisible(szTarName,0);
               dSetSpritePosition(szTarName,55+4*i,b[i]);
               flag2[i]=1;
               TIME-=5;
           }
        if(strstr(szSrcName,"LONG") !=NULL&&strcmp(szTarName,dMakeSpriteName("guai",i))==0)//**********
           {
               dSetSpriteVisible(szTarName,0);
               dSetSpriteVisible(szSrcName,0);
               dSetSpritePosition(szTarName,55+4*i,b[i]);
               //dSetSpritePosition(szSrcName,100,b[i]);
               dSetSpriteCollisionResponse(szSrcName,COL_RESPONSE_KILL);
               if(flag==1||flag==0)
               {
                    nv=nv-10;
                    flag2[i]=1;
                    TIME+=5;
               }
           }
    }

}


//第二关碰撞判定
if(choose==2)
{
    if(g_iGameState==1 && strcmp(szTarName,"ball")==0 && strcmp(szSrcName,"man_tiaoyue")==0)
    {
        g_iGameState=2;
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("man",1);//开场小动画判定

    }
    if(g_iGameState==2)
    {
    dSpriteMoveTo("man",-25,8,20,1);


        if(strstr(szTarName,"shuzhi")!=NULL)//人和障碍物相碰
        {
            if(strcmp(szSrcName,"man")==0)
            {
                dSetSpriteCollisionResponse("man",COL_RESPONSE_KILL);
                dPlayEffect("effect",0.2,dGetSpritePositionX("man"),dGetSpritePositionY("man"),0);
                ifsi=1;
            }
            if(strcmp(szSrcName,"man_dunxia")==0)
            {
                dSetSpriteCollisionResponse("man_dunxia",COL_RESPONSE_KILL);
                dPlayEffect("effect",0.2,dGetSpritePositionX("man_dunxia"),dGetSpritePositionY("man_dunxia"),0);
                ifsi=1;
            }
            if(strcmp(szSrcName,"man_tiaoyue")==0)
            {
                dSetSpriteCollisionResponse("man_tiaoyue",COL_RESPONSE_KILL);
                dPlayEffect("man_effect",0.2,dGetSpritePositionX("man_tiaoyue"),dGetSpritePositionY("man_tiaoyue"),0);
                ifsi=1;
            }
        }
        if(strstr(szTarName,"ball")!=NULL)//跳跃系统，防止二段跳
        {
            if(strcmp(szSrcName,"man_tiaoyue")==0)
            {
                dSetSpriteEnable("man",1);
                dSetSpriteEnable("man_tiaoyue",0);
                ifqingxie = 1;
                iftiao = 1;
            }
        }
    }
}
//第三关碰撞系统
    if(choose==3)
    {
        if(strstr(szTarName,"dimian")!=NULL)//跳跃控制
        {
            if(strcmp(szSrcName,"man3")==0)
            {
                iftiao2=1;
            }
        }

        if(strstr(szTarName,"huo")!=NULL)//与火焰相碰
        {
            if(strcmp(szSrcName,"man3")==0)
            {
                flagsi=0;
            }
        }

        if(strstr(szTarName,"dici")!=NULL&&strcmp(szSrcName,"man3")==0)//与地刺相碰
        {
            flagsi=0;
        }
        if(strstr(szTarName,"mogu")!=NULL&&strcmp(szSrcName,"man3")==0)//与蘑菇相碰
        {
            flagsi=0;
        }
        if(strstr(szTarName,"mogu")!=NULL&&strcmp(szSrcName,"man3")==0)//与蘑菇相碰
        {
            flagsi=0;
        }
        if(strstr(szSrcName,"man")!=NULL && strcmp(szTarName,"shitou")==0)//与石头相碰，石头消失
        {
            dSpriteDismount("shitou");
           dDeleteSprite("shitou");
        }

    }

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

if(choose==1)
{
      if(3==iColSide)
        {
            dSetSpriteWorldLimitMode("flyman",WORLD_LIMIT_STICKY);
            dSetSpriteLinearVelocity("flyman",0,0);
             flag=4;
             Time=0;
             for(int i=1;i<7;i++)
               dSetSpriteLinearVelocity(dMakeSpriteName("guai",i),0,0);
             dSetSpriteVisible("space",1);
             dSetTextString("space","Please click the M to enter the game again.");
        }
       if(2==iColSide)
         {
             dSetSpriteWorldLimitMode("flyman",WORLD_LIMIT_STICKY);
            // dSetSpritePosition("flyman",x,y+20);
            TIME-=5;
         }
         if((iColSide==1||iColSide==1)&&(strstr(szName,"LONG")!=NULL))
            dDeleteSprite(szName);
}

if(choose==2)
{
    if(strstr(szName,"muban")==0 && iColSide==0)
    {
    dDeleteSprite(szName);
    }
}


if(choose==3)
{


}

}

