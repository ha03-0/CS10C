//lab partner is Chloe Georgiou and we collaborated
#include <iostream>
using namespace std;

#include "Playlist.h"
  PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
  }

  PlaylistNode::PlaylistNode(string ID , string songN, string artistN, int songL){
    uniqueID = ID;
    songName = songN;
    artistName = artistN;
    songLength = songL;
    nextNodePtr = 0;
  }

  void PlaylistNode::InsertAfter(PlaylistNode* newNode){
    newNode -> SetNext(nextNodePtr);
    nextNodePtr = newNode;
  }

  void PlaylistNode::SetNext(PlaylistNode* newPtr){
    nextNodePtr = newPtr;
  }

  string PlaylistNode::GetID() const{
    return this-> uniqueID;
  }
  string PlaylistNode::GetSongName() const{
    return this->songName;
  }

  string PlaylistNode::GetArtistName()const{
    return this->artistName;
  }

  int PlaylistNode::GetSongLength()const{
    return this->songLength;
  }

  PlaylistNode* PlaylistNode::GetNext()const{
    return this-> nextNodePtr;
  }

void PlaylistNode::PrintPlaylistNode(){
  cout << "Unique ID: " << GetID() << endl;
  cout << "Song Name: " << GetSongName() << endl;
  cout << "Artist Name: " << GetArtistName() << endl;
  cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
