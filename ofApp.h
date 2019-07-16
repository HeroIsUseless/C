#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void draw();

	ofxPanel gui; // ���
	ofxToggle rectVisible; // �����
	ofxFloatSlider length; // �뾶
	ofxFloatSlider rotate; // ��ת
	ofxFloatSlider color; // ��ɫ

	ofxToggle ballVisible; // �����
	ofxToggle ballRotate; // �����
	ofIcoSpherePrimitive sphere; // ���� 
	ofLight pointLight; // ���Դ
	ofMaterial material; // ����
	float spinY = 1; // ��ת�ٶ�
	ofCamera cam;
};

