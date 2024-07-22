import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.*;//引入程序所要使用到的包

class MyFrame extends JFrame{
    private static final long serialVersionUID = 1L;
    JPanel p1;//面板
    Button bt1 ,bt2 ,bt3;//按钮
    JLabel l1 ,l2 ,l3 ,l4 ,l5 ,l6 ,l7 ,l8 ,l9;//标签
    JTextField t1 ,t2 ,t3 ,t4 , t5 ,t6;//文本框
    JTextArea ta1 ,ta2;//文本区
    Box boxTop;
    Box boxH;
    Box boxV1 ,boxV2 ,boxV3;
    Box boxHOne, boxHTwo ,boxHThree;
    Box boxVOne ,boxVTwo ,boxVThree ,boxVFour ,boxVFive ,boxVSix;//BoxLayout布局
    MyCommandListener listener1 ,listener2 ,listener3;//监听
    public MyFrame() {
        this.setBounds(250, 150, 780, 350);//位置及大小
        this.setTitle("学生管理界面");//窗口名称
        this.setLayout(new FlowLayout(0));//流式布局
        init1();
        init2();
        init3();//初始化
        this.setVisible(true);//是否可见
    }
    void init1() {//初始化第一部分
        //用于输入信息 及操作
        p1 = new JPanel();
        boxH = Box.createHorizontalBox();
        boxV1 = Box.createVerticalBox();
        boxHOne = Box.createHorizontalBox();
        boxHTwo = Box.createHorizontalBox();
        boxVOne = Box.createVerticalBox();
        boxVTwo = Box.createVerticalBox();
        boxVThree = Box.createVerticalBox();
        boxVFour = Box.createVerticalBox();//创建一些盒子
        l1 = new JLabel("姓名：");
        l2 = new JLabel("学号：");
        l3 = new JLabel("成绩：");
        bt1 = new Button("提交信息");
        bt2 = new Button("查询成绩");
        bt3 = new Button("清空文件");
        boxVOne.add(l1);
        boxVOne.add(l2);
        boxVOne.add(l3);
        t1 = new JTextField(10);
        t2 = new JTextField(10);
        t3 = new JTextField(10);
        boxVTwo.add(t1);
        boxVTwo.add(t2);
        boxVTwo.add(t3);
        boxHOne.add(boxVOne);
        boxHOne.add(Box.createHorizontalStrut(10));
        boxHOne.add(boxVTwo);
        boxVThree.add(bt1);
        boxVThree.add(Box.createVerticalStrut(10));
        boxVThree.add(bt2);
        boxVThree.add(Box.createVerticalStrut(10));
        boxVThree.add(bt3);
        l4 = new JLabel("状态栏");
        boxVFour.add(l4);
        l4.setAlignmentX(Component.CENTER_ALIGNMENT);//设置居中
        boxVFour.add(Box.createVerticalStrut(10));
        ta1 = new JTextArea(10,20);
        ta1.setLineWrap(true);
        boxVFour.add(ta1);
        boxHTwo.add(boxVThree);
        boxHTwo.add(Box.createHorizontalStrut(10));//设置水平距离
        boxHTwo.add(boxVFour);
        boxV1.add(boxHOne);
        boxV1.add(Box.createVerticalStrut(20));//设置竖直距离
        boxV1.add(boxHTwo);
        boxH.add(boxV1);//将他们组合起来
    }
    void init2(){//第二部分初始化
        //用于显示排名信息
        boxV2 = Box.createVerticalBox();
        l5 = new JLabel("排名");
        ta2 = new JTextArea(10,20);
        boxV2.add(l5);
        l5.setAlignmentX(Component.CENTER_ALIGNMENT);
        boxV2.add(Box.createVerticalStrut(10));//竖直距离
        boxV2.add(ta2);
        boxH.add(Box.createHorizontalStrut(50));//水平距离
        boxH.add(boxV2);
    }
    void init3() {//第三部分初始化
        //成绩汇总 和成绩情况
        boxV3 = Box.createVerticalBox();
        boxVFive = Box.createVerticalBox();
        boxVSix = Box.createVerticalBox();
        boxHThree = Box.createHorizontalBox();
        l6 = new JLabel("汇总信息");
        boxV3.add(l6);
        l6.setAlignmentX(Component.CENTER_ALIGNMENT);
        boxV3.add(Box.createVerticalStrut(10));
        l7 = new JLabel("平均分：");
        l8 = new JLabel("最大值：");
        l9 = new JLabel("最小值：");
        t4 = new JTextField(10);
        t5 = new JTextField(10);
        t6 = new JTextField(10);
        boxVFive.add(l7);
        boxVFive.add(Box.createVerticalStrut(100));
        boxVFive.add(l8);
        boxVFive.add(Box.createVerticalStrut(100));
        boxVFive.add(l9);
        boxVSix.add(t4);
        boxVSix.add(Box.createVerticalStrut(90));
        boxVSix.add(t5);
        boxVSix.add(Box.createVerticalStrut(90));
        boxVSix.add(t6);
        boxHThree.add(boxVFive);
        boxHThree.add(Box.createHorizontalStrut(10));
        boxHThree.add(boxVSix);
        boxV3.add(boxHThree);
        boxH.add(Box.createHorizontalStrut(50));
        boxH.add(boxV3);
        boxV1.setBorder(BorderFactory.createLineBorder(Color.cyan));
        boxV2.setBorder(BorderFactory.createLineBorder(Color.cyan));
        boxV3.setBorder(BorderFactory.createLineBorder(Color.cyan));
        p1.add(boxH);
        this.add(p1);
    }
    void setMyCommandListener(MyCommandListener listener1,MyCommandListener listener2,MyCommandListener listener3) {
        this.listener1 = listener1;//添加事件监听
        listener1.setJTextField(t1, t2, t3);
        listener1.setJTextArea(ta1);
        bt1.addActionListener(listener1);
        listener2.setJTextArea(ta1);
        bt3.addActionListener(listener2);
        listener3.setJTextArea1(ta1,ta2);
        listener3.setJTextField(t4, t5, t6);
        bt2.addActionListener(listener3);
    }
}

interface MyCommandListener extends ActionListener{//子接口多给出三个方法 文件 和 数据展示 以及输入信息的获取
    public void setJTextField(JTextField text1,JTextField text2,JTextField text3);
    public void setJTextArea1(JTextArea ta1, JTextArea ta2);
    public void setJTextArea(JTextArea area1);
    public void OpearationFile() throws IOException;
}

class Listen1 implements MyCommandListener{//第一个监视器
    JTextField textInput1,textInput2,textInput3;
    JTextArea textShow;
    File file1 = new File("学生信息1.txt");
    public void setJTextField(JTextField text1, JTextField text2, JTextField text3) {
        textInput1 = text1;
        textInput2 = text2;
        textInput3 = text3;
        text1.setText("");
        text2.setText("");
        text3.setText("");//用于清空文本框
    }

    public void setJTextArea(JTextArea area1) {
        textShow = area1;
    }

    public void OpearationFile() throws IOException {//对文件的操作
        boolean flag = true;
        FileWriter fw1 = new FileWriter(file1,flag);
        BufferedWriter bw = new BufferedWriter(fw1);
        bw.write(textInput1.getText());
        bw.write("  ");
        bw.write(textInput2.getText());
        bw.write("  ");
        bw.write(textInput3.getText());
        bw.newLine();//信息写入文件
        String str1 = "信息保存成功";
        textShow.append(str1);//追加
        bw.close();//关闭文件
    }

    public void actionPerformed(ActionEvent e) {//处理事件
        textShow.setText("");
        try {
            this.OpearationFile();
        } catch (IOException e1) {}
        textInput1.setText("");
        textInput2.setText("");
        textInput3.setText("");//用于清空文本框
    }

    @Override
    public void setJTextArea1(JTextArea ta1, JTextArea ta2) {
        // TODO Auto-generated method stub

    }
}

class Listen2 implements MyCommandListener{//第二个监视器
    JTextArea textShow;
    File file1 = new File("学生信息1.txt");
    public void actionPerformed(ActionEvent e) {
        textShow.setText("");
        try {
            this.OpearationFile();
        } catch (IOException e1) {}
    }

    public void setJTextField(JTextField text1, JTextField text2, JTextField text3) {

    }

    public void setJTextArea(JTextArea area1) {
        textShow = area1;
    }

    public void OpearationFile() throws IOException {//操作文件 主要用于清空文件
        FileWriter fw1 = new FileWriter(file1);
        BufferedWriter bw = new BufferedWriter(fw1);
        bw.write("");
        textShow.append("清空文件成功");
        bw.close();//关闭文件
    }

    @Override
    public void setJTextArea1(JTextArea ta1, JTextArea ta2) {
        // TODO Auto-generated method stub

    }

}

class Listen3 implements MyCommandListener{//第三个监视器
    final int MAXMEMBER = 45;
    File file1 = new File("学生信息1.txt");
    File file2 = new File("学生信息2.txt");
    JTextField textInput1,textInput2,textInput3;
    JTextArea textShow1 ,textShow2;
    String str1;
    String str[][] = new String[MAXMEMBER][3];
    String str2[] = new String[5];
    int maxx ,minn ,aver;
    public void OpearationFile() throws IOException {
        FileReader fr1 = new FileReader(file1);
        BufferedReader br1 = new BufferedReader(fr1);

        str1 =br1.readLine();
        if(str1==null) {
            textShow2.setText("");
            textInput1.setText("暂无");
            textInput2.setText("暂无");
            textInput3.setText("暂无");
            textShow2.setText("文件为空，暂无成绩信息");//文件中无数据是输出的信息
        }
        else {
            int i = 0 ,j ,k;
            int sum = 0;
            while(str1 != null) {//处理文件中的字符串
                str2 = str1.split(" ");
                str[i][0]=str2[0];
                str[i][1]=str2[2];
                str[i][2]=str2[4];
                str1 = br1.readLine();
                i++;
            }
            br1.close();
            //System.out.println(str[1][2]);
            for(j = 0;j < i;j++) {
                sum += Integer.parseInt(str[j][2]);
            }
            aver = sum/i;
            for(j = 0;j < i;j++) {
                int t = j;
                for(k = j + 1;k < i;k++) {
                    if(Integer.parseInt(str[k][2]) > Integer.parseInt(str[j][2])) {
                        t = k;
                    }
                }
                if(t != j) {
                    String temp[][] = new String[MAXMEMBER][3];
                    temp[0] = str[t];
                    str[t] = str[j];
                    str[j] = temp[0];
                }
            }//成绩排序 找出最大值以及最小值
            maxx = Integer.parseInt(str[0][2]);
            minn = Integer.parseInt(str[i-1][2]);
            FileWriter fw1 = new FileWriter(file2);
            try (BufferedWriter bw = new BufferedWriter(fw1)) {
                bw.write("");
                for(j = 0;j < i;j++) {
                    bw.write(str[j][0]);
                    bw.write("  ");
                    bw.write(str[j][1]);
                    bw.write("  ");
                    bw.write(str[j][2]);
                    bw.newLine();
                }
                bw.close();
            }//写入文件
            textShow2.setText("");
            for(j = 0;j < i;j++) {
                textShow2.append(""+(j+1));
                textShow2.append("、");
                textShow2.append(str[j][0]);
                textShow2.append("  ");
                textShow2.append(str[j][1]);
                textShow2.append("  ");
                textShow2.append(str[j][2]);
                textShow2.append("\n");
            }//排名信息
            textInput1.setText(Integer.toString(aver));
            textInput2.setText(Integer.toString(maxx));
            textInput3.setText(Integer.toString(minn));
            textShow1.append("查询成功");
            //System.out.println(aver);
            //System.out.println(maxx);
            //System.out.println(minn);
        }

    }

    public void setJTextField(JTextField text1, JTextField text2, JTextField text3) {
        textInput1 = text1;
        textInput2 = text2;
        textInput3 = text3;
    }

    public void setJTextArea(JTextArea area1) {}

    public void setJTextArea1(JTextArea area1,JTextArea area2) {
        textShow1 = area1;
        textShow2 = area2;
    }

    public void actionPerformed(ActionEvent e) {
        textShow1.setText("");
        try {
            this.OpearationFile();
        } catch (IOException e1) {}
    }

}

public class h4test05 {
    public static void main(String args[]) {
        MyFrame mf = new MyFrame();
        Listen1 listener1 = new Listen1();
        Listen2 listener2 = new Listen2();
        Listen3 listener3 = new Listen3();//创建监视器
        mf.setMyCommandListener(listener1,listener2,listener3);//添加监视器
    }
}

