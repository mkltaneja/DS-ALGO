#include <iostream>
#include <vector>
#define vn vector<Node *>
#define vi vector<int>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int idx = 0;
Node *createTree(vi &arr)
{
    if (arr[idx] == -1 || idx == arr.size())
    {
        idx++;
        return NULL;
    }

    Node *node = new Node(arr[idx], NULL, NULL);
    idx++;

    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == NULL)
        return;

    string str = "";
    str += (node->left != NULL) ? to_string(node->left->data) + " <-- " : " . ";
    str += to_string(node->data);
    str += (node->right != NULL) ? " --> " + to_string(node->right->data) : " . ";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

// BASIC functions========================================================

int size(Node *node)
{
    if (node == NULL)
        return 0;
    return size(node->left) + size(node->right) + 1;
}

bool find(Node *node, int data)
{
    if (node == NULL)
        return false;

    bool res = false;

    if (node->data == data)
        return true;

    res |= find(node->left, data);
    res |= find(node->right, data);

    return res;
}

int height(Node *node)
{
    if (node == NULL)
        return -1;

    int lh = height(node->left);
    int rh = height(node->right);

    return max(lh, rh) + 1;
}

int maxvalue(Node *node)
{
    if (node == NULL)
        return -1e9;
    int lmax = maxvalue(node->left);
    int rmax = maxvalue(node->right);
    int omax = max(lmax, rmax);

    return max(omax, node->data);
}

int minvalue(Node *node)
{
    if (node == NULL)
        return 1e9;
    int lmin = minvalue(node->left);
    int rmin = minvalue(node->right);
    int omin = min(lmin, rmin);

    return min(omin, node->data);
}

// questions======================================================================================

bool isFound = false;
vn path;
vn rootToNodePath_01(Node *node, int data)
{
    if (node == NULL)
        return path;

    if (node->data == data)
        isFound = true;

    if (node->left != NULL && !isFound)
        rootToNodePath_01(node->left, data);
    if (node->right != NULL && !isFound)
        rootToNodePath_01(node->right, data);

    if (isFound)
        path.push_back(node);

    return path;
}

vn rootToNodePath_02(Node *node, int data)
{
    if (node == NULL)
        return {};

    if (node->data == data)
    {
        vn base;
        base.push_back(node);
        return base;
    }

    vn left = rootToNodePath_02(node->left, data);
    if (!left.empty())
    {
        left.push_back(node);
        return left;
    }
    vn right = rootToNodePath_02(node->right, data);
    if (!right.empty())
    {
        right.push_back(node);
        return right;
    }

    return {};
}

int LCA(Node *node, int data1, int data2)
{
    vn list1 = rootToNodePath_02(node, data1);
    vn list2 = rootToNodePath_02(node, data2);

    int lca;
    for (int i = list1.size() - 1, j = list2.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (list1[i]->data != list2[j]->data)
            break;
        lca = list1[i]->data;
    }
    return lca;
}

void kDown(int k, Node *node, Node *pnode)
{
    if (node == NULL || node == pnode)
        return;

    if (k == 0)
    {
        cout << node->data << " ";
        return;
    }

    kDown(k - 1, node->left, pnode);
    kDown(k - 1, node->right, pnode);
}

void kAway_01(int k, int data, Node *node)
{
    vn path = rootToNodePath_02(node, data);
    Node *pnode = NULL;

    for (int i = 0; i < path.size(); i++, k--)
    {
        kDown(k, path[i], pnode);
        pnode = path[i];
    }
}

int kAway_02(int k, int data, Node *node)
{
    if (node == NULL)
        return -1;

    if (node->data == data) // FINDING THAT NODE
    {
        kDown(k, node, NULL);
        return 1;
    }

    int left = kAway_02(k, data, node->left);
    if (left != -1) // WILL BE ENCOUNTERED AFTER THE NODE IS FOUND
    {
        kDown(k - left, node, node->left);
        return left + 1;
    }

    int right = kAway_02(k, data, node->right);
    if (right != -1) // WILL BE ENCOUNTERED AFTER THE NODE IS FOUND
    {
        kDown(k - right, node, node->right);
        return right + 1;
    }

    return -1;
}

int diameter_01(Node *node)
{
    if (node == NULL)
        return 0;

    int ld = diameter_01(node->left);
    int rd = diameter_01(node->right);

    int lh = height(node->left);
    int rh = height(node->right);

    return max(max(ld, rd), lh + rh + 2);
}

vi diameter_02(Node *node)  //OPTIMIZED
{
    if (node == NULL)
        return {0, -1};  //0th index is diameter and 1st index is height

    vi ld = diameter_02(node->left);
    vi rd = diameter_02(node->right);

    vi diaheight(2, 0);

    diaheight[0] = max(max(ld[0], rd[0]), ld[1] + rd[1] + 2);  //SAME AS RETURN STATEMENT OF DIAMETER
    diaheight[1] = max(ld[1],rd[1])+1;  //SAME AS RETURN STATEMENT OF HEIGHT

    return diaheight;   
}

static int maxdia = 0;
int diameter_03(Node* node)
{
    if(node == NULL)
        return -1;

    int lh = diameter_03(node->left);
    int rh = diameter_03(node->right);

    maxdia = lh+rh+2;
    return max(lh,rh)+1;
}

int main()
{
    // vi arr = {0, 1, 2, 3, 4, -1,- 1, 7, -1, -1, -1, 11, -1, -1, 14, 15, -1, -1, 18, -1, 19, -1, -1};
    vi arr = {10, 20, 30, -1, -1, 40, -1, -1, 50, 60, 80, -1, -1, -1, 70, 90, -1, 100, 110, -1, -1, 120, -1, -1, -1};

    Node *root = createTree(arr);
    // display(root);

    // cout<<"SIZE = "<<size(root)<<endl;

    // cout<<(boolalpha)<<find(root,600);

    // cout<<height(root);

    // cout<<maxvalue(root);

    // cout<<minvalue(root);

    // vn patharr = rootToNodePath_01(root, 80);
    // for (int i = 0; i < patharr.size(); i++)
    //     cout << patharr[i]->data << " ";

    // vn patharr = rootToNodePath_02(root, 80);
    // for (int i = 0; i < patharr.size(); i++)
    // {
    //     cout << patharr[i]->data << " ";
    // }

    // cout<<LCA(root,60,70);

    // kAway_01(3, 50, root);
    // kAway_02(3, 50, root);

    // cout << diameter_01(root);

    // vi dia = diameter_02(root);
    // cout<<dia[0];

    diameter_03(root);
    cout<<maxdia;
}



#include <stdio.h> 
#include <stdlib.h> 
  
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0, j = 0, k = 1;
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 