#pragma once
#include "ofMain.h"

class ofxMovableQuad
{
public:
	void setup(float x, float y, float w, float h);
	void draw(const ofTexture& texture);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
	void setActive(bool isActive);
	ofVec2f getPosition();
	ofVec2f getSize();
private:
	ofMesh mesh;
	bool isSelected;
	bool isActive;
};