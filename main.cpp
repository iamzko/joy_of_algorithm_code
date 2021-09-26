#include <iostream>
#include <vector>
#include "chinese_number_trans.h"

void str_all_sort(char* src_str,int start_index,int end_index)
{
    if(start_index == end_index)
    {
        std::cout << src_str;
    }
    else
    {
        for(int i = start_index; i < end_index; ++i)
        {
            char temp = src_str[start_index];
            src_str[start_index] = src_str[i];
            src_str[i]  = temp;
            str_all_sort(src_str,start_index+1,end_index);
            temp = src_str[i];
            src_str[i] = src_str[start_index];
            src_str[start_index] = temp;
        }
    }
}

void str_all_sort(std::string src ,int start_index)
{
    if(start_index == src.size()-1)
    {
        std::cout << src<< std::endl;
    }
    else
    {
        //回溯的思想，整个串的全排依赖字串的全排，递归下去
        for(int i = start_index;i < src.size(); ++i)
        {
            std::swap(src[start_index],src[i]);
            str_all_sort(src,start_index+1);
        }
    }

}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::string chinese_number;
    chinese_number_trans::number_to_chinese(92323110100,chinese_number);
    std::cout << chinese_number << std::endl;

    char * test = "abcdefg";
//    str_all_sort(test,0,2);
    str_all_sort(test,0);


    return 0;
}
