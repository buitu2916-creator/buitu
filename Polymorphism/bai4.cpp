#include <iostream>
#include <string>
using namespace std;

class MediaFile {
public:
    virtual void play() {
        cout << "Opening media file..." << endl;
    }

    virtual string getType() {
        return "Generic Media";
    }
};

class AudioFile : public MediaFile {
public:
    void play() override {
        cout << "Playing audio..." << endl;
    }

    string getType() override {
        return "Audio File";
    }
};

class VideoFile : public MediaFile {
public:
    void play() override {
        cout << "Rendering video..." << endl;
    }

    string getType() override {
        return "Video File";
    }
};

class GameFile : public MediaFile {
public:
    void play() override {
        cout << "Launching 3D engine..." << endl;
    }

    string getType() override {
        return "Game File";
    }
};

void openFile(MediaFile* file) {
    cout << "File type: " << file->getType() << endl;
    file->play();
    cout << endl;
}

int main() {
    MediaFile* files[3];

    files[0] = new AudioFile();
    files[1] = new VideoFile();
    files[2] = new GameFile();

    for (int i = 0; i < 3; i++) {
        openFile(files[i]);
    }

    for (int i = 0; i < 3; i++) {
        delete files[i];
    }

    return 0;
}
