#include <iostream>
#include "User.hpp"
#include "Video.hpp"

void User::printSubscriptions() {
    Node< Video*> * first = subscriptions.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

void User::printFriends() {
    Node< User*> * first = friends.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

ostream& operator<<(ostream& out, const User & user) {
    string st = (user.status == ACTIVE) ? "active" : "suspended";
    out << "username:" << user.username << ",name:" << user.name << ",surname:" << user.surname << ",Status:" << st << endl;
    return out;
}

/* TO-DO: method implementations below */

User::User(){

    status = ACTIVE;
    LinkedList< Video* > subscriptions;
    LinkedList< User* > friends;
}
User::~User(){
    username="";
    name="";
    surname="";
    updateStatus(SUSPENDED);
    subscriptions.clear();
    friends.clear();
}

User::User(string username, string name, string surname){
    this->username=username;
    this->name=name;
    this->surname = surname;
    status = ACTIVE;

}

const string& User::getUsername() const{
    return username;
}
const string& User::getName() const{
    return name;
}
const string& User::getSurname() const{
    return surname;
}
Status User::getStatus() const{
    return status;
}

void User::updateStatus(Status st){
    status = st;
}
void User::subscribe(Video * video){
    Node<Video*>* subHead = subscriptions.getHead();
    subscriptions.insertNode(subHead,video);
}
//her birine null gorene kadar kosulu ekle
void User::unSubscribe(Video * video){
    Node<Video*> * subHead = subscriptions.getHead();
    while(subHead->getNext()->getData()->getTitle() != video->getTitle()){
      subHead = subHead->getNext();
    }
    subscriptions.deleteNode(subHead);

}
void User::addFriend(User * user){
    Node<User*> * friendHead =  friends.getHead();
    friends.insertNode(friendHead,user);
}

void User::removeFriend(User * user){
    Node<User*> * friendHead = friends.getHead();
    while(friendHead->getNext()->getData()->getUsername() != user->getUsername()){
      friendHead = friendHead->getNext();
    }
    friends.deleteNode(friendHead);

}
LinkedList<Video* > User::*getSubscriptions(){

// return     &subscriptions;
    // LinkedList<Video* > subscriptions;
}
LinkedList< User* > User::*getFriends(){
   // LinkedList<User* > friends;
}
bool User::operator==(const User & rhs) const{
  return this == &rhs;
}
