//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include"bits/stdc++.h"


int laba=0;//�������Ȱ󶨵Ĳ�ž�����Ƿ�ɼ�
int wenzi=1;//���ֽ��ܽ��澫����ʾ˳��
int GrowthStage=1;//�����׶�
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
	dSetWindowTitle("wine");
    dLoadMap("wine.t2d");
	// ������ѭ����������Ļͼ��ˢ�µȹ���
	while( dEngineMainLoop() )
	{
		// ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
		float	fTimeDelta	=	dGetTimeDelta();

		// ִ����Ϸ��ѭ��
		//printf("1\n");//����ˢ��Ƶ��
        dSetSpriteVisible("chahao",laba%2 );//���Ʋ�ž���ĳ�������ʧ
        if(wenzi<=1)
        {
            wenzi=1;
            dSetSpriteVisible("wenzi1",1);
            dSetSpriteVisible("wenzi2",0);
            dSetSpriteVisible("wenzi3",0);
        }
        if(wenzi==2)
        {
            dSetSpriteVisible("wenzi1",0);
            dSetSpriteVisible("wenzi3",0);
            dSetSpriteVisible("wenzi2",1);
        }
        if(wenzi>=3)
        {
            wenzi=3;
            dSetSpriteVisible("wenzi1",0);
            dSetSpriteVisible("wenzi2",0);
            dSetSpriteVisible("wenzi3",1);
        }
        if(GrowthStage==1)
        {
            dSetTextString( "jindutiao", "0%" );
            dSetTextString( "jieduanming", "��ѿ��" );
            dSetTextString( "temperature", "�����¶ȣ�10��-15��" );
            dSetTextString( "humidity", "����ʪ�ȣ�70%����" );
            dSetTextString( "light", "����ǿ�ȣ���Ҫ��" );
            dSetTextString( "co2", "����CO2Ũ�ȣ�300mg/L" );
            dSetTextString( "wendu", "   �¶�" );//ע��ո�
            dSetTextString( "shidu", "   ʪ��" );
            dSetTextString( "eryang", "������̼Ũ��" );
            dSetTextString( "guangzhao", "����ǿ��" );
            dSetSpriteVisible("jindu1",0);
            dSetSpriteVisible("jindu2",0);
            dSetSpriteVisible("jindu3",0);
            dSetSpriteVisible("jindu4",0);
            dSetSpriteVisible("jindu5",0);

        }
        if(GrowthStage==2)
        {
            dSetTextString( "jindutiao", "20%" );
            dSetTextString( "jieduanming", "������" );
            dSetTextString( "temperature", "�����¶ȣ�25��-30��" );
            dSetTextString( "humidity", "����ʪ�ȣ�70%����" );
            dSetTextString( "light", "���˹��գ���ֹ���" );
            dSetTextString( "co2", "����CO2Ũ�ȣ�300mg/L" );
            dSetSpriteVisible("jindu1",1);
            dSetSpriteVisible("jindu2",0);
            dSetSpriteVisible("jindu3",0);
            dSetSpriteVisible("jindu4",0);
            dSetSpriteVisible("jindu5",0);

        }
        if(GrowthStage==3)
        {
            dSetTextString( "jindutiao", "40%" );
            dSetTextString( "jieduanming", "������" );
            dSetTextString( "temperature", "�����¶ȣ�15��-20��" );
            dSetTextString( "humidity", "����ʪ�ȣ�50%����" );
            dSetTextString( "light", "���˹��գ���ֹ���" );
            dSetTextString( "co2", "����CO2Ũ�ȣ�300mg/L" );
            dSetSpriteVisible("jindu1",1);
            dSetSpriteVisible("jindu2",1);
            dSetSpriteVisible("jindu3",0);
            dSetSpriteVisible("jindu4",0);
            dSetSpriteVisible("jindu5",0);

        }
        if(GrowthStage==4)
        {
            dSetTextString( "jindutiao", "60%" );
            dSetTextString( "jieduanming", "�����" );
            dSetTextString( "temperature", "�����¶ȣ�28��-32��" );
            dSetTextString( "humidity", "����ʪ�ȣ�50%����" );
            dSetTextString( "light", "���˹��գ���ֹ���" );
            dSetTextString( "co2", "����CO2Ũ�ȣ�600mg/L" );
            dSetSpriteVisible("jindu1",1);
            dSetSpriteVisible("jindu2",1);
            dSetSpriteVisible("jindu3",1);
            dSetSpriteVisible("jindu4",0);
            dSetSpriteVisible("jindu5",0);

        }
        if(GrowthStage==5)
        {
            dSetTextString( "jindutiao", "80%" );
            dSetTextString( "jieduanming", "������" );
            dSetTextString( "temperature", "�����¶ȣ�28��-32��" );
            dSetTextString( "humidity", "����ʪ�ȣ�40%����" );
            dSetTextString( "light", "���˹��գ���ֹ���" );
            dSetTextString( "co2", "����CO2Ũ�ȣ�400mg/L" );
            dSetSpriteVisible("jindu1",1);
            dSetSpriteVisible("jindu2",1);
            dSetSpriteVisible("jindu3",1);
            dSetSpriteVisible("jindu4",1);
            dSetSpriteVisible("jindu5",0);

        }
        if(GrowthStage==6)
        {
            dSetTextString( "jindutiao", "100%" );
            dSetTextString( "jieduanming", "�Ѿ���ֲ���" );
            dSetTextString( "temperature", "" );
            dSetTextString( "humidity", "" );
            dSetTextString( "light", "" );
            dSetTextString( "co2", "" );
            dSetSpriteVisible("jindu1",1);
            dSetSpriteVisible("jindu2",1);
            dSetSpriteVisible("jindu3",1);
            dSetSpriteVisible("jindu4",1);
            dSetSpriteVisible("jindu5",1);

        }

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
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(dIsPointInSprite("kaishi",fMouseX,fMouseY))
    {
        dSetSpriteWidth("kaishi",30);
        dSetSpriteHeight("kaishi",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("kaishi",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("kaishi",25);
        dSetSpriteHeight("kaishi",10);
    }

    if(dIsPointInSprite("jieshao",fMouseX,fMouseY))
    {
        dSetSpriteWidth("jieshao",30);
        dSetSpriteHeight("jieshao",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("jieshao",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("jieshao",25);
        dSetSpriteHeight("jieshao",10);
    }
    if(dIsPointInSprite("laba",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("laba",7);
        dSetSpriteHeight("laba",7);
        dSetSpriteWidth("chahao",7);
        dSetSpriteHeight("chahao",7);
    }
    if(dIsPointInSprite("laba",fMouseX,fMouseY))
    {
        dSetSpriteWidth("laba",9);
        dSetSpriteHeight("laba",9);
        dSetSpriteWidth("chahao",9);
        dSetSpriteHeight("chahao",9);
        //dPlaySound("mouse",0,1);
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
    if(dIsPointInSprite("shangjieduan",fMouseX,fMouseY))
    {
        dSetSpriteWidth("shangjieduan",17.5);
        dSetSpriteHeight("shangjieduan",7);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("shangjieduan",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("shangjieduan",15);
        dSetSpriteHeight("shangjieduan",6);
    }
    if(dIsPointInSprite("xiajieduan",fMouseX,fMouseY))
    {
        dSetSpriteWidth("xiajieduan",17.5);
        dSetSpriteHeight("xiajieduan",7);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("xiajieduan",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("xiajieduan",15);
        dSetSpriteHeight("xiajieduan",6);
    }
    if(dIsPointInSprite("zhi",fMouseX,fMouseY))//���溦��ʾ
    {
        dSetSpriteWidth("zhi",30);
        dSetSpriteHeight("zhi",40);
        dSetSpriteWidth("duihao1",5);
        dSetSpriteHeight("duihao1",5);
        dSetSpriteWidth("duihao2",5);
        dSetSpriteHeight("duihao2",5);
        dSetSpriteWidth("duihao3",5);
        dSetSpriteHeight("duihao3",5);
        dSetSpriteWidth("duihao4",5);
        dSetSpriteHeight("duihao4",5);
        dSetSpriteWidth("duihao5",5);
        dSetSpriteHeight("duihao5",5);
        dSetSpriteWidth("duihao6",5);
        dSetSpriteHeight("duihao6",5);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("zhi",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("zhi",18);
        dSetSpriteHeight("zhi",24);
        dSetSpriteWidth("duihao1",3);
        dSetSpriteHeight("duihao1",3);
        dSetSpriteWidth("duihao2",3);
        dSetSpriteHeight("duihao2",3);
        dSetSpriteWidth("duihao3",3);
        dSetSpriteHeight("duihao3",3);
        dSetSpriteWidth("duihao4",3);
        dSetSpriteHeight("duihao4",3);
        dSetSpriteWidth("duihao5",3);
        dSetSpriteHeight("duihao5",3);
        dSetSpriteWidth("duihao6",3);
        dSetSpriteHeight("duihao6",3);
    }
    if(dIsPointInSprite("timu",fMouseX,fMouseY))
    {
        dSetSpriteWidth("timu",88);
        dSetSpriteHeight("timu",8);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("timu",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("timu",66);
        dSetSpriteHeight("timu",6);
    }
    if(dIsPointInSprite("shangye",fMouseX,fMouseY))
    {
        dSetSpriteWidth("shangye",9);
        dSetSpriteHeight("shangye",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("shangye",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("shangye",6);
        dSetSpriteHeight("shangye",8);
    }
    if(dIsPointInSprite("xiaye",fMouseX,fMouseY))
    {
        dSetSpriteWidth("xiaye",9);
        dSetSpriteHeight("xiaye",12);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("xiaye",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("xiaye",6);
        dSetSpriteHeight("xiaye",8);
    }
    if(dIsPointInSprite("fanhui1",fMouseX,fMouseY))
    {
        dSetSpriteWidth("fanhui1",12.25);
        dSetSpriteHeight("fanhui1",9.75);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("fanhui1",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("fanhui1",7.5);
        dSetSpriteHeight("fanhui1",6.5);
    }
    if(dIsPointInSprite("fanhui2",fMouseX,fMouseY))
    {
        dSetSpriteWidth("fanhui2",12.25);
        dSetSpriteHeight("fanhui2",9.75);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("fanhui2",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("fanhui2",7.5);
        dSetSpriteHeight("fanhui2",6.5);
    }
    if(dIsPointInSprite("fanhui3",fMouseX,fMouseY))
    {
        dSetSpriteWidth("fanhui3",12.25);
        dSetSpriteHeight("fanhui3",9.75);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("fanhui3",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("fanhui3",7.5);
        dSetSpriteHeight("fanhui3",6.5);
    }
    if(dIsPointInSprite("fanhui4",fMouseX,fMouseY))
    {
        dSetSpriteWidth("fanhui4",12.25);
        dSetSpriteHeight("fanhui4",9.75);
        //dPlaySound("mouse",0,1);
    }
    if(dIsPointInSprite("fanhui4",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("fanhui4",7.5);
        dSetSpriteHeight("fanhui4",6.5);
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
    if(iMouseType==0 && dIsPointInSprite("fanhui4",fMouseX,fMouseY))
    {
        dLoadMap("guanka.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("zhongzhi",fMouseX,fMouseY))
    {
        dLoadMap("nongchang.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("niangzao",fMouseX,fMouseY))
    {
        dLoadMap("gongchang.t2d");
    }
    if(iMouseType==0 && dIsPointInSprite("laba",fMouseX,fMouseY))
    {
        laba=laba+1;
        //�˴���ӿ����������ź���
    }
    if(iMouseType==0 && dIsPointInSprite("shangye",fMouseX,fMouseY))
    {
        wenzi=wenzi-1;//���ֽ����Ϸ�ҳ
    }
    if(iMouseType==0 && dIsPointInSprite("xiaye",fMouseX,fMouseY))
    {
        wenzi=wenzi+1;//���ֽ����·�ҳ
    }
    if(iMouseType==0 && dIsPointInSprite("shangjieduan",fMouseX,fMouseY)&&GrowthStage>1)
    {
        GrowthStage--;
    }
    if(iMouseType==0 && dIsPointInSprite("xiajieduan",fMouseX,fMouseY)&&GrowthStage<6)
    {
        GrowthStage++;
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
	OnKeyUp(iKey);
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
}

