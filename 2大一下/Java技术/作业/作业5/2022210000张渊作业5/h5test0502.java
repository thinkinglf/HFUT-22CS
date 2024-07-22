/**
 * FileName: HomeWork6_5Client
 * Author:   zhangnuanxin
 * Date:     2020/10/21 16:00
 * Description:
 * 编写程序，用Socket通信机制在服务器和客户端之间传输文件
 * History:
 * <author>          <time>          <version>          <desc>
 * zhangnuanxin     2020/10/21          1.0              描述
 */

import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.net.Socket;

import com.sun.tools.javac.Main;

public class h5test0502 extends Socket
{

    private static final String SERVER_IP = "127.0.0.1"; // 服务端IP
    private static final int SERVER_PORT = 8888; // 服务端端口

    private Socket client;

    private FileInputStream fis;

    private DataOutputStream dos;


    //与服务器建立连接

    public h5test0502() throws Exception
    {
        super(SERVER_IP, SERVER_PORT);
        this.client = this;
        System.out.println("Cliect[port:" + client.getLocalPort() + "] 成功连接服务端");
    }

    //向服务器传输文件
    public void sendFile() throws Exception
    {
        try
        {
            File file = new File("C:\\test.txt");
            if(file.exists()) {
                fis = new FileInputStream(file);
                dos = new DataOutputStream(client.getOutputStream());

                // 文件名和长度
                dos.writeUTF(file.getName());
                dos.flush();
                dos.writeLong(file.length());
                dos.flush();

                // 开始传输文件
                System.out.println("======== 开始传输文件 ========");
                byte[] bytes = new byte[1024];
                int length = 0;
                long progress = 0;
                while((length = fis.read(bytes, 0, bytes.length)) != -1)
                {
                    dos.write(bytes, 0, length);
                    dos.flush();
                    progress += length;
                    System.out.print("| " + (100*progress/file.length()) + "% |");
                }
                System.out.println();
                System.out.println("======== 文件传输成功 ========");
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally
        {
            if(fis != null)
                fis.close();
            if(dos != null)
                dos.close();
            client.close();
        }
    }

    public static void main(String[] args)
    {
        try
        {
            h5test0502 client = new h5test0502(); // 启动客户端连接
            client.sendFile(); // 传输文件
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

}
