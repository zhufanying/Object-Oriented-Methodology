public class Main
{
    public static void main(String[] args) {
        OperatorFactory factory = new OperatorFactory();
        Calculate cal;

        cal = factory.createOperator('+');
        cal.displayResult();
    }
}