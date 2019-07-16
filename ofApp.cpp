#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// �������
	gui.setup();
	gui.add(rectVisible.setup("ball visible", true));
	gui.add(color.setup("color", 255, 0, 255)); // ��ɫ
	gui.add(length.setup("length", 100, 0, 100)); // ����
	gui.add(rotate.setup("rotate", 360, 0, 360)); // ��ת
	gui.add(ballVisible.setup("ball visible",false));
	gui.add(ballRotate.setup("ball rotate", true));

	// ���ñ���
	ofBackground(100);
	// ���ù�Դ
	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor(ofFloatColor(0.9, 0.9, 0.9)); // ������������ɫ
	// ��������
	sphere.setRadius(100);
	material.setShininess(120); // ƽ����
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	if (ballVisible) {
		cam.setGlobalPosition({ 0,0,cam.getImagePlaneDistance(ofGetCurrentViewport()) }); // �趨�����λ��
		cam.begin();
		sphere.setPosition(0, 0, 0); // ����Ϊ����ԭ��
		sphere.rotateDeg(ballRotate, 0, 1.0, 0.0); // ������ת
		ofNoFill(); // �����ǻ�������Ŀ��
		ofSetColor(255, 255, 255);
		sphere.setScale(1.01f);
		sphere.drawWireframe();
		sphere.setScale(1.f);
		cam.end();
	}
	if (rectVisible) {
		ofTranslate(400, 300, 0); // ��������
		ofRotate(rotate, 0, 0, 1); // �������ת
		ofSetColor(color);
		ofFill();
		ofDrawRectangle(-50, -50, 0, length, length);
	}
}
