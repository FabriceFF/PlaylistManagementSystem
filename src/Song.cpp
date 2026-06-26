#include "Song.h"
#include <sstream>

Song::Song(const std::string& title, const std::string& artist, int duration)
        : title(title), artist(artist), duration(duration) {}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getArtist() const {
    return artist;
}

int Song::getDuration() const {
    return duration;
}

std::string Song::toString() const {
    std::stringstream ss;
    ss << title << " - " << artist << " (" << duration << "s)";
    return ss.str();
}
