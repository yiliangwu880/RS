#pragma once

//����ͼ������ܽṹ

class libevent
{

};

class libevent_cpp : public libevent
{

};

class svr_util
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

