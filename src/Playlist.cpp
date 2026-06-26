//
// Created by fabri on 19.06.2026.
#include "Playlist.h"
#include <algorithm>
#include <sstream>
#include <random>

using namespace std;

Playlist::Playlist(const std::string &name) : name(name) {}

void Playlist::addSong(const Song &song) {
    songs.push_back(song);
}
void Playlist::removeSong(int index) {
    if (index >= 0 && index < songs.size()) {
        songs.erase(songs.begin() + index);
    }
}
 std::string Playlist::getName() const {
     return name;
 }
 const vector<Song> &Playlist::getSongs() const {
    return songs;
}
int Playlist::getTotalDuration() const {
    int total = 0;
    for (const auto& s : songs) {
        total += s.getDuration();
    }
    return total;
}
void Playlist::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(songs.begin(), songs.end(), g);
}
void Playlist::sortByTitle() {
    std::sort(songs.begin(), songs.end(),
              [](const Song& a, const Song& b) {
                  return a.getTitle() < b.getTitle();
              });
}
void Playlist::sortByArtist() {
    std::sort(songs.begin(), songs.end(),
              [](const Song& a, const Song& b) {
                  return a.getArtist() < b.getArtist();
              });
}
    std::string Playlist::toString() const {
        std::stringstream ss;
        ss << "Playlist: " << name << "\n";

        for (int i = 0; i < songs.size(); i++) {
            ss << i << ". " << songs[i].toString() << "\n";
        }

        ss << "Total duration: " << getTotalDuration() << " seconds\n";
        return ss.str();
    }






