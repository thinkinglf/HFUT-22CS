import java.math.BigInteger;

public class h1test05 {
    public static void main(String [] args)
    {
        int i=1;//i指的是每个数(要对i进行取阶乘操作)
        BigInteger num=BigInteger.valueOf(1);//创建大数num(最终结果)
        do
        {
            BigInteger t=BigInteger.valueOf(1);//临时储存阶乘
            for(int j=1;j<=i;j++)
            {
                t=t.multiply(BigInteger.valueOf(j));
            }
            num=num.multiply(t);
            i++;
        }while(i<89);//注意循环次数不要写错
        System.out.println(num);
    }
}
