#include <cstdio>

struct TreeNode
{
	int l, r, val;
	bool lazy;
	TreeNode *lchild, *mchild, *rchild;
	TreeNode(int l, int r)
		: l(l),
		  r(r),
		  val(len()),
		  lazy(false),
		  lchild(nullptr),
		  mchild(nullptr),
		  rchild(nullptr)
	{
	}
	int len() { return r - l + 1; }
	void build()
	{
		int m1 = l + (r - l) / 3;
		int m2 = (m1 + r) >> 1;
		if (!lchild)
			lchild = new TreeNode(l, m1);
		if (!mchild)
			mchild = new TreeNode(m1 + 1, m2);
		if (!rchild)
			rchild = new TreeNode(m2 + 1, r);
	}
	void push_down()
	{
		if (lazy)
		{
			lchild->val  = 0;
			mchild->val  = 0;
			rchild->val  = 0;
			lazy		 = false;
			lchild->lazy = rchild->lazy = true;
		}
	}
	void push_up() { val = lchild->val + mchild->val + rchild->val; }
	void update(int L, int R)
	{
		if (L <= l && r <= R)
		{
			val  = 0;
			lazy = true;
			return;
		}
		build();
		push_down();
		if (L <= lchild->r)
			lchild->update(L, R);
		if (!(R < mchild->l || L > mchild->r))
			mchild->update(L, R);
		if (R >= rchild->l)
			rchild->update(L, R);
		push_up();
	}
	int query(int L, int R)
	{
		if (L <= l && r <= R)
			return val;
		build();
		push_down();
		int ret = 0;
		if (L <= lchild->r)
			ret += lchild->query(L, R);
		if (!(R < mchild->l || L > mchild->r))
			ret += mchild->query(L, R);
		if (R >= rchild->l)
			ret += rchild->query(L, R);
		return ret;
	}
};

int N, Q;

int main()
{
	scanf("%d %d", &N, &Q);
	TreeNode *root = new TreeNode(1, N);
	while (Q--)
	{
		int t, L, R;
		scanf("%d %d %d", &t, &L, &R);
		if (t == 1)
			root->update(L, R);
		else
			printf("%d\n", root->query(L, R));
	}
	return 0;
}
