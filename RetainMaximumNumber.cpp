/*
��Ŀ����
����һ��ʮ���Ƶ�������number��ѡ�������ȥ��һ�������֣�ϣ������������������ɵ����������
��������:
����Ϊ�������ݣ���һ����������number��1 �� length(number) �� 1000���ڶ�����ϣ��ȥ������������cnt 1 �� cnt < length(number)��
�������:
������������Ľ����
ʾ��1
����

325
1
���

35
*/

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string n;
	int m;
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int j;
            int tl=n.length();
			for(j=0;j<tl-1;j++){
				if(n[j]<n[j+1]){
					n.erase(n.begin()+j);
					break;
				}
			}
			if(j==tl-1){
				n.erase(n.begin()+j);
			}
		}
		cout<<n<<endl;
	}
	
	return 0;
}
