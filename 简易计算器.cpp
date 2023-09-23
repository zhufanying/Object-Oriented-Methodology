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

//�ӷ����� 
class Addition: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 + num2;
	}
};

//�������� 
class Subtraction: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 - num2;
	}
};

//�˷����� 
class Multiplication: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		return num1 * num2;
	}
};

//�������� 
class Division: public Calculate {
public:
	double disPlay(double num1,double num2) const override {
		if(num2 != 0)
			return num1 / num2;
		else{
			cout<<"���󣡳�������Ϊ0��" <<endl; 
			return 0;}
	}
};

//�����жϹ��� 
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
                cout << "��֧�ֵĲ�������" << endl;
                break;
        }
        return cal;
    }
};

// ������
void displayResult() {
    double num1, num2, result;
	    char ch;
	    bool continueCalculating = true;
	
	    OperatorFactory factory;
	
	    while (continueCalculating) {
	        system("cls");
	        cout << "������������ֵ�ͷ��ţ��ÿո�ָ�����";
	        cin >> num1 >> num2 >> ch;
	
	        Calculate* cal = factory.createOperator(ch);
	
	        if (cal != nullptr) {
	            result = cal->disPlay(num1, num2);
	            delete cal;
	            cout << num1 << " " << ch << " " << num2 << " = " << result << endl;
	        }
	
	        cout << "�Ƿ�������㣿(y/n): ";
	        char choice;
	        cin >> choice;
	        if (choice != 'y') {
	            continueCalculating = false;
	        }
	    }
}

//��� 
int main()
{
	displayResult();
	return 0;
}
