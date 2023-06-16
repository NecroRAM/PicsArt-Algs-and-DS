leftRotate(TreeNode<T>* x)
{
	TreeNode<T>* y = x->right;
	x->right = y->left;
	if (y->left != NIL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NIL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right= y;
	y->left = x;
	x->parent = y;
}

insert(T z)
{
	y = NIL;
	x = root;
	while (x != NIL)
	{
		y = x;
		if (z->val < x->val)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NIL)
		root = z;
	else if (z->val < y->val)
		y->left = z;
	else
		y->right = z;
	z->right = z->left = NIL;
	z->color = RED;
	insertFixup();
}