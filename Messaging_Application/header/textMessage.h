#pragma once
#include "message.h"
#include <string>

class TextMessage : public Message {
public:
    TextMessage(User* sender, Conversation* conversation, const std::string& content);
    ~TextMessage() = default;

    void displayContent() const;
    std::string getMessageType() const;
private:
    std::string m_content;
};