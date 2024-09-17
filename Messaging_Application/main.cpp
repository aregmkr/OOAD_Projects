#include <iostream>
#include "./header/user.h"
#include "./header/conversation.h"
#include "./header/message.h"
#include "./header/textMessage.h"
#include "./header/multimedia_message.h"

int main() {
    User obj1("Bob", "1234");
    User obj2("Obama", "5678");
    obj1.createConversation(obj2);

    Conversation* conversation = obj1.getConversations().front();
    
    int action = 0;
    while (action != 4) {
        std::string line;
        std::cout << "Send message to " << obj2.getName() << ": ";
        std::getline(std::cin, line);
        if (line.empty()) continue;

        TextMessage* tmp = new TextMessage(&obj1, conversation, line);
        conversation->addMessage(tmp);
        obj1.sendMessage(tmp, conversation);
        obj2.receiveMessage(tmp);

        ++action;
    }
    
    obj1.viewConversationHistory(conversation);
    return 0;
}
