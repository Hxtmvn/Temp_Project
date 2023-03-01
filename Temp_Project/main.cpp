#include <iostream>

class LinkedList
{
public:
    struct Node
    {
        std::string data;
        Node* next;
    };
    
    static void insertLeft(Node** head, std::string data)
    {
        Node* tmp_obj = (LinkedList::Node*)malloc(sizeof(LinkedList::Node));
        tmp_obj->data = data;
        
        tmp_obj->next = *head;
        *head = tmp_obj;
    }

    static void insertRight(Node** head, std::string data)
    {
        Node* iterator = *head;
        Node* tmp_obj = (LinkedList::Node*)malloc(sizeof(LinkedList::Node));
        tmp_obj->data = data;
        
        if(iterator != NULL)
        {
            while(iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = tmp_obj;
            tmp_obj->next = NULL;
        }
        else
        {
            *head = tmp_obj;
            tmp_obj->next = NULL;
        }
        return;
    }

    static void insertByIndex(Node* head, std::string data, int index)
    {
        Node* tmp_obj = (LinkedList::Node*)malloc(sizeof(LinkedList::Node));
        tmp_obj->data = data;
        
        tmp_obj->next = findByIndex(head, index);
        findByIndex(head, index-1)->next = tmp_obj;
        
        return;
    }

    static Node* findByVaule(Node* head, std::string data)
    {
        Node* iterator = head;
        if(iterator != NULL)
        {
            do
            {
                if(iterator->data == data)
                {
                    return iterator;
                }
                else
                {
                    iterator = iterator->next;
                }
            } while(iterator->next != NULL);
        }
        
        return NULL;
    }

    static Node* findByIndex(Node* head, int index)
    {
        Node* iterator = head;
        if(iterator != NULL)
        {
            for(int i = 0; i < index; i++)
            {
                iterator = iterator->next;
            }
            return iterator;
        }
        return NULL;
    }
    
    static void printTheList(Node* head)
    {
        LinkedList::Node* iterator = head;
        while(iterator != NULL)
        {
            std::cout << iterator->data << std::endl;
            iterator = iterator->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    LinkedList::Node* head = NULL;
    
    LinkedList::insertRight(&head, "first_object");
    LinkedList::insertRight(&head, "second_object");
    
    LinkedList::printTheList(head);
    
    return 0;
}
        

