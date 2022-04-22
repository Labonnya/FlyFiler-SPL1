#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_TREE_HT 100
 
struct min_heap_node {
 
    char data;
    unsigned freq;
    struct min_heap_node *left, *right;
};
 

struct min_heap {
    unsigned size;
    unsigned cap;
    struct min_heap_node** array;
};
 

struct min_heap_node* newNode(char data, unsigned freq)
{
    struct min_heap_node* temp
        = (struct min_heap_node*)malloc
(sizeof(struct min_heap_node));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 

struct min_heap* create_min_heap(unsigned cap)
 
{
 
    struct min_heap* minHeap
        = (struct min_heap*)malloc(sizeof(struct min_heap));
 
  
    minHeap->size = 0;
 
    minHeap->cap = cap;
 
    minHeap->array
        = (struct min_heap_node**)malloc(minHeap->
cap * sizeof(struct min_heap_node*));
    return minHeap;
}
 

void swap_min_heap_node(struct min_heap_node** x,
                    struct min_heap_node** y)
 
{
 
    struct min_heap_node* p = *x;
    *x = *y;
    *y= p;
}
 

void minHeapify(struct min_heap* minHeap, int index)
 
{
 
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
 
    if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != index) {
        swap_min_heap_node(&minHeap->array[smallest],
                        &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}
 

int if_Size_One(struct min_heap* minHeap)
{
 
    return (minHeap->size == 1);
}
 

struct min_heap_node* extMin(struct min_heap* minHeap)
 
{
 
    struct min_heap_node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}
 
void ins_min_heap(struct min_heap_node* minHeap,
                struct min_heap_node* min_heap_node)
 
{
 
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i && min_heap_node->freq < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = min_heap_node;
}
 

void create_min_heap(struct min_heap* minHeap)
 
{
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout<< arr[i];
 
    cout<<"\n";
}
 
int if_leaf(struct min_heap_node* root)
 
{
 
    return !(root->left) && !(root->right);
}
 

struct min_heap* create_BuildMinHeap(char data[], int freq[], int size)
 
{
 
    struct min_heap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    create_min_heap(minHeap);
 
    return minHeap;
}
 

struct min_heap_node* buildht(char data[], int freq[], int size)
 
{
    struct min_heap_node *left, *right, *top;
 
    struct min_heap* minHeap = create_BuildMinHeap(data, freq, size);
 

    while (!ifSizeOne(minHeap)) {
 
        left = extMin(minHeap);
        right = extMin(minHeap);
        
        top = newNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        ins_min_heap(minHeap, top);
    }

    return extMin(minHeap);
}
 

void printc(struct min_heap_node* root, int arr[], int top)
 
{

    if (root->left) {
 
        arr[top] = 0;
        printc(root->left, arr, top + 1);
    }
 
    if (root->right) {
 
        arr[top] = 1;
        printc(root->right, arr, top + 1);
    }
 
    if (if_Leaf(root)) {
 
        cout<< root->data <<": ";
        printArray(arr, top);
    }
}
 

void huff_code(char data[], int freq[], int size)
 
{
    
    struct min_heap_node* root
        = buildht(data, freq, size);
 
 
    int arr[MAX_TREE_HT], top = 0;
 
    printc(root, arr, top);
}
 
 
int main()
{
 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    huff_code(arr, freq, size);
 
    return 0;
}
