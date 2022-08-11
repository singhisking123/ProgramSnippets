#include <bits/stdc++.h>
using namespace std;
struct et
{
    public:
	char value;
	et* left, *right;
    et(char c)
    {
        value = c;
        left = right = NULL;
    }
};
bool isOperand(char x)
{
return (x >= 'a' && x <= 'z') ||
		(x >= 'A' && x <= 'Z');
}
string getInfix(char exp[])
{
	stack<string> s;

	for (int i=0; exp[i]!='\0'; i++)
	{
		// Push operands
		if (isOperand(exp[i]))
		{
		string op(1, exp[i]);
		s.push(op);
		}

		// We assume that input is
		// a valid postfix and expect
		// an operator.
		else
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push( op2 + exp[i] +
				op1 );
		}
	}

	// There must be a single element
	// in stack now which is the required
	// infix.
	return s.top();
}

//Function to construct binary tree from postorder and inorder traversals. 
et *buildTreeUtil(string in, char post[], int inStrt, int inEnd, int *index) 
{
    //base case
    if (inStrt > inEnd) return NULL;

    //picking current et from postorder traversal using postIndex
    //and decrementing postIndex.
    et *tet = new et(post[*index]);
    (*index)--;

    //if this et has no children then we return the et.
    if (inStrt == inEnd) 
    return tet;

    //else we find the index of this et in inorder traversal.
    int inIndex = search(in, inStrt, inEnd, tet->value);

    //using index in inorder traversal, we construct right and left subtrees
    //by calling the function buildTreeUtil recursively.
    tet->right = buildTreeUtil(in, post, inIndex + 1, inEnd, index);
    tet->left = buildTreeUtil(in, post, inStrt, inIndex - 1, index);

    return tet;
}

//Function to find index of a value in array.
int search(string arr, int strt, int end, char value) 
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
}

//Function to return a tree created from postorder and inoreder traversals.
et *buildTree(string in, char post[], int n)
{
    int index = n - 1;
    return buildTreeUtil(in, post, 0, n - 1, &index);
}



//function to construct expression tree
et* constructTree(char postfix[])
{
    string infix = getInfix(postfix);
    int n = infix.size();
    return buildTree(infix,postfix,n);
}