
import java.util.Scanner;


abstract class Calculate {
    protected double num1;
    protected double num2;

    public abstract double disPlay(double num1, double num2);

    public void displayResult() {
        Scanner scanner = new Scanner(System.in);
        char choice;

        do {
            System.out.print("请输入两个数值和符号（用空格分隔）：");
            num1 = scanner.nextDouble();
            num2 = scanner.nextDouble();
            char ch = scanner.next().charAt(0);

            double result = disPlay(num1, num2);
            System.out.println(num1 + " " + ch + " " + num2 + " = " + result);

            System.out.print("是否继续计算？(y/n): ");
            choice = scanner.next().charAt(0);
        } while (choice == 'y');
    }
}

class Addition extends Calculate {
    @Override
    public double disPlay(double num1, double num2) {
        return num1 + num2;
    }
}

class Subtraction extends Calculate {
    @Override
    public double disPlay(double num1, double num2) {
        return num1 - num2;
    }
}

class Multiplication extends Calculate {
    @Override
    public double disPlay(double num1, double num2) {
        return num1 * num2;
    }
}

class Division extends Calculate {
    @Override
    public double disPlay(double num1, double num2) {
        if (num2 != 0)
            return num1 / num2;
        else {
            System.out.println("错误！除数不能为0！");
            return 0;
        }
    }
}

class OperatorFactory {
    public Calculate createOperator(char op) {
        Calculate cal = null;

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
                System.out.println("不支持的操作符！");
                break;
        }
        return cal;
    }
}

