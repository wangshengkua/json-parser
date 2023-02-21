#pragma once
#include<string>
#include<vector>
#include<map>
using namespace std;
namespace yazi{
namespace json{
class Json{
    public:
		enum Type {       //类型
			json_null = 0,
			json_bool,
			json_int,
			json_double,
			json_string,
			json_array,
			json_object,
		};

		//重构器
        Json();
		Json(bool value);
		Json(int value);
		Json(double value);
		Json(const char* value);
		Json(const string &value);
		Json(Type type);
		Json(const Json& other);

		//重构bool int double string；
        operator bool();
        operator int();
        operator double();
        operator string();

		//对[]重构 判断里面类型；
        Json & operator [](int index);
        void append(const Json & other);

		Json & operator [](const char * key);
		Json & operator [](const string & key);

		//对 = ， == ， ！= 进行重构；
		void operator = (const Json & other);
		bool operator == (const Json & other);
		bool operator != (const Json & other);


        string str() const;
		void copy(const Json & other);
		void clear();

		typedef std::vector<Json>::iterator iterator;
		iterator begin(){
			return m_value.m_array->begin();
		}
		iterator end(){
			return m_value.m_array->end();
		}

		bool isNull() const {return m_type == json_null;}
		bool isBool() const {return m_type == json_bool;}
		bool isInt() const {return m_type == json_int;}
		bool isDouble() const {return m_type == json_double;}
		bool isObject() const {return m_type == json_object;}
		bool isString() const {return m_type == json_string;}
		bool isArray() const {return m_type == json_array;}

		bool asBool() const;
		int asInt() const;
		double asDouble() const;
		string asString() const;

		bool has(int index);
		bool has(const char *key);
		bool has(const string & key);

		void remove(int index);
		void remove(const char *key);
		void remove(const string & key);

		void parse(const string &str);
    private:
		union Value {  //内容
			bool m_bool;
			int m_int;
			double m_double;
			std::string *m_string;
			std::vector<Json> *m_array;
			std::map<string, Json>* m_object;
		};
		Type m_type;  //类型
		Value m_value;  //内容
};

}}