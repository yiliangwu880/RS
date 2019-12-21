
目标：
{
	针对游戏或者类游戏服务器需求。
	不面面俱到，只重视实际。
	学习成本低。
	开发效率高。
	性能可以扩展物理机来提升。
	尽量单进程单线程模式。
	基础基本的库独立性好，无依赖关系。
}

设计思想：
{
	消灭重复劳动。
	用合适产品的技术，不用最牛逼的技术。
	为了简化问题，推荐使用单进程但线程模式，也提供多线程模式供选择。

}

RS项目 整体框架设计：
{

	basesvr: libevent_cpp svr_util为基础，封易用服务器启动对象。
	1 网络收发库： libevent2,C++封装，快速写网络通讯， 服务器，客户端链接
	{
		所有服务器，需要用进程间通讯的，都要引用这个库。 默认省略写 include 1
	}
	有独立测试项目，后面所有功能，都做一个独立测试项目，写测试用例。
	

	21 svr_util 库：
	{	
		11 线程库
		{
		}
		服务器常用的功能：日志，唯一进程，参数读取，信号，崩溃日志，线程间通讯库
	}
	
	2  msg_forward 消息转发服务：服务器通讯用，做其他服务器的转发服务。
	{
		根据服务id,路由消息。 容易配置，服务消费者只需要知道对方服务id,就能通讯。
		可以多个msg_forward。高可用，无状态。
		22 mfd  msg_forward客户端驱动
		{
			服务器断开，定时重连。
			注册服务器id
			发送，接收
			断开连接通知。
		}
	}
	
	3 网关：客户端 入口，验证，转发消息
	{
	}
	
	4 基础登陆验证流程库，可根据不同游戏扩展，
	{
		无状态
		可扩展内容：
		{
			支持本服db验证，
			第三方服务器验证
			验证结果通知接口
		}
	}
	 
	5 接入服务器，access
	{
		
		可扩展内容：
		{
			验证接口：接登陆验证用
			转发机制： 默认转发服务器，制定转发
		}
	}
	
	6 DbProxy:
	{
		和客户端：用protobuf 描述对象以及行为 
		转化客户端消息为db操作
		可创建表，或者集合
		可扩展：
		{
			默认mysql
			db类型： mysql,mongodb等。
			取模分库
			缓存redis
		}
	}
	7 cpp_lua_i
	{
		cpp lua interface
		多参考别的项目，采取简单好用方法
	}
		
	-----------------------后面后期看需要开发--------------

	
	线程间通讯库
	日志库--直接用开源log4cplus
	com_server
	{
		可复用标准服务器组件，依赖libevent_cpp, svr_util
		可做多种，功能组合起来用。设计待思考
		日志功能整理好
		宕机日志，进程启动，kill-10关闭方式，svr_util timer功能
		type1: 让用户不用编写main函数，只要回调函数启动自己的自定义侦听器服务器，客户端
		
	}
}

待定项:
{
	业务事件管理，支持post,Trigger(马上触发)
	邮件
	排行榜
	
}


