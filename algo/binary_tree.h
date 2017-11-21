#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <cstddef>

namespace algo {

template<typename ValueType, typename Print>
class BinaryTree {
    enum TraversalOrder {
        kPreorder = 0,
        kInorder,
        kPostorder
    };
    
    struct Node {
        Node(const ValueType& value)
            : value_(value),
              left_(nullptr),
              right_(nullptr) {
        }
        
        ValueType value_;
        struct Node* left_;
        struct Node* right_;
    };

public:
    BinaryTree() : root_(nullptr), size_(0), deep_(0) {

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

public:
    void Traversal(TraversalOrder order) {
        switch (order) {
            case kPreorder:
                PreorderTraversal(root_);
                break;
            case kInorder:
                InorderTraversal(root_);
                break;
            case kPostorder:
                PostorderTraversal(root_);
                break;
            default:
                break;
        }
    }
    
private:
    void PreorderTraversal(Node* root) {
        if (root) {
            Print(root);
            PreorderTraversal(root->left);
            PreorderTraversal(root->right_);
        }
    }
    void InorderTraversal(Node* root) {
        if (root) {
            InorderTraversal(root->left);
            Print(root);
            InorderTraversal(root->right_);
        }
        
    }
    void PostorderTraversal(Node* root) {
        if (root) {
            PostorderTraversal(root->left);
            PostorderTraversal(root->right);
            Print(root);
        }
    }

private:
    Node* root_;
    size_t size_;
    size_t deep_;
};
    
}
#endif /* BINARY_TREE_H_ */
