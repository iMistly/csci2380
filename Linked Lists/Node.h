class Node{
    public:
        float value;
        Node* next;

        Node(float inValue){
            value = inValue;
            next = nullptr;
        }
};