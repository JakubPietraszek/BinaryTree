#include <iostream>
#include <cmath>
#include <vector>
class Node {
public:
	int data;
	Node* right;
	Node* left;
	Node(int data) {
		this->data = data;
		right = nullptr;
		left = nullptr;
	}
};
int maxDepth(Node* node) {
    if (node == nullptr)
        return 0;
    else {
       
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int leftMaxDepht(Node* node) {
    int depth{};
    Node* current = node;
    while (current != nullptr) {
        depth++;
        current = current->left;
    }
    return depth;
}
void printOutSpace(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
}
void printOutTree(Node* node) {

}
std::vector<std::vector<Node*>> tree;
void fillTree(Node* node) {
    int n = maxDepth(node);
    std::vector<Node*> rootNodeVector{node};
    tree.push_back(rootNodeVector);
    for(int i = 1; i < n; i++) {
        std::vector<Node*> row;
        for (int j = 0; j < pow(2, i - 1); j++) {
            if (tree[i - 1][j] != NULL) {
                row.push_back(tree[i - 1][j]->left);
                row.push_back(tree[i - 1][j]->right);
            }
        }
        tree.push_back(row);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    fillTree(root);
    for (auto i : tree) {
        for (auto j : i) {
            if (j != NULL) {
                std::cout << j->data << " ";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    


	return 0;
}