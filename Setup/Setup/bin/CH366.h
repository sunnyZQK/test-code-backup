#include "stdafx.h"


/******************************************************************************* 
1�� �������ƣ� OpenTP366
2�� ���������� ��366�豸
3�� ��������� ��
4�� �� �� ֵ�� -1   DLL����ʧ��
			 -2    ��������ʧ��
			 -3    δ�ҵ���
			 1     �򿪳ɹ� 
5�� ��̬�ڴ棺 ��
6�� ������ƣ�  ��ë
7�� �������ڣ� 2011-9-1 14:42:46
8�� ��    ע�� 
********************************************************************************/ 
extern "C" __declspec(dllexport) int OpenCH366(void);

/******************************************************************************* 
1�� �������ƣ� GetNet
2�� ���������� �õ���ǰ����������
3�� ���������  ��
4�� �� �� ֵ�� ����2Ϊ������1Ϊ����
5�� ��̬�ڴ棺 ��
6�� ������ƣ�  ��ë
7�� �������ڣ� 2011-9-1 15:09:16
8�� ��    ע�� 
********************************************************************************/ 
extern "C" __declspec(dllexport) int GetNet(void);

/******************************************************************************* 
1�� �������ƣ� ChangeNet
2�� ���������� 
3�� ��������� bNetBit    Ϊ1ʱ���л�������;�����л���������
			 iPowerOff    Ϊ1ʱ�������������Ϊ2���߼��������������ߵĻ�����������Զ����� Ϊ3ʱ�رռ����
			 bInterFace Ϊ1ʱ������ʱ����ѡ����棬���򲻳�ѡ����档
4�� �� �� ֵ��  0���ɹ��л�
			   1��δ�ҵ���
			   2����ȡ���绷��ʧ��
			   3�������л���������ʧ��
			   4�������л�д�뻻������ʧ��
			   5��������������
			   6�����������ߡ��ػ�����
			   7���л��������ͳ���
5�� ��̬�ڴ棺 ��
6�� ������ƣ�  ��ë
7�� �������ڣ� 2011-9-23 17:48:03
8�� ��    ע�� �˴�δ�Ӵ�����������
********************************************************************************/ 
extern "C" __declspec(dllexport) int ChangeNet(BOOL bNetBit, int iPowerOff, BOOL bInterFace);

//�ر�366�豸
extern "C" __declspec(dllexport) void CloseCH366(void);

//�Զ���TRACE����
extern "C" __declspec(dllexport) void MyTRACE(WCHAR *fmt, ...);