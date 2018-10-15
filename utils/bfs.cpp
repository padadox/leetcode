queue<TreeNode*> q;
queue<int> level;
q.push(root);
level.push(0);

while(!q.empty()) {
    TreeNode* p = q.front();
    int lvl = level.front();
    q.pop();
    level.pop();

    lvl++;

    if(p->left != NULL) {
        if(lvl == n) {
            ans.push_back(p->left->val);
        }
        else {
            q.push(p->left);
            level.push(lvl);
        }
    }

    if(p->right != NULL) {
        if(lvl == n) {
            ans.push_back(p->right->val);
        }
        else {
            q.push(p->right);
            level.push(lvl);
        }
    }
}
