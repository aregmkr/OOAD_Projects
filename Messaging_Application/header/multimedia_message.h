#pragma once
#include "message.h"
#include <string>

class MultimediaMessage : public Message {
public:
    MultimediaMessage(User* sender, Conversation* conversation, const std::string& filePath, const std::string& mediaType);
    ~MultimediaMessage() = default;

    void displayContent() const;
    std::string getMessageType() const;
private:
    std::string m_filePath;
    std::string m_mediaType;
};