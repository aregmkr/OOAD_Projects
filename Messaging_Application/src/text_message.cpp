#include "../header/textMessage.h"
#include <ctime>
TextMessage::TextMessage(User* sender, Conversation* conversation, const std::string& content) : Message(sender, conversation), m_content{content} {}


void TextMessage::displayContent() const {
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp_);
    std::cout << m_content << std::endl;
     std::cout << "Message sented at " << std::ctime(&time); 
}

std::string TextMessage::getMessageType() const {
    return "Text";
}