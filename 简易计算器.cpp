#include <iostream>
#include <string>

using namespace std;

class Calculate {
protected:
	double num1;
	double num2;
public:
	virtual ~Calculate(){} 
	virtual double disPlay(double num1,double num2) const = 0;
	void displayResult(); 
}; 

//加法操作 
class Addition: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 + num2;
	}
};

//减法操作 
class Subtraction: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 - num2;
	}
};

//乘法操作 
class Multiplication: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 * num2;
	}
};

//除法操作 
class Division: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		if(num2 != 0)
			return num1 / num2;
		else{
			cout<<"错误！除数不能为0！" <<endl; 
			return 0;}
	}
};

//符号判断工厂 
class OperatorFactory{
public:
	Calculate* createOperator(char op) {
        Calculate* cal = nullptr;

        switch (op) {
            case '+':
                cal = new Addition();
                break;
            case '-':
                cal = new Subtraction();
                break;
            case '*':
                cal = new Multiplication();
                break;
            case '/':
                cal = new Division();
                break;
            default:
                cout << "不支持的操作符！" << endl;
                break;
        }
        return cal;
    }
};

// 输出结果
void displayResult() {
    double num1, num2, result;
	    char ch;
	    bool continueCalculating = true;
	
	    OperatorFactory factory;
	
	    while (continueCalculating) {
	        system("cls");
	        cout << "请输入两个数值和符号（用空格分隔）：";
	        cin >> num1 >> num2 >> ch;
	
	        Calculate* cal = factory.createOperator(ch);
	
	        if (cal != nullptr) {
	            result = cal->disPlay(num1, num2);
	            delete cal;
	            cout << num1 << " " << ch << " " << num2 << " = " << result << endl;
	        }
	
	        cout << "是否继续计算？(y/n): ";
	        char choice;
	        cin >> choice;
	        if (choice != 'y') {
	            continueCalculating = false;
	        }
	    }
}

//入口 
int main()
{
	displayResult();
	return 0;
}
