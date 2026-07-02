#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "Playlist.h"

class FileHandler {
public:
    // Save playlist to a text file
    static void savePlaylist(const Playlist& playlist, const std::string& filename);

    // Load playlist from a text file
    static Playlist loadPlaylist(const std::string& filename);
};

#endif // FILEHANDLER_H
FILEHANDLER_H