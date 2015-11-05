//VideoManager.h
#pragma once
#include <hge.h>
#include <dshow.h>
#pragma comment(lib,"strmiids.lib")
#pragma comment(lib,"quartz.lib")
//视频管理类
class VideoManager
{
public:
 VideoManager();
 ~VideoManager();
 void Init();     //初始化
 void Release();  //释放资源
 void PlayFile(const WCHAR* filename);  //加载视频
 void Play();    //播放
 void Pause();   //暂停
 void Stop();    //停止 
 bool IsPlaying()const { return m_bIsPlaying;} //释放正在播放
 void SetContinuePlay(bool value) { m_bIsContinuePlay=value; }
 bool HandleEvent(); //消息处理
private:
 HGE*            m_phge;
 IGraphBuilder* m_pGraph;
 IMediaControl* m_pMediaControl;
 IMediaEventEx* m_pEvent;
 HWND            m_hwnd;
 HRESULT         hr;
 IVideoWindow* m_pVidWin;
 bool  m_bIsPlaying; //是否在播放
 bool  m_bIsContinuePlay; //是否持续播放（不间断）
};