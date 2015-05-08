/*
	����������֡����
*/

#ifndef __AnimationUtil_H__
#define __AnimationUtil_H__
#include "cocos2d.h"
USING_NS_CC;
class AnimationUtil{
public:
	/* �����ļ�����ǰ׺������������
		name:ͼƬ����
		delay�������ӳ�
		iLoops�����Ŵ���
	*/
	static Animation* creaateWithSingleFrameName(const char* name, float delay, int iLoops);

	/* �����ļ�����ǰ׺������������ָ������ͼƬ����
		name:ͼƬ����
		iNum:ͼƬ����
		delay�������ӳ�
		iLoops�����Ŵ���
	*/
	static Animation* createWithFrameNameAndNum(const char* name, int iNum, float delay, int iLoops);
};
#endif