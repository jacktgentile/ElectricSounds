#pragma once
#include "ofMain.h"
#include <math.h>
#include <vector>

class ofApp : public ofBaseApp{
	static string ms_to_time(int ms);
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//--------Audio variables----------------
		ofSoundPlayer mySound;
		const int num_bands_ = 512;
		float smoothed_spec_[512];
		float cur_vol_ = 0.0f;
		float smoothed_vol_ = 0.0f;
		float max_vol_ = 0.0f;
		int position_ms_ = 0;
		int max_position_ms_;

		//--------App State----------------------
		enum state {
			RUNNING = 0,
			INFO_RUNNING,
			PAUSED,
			INFO_PAUSED
		};
		state cur_state_;

		//--------Graphic Items------------------
		struct circle_shape {
			int delX, delY;
			int posX, posY;
			int radius, delRadius;
			ofColor color_ = ofColor(124, 239, 36);
			circle_shape() {
				delX = ofRandom(-5, 4);
				if (delX == 0) delX = 5;
				delY = ofRandom(-5, 4);
				if (delY == 0) delY = 5;

				posX = ofRandom(ofGetWidth());
				posY = ofRandom(ofGetHeight());

				delRadius = ofRandom(100, 200);

				color_.setHue(ofRandom(48, 68));
			}
			void draw() {
				ofSetColor(color_);
				ofDrawCircle(posX, posY, radius);
			}
			void move() {
				if (delX > 0 && posX > ofGetWidth() - radius) {
					delX *= -1;
				}
				else if (delX < 0 && posX < radius) {
					delX *= -1;
				}
				posX += delX;
				if (delY > 0 && posY > ofGetHeight() - radius) {
					delY *= -1;
				}
				else if (delY < 0 && posY < radius) {
					delY *= -1;
				}
				posY += delY;
			}
			void update(float small, float large) {
				radius = 20 + (delRadius * small / large);
				move();
			}
		};
		struct polygon_shape {
			float tau;
			int delX, delY;
			int posX, posY;
			int numSides;
			float theta;
			int radius, delRadius;
			float angle, delAngle;
			ofColor color_ = ofColor(132, 255, 38);
			polygon_shape() {
				delX = ofRandom(-5, 4);
				if (delX == 0) delX = 5;
				delY = ofRandom(-5, 4);
				if (delY == 0) delY = 5;

				posX = ofRandom(ofGetWidth());
				posY = ofRandom(ofGetHeight());

				tau = M_TWO_PI;
				numSides = ofRandom(3, 8);
				theta = tau / static_cast <float> (numSides);

				delRadius = ofRandom(100, 200);

				angle = tau * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
				delAngle = angle / 50.0;
				color_.setHue(ofRandom(48, 64));
			}
			void draw() {
				ofSetColor(color_);
				ofFill();
				ofBeginShape();
				for (int i = 0; i < numSides; i++) {
					ofVertex(posX + radius * cos(angle + theta * i), posY + radius * sin(angle + theta * i));
				}
				ofEndShape(true);
			}
			void move() {
				angle += delAngle;
				if (angle >= tau) {
					angle -= tau;
				}
				if (delX > 0 && posX > ofGetWidth() - radius) {
					delX *= -1;
				}
				else if (delX < 0 && posX < radius) {
					delX *= -1;
				}
				posX += delX;
				if (delY > 0 && posY > ofGetHeight() - radius) {
					delY *= -1;
				}
				else if (delY < 0 && posY < radius) {
					delY *= -1;
				}
				posY += delY;
			}
			void update(float small, float large) {
				radius = 30 + delRadius * (small / large);
				move();
			}
		};
		std::vector<circle_shape> circle_vector_;
		std::vector<polygon_shape> poly_vector_;
};
