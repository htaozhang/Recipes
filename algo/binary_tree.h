#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

template<typename ValueType, typename Print>
class BinaryTree {
    struct Node {
        Node(const ValueType& value) : value_(value), left_(nullptr), right_(nullptr) {}
        ValueType value_;
        struct Node* left_;
        struct Node* right_;
    };

public:
    BinaryTree() {
        root_ = nullptr;
    }
    ~BinaryTree() {
        Release(root_);
    }

    virtual bool Insert(ValueType& value) = delete;
    virtual bool Delete(ValueType& value) = delete;

    bool Empty() {
        return size_ == 0;
    }

    size_t Size() {
        return size_;
    }

    size_t Deep() {
        return deep_;
    }

    void Release(Node* root) {
        if (root) {
            Release(root->left);
            Release(root->right);
            delete root;
            root = nullptr;
        }
    }

    void PreorderTraversal() {
        Print(root_);
        PreorderTraversal(root_->left);
        PreorderTraversal(root_->right_);
    }
    void InorderTraversal() {

    }
    void PostorderTraversal() {

    }

private:
    Node* root_;
    size_t size_;
    size_t deep_;
};
#endif /* BINARY_TREE_H_ */