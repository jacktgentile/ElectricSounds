#include "ofApp.h"
#include <iomanip>
#include <sstream>


//convert time in milliseconds to a string of form min:sec
string ofApp::ms_to_time(int ms)
{
	stringstream time_str;
	int time_sec = ms / 1000;
	int time_min = time_sec / 60;
	time_sec = time_sec % 60;
	time_str << time_min << ":";
	if (time_sec < 10) {
		time_str << 0;
	}
	time_str << time_sec;
	return time_str.str();
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(0);
	ofSetFrameRate(50);
	cur_state_ = RUNNING;
	for (int i = 0; i < num_bands_; i++) {
		smoothed_spec_[i] = 0.0f;
	}

	//play the song at this file in bin/data/
	//calc the length of the song inspired by this https://forum.openframeworks.cc/t/ofsoundplayer-length/11560
	mySound.load("songs/6-inch.wav");
	mySound.setVolume(0.0);
	mySound.play();
	mySound.setPosition(0.9999999f);
	max_position_ms_ = mySound.getPositionMS();
	mySound.setPosition(0);
	mySound.setVolume(0.8);
	mySound.setLoop(true);

	//fill shape vectors with 4 random 
	for (int i = 0; i < 4; i++) {
		circle_vector_.push_back(circle_shape());
		poly_vector_.push_back(polygon_shape());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (cur_state_ == RUNNING || cur_state_ == INFO_RUNNING) {
		position_ms_ = mySound.getPositionMS();
		//calculate cur_vol_ as sum of floats in spectrum
		cur_vol_ = 0.0f;
		float * output = ofSoundGetSpectrum(num_bands_);
		int max_pitch_ = 0;
		for (int i = 0; i < num_bands_; i++) {
			smoothed_spec_[i] = 0.9 * smoothed_spec_[i] + 0.1 * output[i];
			cur_vol_ += output[i];
			
		}
		//keep track of the greatest volume
		if (cur_vol_ > max_vol_) {
			max_vol_ = cur_vol_;
		}
		//cur_vol changes too quickly, so adjust the smoothed_vol
		smoothed_vol_ = (0.9 * smoothed_vol_ + 0.1 * cur_vol_);
		//can't use a for-each loop because items are being modified
		for (int i = 0; i < circle_vector_.size(); i++) {
			circle_vector_[i].update(smoothed_vol_, max_vol_);
		}
		for (int i = 0; i < poly_vector_.size(); i++) {
			poly_vector_[i].update(smoothed_vol_, max_vol_);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	//draw smoothed spectrum in both corners
	ofSetColor(209, 31, 203);
	for (int i = 0; i < num_bands_; i++) {
		float strength = smoothed_spec_[i];
		float bar_width = 2 * ofGetWidth() / num_bands_;
		ofDrawRectangle((bar_width + 2) * i, 0, bar_width, ofGetHeight() * smoothed_spec_[i]);
		ofDrawRectangle(ofGetWidth() - ((bar_width + 2) * i), ofGetHeight(), bar_width, -1 * ofGetHeight() * smoothed_spec_[i]);
	}

	//draw each shape
	if (circle_vector_.size() > poly_vector_.size()) {
		for (int i = poly_vector_.size(); i < circle_vector_.size(); i++) {
			circle_vector_[i].draw();
		}
	}
	else if (poly_vector_.size() > circle_vector_.size()) {
		for (int i = circle_vector_.size(); i < poly_vector_.size(); i++) {
			poly_vector_[i].draw();
		}
	}
	for (int i = 0; i < circle_vector_.size() && i < poly_vector_.size(); i++) {
		circle_vector_[i].draw();
		poly_vector_[i].draw();
	}

	//draw info table if state is info
	if (cur_state_ == INFO_RUNNING || cur_state_ == INFO_PAUSED) {
		ofSetColor(241, 36, 94);
		stringstream message;
		message << "volume: " << fixed << setprecision(2) << mySound.getVolume();
		ofDrawBitmapString(message.str(), 50, ofGetHeight() - 170);
		message.str("");
		message << ms_to_time(position_ms_) << " / " << ms_to_time(max_position_ms_);
		ofDrawBitmapString(message.str(), 50, ofGetHeight() - 150);
		ofDrawBitmapString("i for info", 50, ofGetHeight() - 130);
		ofDrawBitmapString("p for pause", 50, ofGetHeight() - 110);
		ofDrawBitmapString("+/- for volume", 50, ofGetHeight() - 90);
		ofDrawBitmapString("u/j change circle count", 50, ofGetHeight() - 70);
		ofDrawBitmapString("y/h change polygon count", 50, ofGetHeight() - 50);
		ofDrawBitmapString("arrow keys to fast forward/rewind", 50, ofGetHeight() - 30);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//toggle paused state
	if (key == 'p') {
		switch (cur_state_)
		{
		case ofApp::RUNNING:
			cur_state_ = ofApp::PAUSED;
			mySound.setPaused(true);
			break;
		case ofApp::INFO_RUNNING:
			cur_state_ = ofApp::INFO_PAUSED;
			mySound.setPaused(true);
			break;
		case ofApp::PAUSED:
			cur_state_ = ofApp::RUNNING;
			mySound.setPaused(false);
			break;
		case ofApp::INFO_PAUSED:
			cur_state_ = ofApp::INFO_RUNNING;
			mySound.setPaused(false);
			break;
		default:
			break;
		}
	}
	//toggle info display
	if (key == 'i') {
		switch (cur_state_)
		{
		case ofApp::RUNNING:
			cur_state_ = INFO_RUNNING;
			break;
		case ofApp::INFO_RUNNING:
			cur_state_ = RUNNING;
			break;
		case ofApp::PAUSED:
			cur_state_ = INFO_PAUSED;
			break;
		case ofApp::INFO_PAUSED:
			cur_state_ = PAUSED;
			break;
		default:
			break;
		}
	}
	//change num of circles
	if (key == 'u' && circle_vector_.size() < 10) {
		circle_vector_.push_back(circle_shape());
	}
	if (key == 'j' && circle_vector_.size() > 0) {
		circle_vector_.pop_back();
	}
	//change num of polygons
	if (key == 'y' && poly_vector_.size() < 10) {
		poly_vector_.push_back(polygon_shape());
	}
	if (key == 'h' && poly_vector_.size() > 0) {
		poly_vector_.pop_back();
	}
	//decrease volume
	if (key == '-') {
		if (mySound.getVolume() > 0) {
			mySound.setVolume(mySound.getVolume() - 0.05);
		}
	}
	//increase volume
	if (key == '=') {
		if (mySound.getVolume() < 1) {
			mySound.setVolume(mySound.getVolume() + 0.05);
		}
	}
	//rewind 10 seconds
	if (key == OF_KEY_LEFT) {
		if (position_ms_ <= 10000) {
			mySound.setPositionMS(0);
		}
		else {
			mySound.setPositionMS(position_ms_ - 10000);
		}
	}
	//fast forward 10 seconds
	if (key == OF_KEY_RIGHT) {
		if (position_ms_ + 10000 < max_position_ms_) {
			mySound.setPositionMS(position_ms_ + 10000);
		}
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
