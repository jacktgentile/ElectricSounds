#pragma once
#include "Gist-master\src\Gist.h"
#include "ofMain.h"

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

		ofSoundStream soundStream;
		void audioIn(float * input, int bufferSize, int nChannels);
		float cur_vol_ = 0.0;
		float smoothed_vol_ = 0.0;
		float max_vol_ = 0.0;

		enum state {
			RUNNING = 0,
			PAUSED
		};
		state cur_state_;

		//stores a circle that moves around the screen
		struct circle_shape {
			int delX, delY;
			int posX, posY;
			int radius;
			int c_red, c_green, c_blue;
			circle_shape() {
				delX = rand() % 6 - 2;
				if (delX == 0) delX = -3;
				delY = rand() % 6 - 2;
				if (delY == 0) delY = -3;
				posX = rand() % ofGetWidth();
				posY = rand() % ofGetHeight();
				c_red = rand() % 256;
				c_green = rand() % 256;
				c_blue = rand() % 256;
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
				move();
				radius = 10 + (200 * small / large);
			}
		};
		circle_shape circle_, circle_two_;
};
