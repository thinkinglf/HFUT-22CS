import java.util.Scanner;

public class h1test04 {
    public static void main(String [] args)
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("请输入球的半径");
        double num=sc.nextDouble();
        double x=3.14,V;
        V=x*4/3*num*num*num;//注意输出小数
        System.out.println("球的体积是"+V);
    }
}
