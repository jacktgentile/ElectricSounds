#include "ofApp.h"
#include <iomanip>
#include <sstream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	ofSetFrameRate(15);
	//0 output channels
	//44100 input per second (standard)
	//256 standard requested bufferSize
	//4 num buffers
	//http://openframeworks.cc/documentation/sound/ofSoundStream/#show_setup
	soundStream.setup(this, 0, 2, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(230, 100, 100);
	stringstream message;
	message << "Volume:     " << fixed << setprecision(2) << cur_vol;
	ofDrawBitmapString(message.str(), 50, 50);
	//clear stringstream variable
	//
	message.str("");
	message << "Max volume: " << fixed << setprecision(2) << max_vol;
	ofDrawBitmapString(message.str(), 50, 70);
	ofDrawRectangle(50, 100, cur_vol * 20.0, 50);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
	cur_vol = 0.0;
	for (int i = 0; i < bufferSize; i++) {
		float temp = input[i];
		cur_vol += abs(temp);
	}
	if (cur_vol > max_vol) {
		max_vol = cur_vol;
	}
	//std::cout << cur_vol << endl;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
