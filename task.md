# 测试报告
需要网络流量参数。

# access_svr 消息缓存
    需求: 例如切换场景过程中，zone1->zone2. 过程中zone1 删掉角色状态，zone2还没准备号角色状态，这时不能处理客户端消息。就需要access_svr缓存消息了。_ 

# old
LOG_DEBUG_SEC //一秒最多打印一次的日志

配置定义数据格式，内存数据结构，db结构，网络协议结构自动化统一生成。 
{
    比如新加一个角色存库模块需要做：定义配置格式，生成代码结构。 用户不需要再手动定义任何对象结构。
    避免多出结构格式不一样，手动写容易犯人工错误。
}

CppUtility全部搬运到 svr_util, 和app_util

app_util : public svr_util, libcevent_cpp, acc_driver, mf_driver

每个组件，性能测试。

com_server


excel to data. cpp 解析代码。

排行榜，库或者服务器

修改DB表结构：服务器进程启动检查protobuf和DB表。发现不一样就更新表结构

参考 skynet或者复用 ,开发actor模型 多线程服务器

# 服务器内部网络消息协议，都是C++，就用最简单的C结构体二进制格式。
{
    一些改进：
        每个msg都有msg.cmdid const 字段存放消息号。
        进程从网络接收包，读取消息号，获取消息体对象，初始化。分发消息体抽象对象给用户使用。
    参考代码：
```c++
        struct BaseMsg{
            BaseMsg(int cmdId) :m_cmdId(cmdId){}
            const uint32 m_cmdId;
        }
        struct MyMsg : public BaseMsg
        {
            MyMsg():BaseMsg(301)
            {}
            ...
        }

        union uu
        {
            MyMsg o1;
            MyMsg2 o2;
            ...
        }

        dipatchMsg(char *msg, ...);

        HandMsg(char *msg)
        {
            const MyMsg *pMsg = ParseMsg<MyMsg>(msg);
            if(null == pMsg) return;
        }

        ParseMsg<MyMsg>(char *msg)
        {
           const MyMsg *pMsg =  (const MyMsg *)msg;     
           MyMsg msg;
           if(pMsg->cmdid != msg.cmd_id) return null;
           return pMsg;
        }
```
    用户加新消息需要做：
        定义cmdid。
        消息体定义，加入cmdid关联。
        注册接收cmdId函数
}