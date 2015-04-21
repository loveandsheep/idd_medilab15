#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0, 0, 0);
	ofSetCircleResolution(64);

	for (int i = 0;i < numBlob;i++){
		position[i].set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		velocity[i].set(ofRandomf() * 5.0, ofRandomf() * 5.0);
		cl[i].setHsb(ofRandom(0.4) + 0.45, ofRandom(0.5,1.0), 1.0, 0.5);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < numBlob; i++){
		position[i] += velocity[i];

		if (abs(position[i].x - ofGetWidth() / 2.0) > ofGetWidth() / 2.0)
			velocity[i].x *= -1;

		if (abs(position[i].y - ofGetHeight() / 2.0) > ofGetHeight() / 2.0)
			velocity[i].y *= -1;

	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	glPointSize(3.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < numBlob; i++){
		ofSetColor(cl[i]);
		glVertex2d(position[i].x, position[i].y);
	}
	glEnd();

	ofDrawBitmapString(ofToString(ofGetFrameRate()), 30,30);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}
