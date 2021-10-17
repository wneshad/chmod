import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class StringToDate {
    public static void main(String[] args)throws Exception{
    Scanner scanner = new Scanner(System.in);
    System.out.println("enter the value of String s : ");
    String s = scanner.next();

    Date date= new SimpleDateFormat("dd/MM/yyyy").parse(s);
    System.out.println("String s is converted into Date date : " + date );

}

}
