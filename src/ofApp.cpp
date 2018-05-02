#include "ofApp.h"
#include <iomanip>
#include <sstream>


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(0);
	ofSetFrameRate(50);
	cur_state_ = RUNNING;
	for (int i = 0; i < num_bands_; i++) {
		smoothed_spec_[i] = 0.0f;
	}

	//start the song at this file in bin/data/
	mySound.load("songs/6-inch.wav");
	mySound.setVolume(1.0);
	mySound.play();

	//fill shape vectors with 4 random 
	for (int i = 0; i < 4; i++) {
		circle_vector_.push_back(circle_shape());
		poly_vector_.push_back(polygon_shape());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (cur_state_ == RUNNING || cur_state_ == INFO_RUNNING) {
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
		ofDrawBitmapString(message.str(), 50, ofGetHeight() - 150);
		ofDrawBitmapString("i for info", 50, ofGetHeight() - 130);
		ofDrawBitmapString("p for pause", 50, ofGetHeight() - 110);
		ofDrawBitmapString("+/- for volume", 50, ofGetHeight() - 90);
		ofDrawBitmapString("u/j change circle count", 50, ofGetHeight() - 70);
		ofDrawBitmapString("y/h change polygon count", 50, ofGetHeight() - 50);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//soundStream stops in paused state since it isn't being used
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
	if (key == 'u' && circle_vector_.size() < 10) {
		circle_vector_.push_back(circle_shape());
	}
	if (key == 'j' && circle_vector_.size() > 0) {
		circle_vector_.pop_back();
	}
	if (key == 'y' && poly_vector_.size() < 10) {
		poly_vector_.push_back(polygon_shape());
	}
	if (key == 'h' && poly_vector_.size() > 0) {
		poly_vector_.pop_back();
	}
	if (key == '-') {
		if (mySound.getVolume() > 0) {
			mySound.setVolume(mySound.getVolume() - 0.05);
		}
	}
	if (key == '=') {
		if (mySound.getVolume() < 1) {
			mySound.setVolume(mySound.getVolume() + 0.05);
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
