import java.util.Scanner;

public class h1test03 {
    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入摄氏度");
        double num=sc.nextDouble();
        double x;
        x=num*9/5+32;//注意输出小数
        System.out.println("华氏温度是"+x);
    }
}

