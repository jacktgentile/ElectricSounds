#include "ofApp.h"
#include <iomanip>
#include <sstream>


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(0);
	ofSetFrameRate(50);
	cur_state_ = RUNNING;

	//start the song at this file in bin/data/
	mySound.load("songs/hold_up.wav");
	mySound.setVolume(0.8);
	mySound.play();

	//fill shape vectors with 4 random 
	for (int i = 0; i < 4; i++) {
		circle_vector_.push_back(circle_shape());
		poly_vector_.push_back(polygon_shape());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (cur_state_ == RUNNING) {
		//calculate cur_vol_ as sum of floats in spectrum
		cur_vol_ = 0.0f;
		float * input = ofSoundGetSpectrum(num_bands_);
		for (int i = 0; i < num_bands_; i++) {
			cur_vol_ += input[i];
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
	ofSetColor(255, 150, 150);
	//Display current volume values for testing
	stringstream message;
	message << "max vol: " << fixed << setprecision(2) << max_vol_;
	ofDrawBitmapString(message.str(), 20, 20);
	message.str("");
	message << "sm vol:  " << fixed << setprecision(2) << smoothed_vol_;
	ofDrawBitmapString(message.str(), 20, 40);

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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//soundStream stops in paused state since it isn't being used
	if (key == 'p' && cur_state_ == RUNNING) {
		mySound.setPaused(true);
		cur_state_ = PAUSED;
	}
	else if (key == 'p' && cur_state_ == PAUSED) {
		mySound.setPaused(false);
		cur_state_ = RUNNING;
	}
	if (key == 'u' && circle_vector_.size() < 10) {
		circle_vector_.push_back(circle_shape());
	}
	if (key == 'j' && circle_vector_.size() > 0) {
		circle_vector_.pop_back();
	}
	if (key == 'i' && poly_vector_.size() < 10) {
		poly_vector_.push_back(polygon_shape());
	}
	if (key == 'k' && poly_vector_.size() > 0) {
		poly_vector_.pop_back();
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
