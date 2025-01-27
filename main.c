#include <stdbool.h>//用于bool类型变量和bool函数
#include <stdio.h>//标准输入输出流
// #include <stdlib.h>
// #include <conio.h>
#include <float.h>//输入限制
// #include <windows.h>
#include <limits.h>//输入限制
#include <math.h>//计算指数
#include <stdlib.h>//结构体等等
//以上为头文件
#define PI 3.14159265
#define MAX_SIZE 4 // 最大节点数
#define FILE_NAME "D:\\my.txt"
//以上为宏定义
struct sta_node
{//此处声明了一个静态链表
    int data;    // 数据域
    int next;    // 指针域
}list[MAX_SIZE];
struct node
{//此处是动态链表
    int data;
    struct node *next;
};
struct student
{//这个跟链表没关系
    int id;
    char name[50];
    short score;
}student[10];
//以上为结构体声明
short choose_output(void);
short arithmetic(short n);
void clear_stdin(void);
void lf_input(double *n);
void llu_input(unsigned long long int *n);
void hd_input(short *n);
void d_input(int *n);
short choose(short num_of_options);
void llu_hex_oct_output(const unsigned long long int *n);
void lf_hex_oct_output(const double *n);
void num_of_digits(unsigned long long int n);
short lf_if_zero(const double *n);
unsigned long long int llu_if_zero(const unsigned long long int *n);
bool if_leap_years(const short int *year);
short convert_percent_to_grade_and_output(const short int *grade);
unsigned long long int sum_of_odd_numbers_1_to_input(const unsigned long long int *input);
unsigned long long int sum_of_even_numbers_1_to_input(const unsigned long long int *input);
void sum_of_multiples_of_3_1_to_input(const unsigned long long int *input);
unsigned long long int fisrt_divisible_by_both_3_and_5(const unsigned long long int *in1,
                                                       const unsigned long long int *in2);
const unsigned long long int *who_is_bigger(const unsigned long long int *a,
                                      const unsigned long long int *b);
void max_and_min( unsigned long long int *a, unsigned long long int *b);
void daffodil_number(void);
void bubble(unsigned long long int *arr,int n);
// void matrix_input(double **matrix);
double * matrix_create(short *r,short *c);
void matrix_Transpose(double *matrix,int row,int col);
double **allocate_2d_array(int row, int col);
void free_2d_array(double **array, int row);
short int get_the_number_of_words(void);
void initialize(int *head);
void insert(int *head, int value);
void traverse(int head);
void delete_link(struct node *head,int place);
void insert_link(struct node *head,int place,int x);
void output_link(struct node *head);
struct node* creat_link(void);
void struct_bubble(struct student arr[], const int n);
void student_create(void);
void student_sort(void);
void student_display(void);
//以上为函数原型
int main(int argc, const char * argv[])
{
    // welcome();
    short if_exit_choose = 0;
    for (;if_exit_choose!=-1;)
    {//为了让计算器能被反复调出，自由退出
        if_exit_choose=choose_output();
    }
    return 0;
}
void clear_stdin(void)
{//用于清空缓冲区
    int ch;
    // 循环读取输入流中的所有字符，直到换行符或 EOF
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        ;// 什么都不做，仅用于清空缓冲区
    }
}
//简单说一下哈，就是所有的输入都用我自己写的函数代替了，里面包含了输入检查
//原生scanf容易把自己卡死，getchar说实话太累了
void d_input(int *n)
{
    int tmp=0;
    bool is_num = true;
    goto_d:;
    is_num=scanf("%d",&tmp);
    if(!is_num || tmp>INT_MAX || tmp<INT_MIN)
    {
        printf("Incorrect input! Plz enter again.\n");
        clear_stdin();
        goto goto_d;
    }
    *n=tmp;
}
void lf_input(double *n)
{
    double tmp=0;
    bool is_num = true;
    goto_lf:;
    is_num=scanf("%lf",&tmp);
    if(!is_num || tmp>DBL_MAX || tmp<DBL_MIN)
    {
        printf("Incorrect input! Plz enter again.\n");
        clear_stdin();
        goto goto_lf;
    }
    *n=tmp;
}
void llu_input(unsigned long long int *n)
{
    unsigned long long int tmp=0;
    bool is_num = true;
    goto_lld:;
    is_num=scanf("%llu",&tmp);
    if(!is_num || tmp>ULLONG_MAX || tmp<0)
    {
        printf("Incorrect input! Plz enter again.\n");
        clear_stdin();
        goto goto_lld;
    }
    *n=tmp;
}
void hd_input(short *n)
{
    short tmp=0;
    bool is_num = true;
    goto_hd:;
    is_num=scanf("%hd",&tmp);
    if(!is_num || tmp>SHRT_MAX || tmp<SHRT_MIN)
    {
        printf("Incorrect input! Plz enter again.\n");
        clear_stdin();
        goto goto_hd;
    }
    *n=tmp;
}
short lf_if_zero(const double *n)
{
    if(*n==0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
unsigned long long int llu_if_zero(const unsigned long long int *n)
{
    if(*n==0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

short choose(short num_of_options)
{//选择部分单独写，没必要大动干戈
    short choice=0;
    bool choice_is_ok=true;
    //此处检测是否输入数字
    goto_choose:;
    choice_is_ok=scanf("%hd",&choice);
    if(!choice_is_ok || choice<1 || choice>num_of_options)
    {//此处添加检测是否在范围之内
        printf("Incorrect input! Plz enter again.\n");
        clear_stdin();
        goto goto_choose;
    }
    return choice;
}
void llu_hex_oct_output(const unsigned long long int *n)
{
    printf("Result in oct: %llo\n",*n);
    printf("Result in hex: %llX\n",*n);
}
void lf_hex_oct_output(const double *n)
{
    printf("Result(integer part) in oct: %llo\n",(long long int)*n);
    printf("Result(integer part) in hex: %llX\n",(long long int)*n);
}
short choose_output(void)
{
    for (int i=0;i<84;i++)
    {
        printf("*");
    }
    printf("\n");
    printf("*    A SMAll CALCULATOR                                                            *\n");
    printf("*                                                                                  *\n");
    short choice=0;
    // printf("\n\n");
    printf("*    Choose an option:                                                             *\n");
    printf("*    1. Addition                                                                   *\n");
    printf("*    2. Subtraction                                                                *\n");
    printf("*    3. Multiplication                                                             *\n");
    printf("*    4. Division                                                                   *\n");
    printf("*    5. Modular arithmetic                                                         *\n");
    printf("*    6. Calculate circle area                                                      *\n");
    printf("*    7. Determine the number of digits                                             *\n");
    printf("*    8. Determine the leap year                                                    *\n");
    printf("*    9. Convert percent to grade                                                   *\n");
    printf("*    10.Calculates the sum of odd numbers from 1 to the input number               *\n");
    printf("*    11.Calculates the sum of even numbers from 1 to the input number              *\n");
    printf("*    12.Calculates the sum of multiples of 3 from 1 to the input number            *\n");
    printf("*    13.Find the first number that is divisible by both 3 and 5 between A and B    *\n");
    printf("*    14.Daffodil number (Three digits only)                                        *\n");
    printf("*    15.Compare two numbers                                                        *\n");
    printf("*    16.Compare two numbers and give max and min                                   *\n");
    printf("*    17.Bubble                                                                     *\n");
    printf("*    18.Matrix transpose                                                           *\n");
    printf("*    19.Sum of the main diagonal elements (Square Matrix)                          *\n");
    printf("*    20.Get the number of words                                                    *\n");
    printf("*    21.Static linklist                                                            *\n");
    printf("*    22.Dynamic linklist                                                           *\n");
    printf("*    23.Count and sort the students                                                *\n");
    printf("*    24.Open the file and add ten to everyone's score                              *\n");
    printf("*    25.Exit                                                                       *\n");
    //前十个：
    //加/减/乘/除/取模/圆面积/数字位数/闰年/百分转A/计算从1到输入数之间的奇数和
    //11-13：
    //计算从1到输入数之间的偶数和/输出从1到输入数之间所有3的倍数/第一个即被3整除又被5整除的数
    //14-20:
    //求三位数的水仙花数/两数比大小/两数比大小/冒泡/矩阵转置/方阵求主对角线元素和/数单词个数
    //21-25:
    //静态链表/动态链表/学生结构体排序/打开文件并且操作其中的十个数/退出
    for (int i=0;i<84;i++)
    {
        printf("*");
    }
    printf("\n");
    //其实这里可以不用写那么多printf的，但是自动补全帮大忙
    choice=choose(25);
    printf("You choose %d.\n",choice);
    if (arithmetic(choice)==-1)
    {//输入不正常的情况
        return -1;
    }
}
short arithmetic(short n)
{//由于反复调用，不得已把变量都放在这里声明
    double a,b,y;
    a=b=y=0;//用于lf
    unsigned long long int c,d,z;
    c=d=z=0;//用于llu
    short int p;
    p=0;//用于hd
    unsigned long long int arr[10]={0};//用于llu[]
    double **matr={0};//用于矩阵
    int w;
    w=0;//用于d
    short int arr_score[10]={0};//用于文件的成绩操作
    switch(n)
    {
        case 1:
        {
            printf("\nNow PLUS!");
            printf("\nEnter the addend A:");
            lf_input(&a);
            printf("\nEnter the addend B:");
            lf_input(&b);
            y=a+b;
            printf("\nThe sum of the numbers A+B is:%lf\n",y);
            lf_hex_oct_output(&y);
            break;
        }
        case 2:
        {
            printf("\nNow MINUS!");
            printf("\nEnter the minuend A:");
            lf_input(&a);
            printf("\nEnter the subtrahend B:");
            lf_input(&b);
            y=a-b;
            printf("\nThe difference of the numbers A-B is:%lf\n",y);
            lf_hex_oct_output(&y);
            break;
        }
        case 3:
        {
            printf("\nNow MULTIPLE!");
            printf("\nEnter the multiplier A:");
            lf_input(&a);
            printf("\nEnter the multiplier B:");
            lf_input(&b);
            y=a*b;
            printf("\nThe product of the numbers A*B is:%lf\n",y);
            lf_hex_oct_output(&y);
            printf("\nThe index form is %E.\n",y);
            break;
        }
        case 4:
        {
            printf("\nNow DIVIDE!");
            printf("\nEnter the dividend A:");
            lf_input(&a);
            printf("\nEnter the divisor B:");
            goto_divisor_4:;
            lf_input(&b);
            if (lf_if_zero(&b))
            {
                printf("\nThe divisor cannot be a zero.\n");
                printf("Plz enter the divisor again.\n");
                goto goto_divisor_4;
            }
            y=a/b;
            printf("\nThe quotient of the numbers A/B is:%lf\n",y);
            lf_hex_oct_output(&y);
            break;
        }
        case 5:
        {
            printf("\nNow MODULAR!");
            printf("\nEnter the dividend A:");
            llu_input(&c);
            printf("\nEnter the divisor B:");
            goto_divisor_5:;
            llu_input(&d);
            if (llu_if_zero(&d))
            {
                printf("\nThe divisor cannot be a zero.\n");
                printf("Plz enter the divisor again.\n");
                goto goto_divisor_5;
            }
            z=c%d;
            printf("\nThe remainder of the numbers A%%B is:%llu\n",z);
            llu_hex_oct_output(&z);
            break;
        }
        case 6:
        {
            printf("\nNow CIRCLE AREA!");
            printf("\nEnter the circle radius:");
            lf_input(&a);
            y=PI*pow(a,2);
            printf("\nThe area of the circle is:%lf\n",y);
            lf_hex_oct_output(&y);
            printf("\nKeep two decimal places: %.2lf\n",y);
            break;
        }
        case 7:
        {
            printf("\nNow determine the number of digits!");
            printf("\nEnter the number:");
            llu_input(&c);
            num_of_digits(c);
            // printf("\nDigits: %u\n",num_of_digits(c));
            break;
        }
        case 8:
        {
            printf("\nNow determining leap years!");
            printf("\nEnter the year(AD):");
            hd_input(&p);//公元前可以计算闰年吗？
            if (if_leap_years(&p))
            {
                printf("\n%hd is leap year.\n",p);
            }
            else
            {
                printf("\n%hd is a average year.\n",p);
            }
            break;
        }
        case 9:
        {
            printf("\nNow convert from percent score to grade ratings!");
            printf("\nEnter the percent score:");
            goto_score:;
            hd_input(&p);
            if (convert_percent_to_grade_and_output(&p))
            {
                goto goto_score;
            }
            break;
        }
        case 10:
        {
            printf("\nNow calculates the sum of odd numbers "
                   "from 1 to the input number!\n");
            llu_input(&c);
            printf("The sum of odd numbers is "
                   "%llu.\n",sum_of_odd_numbers_1_to_input(&c));
            break;
        }
        case 11:
        {
            printf("\nNow calculates the sum of even numbers "
                   "from 1 to the input number!\n");
            llu_input(&c);
            printf("The sum of even numbers is "
                   "%llu.\n",sum_of_even_numbers_1_to_input(&c));
            break;
        }
        case 12:
        {
            printf("\nNow output all multiples of 3 "
                   "from 1 to the input number!\n");
            llu_input(&c);
            sum_of_multiples_of_3_1_to_input(&c);
            break;
        }
        case 13:
        {
            printf("\nNow find the first number "
                   "that is divisible by both 3 and 5!\n");
            printf("\nEnter the lower limit number:");
            llu_input(&c);
            printf("\nEnter the upper limit number:");
            llu_input(&d);
            printf("\nThe first number is %llu.\n",
                fisrt_divisible_by_both_3_and_5(&c,&d));
            break;
        }
        case 14:
        {
            printf("\nAll daffodil number:\n");
            daffodil_number();
            break;
        }
        case 15:
        {
            printf("\nNow compare two numbers!\n");
            printf("Enter a number:\n");
            llu_input(&c);
            printf("Enter another number:\n");
            llu_input(&d);
            printf("\nThe bigger is  %llu.\n",*who_is_bigger(&c,&d));
            break;
        }
        case 16:
        {
            printf("\nNow compare two numbers!\n");
            printf("Enter a number:\n");
            llu_input(&c);
            printf("Enter another number:\n");
            llu_input(&d);
            max_and_min(&c,&d);
            printf("Max is %llu, min is %llu.\n",c,d);
            break;
        }
        case 17:
        {
            printf("\nNow BUBBLE!\n");
            printf("Plz enter 10 numbers.\n");
            for(short i=0;i<10;i++)
            {
                llu_input(arr+i);
            }
            bubble(arr,10);
            for(short i=0;i<10;i++)
            {
                // llu_input(arr+i);
                printf("%7llu",arr[i]);
            }
            printf("\n");
            break;
        }
        case 18:
        {//别再玩动态分配了，头发要没了QAQ
            printf("\nNow transpose!\n");
            short row, col;
            row=col=0;
            double *p_matrix=matrix_create(&row,&col);
            if(p_matrix==NULL)
            {
                printf("\nMemory allocation failed!\n");
                break;
            }
            matrix_Transpose(p_matrix,row,col);
            printf("\n");
            free(p_matrix);
            //在我彻底搞明白怎么自己独立写这么复杂的动态分配之前
            //我不会说C语言一句好话
            break;
        }
        case 19:
        {
            printf("\nNow find the sum of main diagonal elements!\n");
            printf("Enter row and column sizes:\n");
            hd_input(&p);
            printf("Please enter your elements.\n");
            matr=allocate_2d_array(p,p);
            for(short i=0;i<p;i++)
            {
                for(short j=0;j<p;j++)
                {
                    lf_input(&matr[i][j]);
                }
            }
            for(short i=0;i<p;i++)
            {
                a+=matr[i][i];
            }
            printf("The sum of main diagonal elements is %lf.\n",a);
            free_2d_array(matr,p);
            break;
        }
        case 20:
        {
            getchar();
            printf("\nNow get the number of words!\n");
            printf("Enter sentence in a row, stop with enter.\n");
            printf("The sum is %hd\n",get_the_number_of_words());
            break;
        }
        case 21:
        {
            int sta_head; // 静态链表头指针
            initialize(&sta_head); // 初始化链表
            // 插入数据
            printf("\nNow enter your int numbers in the static linklist!\n");
            while(1)
            {
                d_input(&w);
                if(w<=0)
                {
                    break;
                }
                else
                {
                    insert(&sta_head, w);
                }
            }
            // 遍历链表
            printf("Static Linked List:\n");
            traverse(sta_head);
            break;
        }
        case 22:
        {
            struct node *head = NULL;
            int x,place;
            head=creat_link();
            output_link(head);
            printf("X! you wanna insert.-1 to exit.\n");
            d_input(&x);
            if(x==-1)
            {
                goto goto_dynamic_linklist;
            }
            printf("where you wanna insert?-1 to exit.\n");
            d_input(&place);
            insert_link(head,place,x);
            output_link(head);
            printf("where you wanna delete?-1 to exit.\n");
            d_input(&place);
            delete_link(head,place);
            output_link(head);
            goto_dynamic_linklist:;
            free(head);//你（指编译器）怎么又不叫唤内存泄漏了？
            //还是我自己想起来写的这句
            break;
        }
        case 23:
        {
            printf("\nNow count and sort the students!\n");
            student_create();
            student_sort();
            student_display();
            break;
        }
        case 24:
        {
            printf("\nNow open the file and give everyone ten points!\n");
            FILE *file;
            file = fopen(FILE_NAME, "r+");
            if (file == NULL)
            {//打不开的情况
                printf("File not found or cannot be opened.\n");
                break;
            }
            else
            {
                printf("File opened successfully.\n");
            }
            for(int i=0;i<10 && fscanf(file,"%hd",&arr_score[i])==1;i++)
            {
                // fscanf(file,"%hd",&arr_score[i]);
                printf("Score: %hd\n",arr_score[i]);
            }
            //不是，为啥要用feof()啊，有啥用吗？？？
            rewind(file);//回到文件头
            printf("Here add ten to everyone's score.\n");
            for(int i=0;i<10;i++)
            {
                fprintf(file,"%hd\n",arr_score[i]+10);
            }
            rewind(file);//回到文件头
            printf("Here's the conclusion.\n");
            for(int i=0;i<10 && fscanf(file,"%hd",&arr_score[i])==1;i++)
            {
                // fscanf(file,"%hd",&arr_score[i]);
                printf("Score: %d\n",arr_score[i]);
            }
            fclose(file);
            break;
        }
        default:
        {
            printf("\nNow EXIT!\n");
            return -1;
        }
    }
}
void num_of_digits(unsigned long long int n)
{
    unsigned long long int archive;
    archive=n;//存档一个n防止篡改元数据
    unsigned int num_of_digits=0;
    while(archive)
    {
        archive/=10;
        num_of_digits++;
    }
    short num[21]={0};//llu一共20位
    for (int i=0;i<num_of_digits;i++)
    {
        num[i]=n%10;
        //这里会报一个隐式转换警告，我不是很懂，毕竟这里不可能出现任何溢出
        //哦要是真强制转换了肯定溢出，专业知识受到挑战
        //困惑
        //虽然我现在还是困惑，但是我前几天写的是什么注释啊
        //看来以后打注释要打时间戳了
        //但是这个程序就先算了吧
        n/=10;
    }
    printf("\nThe digit is %u.\n",num_of_digits);
    switch(num_of_digits)
    {   //累死我了Σ_(꒪ཀ꒪」∠)_
        case 20:printf("Ten-quintillions place is     %hu.\n",num[19]);
        case 19:printf("Quintillions place is         %hu.\n",num[18]);
        case 18:printf("Hundred-quadrillions place is %hu.\n",num[17]);
        case 17:printf("Ten-quadrillions place is     %hu.\n",num[16]);
        case 16:printf("Quadrillions place is         %hu.\n",num[15]);
        case 15:printf("Hundred-trillions place is    %hu.\n",num[14]);
        case 14:printf("Ten-trillions place is        %hu.\n",num[13]);
        case 13:printf("Trillions place is            %hu.\n",num[12]);
        case 12:printf("Hundred-billions place is     %hu.\n",num[11]);
        case 11:printf("Ten-billions place is         %hu.\n",num[10]);
        case 10:printf("Billions place is             %hu.\n",num[9]);
        case  9:printf("Hundred-millions place is     %hu.\n",num[8]);
        case  8:printf("Ten-millions place is         %hu.\n",num[7]);
        case  7:printf("Millions place is             %hu.\n",num[6]);
        case  6:printf("Hundred-thousands place is    %hu.\n",num[5]);
        case  5:printf("Ten-thousands place is        %hu.\n",num[4]);
        case  4:printf("Thousands place is            %hu.\n",num[3]);
        case  3:printf("Hundreds place is             %hu.\n",num[2]);
        case  2:printf("Tens place is                 %hu.\n",num[1]);
        case  1:printf("Units place is                %hu.\n",num[0]);
        default:printf("Is there any errors?\n");//真的需要default吗？
    }
}
bool if_leap_years(const short int *year)
{//使用维基百科上Planetoid的个人作品（流程图）进行闰年判断
    if(*year%4==0)
    {
        if(*year%100==0)
        {
            if(*year%400==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
short convert_percent_to_grade_and_output(const short int *grade)
{
    if (*grade>=0 && *grade<=100)
    {
        switch((*grade)/10)
        {
            case 10:;
            case 9:printf("Excellent!\n");break;
            case 8:printf("Good!\n");break;
            case 7:printf("Average!\n");break;
            case 6:printf("Pass!\n");break;
            default:printf("Fail!\n");break;
        }
        return 0;
    }
    else
    {
        printf("Are you ok?\n");
        printf("Please enter a number between 0 and 100.\n");
        return -1;
    }
}
unsigned long long int sum_of_odd_numbers_1_to_input(const unsigned long long int *input)
{
    unsigned long long int sum=0;
    for(int i=1;i<*input;i++)
    {
        if(i%2!=0)
        {
            sum+=i;
        }
    }
    return sum;
}
unsigned long long int sum_of_even_numbers_1_to_input(const unsigned long long int *input)
{
    unsigned long long int sum=0;
    /*for(int i=0;i<*input;i++)
    {
        if(i%2==0)
        {
            sum+=i;
        }
    }*/
    int i=1;
    while (i<*input)
    {
        if(i%2==0)
        {
            sum+=i;
        }
        i++;
    }
    return sum;
}
void sum_of_multiples_of_3_1_to_input(const unsigned long long int *input)
{
    unsigned long long int i=1;
    do//这do while是真难写
    {
        if (i%3==0)
        {
            printf("%llu\n",i);
        }
        i++;
    }while(i<*input);
}
unsigned long long int fisrt_divisible_by_both_3_and_5(const unsigned long long int *in1,
                                                       const unsigned long long int *in2)
{//先把上下限确定下来
    unsigned long long int a1=*in1<=*in2?*in1:*in2;
    unsigned long long int a2=*in1>*in2?*in1:*in2;
    for (unsigned long long int i=a1;i<=a2;i++)
    {
        if(i%5==0 && i%3==0)
        {
            return i;
        }
    }
}
void daffodil_number(void)
{//气死我了//我是真有病//我为什么要输出任意位数的水仙花数//这玩意能在卡死之前算完吗//不改了
    short int num[21]={0};
    short int num_of_digits=0;
    unsigned long long int conclusion,tmp,power;
    for(unsigned long long int n=100;n<=(unsigned long long int)pow(10,3);n++)
    {//改变这里的上下限以改变输出范围
        tmp=n;
        num_of_digits=conclusion=0;//叫叫叫/叫你妈叫/0跟你转不转换有什么关系
        while(tmp)
        {//找一下一共多少位
            tmp/=10;
            num_of_digits++;
        }
        tmp=n;
        for (int i=0;i<num_of_digits;i++)
        {//把每一位拆开放进数组
            num[i]=tmp%10;
            tmp/=10;
        }
        for(int i=0;i<num_of_digits;i++)
        {//计算水仙花数
            // conclusion+=(unsigned long long int)pow(num[i],num_of_digits);
            power=1;//不是零因为所有数会变零
            for (int j = 0; j < num_of_digits; j++)
            { // 手动计算幂，替代 pow,传说中pow极不精确
                power *= num[i];
            }
            conclusion+=power;
        }
        if (conclusion==n)
        {
            printf("%llu\n",conclusion);
        }
    }
}
const unsigned long long int *who_is_bigger(const unsigned long long int *a,
                                      const unsigned long long int *b)
{
    return (*a)>(*b)?a:b;
}
void max_and_min( unsigned long long int *a, unsigned long long int *b)
{//为什么要写这种程序？
    if(*a>=*b)
    {//让a比b大，就这么简单
        ;
    }
    else
    {
        unsigned long long int tmp=*a;
        *a=*b;
        *b=tmp;
    }
}
void bubble(unsigned long long int *arr, const int n)
{//一个人畜无害的冒泡
    unsigned long long int tmp=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (*(arr+j)>*(arr+j+1))
            {
                tmp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=tmp;
            }
        }
    }
}
//惨痛经历难以忘怀//这都写的啥啊//不忍心删掉
/*void matrix_Transpose(double **matrix,int row,int col)
{
    // 创建一个指针数组，用来存储每一行的起始地址
    double **arr = (double **)malloc(row * sizeof(double*));
    if (arr == NULL)
    { // 检查内存分配是否成功
        printf("Memory error.\n");
        return;
    }
    // 动态分配每一行的内存
    for (int i = 0; i < row; i++)
    {
        arr[i] = (double *)malloc(col * sizeof(double));
        if (arr[i] == NULL)
        { // 检查每行内存分配是否成功
            printf("Memory error of row %d.\n",i);
            return;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("ROW %d, COL %d\n",i,j);
            arr[i][j] = getchar()-'0'; //输入数据
            printf("It's %4lf", arr[i][j]);
        }
        printf("\n");
    }
    printf("Before transpose:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("It's %4lf", arr[i][j]);
        }
        printf("\n");
    }

    printf("After transpose:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("It's %4lf", arr[i][j]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        free(arr[i]); // 释放每一行
    }
    free(arr); // 释放指针数组
}*/
/*void matrix_input(double **matrix)
{
    double a=0;
    goto_row_col:;
    printf("How many rows or cols you wanna create?\n");
    lf_input(&a);
    if(a>=10)
    {
        printf("No. Too big. Enter again.\n");
        goto goto_row_col;
    }
    else
    {
        printf("Enter your matrix.\n");
        for(short i=0;i<10;i++)
        {
            goto_next_row:;
            for(short j=0;j<10;j++)
            {
                matrix[i][j]=getchar()-'0';
                if(matrix[i][j]+'0'=='\n')
                {
                    i++;
                    goto goto_next_row;
                }
            }
        }
    }
}*/
double * matrix_create(short *r,short *c)
{
    short int row,col;
    row=col=0;
    printf("How many ROWs you wanna input?\n");
    hd_input(&row);
    printf("How many COLUMNs you wanna input?\n");
    hd_input(&col);
    if (row <= 0 || col <= 0)
    {
        printf("Invalid matrix dimensions!\n");
        return NULL;
    }
    double *point=(double *)malloc(sizeof(double)*row*col);
    //这里创建了一个貌似是二维数组的东西，就拿它用吧
    /*for(int i=0;i<row;i++)
    {//赋初值防止爆炸
        for(int j=0;j<col;j++)
        {
            // point[i*col+j]=0;
            *(point + i * col + j)=0;
        }
    }*///好像根本不用赋初值？
    printf("Enter the elements of the matrix.\n");
    for(int i=0;i<row;i++)
    {//输入浮点数
        for(int j=0;j<col;j++)
        {
            lf_input((point + i * col + j));
        }
    }
    *r=row;
    *c=col;
    return point;
}
void matrix_Transpose(double *matrix,int row,int col)
{//别tm叫唤const了//老子不需要//再说了我加上const以后你就报错什么意思
    //这个函数你想死可以直说，不用这么折磨我
    // row=col>row?col:row;
    // col=col>row?col:row;
    // 动态分配二维数组,行列调换用于转置
    double **tmp = allocate_2d_array(col, row);
    //到底哪儿tm内存泄露了？我多掉这几根头发就是因为你
    // 初始化数组
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            tmp[i][j] =0;
        }
    }*/
    for (int i = 0; i < row; i++)
    {//转置的操作，关于为什么不操作原数组，别问，问就是我不会
        for (int j = 0; j < col; j++)
        {
            tmp[j][i]=*(matrix+i * col + j);
        }
    }
    printf("The transposed matrix is:\n");
    for (int i = 0; i < col; i++)
    {//打印矩阵
        for (int j = 0; j < row; j++)
        {
            printf("%10lf",tmp[i][j]);
        }
        printf("\n");
    }
    free_2d_array(tmp, col);
}
double **allocate_2d_array(int row, int col)
{
    // 分配行指针
    double **array = (double **)malloc(row * sizeof(double *));
    if (array == NULL)
    {
        printf("Memory error!\n");
        return NULL;
    }
    // 为每一行单独分配内存
    for (int i = 0; i < row; i++)
    {
        array[i] = (double *)malloc(col * sizeof(double));
        if (array[i] == NULL)
        {
            printf("Memory error!\n");
            // 出问题后释放已经分配的行
            for (int j = 0; j < i; j++)
            {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}
void free_2d_array(double **array, int row)
{
    if (array == NULL)
    {
        return;
    }
    // 释放每一行的内存
    for (int i = 0; i < row; i++)
    {
        free(array[i]);
    }
    // 释放行指针
    free(array);
}
short int get_the_number_of_words(void)
{//获取单词数量
    short int sum=0;
    char ch,pre;
    ch=pre='\0';
    while(ch!='\n')
    {
        ch=getchar();
        if (ch==' ' || ch=='\t' || ch=='\n')
        {
            if (pre!=' ' && pre!='\t' && pre!='\0')
            {
                sum++;
            }
        }
        pre=ch;
    }
    if (pre != ' ' && pre != '\t' && pre != '\n' && pre != '\0')
    {//为什么总是报警告啊啊啊啊啊
        sum++;
    }//这是防止不正常输入打的空格造成问题
    return sum;
}
void initialize(int *head)
{
    *head = -1; // 头指针初始化为空
    //暂时先这样，不知道怎么往下写，反正没报错
}
void insert(int *head, int value)
{// 插入节点到链表（头插法）//静态链表，没打注释的是动态的
    static int index = 0; // 静态变量，表示下一个可用节点的索引
    if (index >= MAX_SIZE)
    {//防止溢出
        printf("List is full!\n");
        return;
    }
    list[index].data = value;  // 设置节点数据
    list[index].next = *head;  // 新节点指向当前头节点
    *head = index;             // 更新头指针为新节点
    index++;                   // 更新可用节点索引
}
void traverse(int head)
{// 遍历静态链表
    int current = head;
    while (current != -1)
    {
        printf("%d -> ", list[current].data);
        current = list[current].next;
    }
    printf("NULL\n");
}
void delete_link(struct node *head,int place)
{
    struct node *p,*pre;
    int i;
    pre=head;
    i=0;
    while(i<place-1 && pre->next!=NULL)
    {
        pre=pre->next;
        i++;
    }
    if(i>place-1 || pre->next==NULL)
    {
        printf("error\n");
    }
    else
    {
        p=pre->next;
        pre->next=p->next;
        free(p);
    }
}
void insert_link(struct node *head,int place,int x)
{
    struct node *p,*pre;
    int i;
    pre=head;
    i=0;
    while(i<place-1 && pre->next!=NULL)
    {
        pre=pre->next;
        i++;
    }
    if(i>place-1 || pre==NULL)
    {
        printf("error\n");
    }
    else
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=pre->next;
        pre->next=p;
    }
}
void output_link(struct node *head)
{
    struct node *p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%7d",p->data);
        p=p->next;
    }
    printf("\n");
}
struct node* creat_link(void)
{
    struct node *head,*p,*pre;
    int x;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    pre=head;
    printf("Enter the data(Positive numbers only, -1 to exit):\n");
    while(true)
    {
        d_input(&x);
        if(x==-1)
        {
            break;
        }
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        pre->next=p;
        pre=p;
    }
    return head;
}
void student_create(void)
{//结构体内容输入全在这里了，输入一次显示一次
    printf("There are 10 students to enter.\n");
    for(short int i=0;i<10;i++)
    {
        printf("Enter student %hd:\n",i+1);
        printf("Enter id:\n");
        d_input(&student[i].id);
        printf("ID is: %d\n",student[i].id);
        getchar();
        printf("Enter name(no space but \"_\"):\n");
        for(int j=0;j<50;j++)
        {
            student[i].name[j]=getchar();
            if(student[i].name[j]=='\0' || student[i].name[j]=='\n')
            {
                break;
            }
        }
        for(int j=0;j<50;j++)
        {
            // student[i].name[j]=getchar();
            if(student[i].name[j]=='_')
            {
                student[i].name[j]=' ';
            }
        }
        printf("Name:%s\n",student[i].name);
        // getchar();
        printf("Enter score.\n");
        hd_input(&student[i].score);
        printf("Score:%d\n",student[i].score);
    }
}
void student_sort(void)
{
    struct_bubble(student,10);
    //你问我为什么要单独写个函数？谁知道呢
}
void struct_bubble(struct student arr[], const int n)
{//之前的冒泡用不了，重新写了一个针对结构体的冒泡
    struct student tmp;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j].score>arr[j+1].score)
            {
                /*tmp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=tmp;*/
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}
void student_display(void)
{//显示结构体中的数据
    printf("There are 10 students to display.\n");
    for(short int i=0;i<10;i++)
    {
        printf("Student %hd:\n",i+1);
        printf("ID is: %d\n",student[i].id);
        printf("Name:%s\n",student[i].name);
        printf("Score:%d\n",student[i].score);
    }
}