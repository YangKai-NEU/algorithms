#include <iostream>
#include <string>
using namespace std;

class BinDecimal {
public:
    string printBin(double num) {
        // write code here
        double tmp=0.5;
		string result="0.";
		while(num){
			if(num>=tmp){
				num-=tmp;
				result+='1';
			}else{
				result+='0';
			}
			tmp/=2;
		}
		if(result.length()>34){
			return "Error";
		}
		return result;
    }
};

int main(int argc, char *argv[])
{
	BinDecimal b;
	cout<<b.printBin(0.75)<<endl;
	
	return 0;
}
