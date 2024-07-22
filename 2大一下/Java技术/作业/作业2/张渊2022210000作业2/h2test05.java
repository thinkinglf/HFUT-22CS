import java.util.*;
//导入java的一个基础库（util）的全部类

public class h2test05
{
    public static void main(String [] args)
    {
        Scanner scanner = new Scanner(System.in);//读取用户输入的字符串
        System.out.print("请输入一个浮点数字符串： ");
        String input = scanner.nextLine();//读取输入的  **下一行**
        try
        {
            double num = Double.parseDouble(input);//将字符串转变为double类型
            int integer = (int) num;//***integer
            System.out.println("转换后的整数为：" + integer);
        }
        catch (NumberFormatException e) {//用于捕捉用户所写的浮点型字符串是否发生了异常
            System.out.println("输入的字符串不是一个合法的浮点数！");
        }//异常处理
    }
}
