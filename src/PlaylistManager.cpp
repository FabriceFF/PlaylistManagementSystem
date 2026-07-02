#include "PlaylistManager.h"
#include <sstream>

void PlaylistManager::createPlaylist(const std::string& name) {
    playlists.emplace(name, Playlist(name));
}

void PlaylistManager::deletePlaylist(const std::string& name) {
    playlists.erase(name);
}

Playlist* PlaylistManager::getPlaylist(const std::string& name) {
    auto it = playlists.find(name);
    if (it != playlists.end()) {
        return &(it->second);
    }
    return nullptr;
}

std::string PlaylistManager::listPlaylists() const {
    std::stringstream ss;
    ss << "Playlists:\n";

    for (const auto& p : playlists) {
        ss << "- " << p.first << "\n";
    }

    return ss.str();
}
