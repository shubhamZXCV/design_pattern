// adapter (structural design pattern)

#include<iostream>
#include<string.h>

using namespace std;

// target interface

class MediaPlayer{
public:
    virtual void play(const string &audioType)=0;
    virtual ~MediaPlayer(){};
};

// adaptee (existing class)
class VLCPLayer{
public:
    void playVLC(const string&fileType){
        cout << "PLaying: " << fileType << " file using VLC player" << endl;
    }
};

// Adapter
class MediaAdapter : public MediaPlayer{
private:
    VLCPLayer vlc;
public:
    void play(const string&fileType) override{
        if(fileType == "mp4"){
            vlc.playVLC(fileType);
        }else{
            cout << "Format not supported by VLC" << endl;
        }
    }
};

int main(){
    MediaPlayer * player = new MediaAdapter();

    player->play("mp4");
    player->play("mp3");

    delete player;
    return 0;
}