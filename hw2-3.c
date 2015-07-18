#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(){
    char temp[9],
        inputs[30][9];          //inputs: 储存所有输入的字符
    int count = 0,              //count: 输入的个数
        i,
        index = -1,             //index: 记录栈顶的位置
        error = 0;
    float number[30];           //number: 用数组储存数字（可以算是栈吗= =）
 
    //当成字符串输入
    while (scanf("%s", temp) != EOF)
     
        //strcpy在 string.h 里，将输入存进 inputs 中，
        //同时count在计算个数
        strcpy(inputs[count++], temp); 
                                                                 
    //从尾开始扫描
    for (i = count - 1; i >= 0; i--){
        char *t = inputs[i];
 
        //扫描到符号（所有符号长度为1，且ASCII中都在'0'前）
        if (strlen(t) == 1 && *t < '0'){
         
            //取出栈顶第一个数字，同时将index放到下面一个数字的位置
            float m = number[index--], 
 
                //取出第二个数字
                n = number[index], 
 
                //【指向】第二个数字的位置，这个位置用来储存计算结果
                *c = &number[index]; 
 
            //运算
            if (*t == '/'){
                //被除数为0即立刻跳出循环输出ERROR
                if (n == 0){
                    error = 1;
                    break;
                }
                *c = m / n;
            }
            else if (*t == '*')
                *c = m * n;
            else if (*t == '-')
                *c = m - n;
            else if (*t == '+')
                *c = m + n;
        }
 
        //扫描到数字
        else
            //atof() 在 stdlib.h 里，转换字符串为float储存在number的栈顶
            number[++index] = atof(t); 
    }
 
    //输出，三目运算符判断是否出错。最后的结果number栈的栈底即0位置上～
    printf(error ? "ERROR\n" : "%.1f\n", number[0]);
   
    return 0;
}