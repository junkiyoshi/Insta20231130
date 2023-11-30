#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	float span = 0.5;
	ofColor color;

	for(int z = 0; z > -100; z -= 10){

		for (float x = -100; x <= 820; x += span) {

			for (float y = -100; y <= 820; y += span) {

				float noise_value = ofNoise(x * 0.005, y * 0.005,  ofGetFrameNum() * 0.025, z * 0.005 + ofGetFrameNum() * 0.0025);
				if ((noise_value >= 0.45 && noise_value <= 0.48) || (noise_value >= 0.52 && noise_value <= 0.55)) {

					this->mesh.addVertex(glm::vec3(x, y, z));
					this->mesh.addVertex(glm::vec3(x + span, y, z));
					this->mesh.addVertex(glm::vec3(x + span, y + span, z));
					this->mesh.addVertex(glm::vec3(x, y + span, z));

					this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 4); this->mesh.addIndex(this->mesh.getNumVertices() - 3);
					this->mesh.addIndex(this->mesh.getNumVertices() - 1); this->mesh.addIndex(this->mesh.getNumVertices() - 2); this->mesh.addIndex(this->mesh.getNumVertices() - 3);

					if ((noise_value >= 0.4 && noise_value <= 0.48)) {

						color = ofColor(ofMap(z, 0, -100, 255, 0));
					}
					else {

						color = ofColor(ofMap(z, 0, -100, 255, 0));
					}

					for (int i = 0; i < 4; i++) {

						this->mesh.addColor(color);
					}
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->mesh.draw();

	/*
	int start = 1;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}