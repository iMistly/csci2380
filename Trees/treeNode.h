class TreeNode {
    public:
        int data;
        TreeNode* right;
        TreeNode* left;

        TreeNode(int inData){
            data = inData;
            right = nullptr;
            left = nullptr;
        }
};

// If a value does not exist in the tree, place it on the right
// If a value does exist in the tree, place it on the left
class UniqueTree{
    public:
        TreeNode* root;

        UniqueTree(TreeNode* inRoot){
            root = inRoot;
        }

        void addNode(TreeNode* newNode){
            TreeNode* current = root;
            while(current!=nullptr){
            cout << current->data << '\n';
                if(current->data == newNode->data){
                    TreeNode* tmp = current;
                    while(tmp->left!=nullptr){
                        cout << tmp->data << '\n';
                        tmp = tmp->left;
                    }
                    tmp->left = newNode;
                    cout << "Assigned left\n";
                    return;
                }
                else if(current->right == nullptr){
                    current->right = newNode;
                    cout << "Assigned right\n";
                    return;    
                }
            current = current->right;
            }
        }
};