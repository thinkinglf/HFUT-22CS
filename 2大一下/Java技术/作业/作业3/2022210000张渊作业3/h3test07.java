import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class WindowMouse extends JFrame{
    WindowMouse(){
        setTitle("鼠标绘图");//设置窗口标题
        setBounds(100,100,450,450);//设置窗口显示位置和大小
        setVisible(true);//显示窗体
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//结束窗口所在的应用程序
        addMouseListener(new MouseAdapter(){//重写监听器
            public void mouseClicked(MouseEvent e){
                if(e.getClickCount()==1){//单击时
                    if(e.getButton()==e.BUTTON3){//单击左键时
                        Graphics g=getGraphics();
                        g.setColor(Color.green);//设置当前颜色为绿色
                        g.fillOval(e.getX(),e.getY(),60,60);//用当前颜色填充由指定矩形界定的椭圆
                    }
                    else if(e.getButton()==e.BUTTON1){//单击右键时
                        Graphics g=getGraphics();
                        g.setColor(Color.red);//设置当前颜色为红色
                        g.fillRect(e.getX(),e.getY(),60,60);//用当前颜色填写指定的矩形
                    }
                }
                else if(e.getClickCount()==2){//双击时
                    if(e.getButton()==e.BUTTON1){//双击左键时
                        repaint();//清屏
                    }
                }
            }
        });
    }
}
public class h3test07{
    public static void main(String [] args){
        new WindowMouse();
    }
}