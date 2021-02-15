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
//��һ��
float nv=-60;
int flag2[7] ={0};
int a=0;int flag=2;//2 ��ʼ��0 ��1 δ�������ٶȣ� 3ͨ��������Ϸ��4 ʧ��

float fPosX1;
float fPosY1;
float fPosX2;
float fPosY2;
float fTimeDelta;//ɾ��While�жԸñ����Ķ��壬���䶨��Ϊȫ�ֱ���
float Time=0;
float b[10];
float x;
float y;
float TIME=0;
float X;
float Y;

//�ڶ���
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
float g_fManStartPosX; //�洢�˵ĳ�ʼXλ��
float g_fManStartPosY; //�洢�˵ĳ�ʼYλ��
float fRotateSpeed;//

//������
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
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	// ��ʼ����Ϸ����
	if( !dInitGameEngine( hInstance, lpCmdLine ) )
		return 0;

	// To do : �ڴ�ʹ��API���Ĵ��ڱ���
        dSetWindowTitle("Lesson");
    float screenright=dGetScreenRight();
    float screentop=dGetScreenTop();
    float screenbottom=dGetScreenBottom();
    float screenleft=dGetScreenLeft();//��ȡ��Ļ�߽�ֵ

    dLoadMap("kaishijiemian.t2d");
    dPlaySound("fengmian",1,1);
//��һ��
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

//�ڶ���
    if(choose==2)
    {
        dLoadMap("guanka2.t2d");
        dPlaySound("guanka2",1,1);

        fRotateSpeed=1.f*dGetSpriteRotation("man");//�˰ڶ��ٶȣ�ƫ��Ƕ�*һ��������λ����/��

        dSetSpriteEnable("man_dunxia",0);
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("padi",0);//�ڶ��س�ʼ�������

        tiaoposx=dGetSpritePositionX("man_tiaoyue");
        tiaoposy=dGetSpritePositionY("man_tiaoyue");//��ȡ������
    }


//������
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


	// ������ѭ����������Ļͼ��ˢ�µȹ���
	while( dEngineMainLoop() )
	{
		// ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
        fTimeDelta	=	dGetTimeDelta();

    //��һ������
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
                    flag2[i]=2;//�����ظ����ţ�������ʧ����Ļ��

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


    //�ڶ�������
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
            //�ϰ�������
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

                if(ifqingxie==1)//����������б
                {
                    float fThisRotate = fRotateSpeed * fTimeDelta;

                        g_fManRotation+=fThisRotate;
                        fRotateSpeed=0.1f*g_fManRotation+4;
                        if(flagD==1)
                        {
                            float fkeyRotate = 30.f * fTimeDelta;//��D������һ���ٶȳ���
                            g_fManRotation+=fkeyRotate;
                        }
                        if(flagA==1)
                        {
                            float fkeyRotate = -30.f * fTimeDelta;//��A������һ���ٶȳ���
                            g_fManRotation+=fkeyRotate;
                        }

                        if(g_fManRotation >= 110.f || g_fManRotation <= -110.f)//�ж�����б������ʧ������
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
                                ifsi=1;//��ת��ʧ�ܽ���
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
 //����������
        if(choose==3)
        {
        dSetSpriteConstantForce("man3",0,100,1);
        float posxman=dGetSpritePositionX("man3");
        float posyman=dGetSpritePositionY("man3");

        //����Ģ�����ش�
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


        //�������
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


        //���л���

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


        //ͳһ��������
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


		// ִ����Ϸ��ѭ��
		GameMainLoop( fTimeDelta );
	};

	// �ر���Ϸ����
	dShutdownGameEngine();
	return 0;
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
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
// ���沶׽�������Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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
        fRotateSpeed=1.f*dGetSpriteRotation("man");//�˰ڶ��ٶȣ�ƫ��Ƕ�*һ��������λ����/��

        dSetSpriteEnable("man_dunxia",0);
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("padi",0);//�ڶ��س�ʼ�������

        tiaoposx=dGetSpritePositionX("man_tiaoyue");
        tiaoposy=dGetSpritePositionY("man_tiaoyue");//��ȡ������
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
// ���沶׽��굯����Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnMouseUp(iMouseType, fMouseX, fMouseY);

}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
//
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����

//��һ�ؿ������
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
                szname = dMakeSpriteName("LONG",a++ );		//�õ��ڵ�����
                dCloneSprite("LONG",szname);		//�����ڵ�ģ��
                dSetSpritePosition(szname,fPosX2+1,fPosY2+0.7);
                dSetSpriteLinearVelocity(szname,60,0);
                dPlayEffect("BZ",1,fPosX2,fPosY2,0);

                if(flag==0||flag==1)
                    nv=nv+5;
            }
            break;
        }
	}


	//�����������

}


//�ڶ��ؿ������
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
    float man3x = dGetSpritePositionX("man3");//��������
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
            //�жϱ���ͼ�Ƿ��ƶ�
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
             //�жϱ���ͼ�Ƿ��ƶ�
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
            fRotateSpeed=1.f*dGetSpriteRotation("man");//�˰ڶ��ٶȣ�ƫ��Ƕ�*һ��������λ����/��
            dSetSpriteEnable("man_dunxia",0);
            dSetSpriteEnable("man_tiaoyue",0);
            dSetSpriteEnable("padi",0);//�ڶ��س�ʼ�������

            tiaoposx=dGetSpritePositionX("man_tiaoyue");
            tiaoposy=dGetSpritePositionY("man_tiaoyue");//��ȡ������
            }

        }


OnKeyDown(iKey, iAltPress, iShiftPress, iCtrlPress);

}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
//
void dOnKeyUp( const int iKey )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����

//��һ�ؿ���ϵͳ
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



//�����ؿ���ϵͳ
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

//�ڶ��ؿ���ϵͳ
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
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
//
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
// �����ڴ������Ϸ��Ҫ����Ӧ����


//��һ����ײ�ж�
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


//�ڶ�����ײ�ж�
if(choose==2)
{
    if(g_iGameState==1 && strcmp(szTarName,"ball")==0 && strcmp(szSrcName,"man_tiaoyue")==0)
    {
        g_iGameState=2;
        dSetSpriteEnable("man_tiaoyue",0);
        dSetSpriteEnable("man",1);//����С�����ж�

    }
    if(g_iGameState==2)
    {
    dSpriteMoveTo("man",-25,8,20,1);


        if(strstr(szTarName,"shuzhi")!=NULL)//�˺��ϰ�������
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
        if(strstr(szTarName,"ball")!=NULL)//��Ծϵͳ����ֹ������
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
//��������ײϵͳ
    if(choose==3)
    {
        if(strstr(szTarName,"dimian")!=NULL)//��Ծ����
        {
            if(strcmp(szSrcName,"man3")==0)
            {
                iftiao2=1;
            }
        }

        if(strstr(szTarName,"huo")!=NULL)//���������
        {
            if(strcmp(szSrcName,"man3")==0)
            {
                flagsi=0;
            }
        }

        if(strstr(szTarName,"dici")!=NULL&&strcmp(szSrcName,"man3")==0)//��ش�����
        {
            flagsi=0;
        }
        if(strstr(szTarName,"mogu")!=NULL&&strcmp(szSrcName,"man3")==0)//��Ģ������
        {
            flagsi=0;
        }
        if(strstr(szTarName,"mogu")!=NULL&&strcmp(szSrcName,"man3")==0)//��Ģ������
        {
            flagsi=0;
        }
        if(strstr(szSrcName,"man")!=NULL && strcmp(szTarName,"shitou")==0)//��ʯͷ������ʯͷ��ʧ
        {
            dSpriteDismount("shitou");
           dDeleteSprite("shitou");
        }

    }

	OnSpriteColSprite(szSrcName, szTarName);
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
//
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
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

