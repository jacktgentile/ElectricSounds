#include "ofApp.h"
#include <iomanip>
#include <sstream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0);
	ofSetFrameRate(30);
	smoothed_vol_ = 0.0;
	cur_state_ = RUNNING;


	//0 output channels 2 input
	//44100 input per second (standard)
	//256 standard requested bufferSize
	//4 num buffers
	//http://openframeworks.cc/documentation/sound/ofSoundStream/#show_setup
	soundStream.setup(this, 0, 2, 44100, 256, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (cur_state_ == RUNNING) {
		circle_.update(smoothed_vol_, max_vol_);
		circle_two_.update(smoothed_vol_, max_vol_);
		shape_.update(smoothed_vol_, max_vol_);
		shape_two_.update(smoothed_vol_, max_vol_);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 150, 150);
	stringstream message;
	message << "max vol: " << fixed << setprecision(2) << max_vol_;
	ofDrawBitmapString(message.str(), 20, 20);
	message.str("");
	message << "sm vol:  " << fixed << setprecision(2) << smoothed_vol_;
	ofDrawBitmapString(message.str(), 20, 40);

	circle_.draw();
	circle_two_.draw();
	shape_.draw();
	shape_two_.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'p') {
		soundStream.stop();
		cur_state_ = PAUSED;
	}
	else if (key == 'u') {
		soundStream.start();
		cur_state_ = RUNNING;
	}
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

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
	//read audio input, then estimate volume
	cur_vol_ = 0.0;
	for (int i = 0; i < bufferSize; i++) {
		float temp = input[i];
		cur_vol_ += abs(temp);
	}
	//keep track of the greatest volume
	if (cur_vol_ > max_vol_) {
		max_vol_ = cur_vol_;
	}
	//cur_vol changes too quickly, so adjust the smoothed_vol
	smoothed_vol_ = (0.9 * smoothed_vol_ + 0.1 * cur_vol_);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
