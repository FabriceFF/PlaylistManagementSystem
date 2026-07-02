//
// Created by fabri on 19.06.2026.
#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <string>
#include <map>
#include "Playlist.h"

class PlaylistManager {
private:
    std::map<std::string, Playlist> playlists;

public:
    // Create a new playlist
    void createPlaylist(const std::string& name);

    // Delete a playlist
    void deletePlaylist(const std::string& name);

    // Get a playlist by name
    Playlist* getPlaylist(const std::string& name);

    // List all playlists
    std::string listPlaylists() const;

     void saveAll(const std::string& folderPath) const;
};

#endif // PLAYLISTMANAGER_H