import java.util.Random;
import java.util.Vector;

class Person
{
    public int ID;//ID
    public String email;//邮箱地址
    public String name;//姓名

    Person(){}

    Person(int id,String email,String name)
    {//获取Person类对象的数据
        this.ID =id;
        this.email =email;
        this.name =name;
    }

    public int getID(){//获取ID
        return ID;
    }

    public String getemail(){//获取邮箱地址
        return email;
    }

    public String getname(){//获取姓名信息
        return name;
    }

    public String toString(){//输出信息
        return ("Person类:"+"\n"+"姓名："+this.name +"\n"+"ID:"+this.ID +"\n"+"邮箱地址："+this.email);
    }
}

class Student extends Person
{//Student继承Person类
    String grade;//年级
    String m_class;//班级（注意与class区分）

    Student(){}

    Student(int id,String email,String name,String grade,String m_class)
    {//获取Student类对象的数据
        super(id,email,name);//使用super调用父类构造函数必须放在第一行(重要)
        this.grade =grade;
        this.m_class =m_class;
    }

    public String toString(){//输出信息
        return ("Student类:"+"\n"+"姓名："+this.name +"\n"+"ID:"+this.ID +"\n"+"邮箱地址："+this.email +"\n"+ grade +"年级/"+ m_class);
    }
}

class Employee extends Person
{
    Employee(){}

    Employee(int id,String email,String name){
        super(id,email,name);
    }

    public String toString(){//打印输出信息
        return ("Employee类:"+"\n"+"姓名："+this.name +"\n"+"ID:"+this.ID +"\n"+"邮箱地址："+this.email +"\n");
    }
}

class Staff extends Employee
{
    String m_work;//职务信息

    Staff(){}

    Staff(int id,String email,String name,String m_work){//职工类构造函数
        super(id,email,name);
        this.m_work=m_work;
    }

    public String toString(){//打印输出信息
        return ("Staff类:"+"\n"+"姓名："+this.name +"\n"+"ID:"+this.ID +"\n"+"邮箱地址："+this.email +"\n"+"职务信息："+m_work);
    }
}

class Faculty extends Employee
{
    String lecture;//主讲课程
    String subject;//专业信息

    Faculty(){}

    Faculty(int id,String email,String name,String lecture,String subject){
        super(id,email,name);
        this.lecture =lecture;
        this.subject =subject;
    }

    public String toString(){//打印输出信息
        return  ("Faculty类:"+"\n"+"姓名："+this.name +"\n"+"ID:"+this.ID +"\n"+"邮箱地址："+this.email +"\n"+"主讲课程:"+ lecture +"专业信息:"+ subject);
    }
}

public class h2test02
{
    public static void main(String args[])
    {
        Vector<Person>people=new Vector<Person>();//名称为people的vector容器

        for(int i=0;i<5;i++)
        {
            int IDrandom=(int)(Math.random()*10000+10086);//随机生成指定范围ID
            int gradeRandom=(int)(Math.random()*4+1);//随机生成年级
            int classRandom=(int)(Math.random()*5+1);//随机生成班级

            //临时变量
            String grade;//年级
            String m_class;//班级

            if(gradeRandom==1)
                grade="大一";
            else if(gradeRandom==2)
                grade="大二";
            else if(gradeRandom==3)
                grade="大三";
            else
                grade="大四";

            if(classRandom==1)
                m_class="一班";
            else if(classRandom==2)
                m_class="二班";
            else if(classRandom==3)
                m_class="三班";
            else if(classRandom==4)
                m_class="四班";
            else
                m_class="五班";

            Random ra = new Random();//产生不同类的人

            switch(ra.nextInt(3))
            {//生成随机类
                case 0:people.add (new Staff(IDrandom,"职工@163.com","职工","职员"));break;
                case 1:people.add (new Student(IDrandom,"学生@163.com","学生",grade,m_class));break;
                case 2:people.add (new Faculty(IDrandom,"教师@163.com","教师","java ","计算机科学与技术"));break;
            }
        }

        for(int j=0;j<people.size();j++){
            System.out.println(people.get(j).toString()+"\n");//toString打印输出
        }
    }
}