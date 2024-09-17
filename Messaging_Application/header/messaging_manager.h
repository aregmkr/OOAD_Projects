#pragma once
#include "message.h"
#include "conversation.h"
#include <vector>

class MessagingManager {
public:
    virtual void sendMessage(Message* message, Conversation* conversation) = 0;
    virtual void receiveMessage(Message* message) = 0;
    virtual std::vector<Message*> viewConversationHistory(Conversation* conversation) const = 0;
    virtual ~MessagingManager() = default;
};