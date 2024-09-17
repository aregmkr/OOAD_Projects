#pragma once
#include <iostream>
#include <vector>
//#include "conversaiton.h"
#include "message.h"
#include "messaging_manager.h"

class Conversation;

class User : public MessagingManager{
public:
    User(const std::string& name, const std::string& contactInfo);
    User(const User&) = delete;
    User(User&&) = delete;
    User& operator=(const User&) = delete;
    User& operator=(User&&) = delete;
    ~User();

    void createConversation(const User& user);
    void manageSettings();
    std::vector<Conversation*> getConversations() const;
    std::vector<Message*> viewConversationHistory(Conversation* conversation) const override;
    void sendMessage(Message* message, Conversation* conversation) override;
    void receiveMessage(Message* message) override;
    std::string getName() const;
private:
    std::string m_name;
    std::string m_contactInfo;
    std::vector<Conversation*> m_conversations;
};