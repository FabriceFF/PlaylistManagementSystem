#include <iostream>
#include <filesystem>
#include "PlaylistManager.h"
#include "FileHandler.h"

// Display the menu options
void showMenu() {
    std::cout << "\n===== PLAYLIST MANAGEMENT SYSTEM =====\n";
    std::cout << "1. Create playlist\n";
    std::cout << "2. Delete playlist\n";
    std::cout << "3. List playlists\n";
    std::cout << "4. Add song to playlist\n";
    std::cout << "5. Remove song from playlist\n";
    std::cout << "6. Show playlist\n";
    std::cout << "7. Shuffle playlist\n";
    std::cout << "8. Sort playlist by title\n";
    std::cout << "9. Sort playlist by artist\n";
    std::cout << "10. Save playlist\n";
    std::cout << "11. Load playlist\n";
    std::cout << "12. Save ALL playlists\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    // Ensure the folder for saving playlists exists
    std::filesystem::create_directories("data/Playlists");

    PlaylistManager manager;  // Object managing all playlists
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting program.\n";
            break;
        }

        std::string name;

        switch (choice) {

            // Create a new playlist
            case 1: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                manager.createPlaylist(name);
                std::cout << "Playlist created.\n";
                break;
            }

            // Delete a playlist
            case 2: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                manager.deletePlaylist(name);
                std::cout << "Playlist deleted.\n";
                break;
            }

            // List all playlists
            case 3: {
                std::cout << manager.listPlaylists();
                break;
            }

            // Add a song to a playlist
            case 4: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                std::string title, artist;
                int duration;

                std::cout << "Song title: ";
                std::cin >> title;
                std::cout << "Artist: ";
                std::cin >> artist;
                std::cout << "Duration (seconds): ";
                std::cin >> duration;

                p->addSong(Song(title, artist, duration));
                std::cout << "Song added.\n";
                break;
            }

            // Remove a song from a playlist
            case 5: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                int index;
                std::cout << "Enter song index to remove: ";
                std::cin >> index;

                p->removeSong(index);
                std::cout << "Song removed.\n";
                break;
            }

            // Show playlist contents
            case 6: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                std::cout << p->toString();
                break;
            }

            // Shuffle playlist
            case 7: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                p->shuffle();
                std::cout << "Playlist shuffled.\n";
                break;
            }

            // Sort playlist by title
            case 8: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                p->sortByTitle();
                std::cout << "Playlist sorted by title.\n";
                break;
            }

            // Sort playlist by artist
            case 9: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                p->sortByArtist();
                std::cout << "Playlist sorted by artist.\n";
                break;
            }

            // Save a single playlist
            case 10: {
                std::cout << "Enter playlist name: ";
                std::cin >> name;
                Playlist* p = manager.getPlaylist(name);

                if (!p) {
                    std::cout << "Playlist not found.\n";
                    break;
                }

                std::string path = "data/Playlists/" + name + ".txt";
                FileHandler::savePlaylist(*p, path);
                std::cout << "Playlist saved to " << path << "\n";
                break;
            }

            // Load a playlist from disk
            case 11: {
                std::cout << "Enter filename (without extension): ";
                std::cin >> name;

                std::string path = "data/Playlists/" + name + ".txt";

                try {
                    Playlist loaded = FileHandler::loadPlaylist(path);

                    manager.deletePlaylist(name);
                    manager.createPlaylist(name);

                    Playlist* p = manager.getPlaylist(name);
                    *p = loaded;

                    std::cout << "Playlist loaded.\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }

                break;
            }

            // Save ALL playlists
            case 12: {
                manager.saveAll("data/Playlists");
                std::cout << "All playlists saved.\n";
                break;
            }

            default:
                std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
