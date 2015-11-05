//VideoManager.h
#pragma once
#include <hge.h>
#include <dshow.h>
#pragma comment(lib,"strmiids.lib")
#pragma comment(lib,"quartz.lib")
//��Ƶ������
class VideoManager
{
public:
 VideoManager();
 ~VideoManager();
 void Init();     //��ʼ��
 void Release();  //�ͷ���Դ
 void PlayFile(const WCHAR* filename);  //������Ƶ
 void Play();    //����
 void Pause();   //��ͣ
 void Stop();    //ֹͣ 
 bool IsPlaying()const { return m_bIsPlaying;} //�ͷ����ڲ���
 void SetContinuePlay(bool value) { m_bIsContinuePlay=value; }
 bool HandleEvent(); //��Ϣ����
private:
 HGE*            m_phge;
 IGraphBuilder* m_pGraph;
 IMediaControl* m_pMediaControl;
 IMediaEventEx* m_pEvent;
 HWND            m_hwnd;
 HRESULT         hr;
 IVideoWindow* m_pVidWin;
 bool  m_bIsPlaying; //�Ƿ��ڲ���
 bool  m_bIsContinuePlay; //�Ƿ�������ţ�����ϣ�
};