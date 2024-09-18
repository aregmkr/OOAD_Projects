#include <iostream>
#include "./header/user.h"
#include "./header/conversation.h"
#include "./header/message.h"
#include "./header/textMessage.h"
#include "./header/multimedia_message.h"

int main() {
    std::string text;
    std::string file;
    std::string media;
   
    std::string name1;
    std::string contact1;
    std::string name2;
    std::string contact2;

    std::cout << "|Starts creating first user|\n";
    std::cout << "Enter user name -> ";
    std::getline(std::cin, name1);
    std::cout << "Enter user contact -> ";
    std::getline(std::cin, contact1);
    User user1(name1, contact1);

    std::cout << "\n|Starts creating second user|\n";
    std::cout << "Enter user name -> ";
    std::getline(std::cin, name2);
    std::cout << "Enter user contact -> ";
    std::getline(std::cin, contact2);
    User user2(name2, contact2);
    user1.createConversation(user2);
    Conversation* conversation = user1.getConversations().front();
    int action = 0;
    while(action != 4) {
        std::cout << "Send text message -> 1\nSend multimedia message -> 2\nHistory -> 3\nExit -> 4\n";
        std::cin >> action;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(action) {
            case 1: {
                std::cout << "Enter text: ";
                std::getline(std::cin, text);
                TextMessage * textM = new TextMessage(&user1, conversation, text);
                conversation->addMessage(textM);
                break;
            }
            case 2: {
                std::cout << "Enter multimedia filepath: ";
                std::getline(std::cin, file);
                std::cout << "Enter multimedia type: ";
                std::getline(std::cin, media);
                MultimediaMessage* message = new MultimediaMessage(&user1, conversation, file, media);
                conversation->addMessage(message);
                break;
            }
            case 3:
                user1.viewConversationHistory(conversation);
                break;
            default:
                break;
        }
    }
    return 0;
}
