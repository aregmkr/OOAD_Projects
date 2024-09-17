#pragma once
#include "user.h"
#include "conversation.h"
#include <chrono>
#include <string>

class Conversation;
class User;

class Message {
public:
    Message(User* sender, Conversation* conversation) : m_sender(sender), m_conversation(conversation), timestamp_(std::chrono::system_clock::now()) {}
    virtual ~Message() = default;
    virtual void displayContent() const = 0;
    virtual std::string getMessageType() const = 0;
private:    
    User* m_sender;
    Conversation* m_conversation;
    std::chrono::time_point<std::chrono::system_clock> timestamp_;
};