#include "ofxMovableQuad.h"

void ofxMovableQuad::setup(float x, float y, float w, float h)
{
	mesh.addVertex(ofVec2f(x, y));
	mesh.addVertex(ofVec2f(x, y + h));
	mesh.addVertex(ofVec2f(x + w, y + h));
	mesh.addVertex(ofVec2f(x + w, y));

	mesh.addTexCoord(ofVec2f(0, 0));
	mesh.addTexCoord(ofVec2f(0, 1));
	mesh.addTexCoord(ofVec2f(1, 1));
	mesh.addTexCoord(ofVec2f(1, 0));

	mesh.addIndex(0);
	mesh.addIndex(1);
	mesh.addIndex(3);
	mesh.addIndex(3);
	mesh.addIndex(1);
	mesh.addIndex(2);

	isActive = true;
}

void ofxMovableQuad::draw(const ofTexture & texture)
{
	if (!isActive)return;
	texture.bind();
	mesh.drawFaces();
	texture.unbind();
	if (isSelected) {
		ofPushStyle();
		ofNoFill();
		ofSetColor(0, 255, 0);
		ofDrawRectangle(mesh.getVertex(0), mesh.getVertex(3).x - mesh.getVertex(0).x, mesh.getVertex(1).y - mesh.getVertex(0).y);
		ofPopStyle();
		
	}
}

void ofxMovableQuad::mouseDragged(int x, int y, int button)
{
	if (isSelected) {
		for (auto i = 0; i < mesh.getNumVertices(); i++) {
			mesh.setVertex(i, mesh.getVertex(i) + ofVec2f(x - ofGetPreviousMouseX(), y - ofGetPreviousMouseY()));
		}
	}
}

void ofxMovableQuad::mousePressed(int x, int y, int button)
{
	isSelected = false;
	if (x > mesh.getVertex(0).x && x < mesh.getVertex(3).x) {
		if (y > mesh.getVertex(0).y && y < mesh.getVertex(1).y) {
			isSelected = true;
		}
	}
}

void ofxMovableQuad::keyPressed(int key)
{
	if (isSelected) {
		if (key == OF_KEY_BACKSPACE) {
			this->isActive = false;
		}
	}
}

void ofxMovableQuad::setActive(bool isActive)
{
	this->isActive = isActive;
}
