import java.util.concurrent.*;
import java.math.*;
class Prime2 implements Callable<BigDecimal>{//求完全数
    private long count=0;
    @Override//实现Callable接口可以通过get()方法获取返回值
    public synchronized BigDecimal call(){//对应的需要implements的方法有返回值，可抛出异常
        for(int i = 1;i <= 10000;i++){
            boolean isPrime = true;
            for (int j = 2; j < i; j++)
            {
                if(i % j == 0){
                    isPrime = false;
                    break;}
            }
            if(isPrime){
                count+=i;
            }
        }
        return new BigDecimal(count-1);//使用BigDecimal对象进行精确计算，详情请见java.math.BigDecimal
    }
}
@SuppressWarnings("all")
class Perfect implements Callable<BigDecimal>{//求完全数
    @Override
    public synchronized BigDecimal call(){
        long count_perfect=0;
        for(int temp=1;temp<=10000;temp++){
            long factor=0;
            for(int temp1=1;temp1<=temp/2+1;temp1++){
                if(temp%temp1==0){
                    factor+=temp1;
                }
            }
            if(factor==temp){
                count_perfect+=temp;
            }
        }return new BigDecimal(count_perfect-1);
    }
}
@SuppressWarnings("all")
public class h4test02{/**主函数*/
public static void main(String[] args)throws Exception {
    FutureTask<BigDecimal> fu1 = new FutureTask<BigDecimal>(new Prime2());//要先用FutureTask包装实现Callable类的对象
    FutureTask<BigDecimal> fu2 = new FutureTask<BigDecimal>(new Perfect());
    new Thread(fu1).start();
    new Thread(fu2).start();
    System.out.println(fu2.get().multiply(fu1.get()));
}
}