//
// Created by fabri on 19.06.2026.
//
#include <iostream>
#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song {
    private:
    int duration;
    string artist;
    string title;

    public: //constructor
    Song(const int duration, const string& artist, const string& title);

    // Read the privates
    string get_artist() const;
    string get_title() const;
    int get_duration() const;

    //Convert song to readable text
    string to_string() const;
};
#endif