#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> data;

    void Insert(int num)
    {
        data.push_back(num);
		int tmp=num;
		int i;
		for(i=data.size()-2;i>=0;i--){
			if(data[i]>tmp){
				data[i+1]=data[i];
			}else{
				break;
			}
		}
		data[i+1]=tmp;
    }

    double GetMedian()
    { 
		if(data.size()%2==0){
			return (data[data.size()/2]+data[data.size()/2-1])*1.0/2;
		}else{
			return data[data.size()/2];
		}
    }

};

int main(int argc, char *argv[])
{
	Solution solution;
	solution.Insert(5);
	cout<<solution.GetMedian()<<endl;

	solution.Insert(2);
	cout<<solution.GetMedian()<<endl;

	solution.Insert(3);
	cout<<solution.GetMedian()<<endl;

	solution.Insert(4);
	cout<<solution.GetMedian()<<endl;
	
	return 0;
}
