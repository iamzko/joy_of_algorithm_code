//
// Created by Administrator on 2021/9/26.
//

#ifndef JOY_OF_ALGORITHM_CODE_CHINESE_NUMBER_TRANS_H
#define JOY_OF_ALGORITHM_CODE_CHINESE_NUMBER_TRANS_H

#include <string>
#include <iostream>

const std::string chinese_numbers[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
const std::string chinese_weight[] = {"", "十", "百", "千"};
const std::string chinese_section[] = {"", "万", "亿", "万亿"};

class chinese_number_trans
{
public:
    static void number_to_chinese(unsigned int num, std::string &str)
    {
        int section_index = 0;
        bool need_zero = false;
        while (num > 0)
        {
            std::string str_num;
            auto section = num % 10000;//获取一节的数
            if (need_zero)
            {
                str.insert(0, chinese_numbers[0]);
            }
            //处理一节内部的数字
            number_section_to_chinese(section, str_num);
            //是否需要添加节权位
            str_num += (section != 0) ? chinese_section[section_index] : chinese_section[0];
            str.insert(0, str_num);
            //判断千位有没有数，没有的话要补零
            need_zero = (section < 1000) && (section > 0);
            num = num / 10000;
            section_index++;
        }
    }

    static void number_section_to_chinese(unsigned int num, std::string &str)
    {
        std::string str_num;
        int weight_index = 0;
        bool zero = true;
        while (num > 0)
        {
            int v = num % 10;
            if (v == 0)
            {
                if (num == 0 || !zero)
                {
                    zero = true;
                    str.insert(0, chinese_numbers[v]);
                }
            }
            else
            {
                zero = false;
                str_num = chinese_numbers[v];
                str_num += chinese_weight[weight_index];
                str.insert(0, str_num);
            }
            weight_index++;
            num = num / 10;
        }
    }
};

#endif //JOY_OF_ALGORITHM_CODE_CHINESE_NUMBER_TRANS_H
