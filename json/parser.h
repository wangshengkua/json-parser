#pragma once

#include "json.h"
#include<string>
using namespace std;

namespace yazi{
namespace json{
    class Parser{
        public:
            Parser();
            void load(const string & str);

            Json parse();
        private:
            void skip_white_space(); //忽略空格，回车，换行
            char get_next_token(); //获取下一个字符

            Json parse_null();  
            Json parse_bool(); 
            Json parse_number();
            string parse_string(); 
            Json parse_array();
            Json parse_object();    
        private:
            string m_str;
            int m_idx;
    };
}
}