class DNode{
    public:
        float data;
        DNode* next;
        DNode* prev;

        DNode(float inData=0){
            data = inData;
            next = nullptr;
            prev = nullptr;
        }

};

class DLList{
    public:
        DNode* head;
        DNode* tail;

        DLList(){
            head = nullptr;
            tail = nullptr;
        }
};