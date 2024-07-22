/**
 * FileName: HomeWork6_4
 * Author:   zhangnuanxin
 * Date:     2020/10/21 06:00
 * Description:
 * 说明并尝试通过URL从服务器上读取一个文本文件，并显示该文本文件的内容。
 * History:
 * <author>          <time>          <version>          <desc>
 * zhangnuanxin     2020/10/21          1.0              描述
 */

import java.net.*;
import java.io.*;

public class h5test04
{
    public static void main(String args[]) throws Exception     //直接抛出异常，不做处理
    {
        URL myurl = new URL("https://mirrors6.tuna.tsinghua.edu.cn/ubuntu-releases/robots.txt");
        /*
         * 创建URL对象
         * 采用的地址为清华大学tuna开源镜像站
         * 访问方式为ipv6，速度快，连接稳定
         * txt内容为：User-Agent: *
         * Disallow: .pool
         * Disallow: /*（和左边一样的斜杠）.pool
         */

        URLConnection uc = myurl.openConnection();
        //创建连接

        InputStreamReader isr = new InputStreamReader(uc.getInputStream());
        //获取服务器端字节流

        BufferedReader in = new BufferedReader(isr);
        //读取服务器端文件

        String inputLine;
        //按行读取文件

        while ((inputLine = in.readLine()) != null)
        {
            System.out.println(inputLine);
        }
        //当读取行不为空时按行输出读取内容

        in.close();
        //关闭

    }
}
