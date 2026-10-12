#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    char symbol;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct
{
    char symbol;
    int length;
    char code[100];
} Code;

Node *createNode(char symbol, int frequency)
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void generateLengths(Node *root, int depth, Code codes[], int *count)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        codes[*count].symbol = root->symbol;
        codes[*count].length = depth;
        (*count)++;
        return;
    }

    generateLengths(root->left, depth + 1, codes, count);
    generateLengths(root->right, depth + 1, codes, count);
}

int compareCode(const void *a, const void *b)
{
    Code *x = (Code *)a;
    Code *y = (Code *)b;

    if (x->length != y->length)
        return x->length - y->length;

    return x->symbol - y->symbol;
}

void printCanonicalCodes(Code codes[], int n)
{
    qsort(codes, n, sizeof(Code), compareCode);

    unsigned int currentCode = 0;
    int previousLength = codes[0].length;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            currentCode = 0;
        }
        else
        {
            currentCode++;

            if (codes[i].length > previousLength)
            {
                currentCode <<=
                    (codes[i].length - previousLength);
            }
        }

        for (int j = codes[i].length - 1; j >= 0; j--)
        {
            codes[i].code[
                codes[i].length - 1 - j
            ] = ((currentCode >> j) & 1) + '0';
        }

        codes[i].code[codes[i].length] = '\0';

        previousLength = codes[i].length;
    }

    printf("\nCanonical Huffman Codebook:\n");

    printf("Symbol\tFrequency\tCode\n");

    for (int i = 0; i < n; i++)
    {
        printf("%c\t\t%d\t\t%s\n",
               codes[i].symbol,
               0,
               codes[i].code);
    }
}

int main()
{
    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    char symbols[n];
    int frequency[n];

    Node *nodes[MAX];

    printf("Enter symbol and frequency:\n");

    for (int i = 0; i < n; i++)
    {
        scanf(" %c %d",
              &symbols[i],
              &frequency[i]);

        nodes[i] =
            createNode(symbols[i], frequency[i]);
    }

    int size = n;

    while (size > 1)
    {
        int first = 0;
        int second = 1;

        if (nodes[first]->frequency >
            nodes[second]->frequency)
        {
            int temp = first;
            first = second;
            second = temp;
        }

        for (int i = 2; i < size; i++)
        {
            if (nodes[i]->frequency <
                nodes[first]->frequency)
            {
                second = first;
                first = i;
            }
            else if (nodes[i]->frequency <
                     nodes[second]->frequency)
            {
                second = i;
            }
        }

        Node *parent =
            createNode('$',
                       nodes[first]->frequency +
                       nodes[second]->frequency);

        parent->left = nodes[first];
        parent->right = nodes[second];

        if (first > second)
        {
            int temp = first;
            first = second;
            second = temp;
        }

        nodes[first] = parent;
        nodes[second] = nodes[size - 1];

        size--;
    }

    Node *root = nodes[0];

    Code codes[MAX];
    int count = 0;

    generateLengths(root, 0, codes, &count);

    printCanonicalCodes(codes, count);

    return 0;
}