#include "textMessage.h"

TextMessage::TextMessage(User* sender, Conversation* conversation, const std::string& content) : Message(sender, conversation), m_content{content} {}


void TextMessage::displayContent() const {
    std::cout << m_content << std::endl;
}

std::string TextMessage::getMessageType() const {
    return "Text";
}