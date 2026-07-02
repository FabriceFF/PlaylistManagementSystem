//
// Created by fabri on 19.06.2026.
#include "FileHandler.h"
#include <fstream>
#include <sstream>

void FileHandler::savePlaylist(const Playlist& playlist, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing.");
    }

    file << playlist.getName() << "\n";

    for (const auto& song : playlist.getSongs()) {
        file << song.getTitle() << ";"
             << song.getArtist() << ";"
             << song.getDuration() << "\n";
    }

    file.close();
}

Playlist FileHandler::loadPlaylist(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading.");
    }

    std::string name;
    std::getline(file, name);

    Playlist playlist(name);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, artist, durationStr;

        std::getline(ss, title, ';');
        std::getline(ss, artist, ';');
        std::getline(ss, durationStr, ';');

        int duration = std::stoi(durationStr);

        playlist.addSong(Song(title, artist, duration));
    }

    file.close();
    return playlist;
}
