#pragma once

//����ͼ������ܽṹ

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

//��CPP LUA��������
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

//ҵ�������������������
//access connect driver  
class acc_driver : public libevent_cpp, public svr_util, public acc_proto
{

};

class login_svr : public libevent_cpp, public svr_util, public acc_con_dev
{

};

//protoЭ�齻������ȡ����DB�� mysql, redis, mongodb
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

