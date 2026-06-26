#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"

class Playlist {
private:
    std::string name;
    std::vector<Song> songs;

public:
    Playlist(const std::string& name);

    void addSong(const Song& song);
    void removeSong(int index);

    std::string getName() const;
    const std::vector<Song>& getSongs() const;

    int getTotalDuration() const;
    void shuffle();
    void sortByTitle();
    void sortByArtist();

    std::string toString() const;
};

#endif // PLAYLIST_H
