#pragma once
#include <vector>
#include <string>
#include "user.h"
#include "message.h"

class User;
class Message;

class Conversation {
public:
    void addMessage(Message* message);
    void addUser(User* user);
    std::vector<Message*> getMessages() const;
private:
    std::vector<User*> m_participants;
    std::vector<Message*> m_messageHistory;
};