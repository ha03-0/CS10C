//lab partner is Chloe Georgiou and we collaborated
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
using namespace std;

class PlaylistNode{
  public:
    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode* newNode);
    void SetNext(PlaylistNode* newPtr);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();

  private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

};
#endif
