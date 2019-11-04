#pragma once

//用类图描述框架结构

class protobuf
{

};
class libevent
{

};

////////////////////////////////////////////////
class libevent_cpp : public libevent
{

};

class svr_util
{

};

//让CPP LUA交换更简化
class lua_mgr
{

};

class acc_proto
{

};

//access_svr
class access_svr : public libevent_cpp, public svr_util, public acc_proto
{

};

//业务服务器接入网关驱动
//access connect driver  
class acc_driver : public libevent_cpp, public svr_util, public acc_proto
{

};

class login_svr : public libevent_cpp, public svr_util, public acc_con_dev
{

};

//proto协议交换，读取任意DB。 mysql, redis, mongodb
class db_proxy_svr : public libevent_cpp, public svr_util, public protobuf
{

};


class mf_proto
{

};

class mf_driver : public mf_proto, public libevent_cpp
{

};


class mf_svr : public libevent_cpp, public svr_util, public mf_proto
{

};

