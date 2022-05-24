/*
 * @descripttion: 日志类头文件
 * @param: 
 * @return: 
 */

//ifndef 宏 是为了避免头文件重复引用，可以直接使用once
#ifndef __MARVEL_LOG_H__
#define __MARVEL_LOG_H__

#include <string>
#include <stdint.h>
//namespace确认命名空间
namespace marvel{
    //每个日志生成均放到logevent
    class LogEvent {
        public:
            LogEvent();
        private:
            const char* m_file = nullptr; //文件名
            int32_t m_line = 0;
            uint32_t m_threadId = 0; //线程Id
            uint32_t m_fiberId = 0; //协程Id
            std::string m_content; //消息
            uint64_t m_time; //可能有毫秒级 
    };
    //日志输出器
    class Logger{
        public:
            //日志级别
           enum Level{
               DEBUG = 1,
               INFO = 2,
               WARN = 3,
               ERROR = 4,
               FATAL = 5
           };
           Logger(); //构造函数
           void Log(Level level, const LogEvent& event);
        private:
    };
    //日志输出地
    class LogAppender{
        public:
            //因为日志的输出地很多，所以采用虚类析构函数，如果不采用虚类构造函数的话，子类在释放空间的时候会有问题
            virtual ~LogAppender(); //todo：为什么子类释放会有问题

    };
    //日志格式化
    class LogFormatter{

    };
}


#endif
