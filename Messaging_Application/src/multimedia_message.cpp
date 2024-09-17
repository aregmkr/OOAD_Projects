#include "../header/multimedia_message.h"

MultimediaMessage::MultimediaMessage(User* sender, Conversation* conversation, const std::string& filePath, const std::string& mediaType) : Message(sender, conversation), m_filePath{filePath}, m_mediaType{mediaType} {}


void MultimediaMessage::displayContent() const {
    std::cout << "File path -> " << m_filePath << std::endl;
    std::cout << "Media type -> " << m_mediaType << std::endl;
}

std::string MultimediaMessage::getMessageType() const {
    return "Multimedia";
}