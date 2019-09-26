#pragma once

//用类图描述框架结构

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

