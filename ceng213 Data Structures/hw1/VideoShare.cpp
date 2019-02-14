#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VideoShare.hpp"
#include "User.hpp"

using namespace std;

void VideoShare::printAllVideos() {
    videos.print();
}

void VideoShare::printAllUsers() {
    users.print();
}

/* TO-DO: method implementations below */

VideoShare::VideoShare(){
    LinkedList<User> users;
    LinkedList<Video> videos;


}
VideoShare::~VideoShare(){
    users.clear();
    videos.clear();

}
void VideoShare::createUser(const string & userName, const string & name, const string & surname){
  Node<User>* usersHead = users.getHead();
  User* newUser = new User(userName,name,surname);

  users.insertNode(usersHead,*newUser);
}
void VideoShare::loadUsers(const string & fileName){
      ifstream file;
      file.open(fileName.c_str());

      if (!file.good()){
        return;
      }
      string username, name, surname;

      while(getline(file, username ,';')){

        getline(file, name, ';');
        getline(file, surname);

        createUser(username, name, surname);
  }
}


void VideoShare::createVideo(const string & title, const string & genre){
    Node<Video>* videosHead = videos.getHead();
    Video* newVideo = new Video(title,genre);
    videos.insertNode(videosHead,*newVideo);
}
void VideoShare::loadVideos(const string & fileName){
      ifstream file;
      file.open(fileName.c_str());

      if (!file.good()){
        return;
      }
      string title, genre;

      while(getline(file, title ,';')){

        getline(file, genre);

        createVideo(title, genre);
  }
}

void VideoShare::addFriendship(const string & userName1, const string & userName2){
    Node<User>* userFirst = users.first();
    Node<User>* userSec = users.first();
    while(userFirst){

        if(userFirst->getData().getUsername()==userName1){
            while(userSec){
                if(userSec->getDataPtr()->getUsername()==userName2){
                    //User * userF = new User(userName1,userFirst->getData().getName(),userFirst->getData().getSurname());
                    userSec->getDataPtr()->addFriend(userFirst->getDataPtr());
                   // User * userS = new User(userName2,userSec->getData().getName(),userSec->getData().getSurname());
                    userFirst->getDataPtr()->addFriend(userSec->getDataPtr());
                }
                userSec=userSec->getNext();
            }
        }
        userFirst=userFirst->getNext();
    }
}
void VideoShare::removeFriendship(const string & userName1, const string & userName2){
    Node<User>* userFirst = users.first();
    Node<User>* userSec = users.first();
    while(userFirst){

        if(userFirst->getData().getUsername()==userName1){
            while(userSec){
                if(userSec->getDataPtr()->getUsername()==userName2){
                    userSec->getDataPtr()->removeFriend(userFirst->getDataPtr());
                    userFirst->getDataPtr()->removeFriend(userSec->getDataPtr());
                }
                userSec=userSec->getNext();
            }
        }
        userFirst=userFirst->getNext();
    }
}

void VideoShare::printFriendsOfUser(const string & userName){
    Node<User>* userF = users.first();
    while(userF) {
        if(userF->getData().getUsername()==userName){
            userF->getDataPtr()->printFriends();
        }
        userF= userF->getNext();
    }
}

void VideoShare::subscribe(const string & userName, const string & videoTitle){
    Node<User>* userFirst = users.first();
    Node<Video>* videoFirst = videos.first();
    while(userFirst){
        if(userFirst->getData().getUsername()==userName && userFirst->getData().getStatus()!=SUSPENDED ){
            while(videoFirst){
                if(videoFirst->getDataPtr()->getTitle()==videoTitle){
                    userFirst->getDataPtr()->subscribe(videoFirst->getDataPtr());
                }
                videoFirst=videoFirst->getNext();
            }
        }
        userFirst=userFirst->getNext();
    }
}

void VideoShare::printUserSubscriptions(const string & userName){
    Node<User>* userF = users.first();
    while(userF) {
        if(userF->getData().getUsername()==userName){
            userF->getDataPtr()->printSubscriptions();
        }
        userF= userF->getNext();
    }
}

void VideoShare::unSubscribe(const string & userName, const string & videoTitle){
    Node<User>* userFirst = users.first();
    Node<Video>* videoFirst = videos.first();
    while(userFirst){
        if(userFirst->getData().getUsername()==userName && userFirst->getData().getStatus()!=SUSPENDED ){
            while(videoFirst){
                if(videoFirst->getDataPtr()->getTitle()==videoTitle){
                    userFirst->getDataPtr()->unSubscribe(videoFirst->getDataPtr());
                }
                videoFirst=videoFirst->getNext();
            }
        }
        userFirst=userFirst->getNext();
    }
}
void VideoShare::updateUserStatus(const string & userName, Status newStatus){
    Node<User>* userFirst = users.first();
    while(userFirst){
        if(userFirst->getData().getUsername()==userName){
            userFirst->getDataPtr()->updateStatus(newStatus);
        }
        userFirst=userFirst->getNext();
    }
}

/*
void VideoShare::deleteUser(const string & userName){
   // removeFriendship() i kullan
    Node<User>* userFirst = users.first();
    while(userFirst){
        if(userFirst->getData().getUsername()==userName){
            //userFirst->getDataPtr()->getSubscriptions();
        }
        userFirst=userFirst->getNext();
    }
}
*/
