import javax.swing.*;
import java.awt.*;

class ShowLayout extends JFrame{
    PanelDiceLayout PanelDice;
    ShowLayout(){
        PanelDice=new PanelDiceLayout();//创建面板实例
        add(PanelDice);//将面板实例添加到窗口容器中
        setBounds(100,100,400,400);//设置窗口显示位置和大小
        setTitle("三点的骰子");//设置窗口标题
        setVisible(true);//显示窗体
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//结束窗口所在的应用程序
    }
}

class PanelDiceLayout extends JPanel{//创建内部面板
    public void paint(Graphics g){//重写paint()方法
        Graphics2D g2 = (Graphics2D)g;//将抽象父类的Graphics强制转换为子类Graphics2D
        //g2.setStroke(new BasicStroke());可设置线条粗细
        g2.setColor(Color.black);//设置当前颜色为黑色
        g2.drawRoundRect(150,100,100,100,20,20);//绘制一个概略的圆角矩形
        g2.setColor(Color.red);//设置当前颜色为红色
        g2.fillOval(170,120,20,20);//用当前颜色填充指定矩形界定的椭圆
        g2.fillOval(210,120,20,20);//
        g2.fillOval(210,160,20,20);//
        g2.fillOval(170,160,20,20);//
    }
}
public class h3test06{
    public static void main(String [] args){
        new ShowLayout();
    }
}