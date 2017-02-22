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
private:
	ofMesh mesh;
	bool isSelected;
	bool isActive;
};