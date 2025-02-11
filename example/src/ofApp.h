#pragma once

#include "ofMain.h"
#include "ofxBonjour.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    ofxBonjourBrowser browser;
    ofxBonjourPublisher publisher;
    
    class NotificationReceiver : public ofxBonjourBrowserFoundNotificationReceiverInterface {
        static const std::string LogTag;
        
		void foundService(const std::string &type, const std::string &name, const std::string &ip, const std::string &domain, const std::uint16_t port, std::map<std::string,std::string> txt) override {
            ofLogVerbose(LogTag) << "Found Device: " << type << ", " << name << "@" << ip << " in " << domain;
        }
    } receiver;
};
