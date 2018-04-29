#pragma once
#include "Gist-master\src\Gist.h"
#include "ofMain.h"
#include <math.h>
#include <vector>

class ofApp : public ofBaseApp{

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
		ofSoundStream soundStream;
		ofSoundPlayer mySound;
		void audioIn(float * input, int bufferSize, int nChannels);
		float cur_vol_ = 0.0;
		float smoothed_vol_ = 0.0;
		float max_vol_ = 0.0;

		//--------App State----------------------
		enum state {
			RUNNING = 0,
			PAUSED
		};
		state cur_state_;

		//--------Graphic Items------------------
		struct circle_shape {
			int delX, delY;
			int posX, posY;
			int radius, delRadius;
			int c_red, c_green, c_blue;
			circle_shape() {
				delX = rand() % 10 - 5;
				if (delX == 0) delX = 5;
				delY = rand() % 10 - 5;
				if (delY == 0) delY = 5;

				posX = rand() % ofGetWidth();
				posY = rand() % ofGetHeight();

				delRadius = 100 + (rand() % 300);

				c_red = 128 + rand() % 128;
				c_green = 128 + rand() % 128;
				c_blue = 128 + rand() % 128;
			}
			void draw() {
				ofSetColor(c_red, c_green, c_blue);
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
			int c_red, c_green, c_blue;
			polygon_shape() {
				tau = 2 * M_PI;
				delX = rand() % 10 - 5;
				if (delX == 0) delX = 5;
				delY = rand() % 10 - 5;
				if (delY == 0) delY = 5;
				posX = rand() % ofGetWidth();
				posY = rand() % ofGetHeight();
				numSides = 3 + rand() % 6;
				theta = tau / static_cast <float> (numSides);
				delRadius = 100 + (rand() % 300);
				angle = M_PI_2 * (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
				delAngle = angle / 12.0;
				c_red = 128 + rand() % 128;
				c_green = 128 + rand() % 128;
				c_blue = 128 + rand() % 128;
			}
			void draw() {
				ofSetColor(c_red, c_green, c_blue);
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
