#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;  
  
//huffman tree�ڵ㶨��  
typedef struct  
{  
    int weight;                 //����Ȩֵ  
    int parent, lchild, rchild; //�������Һ��ӵĽڵ�ֵ  
}HuffmanNode, *HuffmanTree;  
  
typedef char **HuffmanCode;  

void HuffmanCoding(HuffmanTree &HT, int *w, int n); //Huffman���뺯��  
void select(HuffmanTree HT,int n, int &s1, int &s2);//ѡ�����нڵ�ֵ��С�������ڵ�  
void Error(char* message);      //��ʾ������Ϣ  

int w[] = {2, 5, 7, 4}; //���ڵ�Ȩֵ  

int main(int argc, char* argv[])  
{  
    HuffmanTree HT;
    HuffmanCoding(HT, w, 6);
    return 0;  
}  
  
void HuffmanCoding(HuffmanTree &HT, int *w, int n)  
{
    int m = 2 * n - 1; //n nodes create huffman tree need 2n-1 nodes  
    HT = (HuffmanNode*)malloc((m + 1) * sizeof(HuffmanNode));//Huffman tree�����нڵ�  
  
    int s1, s2; //record the two mini weights nodes  
  
    memset(HT, 0, (m + 1)* sizeof(HuffmanNode));    //�����нڵ��ʼ��Ϊ-0  
    //set the n nodes  
    for (int i = 1; i <= n; i++)  
    {  
        HT[i].weight = *w++;    //��ʼ�����ڵ�Ȩֵ  
    }  
  
    //����Huffman tree  
    for(int i = n + 1; i <= m; ++i)  
    {  
        //ѡ��ʣ��ڵ���Ȩֵ��С��s1��s2  
        select(HT, i - 1, s1, s2);  
        HT[s1].parent = i;  
        HT[s2].parent = i;  
        HT[i].lchild = s1;  
        HT[i].rchild = s2;  
        HT[i].weight = HT[s1].weight + HT[s2].weight;  
    }  
  
    HuffmanCode HC;  
    int start, c, f;  
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));  
    char* cd = (char*)malloc(n * sizeof(char));  
    cd[n - 1] = '\0';  
    for(int i = 1; i <= n; ++i)  
    {  
        start = n - 1;  
        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)  
            if (HT[f].lchild == c)  
                cd[--start] = '0';  
            else  
                cd[--start] = '1';  
        HC[i] = (char*)malloc((n - start) * sizeof(char));  
        strcpy(HC[i], &cd[start]);  
    }  
  
    for (int i = 1; i <= n; i++)  
    {  
        cout<<HC[i]<<endl;  
    }
    free(cd);  
    free(HC);  
    free(HT);  
}  
  
void select(HuffmanTree HT, int n, int &s1, int &s2)
{  
    s1 = 1;  
    s2 = 1;  
    int min  = 99999;  
    int i;  
    //ѡ��δ��ʹ�õĵ�һ���ڵ㣬  
    for (i = 1; i <= n; ++i)  
    {  
        if (HT[i].parent == 0)  
        {  
            min = HT[i].weight;  
            break;  
        }  
    }  
  
    //find the mini s1  
    for (int p =  1; p <= n; ++p)  
    {  
        if(0 == HT[p].parent && min >= HT[p].weight)  
        {  
            s1 = p;  
            min = HT[p].weight;  
        }  
    }  
  
    //find the s2  
    min = 99999;  
    for (int q =  1; q <= n; ++q)  
    {  
        if(0 == HT[q].parent && min >= HT[q].weight )  
        {  
            if( q == s1)  
                continue;  
            s2 = q;  
            min = HT[q].weight;  
        }  
    }  
}  