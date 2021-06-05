//lab partner is Chloe Georgiou and we collaborated
#include <iostream>
#include <string>
using namespace std;
#include "Playlist.h"


char PrintMenu(string playlist){
  char input;
  bool repeat = true;

  while(repeat){
    cout << playlist << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;

    cin>> input;
    if(input == 'a' || input == 'd' || input == 'c' || input == 's' || input == 't' || input == 'o' || input == 'q'){
      repeat = false;
    }
    else{
      cout << "Invalid" << endl;
    }
  }
  return input;
}

int main() {
  PlaylistNode* head = 0;
  //i'm not sure if i should set it to null or to 0 because in cs10b we were told to set it to 0
  PlaylistNode* tail = 0;
  string playlist;
  char input;
  string ID;
  string newSong;
  string newArtist;
  int newLength;
  int numOfNodes = 0;

  cout << "Enter playlist's title:" << endl;
  cout << endl;
  getline(cin, playlist);
  input = PrintMenu(playlist);

  while(input != 'q'){
    if(input == 'a'){
      numOfNodes++;
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:";
      cin.ignore();
      getline(cin, ID);
      cout << endl;
      cout << "Enter song's name:";
      getline(cin, newSong);
      cout << endl;
      cout << "Enter artist's name:";
      getline(cin, newArtist);
      cout << endl;
      cout << "Enter song's length (in seconds):" << endl;
      cin >> newLength;
      cout << endl;// << endl;

      PlaylistNode* num;
      num = new PlaylistNode(ID, newSong, newArtist, newLength);
      if(head == 0){
        tail = num;
        head = num;
      }
      else{
        tail -> SetNext(num);
        tail = tail-> GetNext();
      }
    }
    if(input == 'd'){
      PlaylistNode* curr;
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:";
      cin.ignore();
      getline(cin, ID);
      cout << endl;

      if(numOfNodes == 0){}
      else if (head-> GetID() == ID){
        cout << "\"" << head->GetSongName() << "\"" << " removed." << endl << endl;
        head = head->GetNext();
        numOfNodes--;
      }
      else if (tail ->GetID() == ID){
        cout << "\"" << tail -> GetSongName() << "\"" << " removed" << endl << endl;
        PlaylistNode* newTail = head;
        PlaylistNode* deleteTail = head->GetNext();
        while (deleteTail->GetNext() != 0){
          newTail = deleteTail;
          deleteTail = deleteTail->GetNext();
        }
        delete deleteTail;
        newTail -> SetNext(0);
        tail = newTail;
        numOfNodes--;
      }
      else{
        PlaylistNode* curr = head;
        while(curr->GetNext() !=0){
          if(curr->GetNext()->GetID() == ID){
            cout << "\"" << curr-> GetNext() -> GetSongName() << "\"" << " removed." << endl << endl;
            curr -> SetNext(curr-> GetNext()->GetNext());
            numOfNodes--;
          }
          curr = curr -> GetNext();
        }
      }
    }
  if(input == 'c'){
    int count = 1;
    PlaylistNode* prev; //previous
    PlaylistNode* curr = head; // Song
    PlaylistNode* cSONG = head;  // song
    //PlaylistNode* nSONG = head;
    PlaylistNode songT; //Title
    int pos1; //cur
    int pos2; // new
    int i = 1;
    //i = 1;
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:";
      cin >> pos1;
      cout << endl;
      cout << "Enter new position for song:";
      cin >> pos2;
      cout << endl;
    if(pos2 < 1){
      pos2 = 1;
    }
    if (pos2 > numOfNodes){
      pos2 = numOfNodes;
    }
    if (pos1 == pos2 || pos1 < 1 || pos1 > numOfNodes || numOfNodes == 0){}
    else{
      while (i < pos1){
        cSONG = cSONG -> GetNext();
        i++;
      }
      ID = cSONG->GetID();
      songT = *cSONG;
      if(pos2 < 2){
        while (count != pos1){
          if(curr -> GetNext() != 0){
            prev = curr;
            curr = curr -> GetNext();
            count ++;
        }
        }
        prev -> SetNext(curr->GetNext());
        curr->SetNext(head);
        head = curr;
      }
      else if(pos1 < 2){
        if(pos2 == numOfNodes){
          tail -> SetNext(head);
          head = head -> GetNext();
          tail -> GetNext()->SetNext(0);
          tail = tail -> GetNext();
        }
        else{
          if(pos2 >= numOfNodes){
            pos2 = numOfNodes;
          }
          prev = head -> GetNext();
          curr = head;
          head = prev;
          count = 1;
          PlaylistNode* nPos = head;
          PlaylistNode* nPrev;
          while (count != pos2){
            if(nPos -> GetNext() != 0){
              nPrev = nPos;
              nPos = nPos -> GetNext();
              count++;
            }
          }
          curr -> SetNext(nPos);
          nPrev -> SetNext(curr);
        }
      }
      else if (pos2 >= numOfNodes){
        PlaylistNode* nPos = head;
        PlaylistNode* nPrev;
        count = 1;
        while (count != pos1){
          if(curr ->GetNext() != 0){
            prev = curr;
            curr = curr ->GetNext();
            count++;
          }
        }
        prev -> SetNext(curr-> GetNext());
        curr -> SetNext(0);
        tail -> SetNext(curr);
        tail = tail -> GetNext();
      }
      else{
        while(count != pos1){
          if(curr -> GetNext() != 0){
            prev = curr;
            curr = curr -> GetNext();
            count++;
          }
        }
        prev -> SetNext(curr -> GetNext());
        count = 1;
        PlaylistNode* nPos = head;
        PlaylistNode* nPrev;
        while ( count != pos2){
          if(nPos ->GetNext() != 0){
            nPrev = nPos;
            nPos = nPos -> GetNext();
            count ++;
          }
        }
        curr -> SetNext(nPos);
        nPrev->SetNext(curr);
      }
      cout << "\"" << songT.GetSongName() << "\"" << " moved to position " << pos2 << endl << endl;
      }
    }

// 3
    if (input == 's'){
      string name;
      int count = 0;
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      cin.ignore();
      getline(cin,name);
      cout<<endl;

      for(PlaylistNode* i = head; i != 0; i = i->GetNext()){
        count ++;
        if(i-> GetArtistName() == name){
          cout << count << "." << endl;
          i->PrintPlaylistNode();
          cout << endl;
        }
      }
    }
    if(input == 't'){
      int time = 0;
      for (PlaylistNode* i = head; i != 0; i = i->GetNext()){
        time += i -> GetSongLength();
      }
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      cout << "Total time: " << time << " seconds" << endl;
      cout << endl;
    }

    if (input == 'o'){
      int count = 0;
      cout << playlist << " - OUTPUT FULL PLAYLIST" << endl;
      if (head == 0){
        cout << "Playlist is empty" << endl << endl;
    }
    else{
      for(PlaylistNode* i = head; i != 0; i = i->GetNext()){
        count ++;
        cout << count << "." << endl;
        i -> PrintPlaylistNode();
        cout << endl;
      }
    }
  }
    input = PrintMenu(playlist);
  }
   return 0;
}
// }
