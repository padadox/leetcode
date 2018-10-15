stack<int> flag;
stack<TreeNode*> s;
s.push(root);
flag.push(0);
while(!s.empty()) {
    TreeNode* p = s.top();
    auto &cur_flag = flag.top();
    flag.pop();
    if(0 == cur_flag) {
        flag.push(1);
        if(root->left != NULL) {
            s.push(root->left);
            flag.push(0);
            if(target == root->left) {
                break;
            }
        }
    }
    else if(1 == cur_flag) {
        flag.push(2);
        if(root->right != NULL) {
            s.push(root->right);
            flag.push(0);

            if(target == root->right) {
                break;
            }
        }
    }
    else {
        s.pop();
    }
}

