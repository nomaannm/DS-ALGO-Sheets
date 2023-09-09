import java.util.Scanner;
public class NegativePositive {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int negative = scanner.nextInt();
        int positive = negativeToPositive(negative);

        System.out.println(positive);

    }

    private static int negativeToPositive(int num)
    {
        // the negative number must be more than single digits , for ex : - -23 , -124 ,etc
        if(num / 10 == 0) {System.out.println("This is a single digit number"); return num * -1 ;}
        else {
        num /= 10;
        num %= 10; 
        System.out.print("Second last digit with positive sign : ");  
        return num * -1 ; }

    }
    
    
}
