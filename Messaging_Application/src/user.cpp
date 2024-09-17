#include "../header/user.h"
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
        messages[i]->displayContent();
    } 
    return conversation->getMessages();
}

std::string User::getName() const {
    return m_name;
}