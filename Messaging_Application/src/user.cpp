#include "../header/user.h"
#include "../header/textMessage.h"
#include "../header/multimedia_message.h"
#include <vector>

User::User(const std::string& name, const std::string& contactInfo) : m_name{name}, m_contactInfo{contactInfo} {}

User::~User() {
    for (int i = 0; i < m_conversations.size(); ++i) {
        delete m_conversations[i];
    }
    m_conversations.clear();
}

void User::createConversation(const User& user) {
    Conversation* conversation_ = new Conversation();
    conversation_->addUser(this);
    conversation_->addUser(const_cast<User *>(&user));
    m_conversations.push_back(conversation_);
    std::cout << "Conversation created.\n";
}   

std::vector<Conversation*> User::getConversations() const {
    return m_conversations;
}

void User::receiveMessage(Message* message) {
    message->displayContent();
}

void User::manageSettings() {
    int action = 0;
    std::string name;
    std::string info;
    std::cout << "User settings\n";
    std::cout << "Change user name -> 1\n";
    std::cout << "Change user contact info - > 2\n";
    std::cin >> action;
    switch(action) {
        case 1:
            std::cout << "Enter new user name: ";
            std::cin >> name;
            m_name = name;
            std::cout << "User name changed.\n";
            break;
        case 2:
            std::cout << "Enter new contect info: ";
            std::cin >> info;
            m_contactInfo = info;
            std::cout << "User contact info changed.\n";
            break;
        default:
            break;
    }
} 

void User::sendMessage(Message* Message, Conversation* conversation) {
    conversation->addMessage(Message);
    std::cout << "Message sented.\n";
}

std::vector<Message*> User::viewConversationHistory(Conversation* conversation) const {
    std::vector<Message*> messages = conversation->getMessages();
    for (int i = 0; i < messages.size(); ++i) {
        std::cout << "About message: " << std::endl;
        messages[i]->displayContent();
    } 
    return conversation->getMessages();
}

std::string User::getName() const {
    return m_name;
}

/*
void User::createChat() {
    std::string name1;
    std::string contact1;

    std::string name2;
    std::string contact2;

    std::cout << "Creating first account.\n";
    std::cout << "Enter user name: ";
    std::cin >> name1;
    std::cout << "Enter user contact info: ";
    std::cin >> contact1;
    User user1(name1, contact1);

    std::cout << "Enter second user name: ";
    std::cin >> name2;
    std::cout << "Enter second user contact info: ";
    std::cin >> contact2;
    User user2(name2, contact2);

    user1.createConversation(user2);

    Conversation* conversation = user1.getConversations().front();

    std::string message;
    TextMessage* text = new TextMessage(&user1, conversation, message);
    short action = 1;
    std::cout << "|Who whants to send|\n";
    std::cout << user1.getName() << "-> 1\n" << user2.getName() << " -> 2\n";
    switch (action)
    {
    case 1:
        std::cout << "Enter message to send from " << user1.getName() << " to " << user2.getName();
        std::cin.ignore();
        std::getline(std::cin, message);
        TextMessage* text = new TextMessage(&user1, conversation, message);
        conversation->addMessage(text);
        break;
    case 2:
        std::cout << "Enter message to send from " << user2.getName() << " to " << user1.getName();
        std::cin.ignore();
        std::getline(std::cin, message);
        TextMessage* text = new TextMessage(&user2, conversation, message);
        conversation->addMessage(text);
    default:
        break;
    }

}
*/
