#include <iostream>
#include "Playlist.h"

int main() {
    Playlist p("My Favorites");

    p.addSong(Song("Shape of You", "Ed Sheeran", 240));
    p.addSong(Song("Blinding Lights", "The Weeknd", 200));
    p.addSong(Song("Believer", "Imagine Dragons", 210));

    std::cout << p.toString() << std::endl;

    p.sortByTitle();
    std::cout << "\nAfter sorting by title:\n";
    std::cout << p.toString() << std::endl;

    p.shuffle();
    std::cout << "\nAfter shuffle:\n";
    std::cout << p.toString() << std::endl;

    return 0;
}
