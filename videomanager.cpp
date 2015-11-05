#include "videomanager.h"



#define WM_GRAPHNOTIFY  WM_APP + 1

VideoManager::VideoManager()
{ 
 m_bIsPlaying = false;
 m_phge = 0;
 m_pGraph = 0;
 m_pMediaControl = 0;
 m_pEvent = 0; 
 m_pVidWin = 0;
 m_bIsContinuePlay = false;
 hr = CoInitialize(NULL);
}
VideoManager::~VideoManager()
{ 
	CoUninitialize();
}
//��ʼ��
void VideoManager::Init()
{
  m_phge = hgeCreate(HGE_VERSION);
  m_hwnd = m_phge->System_GetState(HGE_HWND);    
}
//�ͷ���Դ
void VideoManager::Release()
{
    hr=m_pGraph->QueryInterface(IID_IVideoWindow, (void **)&m_pVidWin);
    hr=m_pVidWin->put_Visible(OAFALSE);
    hr=m_pVidWin->put_Owner(NULL);
    // Stop the graph.
    hr=m_pMediaControl->Stop(); 
    long evCode;
    m_pEvent->WaitForCompletion(INFINITE, &evCode);
    if(m_pMediaControl) m_pMediaControl->Release();
    if(m_pEvent) m_pEvent->Release();
    if(m_pGraph) m_pGraph->Release();
    m_pGraph = NULL;
    m_pVidWin = NULL;
    m_pMediaControl = NULL;
    m_pEvent = NULL;
}
//������Ƶ
void VideoManager::PlayFile(const WCHAR* filename)
{ 
 Stop();
 hr=m_pGraph->RenderFile(filename,NULL);
 RECT rc;
 GetClientRect(m_hwnd, &rc);
 hr=m_pVidWin->SetWindowPosition(0, 0, rc.right, rc.bottom);
 hr=m_pVidWin->put_Owner((OAHWND)m_hwnd); 
 hr=m_pVidWin->put_MessageDrain((OAHWND)m_hwnd);
 hr=m_pVidWin->put_WindowStyle( WS_CHILD | WS_CLIPSIBLINGS);
 
 Play();
}
//������Ƶ
void VideoManager::Play()
{
 if(m_pMediaControl)
 {
  hr=m_pVidWin->put_Visible(OATRUE);
  hr=m_pMediaControl->Run();
  m_bIsPlaying = true;  
  if(m_bIsContinuePlay)
  {
   long evCode;
   hr=m_pEvent->WaitForCompletion(INFINITE, &evCode);  //ǿ�Ƴ������ţ�������������Ϣ��
   m_bIsPlaying = false;
  }
 }
}
//��ͣ
void VideoManager::Pause()
{
 if(m_pMediaControl) hr=m_pMediaControl->Pause();
}
//ֹͣ
void VideoManager::Stop()
{
 if(m_pMediaControl)
 {
  hr=m_pMediaControl->Stop();
  hr=m_pMediaControl->Release();
  m_bIsPlaying = false;
 }
    if(m_pEvent)  m_pEvent->Release();
    if(m_pGraph)  m_pGraph->Release();
 if(m_pVidWin) m_pVidWin->Release();
 hr=CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&m_pGraph);
 hr=m_pGraph->QueryInterface(IID_IVideoWindow, (void **)&m_pVidWin);  
 hr=m_pGraph->QueryInterface(IID_IMediaEventEx, (void **)&m_pEvent);
    //m_pEvent->SetNotifyWindow((OAHWND)m_hwnd, WM_GRAPHNOTIFY, 0);
  hr=m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl);  
  
}
//��Ϣ����
bool VideoManager::HandleEvent()
{
    long evCode, param1, param2;
    while (hr = m_pEvent->GetEvent(&evCode, &param1, &param2, 0), SUCCEEDED(hr))
    {
        hr = m_pEvent->FreeEventParams(evCode, param1, param2);
        if ((EC_COMPLETE == evCode) || (EC_USERABORT == evCode))
        {    
   Stop();    
            break;
        }
    }
 return false;
}