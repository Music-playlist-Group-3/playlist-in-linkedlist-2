#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define the structure for a song
struct Song {
    string title;
    string artist;
    Song* next;
};

// Function to insert a song at the beginning of the playlist
void insertAtBeginning(Song*& head, const string& title, const string& artist) {
    Song* newSong = new Song{title, artist, head};
    head = newSong;
}

// Function to insert a song at the end of the playlist
void insertAtEnd(Song*& head, const string& title, const string& artist) {
    Song* newSong = new Song{title, artist, nullptr};
    if (head == nullptr) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}
// Function to insert a song at a specific position in the playlist
void insertAtPosition(Song*& head, const string& title, const string& artist, int position) {
    if (position <= 0) {
        cout << "Position must be greater than 0." << endl;
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, title, artist);
        return;
    }
    Song* newSong = new Song{title, artist, nullptr};
    Song* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        newSong->next = temp->next;
        temp->next = newSong;
    } else {
        cout << "Position out of bounds." << endl;
    }
}

// Function to delete a song from the beginning of the playlist
void deleteAtBeginning(Song*& head) {
    if (head == nullptr) {
        cout << "Playlist is empty." << endl;
        return;
    }
    Song* temp = head;
    head = head->next;
    delete temp;
}
